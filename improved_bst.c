#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    // If data is already in the tree, do nothing (no duplicates allowed).
    return root;
}

// Helper function to find the in-order successor
struct Node *getSuccessor(struct Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

// Function to delete a node from the BST
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return root; // Node not found
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Node with one or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node *succ = getSuccessor(root);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

// Function to search for a node in the BST
struct Node *search(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    if (data < root->data)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function for in-order traversal of the BST
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

// Main function
int main()
{
    struct Node *root = NULL;

    // Insert nodes into the BST
    root = insert(root, 100);
    root = insert(root, 35);
    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 20);

    printf("In-order Traversal Before Deletion:\n");
    inorder(root);
    printf("\n");

    // Delete a node
    root = deleteNode(root, 40);
    printf("In-order Traversal After Deleting 40:\n");
    inorder(root);
    printf("\n");

    // Search for a node
    int searchKey = 50;
    struct Node *searchResult = search(root, searchKey);
    if (searchResult != NULL)
    {
        printf("Node %d FOUND in the BST\n", searchKey);
    }
    else
    {
        printf("Node %d NOT FOUND in the BST\n", searchKey);
    }

    return 0;
}
