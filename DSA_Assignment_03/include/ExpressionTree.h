#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <BinaryTree.h>
#include <string>
using namespace std;

//Expression tree node pointer
typedef BinaryNode<char>* ExpTreeNodePtr;

//Class ExpressionTree works with characters only
class ExpressionTree : public BinaryTree<char>
{
    public:
        //Constructor
        ExpressionTree();
        //Deep copy constructor from the given Binary Node (char type)
        ExpressionTree(ExpTreeNodePtr data);
        //Virtual destructor
        virtual ~ExpressionTree();
        //Create Expression tree from the given postfix expression
        void create_expression_tree(string expression);
        //Get the cloned(Deep copy) left Sub Tree
        ExpressionTree left();
        //Get the cloned(Deep copy) right sub-tree
        ExpressionTree right();

    private:
        //private Utility Functions
        bool is_operator(char ch);
};

#endif // EXPRESSIONTREE_H
