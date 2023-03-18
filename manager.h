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

//Configure char size
#define nameSyze 60
#define localSize 40
#define mailSize 70

#pragma region ManagerStruct
typedef  struct Manager {
    int vat;
    char name[nameSyze];
    char local[localSize];
    char mail[mailSize];
    struct Manager* next;

} Manager;
#pragma endregion

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//                    FUNCTIONS DECLARATION						//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#pragma region ManagerFunctions
Manager* CreateManager(int vat, char name[], char local[], char mail[]);
Manager* InsertManagerOrdered(Manager* managers, Manager* newManager);
bool ManagerExists(Manager* managers, int vat);
void ShowManagersList(Manager* managers);
void ShowManager(Manager* manager);
Manager* ModifyManagerName(Manager* managers, int vat, char newName[]);
Manager* SearchManager(Manager* managers, int vat);
Manager* RemoveManager(Manager* managers, int vat);
bool SaveManagersToBin(char* fileName, Manager* managers);
Manager* ReadManagersFromBin(char* fileName);
bool DestroyManagersList(Manager** managers);
#pragma endregion