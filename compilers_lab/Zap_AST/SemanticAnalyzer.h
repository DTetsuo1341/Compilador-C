#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include "ast.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>

/**
 * @enum DataType
 * @brief Representa los tipos de datos soportados por el lenguaje.
 */
enum class DataType { INT, FLOAT, STRING, BOOL, ARRAY, VOID, ERROR };

/**
 * @enum Category
 * @brief Define la categoría de un símbolo dentro de la tabla.
 */
enum class Category { VARIABLE, FUNCTION };

/**
 * @struct Symbol
 * @brief Representa una entrada en la tabla de símbolos.
 */
struct Symbol {
    std::string name;   ///< Nombre del identificador
    Category category;  ///< Categoria
    DataType type;      ///< Tipo de dato
    int depth;          ///< Nivel de ámbito (0 = global, 1 = local, etc.)
    
    /**
     * @brief Constructor de la estructura Symbol.
     * @param n Nombre del símbolo.
     * @param cat Categoría del símbolo.
     * @param t Tipo de dato.
     * @param d Nivel de profundidad (scope).
     */
    Symbol(std::string n, Category cat, DataType t, int d)
        : name(n), category(cat), type(t), depth(d) {}
};

/**
 * @class SymbolTable
 * @brief Gestiona la tabla de símbolos utilizando ámbitos anidados.
 */
class SymbolTable {
private:
    
    /**
     * @brief Pila de ámbitos.
     * Cada elemento representa un scope con sus símbolos.
     */
    std::vector<std::unordered_map<std::string, std::shared_ptr<Symbol>>> scopes;

public:

    /**
     * @brief Constructor de la tabla de símbolos.
     * Inicializa el ámbito global.
     */
    SymbolTable();

    /**
     * @brief Crea un nuevo ámbito.
     * Se utiliza al entrar a un bloque.
     */
    void push_scope();
    
    /**
     * @brief Elimina el ámbito actual.
     * Se utiliza al salir de un bloque.
     */
    void pop_scope();

    /**
     * @brief Inserta un nuevo símbolo en el ámbito actual.
     * @param name Nombre del símbolo.
     * @param cat Categoría (variable o función).
     * @param type Tipo de dato.
     * @return true si la inserción fue exitosa, false si ya existe en el mismo ámbito.
     */
    bool insert(const std::string& name, Category cat, DataType type);

    /**
     * @brief Busca un símbolo en todos los ámbitos.
     * @param name Nombre del símbolo a buscar.
     * @return Puntero al símbolo si existe, nullptr en caso contrario.
     */
    std::shared_ptr<Symbol> lookup(const std::string& name);
};

/**
 * @class SemanticAnalyzer
 * @brief Realiza el análisis semántico del AST.
 */
class SemanticAnalyzer {
private:
    SymbolTable table;                  ///< Tabla de simbolos
    std::vector<std::string> errors;    ///< Lista errores semantico

    /**
     * @brief Convierte una cadena a un tipo de dato.
     * @param type_str Cadena que representa el tipo.
     * @return Tipo de dato correspondiente.
     */
    DataType stringToDataType(const std::string& type_str);
    
    /**
     * @brief Determina el tipo dominante entre dos tipos.
     * @param t1 Primer tipo.
     * @param t2 Segundo tipo.
     * @return Tipo resultante.
     */
    DataType get_priority_type(DataType t1, DataType t2);

    /**
     * @brief Verifica compatibilidad de tipos.
     * @param expected Tipo esperado.
     * @param actual Tipo recibido.
     * @param context Contexto del error.
     * @param linea Número de línea.
     */
    void check_types(DataType expected, DataType actual, const std::string& context, int linea);
    
    /**
     * @brief Registra un error semántico.
     * @param msg Mensaje de error.
     * @param linea Línea donde ocurrió el error.
     */
    void report_error(const std::string& msg, int linea);

    /** @brief Maneja declaraciones de variables. */
    void handle_declaration(Node* node);

    /** @brief Maneja asignaciones. */
    void handle_assignment(Node* node);

    /** @brief Maneja operaciones. */
    void handle_operation(Node* node);

    /** @brief Maneja estructuras condicionales. */
    void handle_conditional(Node* node);

    /** @brief Maneja ciclos. */
    void handle_loop(Node* node);

    /** @brief Maneja declaraciones de funciones. */
    void handle_function(Node* node);

public:
    /**
     * @brief Constructor del analizador semántico.
     */
    SemanticAnalyzer();

    /**
     * @brief Inicia el análisis semántico del AST.
     * @param node Nodo raíz del AST.
     */
    void analyze(Node* node);

    /**
     * @brief Indica si se encontraron errores.
     * @return true si hay errores, false en caso contrario.
     */
    bool has_errors() const;

    /**
     * @brief Imprime los resultados del análisis.
     */
    void print_results() const;
};

#endif 