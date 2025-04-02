/** C++ implementation for Red-Black Tree Insertion
http://quiz.geeksforgeeks.org/c-program-red-black-tree-insertion/
   This code is adopted from the code provided by
   Dinesh Khandelwal in comments **/
/********************************
* Autor:Juan Esteban Bello 
* Materia: Estructuras de Datos                 
* Tema: Red Black Tree
*********************************/

#include <bits/stdc++.h>
#include "redblacktree.h"
using namespace std;

int main()
{
    RBTree tree;
 
    tree.insert(11);
    tree.insert(19);
    tree.insert(7);
    tree.insert(14);
    tree.insert(17);
    tree.insert(31);
    tree.insert(26);
    tree.insert(45);
    tree.insert(70);
   
    cout << "Inoder Traversal of Created Tree\n";
    tree.inorder();
 
    cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
    cout << "\n";
 
    return 0;
}
// Conclusión: Al insertar los valores de las diapositivas vistas en clase (las cuales presentan el ejercicio incompleto) se observa que el resultado in order final es : 7 11 14 17 19 26 31 45 70
// y Level Order es 17 11 26 7 14 19 45 31 70
