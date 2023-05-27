/**
 * @file adjacency.c
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Vehicle Functions File
 * @date 2023-05-27
 */

// Librarias
#include "adjacency.h"
#include "graph.h"

Adjacency* CreateAdjacency(int AdjCode, float AdjDist) {
    Adjacency* newAdj = (Adjacency*)malloc(sizeof(Adjacency));
    if (newAdj == NULL) return NULL;

    newAdj->cod = AdjCode;
    newAdj->distance = AdjDist;
    newAdj->next = NULL;

    return newAdj;
}

Adjacency* InsertAdjacency(Adjacency* adjacencies, Adjacency* newAdjacency, bool* result) {
    *result = false;

    if (newAdjacency == NULL) return adjacencies;

    if (ExistsAdjacency(adjacencies, newAdjacency->cod) == true) return adjacencies;

    if (adjacencies == NULL) {
        adjacencies = newAdjacency;
        *result = true;
        return adjacencies;
    }

    newAdjacency->next = adjacencies;
    adjacencies = newAdjacency;

    return adjacencies;
}

// Displays the adjacencies created
void ShowAdjacencies(Adjacency* adjacencies) {
    Adjacency* currentAdjacency = adjacencies;

    while (currentAdjacency != NULL) {
        printf("\tAdjacency: %d - %.0f Kms\n", currentAdjacency->cod, currentAdjacency->distance);
        currentAdjacency = currentAdjacency->next;
    }
}

// Checks if an adjacency with the given code exists
bool ExistsAdjacency(Adjacency* adjacencies, int cod) {
    Adjacency* currentAdjacency = adjacencies;

    while (currentAdjacency != NULL) {
        if (currentAdjacency->cod == cod) {
            return true;
        }
        currentAdjacency = currentAdjacency->next;
    }

    return false;
}

// Displays the adjacencies of a specific city
void ShowAdjacenciesCity(Adjacency* adjacencies, Edge* vertices) {
    Adjacency* currentAdjacency = adjacencies;

    while (currentAdjacency != NULL) {
        Edge* cityEdge = SearchEdgeCode(vertices, currentAdjacency->cod);
        if (cityEdge != NULL) {
            printf("\tAdjacency ID: %d - %s - %.0f Kms\n", cityEdge->cod, cityEdge->city, currentAdjacency->distance);
        }
        currentAdjacency = currentAdjacency->next;
    }
}

// Saves the adjacencies to a binary file associated with the source edge code
int SaveAdjacencies(Adjacency* adjacencies, char* fileName, int sourceEdgeCode) {
    FILE* file;

    if (adjacencies == NULL) return -1;

    file = fopen(fileName, "ab");
    if (file == NULL) return -2;

    Adjacency* auxAdjacency = adjacencies;
    AdjacencyFile auxFile;

    while (auxAdjacency != NULL) {
        auxFile.destCode = auxAdjacency->cod;
        auxFile.sourceCode = sourceEdgeCode;
        auxFile.distance = auxAdjacency->distance;
        fwrite(&auxFile, 1, sizeof(AdjacencyFile), file);
        auxAdjacency = auxAdjacency->next;
    }

    fclose(file);
    return 1;
}
