#include <stdio.h> 
#include <stdlib.h> 
#define MAX 20 
struct Node { 
int vertex; 
struct Node* next; 
}; 
struct Graph { 
int vertices; 
struct Node* adjList[MAX]; 
}; 
void createGraph(struct Graph* graph, int vertices) { 
graph->vertices = vertices; 
for (int i = 0; i < vertices; i++) { 
graph->adjList[i] = NULL; 
} 
} 
struct Node* createNode(int vertex) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->vertex = vertex; 
newNode->next = NULL; 
return newNode; 
} 
void addEdge(struct Graph* graph, int src, int dest) { struct Node* newNode = createNode(dest); 

newNode->next = graph->adjList[src]; 
graph->adjList[src] = newNode; 
newNode = createNode(src); 
newNode->next = graph->adjList[dest]; 
graph->adjList[dest] = newNode; 
} 
void bfs(struct Graph* graph, int startVertex) { 
int visited[MAX] = {0}; 
int queue[MAX], front = -1, rear = -1; 
rear++; 
queue[rear] = startVertex; 
visited[startVertex] = 1; 
printf("BFS Traversal starting from vertex %d: ", startVertex); 
while (front != rear) { 
front++; 
int currentVertex = queue[front]; 
printf("%d ", currentVertex); 
struct Node* temp = graph->adjList[currentVertex]; while (temp != NULL) { 
int adjVertex = temp->vertex; 
if (!visited[adjVertex]) { 
rear++; 
queue[rear] = adjVertex; 
visited[adjVertex] = 1; 
} 
temp = temp->next; 
} 
} 

printf("\n"); 
} 
int main() { 
struct Graph graph; 
int vertices, edges, src, dest, startVertex; 
printf("Enter the number of vertices: "); 
scanf("%d", &vertices); 
createGraph(&graph, vertices); 
printf("Enter the number of edges: "); 
scanf("%d", &edges); 
for (int i = 0; i < edges; i++) { 
printf("Enter source vertex: "); 
scanf("%d", &src); 
printf("Enter destination vertices (separate by space, end with -1): "); while (1) { 
scanf("%d", &dest); 
if (dest == -1) { 
break; 
} 
addEdge(&graph, src, dest); 
} 
} 
printf("Enter the starting vertex for BFS: "); 
scanf("%d", &startVertex); 
bfs(&graph, startVertex); 
return 0; 
 
} 

