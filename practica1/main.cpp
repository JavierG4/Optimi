 /*
 *  Programa principal.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Cursos  : 2012-2021
 */

#include <string.h>
#include "grafo.h"


void menu (unsigned dirigido, char &opcion) {
//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido 

    cout << "Optimiza!cion en Grafos, 2021-2022 NOMBRE DEL ESTUDIANTE" << endl;
    cout << "c. [c]argar grafo desde fichero" << endl;
    if (dirigido == 0) { //Grafo no dirigido
            cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
            cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
            cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
            cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo" << endl;
            cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo" << endl;
            cout << "o. Mostrar c[o]mponentes conexas del grafo" << endl;
            cout << "k. Mostrar árbol generador minimo coste, [k]ruskal" << endl;
            cout << "P. Mostrar árbol generador minimo coste, [p]rim" << endl;
    }
    else {
            cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
            cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
            cout << "p. Mostrar la lista de [p]redecesores del grafo" << endl;
            cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
            cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo por sucesores" << endl;
            cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo por sucesores" << endl;
            cout << "d. Caminos mínimos: [d]ijkstra" << endl;
            cout << "v. Caminos mínimos: Comparamos Dijkstra [v]s BellmanFordEnd" << endl;
            cout << "f. Caminos mínimos: [f]loyd-warshall" << endl;
        };
    cout << "q. Finalizar el programa" << endl;
    cout << "Introduce la letra de la accion a ejecutar  > ";
    cin >> opcion;
};


// El principal es simplemente un gestor de menu, diferenciando acciones para dirigido y para no dirigido, y un men� inicial si no hay un grafo cargado
int main(int argc, char *argv[]) {  
    int error_apertura;
    char nombrefichero[85], opcion;
    //clrscr();
    //Si tenemos el nombre del primer fichero por argumento, es una excepcion, y lo intentamos cargar, si no, lo pedimos desde teclado
    if (argc > 1) {
	cout << "Cargando datos desde el fichero dado como argumento" << endl;
        strcpy(nombrefichero, argv[1]);
    }
    else {
        cout << "Introduce el nombre completo del fichero de datos" << endl;
        cin >> nombrefichero;
    };
    GRAFO G(nombrefichero, error_apertura);
    if (error_apertura == 1) {
        cout << "Error en la apertura del fichero desde argumento: revisa nombre y formato" << endl;
       
    
    }
    else {
        cout<< "Grafo cargado desde el fichero " << nombrefichero << endl;
    

        do {
            menu(G.Es_dirigido(), opcion);
            switch (opcion) {
                case 'c' :    
         	    cout << "Introduce el nombre completo del fichero de datos" << endl;
                    cin >> nombrefichero;
                    G.actualizar(nombrefichero, error_apertura);
                    if (error_apertura == 1) {
                        cout << "Error en la apertura del fichero: revisa nombre y formato : puedes volver a intentarlo" << endl;
                    }
                    else {
                        cout << "Fichero cargado correctamente desde " << nombrefichero << endl;
                    };
                    break;
                    
                case 'i' :
		            cout << "Grafo cargado desde " << nombrefichero << endl;
                    G.Info_Grafo();
                    break;
                    
                case 's':
                    G.Mostrar_Listas(1);
                    break;
                    
                case 'p':
                    G.Mostrar_Listas(-1);
                    break;
                
                case 'a':
                    G.Mostrar_Listas(0);
                    break;
                case 'm':
                    G.RecorridoAmplitud();
                    break;
                case 'P':
                    G.ArbolPrim();
                    break;
            } 


        }     
        while (opcion != 'q');
    }
    cout << "Fin del programa" << endl;
	return(0);
};
