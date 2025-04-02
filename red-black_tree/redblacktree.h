#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <bits/stdc++.h>
using namespace std;
 
enum Color {RED, BLACK};
 
struct Node
{
    int data;
    bool color;
    Node *left, *right, *parent;
 
    // Constructor
    Node(int data)
    {
       this->data = data;
       left = right = parent = NULL;
    }
};
 
// Class to represent Red-Black Tree
class RBTree
{
private:
    Node *root;
protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);
public:
    // Constructor
    RBTree() { root = NULL; }
    void insert(const int &n);
    void inorder();
    void levelOrder();

};

#include"redblacktree.hxx"
#endif //REDBLACKTREE_H

