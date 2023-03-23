/**
 * @file client.c
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Client functions implementation from client.h
 */

// Import Libraries
#include "client.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//			IMPLEMENTING FUNCTIONS          					//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

Client* CreateClient(int vat, char name[], char location[], float balance)
{
    Client* newClient = (Client*)malloc(sizeof(Client));
    newClient->vat = vat;
    strcpy(newClient->name, name);
    strcpy(newClient->location, location);
    newClient->balance = balance;
    newClient->next = NULL;
    return newClient;
}

Client* InsertClientOrdered(Client* clients, Client* newClient)
{
    if (ClientExists(clients, newClient->vat)) return clients;

    if (clients == NULL || strcmp(newClient->name, clients->name) < 0) {
        newClient->next = clients;
        clients = newClient; //Insere no in�cio
    }
    else
    {
        Client* aux = clients->next;
        Client* auxAnt = clients;
        while (aux && strcmp(newClient->name, aux->name) > 0) {
            auxAnt = aux;
            aux = aux->next;
        }
        auxAnt->next = newClient; //Insere no meio ou fim
        newClient->next = aux;
    }
    return clients;
}

bool ClientExists(Client* clients, int vat)
{
    if (clients == NULL) return false;

    Client* aux = clients;
    while (aux != NULL)
    {
        if (aux->vat == vat)
            return true;
        aux = aux->next;
    }
    return false;
}

void ShowClientsList(Client* clients)
{
    Client* aux = clients;
    while (aux)
    {
        ShowClient(aux);
        aux = aux->next;
    }
}

void ShowClient(Client* client)
{
    if (client != NULL)
    {
        printf("-------CLIENT DATA-------\n");
        printf("VAT: %d\n", client->vat);
        printf("Name: %s\n", client->name);
        printf("location: %s\n", client->location);
        printf("Balance: %.2f\n", client->balance);
    }
}

Client* ModifyClientName(Client* clients, int vat, char* newName) {
    Client* aux = SearchClient(clients, vat);
    if (aux != NULL)
    {
        strcpy(aux->name, newName);
    }
    return clients;
}

Client* SearchClient(Client* clients, int vat)
{
    if (clients == NULL) return NULL;
    else
    {
        Client* aux = clients;
        while (aux != NULL) {
            if (aux->vat == vat) {
                return (aux);
            }
            aux = aux->next;
        }
        return NULL;
    }
}

Client* RemoveClient(Client* clients, int vat)
{
    if (clients == NULL) return NULL;

    if (clients->vat == vat)
    {
        Client* aux = clients;
        clients = clients->next;
        free(aux);
    }
    else
    {
        Client* aux = clients;
        Client* auxPrevious = aux;
        while (aux && aux->vat != vat) {
            auxPrevious = aux;
            aux = aux->next;
        }
        if (aux != NULL) {
            auxPrevious->next = aux->next;
            free(aux);
        }
    }
    return clients;
}

bool SaveClientToBin(char* fileName, Client* clients)
{
    FILE* file;

    if (clients == NULL) return false;
    if ((file = fopen(fileName, "wb")) == NULL) return false;

    Client* aux = clients;
    Client auxClient;
    while (aux !=NULL)
    {
        auxClient.vat = aux->vat;
        strcpy(auxClient.name, aux->name);
        strcpy(auxClient.location, aux->location);
        auxClient.balance = aux->balance;
        fwrite(&auxClient, sizeof(Client), 1, file);
        aux = aux->next;
    }
    fclose(file);
    return true;
}

Client* ReadClientFromBin(char* fileName)
{
    FILE* file;
    Client* clients = NULL;
    Client* aux;

    if ((file = fopen(fileName, "rb")) == NULL) return NULL;

    Client auxClient;
    while (fread(&auxClient, sizeof(Client), 1, file))
    {
        aux = CreateClient(auxClient.vat, auxClient.name, auxClient.location, auxClient.balance);
        clients = InsertClientOrdered(clients, aux);
    }
    fclose(file);
    return clients;
}

bool DestroyClientsList(Client** clients)
{
    if (clients != NULL)
    {
        Client* aux;
        while (*clients)
        {
            aux = *clients;
            *clients = (*clients)->next;
            free(aux);
        }
        return true;
    }
    return false;
}