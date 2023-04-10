 /*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo.h"

void GRAFO :: destroy()
{
	for (unsigned i=0; i< n; i++)
    {
		LS[i].clear();
		A[i].clear();
		if (dirigido == 1)
        {
            LP[i].clear();
        };
	}
	LS.clear();
	LP.clear();
	A.clear();

}

void GRAFO :: build (char nombrefichero[85], int &errorapertura) {
    ElementoLista     dummy;
	ifstream textfile;
	textfile.open(nombrefichero);
    
	if (textfile.is_open()) {
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
        unsigned i, j, k;
        LS.resize(n); // ajustamos tamaño de sucesor
        if(dirigido == 1) { // Ajustas tamaño del pred
            LP.resize(n);
        }
        for (k = 0; k<m; k++){
            textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
            dummy.j = j - 1;
            LS[i - 1].push_back(dummy);
            if(dirigido == 0) {
                ElementoLista dummy1;
                dummy1.j = i -1;
                dummy1.c = dummy.c;
                LS[j - 1].push_back(dummy1);
            }
            else if (dirigido == 1){
                ElementoLista dummy1;
                dummy1.j = i -1;
                dummy1.c = dummy.c;
                LP[j - 1].push_back(dummy1);
            }
        }
        errorapertura = 0;
    }
}
GRAFO::~GRAFO() {
	destroy();
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) {
	build (nombrefichero, errorapertura);
}

void GRAFO:: actualizar (char nombrefichero[85], int &errorapertura) {
    //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
    destroy();
    //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
    build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido() {
    if (dirigido == 1){
        return true;
    }
    if (dirigido == 0){
        return false;
    }
    return true;
}

void GRAFO::Info_Grafo() {
    if(Es_dirigido() == true ) {
        cout << "Es dirijido  | ";
        cout << "Nodos " << n << " | ";
        cout << "Arcos " << m << " | " << endl;
    }
    if(Es_dirigido() == false ) {
        cout << "Grafo no dirijido ";
        cout << "nodos " << n << " | ";
        cout << "Aristas" << m << " | ";
    }
}

void Mostrar_Lista(vector<LA_nodo> L) {
    for (int r = 0; r < L.size() ; r++) {
        std::cout << "nodo " << r + 1 << ": {";
        for (ElementoLista dummy : L[r]) { // Recorro el vector
            if (L[r].at(L[r].size() - 1).j == dummy.j) {
                std::cout << dummy.j + 1 << " : "; // Nodo sucesor
                std::cout << dummy.c; // Coste
            }
            else {
                std::cout << dummy.j + 1 << " : "; // Nodo sucesor
                std::cout << dummy.c << " , "; // Coste
            }
        }
        std::cout << "}" << std::endl;
    }
}
void GRAFO :: Mostrar_Listas (int l) {
    if (l == -1) {
        std::cout << " =Lista de predecesores== " << std::endl;
        Mostrar_Lista(LP);
    }
    else if(l == 0){
        std::cout << " ==Lista de adyacencia== " << std::endl;
        Mostrar_Lista(LS);
    }
    else if (l == 1){
        std::cout << " ==Lista de sucesores== " << std::endl;
        Mostrar_Lista(LS);
    }
}
/*void GRAFO :: Mostrar_Listas (int l) {
    if (l = 1) { // Sucesores
        std::cout << "--Lista de sucesores--" << std::endl;
        for (int r = 0; r < LP.size() ; r++) {
        std::cout << "Nodo " << r + 1 << ": {";
        for (ElementoLista dummy : LP[r]) {
            if (LP[r].at(LP[r].size() - 1).j == dummy.j) {
                std::cout << dummy.j + 1;
            }
            else {
                std::cout << dummy.j + 1 << ", ";
            }
        }
        std::cout << "}" << std::endl;
        }
    }
    if (l = -1) { // Predecesores
        std::cout << "--Lista de predecesores--" << std::endl;
        for (int r = 0; r < LP.size() ; r++) {
        std::cout << "Nodo " << r + 1 << ": {";
        for (ElementoLista dummy : LP[r]) {
            if (LP[r].at(LP[r].size() - 1).j == dummy.j) {
                std::cout << dummy.j + 1;
            }
            else {
                std::cout << dummy.j + 1 << ", ";
            }
        }
        std::cout << "}" << std::endl;
        }
    }
    if (l = 0) { // Predecesores
        std::cout << "--Lista de adyacencia--" << std::endl
        for (int r = 0; r < LP.size() ; r++) {
        std::cout << "Nodo " << r + 1 << ": {";
        for (ElementoLista dummy : LP[r]) {
            if (LP[r].at(LP[r].size() - 1).j == dummy.j) {
                std::cout << dummy.j + 1;
            }
            else {
                std::cout << dummy.j + 1 << ", ";
            }
        }
        std::cout << "}" << std::endl;
        }
    }
}
*/

void GRAFO::Mostrar_Matriz() {//Muestra la matriz de adyacencia, tanto los nodos adyacentes como sus costes

}

void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) { //Recorrido en profundidad recursivo con recorridos enum y postnum
	visitado[i] = true;
    prenum[prenum_ind++]=i;//asignamos el orden de visita prenum que corresponde el nodo i
    for (unsigned j=0;j<L[i].size();j++)
             if (!visitado[L[i][j].j])
                {
                dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
                };
    postnum[postnum_ind++]=i;//asignamos el orden de visita posnum que corresponde al nodo i
}

void GRAFO::RecorridoProfundidad() {

}

void GRAFO::bfs_num(	unsigned i, //nodo desde el que realizamos el recorrido en amplitud
				vector<LA_nodo>  L, //lista que recorremos, LS o LP; por defecto LS
				vector<unsigned> &pred, //vector de predecesores en el recorrido
				vector<unsigned> &d) { //vector de distancias a nodo i+1
//Recorrido en amplitud con la construccion de pred y d: usamos la cola

    vector<bool> visitado; //creamos e iniciamos el vector visitado
    visitado.resize(n, false);
    visitado[i] = true;

    pred.resize(n, 0); //creamos e inicializamos pred y d
    d.resize(n, 0);
    pred[i] = i;
    d[i] = 0;

    queue<unsigned> cola; //creamos e inicializamos la cola
    cola.push(i);//iniciamos el recorrido desde el nodo i+1

    while (!cola.empty()) //al menos entra una vez al visitar el nodo i+1 y contin�a hasta que la cola se vac�e
    {   unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
        cola.pop(); //lo sacamos de la cola
        //Hacemos el recorrido sobre L desde el nodo k+1
        for (unsigned j=0;j<L[k].size();j++) {
            //Recorremos todos los nodos u adyacentes al nodo k+1
            //Si el nodo u no est� visitado
            int nodo = L[k].at(j).j;
            if (visitado[nodo] == true) {
                continue;
            }
            visitado[nodo] = true;
            cola.push(nodo);
            pred[nodo] = k;
             d[nodo] = d[k] + 1;
            };
        //Hemos terminado pues la cola est� vac�a
    };
}
//Construye un recorrido en amplitud desde un nodo inicial
void GRAFO::RecorridoAmplitud() { // He añadido el Grafo porque sino no se puede usar el metodo bfs y la lista LS
    cout << "Inicio del recorrido en Amplitud del Grafo" << endl;
    int inicial = 1;
    std::vector<unsigned> pred;
    std::vector<unsigned> d;
    bfs_num(inicial, LS, pred, d);
    // imprimimos los resutlados;
    std::cout << "predecesores: " << std::endl;
    int nodo = 1;
    for (auto valor : pred) {
        std::cout << "[" << nodo << "] " << valor + 1 << " ";
        ++nodo;
    }
    std::cout << std::endl;
    std::cout << "distancias: " << std::endl;;
    nodo = 1;
    for (auto valor : d) {
        std::cout << "[" << nodo << "] " << valor << " ";
        ++nodo;
    }
    std::cout << std::endl;
}

