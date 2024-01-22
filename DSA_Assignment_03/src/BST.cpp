#include "BST.h"
#include <iostream>
using namespace std;


template <class Comparable>
BST<Comparable>::BST()
{
    //constructor of base class will work
}

template <class Comparable>
BST<Comparable>::BST(BinaryNode<Comparable>* root): BinaryTree<Comparable>(root)
{
    //copy constructor of the base with arguments will handle this
}

template <class Comparable>
BST<Comparable>::~BST()
{
    //destructor of base will work
}

template <class Comparable>
bool BST<Comparable>::search(const Comparable data)
{
    if(BinaryTree<Comparable>::tree_root!=NULL)
    {
        BinaryNode<Comparable>* current=BinaryTree<Comparable>::tree_root;
        while(current!=NULL)
        {
            if(BinaryTree<Comparable>::tree_root->element==data)
            return true;
            if(BinaryTree<Comparable>::tree_root->element>data)
            {
               current=current->left;
            }
            if(BinaryTree<Comparable>::tree_root->element<data)
            {
                current=current->right;
            }
        }
        return false;
    }
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::findMin()                      //min find function
{
    return findMin(BinaryTree<Comparable>::tree_root);
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::findMax()                      //max find function
{
    return findMax(BinaryTree<Comparable>::tree_root);
}

template <class Comparable>
void BST<Comparable>::insert(const Comparable data)                     //insert function
{
    insert(data, BinaryTree<Comparable>::tree_root);
}

template <class Comparable>
void BST<Comparable>::remove(const Comparable data)         //remove function
{
    remove(data, BinaryTree<Comparable>::tree_root);
}

template <class Comparable>
void BST<Comparable>::insert(const Comparable data, BinaryNode<Comparable>*& root)          //core insert element function
{
    if(root==NULL)
    {
        root=BinaryTree<Comparable>::create_node(data);
    }
    else
    {
        if(root->element>data)                              //if smaller than the root element than insert on left
        {
            insert(data,root->left);
        }
        else
        {
            if(root->element<data)                         //if larger than the root element than insert on right
            {
                insert(data,root->right);
            }
        }
    }
}

template <class Comparable>
void BST<Comparable>::remove(const Comparable data, BinaryNode<Comparable>*& root)          //core remove function
{
    if(root!=NULL)
    {
        if(root->element>data)
        {
            remove(data,root->left);
        }
        else
        {
            if(root->element<data)
            {
                remove(data,root->right);
            }
            else
            {
                if(root->left!=NULL && root->right!=NULL)               //in case of two child
                {
                    root->element=findMin(root->right)->element;
                    remove(root->element,root->right);
                }
                else                                                      //in case of one or no child
                {
                    BinaryNode<Comparable>* oldnode=BinaryTree<Comparable>::tree_root;
                    root=(BinaryTree<Comparable>::tree_root->left!=NULL)? root->left : root->right;
                    delete oldnode;
                }
            }
        }
    }
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::findMin(BinaryNode<Comparable>* root)              //core minimum find function
{
    if(BinaryTree<Comparable>::tree_root!=NULL)
    {
        findMin(root->left);        //minimum element will be at the left most leave of BST
    }
    return root;
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::findMax(BinaryNode<Comparable>* root)              //core maximum find function
{
    if(BinaryTree<Comparable>::tree_root!=NULL)
    {
        findMin(root->right);       //maximum element will be at the right most leave of BST
    }
    return root;
}
