#ifndef CITY_H
#define CITY_H

#include "vehicle.h"

typedef struct City {
    char code[4];
    char name[30];
    struct City* next;
} City;

typedef struct EdgeNode {
    int distance;
    City* origin;
    City* destination;
    struct EdgeNode* next;
} EdgeNode;

typedef struct {
    City* city;
    int distance;
} CityDistance;


/**
 * @brief Creates a city with the specified code
 *
 * @param code - City code
 * @return City* - Pointer to the new city
 */
City* CreateCity(char* code, char* name);

/**
 * @brief Creates an edge node with the specified distance, origin, and destination
 *
 * @param distance - Distance between the cities
 * @param origin - Origin city
 * @param destination - Destination city
 * @return EdgeNode* - Pointer to the new edge node
 */
EdgeNode* CreateEdgeNode(int distance, City* origin, City* destination);

/**
 * @brief Inserts a city into the city list in alphabetical order based on city code
 *
 * @param cities - Pointer to the head of the city list
 * @param newCity - City to insert
 * @return City* - Pointer to the head of the modified city list
 */
City* InsertCityOrdered(City* cities, City* newCity);

/**
 * @brief Inserts an edge node into the edge list in ascending order based on distance
 *
 * @param edges - Pointer to the head of the edge list
 * @param newEdge - Edge node to insert
 * @return EdgeNode* - Pointer to the head of the modified edge list
 */
EdgeNode* InsertEdgeNodeOrdered(EdgeNode* edges, EdgeNode* newEdge);

/**
 * @brief Checks if a city with a specific code exists in the city list
 *
 * @param cities - Pointer to the head of the city list
 * @param code - City code to search for
 * @return int - Returns 1 if the city exists, 0 otherwise
 */
int CityExists(City* cities, char* code);

/**
 * @brief Display the list of cities
 *
 * @param cities Pointer to the head of the city list
 */
void ShowCities(City* cities);

/**
 * @brief Display all edges (connections between cities) for a specific city
 *
 * @param edges Pointer to the head of the edge list
 * @param city Pointer to the city
 */
void ShowCityEdges(EdgeNode* edges, City* city);

/**
 * @brief Display all vehicles in a specific city
 *
 * @param vehicles Pointer to the head of the vehicle list
 * @param city Pointer to the city
 */
void ShowVehiclesInCity(Vehicle* vehicles, City* city);

/**
 * @brief Get a city by it's code
 *
 * @param cities Pointer to the head of the city list
 * @param code City code
 */
City* GetCity(City* cities, char* code);

/**
 * @brief Shows a city and it's connections and vehicles
 *
 * @param cities Pointer to the head of the city list
 * @param edges Pointer to the head of the edges list
 * @param vehicles Pointer to the head of the vehicles list
 */
void ShowAllCityInfo(City* cities, EdgeNode* edges, Vehicle* vehicles);

City** GetNearbyCities(City* cities, EdgeNode* edges, char* code, int range);

void ShowNearbyVehicles(Vehicle* vehicles, City** nearbyCities);
#endif // CITY_H