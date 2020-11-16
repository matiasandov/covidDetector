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
#include <list>
using namespace std;


//complejidad O(v+e) // MULTILSTA clase grafos
void loadGraph2(int nV, int nE, Graph<int, int> *  graph)
{
    //precondición
    if (nV > 0 && nE > 0 ) {
        //para añadirle al de a ultima posicion todos las aristas restantes después del for
        
       //contar vertex llenados y guardar el valor del ultimo, que realmente será igual a nV
        int contVertex = 0;
        //llenar de vertex
        for (int i = 0; i <= nV ; i++) {
            
            //añadir vertex con valor de i
            graph->addVertex(i);
            
            Edge<int, int>  * arista = new Edge<int, int>(0,graph->nodes[i+1]);
            
            graph->nodes[i]->addEdge(arista);
            contVertex++;
           
        }
        
        //añadir aristas restantes al ultimo vertex de la lista
        if (nV < nE ) {
            for (contVertex; contVertex <= nE; contVertex++) {
                Edge<int, int> *arista = new Edge<int, int>(0,graph->nodes[nV]);
                graph->nodes[nV]->addEdge(arista);
            }
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
    list< Vertex<int, int> > nodos;
    int tam = graph->nodes.size();
    
    //lista para checar los que ya son visitados
    bool *visited = new bool[tam];
        for(int i = 0; i < tam; i++)
            visited[i] = false;
    
    //nodo buscado
    graph->nodes[nodoInicial]->visitado = true;
    nodos.push_back(nodoInicial);
    
    // 'i' will be used to get all adjacent
        // vertices of a vertex
    list<int>::iterator i;
    
    while(!nodos.empty())
       {
           // Dequeue a vertex from queue and print it
           Vertex<int, int> nodoAct = nodos.front();
           cout << nodoAct << " ";
           nodos.pop_front();
           
           /*for (i = graph->nodes[nodoInicial]; i != graph->nodes[tam]; ++i)
                   {
                       if (!visited[*i])
                       {
                           visited[*i] = true;
                           queue.push_back(*i);
                       }
                   }*/
           
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
    
    cout << multilista;
    
    /* Recorrido con BFS
    std::cout << "------ Multilista con BFS ------" << std::endl;
    int nodo_u = 1;
    BFS(multilista, u);*/
    
    delete multilista;
    
    return 0;
}
