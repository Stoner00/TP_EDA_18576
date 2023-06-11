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
    if (newAdjacency == NULL) return adjacencies;

    if (ExistsAdjacency(adjacencies, newAdjacency->cod) == true) return adjacencies;

    if (adjacencies == NULL) {
        adjacencies = newAdjacency;
        return adjacencies;
    }

    newAdjacency->next = adjacencies;
    adjacencies = newAdjacency;

    return adjacencies;
}

// Displays the adjacencies list
void ShowAdjacencies(Adjacency* adjacencies) {
    Adjacency* currentAdjacency = adjacencies;

    while (currentAdjacency != NULL) {
        printf("\tAdjacency: %d - %.0f Kms\n", currentAdjacency->cod, currentAdjacency->distance);
        currentAdjacency = currentAdjacency->next;
    }
}

// Displays the adjacencies of a specific city
void ShowAdjacenciesCity(Adjacency* adjacencies, Edge* edges) {
    if(adjacencies == NULL){return;}
    if(edges == NULL){return;}

    Edge* cityEdge = SearchEdgeCode(edges, adjacencies->cod);
    printf("\tAdjacency ID: %d - %s - %.0f Kms\n", adjacencies->cod, cityEdge->city, adjacencies->distance);
    ShowAdjacenciesCity(adjacencies->next, edges);
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

// Insert adjacency on start edge
Edge* InsertAdjacencyEdge(Edge* edges, char* startCity, char* destCity, float distance, bool* result) {
    * result = false;

    if (edges == NULL) return edges;
    Edge* auxStart = SearchEdge(edges, startCity);		// search start edge
    int edgeCode = SearchEdgeCodeByCity(edges, destCity);		// Edge code form start city

    if (auxStart == NULL || edgeCode <0) return edges;			// If duplicated, leave

    if (ExistsAdjacency(auxStart->adjacencies, edgeCode) == true)
        return edges;															// Validate if already exists

    //Insere nova adjacencia no vertice "Origem"
    Adjacency * newAdjacency = CreateAdjacency(edgeCode, distance);
    auxStart->adjacencies = InsertAdjacency(auxStart->adjacencies, newAdjacency, result);
    return edges;
}

// Insert adjacency on start edge by id
Edge* InsertAdjacencyEdgeCod(Edge* edges, int startCode, int destCode, float distance, bool* result) {

    * result = false;

    if (edges == NULL) return edges;

    Edge* src = SearchEdgeCode(edges, startCode);
    Edge* dst = SearchEdgeCode(edges, destCode);
    if (src == NULL || dst == NULL) return edges;		//<! Se não encontrou vertice origem e destino, ignora operação

    if (ExistsAdjacency(src->adjacencies, destCode) == true)
        return edges; //Se já foi registado esta adjacencia, ignorar a operação

    //Insere nova adjacencia no vertice "Origem"
    Adjacency* newAdjacency = CreateAdjacency(destCode, distance);
    src->adjacencies = InsertAdjacency(src->adjacencies, newAdjacency, result);
    return edges;
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

Edge* ReadAdjacencies(Edge* edges, bool* result){
    *result = false;
    FILE* file;

    AdjacencyFile aux;
    Edge* auxEdge = edges;
    while (auxEdge != NULL){
        char fileName[100];
        sprintf(fileName, "ficheiros/vertices_%s.bin", auxEdge->city);
        file = fopen(fileName, "rb");
        if (file != NULL) {
            while (fread(&aux, 1, sizeof(AdjacencyFile), file)) {
                edges = InsertAdjacencyEdgeCod(edges, aux.sourceCode, aux.destCode, aux.distance, result);
            }
            fclose(file);
        }
        auxEdge = auxEdge->next;
    }

    return edges;
}
