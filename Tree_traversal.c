#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void Postorder(struct node *node)
{
    if (node == NULL)
        return;
    Postorder(node->left);
    Postorder(node->right);
    printf("%d ", node->data);
}

void Inorder(struct node *node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}

void Preorder(struct node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    Preorder(node->left);
    Preorder(node->right);
}

int main()
{
    struct node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(0);
    root->left->right = newNode(1);
    root->left->right->left = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);
    root->right->right->right = newNode(9);

    printf("\nPreorder:\t");
    Preorder(root);

    printf("\nInorder:\t");
    Inorder(root);

    printf("\nPostorder:\t");
    Postorder(root);

    return 0;
}
