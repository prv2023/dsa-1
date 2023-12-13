#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjList[MAX_VERTICES];
};

struct Stack {
    int data[MAX_VERTICES];
    int top;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Since it's an undirected graph, add an edge from dest to src as well
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    stack->data[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->data[stack->top--];
}

void dfs(struct Graph* graph, int startVertex) {
    struct Stack* stack = createStack();
    int visited[MAX_VERTICES] = {0};

    push(stack, startVertex);

    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);

        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;
        }

        struct Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                push(stack, temp->vertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("Depth-First Search starting from vertex %d: ", startVertex);
    dfs(graph, startVertex);

    return 0;
}
