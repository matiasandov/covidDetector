//
//  BinaryTree.hpp
//  ArbolBinario
//
//  Created by Matías Méndez on 13/10/20.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

#include "TreeNode.hpp"





template <class T>
class BinaryTree {
protected:
    TreeNode<T> * root = nullptr;
    
public:
    int cont = 0;
    //constructor empieza vacío
    BinaryTree() {}
    virtual ~BinaryTree();
    
    TreeNode<T> * getRoot();
    
    /* Insertar un nodo en el árbol */
    bool insert(T &, TreeNode<T> *);
    bool insert(TreeNode<T> *, TreeNode<T> *);
    
    bool empty() const;
    
    /* Eliminar un nodo del árbol: se pone en virtual para poder heredar
    virtual TreeNode<T> * remove(T &); */
    
    /* Eliminar todos los nodos del árbol */
    void clear();
    void clear(TreeNode<T> * );
    
    
    /* Recorridos de un árbol */
    void preOrden() const;
    void preOrden(TreeNode<T> *) const;

    void inOrden() const;
    void inOrden(TreeNode<T> *) const;
    
    void top(int );
    void top(TreeNode<T> *, int &, int &  ) ;
    
    int topN(TreeNode<T> *, int , int   ) ;
    
    void postOrden() const;
    void postOrden(TreeNode<T> *) const;
    
    void levelByLevel() const;
    void levelByLevel(TreeNode<T> *) const;
    
};
template <class T>
TreeNode<T> *  BinaryTree<T>::getRoot(){
    return this->root;
}



template <class T>
void BinaryTree<T>::top(int nTop){
    
    this->top( this->root, nTop, this->cont );
}

template <class T>
void BinaryTree<T>::top(TreeNode<T> * node, int & nTop, int & contP  ) {
    
    if ((node != nullptr) && (contP <= nTop) ) {
        
        
        
        top( node->getRight(), nTop,  contP );
        
        std::cout << *node << " ";
        cout << " este es el cont "<< contP++;
        
        top( node->getLeft(), nTop,  contP );
        
    }
    
}

template <class T>
int BinaryTree<T>::topN(TreeNode<T> * node, int  nTop, int  contP  ) {
    
    if ((node != nullptr) && (contP < nTop) ) {
        
        contP = topN( node->getRight(), nTop,  contP );
        
        if (contP < nTop){
            std::cout << *node << " ";
        } else return contP;
        
        
        contP = topN( node->getLeft(), nTop,  contP );
        
    }
    return contP;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    this->clear();
}

template <class T>
bool BinaryTree<T>::empty() const
{
    return this->root == nullptr;
}

/* Insertar un nodo en el árbol */
template <class T>
bool BinaryTree<T>::insert(T & value, TreeNode<T> * parent)
{
    return this->insert( new TreeNode<T>(value), parent );
}

template <class T>
bool BinaryTree<T>::insert(TreeNode<T> * node, TreeNode<T> * parent)
{
    /* Declarar variable para saber si se insertó el nodo */
    bool inserted = false;
    
    /* Verificar si el árbol está vacío */
    if (this->root == nullptr) {
        /* Establecer el nodo como raíz */
        this->root = node;
    }
    else if (parent == nullptr)
    {
        /* Insertar un nuevo nodo raiz */
        node->setLeft(root);
        root = node;
    }
    else {
        if (parent->getLeft() == nullptr) {
            parent->setLeft(node);
            inserted = true;
        }
        else if (parent->getRight() == nullptr) {
            parent->setRight(node);
            inserted = true;
            }
        else {
            inserted = insert(node, parent->getLeft() );
            if (!inserted) {
                insert(node, parent->getRight() );
            }
        }
    }
    
    return inserted;
}

/* Eliminar un nodo del árbol
template <class T>
TreeNode<T> * BinaryTree<T>::remove(T &)
{
    
}*/

/* Eliminar todos los nodos del árbol */
template <class T>
void BinaryTree<T>::clear()
{
    this->clear(this->root);
    this->root = nullptr;
}

template <class T>
void BinaryTree<T>::clear(TreeNode<T> * node)
{
    if (node != nullptr) {
        clear( node->getLeft() );
        clear( node->getRight() );
        delete node;
    }
}

/* Recorridos de un árbol */
template <class T>
void BinaryTree<T>::preOrden() const
{
    this->preOrden( this->root );
}

template <class T>
void BinaryTree<T>::preOrden(TreeNode<T> * node) const
{
    if (node != nullptr) {
        /* Procesar el nodo */
        std::cout << *node << " ";
        
        /* Desplazarse a la izquierda */
        preOrden( node->getLeft() );
        
        /* Desplazarse a la derecha */
        preOrden( node->getRight() );
    }
}

template <class T>
void BinaryTree<T>::inOrden() const
{
    this->inOrden( this->root );
}

template <class T>
void BinaryTree<T>::inOrden(TreeNode<T> * node) const
{
    if (node != nullptr) {
        /* Desplazarse a la izquierda */
        inOrden( node->getLeft() );
        
        /* Procesar el nodo */
        std::cout << *node << " ";
        
        /* Desplazarse a la derecha */
        inOrden( node->getRight() );
    }
}

template <class T>
void BinaryTree<T>::postOrden() const
{
    this->postOrden( this->root );
}

template <class T>
void BinaryTree<T>::postOrden(TreeNode<T> * node) const
{
    if (node != nullptr) {
        /* Desplazarse a la izquierda */
        postOrden( node->getLeft() );
        
        /* Desplazarse a la derecha */
        postOrden( node->getRight() );
        
        /* Procesar el nodo */
        std::cout << *node << " ";
    }
}

//complejidad lineal O(n)
template <class T>
void  BinaryTree<T>::levelByLevel() const {
    this->levelByLevel( this->root );
}

//complejidad lineal O(n)
template <class T>
void  BinaryTree<T>::levelByLevel(TreeNode<T> *root) const {
    // Base Case
        if (root == NULL) return ;
    
    // QUE PARA debe llevar apuntador por espacio de memoria dinamico
    queue < TreeNode<T> *> q;
  
    // Enqueue Root and PARA  height
    q.push(root);
    
  //mientras no este vacio
    while (q.empty() == false)
    {
        
        //contador de numero de nodos en el nivela actual
        int nodeCount = q.size();
  
       
        //ciclo dentro del nivel donde imprimirá cada nodo del nivel
        while (nodeCount > 0)
        {
            TreeNode<T> *actualFrente = q.front();
            //imprime el nodo al fronte
            cout << actualFrente->getInfo() << " ";
            
            //borra nodo al frente y pasará al siguiente en el nuevo ciclo
            q.pop();
            
            //si hay uno a la izquierda lo agrega al Queue para imprimirlo
            if (actualFrente->getLeft() != NULL)
                q.push(actualFrente->getLeft() );
            
            //lo mismo con derecho
            if (actualFrente->getRight() != NULL)
                q.push(actualFrente->getRight() );
            nodeCount--;
        }
        cout << endl;
    }
}

#endif
