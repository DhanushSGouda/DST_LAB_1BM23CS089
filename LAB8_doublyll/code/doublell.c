#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
int data; 
struct Node* prev; 
struct Node* next; 
}; 
void createList(struct Node** head) { 
*head = NULL; 
} 
void insertLeft(struct Node** head, int data, int value) { struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->data = data; 
newNode->prev = NULL; 
newNode->next = NULL; 
if (*head == NULL) { 
*head = newNode; 
return; 

} 
struct Node* temp = *head; 
while (temp != NULL && temp->data != value) { temp = temp->next; 
} 
if (temp != NULL) { 
newNode->next = temp; 
newNode->prev = temp->prev; 
if (temp->prev != NULL) { 
temp->prev->next = newNode; 
} 
temp->prev = newNode; 
if (*head == temp) { 
*head = newNode; 
} 
} else { 
printf("Node with value %d not found.\n", value); } 
} 
void deleteNode(struct Node** head, int value) { struct Node* temp = *head; 
if (temp != NULL && temp->data == value) { *head = temp->next; 
if (*head != NULL) { 

(*head)->prev = NULL; 
} 
free(temp); 
return; 
} 
while (temp != NULL && temp->data != value) { temp = temp->next; 
} 
if (temp == NULL) { 
printf("Node with value %d not found.\n", value); return; 
} 
if (temp->next != NULL) { 
temp->next->prev = temp->prev; 
} 
if (temp->prev != NULL) { 
temp->prev->next = temp->next; 
} 
free(temp); 
} 
void displayList(struct Node* head) { 
struct Node* temp = head; 
if (temp == NULL) { 
printf("The list is empty.\n"); 

return; 
} 
printf("Doubly Linked List: "); 
while (temp != NULL) { 
printf("%d <-> ", temp->data); 
temp = temp->next; 
} 
printf("NULL\n"); 
} 
int main() { 
struct Node* head; 
int choice, data, value; 
createList(&head); 
while (1) { 
printf("\nChoose an operation:\n"); 
printf("1. Insert node to the left of a node\n"); printf("2. Delete node based on a specific value\n"); printf("3. Display the list\n"); 
printf("4. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter the value to insert: "); 

scanf("%d", &data); 
printf("Enter the value to insert to the left of: "); scanf("%d", &value); 
insertLeft(&head, data, value); 
break; 
case 2: 
printf("Enter the value to delete: "); 
scanf("%d", &value); 
deleteNode(&head, value); 
break; 
case 3: 
displayList(head); 
break; 
case 4: 
printf("Exiting...\n"); 
exit(0); 
default: 
printf("Invalid choice, please try again.\n"); } 
} 
return 0; 
} 

