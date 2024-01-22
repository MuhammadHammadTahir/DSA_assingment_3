#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class Comparable>
struct BinaryNode
{
    Comparable element;     //data
    BinaryNode<Comparable>* left;  //left child
    BinaryNode<Comparable>* right;  //right child
};

template <class Comparable>
class BinaryTree
{
    public:
        //constructors
        BinaryTree();      //default
        BinaryTree(BinaryNode<Comparable>* root); //paramitrized constructor
        BinaryTree(const BinaryTree& t);            //copy constructor
        //destructor
        virtual ~BinaryTree();
        //insert Node in level order (left empty location of tree)
        virtual void insert(const Comparable x);
        //Access functions
        Comparable root();
        BinaryTree<Comparable> Left();
        BinaryTree<Comparable> right();
        //Tree Traversing
        void traverse_inOrder();
        void traverse_preOrder();
        void traverse_postOrder();
        //Make tree empty
        void make_empty();
        //check if tree empty
        bool empty() const;

    protected:
        BinaryNode<Comparable>* create_node(Comparable data);
        BinaryNode<Comparable>* copyTree(BinaryNode<Comparable>* root);
        BinaryNode<Comparable>* tree_root;

    private:
        //Tree Traversing private (with the root pointer)
        void traverse_inOrder(BinaryNode<Comparable>* root);
        void traverse_preOrder(BinaryNode<Comparable>* root);
        void traverse_postOrder(BinaryNode<Comparable>* root);
        void deleteTree(BinaryNode<Comparable>* root);
};

#endif // BINARYTREE_H
