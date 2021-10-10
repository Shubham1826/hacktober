#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BSTnode
{
    int data;
    struct BSTnode *left;
    struct BSTnode *right;
};
struct BSTnode *root = NULL;

struct BSTnode *createNode(int data)
{

    struct BSTnode *newNode = (struct BSTnode *)malloc(sizeof(struct BSTnode));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insert(int data)
{
    struct BSTnode *newNode = createNode(data);

    if (root == NULL)
    {
        root = newNode;
        return;
    }
    else
    {
        struct BSTnode *current = root, *parent = NULL;

        while (true)
        {
            parent = current;
            if (data < current->data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = newNode;
                    return;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}
struct BSTnode *minNode(struct BSTnode *root)
{
    if (root->left != NULL)
        return minNode(root->left);
    else
        return root;
}

struct BSTnode *deleteNode(struct BSTnode *node, int value)
{
    if (node == NULL)
    {
        return NULL;
    }
    else
    {
        if (value < node->data)
            node->left = deleteNode(node->left, value);

        else if (value > node->data)
            node->right = deleteNode(node->right, value);

        else
        {
            if (node->left == NULL && node->right == NULL)
                node = NULL;
            else if (node->left == NULL)
            {
                node = node->right;
            }
            else if (node->right == NULL)
            {
                node = node->left;
            }
            else
            {
                struct BSTnode *temp = minNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }
}
void inorderTraversal(struct BSTnode *node)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    else
    {

        if (node->left != NULL)
            inorderTraversal(node->left);
        printf("%d ", node->data);
        if (node->right != NULL)
            inorderTraversal(node->right);
    }
}
int main()
{
    insert(24);
    insert(56);
    insert(20);
    insert(22);
    insert(10);
    insert(50);

    inorderTraversal(root);
    struct BSTnode *deletedNode = NULL;
    deletedNode = deleteNode(root, 10);
    printf("\nBinary search tree after deleting node 10: \n");
    inorderTraversal(root);
    deletedNode = deleteNode(root, 56);
    printf("\nBinary search tree after deleting node 56: \n");
    inorderTraversal(root);
    deletedNode = deleteNode(root, 24);
    printf("\nBinary search tree after deleting node 24: \n");
    inorderTraversal(root);
    return 0;
}
