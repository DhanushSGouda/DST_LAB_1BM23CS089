#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
int data; 
struct Node* next; 
}; 
void insert(struct Node** head, int data) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
struct Node* temp = *head; 
newNode->data = data; 
newNode->next = NULL; 
if (*head == NULL) { 
*head = newNode; 
return; 
} 
while (temp->next != NULL) { 
temp = temp->next; 
} 
temp->next = newNode; 
} 
void display(struct Node* head) { 
struct Node* temp = head; 

while (temp != NULL) { 
printf("%d -> ", temp->data); 
temp = temp->next; 
} 
printf("NULL\n"); 
} 
void sort(struct Node* head) { 
struct Node *current, *index; 
int temp; 
if (head == NULL) { 
return; 
} 
for (current = head; current != NULL; current = current->next) { for (index = current->next; index != NULL; index = index->next) { if (current->data > index->data) { 
temp = current->data; 
current->data = index->data; 
index->data = temp; 
} 
} 
} 
} 
void reverse(struct Node** head) { 
struct Node *prev = NULL, *current = *head, *next = NULL; while (current != NULL) { 
next = current->next; 
current->next = prev; 

prev = current; 
current = next; 
} 
*head = prev; 
} 
void concatenate(struct Node** head1, struct Node* head2) { if (*head1 == NULL) { 
*head1 = head2; 
return; 
} 
struct Node* temp = *head1; 
while (temp->next != NULL) { 
temp = temp->next; 
} 
temp->next = head2; 
} 
int main() { 
struct Node* list1 = NULL; 
struct Node* list2 = NULL; 
insert(&list1, 3); 
insert(&list1, 1); 
insert(&list1, 4); 
insert(&list1, 2); 
printf("Original List:\n"); 
display(list1); 

sort(list1); 
printf("Sorted List:\n"); 
display(list1); 
reverse(&list1); 
printf("Reversed List:\n"); 
display(list1); 
insert(&list2, 5); 
insert(&list2, 6); 
printf("Second List:\n"); 
display(list2); 
concatenate(&list1, list2); 
printf("Concatenated List:\n"); 
display(list1); 
return 0; 
} 


