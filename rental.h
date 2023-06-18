/**
 * @file rental.h
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Header file containing the structure and function declarations for rentals
 */

#pragma once
#pragma warning (disable: 4996)

// Import Libraries
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "vehicle.h"
#include "client.h"

// Configure char size
#define dateSize 11 // Assuming YYYY-MM-DD format

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//                    STRUCT DECLARATION                        //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region RentalStruct

/**
 * @brief Rental structure
 */
typedef struct Rental {
    int rentalID;
    int vehicleID;
    int clientID;
    float totalKilometers;
    float totalCost;
    char date[dateSize];
    struct Rental* next;
} Rental;

#pragma endregion

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//                    FUNCTIONS DECLARATION                     //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region RentalFunctions

/**
 * @brief Create a rental with specified parameters
 * @param rentalID The unique identifier for this rental
 * @param vehicleID The id of the rented vehicle
 * @param clientVAT The vat of the client who rents the vehicle
 * @param totalKilometers The total kilometers that are planned to be driven with the vehicle
 * @param vehicle Vehicle to rent
 * @param client Client requesting the rental
 * @return Rental* Pointer to the new rental, or NULL if failed
 */
Rental* CreateRental(int rentalID, int vehicleID, int clientVAT, float totalKilometers, Vehicle* vehicle, Client* client);

/**
 * @brief Insert a rental into the list in an ordered manner by date
 * @param rentals A pointer to the list of rentals
 * @param newRental A pointer to the new rental to insert
 * @return A pointer to the updated list of rentals
 */
Rental* InsertRentalOrdered(Rental* rentals, Rental* newRental);

/**
 * @brief Check if a rental with the given ID exists in the list
 * @param rentals List of rentals
 * @param rentalID Rental ID to search
 * @return bool True if the rental exists, false otherwise
 */
bool RentalExists(Rental* rentals, int rentalID);

/**
 * @brief Remove a rental from the list
 * @param rentals A pointer to the list of rentals
 * @param rentalID The ID of the rental to remove
 * @return A pointer to the updated list of rentals
 */
Rental* RemoveRental(Rental* rentals, int rentalID);

/**
 * @brief Search a rental by rental ID
 * @param rentals A pointer to the list of rentals
 * @param rentalID The ID of the rental to search for
 * @return A pointer to the found rental, or NULL if not found
 */
Rental* SearchRental(Rental* rentals, int rentalID);

/**
 * @brief Free rentals list from memory
 * @param rentals A pointer to the pointer to the list of rentals
 * @return True if successful, false otherwise
 */
bool DestroyRentalsList(Rental** rentals);

/**
 * @brief Save rentals list to a .bin file
 * @param fileName The name of the .bin file to save to
 * @param rentals A pointer to the list of rentals
 * @return True if successful, false otherwise
 */
bool SaveRentalsToBin(char* fileName, Rental* rentals);

/**
 * @brief Read rentals from a .bin file into a list
 * @param fileName The name of the .bin file to read from
 * @return A pointer to the list of rentals read from the file, or NULL if unsuccessful
 */
Rental* ReadRentalsFromBin(char* fileName);

/**
 * @brief Print data from a rental
 * @param rental A pointer to the rental to show
 */
void ShowRental(Rental* rental);

/**
 * @brief Show the list of rentals in memory
 * @param rentals A pointer to the list of rentals
 */
void ShowRentalsList(Rental* rentals);

#pragma endregion
