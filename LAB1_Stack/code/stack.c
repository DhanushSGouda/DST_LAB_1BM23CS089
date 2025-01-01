 #include <stdio.h> 
#define MAX 100 
void push(int *stack, int *top, int value) { 
if (*top == MAX - 1) { 
printf("Stack Overflow\n"); 
return; 
} 
stack[++(*top)] = value; 
} 
void pop(int *stack, int *top) { 
if (*top == -1) { 
printf("Stack Underflow\n"); 
return; 
} 
printf("Popped element: %d\n", stack[(*top)--]); 
} 
void display(int *stack, int *top) { 
if (*top == -1) { 
printf("Stack is empty\n"); 
return; 
} 
for (int i = *top; i >= 0; i--) { 
printf("%d\n", stack[i]); 
} 
} 
int main() { 
int stack[MAX], top = -1, choice, value; 
do { 
printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: "); scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter value to push: "); 
scanf("%d", &value); 
push(stack, &top, value); 
break; 
case 2: 
pop(stack, &top); 
break; 
case 3: 
display(stack, &top); 
break; 
case 4: 
break; 
default: 
printf("Invalid choice\n"); 
} 
} while (choice != 4); 
return 0; 
}

