#pragma once
#include <string>

/**
 * @enum TACOp
 * @brief Opcodes del conjunto de instrucciones FIS-25.
 */
enum class TACOp {
    // Memoria
    VAR,            ///< VAR <dest>
    ASSIGN,         ///< ASSIGN <src> <dest>

    // Aritmética
    ADD, SUB, MUL, DIV, MOD, POW,

    // Comparación (resultado booleano)
    EQ, NEQ, GT, GTE, LT, LTE,

    // Control de flujo
    LABEL,          ///< LABEL <nombre>
    GOTO,           ///< GOTO <label>
    IF_GOTO,        ///< IF <cond> GOTO <label>
    IFFALSE_GOTO,   ///< IFFALSE <cond> GOTO <label>

    // Subrutinas
    PARAM,          ///< PARAM <val>        — apila argumento antes de GOSUB
    PARAM_GET,      ///< PARAM_GET <dest>   — recupera argumento dentro de la función
    GOSUB,          ///< GOSUB <fn>
    RETURN,         ///< RETURN             — devuelve control; valor viaja en _ret

    // I/O
    PRINT,          ///< PRINT <val>
    INPUT,          ///< INPUT <dest>
    PIXEL,          ///< PIXEL <x> <y> <c>
    KEY             ///< KEY <k> <dest>
};

/**
 * @struct TACInstruction
 * @brief Una instrucción de tres direcciones para la arquitectura FIS-25.
 *
 * Los campos que no aplican a una instrucción se dejan vacíos ("").
 *
 *  Instrucción       | arg1       | arg2   | result
 *  ------------------|------------|--------|--------
 *  VAR               |            |        | nombre
 *  ASSIGN            | src        |        | dest
 *  ADD/SUB/…         | op1        | op2    | dest
 *  EQ/NEQ/…          | op1        | op2    | dest
 *  LABEL             |            |        | nombre
 *  GOTO              |            |        | label
 *  IF_GOTO           | cond       |        | label
 *  IFFALSE_GOTO      | cond       |        | label
 *  PARAM             | val        |        |
 *  PARAM_GET         |            |        | dest
 *  GOSUB             |            |        | fn
 *  RETURN            |            |        |
 *  PRINT             | val        |        |
 *  INPUT             |            |        | dest
 *  PIXEL             | x          | y      | c
 *  KEY               | k          |        | dest
 */
struct TACInstruction {
    TACOp       op;
    std::string arg1;
    std::string arg2;
    std::string result;

    TACInstruction(TACOp op,
                   std::string arg1   = "",
                   std::string arg2   = "",
                   std::string result = "")
        : op(op), arg1(std::move(arg1)),
          arg2(std::move(arg2)), result(std::move(result)) {}

    /** @brief Serializa la instrucción al formato textual FIS-25. */
    std::string to_string() const;
};