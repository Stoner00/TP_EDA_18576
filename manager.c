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

Manager* CreateManager(int vat, char name[], char location[], char mail[])
{
    Manager* newManager = (Manager*)malloc(sizeof(Manager));
    newManager->vat = vat;
    strcpy(newManager->name, name);
    strcpy(newManager->location, location);
    strcpy(newManager->mail, mail);
    newManager->next = NULL;
    return newManager;
}

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

void ShowManagersList(Manager* managers)
{
    Manager* aux = managers;
    while (aux)
    {
        ShowManager(aux);
        aux = aux->next;
    }
}

void ShowManager(Manager* manager)
{
    if (manager != NULL)
    {
        printf("-------MANAGER DATA-------\n");
        printf("VAT: %d\n", manager->vat);
        printf("Name: %s\n", manager->name);
        printf("Location: %s\n", manager->location);
        printf("Mail: %s\n", manager->mail);
    }
}

Manager* ModifyManagerName(Manager* managers, int vat, char* newName)
{
    Manager* aux = SearchManager(managers, vat);
    if (aux != NULL)
    {
        strcpy(aux->name, newName);
    }
    return managers;
}

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
        strcpy(auxManager.location, aux->location);
        strcpy(auxManager.mail, aux->mail);
        fwrite(&auxManager, sizeof(Manager), 1, file);
        aux = aux->next;
    }
    fclose(file);
    return true;
}

Manager* ReadManagersFromBin(char* fileName)
{
    FILE* file;
    Manager* managers = NULL;
    Manager* aux;

    if ((file = fopen(fileName, "rb")) == NULL) return NULL;

    Manager auxManager;
    while (fread(&auxManager, sizeof(Manager), 1, file))
    {
        aux = CreateManager(auxManager.vat, auxManager.name, auxManager.location, auxManager.mail);
        managers = InsertManagerOrdered(managers, aux);
    }
    fclose(file);
    return managers;
}

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
