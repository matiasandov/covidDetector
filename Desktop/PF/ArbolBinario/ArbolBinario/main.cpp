//
//  main.cpp
//  ArbolBinario
//
//  Created by Matías Méndez on 13/10/20.
//

#include <iostream>
#include "TreeNode.hpp"
#include "BinaryTree.hpp"
#include "BST.hpp"

int main(int argc, const char * argv[]) {
    /* Creación de un BinaryTree vacío */
        std::cout << std::endl;
        std::cout << "--- Demostración del uso de un Binary Tree ---" << std::endl;
        std::cout << std::endl;
        
        /* Crear un árbol */
        std::cout << "(C) Se crea un árbol vacío" << std::endl;
        BST<int> * tree = new BST<int>();
        
        /* Insertar nodos en el árbol */
        
        std::cout << "(I) Se insertó la raiz" << std::endl;
        TreeNode<int> * root = new TreeNode<int>(5);
        
        //cuando algo este mal pon la flechita para evr que muestra y no te estreses
    
    //creacion de BST
        tree->BinaryTree<int>::insert(root, nullptr);
        
        std::cout << "(I) Se insertaron algunos nodos" << std::endl;
        
        TreeNode<int> * a = new TreeNode<int>(2);
        TreeNode<int> * b = new TreeNode<int>(7);
        TreeNode<int> * c = new TreeNode<int>(4);
        TreeNode<int> * d = new TreeNode<int>(1);
        TreeNode<int> * e = new TreeNode<int>(6);
        TreeNode<int> * f = new TreeNode<int>(3);
        /*
        tree->BinaryTree<int>::insert(a, root);
        tree->BinaryTree<int>::insert(b, root);
        tree->BinaryTree<int>::insert(c, root);
        tree->BinaryTree<int>::insert(d, root);
        
        tree->BinaryTree<int>::insert(e, b);
        tree->BinaryTree<int>::insert(f, b);*/
    //
    tree->insert(a);
    tree->insert(b);
    tree->insert(c);
    tree->insert(d);
    tree->insert(e);
    tree->insert(f);
    
    
        
    std::cout << "(PV) Imprimir en niveles (Complejidad 0(n)) " << std::endl;
        tree->visit(4);
    cout << std::endl;
    
    std::cout << "(PH) Altura del arbol (Complejidad 0(n)) " << std::endl;
    cout << tree->height() << std::endl;
    
    std::cout << "(PA) Ancestro de nodo 'f' (Complejidad 0(n)) " << std::endl;
    tree->ancestors(f);
    
    std::cout << "(PA) Altura de nodo 'c' (Complejidad logaritmica si el arbol esta balanceado y sino complejidad lineal) " << std::endl;
    cout << tree->whatLevelamI(c) << std::endl;
    
        
        
        std::cout << "(C) Se eliminan todos los nodos del árbol" << std::endl;
        tree->clear();
        
        /* Determinar si el árbol está vacío */
        std::cout << (tree->empty() ? "(E) El árbol está vacío" : "(E) El árbol tiene elementos") << std::endl;
        
        /* Eliminar la memoria ocupada por el árbol */
        delete tree;
        std::cout << "(D) Se liberó la memoria del árbol" << std::endl;
        
        
       
        
        
    return 0;
}
