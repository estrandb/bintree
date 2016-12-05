#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <cstddef>

template <typename T> struct node
{
    T key_value;
    node<T>* parent;
    node<T>* left;
    node<T>* right;
};

template <typename T> class BinaryTree
{
    public:
        BinaryTree();
        ~BinaryTree();
        void insert_node(T key);
        node<T>* search_tree(T key);
        void destroy_tree();

        node<T>* root;
    protected:

    private:
        void destroy_tree(node<T>* leaf);
        void insert_node(T key, node<T>* leaf);
        node<T>* search_tree(T key, node<T>* leaf);


};

template<typename T> BinaryTree<T>::BinaryTree()
{
    root=NULL;
}

template<typename T> BinaryTree<T>::~BinaryTree()
{
    destroy_tree();
}

template<typename T> void BinaryTree<T>::destroy_tree(node<T>* leaf)
{
    if (leaf!=NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

template <typename T> void BinaryTree<T>::insert_node(T key, node<T>* leaf)
{
    //to the left, insert key is smaller than current node
    if (key < leaf->key_value)
    {
        if (leaf->left != NULL)
        {
            insert_node(key, leaf->left);
        }
        else
        {
            leaf->left = new node<T>;
            leaf->left->key_value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }

    //to the right, insert key is larger than current node
    if (key >= leaf->key_value)
    {
        if (leaf->right != NULL)
        {
            insert_node(key, leaf->right);
        }
        else
        {
            leaf->right = new node<T>;
            leaf->right->key_value = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}

template<typename T> node<T>* BinaryTree<T>::search_tree(T key, node<T>* leaf)
{
    if (leaf != NULL)
    {
        if (key == leaf->key_value)
        {
            return leaf;
        }
        if (key < leaf->key_value)
        {
            return search_tree(key, leaf->left);
        }
        else
        {
            return search_tree(key, leaf->right);
        }
    }
    else
        return NULL;
}

template<typename T> void BinaryTree<T>::insert_node(T key)
{
    if (root != NULL)
    {
        insert_node(key, root);
    }
    else
    {
        root = new node<T>;
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

template<typename T> node<T>* BinaryTree<T>::search_tree(T key)
{
    return search_tree(key, root);
}

template<typename T> void BinaryTree<T>::destroy_tree()
{
    destroy_tree(root);
}


#endif // BINARYTREE_H
