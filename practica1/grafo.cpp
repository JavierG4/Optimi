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
		unsigned i, j, k;
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
    }
    if (dirigido == 1) {
		LS.resize(n);
        LP.resize(n);
        for (k=0;k<m;k++) {
			textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
            dummy.j = j - 1;
            LS[i-1].push_back(dummy);
            dummy.j = i - 1;
            LS[j-1].push_back(dummy);
        }
        for (k=0;k<m;k++) {
			textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
            dummy.j = j - 1;
            LP[i-1].push_back(dummy);
            dummy.j = i - 1;
            LP[j-1].push_back(dummy);
        }
    }
    if (dirigido == 0) {
        LS.resize(n);
        for (k=0;k<m;k++) {
			textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
            dummy.j = j - 1;
            LS[i-1].push_back(dummy);
            dummy.j = i - 1;
            LS[j-1].push_back(dummy);
        }
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

}

void GRAFO::Info_Grafo() {
    if(Es_dirigido() == true ) {
        cout << "Es dirijido  | ";
        cout << "nodos " << LP.size() << " | ";
        cout << "Arcose" <<  << " | ";
    }
    if(Es_dirigido() == false ) {
        cout << "Grafo no dirijido ";
        cout << "nodos " << LP.size() << " | ";
        cout << "Aristas" <<  << " | ";
    }
}

void Mostrar_Lista(vector<LA_nodo> L) {

}

void GRAFO :: Mostrar_Listas (int l) {
    if (l = 1) { // Sucesores
        for(int w = 0; i < LS.size(); w++){
            for(int t = 0; LS[w].size() < LP; t++)
            cout << "[" << w+1 << "] ";
            cout << LS[w][t].j << " : " << LS[w][t].c
        }
    }
}

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
        for (unsigned j=0;j<L[k].size();j++)
            //Recorremos todos los nodos u adyacentes al nodo k+1
            //Si el nodo u no est� visitado
            {
            //Lo visitamos
            //Lo metemos en la cola
            //le asignamos el predecesor
            //le calculamos su etiqueta distancia
            };
        //Hemos terminado pues la cola est� vac�a
    };
}
//Construye un recorrido en amplitud desde un nodo inicial
void RecorridoAmplitud() {



}

