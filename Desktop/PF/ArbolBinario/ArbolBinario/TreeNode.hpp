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
class TreeNode{
private:
    //debe tener la info y un apunatdor a otro nodo
    T info;
    //nullptr es porque no sabes que hay despues pero sabes que habra algo
    TreeNode<T> * left = nullptr;
    
    TreeNode<T> * right = nullptr;
    
public:
    TreeNode(){};
    //constructor por parametro: pasas un objeto por referencia, para que si se hace un cambio, se guarde en el objeto, lo que estas pasando es una direccion en memoria, si se hace un cambio, se queda el cambio en memoria
    
    TreeNode( const T & _info): info (_info){};
    
    //esta es para crear un nodo a aprtir de otro Node, o sea crear una copia
    TreeNode( const TreeNode<T> & );
    
    //destructor del obejto para no alamcenar mucho en memoria y liberrla al decir delete
    virtual ~TreeNode();
    
    T getInfo() const{return info;}
    //pasar referencias en lugar de copiar apuntador
    void setInfo(T & value){ info = value;}
    
    //esto regresara un apuntador al siguiente nodo tipo T
    
    TreeNode<T> * getNext() const { return next; }
    
    //metodo set recibira un apuntador nomas, o sea el valor que reciba
    void setNext(TreeNode<T> * value){ next = value;}
    /* Sobrecarga operador == */
    bool operator ==(TreeNode<T> &);
    
    //es importante saber que aqui debes poner Tn para que no se confunda con T porque es una funcion generica FRIEND
    template <typename Tn>
        friend ostream & operator << (ostream & os, const TreeNode<Tn> & node);
    
};



template <class T>
//constructor de copia: cuando creas un nodo a partir de otro, por eso con other te referies a que del otro nodo que quieras clonar, le asignas la info y el apuntador del nodo que quieres clonar
Node<T>::Node(const TreeNode<T> & other){
    
    info = other.info;
    next = other.next;
    
}

//destructor
template <class T>
Node<T>::~Node(){
    info.~T();
    next = nullptr;
}

template <class T>
//se sobrecarga de alguna maner el == para hacer una copia
bool Node<T>::operator ==(Node<T> & other)
{
    return (info == other.info) && (next == other.next);
}

template <class T>
//solo se imprimira el atributo info
std::ostream & operator << (std::ostream & os, const Node<T> & node)
{
    os << node.info;
    
    return os;
}

#endif /* Node_hpp */
#endif /* TreeNode_hpp */
