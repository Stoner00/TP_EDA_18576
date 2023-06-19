/**
 * @file city.c
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief City functions implementation from city.h
 */

#include "city.h"
#include <stdlib.h>
#include <string.h>

City* CreateCity(int id, char* code, char* name) {
    City* city = (City *)malloc(sizeof(City));
    if (city != NULL) {
        city->id = id;
        strncpy(city->code, code, 3);
        city->code[3] = '\0';
        strncpy(city->name, name, 30);
        city->name[29] = '\0';
        city->next = NULL;
    }
    return city;
}

EdgeNode* CreateEdgeNode(int distance, City* origin, City* destination) {
    EdgeNode* edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
    if (edgeNode != NULL) {
        edgeNode->distance = distance;
        edgeNode->origin = origin;
        edgeNode->destination = destination;
        edgeNode->next = NULL;
    }
    return edgeNode;
}

City* InsertCityOrdered(City* cities, City* newCity) {
    if (CityExists(cities, newCity->code)) return cities;

    if (cities == NULL || strcmp(cities->code, newCity->code) > 0) {
        newCity->next = cities;
        cities = newCity;
    } else {
        City* current = cities;
        while (current->next != NULL && strcmp(current->next->code, newCity->code) < 0) {
            current = current->next;
        }
        newCity->next = current->next;
        current->next = newCity;
    }
    return cities;
}

int CityExists(City* cities, char* code) {
    City* current = cities;
    while (current != NULL) {
        if (strcmp(current->code, code) == 0) return 1;
        current = current->next;
    }
    return 0;
}

void ShowCities(City* cities) {
    City* current = cities;
    while (current != NULL) {
        printf("City: %s\n", current->code);
        current = current->next;
    }
}

void ShowCityEdges(Graph* graph, City* city, City* cities) {
    printf("Edges for city: %s\n", city->code);
    for(int i = 0; i < graph->size; i++) {
        if(graph->matrix[city->id][i] != 0) {

            City* auxCity = GetCityById(cities, i);

            if(graph->matrix[city->id][i] < 50000) {  // Check if there's a path
                City* auxCity = GetCityById(cities, i);
                printf("Connected to city: %s, Distance: %d\n", auxCity->code, graph->matrix[city->id][i]);
            }
            else {
                printf("No direct path to city: %s\n", auxCity->code);
            }
//            printf("Connected to city: %s, Distance: %d\n", auxCity->code, graph->matrix[city->id][i]);
        }
    }
}

void ShowVehiclesInCity(Vehicle* vehicles, City* city) {
    Vehicle* current = vehicles;
    while (current != NULL) {
        if (strcmp(current->location, city->code) == 0) {
            printf("Vehicle ID: %d, Type: %s, Battery: %.2d%%, Cost: %.2f, City: %s\n",
                   current->id, current->type, current->battery, current->cost, current->location);
        }
        current = current->next;
    }
}

City* GetCity(City* cities, char* code) {
    City* current = cities;
    while (current != NULL) {
        if (strcmp(current->code, code) == 0) return current;
        current = current->next;
    }
    return NULL;
}

City* GetCityById(City* cities, int id) {
    City* current = cities;
    while (current != NULL) {
        if (current->id == id) return current;
        current = current->next;
    }
    return NULL;
}

void ShowAllCityInfo(City* cities, Graph* graph, Vehicle* vehicles) {
    City* currentCity = cities;
    while (currentCity != NULL) {
        printf("City: %s\n", currentCity->code);
        ShowCityEdges(graph, currentCity, cities);
        ShowVehiclesInCity(vehicles, currentCity);
        currentCity = currentCity->next;
        printf("\n");
    }
}

void ShowNearbyVehiclesFromGraph(City* cities, Graph* graph, Vehicle* vehicles, char* startCityCode, int range) {
    City* startCity = GetCity(cities, startCityCode);
    if(startCity == NULL) {
        printf("City not found: %s\n", startCityCode);
        return;
    }

    for(int i = 0; i < graph->size; i++) {
        if(graph->matrix[startCity->id][i] <= range) {
            City* currentCity = GetCityById(cities, i);
            printf("City: %s, Distance: %d\n", currentCity->code, graph->matrix[startCity->id][i]);
            ShowVehiclesInCity(vehicles, currentCity);
        }
    }
}


