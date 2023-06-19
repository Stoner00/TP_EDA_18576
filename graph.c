/**
 * @file graph.c
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Graph functions implementation from graph.h
 */

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

void FreeGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}


Graph* AddEdge(Graph* graph, City* city1, City* city2, int distance) {
    graph->matrix[city1->id][city2->id] = distance;
    graph->matrix[city2->id][city1->id] = distance;

    return graph;
}

void NearestNeighbor(Graph* graph, int startCity) {
    int* visited = (int*)calloc(graph->size, sizeof(int));
    int* path = (int*)malloc((graph->size + 1) * sizeof(int));
    int totalDist = 0;
    int numVisited = 0;

    int currentCity = startCity;
    visited[startCity] = 1;
    path[numVisited++] = startCity;

    while(numVisited < graph->size) {
        int minDist = INT_MAX;
        int minCity;

        for(int i = 0; i < graph->size; i++) {
            if(visited[i] == 0 && graph->matrix[currentCity][i] < minDist) {
                minDist = graph->matrix[currentCity][i];
                minCity = i;
            }
        }

        currentCity = minCity;
        visited[minCity] = 1;
        path[numVisited++] = minCity;
        totalDist += minDist;
    }

    totalDist += graph->matrix[currentCity][startCity];
    path[numVisited] = startCity;

    printf("Path: ");
    for(int i = 0; i <= graph->size; i++) {
        printf("%d ", path[i]);
    }

    printf("\nTotal distance: %d\n", totalDist);

    free(visited);
    free(path);

}

void NearestNeighborLowBattery(Graph* graph, City* cities, Vehicle* vehicles,int startCity) {
    int* visited = (int*)calloc(graph->size, sizeof(int));
    int* path = (int*)malloc((graph->size + 1) * sizeof(int));
    int totalDist = 0;
    int numVisited = 0;

    int currentCity = startCity;
    visited[startCity] = 1;
    path[numVisited++] = startCity;

    while(numVisited < graph->size) {
        int minDist = INT_MAX;
        int minCity;

        for(int i = 0; i < graph->size; i++) {
                if(visited[i] == 0 && graph->matrix[currentCity][i] < minDist) {
                minDist = graph->matrix[currentCity][i];
                minCity = i;
            }
        }

        City* aux = GetCityById(cities, currentCity);
        currentCity = minCity;
        visited[minCity] = 1;
        if(CityHasVehicleBelowBattery(aux, vehicles, 65))
        {
            path[numVisited++] = minCity;
            totalDist += minDist;
        }

    }

    totalDist += graph->matrix[currentCity][startCity];
    path[numVisited] = startCity;

    printf("Path: ");
    for(int i = 0; i <= graph->size; i++) {
        printf("%d ", path[i]);
    }

    printf("\nTotal distance: %d\n", totalDist);

    free(visited);
    free(path);

}



bool CityHasVehicleBelowBattery(City* city, Vehicle* vehicles, int battery) {
    Vehicle* current = vehicles;
    while (current != NULL) {
        if (current->location == city->code && current->battery < battery) {
            return true;
        }
        current = current->next;
    }
    return false;
}
