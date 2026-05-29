#pragma once
#include "ast.h"
#include "tac.h"
#include <vector>
#include <string>

/**
 * @class TACGenerator
 * @brief Recorre el AST y emite instrucciones FIS-25 de tres direcciones.
 *
 * Convención de valor de retorno de funciones:
 *   La variable global `_ret` actúa como registro de retorno.
 *   - Antes de RETURN  →  ASSIGN <expr> _ret
 *   - Después de GOSUB →  ASSIGN _ret <temp>
 *
 * Temporales se declaran con VAR justo antes de su primera asignación (opción A).
 */
class TACGenerator {
public:
    /** @brief Punto de entrada: genera TAC para el AST completo. */
    void generate(Node* root);

    /** @brief Ejecuta los pases de optimización sobre las instrucciones generadas. */
    void optimize();

    /** @brief Imprime el programa TAC en stdout. */
    void print() const;

    /** @brief Escribe el programa TAC en un archivo. */
    void write(const std::string& filename) const;

private:
    std::vector<TACInstruction> instructions;
    int temp_count  = 0;
    int label_count = 0;

    //  Generadores de nombres únicos 
    std::string new_temp();     ///< t0, t1, t2, …
    std::string new_label();    ///< L0, L1, L2, …

    //  Emisión 
    void emit(TACInstruction instr);

    //  Dispatcher principal 
    /**
     * @brief Genera TAC para un nodo y retorna el "lugar" del resultado.
     *
     * El lugar puede ser:
     *   - Un temporal  ("t3")
     *   - Un nombre de variable ("x")
     *   - Un literal   ("42", "3.14", "\"hola\"", "1", "0")
     *   - Vacío ("")   para nodos que no producen valor (statements)
     */
    std::string gen(Node* node);

    //  Handlers por tipo de nodo 
    void        gen_program        (Node* node);
    void        gen_function       (Node* node);
    void        gen_statement_list (Node* node);
    void        gen_declaration    (Node* node);
    void        gen_assignment     (Node* node);
    void        gen_conditional    (Node* node);
    void        gen_loop           (Node* node);
    void        gen_return         (Node* node);
    void        gen_print          (Node* node);
    void        gen_read           (Node* node);
    std::string gen_operation      (Node* node);
    std::string gen_comparison     (Node* node);
    std::string gen_call           (Node* node);

    //  Pases de optimización 
    void pass_dead_code      ();   ///< Elimina código inalcanzable tras GOTO/RETURN
    void pass_redundant_goto ();   ///< Elimina GOTO Lx cuando LABEL Lx es lo siguiente
    void pass_unused_labels  ();   ///< Elimina etiquetas que nadie referencia
    void pass_constant_fold  ();   ///< Evalúa operaciones entre literales en compilación

    static bool        is_literal (const std::string& s);
    static double      to_num     (const std::string& s);
    static std::string fmt_num    (double v);
};