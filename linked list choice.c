#include <stdio.h>
#include <stdlib.h>
// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};
// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning\n", value);
}
// Function to insert a node at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at the end\n", value);
}
// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}
// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) { // Only one node
        printf("Deleted %d from end\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("Deleted %d from end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}
// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
// Main function with menu-driven approach
int main() {
    struct Node* head = NULL;
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                deleteFromBeginning(&head);
                break;
            case 4:
                deleteFromEnd(&head);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
/*Menu:
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display List
6. Exit
Enter your choice: 1
Enter value: 10
Inserted 10 at the beginning

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display List
6. Exit
Enter your choice: 2
Enter value: 20
Inserted 20 at the end

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display List
6. Exit
Enter your choice: 1
Enter value: 5
Inserted 5 at the beginning

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display List
6. Exit
Enter your choice: 5
Linked List: 5 -> 10 -> 20 -> NULL

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display List
6. Exit
Enter your choice: 3
Deleted 5 from beginning

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display List
6. Exit
Enter your choice: 4
Deleted 20 from end

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display List
6. Exit
Enter your choice: 5
Linked List: 10 -> NULL

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display List
6. Exit
Enter your choice: 6
Exiting...*/