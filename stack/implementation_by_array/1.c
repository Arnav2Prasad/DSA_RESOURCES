
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int size;
    int top;
    char *array;
} stack;

void init(stack *s, int size) {
    s->size = size;
    s->top = -1;
    s->array = (char *)malloc(size * sizeof(char));
}

int isEmpty(stack s) {
    return s.top == -1;
}

void push(stack *s, char item) {
    s->array[++s->top] = item;
}

char pop(stack *s) {
    if (!isEmpty(*s)) {
        return s->array[s->top--];
    }
    return '$'; // '$' indicates an empty stack
}

char peek(stack s) {
    if (!isEmpty(s)) {
        return s.array[s.top];
    }
    return '$'; // '$' indicates an empty stack
}

int precedence(char operator) {
    switch (operator) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char *infixToPostfix(char *infix) {
    int i, j;
    int len = strlen(infix);
    char *postfix = (char *)malloc((2 * len + 1) * sizeof(char)); // Twice the length for possible spaces
    stack s;
    init(&s, len);

    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        if (isalnum(infix[i])) {
            while (isalnum(infix[i])) {
                postfix[j++] = infix[i++];
            }
            i--; // Adjust index back by one because the outer loop will increment it
            postfix[j++] = ' ';
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(s) && peek(s) != '(')
                postfix[j++] = pop(&s);
            pop(&s); // Pop '(' from the stack
        } else if (isOperator(infix[i])) {
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(infix[i]) && peek(s) != '(')
                postfix[j++] = pop(&s);s
            push(&s, infix[i]);
        }
    }

    while (!isEmpty(s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';

    return postfix;
}

int main() {
    char infix[100]; // Adjust the size as needed
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    char *postfix = infixToPostfix(infix);
    printf("Infix Expression: %s", infix);
    printf("Postfix Expression: %s\n", postfix);

    free(postfix);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct ADT{
    int size;
    int top;
    int *s;
}stack;

void init(stack *stack1, int size1){
    stack1->size = size1;
    stack1->top = -1;
    stack1->s = (int*)malloc(size1 * sizeof(int));
}

int isFull(stack stack1){
    if(stack1.top == stack1.size-1)
        return 1;
    else return 0;
}

int isEmpty(stack stack1){
    if(stack1.top == -1)
        return 1;
    else return 0;
}

void push(stack *stack1, int value){
    if(!isFull(*stack1)){
        stack1->s[++stack1->top] = value;
    }
    else{
        printf("Stack is full");
    }
}

int pop(stack *stack1){
    if(!isEmpty(*stack1)){
        return stack1->s[stack1->top--];
    }
    else
     printf("Stack is Empty");
}

int peek(stack *stack1){
    if(!isEmpty(*stack1)){
        return stack1->s[stack1->top];
    }
    else
     printf("Stack is Empty");
}

void display(stack stack1){
    if(!isEmpty(stack1)){
        for(int i=stack1.top; i >= 0 ; i--){
            printf("%d\t", stack1.s[i]);
        }
        printf("\n");
    }
    else{
        printf("Empty stack");
    }
}

int precedence(char precedence){
    switch(precedence){
    case '+':
    case '-':
        return 10;
        break;
    case '*':
    case '/':
        return 20;
        break;
    case '^':
        return 30;
        break;
    case ')':
        return 5;
        break;
    }
}
int main(){
    stack s;
    init(&s,5);
    push(&s ,2);
    push(&s ,3);
    push(&s ,4);
    push(&s ,5);
    display(s);
    printf("The popped character is %d\n", pop(&s));
    display(s);
    char infix[100];
    gets(infix);
    stack s1;
    init(&s,100);
    char postfix[100];
    int j =0;
    char c;
    int i =0;
    while(infix[i] != '\0'){
        c = infix[i];

    }
}
