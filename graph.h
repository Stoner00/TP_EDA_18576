/**
 * @file graph.h
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Header file containing the structure and function declarations for graph
 */

// Disable security warnings
#pragma once
#pragma warning (disable: 4996)

// Import Libraries
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "vehicle.h"

//Configure char size
#define sizeName 25

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//					STRUCT DECLARATION 						    //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region Structs

/**
 * @brief Edge structure
 */
typedef struct Edge {
    int cod;
    char city[sizeName];
    bool visited;
    struct Edge* next;
    struct Adjacency* adjacencies;
    struct Client* clients;
    struct Vehicle* vehicle;
} Edge;

typedef struct EdgeFile {
    int cod;
    char city[sizeName];
    bool visited;
} EdgeFile;

#pragma endregion

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//                    FUNCTIONS DECLARATION						//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region GraphFunctions

/**
 * @defgroup GraphFunctions
 * @{
 */

/**
 * @brief Creates a graph structure.
 *
 * @return The pointer to the created graph.
 */
Edge* CreateGraph();

/**
 * @brief Displays the graph.
 *
 * @param edges The pointer to the graph.
 * @return The pointer to the graph.
 */
Edge* ShowGraph(Edge* edges);

/**
 * @brief Saves the graph to a file.
 *
 * @param edges The pointer to the graph.
 * @param fileName The name of the file to save the graph.
 * @return The result of the operation (success or failure).
 */
bool SaveGraph(Edge* edges, char* fileName);

/**
 * @brief Reads the graph from a file.
 *
 * @param edges The pointer to the graph.
 * @param fileName The name of the file to read the graph from.
 * @param result The result of the operation (success or failure).
 * @return The pointer to the graph.
 */
Edge* ReadGraph(Edge* edges, char* fileName, bool* result);

/**
 * @brief Creates a new edge.
 *
 * @param city The name of the city.
 * @param cod The code of the edge.
 * @return The pointer to the created edge.
 */
Edge* CreateEdge(char* city, int cod);

/**
 * @brief Inserts an edge into the graph in an ordered manner.
 *
 * @param edges The pointer to the graph.
 * @param newEdge The pointer to the edge to insert.
 * @param result The result of the operation (success or failure).
 * @return The pointer to the graph.
 */
Edge* InsertEdgeOrdered(Edge* edges, Edge* newEdge, bool* result);

/**
 * @brief Displays the list of edges in the graph.
 *
 * @param edges The pointer to the graph.
 */
void ShowEdgesList(Edge* edges);

/**
 * @brief Displays the total list of edges in the graph.
 *
 * @param edges The pointer to the graph.
 * @param aux The auxiliary pointer to the graph.
 */
void ShowEdgesListTotal(Edge* edges, Edge* aux);

/**
 * @brief Searches for an edge in the graph by city name.
 *
 * @param edges The pointer to the graph.
 * @param city The name of the city.
 * @return The pointer to the edge if found, NULL otherwise.
 */
Edge* SearchEdge(Edge* edges, char* city);

/**
 * @brief Searches for an edge's code in the graph by city name.
 *
 * @param edges The pointer to the graph.
 * @param city The name of the city.
 * @return The code of the edge if found, -1 otherwise.
 */
int SearchEdgeCodeByCity(Edge* edges, char* city);

/**
 * @brief Searches for an edge in the graph by code.
 *
 * @param edges The pointer to the graph.
 * @param cod The code of the edge.
 * @return The pointer to the edge if found, NULL otherwise.
 */
Edge* SearchEdgeCode(Edge* edges, int cod);

/**
 * @brief Validates the connections between edges in the graph using city names.
 *
 * @param edges The pointer to the graph.
 * @param src The name of the source city.
 * @param dst The name of the destination city.
 * @return True if the connection is valid, false otherwise.
 */
bool ValidateEdgeConections(Edge* edges, char* src, char* dst);

/**
 * @brief Counts the number of hops between two cities in the graph using city names.
 *
 * @param edges The pointer to the graph.
 * @param src The name of the source city.
 * @param dst The name of the destination city.
 * @param countHops The initial count of hops.
 * @return The number of hops between the cities.
 */
int CountHopsByName(Edge* edges, char* src, char* dst, int countHops);

/**
 * @brief Counts the number of hops between two cities in the graph using edge codes.
 *
 * @param edge The pointer to the edge.
 * @param src The code of the source city.
 * @param dst The code of the destination city.
 * @param countHops The initial count of hops.
 * @return The number of hops between the cities.
 */
int CountHopsByCode(Edge* edge, int src, int dst, int countHops);

/**
 * @brief Validates the connection between two cities in the graph using city codes.
 *
 * @param edges The pointer to the graph.
 * @param src The code of the source city.
 * @param dst The code of the destination city.
 * @return True if the connection is valid, false otherwise.
 */
bool ValidateConnectionByCityCode(Edge* edges, int src, int dst);

/**
 * @brief Validates the connection between two cities in the graph using city names.
 *
 * @param edges The pointer to the graph.
 * @param src The name of the source city.
 * @param dst The name of the destination city.
 * @return True if the connection is valid, false otherwise.
 */
bool ValidateConnectionByCityName(Edge* edges, char* src, char* dst);

/**
 * @brief Resets the visited flag for all edges in the graph.
 *
 * @param edges The pointer to the graph.
 * @return The pointer to the graph.
 */
Edge* ResetVisitedEdges(Edge* edges);

/**
 * @brief Inserts an adjacency between two cities in the graph using city names.
 *
 * @param edges The pointer to the graph.
 * @param sourceCity The name of the source city.
 * @param destCity The name of the destination city.
 * @param distance The distance between the cities.
 * @param result The result of the operation (success or failure).
 * @return The pointer to the graph.
 */
Edge* InsertAdjacencyEdgeCityName(Edge* edges, char* sourceCity, char* destCity, float distance, bool* result);

/**
 * @brief Reads the adjacencies from the graph.
 *
 * @param edges The pointer to the graph.
 * @param result The result of the operation (success or failure).
 * @return The pointer to the graph.
 */
Edge* ReadAdjacencies(Edge* edges, bool* result);

/**
 * @brief Inserts an adjacency between two cities in the graph using city codes.
 *
 * @param edges The pointer to the graph.
 * @param sourceCode The code of the source city.
 * @param destCode The code of the destination city.
 * @param distance The distance between the cities.
 * @param result The result of the operation (success or failure).
 * @return The pointer to the graph.
 */
Edge* InsertAdjacencyEdgeCityCode(Edge* edges, int sourceCode, int destCode, float distance, bool* result);

/**
 * @brief Inserts a client into the graph.
 *
 * @param edges The pointer to the graph.
 * @param clients The pointer to the clients.
 * @param result The result of the operation (success or failure).
 * @return The pointer to the graph.
 */
Edge* InsertClientGraph(Edge* edges, Client* clients, bool* result);

/**
 * @brief Inserts a client into the edge of the graph.
 *
 * @param edges The pointer to the graph.
 * @param clients The pointer to the clients.
 * @param location The location of the client.
 * @param result The result of the operation (success or failure).
 * @return The pointer to the graph.
 */
Edge* InsertClientEdge(Edge* edges, Client* clients, char* location, bool* result);

/**
 * @brief Inserts a vehicle into the graph.
 *
 * @param edges The pointer to the graph.
 * @param vehicle The pointer to the vehicle.
 * @param result The result of the operation (success or failure).
 * @return The pointer to the graph.
 */
Edge* InsertVehicleGraph(Edge* edges, Vehicle* vehicle, bool* result);

/**
 * @brief Inserts vehicles into the edge of the graph.
 *
 * @param edges The pointer to the graph.
 * @param vehicles The pointer to the vehicles.
 * @param location The location of the vehicles.
 * @param result The result of the operation (success or failure).
 * @return The pointer to the graph.
 */
Edge* InsertVehiclesEdge(Edge* edges, Vehicle* vehicles, char* location, bool* result);

/**
 * @}
 */


#pragma endregion
