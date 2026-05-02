#include "SemanticAnalyzer.h"

/**
 * @brief Constructor de la tabla de símbolos, inicializa la estructura
 * creando el ámbito global (nivel 0).
 */
SymbolTable::SymbolTable() {
    push_scope();
}

/**
 * @brief Inserta un nuevo ámbito en la pila.
 */
void SymbolTable::push_scope() {
    scopes.push_back(std::unordered_map<std::string, std::shared_ptr<Symbol>>());
}

/**
 * @brief Elimina el ámbito actual.
 *
 */
void SymbolTable::pop_scope() {
    if (scopes.size() > 1) {
        scopes.pop_back();
    }
}

/**
 * @brief Inserta un símbolo en el ámbito actual.
 * @param name Nombre del símbolo.
 * @param cat Categoría del símbolo.
 * @param type Tipo de dato del símbolo.
 * @return true si la inserción fue exitosa.
 * @return false si ya existe en el ámbito actual.
 */
bool SymbolTable::insert(const std::string& name, Category cat, DataType type) {
    auto& current_scope = scopes.back();

    if (current_scope.find(name) != current_scope.end()) {
        return false;
    }

    int depth = scopes.size() - 1;
    current_scope[name] = std::make_shared<Symbol>(name, cat, type, depth);
    return true;
}

/**
 * @brief Busca un símbolo en la tabla de símbolos, implementando shadowing,
 * buscando desde el ámbito más interno al global.
 * @param name Nombre del símbolo.
 * @return Puntero al símbolo si existe, nullptr en caso contrario.
 */
std::shared_ptr<Symbol> SymbolTable::lookup(const std::string& name) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        if (it->find(name) != it->end()) {
            return (*it)[name];
        }
    }
    return nullptr;
}

// Analizador Semántico

/**
 * @brief Constructor del analizador semántico.
 */
SemanticAnalyzer::SemanticAnalyzer() {}

/**
 * @brief Indica si existen errores semánticos.
 * @return true si hay errores, false en caso contrario.
 */
bool SemanticAnalyzer::has_errors() const {
    return !errors.empty();
}

/**
 * @brief Imprime el resultado del análisis semántico, muestra un mensaje de éxito
 * o la lista de errores encontrados.
 */
void SemanticAnalyzer::print_results() const {
    if (errors.empty()) {
        std::cout << "\033[1;32m[SEMANTIC] Exito: No se encontró ningún error semántico.\033[0m\n";
    } else {
        std::cout << "\033[1;31m[SEMANTIC] Encontrado " << errors.size() << " error(es):\033[0m\n";
        for (const auto& err : errors) {
            std::cerr << " -> " << err << "\n";
        }
    }
}

/**
 * @brief Registra un error semántico.
 * @param msg Mensaje del error.
 * @param linea Línea donde ocurre.
 */
void SemanticAnalyzer::report_error(const std::string& msg, int linea) {
    errors.push_back("Linea " + std::to_string(linea) + ": " + msg);
}

/**
 * @brief Convierte una cadena a un tipo de dato.
 * @param type_str Representación textual del tipo.
 * @return Tipo correspondiente.
 */
DataType SemanticAnalyzer::stringToDataType(const std::string& type_str) {
    if (type_str == "int") return DataType::INT;
    if (type_str == "flt") return DataType::FLOAT;
    if (type_str == "str") return DataType::STRING;
    if (type_str == "bl")  return DataType::BOOL;
    if (type_str == "arr") return DataType::ARRAY;
    return DataType::VOID;
}

/**
 * @brief Determina el tipo resultante entre dos operandos,
 * implementa reglas de promoción: BOOL < INT < FLOAT.
 * @param t1 Tipo izquierdo.
 * @param t2 Tipo derecho.
 * @return Tipo resultante o ERROR si son incompatibles.
 */
DataType SemanticAnalyzer::get_priority_type(DataType t1, DataType t2) {
    if (t1 == DataType::ERROR || t2 == DataType::ERROR) return DataType::ERROR;
    if (t1 == t2) return t1;

    if (t1 == DataType::FLOAT && (t2 == DataType::INT || t2 == DataType::BOOL)) return DataType::FLOAT;
    if (t2 == DataType::FLOAT && (t1 == DataType::INT || t1 == DataType::BOOL)) return DataType::FLOAT;

    if (t1 == DataType::INT && t2 == DataType::BOOL) return DataType::INT;
    if (t2 == DataType::INT && t1 == DataType::BOOL) return DataType::INT;

    return DataType::ERROR;
}

/**
 * @brief Verifica compatibilidad de tipos en asignaciones, permite promociones
 * implícitas según reglas del lenguaje.
 * @param expected Tipo esperado.
 * @param actual Tipo recibido.
 * @param context Contexto del error.
 * @param linea Línea del error.
 */
void SemanticAnalyzer::check_types(DataType expected, DataType actual, const std::string& context, int linea) {
    if (expected == DataType::ERROR || actual == DataType::ERROR) return;
    if (expected == actual) return;

    if (expected == DataType::INT && actual == DataType::BOOL) return;
    if (expected == DataType::FLOAT && (actual == DataType::INT || actual == DataType::BOOL)) return;

    report_error("Tipo distinto " + context + ".", linea);
}

/**
 * @brief Recorre recursivamente el árbol y evalúa tipos.
 * @param node Nodo actual del AST.
 */
void SemanticAnalyzer::analyze(Node* node) {
    if (!node) return;

    // Literales
    if (node->kind == "Integer") { node->evaluated_type = (int)DataType::INT; return; }
    if (node->kind == "Float")   { node->evaluated_type = (int)DataType::FLOAT; return; }
    if (node->kind == "String")  { node->evaluated_type = (int)DataType::STRING; return; }
    if (node->kind == "True" || node->kind == "False") {
        node->evaluated_type = (int)DataType::BOOL; return;
    }

    // Identificadores
    if (node->kind == "Identifier") {
        auto sym = table.lookup(node->value);
        if (!sym) {
            report_error("Variable '" + node->value + "' no ha sido declarada.", node->linea);
            node->evaluated_type = (int)DataType::ERROR;
        } else {
            node->evaluated_type = (int)sym->type;
        }
        return;
    }

    // Despacha por tipo de nodo
    if (node->kind == "Declaration") { handle_declaration(node); return; }
    if (node->kind == "Assignment")  { handle_assignment(node); return; }
    if (node->kind == "Operation")   { handle_operation(node); return; }
    if (node->kind == "Conditional") { handle_conditional(node); return; }
    if (node->kind == "Loop")        { handle_loop(node); return; }
    if (node->kind == "Function")    { handle_function(node); return; }

    if (node->kind == "Comparison") {
        analyze(node->children[0]);
        analyze(node->children[1]);
        node->evaluated_type = (int)DataType::BOOL;
        return;
    }

    for (auto child : node->children) {
        analyze(child);
    }
}

/**
 * @brief Maneja declaraciones de variables.
 */
void SemanticAnalyzer::handle_declaration(Node* node) {
    DataType type = stringToDataType(node->children[0]->value);

    if (!table.insert(node->value, Category::VARIABLE, type)) {
        report_error("Redeclaración de la variable '" + node->value + "'.", node->linea);
    }

    if (node->children.size() > 1) {
        analyze(node->children[1]);
        check_types(type, (DataType)node->children[1]->evaluated_type,
                    "inicialización de '" + node->value + "'", node->linea);
    }

    node->evaluated_type = (int)type;
}

/**
 * @brief Maneja asignaciones.
 */
void SemanticAnalyzer::handle_assignment(Node* node) {
    auto sym = table.lookup(node->value);

    if (!sym) {
        report_error("Asignación a variable no declarada '" + node->value + "'.", node->linea);
        node->evaluated_type = (int)DataType::ERROR;
        return;
    }

    analyze(node->children[0]);
    check_types(sym->type, (DataType)node->children[0]->evaluated_type,
                "asignación '" + node->value + "'", node->linea);

    node->evaluated_type = (int)sym->type;
}

/**
 * @brief Maneja operaciones aritméticas.
 */
void SemanticAnalyzer::handle_operation(Node* node) {
    analyze(node->children[0]);
    analyze(node->children[1]);

    DataType left = (DataType)node->children[0]->evaluated_type;
    DataType right = (DataType)node->children[1]->evaluated_type;

    DataType result = get_priority_type(left, right);

    if (result == DataType::ERROR && left != DataType::ERROR && right != DataType::ERROR) {
        report_error("Tipo inválido en operación '" + node->value + "'.", node->linea);
    }

    node->evaluated_type = (int)result;
}

/**
 * @brief Maneja estructuras condicionales.
 */
void SemanticAnalyzer::handle_conditional(Node* node) {
    table.push_scope();

    analyze(node->children[0]);
    check_types(DataType::BOOL, (DataType)node->children[0]->evaluated_type,
                "condición IF", node->linea);

    analyze(node->children[1]);
    table.pop_scope();

    if (node->children.size() > 2) {
        table.push_scope();
        analyze(node->children[2]);
        table.pop_scope();
    }
}

/**
 * @brief Maneja ciclos.
 */
void SemanticAnalyzer::handle_loop(Node* node) {
    table.push_scope();

    for (auto child : node->children) {
        analyze(child);
    }

    table.pop_scope();
}

/**
 * @brief Maneja definiciones de funciones.
 */
void SemanticAnalyzer::handle_function(Node* node) {
    std::string func_name = node->value.substr(3);

    table.insert(func_name, Category::FUNCTION, DataType::VOID);

    table.push_scope();

    for (auto child : node->children) {
        if (child->kind == "Parameters") {
            for (auto param : child->children) {
                DataType p_type = stringToDataType(param->children[0]->value);
                table.insert(param->value, Category::VARIABLE, p_type);
            }
        } else {
            analyze(child);
        }
    }

    table.pop_scope();
}