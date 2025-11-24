#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 30
char stack[MAX];
int top = -1;
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}
void pop() {
    if (top >= 0) {
        top--;
    }
}
char peek() {
    return (top >= 0) ? stack[top] : '\0';
}
int isEmpty() {
    return top == -1;
}
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}
char* infixToPostfix(char* s) {
    char* result = (char*)malloc(MAX * sizeof(char));
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i]; 
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                result[j++] = peek();
                pop();
            }
            pop();
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                result[j++] = peek();
                pop();
            }
            push(c);
        }
    }
    while (!isEmpty()) {
        result[j++] = peek();
        pop();
    }
    result[j] = '\0';
    return result;
}
int main() {
    char expression[MAX];
    printf("Enter infix expression: ");
    scanf("%s", expression);
    char* postfix = infixToPostfix(expression);
    printf("Postfix expression: %s\n", postfix);
    free(postfix);
}
//Enter infix expression: (a+b)*(c-d)/e
//Postfix expression: ab+cd-*e/