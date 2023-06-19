/**
 * @file city.h
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Header file containing the structure and function declarations for city
 */

#include "vehicle.h"
#include "graph.h"

typedef struct City {
    int id;
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
 * @param id - City ID
 * @param code - City code
 * @param name - City name
 * @return City* - Pointer to the new city
 */
City* CreateCity(int id, char* code, char* name);

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
void ShowCityEdges(Graph* graph, City* city, City* cities);

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
 * @brief Get a city by it's id
 *
 * @param cities Pointer to the head of the city list
 * @param id City id
 */
City* GetCityById(City* cities, int id);

/**
 * @brief Shows a city and it's connections and vehicles
 *
 * @param cities Pointer to the head of the city list
 * @param graph Pointer to the graph of edged
 * @param vehicles Pointer to the head of the vehicles list
 */
void ShowAllCityInfo(City* cities, Graph* graph, Vehicle* vehicles);

/**
 * @brief Shows vehicles in a range of a city
 *
 * @param cities Pointer to the head of the city list
 * @param graph Pointer to the graph of edged
 * @param vehicles Pointer to the head of the vehicles list
 * @param startCityCode Code of the city to start the range from
 * @param range Range in kilometers
 */
void ShowNearbyVehiclesFromGraph(City* cities, Graph* graph, Vehicle* vehicles, char* startCityCode, int range);
