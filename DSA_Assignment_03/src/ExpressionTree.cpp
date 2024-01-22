#include "ExpressionTree.h"
#include <stack>
#include <string>

using namespace std;

ExpressionTree::ExpressionTree()
{
    //constructor of base class will work
}


ExpressionTree::~ExpressionTree()
{
    //destructor of base will work
}

ExpressionTree::ExpressionTree(ExpTreeNodePtr data): BinaryTree(data)
{
    //copy constructor of the base with arguments will handle this
}

void ExpressionTree:: create_expression_tree(string expression)
{
    ExpTreeNodePtr new_node,p1,p2;
    int flag;
    stack<ExpTreeNodePtr> st;
    for(int i=0;i<expression.length();i++)
    {
        if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/')
        {
            flag=-1;
        }
        else
        {
            if(expression[i]>='A'||expression[i]<='Z'||expression[i]>='a'||expression[i]<='z'||expression[i]>='0'||expression[i]<='9')
            flag=1;
        }
        if(flag==1)
        {
            new_node=create_node(expression[i]);
            st.push(new_node);
        }
        else
        {
            p1=st.top();
            st.pop();
            p2=st.top();
            st.pop();
            new_node=create_node(expression[i]);
            new_node->left=p2;
            new_node->right=p1;
            st.push(new_node);
        }
    }
    tree_root =st.top();
}

ExpressionTree ExpressionTree:: left()
{
    ExpressionTree sub_exp_tree_left(tree_root->left);
    return sub_exp_tree_left;
}

ExpressionTree ExpressionTree:: right()
{
    ExpressionTree sub_exp_tree_right(tree_root->right);
    return sub_exp_tree_right;
}
