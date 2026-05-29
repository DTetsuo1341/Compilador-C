#include "tac_generator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <unordered_set>
#include <stdexcept>

// 
//  TACInstruction::to_string — serialización al formato textual FIS-25
// 
std::string TACInstruction::to_string() const {
    switch (op) {
        case TACOp::VAR:          return "VAR "     + result;
        case TACOp::ASSIGN:       return "ASSIGN "  + arg1 + " " + result;

        case TACOp::ADD:          return "ADD "     + arg1 + " " + arg2 + " " + result;
        case TACOp::SUB:          return "SUB "     + arg1 + " " + arg2 + " " + result;
        case TACOp::MUL:          return "MUL "     + arg1 + " " + arg2 + " " + result;
        case TACOp::DIV:          return "DIV "     + arg1 + " " + arg2 + " " + result;
        case TACOp::MOD:          return "MOD "     + arg1 + " " + arg2 + " " + result;
        case TACOp::POW:          return "POW "     + arg1 + " " + arg2 + " " + result;

        case TACOp::EQ:           return "EQ "      + arg1 + " " + arg2 + " " + result;
        case TACOp::NEQ:          return "NEQ "     + arg1 + " " + arg2 + " " + result;
        case TACOp::GT:           return "GT "      + arg1 + " " + arg2 + " " + result;
        case TACOp::GTE:          return "GTE "     + arg1 + " " + arg2 + " " + result;
        case TACOp::LT:           return "LT "      + arg1 + " " + arg2 + " " + result;
        case TACOp::LTE:          return "LTE "     + arg1 + " " + arg2 + " " + result;

        case TACOp::LABEL:        return "LABEL "   + result;
        case TACOp::GOTO:         return "GOTO "    + result;
        case TACOp::IF_GOTO:      return "IF "      + arg1 + " GOTO " + result;
        case TACOp::IFFALSE_GOTO: return "IFFALSE " + arg1 + " GOTO " + result;

        case TACOp::PARAM:        return "PARAM "     + arg1;
        case TACOp::PARAM_GET:    return "PARAM_GET " + result;
        case TACOp::GOSUB:        return "GOSUB "     + result;
        case TACOp::RETURN:       return "RETURN";

        case TACOp::PRINT:        return "PRINT "  + arg1;
        case TACOp::INPUT:        return "INPUT "  + result;
        case TACOp::PIXEL:        return "PIXEL "  + arg1 + " " + arg2 + " " + result;
        case TACOp::KEY:          return "KEY "    + arg1 + " " + result;
    }
    return "// instruccion desconocida";
}

// 
//  Helpers internos
// 
std::string TACGenerator::new_temp() {
    return "t" + std::to_string(temp_count++);
}

std::string TACGenerator::new_label() {
    return "L" + std::to_string(label_count++);
}

void TACGenerator::emit(TACInstruction instr) {
    instructions.push_back(std::move(instr));
}

// 
//  Punto de entrada público
// 
void TACGenerator::generate(Node* root) {
    if (!root) return;

    // RETVAL es la variable global de retorno de funciones.
    emit({TACOp::VAR, "", "", "RETVAL"});

    gen(root);
}

// 
//  Dispatcher principal
// 
std::string TACGenerator::gen(Node* node) {
    if (!node) return "";

    const std::string& k = node->kind;

    //  Estructura del programa 
    if (k == "Program")         { gen_program(node);        return ""; }
    if (k == "Function")        { gen_function(node);       return ""; }
    if (k == "Statement List")  { gen_statement_list(node); return ""; }
    if (k == "Empty Block")     {                           return ""; }

    //  Statements 
    if (k == "Declaration")     { gen_declaration(node);    return ""; }
    if (k == "Assignment")      { gen_assignment(node);     return ""; }
    if (k == "Return")          { gen_return(node);         return ""; }
    if (k == "Conditional")     { gen_conditional(node);    return ""; }
    if (k == "Loop")            { gen_loop(node);           return ""; }
    if (k == "Print")           { gen_print(node);          return ""; }
    if (k == "Read")            { gen_read(node);           return ""; }

    //  Expresiones (retornan un lugar) 
    if (k == "Operation")       { return gen_operation(node);   }
    if (k == "Comparison")      { return gen_comparison(node);  }
    if (k == "Call")            { return gen_call(node);        }

    //  Literales e identifiers (retornan su valor directamente) 
    if (k == "Integer")         { return node->value; }
    if (k == "Float")           { return node->value; }
    if (k == "True")            { return "1"; }
    if (k == "False")           { return "0"; }
    if (k == "String")          { return node->value; }  // las comillas ya vienen del lexer
    if (k == "Identifier")      { return node->value; }

    //  Nodos contenedor sin código propio — recurrir hijos 
    for (Node* child : node->children) gen(child);
    return "";
}

// 
//  Handlers
// 

void TACGenerator::gen_program(Node* node) {
    for (Node* child : node->children)
        gen(child);
}

//  Function 
//  AST:  Function "fn <nombre>"
//          ├ Parameters (opcional)
//          │     └ Parameter "<nombre>" → [Type]
//          └ Statement List (cuerpo)
void TACGenerator::gen_function(Node* node) {
    // Extraer nombre: "fn nombreFuncion" → "nombreFuncion"
    const std::string fn_name    = node->value.substr(3);
    const std::string label_skip = new_label();

    // La ejecución secuencial salta el cuerpo de la función.
    // El cuerpo solo se alcanza via GOSUB.
    emit({TACOp::GOTO,  "", "", label_skip});
    emit({TACOp::LABEL, "", "", fn_name});

    // Determinar si el primer hijo es Parameters o directo el cuerpo
    int body_idx = 0;
    Node* params = nullptr;

    if (!node->children.empty() && node->children[0]->kind == "Parameters") {
        params   = node->children[0];
        body_idx = 1;
    }

    // Recuperar parámetros de la pila en orden de declaración
    if (params) {
        for (Node* param : params->children) {
            emit({TACOp::VAR,       "", "", param->value});
            emit({TACOp::PARAM_GET, "", "", param->value});
        }
    }

    // Generar cuerpo
    if (body_idx < (int)node->children.size())
        gen(node->children[body_idx]);

    // RETURN implícito — cubre funciones void sin rt explícito
    emit({TACOp::RETURN, "", "", ""});

    emit({TACOp::LABEL, "", "", label_skip});
}

//  Statement List 
void TACGenerator::gen_statement_list(Node* node) {
    for (Node* child : node->children)
        gen(child);
}

//  Declaration 
//  AST:  Declaration "<nombre>"
//          ├ Type
//          └ expression (opcional)
void TACGenerator::gen_declaration(Node* node) {
    emit({TACOp::VAR, "", "", node->value});

    // Si tiene expresión de inicialización (children[1])
    if (node->children.size() > 1) {
        std::string src = gen(node->children[1]);
        emit({TACOp::ASSIGN, src, "", node->value});
    }
}

//  Assignment 
//  AST:  Assignment "<nombre>"
//          └ expression
void TACGenerator::gen_assignment(Node* node) {
    std::string src = gen(node->children[0]);
    emit({TACOp::ASSIGN, src, "", node->value});
}

//  Conditional 
//  AST:  Conditional "if"
//          ├ [0] condición
//          ├ [1] bloque then  (Statement List)
//          ├ [2] Else-If Branches (opcional)
//          └ [2/3] Else (opcional)
//
//  Estructura de etiquetas generada:
//
//      <cond>
//      IFFALSE cond GOTO Lnext
//      <then>
//      GOTO Lend
//    LABEL Lnext          ← o directamente Lend si no hay elsif/else
//      [elsif: cond → IFFALSE Lnext2 → bloque → GOTO Lend → LABEL Lnext2 …]
//      [else block]
//    LABEL Lend
void TACGenerator::gen_conditional(Node* node) {
    const std::string label_end  = new_label();
    std::string       label_next = new_label(); // destino si la condición falla

    // Identificar hijos opcionales
    Node* elsif_branches = nullptr;
    Node* else_node      = nullptr;
    for (size_t i = 2; i < node->children.size(); i++) {
        if (node->children[i]->kind == "Else-If Branches") elsif_branches = node->children[i];
        else if (node->children[i]->kind == "Else")        else_node      = node->children[i];
    }

    // Condición principal
    std::string cond = gen(node->children[0]);
    emit({TACOp::IFFALSE_GOTO, cond, "", label_next});

    // Bloque then
    gen(node->children[1]);
    emit({TACOp::GOTO, "", "", label_end});

    // Cadena de elsif
    if (elsif_branches) {
        for (Node* elsif : elsif_branches->children) {
            emit({TACOp::LABEL, "", "", label_next});
            label_next = new_label();

            std::string ei_cond = gen(elsif->children[0]);
            emit({TACOp::IFFALSE_GOTO, ei_cond, "", label_next});
            gen(elsif->children[1]);
            emit({TACOp::GOTO, "", "", label_end});
        }
    }

    // label_next apunta ahora al bloque else (o al final si no hay else)
    emit({TACOp::LABEL, "", "", label_next});

    if (else_node)
        gen(else_node->children[0]); // el Statement List dentro del Else

    emit({TACOp::LABEL, "", "", label_end});
}

//  Loop 
void TACGenerator::gen_loop(Node* node) {
    if (node->value == "wh") {
        // While:  children[0] = condición,  children[1] = cuerpo
        const std::string label_top = new_label();
        const std::string label_end = new_label();

        emit({TACOp::LABEL, "", "", label_top});

        std::string cond = gen(node->children[0]);
        emit({TACOp::IFFALSE_GOTO, cond, "", label_end});

        gen(node->children[1]); // cuerpo
        emit({TACOp::GOTO, "", "", label_top});
        emit({TACOp::LABEL, "", "", label_end});

    } else if (node->value == "for") {
        // For:  children[0] = FOR Header,  children[1] = cuerpo
        //       FOR Header → [init, condición, actualización]
        Node* header = node->children[0];
        const std::string label_top = new_label();
        const std::string label_end = new_label();

        gen(header->children[0]);               // init (Assignment)
        emit({TACOp::LABEL, "", "", label_top});

        std::string cond = gen(header->children[1]); // condición
        emit({TACOp::IFFALSE_GOTO, cond, "", label_end});

        gen(node->children[1]);                 // cuerpo
        gen(header->children[2]);               // actualización (Assignment)
        emit({TACOp::GOTO, "", "", label_top});
        emit({TACOp::LABEL, "", "", label_end});
    }
}

//  Return 
//  Convención: el valor de retorno viaja en la variable global RETVAL.
void TACGenerator::gen_return(Node* node) {
    if (!node->children.empty()) {
        std::string val = gen(node->children[0]);
        emit({TACOp::ASSIGN, val, "", "RETVAL"});
    }
    emit({TACOp::RETURN, "", "", ""});
}

//  Print 
//  AST:  Print ""
//          └ Arguments
//                └ [expr, expr, …]
void TACGenerator::gen_print(Node* node) {
    if (!node->children.empty() && node->children[0]->kind == "Arguments") {
        for (Node* arg : node->children[0]->children) {
            std::string val = gen(arg);
            emit({TACOp::PRINT, val, "", ""});
        }
    }
}

//  Read 
//  AST:  Read ""
//          └ Identifier "<nombre>"
void TACGenerator::gen_read(Node* node) {
    std::string dest = gen(node->children[0]);
    emit({TACOp::INPUT, "", "", dest});
}

//  Operation 
//  AST:  Operation "+"|"-"|"*"|"/"|"%"
//          ├ expresión izquierda
//          └ expresión derecha
std::string TACGenerator::gen_operation(Node* node) {
    std::string left  = gen(node->children[0]);
    std::string right = gen(node->children[1]);

    TACOp op;
    const std::string& v = node->value;
    if      (v == "+") op = TACOp::ADD;
    else if (v == "-") op = TACOp::SUB;
    else if (v == "*") op = TACOp::MUL;
    else if (v == "/") op = TACOp::DIV;
    else if (v == "%") op = TACOp::MOD;
    else               op = TACOp::ADD; // no debería llegar aquí

    const std::string temp = new_temp();
    emit({TACOp::VAR, "", "", temp});
    emit({op, left, right, temp});
    return temp;
}

//  Comparison 
//  AST:  Comparison "=="|"!="|">"|">="|"<"|"<="
//          ├ expresión izquierda
//          └ expresión derecha
std::string TACGenerator::gen_comparison(Node* node) {
    std::string left  = gen(node->children[0]);
    std::string right = gen(node->children[1]);

    TACOp op;
    const std::string& v = node->value;
    if      (v == "==") op = TACOp::EQ;
    else if (v == "!=") op = TACOp::NEQ;
    else if (v == ">")  op = TACOp::GT;
    else if (v == ">=") op = TACOp::GTE;
    else if (v == "<")  op = TACOp::LT;
    else if (v == "<=") op = TACOp::LTE;
    else                op = TACOp::EQ;

    const std::string temp = new_temp();
    emit({TACOp::VAR, "", "", temp});
    emit({op, left, right, temp});
    return temp;
}

//  Call 
//  AST:  Call "<fn>"
//          └ Arguments (opcional)
//
//  Los argumentos se apilan en orden INVERSO porque la pila de parámetros
//  de FIS-25 es LIFO: el primer PARAM_GET recupera el último PARAM empujado.
//  Empujando derecha→izquierda, PARAM_GET izquierda→derecha da el orden correcto.
std::string TACGenerator::gen_call(Node* node) {
    if (!node->children.empty() && node->children[0]->kind == "Arguments") {
        auto& args = node->children[0]->children;
        for (int i = (int)args.size() - 1; i >= 0; i--) {
            std::string val = gen(args[i]);
            emit({TACOp::PARAM, val, "", ""});
        }
    }

    emit({TACOp::GOSUB, "", "", node->value});

    // Capturar valor de retorno en un temporal
    const std::string temp = new_temp();
    emit({TACOp::VAR,    "", "", temp});
    emit({TACOp::ASSIGN, "RETVAL", "", temp});
    return temp;
}

//  Optimizaciones — se ejecutan sobre el vector de instrucciones ya generado

void TACGenerator::optimize() {
    // Dos rondas: cada pase puede habilitar al siguiente.
    // Ejemplo: dead_code crea GOTOs redundantes; redundant_goto deja
    // etiquetas huérfanas que unused_labels elimina.
    for (int r = 0; r < 2; r++) {
        pass_dead_code();
        pass_redundant_goto();
        pass_unused_labels();
    }
    pass_constant_fold();
}

//  Pase 1: Código muerto 
//  Las instrucciones entre un salto/retorno incondicional y la siguiente
//  etiqueta nunca se ejecutan. Las elimina.
//
//  Antes:                        Después:
//    ASSIGN val RETVAL              ASSIGN val RETVAL
//    RETURN                         RETURN
//    RETURN          ← muerto      LABEL Lskip
//    LABEL Lskip
void TACGenerator::pass_dead_code() {
    std::vector<TACInstruction> out;
    bool live = true;
    for (auto& i : instructions) {
        if (i.op == TACOp::LABEL)                             live = true;
        if (live)                                              out.push_back(i);
        if (i.op == TACOp::GOTO || i.op == TACOp::RETURN)    live = false;
    }
    instructions = std::move(out);
}

//  Pase 2: GOTO redundante 
//  Elimina GOTO Lx cuando la instrucción inmediatamente siguiente es
//  LABEL Lx (el salto no va a ningún lado útil).
//
//  Antes:                        Después:
//    GOTO L3                        (eliminado)
//    LABEL L3                       LABEL L3
void TACGenerator::pass_redundant_goto() {
    std::vector<TACInstruction> out;
    for (size_t i = 0; i < instructions.size(); i++) {
        if (instructions[i].op == TACOp::GOTO          &&
            i + 1 < instructions.size()                &&
            instructions[i+1].op   == TACOp::LABEL     &&
            instructions[i+1].result == instructions[i].result) {
            continue;   // salto redundante → descartar
        }
        out.push_back(instructions[i]);
    }
    instructions = std::move(out);
}

//  Pase 3: Etiquetas sin referencia 
//  Un LABEL Lx que ningún GOTO, IF, IFFALSE ni GOSUB menciona
//  es pura documentación sin efecto; lo elimina.
void TACGenerator::pass_unused_labels() {
    std::unordered_set<std::string> used;
    for (auto& i : instructions) {
        switch (i.op) {
            case TACOp::GOTO:
            case TACOp::IF_GOTO:
            case TACOp::IFFALSE_GOTO:
            case TACOp::GOSUB:         used.insert(i.result); break;
            default: break;
        }
    }
    std::vector<TACInstruction> out;
    for (auto& i : instructions) {
        if (i.op == TACOp::LABEL && !used.count(i.result)) continue;
        out.push_back(i);
    }
    instructions = std::move(out);
}

//  Pase 4: Constant Folding 
//  Evalúa en tiempo de compilación operaciones cuyos dos operandos
//  son literales numéricos y reemplaza la instrucción por un ASSIGN.
//
//  Antes:              Después:
//    MUL 3 4 t0          ASSIGN 12 t0
//    ADD t0 1 t1         ADD t0 1 t1   ← t0 ya no es literal, no aplica
bool TACGenerator::is_literal(const std::string& s) {
    if (s.empty()) return false;
    size_t i = (s[0] == '-') ? 1 : 0;
    if (i == s.size()) return false;
    bool dot = false;
    for (; i < s.size(); i++) {
        if      (s[i] == '.')                             { if (dot) return false; dot = true; }
        else if (!std::isdigit((unsigned char)s[i]))        return false;
    }
    return true;
}

double TACGenerator::to_num(const std::string& s) {
    return std::stod(s);
}

std::string TACGenerator::fmt_num(double v) {
    // Entero exacto representable → sin decimal
    if (v == std::floor(v) && !std::isinf(v) && std::abs(v) < 1e15) {
        std::ostringstream oss;
        oss << static_cast<long long>(v);
        return oss.str();
    }
    std::ostringstream oss;
    oss << std::setprecision(15) << v;
    return oss.str();
}

void TACGenerator::pass_constant_fold() {
    for (auto& instr : instructions) {
        if (!is_literal(instr.arg1) || !is_literal(instr.arg2)) continue;
        double a = to_num(instr.arg1), b = to_num(instr.arg2), r = 0;
        bool ok = true;
        switch (instr.op) {
            case TACOp::ADD: r = a + b; break;
            case TACOp::SUB: r = a - b; break;
            case TACOp::MUL: r = a * b; break;
            case TACOp::DIV: if (b == 0) { ok = false; break; } r = a / b; break;
            case TACOp::MOD: if (b == 0) { ok = false; break; } r = std::fmod(a, b); break;
            default: ok = false; break;
        }
        if (ok) { instr.op = TACOp::ASSIGN; instr.arg1 = fmt_num(r); instr.arg2 = ""; }
    }
}


void TACGenerator::print() const {
    for (const auto& instr : instructions)
        std::cout << instr.to_string() << "\n";
}

void TACGenerator::write(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out.is_open())
        throw std::runtime_error("No se pudo abrir el archivo: " + filename);
    for (const auto& instr : instructions)
        out << instr.to_string() << "\n";
}