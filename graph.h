// graph.h
#ifndef GRAPH_H
#define GRAPH_H

typedef struct City City;

typedef struct Graph {
    int** matrix;
    int size;
} Graph;

Graph* CreateGraph(int size);
void AddEdge(Graph* graph, City* city1, City* city2, int distance);
void FreeGraph(Graph* graph);
void NearestNeighbor(Graph* graph, int start_city);

#endif // GRAPH_H
