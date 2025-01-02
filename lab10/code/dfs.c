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
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->vertex = vertex; 
newNode->next = NULL; 
return newNode; 

} 
void addEdge(struct Graph* graph, int src, int dest) { struct Node* newNode = createNode(dest); newNode->next = graph->adjList[src]; 
graph->adjList[src] = newNode; 
newNode = createNode(src); 
newNode->next = graph->adjList[dest]; 
graph->adjList[dest] = newNode; 
} 
void dfs(struct Graph* graph, int vertex, int visited[]) { visited[vertex] = 1; 
struct Node* temp = graph->adjList[vertex]; while (temp != NULL) { 
int adjVertex = temp->vertex; 
if (!visited[adjVertex]) { 
dfs(graph, adjVertex, visited); 
} 
temp = temp->next; 
} 
} 
int isConnected(struct Graph* graph) { 
int visited[MAX] = {0}; 
dfs(graph, 0, visited); 

for (int i = 0; i < graph->vertices; i++) { if (!visited[i]) { 
return 0; 
} 
} 
return 1; 
} 
int main() { 
struct Graph graph; 
int vertices, edges, src, dest; 
printf("Enter the number of vertices: "); scanf("%d", &vertices); 
createGraph(&graph, vertices); 
printf("Enter the number of edges: "); scanf("%d", &edges); 
for (int i = 0; i < edges; i++) { 
printf("Enter source vertex: "); 
scanf("%d", &src); 
printf("Enter destination vertex: "); scanf("%d", &dest); 
addEdge(&graph, src, dest); 
} 
if (isConnected(&graph)) { 
 
printf("The graph is connected.\n"); 
} else { 
printf("The graph is not connected.\n"); 
} 
printf("Name:Dhanush S\n"); 
printf("USN:1BM23CS089"); 
return 0; 
} 

