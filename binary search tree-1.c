#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For boolean type
// Structure for a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};
// Structure for the adjacency list itself (array of pointers to Node)
struct Graph {
    int numVertices;
    struct Node** adjLists; // Array of pointers to linked lists
    bool* visited;          // To keep track of visited vertices
};
// Queue structure for BFS
struct Queue {
    int items[100]; // Assuming a max of 100 vertices for simplicity
    int front;
    int rear;
};
// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}
// Function to create a graph with 'vertices' number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        perror("Failed to allocate memory for graph");
        exit(EXIT_FAILURE);
    }
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    if (graph->adjLists == NULL) {
        perror("Failed to allocate memory for adjacency lists");
        free(graph);
        exit(EXIT_FAILURE);
    }
    graph->visited = (bool*)malloc(vertices * sizeof(bool));
    if (graph->visited == NULL) {
        perror("Failed to allocate memory for visited array");
        free(graph->adjLists);
        free(graph);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL; // Initialize all adjacency lists to NULL
        graph->visited[i] = false;  // Mark all vertices as not visited
    }
    return graph;
}
// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
// Queue functions
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (q == NULL) {
        perror("Failed to allocate memory for queue");
        exit(EXIT_FAILURE);
    }
    q->front = -1;
    q->rear = -1;
    return q;
}
bool isEmpty(struct Queue* q) {
    return q->rear == -1;
}
void enqueue(struct Queue* q, int value) {
    if (q->rear == 99) { // Max 100 items
        printf("Queue is full!\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) { // Reset queue if empty
            q->front = q->1;
            q->rear = -1;
        }
    }
    return item;
}
// BFS Function
void bfs(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();
    graph->visited[startVertex] = true;
    enqueue(q, startVertex);
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);
        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->data;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(q); // Free the queue memory
}
// Function to free graph memory
void freeGraph(struct Graph* graph) {
    if (graph == NULL) return;
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* current = graph->adjLists[i];
        while (current != NULL) {
            struct Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);
}
// Main function to test BFS
int main() {
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);
    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    // Perform BFS starting from vertex 0
    bfs(graph, 0);
    // You might want to reset visited array if performing BFS from another node
    // for (int i = 0; i < numVertices; i++) {
    //     graph->visited[i] = false;
    // }
    // bfs(graph, 1); // Example of another BFS run
    freeGraph(graph); // Free allocated memory
}//BFS Traversal starting from vertex 0: 0 1 2 3 4 5 