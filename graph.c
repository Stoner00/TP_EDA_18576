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
        return NULL;
    }
    ShowEdgesList(edges);
    return edges;
}

bool SaveGraph(Edge* edges, char* fileName) {
    if (edges == NULL) return false;
    FILE* file;
    int auxAdjacency;

    file = fopen(fileName, "wb");
    if (file == NULL) return false;
    Edge * auxEdge = edges;
    EdgeFile auxFile;
    while (auxEdge != NULL) {
        auxFile.cod = auxEdge->cod;
        strcpy(auxFile.city, auxEdge->city);
        fwrite(&auxFile, 1, sizeof(EdgeFile), file);

        if (auxEdge->adjacencies) {
            char fileName2[100];
            sprintf(fileName2, "ficheiros/vertices_%s.bin", auxEdge->city);
            auxAdjacency = SaveAdjacencies(auxEdge->adjacencies, fileName2, auxEdge->cod);
        }
        auxEdge = auxEdge->next;
    }
    fclose(file);
    return true;
}

Edge* ReadGraph(Edge* edges, char* fileName, bool* result) {
    *result = false;
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) return NULL;
    EdgeFile aux;
    Edge* newEdge;
    while (fread(&aux, 1, sizeof(EdgeFile), file)) {
        newEdge = CreateEdge(aux.city, aux.cod);
        edges = InsertEdgeOrdered(edges, newEdge, result);
    }
    fclose(file);
    return edges;
}

Edge* CreateEdge(char* city, int cod) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    if (newEdge == NULL) {
        return NULL;
    }

    strcpy(newEdge->city, city);
    newEdge->cod = cod;
    strcpy(newEdge->city, city);
    newEdge->next = NULL;
    newEdge->adjacencies = NULL;
    return newEdge;
}

Edge* InsertEdgeOrdered(Edge* edges, Edge* newEdge, bool* result) {
    *result = false;

    if (newEdge == NULL) return edges;


    Edge *aux = edges;
    while (aux != NULL) {						//Check if exists
        if (aux->cod == newEdge->cod) {
            *result = false;
            return edges;
        }
        aux = aux->next;
    }

    if (edges == NULL) {						// Insert at the beggining
        edges = newEdge;
        *result = true;
        return edges;
    }

    else
    {
        Edge* aux = edges;
        Edge* auxAnt = NULL;
        while (aux && aux->cod < newEdge->cod) {
            auxAnt = aux;
            aux = aux->next;
        }
        if (auxAnt == NULL) {					// Insert in the middle
            newEdge->next = edges;
            edges = newEdge;
        }
        else
        {
            auxAnt->next = newEdge;			// Insert at the end
            newEdge->next = aux;
        }
        *result = true;
    }
    return edges;
}

void ShowEdgesList(Edge* edges) {
    Edge* currentEdge = edges;

    if (edges == NULL) return;

    printf("\tEdge: %d - %s \n", edges->cod, edges->city);
    ShowEdgesList(edges->next);
}

void ShowEdgesListTotal(Edge* edges, Edge* aux) {
    if (edges == NULL) return;

    printf("\nEdge: %d - %s\n", edges->cod, edges->city);
    ShowAdjacenciesCity(edges->adjacencies, aux);

    Client* currentClient = edges->clients;
    while (currentClient != NULL) {
        printf("\t	Clients: VAT: %d, Name: %s\n", currentClient->vat, currentClient->name);
        currentClient = currentClient->next;
    }

    Vehicle* currentVehicle = edges->vehicle;
    while (currentVehicle != NULL) {
        printf("\t	Vehicles: ID: %d, Type: %s, Battery: %d%%\n", currentVehicle->id, currentVehicle->type, currentVehicle->battery);
        currentVehicle = currentVehicle->next;
    }

    ShowEdgesListTotal(edges->next, aux);

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

bool ValidateEdgeConectionsCode(Edge* edges, int src, int dst) {
    if (src == dst) return true;

    Edge* aux = SearchEdgeCode(edges, src);
    aux->visited = true;
    printf(" Edge: %s : %d\n", aux->city, aux->cod);

    Adjacency* adjacency = aux->adjacencies;
    while (adjacency) {
        Edge* aux = SearchEdgeCode(edges, adjacency->cod);
        if (aux->visited == false)
        {
            return ValidateEdgeConectionsCode(edges, adjacency->cod, dst);
        }
        else
            aux = aux->next;
    }
}

bool ValidateEdgeConectionsCity(Edge* edges, char* src, char* dst) {
    int srcCod = SearchEdgeCodeByCity(edges, src);
    int dstCod = SearchEdgeCodeByCity(edges, dst);
    bool validateCode = ValidateEdgeConectionsCode(edges, srcCod, dstCod);
    return validateCode;
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

    else {
        Edge* auxEdge = SearchEdgeCode(edges, src);
        Adjacency * auxAdj = auxEdge->adjacencies;

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
    if (edges != NULL) {
        Vehicle* auxVehicle = vehicle;

        while (auxVehicle != NULL)
        {
            if (auxVehicle->location == vehicle->location) {
                edges = InsertVehiclesEdge(edges, vehicle, &auxVehicle->location, &result);
                vehicle = vehicle->next;
            }
            auxVehicle = auxVehicle->next;
        }
    }
    else printf("Error inserting Vehicle!\n");

    return edges;
}

Edge* InsertVehiclesEdge(Edge* edges, Vehicle* vehicles, char* location, bool* result) {
    *result = false;
    if (edges == NULL) return edges;
    if (location == NULL) return edges;

    Edge* auxEdge = SearchEdge(edges, location);

    while (auxEdge != NULL) {

        // check if the location is theone we want
        if (strcmp(auxEdge->city, location) == 0) {
            Vehicle* currentVehicle = vehicles;

            while (currentVehicle != NULL) {

                // check vehicle location
                if (strcmp(currentVehicle->location, location) == 0) {

                    // Check if vehicle already on edge
                    bool alreadyInserted = false;
                    Vehicle* existingVehicle = auxEdge->vehicle;
                    while (existingVehicle != NULL) {
                        if (strcmp(existingVehicle->location, location) == 0 &&
                            strcmp(existingVehicle->type, currentVehicle->type) == 0) {
                            alreadyInserted = true;
                            break;
                        }
                        currentVehicle = existingVehicle->next;
                    }

                    // Insert vehicle
                    if (!alreadyInserted) {

                        Vehicle * newVehicle = (Vehicle*)malloc(sizeof(Vehicle));
                        *newVehicle = *currentVehicle;

                        newVehicle->next = auxEdge->vehicle;
                        auxEdge->vehicle = newVehicle;

                        *result = true;
                    }
                }

                currentVehicle = currentVehicle->next;
            }
            break;
        }
        auxEdge = auxEdge->next;
    }

    return edges;
}
