/**
 * @file vehicle.h
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Header file containing the structure and function declarations for vehicles
 */

// Disable security warnings
#pragma once
#pragma warning (disable: 4996)

// Import Libraries
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Configure char size
#define locationSize 40
#define typeSize 15

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//					STRUCT DECLARATION 						    //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region VehicleStruct

/**
 * @brief Vehicle structure
 */
typedef  struct Vehicle {
    int id;
    char type[typeSize];
    char location[locationSize];
    int battery;
    float cost;
    bool rented;
    struct Client* rentedTo;
    struct Vehicle* next;
} Vehicle;

#pragma endregion

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//                    FUNCTIONS DECLARATION						//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region VehicleFunctions

/**
 * @brief Create a Vehicle object
 * @param id Vehicle ID
 * @param type Vehicle type
 * @param location Vehicle location
 * @param battery Battery percentage
 * @param cost Cost of the vehicle
 * @return Vehicle* Pointer to the new vehicle object
 */
Vehicle* CreateVehicle(int id, char type[], char location[], int battery, float cost);

/**
 * @brief Insert a Vehicle into a sorted list
 * @param vehicles List of vehicles
 * @param newVehicle Vehicle to be inserted
 * @return Vehicle* Updated list of vehicles
 */
Vehicle* InsertVehicleOrdered(Vehicle* vehicles, Vehicle* newVehicle);

/**
 * @brief Insert a vehicle into a list sorted by descending battery
 * @param vehicles List of vehicles
 * @param newVehicle New vehicle to be inserted
 * @return Vehicle* Updated list of vehicles
 */
Vehicle* InsertVehicleSortedByBatteryDesc(Vehicle* vehicles, Vehicle* newVehicle);

/**
 * @brief Modify the battery value of a vehicle
 * @param vehicles List of vehicles
 * @param id Vehicle ID to be modified
 * @param battery New battery value
 * @return Vehicle* Updated list of vehicles
 */
Vehicle* ModifyVehicleBattery(Vehicle* vehicles, int id, int battery);

/**
 * @brief Read vehicles from a binary file and sort them by battery level
 * @param fileName Name of the binary file
 * @return Vehicle* List of vehicles read and sorted by battery
 */
Vehicle* ReadVehicleFromBinSortedByBatteryDesc(char* fileName);

/**
 * @brief Read Vehicles from a binary file to a list
 * @param fileName Name of the file to read from
 * @return Vehicle* List of vehicles read from the file
 */
Vehicle* ReadVehiclesFromBin(char* fileName);

/**
 * @brief Remove a Vehicle from the list
 * @param vehicles List of vehicles
 * @param id Vehicle ID to be removed
 * @return Vehicle* Updated list of vehicles
 */
Vehicle* RemoveVehicle(Vehicle* vehicles, int id);

/**
 * @brief Search for a vehicle in the list by its ID
 * @param vehicles List of vehicles
 * @param id Vehicle ID to search
 * @return Vehicle* Pointer to the found vehicle, or NULL if not found
 */
Vehicle* SearchVehicle(Vehicle* vehicles, int id);

/**
 * @brief Free vehicles list from memory
 * @param vehicles Pointer to the list of vehicles
 * @return bool True if the list was freed, false otherwise
 */
bool DestroyVehiclesList(Vehicle** vehicles);

/**
 * @brief Rent a vehicle
 * @param vehicles List of vehicles
 * @param id Vehicle ID to rent
 * @return bool True if the vehicle was rented, false otherwise
 */
bool RentVehicle(Vehicle* vehicles, int id);

/**
 * @brief Save Vehicles to a binary file
 * @param fileName Name of the file to save to
 * @param vehicles List of vehicles
 * @return bool True if the operation was successful, false otherwise
 */
bool SaveVehiclesToBin(char* fileName, Vehicle* vehicles);

/**
 * @brief Show vehicles of a given location
 * @param vehicles List of vehicles
 * @param location Location to filter vehicles by
 * @return bool True if there are vehicles to show, false otherwise
 */
bool ShowVehiclesByLocation(Vehicle *vehicles, char* location);

/**
 * @brief Unrent a vehicle
 * @param vehicles List of vehicles
 * @param id Vehicle ID to unrent
 * @return bool True if the vehicle was unrented, false otherwise
 */
bool UnrentVehicle(Vehicle* vehicles, int id);

/**
 * @brief Check if a vehicle with the given ID exists in the list
 * @param vehicle List of vehicles
 * @param id Vehicle ID to search
 * @return bool True if the vehicle exists, false otherwise
 */
bool VehicleExists(Vehicle* vehicles, int id);

/**
 * @brief Print data from a Vehicle
 * @param vehicle Vehicle to show data from
 */
void ShowVehicle(Vehicle* vehicle);

/**
 * @brief Show a list of Vehicles in memory
 * @param vehicles List of vehicles
 */
void ShowVehiclesList(Vehicle* vehicles);

#pragma endregion