#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
struct Node* Creat_A_Node(int val) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}
void Display(struct Node *head) {
    struct Node *temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void Insert(int val) {
    struct Node *nn = Creat_A_Node(val);
    if (head == NULL) {
        head = nn;
        tail = head;
    } else {
        tail->next = nn;
        tail = nn;
    }
}
void Insert_At_Head(int val) {
    struct Node *nn = Creat_A_Node(val);
    nn->next = head;
    head = nn;
}
void Insert_At_Middle(int pos, int val) {
    int cnt = 1;
    struct Node *nn = Creat_A_Node(val);
    struct Node *temp = head;
    while (cnt < pos - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL) return;  // Position is out of bounds
    nn->next = temp->next;
    temp->next = nn;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        Insert(val);
    }
    Insert_At_Head(5);
    Insert_At_Middle(3, 200);
    Display(head);
}/*5
10 20 30 40 50
5 10 200 20 30 40 50*/