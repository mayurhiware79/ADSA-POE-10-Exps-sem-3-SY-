#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to find the minimum node
struct Node *findMinNode(struct Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Function to find the maximum node
struct Node *findMaxNode(struct Node *root)
{
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// Function to create a new node
struct Node *createNode(int data)
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
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Updated deleteNode function
struct Node *deleteNode(struct Node *root, int data, int *status)
{
    if (root == NULL)
    {
        *status = 0; // Node not found
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data, status);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data, status);
    }
    else
    {
        // Node found
        *status = 1;

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
        struct Node *temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data, status);
    }
    return root;
}

// Function for in-order traversal
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to search for a node
struct Node *searchNode(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    return searchNode(root->right, data);
}

// Function to display the BST
void display(struct Node *root, int space)
{
    if (root == NULL)
        return;

    space += 5;
    display(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);

    display(root->left, space);
}

// Main function with menu-driven options
int main()
{
    struct Node *root = NULL;
    int choice, element;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Find\n4. Find min\n5. Find max\n6. Display\n7. Exit\n8. In-order Traversal\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            root = insertNode(root, element);
            break;
        case 2:
        {
            int status = 0; // Status to track deletion success
            printf("Enter the element to delete: ");
            scanf("%d", &element);
            root = deleteNode(root, element, &status);

            if (status)
            {
                printf("Node %d deleted successfully.\n", element);
            }
            else
            {
                printf("Node %d not found in the tree.\n", element);
            }
            break;
        }
        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &element);
            struct Node *foundNode = searchNode(root, element);
            if (foundNode != NULL)
            {
                printf("Element %d found in the BST.\n", element);
            }
            else
            {
                printf("Element %d not found in the BST.\n");
            }
            break;
        case 4:
            if (root == NULL)
            {
                printf("Tree is empty.\n");
            }
            else
            {
                struct Node *minNode = findMinNode(root);
                printf("Minimum element is: %d\n", minNode->data);
            }
            break;
        case 5:
            if (root == NULL)
            {
                printf("Tree is empty.\n");
            }
            else
            {
                struct Node *maxNode = findMaxNode(root);
                printf("Maximum element is: %d\n", maxNode->data);
            }
            break;
        case 6:
            if (root == NULL)
            {
                printf("Tree is empty.\n");
            }
            else
            {
                printf("BST Display:\n");
                display(root, 0);
            }
            break;
        case 7:
            exit(0);

        case 8:
            if (root == NULL)
            {
                printf("Tree is empty.\n");
            }
            else
            {
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
            }
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}