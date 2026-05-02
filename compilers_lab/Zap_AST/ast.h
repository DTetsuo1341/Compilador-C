#pragma once
#include <string>
#include <vector>
#include <fstream>

/**
 * @file ast.h
 * @brief Árbol de Sintaxis Abstracta (AST) para el lenguaje Zap.
 *
 * Se puede recorrer con `print()` o exportar con `gen_dot()`.
 * Cada Node es dueño de sus hijos. Llamar `delete` en la raíz libera
 * todo el árbol recursivamente.
 */
class Node {
public:
    /**
     * @brief Tipo de construcción que representa este nodo.
     */
    std::string kind;

    /**
     * @brief Dato adicional asociado al nodo, vacío si no aplica.
     */
    std::string value;

    /**
     * @brief Hijos del nodo en orden izquierda→derecha.
     */
    std::vector<Node*> children;

    /**
     * @brief Indice de tipo del nodo. 
     */
    int evaluated_type = -1;
    
    /**
     * @brief Línea del código donde está el nodo. 
     */
    int linea = 0;

    /**
     * @brief Construye un nodo con kind y value.
     * @param kind  Tipo de construcción (ver campo kind).
     * @param value Dato adicional, por defecto vacío.
     */
    Node(const std::string& kind, const std::string& value = "", int linea = 0);

    /**
     * @brief Destructor recursivo — libera todos los hijos en cascada.
     */
    ~Node();

    /**
     * @brief Agrega un hijo al final de la lista de hijos.
     * @param child Puntero al nodo hijo. Si es nullptr, no hace nada.
     */
    void add_child(Node* child);

    /**
     * @brief Imprime el árbol en stdout con indentación visual.
     * @param prefix  Prefijo acumulado de indentación (uso interno).
     * @param is_last Indica si este nodo es el último hijo (uso interno).
     */
    void print(const std::string& prefix = "", bool is_last = true) const;

    /**
     * @brief Exporta el AST como archivo .dot.
     * @param filename Ruta del archivo de salida.
     */
    void gen_dot(const std::string& filename) const;

private:
    /**
     * @brief Función auxiliar recursiva para gen_dot.
     * @param out    Stream de salida del archivo .dot.
     * @param parent ID del nodo padre en el grafo.
     * @param id     Contador global de IDs (se incrementa en cada llamada).
     */
    void dot_recursive(std::ofstream& out, int parent, int& id) const;
};