// graph.c
#include "graph.h"
#include "city.h"
#include <stdlib.h>
#include <limits.h>

Graph* CreateGraph(int size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = size;
    graph->matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        graph->matrix[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            graph->matrix[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
    return graph;
}

void AddEdge(Graph* graph, City* city1, City* city2, int distance) {
    graph->matrix[city1->id][city2->id] = distance;
    graph->matrix[city2->id][city1->id] = distance;  // If the graph is undirected
}

void FreeGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}

void NearestNeighbor(Graph* graph, int start_city) {
    int* visited = (int*)calloc(graph->size, sizeof(int));
    int* path = (int*)malloc(graph->size * sizeof(int));
    int total_dist = 0;
    int num_visited = 0;

    // Start at the start city
    int current_city = start_city;
    visited[start_city] = 1;
    path[num_visited++] = start_city;

    while(num_visited < graph->size) {
        int min_dist = INT_MAX;
        int min_city;

        // Find the closest city
        for(int i = 0; i < graph->size; i++) {
            if(visited[i] == 0 && graph->matrix[current_city][i] < min_dist) {
                min_dist = graph->matrix[current_city][i];
                min_city = i;
            }
        }

        // Go to the closest city
        current_city = min_city;
        visited[min_city] = 1;
        path[num_visited++] = min_city;
        total_dist += min_dist;
    }

    // Return to the start city
    total_dist += graph->matrix[current_city][start_city];
    path[num_visited] = start_city;

    printf("Path: ");
    for(int i = 0; i <= graph->size; i++) {
        printf("%d ", path[i]);
    }
    printf("\nTotal distance: %d\n", total_dist);

    free(visited);
    free(path);
}
