#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}


struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = root->right;   //inorder successor ,smallest value of right subtree
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int value;
    
    printf("Enter values to insert into the BST (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        root = insert(root, value);
    }
    
    // Print inorder traversal of BST
    printf("Inorder traversal of BST: ");
    inorderTraversal(root);
    printf("\n");
    
    // Print preorder traversal of BST
    printf("Preorder traversal of BST: ");
    preorderTraversal(root);
    printf("\n");
    
    // Print postorder traversal of BST
    printf("Postorder traversal of BST: ");
    postorderTraversal(root);
    printf("\n");
    
    printf("Enter a value to delete from the BST: ");
    scanf("%d", &value);
    root = deleteNode(root, value);
     // Print inorder traversal of BST after deletion
        printf("Inorder traversal of BST after deletion: ");
        inorderTraversal(root);
        printf("\n");
        
        // Print preorder traversal of BST after deletion
        printf("Preorder traversal of BST after deletion: ");
        preorderTraversal(root);
        printf("\n");
        
        // Print postorder traversal of BST after deletion
        printf("Postorder traversal of BST after deletion: ");
        postorderTraversal(root);
        printf("\n");
        
        return 0;
    }
    