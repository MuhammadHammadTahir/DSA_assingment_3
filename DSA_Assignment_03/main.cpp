#include <iostream>
#include <string>
#include <BinaryTree.h>
#include <ExpressionTree.h>
#include <BST.h>

using namespace std;

template <class Comparable>
void traverse_tree(BinaryTree<Comparable>* tree);
void test_binary_tree();
void test_expression_tree();
void test_binary_search_tree();

int main()
{
    test_binary_tree();
    test_expression_tree();
    test_binary_search_tree();
    return 0;
}

void test_binary_tree()
{
    cout<<"Testing Binary Tree"<<endl;
    BinaryTree<char> myTree;
    string values = "1234567890abcde";
    for(int i=0;i<values.length();i++)
        myTree.insert(values[i]);
    traverse_tree(&myTree);
    BinaryTree<char> tr2 = myTree.Left();
    BinaryTree<char> tr3 = myTree.right();
    cout<<endl;
    cout<<"Left sub Tree"<<endl;
    traverse_tree(&tr2);
    cout<<endl;
    traverse_tree(&tr3);
    cout<<endl;
}

void test_expression_tree()
{
     cout<<"\nTesting Expression Tree"<<endl;
     string expression = "762*+6+5-";
     ExpressionTree expTree = ExpressionTree();
     expTree.create_expression_tree(expression);
     traverse_tree(&expTree);
     cout<<endl;
}

void test_binary_search_tree()
{
     cout<<"\n\nTesting Binary Search Tree"<<endl;
     BST<double> myBST;
     double numbers[] = {7, 9, 13, 6, 4, 2, 5, 8, 1, 10, 3, 11, 12};
     for(int i=0; i<13; i++)
     myBST.insert(numbers[i]);
     traverse_tree(&myBST);
}

template <class Comparable>
void traverse_tree(BinaryTree<Comparable> * tree)
{
    cout<<endl;
    cout<<"In Order : ";
    tree->traverse_inOrder();
    cout<<endl;
    cout<<"Pre Order : ";
    tree->traverse_preOrder();
    cout<<endl;
    cout<<"Post Order: ";
    tree->traverse_postOrder();
    cout<<endl;
}
