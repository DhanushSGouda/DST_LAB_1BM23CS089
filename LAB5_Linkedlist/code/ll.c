#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node { 
int value; 
struct Node* next; 
} Node; 
typedef struct LinkedList { 
Node* head; 
Node* tail; 
int length; 
} LinkedList; 
Node* create_node(int value) { 
Node* new_node = (Node*)malloc(sizeof(Node)); 
new_node->value = value; 
new_node->next = NULL; 
return new_node; 
} 
LinkedList* create_linked_list() { 
LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList)); list->head = NULL; 
list->tail = NULL; 
list->length = 0; 
return list; 
} 
void print_list(LinkedList* list) { 
Node* temp = list->head; 
while (temp != NULL) { 
printf("%d -> ", temp->value); 
temp = temp->next; 
} 
printf("NULL\n"); 
} 
void append(LinkedList* list, int value) { Node* new_node = create_node(value); if (list->head == NULL && list->tail == NULL) { list->head = new_node; 
list->tail = new_node; 
} else { 
list->tail->next = new_node; 
list->tail = new_node; 
} 
list->length++; 
} 
Node* pop(LinkedList* list) { 
if (list->length == 0) return NULL; 
Node* temp = list->head; 
Node* pre = list->head; 

while (temp->next != NULL) { 
pre = temp; 
temp = temp->next; 
} 
list->tail = pre; 
pre->next = NULL; 
list->length--; 
if (list->length == 0) { 
list->head = NULL; 
list->tail = NULL; 
} 
return temp; 
} 
void prepend(LinkedList* list, int value) { Node* new_node = create_node(value); if (list->length == 0) { 
list->head = new_node; 
list->tail = new_node; 
} else { 
new_node->next = list->head; 
list->head = new_node; 
} 
list->length++; 
} 
Node* pop_first(LinkedList* list) { if (list->length == 0) return NULL; 

Node* temp = list->head; 
list->head = temp->next; 
temp->next = NULL; 
list->length--; 
if (list->length == 0) list->tail = NULL; 
return temp; 
} 
Node* get(LinkedList* list, int index) { 
if (index < 0 || index >= list->length) return NULL; 
Node* temp = list->head; 
for (int i = 0; i < index; i++) { 
temp = temp->next; 
} 
return temp; 
} 
int set_value(LinkedList* list, int index, int value) { Node* temp = get(list, index); 
if (temp) { 
temp->value = value; 
return 1; 
} 
return 0; 
} 

int insert(LinkedList* list, int index, int value) { if (index < 0 || index > list->length) return 0; if (index == 0) { 
prepend(list, value); 
return 1; 
} 
if (index == list->length) { 
append(list, value); 
return 1; 
} 
Node* new_node = create_node(value); 
Node* prev = get(list, index - 1); 
new_node->next = prev->next; 
prev->next = new_node; 
list->length++; 
return 1; 
} 
Node* remove_node(LinkedList* list, int index) { if (index < 0 || index >= list->length) return NULL; if (index == 0) return pop_first(list); 
if (index == list->length - 1) return pop(list); 
Node* prev = get(list, index - 1); 
Node* temp = prev->next; 
prev->next = temp->next; 
temp->next = NULL; 
list->length--; 

return temp; 
} 
int main() { 
LinkedList* list1 = create_linked_list(); int choice, value, index; 
do { 
printf("1. Append\n"); 
printf("2. Pop\n"); 
printf("3. Print List\n"); 
printf("4. Prepend\n"); 
printf("5. Pop_first\n"); 
printf("6. Insert\n"); 
printf("7. Delete\n"); 
printf("8. Exit\n"); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter value to append to List: "); scanf("%d", &value); 
append(list1, value); 
break; 
case 2: 
pop(list1); 
break; 

case 3: 
printf("List: "); 
print_list(list1); 
break; 
case 4: 
printf("Enter value to prepend to List: "); scanf("%d", &value); 
prepend(list1, value); 
break; 
case 5: 
pop_first(list1); 
break; 
case 6: 
printf("Enter index and value to insert: "); scanf("%d %d", &index, &value); 
insert(list1, index, value); 
break; 
case 7: 
printf("Enter index to delete: "); 
scanf("%d", &index); 
remove_node(list1, index); 
break; 
case 8: 
printf("Exiting...\n"); 
break; 
default: 
printf("Invalid choice, please try again.\n"); } 
} while (choice != 8); 


while (list1->length > 0) { 
Node* temp = pop(list1); 
free(temp); 
} 
free(list1); 
return 0; 
} 

