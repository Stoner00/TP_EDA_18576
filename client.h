//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//           INSTITUTO POLITECNICO DO CAVADO E DO AVE			//
//                          2022/2023							//
//             ENGENHARIA DE SISTEMAS INFORMATICOS				//
//                 ESTRUTURA DADOS AVANCADAS					//
//																//
//         [  Bruno Fernandes - a18576@alunos.ipca.pt  ]		//
//                                                              //
//       Client Header File: Functions and structs for client   //
//                                                              //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

// Disable security warnings
#pragma once
#pragma warning (disable: 4996)

// Import Libraries
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//					STRUCT DECLARATION 						    //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

// Configure char size
#define nameSyze 60
#define localSize 40

#pragma region ClientStruct
typedef struct Client {
    int vat;                                // Unique identifier for Client
    char name[nameSyze];                 // Client name
    char local[localSize];         // Client Address
    float balance;                            // Client Balance
    struct Client* next;                   // Next Client Pointer
} Client;
#pragma endregion


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//                    FUNCTIONS DECLARATION						//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region ClientFunctions
Client* CreateClient(int vat, char name[], char local[], float balance);
Client* InsertClientOrdered(Client* clients, Client* newClient);
bool ClientExists(Client* clients, int vat);
void ShowClientsList(Client* clients);
void ShowClient(Client* client);
Client* ModifyClientName(Client* clients, int vat, char* newName);
Client* SearchClient(Client* clients, int vat);
Client* RemoveClient(Client* clients, int vat);
bool SaveClientToBin(char* fileName, Client* clients);
Client* ReadClientFromBin(char* fileName);
bool DestroyClientsList(Client** clients);
#pragma endregion

