#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <memory>

/**
 * @enum DataType
 * @brief Representa los tipos de datos soportados por el lenguaje.
 */
enum class DataType { INT, FLOAT, STRING, BOOL, ARRAY, VOID, ERROR };

/**
 * @enum Category
 * @brief Define la categoría de un símbolo dentro de la tabla.
 */
enum class Category { VARIABLE, CONSTANT, FUNCTION };

/**
 * @struct Symbol
 * @brief Representa una entrada en la tabla de símbolos.
 */
struct Symbol {
    std::string name;   ///< Nombre del identificador
    Category category;  ///< Categoría del símbolo (variable, constante o función)
    DataType type;      ///< Tipo de dato asociado
    int depth;          ///< Nivel de ámbito (0 = global)
    int linea;          ///< Línea donde se declara el símbolo

    /**
     * @brief Constructor de Symbol.
     * @param n Nombre del símbolo.
     * @param cat Categoría del símbolo.
     * @param t Tipo de dato.
     * @param d Nivel de ámbito.
     * @param l Línea de declaración.
     */
    Symbol(std::string n, Category cat, DataType t, int d, int l)
        : name(n), category(cat), type(t), depth(d), linea(l) {}
};

/**
 * @class SymbolTable
 * @brief Gestiona la tabla de símbolos mediante ámbitos anidados (scopes).
 */
class SymbolTable {
private:
    /**
     * @brief Pila de ámbitos.
     */
    std::vector<std::unordered_map<std::string, std::shared_ptr<Symbol>>> scopes;

public:
    /**
     * @brief Crea un nuevo ámbito.
     */
    void push_scope() {
        scopes.push_back({});
    }

    /**
     * @brief Elimina el ámbito actual.
     */
    void pop_scope() {
        if (!scopes.empty()) scopes.pop_back();
    }

    /**
     * @brief Inserta un símbolo en el ámbito actual.
     * @param name Nombre del símbolo.
     * @param cat Categoría del símbolo.
     * @param type Tipo de dato.
     * @param linea Línea donde se declara.
     * @return true si la inserción fue exitosa.
     * @return false si ya existe un símbolo con el mismo nombre en el ámbito actual.
     */
    bool insert(std::string name, Category cat, DataType type, int linea) {
        auto& current_scope = scopes.back();

        if (current_scope.find(name) != current_scope.end()) {
            return false; // Colisión en el mismo ámbito
        }

        current_scope[name] = std::make_shared<Symbol>(
            name,
            cat,
            type,
            (int)scopes.size() - 1,
            linea
        );

        return true;
    }

    /**
     * @brief Busca un símbolo en la tabla de símbolos.
     * @param name Nombre del símbolo a buscar.
     * @return std::shared_ptr<Symbol> Puntero al símbolo si se encuentra.
     * @return nullptr si no existe en ningún ámbito.
     */
    std::shared_ptr<Symbol> lookup(std::string name) {
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
            if (it->find(name) != it->end()) {
                return (*it)[name];
            }
        }
        return nullptr; // No declarado
    }
};