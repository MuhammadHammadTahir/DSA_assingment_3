#include "BinaryTree.h"
#include <iostream>
#include <queue>

using namespace std;

template <class Comparable>
BinaryTree<Comparable>:: BinaryTree()
{
    tree_root=NULL;        //initilizes the tree root(point towards the tree main root)
}

template <class Comparable>
BinaryTree<Comparable>::BinaryTree(BinaryNode<Comparable>* tree_root)       //parametrized constructor
{
    if(tree_root!=NULL)
    this->tree_root=copyTree(tree_root);
}

template <class Comparable>
BinaryTree<Comparable>:: BinaryTree(const BinaryTree &t)         //copy constructor
{
    if(t.tree_root!=NULL)
    {
        this->tree_root=copyTree(t.tree_root);
    }
}

template <class Comparable>
BinaryNode<Comparable>* BinaryTree<Comparable>:: create_node(Comparable data)  //create new node
{
    BinaryNode<Comparable>* node=new BinaryNode<Comparable>;
    node->element=data;
    node->left=node->right=NULL;
    return node;
}

template <class Comparable>
BinaryNode<Comparable>* BinaryTree<Comparable>:: copyTree(BinaryNode<Comparable>* root)     //copy the tree whose pointer is passed
{
    if(root!=NULL)
    {
        BinaryNode<Comparable>* root_copy=new BinaryNode<Comparable>;
        root_copy->element=root->element;
        root_copy->left=copyTree(root->left);
        root_copy->right=copyTree(root->right);
        return root_copy;
    }
}

template <class Comparable>
void BinaryTree<Comparable>:: insert(const Comparable x)
{
    if(tree_root==NULL)
    {
        tree_root=create_node(x);
    }
    else
    {
        queue<BinaryNode<Comparable>*> q;
        q.push(tree_root);
        while(!q.empty())
        {
            BinaryNode<Comparable>* temp = q.front();
            q.pop();
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            else
            {
                temp->left=create_node(x);
                return;
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            else
            {
                temp->right=create_node(x);
                return;
            }
        }
    }
}

template <class Comparable>
BinaryTree<Comparable>:: ~BinaryTree()
{
    deleteTree(tree_root);                       //free up all the space taken by the tree
}

template <class Comparable>
Comparable BinaryTree<Comparable>:: root()  //return the data in tree_root of tree
{
    return tree_root->element;
}

template <class Comparable>
BinaryTree<Comparable> BinaryTree<Comparable>:: Left()  // write thee copy constructor then use it in these functions
{
    BinaryTree<Comparable> tree_left(tree_root->left);
    return tree_left;
}

template <class Comparable>
BinaryTree<Comparable> BinaryTree<Comparable>:: right() // write thee copy constructor then use it in these functions
{
    BinaryTree<Comparable> tree_right(tree_root->right);
    return tree_right;
}

template <class Comparable>
void BinaryTree<Comparable>:: traverse_inOrder()    //print in inorder
{
    traverse_inOrder(tree_root);
}

template <class Comparable>
void BinaryTree<Comparable>:: traverse_preOrder()   //print in preorder
{
    traverse_preOrder(tree_root);
}

template <class Comparable>
void BinaryTree<Comparable>:: traverse_postOrder()  //print in postorder
{
    traverse_postOrder(tree_root);
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_inOrder(BinaryNode<Comparable>* tree_root)    //core inorder function
{
    if(tree_root!=NULL)                 //if we use !empty() then it will check the main root that will NULL so never stop
    {
        traverse_inOrder(tree_root->left);
        cout<<" "<<tree_root->element;
        traverse_inOrder(tree_root->right);
    }
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_preOrder(BinaryNode<Comparable>* tree_root)    //core preorder function
{
    if(tree_root!=NULL)             //if we use !empty() then it will check the main root that will NULL so never stop
    {
        cout<<tree_root->element<<" ";
        traverse_preOrder(tree_root->left);
        traverse_preOrder(tree_root->right);
    }
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_postOrder(BinaryNode<Comparable>* tree_root)    //core postorder function
{
    if(tree_root!=NULL)             //if we use !empty() then it will check the main root that will NULL so never stop
    {
        traverse_postOrder(tree_root->left);
        traverse_postOrder(tree_root->right);
        cout<<tree_root->element<<" ";
    }
}

template <class Comparable>
void BinaryTree<Comparable>::make_empty()   //work same as the destorctor but object is not destored
{
    deleteTree(tree_root);
    cout<<endl<<"Now tree Become empty"<<endl;
}

template <class Comparable>
bool BinaryTree<Comparable>:: empty() const        //check the tree
{
    if(tree_root==NULL)
        return true;
    else
        return false;
}

template <class Comparable>
void BinaryTree<Comparable>::deleteTree(BinaryNode<Comparable>* tree_root)          //core delete tree function
{
    if(tree_root!=NULL)
    {
        deleteTree(tree_root->left);
        deleteTree(tree_root->right);
        cout<<endl<<"Deleting node: "<<tree_root->element;
        delete tree_root;
    }
}
