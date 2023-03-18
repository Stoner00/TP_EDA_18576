//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//           INSTITUTO POLITECNICO DO CAVADO E DO AVE			//
//                          2022/2023							//
//             ENGENHARIA DE SISTEMAS INFORMATICOS				//
//                 ESTRUTURA DADOS AVANCADAS					//
//																//
//         [  Bruno Fernandes - a18576@alunos.ipca.pt  ]		//
//                                                              //
//         Client Functions Implementation from client.h        //
//                                                              //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

// Import Libraries
#include "client.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//			IMPLEMENTING FUNCTIONS          					//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


/// <summary>
/// Create a new Client
/// </summary>
/// <param name="vat"></param>
/// <param name="name"></param>
/// <param name="local"></param>
/// <param name="balance"></param>
/// <returns>Client*</returns>
Client* CreateClient(int vat, char name[], char local[], float balance)
{
    Client* newClient = (Client*)malloc(sizeof(Client));
    newClient->vat = vat;
    strcpy(newClient->name, name);
    strcpy(newClient->local, local);
    newClient->balance = balance;
    newClient->next = NULL;
    return newClient;
}

/// <summary>
/// Insert Client into List
/// </summary>
/// <param name="clients"></param>
/// <param name="newClient"></param>
/// <returns>Client*</returns>
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

/// <summary>
/// Validates existing of Client by it's VAT
/// </summary>
/// <param name="clients"></param>
/// <param name="vat"></param>
/// <returns>bool</returns>
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

/// <summary>
/// Show list of Clients in memory
/// </summary>
/// <param name="clients"></param>
void ShowClientsList(Client* clients)
{
    Client* aux = clients;
    while (aux)
    {
        ShowClient(aux);
        aux = aux->next;
    }
}

/// <summary>
/// Prints data from a Client
/// </summary>
/// <param name="client"></param>
void ShowClient(Client* client)
{
    if (client != NULL)
    {
        printf("-------CLIENT DATA-------");
        printf("VAT: %d\n", client->vat);
        printf("Name: %s\n", client->name);
        printf("Local: %s\n", client->local);
        printf("Balance: %.2f €\n", client->balance);
    }
}

/// <summary>
/// Modify Client Name
/// </summary>
/// <param name="clients"></param>
/// <param name="vat"></param>
/// <param name="newName"></param>
/// <returns>Client*</returns>
Client* ModifyClientName(Client* clients, int vat, char* newName) {
    Client* aux = SearchClient(clients, vat);
    if (aux != NULL)
    {
        strcpy(aux->name, newName);
    }
    return clients;
}

/// <summary>
/// Search a Client
/// </summary>
/// <param name="clients"></param>
/// <param name="vat"></param>
/// <returns>Client*|Null</returns>
Client* ProcuraClient(Client* clients, int vat)
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

/// <summary>
/// Remove a client from the List
/// </summary>
/// <param name="clients"></param>
/// <param name="vat"></param>
/// <returns>Client*</returns>
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

/// <summary>
/// Saving Clients List to .bin file
/// </summary>
/// <param name="fileName"></param>
/// <param name="clients"></param>
/// <returns>bool</returns>
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
        strcpy(auxClient.local, aux->local);
        auxClient.balance = aux->balance;
        fwrite(&auxClient, sizeof(Client), 1, file);
        aux = aux->next;
    }
    fclose(file);
    return true;
}

/// <summary>
/// Read Clients from .bin file to List
/// </summary>
/// <param name="fileName"></param>
/// <returns>Client*</returns>
Client* ReadClientFromBin(char* fileName)
{
    FILE* file;
    Client* clients = NULL;
    Client* aux;

    if ((file = fopen(fileName, "rb")) == NULL) return NULL;

    Client auxClient;
    while (fread(&auxClient, sizeof(Client), 1, file))
    {
        aux = CreateClient(auxClient.vat, auxClient.name, auxClient.local, auxClient.balance);
        clients = InsertClientOrdered(clients, aux);
    }
    fclose(file);
    return clients;
}

/// <summary>
/// Free Clients list from memory
/// </summary>
/// <param name="clients"></param>
/// <returns>bool</returns>
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