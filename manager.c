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

// Import Libraries
#include "manager.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//			IMPLEMENTING FUNCTIONS          					//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


/// <summary>
/// Create a new manager
/// </summary>
/// <param name="vat"></param>
/// <param name="name"></param>
/// <param name="local"></param>
/// <param name="mail"></param>
/// <returns>Manager*</returns>
Manager* CreateManager(int vat, char name[], char local[], char mail[])
{
    Manager* newManager = (Manager*)malloc(sizeof(Manager));
    newManager->vat = vat;
    strcpy(newManager->name, name);
    strcpy(newManager->local, local);
    strcpy(newManager->mail, mail);
    newManager->next = NULL;
    return newManager;
}

/// <summary>
/// Insert Manager into List
/// </summary>
/// <param name="managers"></param>
/// <param name="newManager"></param>
/// <returns>Manager*</returns>
Manager* InsertManagerOrdered(Manager* managers, Manager* newManager)
{
    if (ManagerExists(managers, newManager->vat)) return managers;

    if (managers == NULL || strcmp(newManager->name, managers->name) < 0) {
        newManager->next = managers;
        managers = newManager;
    }
    else
    {
        Manager* aux = managers->next;
        Manager* auxPrevious = managers;
        while (aux && strcmp(newManager->name, aux->name) > 0) {
            auxPrevious = aux;
            aux = aux->next;
        }
        auxPrevious->next = newManager;
        newManager->next = aux;
    }
    return managers;
}

/// <summary>
/// Validates existing of Manager by it's VAT
/// </summary>
/// <param name="managers"></param>
/// <param name="vat"></param>
/// <returns>bool</returns>
bool ManagerExists(Manager* managers, int vat)
{
    if (managers == NULL) return false;

    Manager* aux = managers;
    while (aux != NULL)
    {
        if (aux->vat == vat)
            return true;
        aux = aux->next;
    }
    return false;
}

/// <summary>
/// Show list of Managers in memory
/// </summary>
/// <param name="managers"></param>
void ShowManagersList(Manager* managers)
{
    Manager* aux = managers;
    while (aux)
    {
        ShowManager(aux);
        aux = aux->next;
    }
}

/// <summary>
/// Prints data from a Manager
/// </summary>
/// <param name="manager"></param>
void MostraManager(Manager* manager)
{
    if (manager != NULL)
    {
        printf("-------CLIENT DATA-------");
        printf("VAT: %d\n", manager->vat);
        printf("Name: %s\n", manager->name);
        printf("Local: %s\n", manager->local);
        printf("Mail: %s\n", manager->mail);
    }
}

/// <summary>
/// Modify Manager Name
/// </summary>
/// <param name="managers"></param>
/// <param name="vat"></param>
/// <param name="newName"></param>
/// <returns>Manageres</returns>
Manager* AlteraManager(Manager* managers, int vat, char* newName)
{
    Manager* aux = SearchManager(managers, vat);
    if (aux != NULL)
    {
        strcpy(aux->name, newName);
    }
    return managers;
}

/// <summary>
/// Search a Manager
/// </summary>
/// <param name="managers"></param>
/// <param name="vat"></param>
/// <returns>Manager*|Null</returns>
Manager* SearchManager(Manager* managers, int vat)
{
    if (managers == NULL) return NULL;
    else
    {
        Manager* aux = managers;
        while (aux != NULL) {
            if (aux->vat == vat) {
                return (aux);
            }
            aux = aux->next;
        }
        return NULL;
    }
}

/// <summary>
/// Remove a Manager
/// </summary>
/// <param name="managers"></param>
/// <param name="vat"></param>
/// <returns>Manager*</returns>
Manager* RemoveManager(Manager* managers, int vat)
{
    if (managers == NULL) return NULL;

    if (managers->vat == vat)
    {
        Manager* aux = managers;
        managers = managers->next;
        free(aux);
    }
    else
    {
        Manager* aux = managers;
        Manager* auxPrevious = aux;
        while (aux && aux->vat != vat) {
            auxPrevious = aux;
            aux = aux->next;
        }
        if (aux != NULL) {
            auxPrevious->next = aux->next;
            free(aux);
        }
    }
    return managers;
}

/// <summary>
/// Saving Managers List to .bin file
/// </summary>
/// <param name="fileName"></param>
/// <param name="managers"></param>
/// <returns>bool</returns>
bool SaveManagersToBin(char* fileName, Manager* managers)
{
    FILE* file;

    if (managers == NULL) return false;
    if ((file = fopen(fileName, "wb")) == NULL) return false;

    Manager* aux = managers;
    Manager auxManager;
    while (aux != NULL)
    {
        auxManager.vat = aux->vat;
        strcpy(auxManager.name, aux->name);
        strcpy(auxManager.local, aux->local);
        strcpy(auxManager.mail, aux->mail);
        fwrite(&auxManager, sizeof(Manager), 1, file);
        aux = aux->next;
    }
    fclose(file);
    return true;
}

/// <summary>
/// Read Managers from .bin file to List
/// </summary>
/// <param name="fileName"></param>
/// <returns>Manager*</returns>
Manager* ReadManagersFromBin(char* fileName)
{
    FILE* file;
    Manager* managers = NULL;
    Manager* aux;

    if ((file = fopen(fileName, "rb")) == NULL) return NULL;

    Manager auxManager;
    while (fread(&auxManager, sizeof(Manager), 1, file))
    {
        aux = CreateManager(auxManager.vat, auxManager.name, auxManager.local, auxManager.mail);
        managers = InsertManagerOrdered(managers, aux);
    }
    fclose(file);
    return managers;
}

/// <summary>
/// Free Clients list from memory
/// </summary>
/// <param name="managers"></param>
/// <returns>bool</returns>
bool DestroyManagersList(Manager** managers)
{
    if (managers != NULL) {
        Manager* aux;
        while (*managers) {
            aux = *managers;
            *managers = (*managers)->next;
            free(aux);
        }
        return true;
    }
    return false;
}
