#include <stdio.h> 
#define MAX 100 
void insert(int *queue, int *front, int *rear, int value) { 
if ((*rear + 1) % MAX == *front) { 
printf("Queue Overflow\n"); 
return; 
} 
if (*front == -1) { 
*front = 0; 
} 
*rear = (*rear + 1) % MAX; 
queue[*rear] = value; 
} 
int delete(int *queue, int *front, int *rear) { 
if (*front == -1) { 
printf("Queue Empty\n"); 
return -1; 
} 
int value = queue[*front]; 
if (*front == *rear) { 
*front = *rear = -1; 
} else { 
*front = (*front + 1) % MAX; 

} 
return value; 
} 
void display(int *queue, int front, int rear) { if (front == -1) { 
printf("Queue Empty\n"); 
return; 
} 
printf("Queue elements: "); 
int i = front; 
while (1) { 
printf("%d ", queue[i]); 
if (i == rear) break; 
i = (i + 1) % MAX; 
} 
printf("\n"); 
} 
int main() { 
int queue[MAX], front = -1, rear = -1; int choice, value; 
do { 
printf("\nMenu:\n"); 
printf("1. Insert\n"); 
printf("2. Delete\n"); 
printf("3. Display\n"); 
printf("4. Exit\n"); 

printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter value to insert: "); 
scanf("%d", &value); 
insert(queue, &front, &rear, value); 
break; 
case 2: 
value = delete(queue, &front, &rear); if (value != -1) { 
printf("Deleted value: %d\n", value); } 
break; 
case 3: 
display(queue, front, rear); 
break; 
case 4: 
printf("Exiting...\n"); 
break; 
default: 
printf("Invalid choice!\n"); 
} 
} while (choice != 4); 
return 0; 
}

