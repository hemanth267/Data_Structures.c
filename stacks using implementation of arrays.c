#include<stdio.h>
#define N 100  // Define stack size
int stack[N];  // Stack array
int top = -1;  // Initialize top
void push(int x) {
    // Check if stack is full
    if (top == N - 1) {
        printf("Overflow\n");
    } else {
        top++;
        stack[top] = x;
    }
}
void pop() {
    if (top == -1) {
        printf("Underflow\n");
    } else {
        printf("%d\n", stack[top]);
        top--;
    }
}
void peek() {
    if (top == -1) {
        printf("empty\n");
    } else {
        printf("%d\n", stack[top]);
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int size() {
    return top + 1;
}
int empty() {
    return top == -1;
}
int main() {
    push(10);
    push(20);
    peek();
    printf("%d\n", size());
    pop();
    printf("%s\n", empty() ? "yes" : "no");
}
//20
//2
//20
//no