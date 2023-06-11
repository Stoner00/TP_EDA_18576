/**
 * @file adjacency.h
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Header file containing the structure and function declarations for adjacency
 */


// Disable security warnings
#pragma warning (disable: 4996)

// Import Libraries
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//					STRUCT DECLARATION 						    //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region Structs
/**
 * @brief Adjacency structure
 */
typedef struct Adjacency {
    int cod;
    float distance;
    struct Adjacency* next;
} Adjacency;

/**
 * @brief Adjacency File structure
 */
typedef struct AdjacencyFile {
    int sourceCode;
    int destCode;
    float distance;
} AdjacencyFile;

#pragma endregion

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//                    FUNCTIONS DECLARATION						//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region AdjacencyStructs
/**
 * @defgroup AdjacencyFunctions
 * @{
 */


/**
 * @brief Creates a new adjacency node.
 *
 * This function allocates memory for a new adjacency node and initializes its values.
 *
 * @param AdjCode The unique code of the adjacency.
 * @param AdjDist The distance between locations/cities (weight).
 * @return A pointer to the newly created adjacency node.
 */
Adjacency* CreateAdjacency(int AdjCode, float AdjDist);

/**
 * @brief Inserts an adjacency node into the adjacency list.
 *
 * This function inserts a new adjacency node into the adjacency list, maintaining the order of adjacency codes.
 *
 * @param adjacencies The current adjacency list.
 * @param newAdjacency The adjacency node to be inserted.
 * @param result A pointer to a boolean variable indicating the success of the insertion.
 * @return The updated adjacency list.
 */
Adjacency* InsertAdjacency(Adjacency* adjacencies, Adjacency* newAdjacency, bool* result);

/**
 * @brief Shows the list of adjacencies.
 *
 * This function displays the adjacencies created.
 *
 * @param adjacencies The adjacency list to be displayed.
 */
void ShowAdjacencies(Adjacency* adjacencies);

/**
 * @brief Checks if an adjacency with the given code exists.
 *
 * This function checks if an adjacency with the specified code exists in the adjacency list.
 *
 * @param adjacencies The adjacency list to be searched.
 * @param cod The code of the adjacency to be checked.
 * @return true if the adjacency exists, false otherwise.
 */
bool ExistsAdjacency(Adjacency* adjacencies, int cod);

/**
 * @brief Shows the adjacencies of a specific city.
 *
 * This function displays the adjacencies (city ID and distance) of a specific city.
 *
 * @param adjacencies The adjacency list.
 * @param edges The list of edges representing the cities.
 */
void ShowAdjacenciesCity(Adjacency* adjacencies, Edge* edges);

/**
 * @brief Saves the adjacencies to a binary file.
 *
 * This function saves the adjacencies to a binary file with the given file name, associated with the source edge code.
 *
 * @param adjacencies The adjacency list to be saved.
 * @param fileName The name of the file to which the adjacencies will be saved.
 * @param sourceEdgeCode The code of the source edge.
 * @return 1 if the adjacencies were successfully saved, -1 if an error occurred while opening the file, -2 if an error occurred while writing to the file.
 */
int SaveAdjacencies(Adjacency* adjacencies, char* fileName, int sourceEdgeCode);

/**
 * @}
 */
#pragma endregion