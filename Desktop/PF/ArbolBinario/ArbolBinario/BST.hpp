//
//  BST.hpp
//  ArbolBinario
//
//  Created by Matías Méndez on 20/10/20.
//

#ifndef BST_hpp
#define BST_hpp
#include "BinaryTree.hpp"

#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
class BST : public BinaryTree<T>
{
    
public:
    //constructor vacio ehredado y también se hereda el apuntador a root
    BST() {};
    virtual ~BST() { };
    
    //al hacer una busqueda se te regresará  un apuntador al objeto
    TreeNode<T> * search(const T &) const;
    bool insert(T &);
    bool insert(TreeNode<T> * );
    
    void visit(int);
    
    
private:
    /* Ocultar algunos métodos heredados */
    //using BinaryTree<T>::insert;
};

/*Complejidad: */
template <class T>
void BST<T>::visit(int opcion){
    
    if (opcion < 1 && opcion > 4) {
        cout << "entrada no valida";
    }
    
    else{
        switch (opcion) {
            case 1:
                preOrden();
                break;
                
            case 2:
                inOrden();
                break;
                
            case 3:
                postOrden();
                break;
                
            default:
                break;
        }
        
        
    }//else
    
    
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
#endif /* BST_hpp */
