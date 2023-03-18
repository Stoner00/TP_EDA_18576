/**
 * @file client.h
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Header file containing the structure and function declarations for clients
 */


// Disable security warnings
#pragma once
#pragma warning (disable: 4996)

// Import Libraries
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Configure char size
#define nameSyze 60
#define locationSize 40

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//					STRUCT DECLARATION 						    //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region ClientStruct

/**
 * @brief Client structure
 */
typedef struct Client {
    int vat;
    char name[nameSyze];
    char location[locationSize];
    float balance;
    struct Client* next;
} Client;

#pragma endregion


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//                    FUNCTIONS DECLARATION						//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region ClientFunctions

/**
 * @brief Create a new Client
 * @param vat The VAT number of the client
 * @param name The name of the client
 * @param location The location of the client
 * @param balance The balance of the client
 * @return A pointer to the new client
 */
Client* CreateClient(int vat, char name[], char location[], float balance);

/**
 * @brief Insert a client into the list in an ordered manner by name
 * @param clients A pointer to the list of clients
 * @param newClient A pointer to the new client to insert
 * @return A pointer to the updated list of clients
 */
Client* InsertClientOrdered(Client* clients, Client* newClient);

/**
 * @brief Modify the name of a client
 * @param clients A pointer to the list of clients
 * @param vat The VAT number of the client to modify
 * @param newName The new name for the client
 * @return A pointer to the updated list of clients
 */
Client* ModifyClientName(Client* clients, int vat, char* newName);

/**
 * @brief Read clients from a .bin file into a list
 * @param fileName The name of the .bin file to read from
 * @return A pointer to the list of clients read from the file, or NULL if unsuccessful
 */
Client* ReadClientFromBin(char* fileName);

/**
 * @brief Remove a client from the list
 * @param clients A pointer to the list of clients
 * @param vat The VAT number of the client to remove
 * @return A pointer to the updated list of clients
 */
Client* RemoveClient(Client* clients, int vat);

/**
 * @brief Search a client by VAT number
 * @param clients A pointer to the list of clients
 * @param vat The VAT number of the client to search for
 * @return A pointer to the found client, or NULL if not found
 */
Client* SearchClient(Client* clients, int vat);

/**
 * @brief Check if a client with a given VAT number exists in the list
 * @param clients A pointer to the list of clients
 * @param vat The VAT number to search for
 * @return True if the client exists, false otherwise
 */
bool ClientExists(Client* clients, int vat);

/**
 * @brief Free clients list from memory
 * @param clients A pointer to the pointer to the list of clients
 * @return True if successful, false otherwise
 */
bool DestroyClientsList(Client** clients);

/**
 * @brief Save clients list to a .bin file
 * @param fileName The name of the .bin file to save to
 * @param clients A pointer to the list of clients
 * @return True if successful, false otherwise
 */
bool SaveClientToBin(char* fileName, Client* clients);

/**
 * @brief Print data from a client
 * @param client A pointer to the client to show
 */
void ShowClient(Client* client);

/**
 * @brief Show the list of clients in memory
 * @param clients A pointer to the list of clients
 */
void ShowClientsList(Client* clients);

#pragma endregion

