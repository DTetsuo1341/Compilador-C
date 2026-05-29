#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include "ast.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>

enum class DataType { INT, FLOAT, STRING, BOOL, ARRAY, VOID, ERROR, UNKNOWN };
enum class Category { VARIABLE, FUNCTION };

struct Symbol {
    std::string name;
    Category    category;
    DataType    type;
    int         depth;

    Symbol(std::string n, Category cat, DataType t, int d)
        : name(n), category(cat), type(t), depth(d) {}
};

class SymbolTable {
private:
    std::vector<std::unordered_map<std::string, std::shared_ptr<Symbol>>> scopes;
public:
    SymbolTable();
    void push_scope();
    void pop_scope();
    bool insert(const std::string& name, Category cat, DataType type);
    std::shared_ptr<Symbol> lookup(const std::string& name);
};

class SemanticAnalyzer {
private:
    SymbolTable              table;
    std::vector<std::string> errors;

    DataType stringToDataType(const std::string& type_str);
    DataType get_priority_type(DataType t1, DataType t2);
    void     check_types(DataType expected, DataType actual,
                         const std::string& context, int linea);
    void     report_error(const std::string& msg, int linea);

    /**
     * @brief Recorre el cuerpo de una función ya analizado y deduce
     *        el tipo de retorno dominante a partir de los nodos Return.
     *        No entra en definiciones de funciones anidadas.
     */
    DataType infer_return_type(Node* node);

    void handle_declaration (Node* node);
    void handle_assignment  (Node* node);
    void handle_operation   (Node* node);
    void handle_conditional (Node* node);
    void handle_loop        (Node* node);
    void handle_function    (Node* node);

    /**
     * @brief Analiza los argumentos de una llamada a función y asigna
     *        al nodo Call el tipo de retorno registrado en la tabla.
     */
    void handle_call(Node* node);

public:
    SemanticAnalyzer();
    void analyze(Node* node);
    bool has_errors() const;
    void print_results() const;
};

#endif