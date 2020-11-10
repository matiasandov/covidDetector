//
//  BST.hpp
//  ArbolBinario
//
//  Created by Matías Méndez on 21/10/20.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

#include "BinaryTree.hpp"

template <class T>
class BST : public BinaryTree<T>
{
    
public:
    //constructor vacio ehredado y también se hereda el apuntador a root
    BST() {};
    virtual ~BST() { };
    
    //al hacer una busqueda se te regresará  un apuntador al objeto
    TreeNode<T> * search(const T &) const;
    bool search(TreeNode<T> *);
    
    bool insert(T &);
    bool insert(TreeNode<T> * );
    
    void visit(int);
    
    int height(TreeNode<T> *);
    int height();
    
    //si se pone apuntador porque tiene que ir apuntando al de arriba
    //complejidad 0(n)
    void ancestors(TreeNode<T> *);
    
    int whatLevelamI(TreeNode<T> *);
    

};

//Complejidad logaritmica si el arbol esta balanceado y sino complejidad lineal
template <class T>
bool BST<T>::search(TreeNode<T> *buscado){
    
    TreeNode<T> * aux = this->root;
    
    while (aux != nullptr) {
        if (aux->getInfo() == buscado->getInfo() ) {
            return true;
        }
        else {
            aux = aux->getInfo() > buscado->getInfo() ? aux->getLeft() : aux->getRight();
        }
    }
    
    return false;
}


//Complejidad logaritmica si el arbol esta balanceado y sino complejidad lineal
template <class T>
int BST<T>::whatLevelamI( TreeNode<T> * buscado){
    bool encontrado = this->search(buscado);
    
    if (encontrado == true) {
        return height(buscado);
    }else{
        return -1;
    }
    
}


template <class T>
void BST<T>::visit(int opcion){
    
    
        switch (opcion) {
            case 1:
                
                BinaryTree<T>::preOrden();
                break;
                
            case 2:
                BinaryTree<T>::inOrden();
                break;
                
            case 3:
                BinaryTree<T>::postOrden();
                break;
                
                //complejidad lineal O(n)
            case 4:
                BinaryTree<T>::levelByLevel();
                break;
            
            default:
                cout << " Entrada no valida ";
                break;
        }
    
}

//recursivo de complejidad O(n)
template <class T>
int BST<T>::height(){
    return this->height(this->root);
}


//recursivo de complejidad O(n)
template <class T>
int BST<T>::height(TreeNode<T>* actual){
    //si esta vacio sera 0
    if (actual == NULL)
        return 0;
    //en cada ciclo se regresa alturaTotal+1 si se encuentra un arbol en izq o derecha
    else
    {
        /* compute the depth of each subtree */
        //se guardara altura del subarbol izquierdo
        int alturaIzq = height(actual->getLeft());
        //lo mismo apr el derecho
        int alturaDer = height(actual->getRight() );
      
        /* se tiene que usar  la altura máxima de los dos subArboles*/
        if (alturaIzq > alturaDer )
            return(alturaIzq + 1);
        else return(alturaDer + 1);
    }
}



template <class T>
TreeNode<T> * BST<T>::search(const T & value) const
{
    TreeNode<T> * aux = this->root;
    
    while (aux != nullptr) {
        if (aux->getInfo() == value) {
            return aux;
        }
        else {
            aux = aux->getInfo() > value ? aux->getLeft() : aux->getRight();
        }
    }
    
    return nullptr;
}

template <class T>
bool BST<T>::insert(T & value)
{
    return this->insert(new TreeNode<T>(value));
}

template <class T>
bool BST<T>::insert(TreeNode<T> * node )
{
    /* No se puede insertar un nodo NULL */
    if (node == nullptr) return false;
    
    /* Obtener la info del nodo a insertar */
    T value = node->getInfo();
    
    /* Establecer un apuntador auxiliar */
    TreeNode<T> * aux = this->root;
    
    /* Estalecer una variable para el padre */
    TreeNode<T> * parent = nullptr;
    
    /* Buscar la posición que le corresponde */
    while (aux != nullptr) {
        if (aux->getInfo() == value) {
            /* Liberar la memoria del nodo porque ya existe */
            delete node;
            
            return false;
        }
        else {
            parent = aux;
            aux = aux->getInfo() > value ? aux->getLeft() : aux->getRight();
        }
    }
    
    /* Establecer el parent del nodo a insertar */
    node->setParent(parent);
    
    /* Si el árbol está vacío, se inserta la raiz */
    if (parent == nullptr) {
        this->root = node;
    }
    else {
        /* Si el value a insertar es menor, se inserta a la izquierda */
        if ( parent->getInfo() > value ) {
            parent->setLeft(node);
        }
        /* Si el value a insertar es mayor, se inserta a la derecha */
        else {
            parent->setRight(node);
        }
    }
    
    return true;
}

//complejidad lineal
template <class T>
void BST<T>::ancestors(TreeNode<T> * ingresado){
    
    if(ingresado == NULL){
        return;
    }
    
    TreeNode<T> * ancestro = ingresado->getParent();
    
    while(ancestro != NULL){
        //no olvidar poner * para refenciar objetos en direccion
        cout <<endl << *ancestro <<endl;
        ancestro = ancestro->getParent();
    }
    
}


#endif /* BST_hpp */
