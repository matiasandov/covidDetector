//
//  TreeNode.hpp
//  ArbolBinario
//
//  Created by Matías Méndez on 13/10/20.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp


#include <stdio.h>
#include <iostream>
using namespace std;

//una lista enlazada deberia ser generica

template <class T>
class TreeNode {
private:
    T info;
    
    //los atributos de un nodo arbol son left y right y su padre
    TreeNode<T> * left = nullptr;
    TreeNode<T> * right = nullptr;
    
    TreeNode<T> * parent = nullptr;
    
public:
    /* Constructores */
    TreeNode() { };
    //constructor por parametro: pasas un objeto por referencia, para que si se hace un cambio, se guarde en el objeto, lo que estas pasando es una direccion en memoria, si se hace un cambio, se queda el cambio en memoria

    TreeNode(const T & _info) : info(_info) {};
    //esta es para crear un nodo a aprtir de otro Node, o sea crear una copia

    TreeNode(const TreeNode<T> & );
    
    /* Destructor */
    virtual ~TreeNode();
    
    /* Getter y Setter */
    T getInfo() const { return info; }
    //pasar referencias en lugar de copiar apuntador
    void setInfo(T & value) { info = value; }
    
    
    TreeNode<T> * getLeft() const { return left; }
    void setLeft(TreeNode<T> * value) { left = value; }
    
    TreeNode<T> * getRight() const { return right; }
    void setRight(TreeNode<T> * value) { right = value; }
    
    TreeNode<T> * getParent() const { return parent; }
    void setParent(TreeNode<T> * value) { parent = value; }
    
    /* Sobrecarga operador == */
    bool operator ==(TreeNode<T> &);
    
    /* Sobrecarga operador << */
    template <typename Tn>
    friend std::ostream & operator << (std::ostream & os, const TreeNode<Tn> & node);
};

template <class T>
TreeNode<T>::TreeNode(const TreeNode<T> & other)
{
    info = other.info;
    left = other.left;
    right = other.right;
}

template <class T>
TreeNode<T>::~TreeNode()
{
    info.~T();
    left = nullptr;
    right = nullptr;
}

template <class T>
bool TreeNode<T>::operator ==(TreeNode<T> & other)
{
    return (info == other.info);
}

template <class T>
std::ostream & operator << (std::ostream & os, const TreeNode<T> & node)
{
    os << node.info;
    
    return os;
}


#endif /* TreeNode_hpp */
