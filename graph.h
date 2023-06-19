/**
 * @file graph.h
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Header file containing the structure and function declarations for graph
 */
#ifndef GRAPH_H
#define GRAPH_H

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//					STRUCT DECLARATION 						    //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#include <stdbool.h>
#include "vehicle.h"

typedef struct City City;

typedef struct Graph {
    int** matrix;
    int size;
} Graph;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//                    FUNCTIONS DECLARATION						//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

/**
 * @brief Create a new graph of a given size
 * @param size Size of the matrix
 * @return Graph* New graph created
 */
Graph* CreateGraph(int size);

/**
 * @brief Adds an edge to the given graph
 * @param city1 First city
 * @param city2 Second city
 * @return Graph* Updated Graph
 */
Graph* AddEdge(Graph* graph, City* city1, City* city2, int distance);

/**
 * @brief Lists the shortest path by nearest neighbour method
 * @param graph Size of the matrix
 * @param startCity ID of the start city
 */
void NearestNeighbor(Graph* graph, int startCity);
void NearestNeighborLowBattery(Graph* graph,City* cities, Vehicle* vehicles,int startCity);
bool CityHasVehicleBelowBattery(City* city, Vehicle* vehicles, int battery);
Graph* FilterGraphForLowBattery(Graph* graph, City* cities, Vehicle* vehicles, int startCity, int battery);
void FindPathForLowBattery(Graph* graph, City* cities, Vehicle* vehicles, int startCity, int battery);
#endif
