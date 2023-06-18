#include "city.h"
#include <stdlib.h>
#include <string.h>

City* CreateCity(char* code, char* name) {
    City* city = (City *)malloc(sizeof(City));
    if (city != NULL) {
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

EdgeNode* InsertEdgeNodeOrdered(EdgeNode* edges, EdgeNode* newEdge) {
    if (edges == NULL || edges->distance > newEdge->distance) {
        newEdge->next = edges;
        edges = newEdge;
    } else {
        EdgeNode* current = edges;
        while (current->next != NULL && current->next->distance < newEdge->distance) {
            current = current->next;
        }
        newEdge->next = current->next;
        current->next = newEdge;
    }
    return edges;
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

void ShowCityEdges(EdgeNode* edges, City* city) {
    EdgeNode* current = edges;
    while (current != NULL) {
        if (current->origin == city) {
            printf("Edge: %s -> %s, Distance: %d\n", current->origin->code, current->destination->code, current->distance);
        }
        current = current->next;
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

void ShowAllCityInfo(City* cities, EdgeNode* edges, Vehicle* vehicles) {
    City* currentCity = cities;
    while (currentCity != NULL) {
        printf("City: %s\n", currentCity->code);
        ShowCityEdges(edges, currentCity);
        ShowVehiclesInCity(vehicles, currentCity);
        currentCity = currentCity->next;
        printf("\n");
    }
}

City** GetNearbyCities(City* cities, EdgeNode* edges, char* code, int range) {
    City** nearbyCities = NULL;
    int count = 0;

    EdgeNode* currentEdge = edges;
    while (currentEdge != NULL) {
        if (strcmp(currentEdge->origin->code, code) == 0 && currentEdge->distance <= range) {
            nearbyCities = (City**)realloc(nearbyCities, sizeof(City*) * (count + 1));
            nearbyCities[count] = currentEdge->destination;
            count++;
        }
        currentEdge = currentEdge->next;
    }

    return nearbyCities;
}

void ShowNearbyVehicles(Vehicle* vehicles, City** nearbyCities) {
    Vehicle* currentVehicle = vehicles;

    while (currentVehicle != NULL) {
        City** currentCity = nearbyCities;
        while (*currentCity != NULL) {
            if (strcmp(currentVehicle->location, (*currentCity)->code) == 0) {
                printf("Vehicle ID: %d, Type: %s, Battery: %.2f%%, Cost: %.2f, City: %s\n",
                       currentVehicle->id, currentVehicle->type, currentVehicle->battery, currentVehicle->cost, currentVehicle->location);
                break;
            }
            currentCity++;
        }
        currentVehicle = currentVehicle->next;
    }
}


