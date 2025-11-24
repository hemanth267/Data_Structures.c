#include <stdio.h>
#include <stdlib.h>
// Structure for a node
struct Node {
    int data;
    struct Node* next;
};
// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
        temp = temp->next;
        temp->next = newNode;
    }
}
// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL)
        return;  
    struct Node *curr = *head, *prev = NULL;  
    while (curr->data != key) {
        if (curr->next == *head) {
            printf("Element not found!\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr == *head && curr->next == *head) {
        *head = NULL;
        free(curr);
        return;
    }
    if (curr == *head) {
        prev = *head;
        while (prev->next != *head)
            prev = prev->next;
        *head = curr->next;
        prev->next = *head;
        free(curr);
    } else if (curr->next == *head) {
        prev->next = *head;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
}
// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to Head)\n");
}
int main() {
    struct Node* head = NULL; 
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    printf("Circular Linked List: ");
    display(head);
    deleteNode(&head, 20);
    printf("After deleting 20: ");
    display(head);
    deleteNode(&head, 10);
    printf("After deleting 10: ");
    display(head);
    }/*Circular Linked List: 10 -> 20 -> 30 -> 40 -> (Back to Head)
After deleting 20: 10 -> 30 -> 40 -> (Back to Head)
After deleting 10: 30 -> 40 -> (Back to Head)*/