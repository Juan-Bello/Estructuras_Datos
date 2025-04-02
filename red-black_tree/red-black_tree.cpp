/** C++ implementation for Red-Black Tree Insertion
http://quiz.geeksforgeeks.org/c-program-red-black-tree-insertion/
   This code is adopted from the code provided by
   Dinesh Khandelwal in comments **/
#include <bits/stdc++.h>
#include "redblacktree.h"
using namespace std;

int main()
{
    RBTree tree;
 
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
 
    cout << "Inoder Traversal of Created Tree\n";
    tree.inorder();
 
    cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
    cout << "\n";
 
    return 0;
}
 
