/**
 * @file manager.h
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Header file containing the structure and function declarations for Managers
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
#define nameSyze 60
#define locationSize 40
#define mailSize 70

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//					STRUCT DECLARATION 						    //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region ManagerStruct

/**
 * @brief Manager structure
 */
typedef  struct Manager {
    int vat;
    char name[nameSyze];
    char location[locationSize];
    char mail[mailSize];
    struct Manager* next;

} Manager;

#pragma endregion

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//                    FUNCTIONS DECLARATION						//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region ManagerFunctions

/**
 * @brief Create a new Manager
 * @param vat The VAT number of the manager
 * @param name The name of the manager
 * @param location The location of the manager
 * @param mail The email of the manager
 * @return A pointer to the new manager
 */
Manager* CreateManager(int vat, char name[], char location[], char mail[]);

/**
 * @brief Insert a manager into the list in an ordered manner by name
 * @param managers A pointer to the list of managers
 * @param newManager A pointer to the new manager to insert
 * @return A pointer to the updated list of managers
 */
Manager* InsertManagerOrdered(Manager* managers, Manager* newManager);

/**
 * @brief Modify the name of a manager
 * @param managers A pointer to the list of managers
 * @param vat The VAT number of the manager to modify
 * @param newName The new name for the manager
 * @return A pointer to the updated list of managers
 */
Manager* ModifyManagerName(Manager* managers, int vat, char newName[]);

/**
 * @brief Read managers from a .bin file into a list
 * @param fileName The name of the .bin file to read from
 * @return A pointer to the list of managers read from the file, or NULL if unsuccessful
 */
Manager* ReadManagersFromBin(char* fileName);

/**
 * @brief Remove a manager from the list
 * @param managers A pointer to the list of managers
 * @param vat The VAT number of the manager to remove
 * @return A pointer to the updated list of managers
 */
Manager* RemoveManager(Manager* managers, int vat);

/**
 * @brief Search a manager by VAT number
 * @param managers A pointer to the list of managers
 * @param vat The VAT number of the manager to search for
 * @return A pointer to the found manager, or NULL if not found
 */
Manager* SearchManager(Manager* managers, int vat);

/**
 * @brief Free managers list from memory
 * @param managers A pointer to the pointer to the list of managers
 * @return True if successful, false otherwise
 */
bool DestroyManagersList(Manager** managers);

/**
 * @brief Check if a manager with a given VAT number exists in the list
 * @param managers A pointer to the list of managers
 * @param vat The VAT number to search for
 * @return True if the manager exists, false otherwise
 */
bool ManagerExists(Manager* managers, int vat);

/**
 * @brief Save the list of managers to a binary file.
 * @param fileName The name of the binary file to save to.
 * @param managers The head of the linked list of managers.
 * @return true if the list was saved successfully, false otherwise.
 */
bool SaveManagersToBin(char* fileName, Manager* managers);

/**
 * @brief Display the information of a single manager.
 * @param manager A pointer to the manager instance to display.
 */
void ShowManager(Manager* manager);

/**
 * @brief Display the information of all managers in a linked list.
 * @param managers The head of the linked list of managers.
 */
void ShowManagersList(Manager* managers);

#pragma endregion