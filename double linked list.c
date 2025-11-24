#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head!=NULL ) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}
// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
    temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
// Delete a node
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}
// Display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;   
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 30);
    printf("Doubly Linked List: ");
    displayList(head);
    deleteNode(&head, 20);
    printf("After deletion: ");
    displayList(head);
}/*Doubly Linked List: 5 <-> 10 <-> 20 <-> 30 <-> NULL
After deletion: 5 <-> 10 <-> 30 <-> NULL*/