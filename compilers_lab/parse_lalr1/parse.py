import json
import sys

def cargar_gramatica(archivo_gramatica):
    producciones = {}
    prod_id = 0
    
    try:
        with open(archivo_gramatica, 'r') as gramatica:
            for linea in gramatica:
                linea = linea.strip()
                #Read only lines with '->' and get the left and right side of the symbol
                if "->" in linea:
                    izq, der = linea.split("->")
                    izq = izq.strip()
                    
                    #Get the number of symbols to pop from the stack and the simbol 
                    #that will replace
                    simbolos_der = der.split()
                    num_pop = len(simbolos_der)
                    
                    producciones[prod_id] = (izq, num_pop)
                    prod_id += 1
                    
        return producciones
    except FileNotFoundError:
        print(f"ERROR: No se encontró el archivo '{archivo_gramatica}'.")
        sys.exit(1)


def parse(archivo_json, archivo_gramatica, cadena):
    producciones = cargar_gramatica(archivo_gramatica)

    #Get the file
    try:
        with open(archivo_json, 'r') as tabla:
            data = json.load(tabla)
    except FileNotFoundError:
        print(f"Error: No se encontro el archivo '{archivo_json}'")
        return
    
    #Get the info
    terminales = data["terminals"]
    no_terminales = data["nonTerminals"]
    acciones = data["action"]
    shift = data["goto"]

    #Add '$' to the string
    simbolos_cadena = cadena.strip().split()
    simbolos_cadena.append("$")

    #Stack of states
    pila = [0]
    #Position of the string read
    cursor = 0

    while True:
        estado = pila[-1]
        simbolo = simbolos_cadena[cursor]

        if simbolo not in terminales:
            print("Símbolo no perteneciente a la gramatica")
            return False
        
        indice_terminal = terminales.index(simbolo)
        #Get the action to do
        accion = acciones[estado][indice_terminal]

        #ERROR action
        if accion["type"] == "ERROR":
            print("\nRECHAZADO: Error de Sintaxis")
            print(f"\nFallo en el token: '{simbolo}' (Posicion: {cursor})")
            print(f"\nAtascado en el Estado: {estado}")
            esperados = [terminales[i] for i, act in enumerate(acciones[estado]) if act["type"] != "ERROR"]
            print(f"\nSe esperaba: {esperados}")
            return False
        
        #SHIFT action
        elif accion["type"] == "SHIFT":
            #Add the new state to read
            edo_siguiente = accion["value"]
            pila.append(edo_siguiente)
            #Read next symbol
            cursor += 1
        
        #REDUCE action
        elif accion["type"] == "REDUCE":
            #Get the rule
            regla = accion["value"]
            izq, num_pop = producciones[regla]

            #Delete the number of states add because of SHIFT action
            if num_pop > 0:
                pila = pila[:-num_pop]
            
            #Get the top of the stack of states, and the index of the
            #non-terminal symbol
            tope = pila[-1]
            indice_noT = no_terminales.index(izq)

            #Get the new state to move
            goto_estado = shift[tope][indice_noT]

            #If the state is valid continue, else finish
            if goto_estado == -1:
                print(f"\nERROR FATAL: GOTO inválido para el estado '{tope}' con '{izq}'")
                return False
                
            pila.append(goto_estado)

        #ACCEPT action
        elif accion["type"] == "ACCEPT":
            print("\nCadena aceptada")
            return True

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print("Uso: python parse.py <tabla.json> <gramatica.txt> \"<cadena a evaluar>\"")
        print("Ejemplo: python parse.py tabla.json gramatica.txt \"a a * a +\"")
    else:
        parse(sys.argv[1], sys.argv[2], sys.argv[3])