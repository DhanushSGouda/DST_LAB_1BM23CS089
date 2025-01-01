#include <stdio.h> 
#include <ctype.h> 
#define MAX 100 
void push(char *stack, int *top, char value) { 
if (*top == MAX - 1) { 
printf("Stack Overflow\n"); 
return; 
} 
stack[++(*top)] = value; 
} 
char pop(char *stack, int *top) { 
if (*top == -1) { 
printf("Stack Underflow\n"); 
return '\0'; 
} 
return stack[(*top)--]; 
} 
int precedence(char op) { 
if (op == '+' || op == '-') return 1; 
if (op == '*' || op == '/') return 2; 
if (op == '^') return 3; 

return 0; 
} 
int isRightAssociative(char op) { 
if (op == '^') return 1; 
return 0; 
} 
void infixToPostfix(char *infix, char *postfix) { 
char stack[MAX]; 
int top = -1, k = 0; 
for (int i = 0; infix[i] != '\0'; i++) { 
if (isalnum(infix[i])) { 
postfix[k++] = infix[i]; 
} else if (infix[i] == '(') { 
push(stack, &top, infix[i]); 
} else if (infix[i] == ')') { 
while (top != -1 && stack[top] != '(') { 
postfix[k++] = pop(stack, &top); 
} 
pop(stack, &top); 
} else { 
while (top != -1 && 
((isRightAssociative(infix[i]) && precedence(stack[top]) > precedence(infix[i])) || 
(!isRightAssociative(infix[i]) && precedence(stack[top]) >= 
precedence(infix[i])))) { 
postfix[k++] = pop(stack, &top); 
} 

push(stack, &top, infix[i]); 
} 
} 
while (top != -1) { 
postfix[k++] = pop(stack, &top); 
} 
postfix[k] = '\0'; 
} 
int main() { 
char infix[MAX], postfix[MAX]; 
printf("Enter a valid infix expression: "); 
scanf("%s", infix); 
infixToPostfix(infix, postfix); 
printf("Postfix expression: %s\n", postfix); 
return 0; 
} 

