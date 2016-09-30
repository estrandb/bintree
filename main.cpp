#include <iostream>
#include <memory>
#include "BinaryTree.h"

using namespace std;

void printtree(node<double>* root)
{
    if (root != NULL)
    {
        cout << root->key_value << ", " << '\n';
        printtree(root->left);
        printtree(root->right);
    }
    return;
}


int main()
{
    unique_ptr<BinaryTree<double>> btree(new BinaryTree<double>());

    btree->insert_node(14.45);
    btree->insert_node(10.453);
    btree->insert_node(10.4532);
    btree->insert_node(50.6);
    btree->insert_node(22.4);
    btree->insert_node(9.0);
    btree->insert_node(16.55);



    printtree(btree->root);
}

