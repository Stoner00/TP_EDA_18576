/**
 * @file adjacency.c
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Vehicle Functions File
 * @date 2023-05-27
 */

// Import Libraries
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function implementations

Edge* CreateGraph() {
    Edge* edges = NULL;
    return edges;
}

Edge* ShowGraph(Edge* edges) {
    if (edges == NULL) {
        printf("Graph is empty.\n");
        return NULL;
    }

    printf("Graph:\n");
    ShowEdgesList(edges);
    return edges;
}

int SaveGraph(Edge* edges, char* fileName) {
    if (edges == NULL) {
        printf("Graph is empty. Nothing to save.\n");
        return 0;
    }

    FILE* file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Error opening file '%s' for writing.\n", fileName);
        return 0;
    }

    Edge* current = edges;
    while (current != NULL) {
        fwrite(current, sizeof(Edge), 1, file);
        current = current->next;
    }

    fclose(file);
    printf("Graph saved to file '%s' successfully.\n", fileName);
    return 1;
}

Edge* ReadGraph(Edge* edges, char* fileName, bool* result) {
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file '%s' for reading.\n", fileName);
        *result = false;
        return edges;
    }

    Edge edge;
    while (fread(&edge, sizeof(Edge), 1, file) != 0) {
        edges = InsertEdgeOrdered(edges, &edge, result);
        if (!*result) {
            fclose(file);
            return edges;
        }
    }

    fclose(file);
    printf("Graph read from file '%s' successfully.\n", fileName);
    *result = true;
    return edges;
}

Edge* CreateEdge(char* city, int cod) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    if (newEdge == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    strcpy(newEdge->city, city);
    newEdge->cod = cod;
    newEdge->next = NULL;
    return newEdge;
}

Edge* InsertEdgeOrdered(Edge* edges, Edge* newEdge, bool* result) {
    if (edges == NULL) {
        *result = true;
        return newEdge;
    }

    if (strcmp(newEdge->city, edges->city) < 0) {
        newEdge->next = edges;
        *result = true;
        return newEdge;
    }

    Edge* current = edges;
    while (current->next != NULL && strcmp(newEdge->city, current->next->city) > 0) {
        current = current->next;
    }

    if (current->next != NULL && strcmp(newEdge->city, current->next->city) == 0) {
        printf("Edge with city '%s' already exists.\n", newEdge->city);
        *result = false;
        return edges;
    }

    newEdge->next = current->next;
    current->next = newEdge;
    *result = true;
    return edges;
}

void ShowEdgesList(Edge* edges) {
    Edge* currentEdge = edges;

    while (currentEdge != NULL) {
        printf("City: %s\n", currentEdge->city);
        printf("Code: %d\n", currentEdge->cod);
        printf("Adjacencies:\n");
        ShowAdjacencies(currentEdge->adjacencies);
        printf("------------------------\n");
        currentEdge = currentEdge->next;
    }
}

void ShowEdgesListTotal(Edge* edges, Edge* aux) {
    Edge* currentEdge = edges;

    while (currentEdge != NULL) {
        printf("City: %s\n", currentEdge->city);
        printf("Code: %d\n", currentEdge->cod);
        printf("Adjacencies:\n");
        ShowAdjacencies(currentEdge->adjacencies);
        printf("------------------------\n");

        if (currentEdge->cod == aux->cod) {
            break;
        }

        currentEdge = currentEdge->next;
    }
}

Edge* SearchEdge(Edge* edges, char* city) {
    Edge* current = edges;
    while (current != NULL) {
        if (strcmp(current->city, city) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int SearchEdgeCodeByCity(Edge* edges, char* city) {
    Edge* edge = SearchEdge(edges, city);
    if (edge != NULL) {
        return edge->cod;
    }
    return -1;
}

Edge* SearchEdgeCode(Edge* edges, int cod) {
    Edge* current = edges;
    while (current != NULL) {
        if (current->cod == cod) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

bool ValidateEdgeConections(Edge* edges, char* src, char* dst) {
    Edge* source = SearchEdge(edges, src);
    Edge* destination = SearchEdge(edges, dst);

    if (source == NULL || destination == NULL) {
        return false;
    }

    return true;
}

int CountHopsByName(Edge* edges, char* src, char* dst, int countHops) {
    if (edges == NULL) return 0;

    if (src == dst) return (++countHops);

    else {
        Edge* auxEdge = SearchEdge(edges, src);
        Adjacency * auxAdj = auxEdge->adjacencies;

        while (auxAdj) {
            Edge* edge = SearchEdgeCode(edges, auxAdj->cod);
            countHops = CountHopsByName(edges, edge->city, dst, countHops);
            auxAdj = auxAdj->next;
        }
    }
    return countHops;
}

int CountHopsByCode(Edge* edges, int src, int dst, int countHops) {
    if (edges == NULL) return 0;

    if (src == dst) return (++countHops);

        // Retorna vertices com adjacencias
    else {
        Edge* auxEdge = SearchEdgeCode(edges, src);
        Adjacency * auxAdj = auxEdge->adjacencies;			// Adjacencias em relação á cidade de SRC

        while (auxAdj) {
            Edge* v = SearchEdgeCode(edges, auxAdj->cod);
            countHops = CountHopsByCode(edges, v->cod, dst, countHops);
            auxAdj = auxAdj->next;
        }
    }
    return countHops;
}

bool ValidateConnectionByCityCode(Edge* edges, int src, int dst) {
    Edge* source = SearchEdgeCode(edges, src);
    Edge* destination = SearchEdgeCode(edges, dst);

    if (source == NULL || destination == NULL) {
        return false;
    }

    return ValidateEdgeConections(edges, source->city, destination->city);
}

bool ValidateConnectionByCityName(Edge* edges, char* src, char* dst) {
    Edge* source = SearchEdge(edges, src);
    Edge* destination = SearchEdge(edges, dst);

    if (source == NULL || destination == NULL) {
        return false;
    }

    return ValidateEdgeConections(edges, src, dst);
}

Edge* ResetVisitedEdges(Edge* edges) {
    Edge* current = edges;
    while (current != NULL) {
        current->visited = false;
        current = current->next;
    }
    return edges;
}

Edge* InsertAdjacencyEdgeCityName(Edge* edges, char* sourceCity, char* destCity, float distance, bool* result) {
    Edge* source = SearchEdge(edges, sourceCity);
    Edge* destination = SearchEdge(edges, destCity);

    if (source == NULL || destination == NULL) {
        *result = false;
        return edges;
    }

    Adjacency* newAdjacency = (Adjacency*)malloc(sizeof(Adjacency));
    if (newAdjacency == NULL) {
        printf("Memory allocation failed.\n");
        *result = false;
        return edges;
    }

    newAdjacency->cod = destination->cod;
    newAdjacency->distance = distance;
    newAdjacency->next = NULL;

    Adjacency* current = source->adjacencies;
    if (current == NULL) {
        source->adjacencies = newAdjacency;
        *result = true;
        return edges;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newAdjacency;
    *result = true;
    return edges;
}

Edge* ReadAdjacencies(Edge* edges, bool* result) {
    Edge* current = edges;
    while (current != NULL) {
        char fileName[100];
        sprintf(fileName, "ficheiros/vertices_%s.bin", current->city);
        FILE* file = fopen(fileName, "rb");
        if (file != NULL) {
            Adjacency adjacency;
            while (fread(&adjacency, sizeof(Adjacency), 1, file) != 0) {
                InsertAdjacencyEdgeCityCode(edges, current->cod, adjacency.cod, adjacency.distance, result);
                if (!*result) {
                    fclose(file);
                    return edges;
                }
            }
            fclose(file);
        }
        current = current->next;
    }

    *result = true;
    return edges;
}

Edge* InsertAdjacencyEdgeCityCode(Edge* edges, int sourceCode, int destCode, float distance, bool* result) {
    Edge* source = SearchEdgeCode(edges, sourceCode);
    Edge* destination = SearchEdgeCode(edges, destCode);

    if (source == NULL || destination == NULL) {
        *result = false;
        return edges;
    }

    Adjacency* newAdjacency = (Adjacency*)malloc(sizeof(Adjacency));
    if (newAdjacency == NULL) {
        printf("Memory allocation failed.\n");
        *result = false;
        return edges;
    }

    newAdjacency->cod = destination->cod;
    newAdjacency->dist = distance;
    newAdjacency->prox = NULL;

    Adjacency* current = source->adjacencies;
    if (current == NULL) {
        source->adjacencies = newAdjacency;
        *result = true;
        return edges;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newAdjacency;
    *result = true;
    return edges;
}

Edge* InsertClientGraph(Edge* edges, Client* clients, bool* result) {
    if (clients == NULL) {
        printf("No clients to insert.\n");
        *result = false;
        return edges;
    }

    Client* current = clients;
    while (current != NULL) {
        edges = InsertClientEdge(edges, current, current->location, result);
        if (!*result) {
            return edges;
        }
        current = current->next;
    }

    *result = true;
    return edges;
}

Edge* InsertClientEdge(Edge* edges, Client* clients, char* location, bool* result) {
    Edge* edge = SearchEdge(edges, location);
    if (edge == NULL) {
        printf("No edge with city '%s' found.\n", location);
        *result = false;
        return edges;
    }

    edge->clients = clients;
    *result = true;
    return edges;
}

Edge* InsertVehicleGraph(Edge* edges, Vehicle* vehicle, bool* result) {
    if (vehicle == NULL) {
        printf("No vehicle to insert.\n");
        *result = false;
        return edges;
    }

    edges = InsertVehiclesEdge(edges, vehicle, vehicle->location, result);
    return edges;
}

Edge* InsertVehiclesEdge(Edge* edges, Vehicle* vehicles, char* location, bool* result) {
    Edge* edge = SearchEdge(edges, location);
    if (edge == NULL) {
        printf("No edge with city '%s' found.\n", location);
        *result = false;
        return edges;
    }

    if (edge->vehicle == NULL) {
        edge->vehicle = vehicles;
    } else {
        Vehicle* current = edge->vehicle;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = vehicles;
    }

    *result = true;
    return edges;
}
