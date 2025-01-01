#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
int data; 
struct Node* left; 
struct Node* right; 
}; 
struct Node* createNode(int data) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->data = data; 
newNode->left = newNode->right = NULL; 
return newNode; 
} 
struct Node* insert(struct Node* root, int data) { 
if (root == NULL) { 
return createNode(data); 
} 
if (data < root->data) { 
root->left = insert(root->left, data); 
} else { 
root->right = insert(root->right, data); 
} 
return root; 
} 

void inorder(struct Node* root) { if (root != NULL) { 
inorder(root->left); 
printf("%d ", root->data); 
inorder(root->right); 
} 
} 
void preorder(struct Node* root) { if (root != NULL) { 
printf("%d ", root->data); 
preorder(root->left); 
preorder(root->right); 
} 
} 
void postorder(struct Node* root) { if (root != NULL) { 
postorder(root->left); 
postorder(root->right); 
printf("%d ", root->data); 
} 
} 
void display(struct Node* root) { if (root == NULL) { 
printf("Tree is empty.\n"); 
return; 
} 
printf("In-order traversal: "); inorder(root); 
printf("\n"); 
printf("Pre-order traversal: "); 
preorder(root); 
printf("\n"); 
printf("Post-order traversal: "); 
postorder(root); 
printf("\n"); 
} 
int main() { 
struct Node* root = NULL; 
int choice, value; 
while (1) { 
printf("\nChoose an operation:\n"); 
printf("1. Insert node into BST\n"); 
printf("2. Display the tree (In-order, Pre-order, Post-order)\n"); printf("3. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter value to insert: "); 
scanf("%d", &value); 
root = insert(root, value); 
break; 
case 2: 
display(root); 
break; 
case 3: 
printf("Exiting...\n"); 
exit(0); 
default: 
printf("Invalid choice, please try again.\n"); 
} 
} 
return 0; 
} 

