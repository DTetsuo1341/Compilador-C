#include "ast.h"
#include <iostream>
#include <fstream>

Node::Node(const std::string& kind, const std::string& value, int linea) {
    this->kind = kind;
    this->value = value;
    this->linea = linea;
}

Node::~Node() {
    // libera hijos en cascada, delete llama al destructor de cada hijo
    for (Node* child : children)
        delete child;
}

void Node::add_child(Node* child) {
    if (child) children.push_back(child);
}

void Node::print(const std::string& prefix, bool is_last) const {
    // conector visual según posición en la lista de hermanos
    std::string connector = is_last ? "└── " : "├── ";
    std::string label     = value.empty() ? kind : kind + " (" + value + ")";

    std::cout << prefix << connector << label << "\n";

    // el prefijo que heredan los hijos depende de si somos el último hermano
    std::string child_prefix = prefix + (is_last ? "    " : "│   ");

    for (size_t i = 0; i < children.size(); i++)
        children[i]->print(child_prefix, i == children.size() - 1);
}

void Node::gen_dot(const std::string& filename) const {
    std::ofstream out(filename);
    out << "digraph AST {\n";
    out << "    node [shape=box, fontname=\"monospace\"];\n";

    int id = 0;
    dot_recursive(out, -1, id);

    out << "}\n";
}

/* escapa caracteres que rompen el formato de etiquetas en Graphviz */
static std::string escape_dot(const std::string& s) {
    std::string out;
    for (char c : s) {
        if      (c == '"')  out += "\\\"";
        else if (c == '\\') out += "\\\\";
        else                out += c;
    }
    return out;
}


void Node::dot_recursive(std::ofstream& out, int parent, int& id) const {
    int current = id++;

    // etiqueta del nodo: kind + value si existe
    std::string label = value.empty() ? kind : kind + "\\n" + escape_dot(value);
    out << "    " << current << " [label=\"" << label << "\"];\n";

    // arista desde el padre
    if (parent >= 0)
        out << "    " << parent << " -> " << current << ";\n";

    for (Node* child : children)
        child->dot_recursive(out, current, id);
}