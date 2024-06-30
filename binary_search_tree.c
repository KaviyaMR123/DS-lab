#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data);
struct Node* insertNode(struct Node* root, int data);
void inorderTraversal(struct Node* root);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
struct Node* deleteNode(struct Node* root, int data);
struct Node* findMin(struct Node* root);
int main() 
{
    struct Node* root = NULL;
    int choice, value;
    while (1) 
    {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insertNode(struct Node* root, int data) 
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
void inorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(struct Node* root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(struct Node* root) 
{
    if (root != NULL) 
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
struct Node* findMin(struct Node* root)
{
    while (root->left != NULL) 
    {
        root = root->left;
    }
    return root;
}
struct Node* deleteNode(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return root;
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
        if (root->left == NULL) 
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
