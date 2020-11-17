//
//  main.cpp
//  Graphs
//
//  Created by Matías Méndez on 10/11/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Graph.hpp"
#include <queue>



//complejidad O(v+e) // MULTILSTA clase grafos
void loadGraph2(int nV, int nE, Graph<int, int> *  graph)
{
    //precondición
    if (nV > 0 && nE > 0 ) {
       
        //llenar de vertex
        for (int i = 0; i <= nV ; i++) {
            
            //añadir vertex con valor de i
            graph->addVertex(i);
           
        }
        
        //añadir aristas de manera random
        for (int i = 0; i < nE ; i++) {
            int v1 = rand() % nV +1;
            int v2 = rand() % nV +1;
            int peso = rand() % 10 +1;
            graph->addEdge(graph->nodes[v1], graph->nodes[v2], peso);
        }

        
        
    }
}

//complejidad O(v+e) --- MATRIZ
void loadGraph(int nV, int nE, std::vector < std::vector<int> > & graph)
{
    int contEdges = 0;
    if (nV > 0 && nE > 0 ) {
        for (int i = 0; i <=nV; i++) {
            for (int j = 0; j <=nV; i++) {
                
                //si aun no se han agregado todos nE arcos que se deben agregar, se agregarán
                if (contEdges <= nE) {
                    graph[i][j] = 1;
                    contEdges++;
                }
                //si YA se agregeron todos los arcos que debían agregarse se pondrán 0's
                else{
                    graph[i][j] = 0;
                    
                }
                
                
            }
        }
    }
    
        
}

//complejidad O(v+e)
vector<int> actuales;

void DFS(std::vector < std::vector<int> > & graph, int nodoInicial)
{
    int tam = graph.size();
    
    int bandera = 0;
    int coordI = 0;
    int coordJ = 0;
    
    for (int i = 0; i <= tam ; i++) {
        for (int j = 0; j <= tam; i++) {
            //para checar si si existe el nodo inicial y si si guardar sus coordenadas
            if(nodoInicial == graph[i][j] && nodoInicial == 1 ){
                cout << "\n si existe nodo inicial";
                coordI = i;
                coordJ = j;
                bandera = 1;
            }
        }
    }
    
    
    if (bandera < 1) {
        cout << " no se encontro el nodo incial";
    }
    else{
        
        
        //iniciar ciclo a partir de nodo inicial
        for ( coordI; coordI <= tam; coordI++) {
            for (coordJ; coordJ <= tam; coordJ++){
                
                //si no se ha visitado
                if (graph[coordI][coordJ] == 1) {
                    actuales.push_back(graph[coordI][coordJ]);
                    cout << "\n actual : " <<graph[coordI][coordJ];
                    graph[coordI][coordJ] += 1;
                    
                }
                
                }
            }
        }
}

//complejidad O(v+e)
void BFS(Graph<int, int> * graph, int nodoInicial)
{
    //crear vector
    queue<Vertex<int, int> *> cola;
    
    graph->nodes[nodoInicial]->visitado = true;
    
    cola.push(graph->nodes[nodoInicial]);
    
    cout << "Inicial : " << *graph->nodes[nodoInicial];
    
    while (cola.size() != 0) {
        Vertex<int, int> * actual = cola.front();
        //aquí tendría que borrar??
        cola.pop();
        for (int i = 0; i < actual->edges.size(); i++) {
            if (actual->edges[i]->getTarget()->visitado == false) {
                Vertex<int, int> * incidente = actual->edges[i]->getTarget();
                incidente->visitado = true;
                cola.push(incidente);
                cout << *incidente;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    /* Definir número de vértices y aristas */
    const int vertices = 10;
    const int aristas = 15;
    
    /* Declaración del grafo como matriz de adyacencia
    std::vector < std::vector<int> > matriz_adyacencia;

    //Generar el grafo como matriz de adyacencia
    loadGraph(vertices, aristas, matriz_adyacencia);
     
    //Recorrido con DFS
    std::cout << "------ Matriz de adyacencia con DFS ------" << std::endl;
    int nodo_u = 1;
    DFS(matriz_adyacencia, u);*/
    
    /* Declaración del grafo como multilista */
    Graph<int, int> * multilista = new Graph<int, int>();

    /* Generar el grafo como multilista */
    loadGraph2(vertices, aristas, multilista);
    
    cout << *multilista;
    
    cout << "\n ------ Multilista con BFS ------" << std::endl;
    BFS(multilista, 1);
    
    /* Recorrido con BFS
    std::
    int nodo_u = 1;
    BFS(multilista, u);*/
    
    delete multilista;
    
    return 0;
}
