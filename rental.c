/**
 * @file rental.c
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Vehicle Functions File
 */

#include "rental.h"
#include <time.h>

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//			IMPLEMENTING FUNCTIONS          					//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

Rental* CreateRental(
        int rentalID,
        int vehicleID,
        int clientVAT,
        float totalKilometers,
        Vehicle* vehicle,
        Client* client
        ) {

    if (vehicle == NULL || client == NULL) {
        return NULL;
    }

    float totalCost = totalKilometers * vehicle->cost;
    if (client->balance < totalCost) {
        return NULL;
    }

    client->balance -= totalCost;

    Rental *newRental = (Rental *)malloc(sizeof(Rental));

    if (newRental == NULL) {
        return NULL;
    }

    newRental->rentalID = rentalID;
    newRental->vehicleID = vehicleID;
    newRental->clientID = clientVAT;
    newRental->totalKilometers = totalKilometers;
    newRental->totalCost = totalCost;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(newRental->date, "%d-%d-%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    newRental->next = NULL;

    return newRental;
}

Rental* InsertRentalOrdered(Rental* rentals, Rental* newRental) {
    if (RentalExists(rentals, newRental->rentalID)) return rentals;

    if (rentals == NULL) {
        rentals = newRental;
    }
    else
    {
        Rental* aux = rentals;
        Rental* auxPrevious = NULL;
        while (aux && aux->rentalID < newRental->rentalID) {
            auxPrevious = aux;
            aux = aux->next;
        }
        if (auxPrevious == NULL) {
            newRental->next = rentals;
            rentals = newRental;
        }
        else
        {
            auxPrevious->next = newRental;
            newRental->next = aux;
        }
    }
    return rentals;
}

bool RentalExists(Rental* rentals, int id)
{
    if (rentals == NULL) return false;

    Rental* aux = rentals;
    while (aux != NULL)
    {
        if (aux->rentalID == id)
            return true;
        aux = aux->next;
    }
    return false;
}

Rental* RemoveRental(Rental* rentals, int rentalID)
{
    if (rentals == NULL) return NULL;

    if (rentals->rentalID == rentalID)
    {
        Rental* aux = rentals;
        rentals = rentals->next;
        free(aux);
    }
    else
    {
        Rental* aux = rentals;
        Rental* auxPrevious = aux;
        while (aux && aux->rentalID != rentalID) {
            auxPrevious = aux;
            aux = aux->next;
        }
        if (aux != NULL) {
            auxPrevious->next = aux->next;
            free(aux);
        }
    }
    return rentals;
}

Rental* SearchRental(Rental* rentals, int rentalID) {
    Rental *current = rentals;

    while(current != NULL) {
        if(current->rentalID == rentalID) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

bool DestroyRentalsList(Rental** rentals) {
    Rental *current = *rentals;
    Rental *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *rentals = NULL;
    return true;
}

bool SaveRentalsToBin(char* fileName, Rental* rentals)
{
    FILE* file;

    if (rentals == NULL) return false;
    if ((file = fopen(fileName, "wb")) == NULL) return false;

    Rental* aux = rentals;
    Rental auxRental;
    while (aux != NULL)
    {
        auxRental.rentalID = aux->rentalID;
        auxRental.vehicleID = aux->vehicleID;
        auxRental.clientID = aux->clientID;
        auxRental.totalKilometers = aux->totalKilometers;
        auxRental.totalCost = aux->totalCost;
        strcpy(auxRental.date, aux->date);
        fwrite(&auxRental, sizeof(Rental), 1, file);
        aux = aux->next;
    }
    fclose(file);
    return true;
}

Rental* ReadRentalsFromBin(char* fileName)
{
    FILE* file;
    Rental* rentals = NULL;
    Rental* aux;

    if ((file = fopen(fileName, "rb")) == NULL) return NULL;
    Rental auxRental;

    while (fread(&auxRental, sizeof(Rental), 1, file))
    {
        aux = (Rental *)malloc(sizeof(Rental));
        if (aux == NULL) {
            return NULL;
        }

        aux->rentalID = auxRental.rentalID;
        aux->vehicleID = auxRental.vehicleID;
        aux->clientID = auxRental.clientID;
        aux->totalKilometers = auxRental.totalKilometers;
        aux->totalCost = auxRental.totalCost;
        strcpy(aux->date, auxRental.date);
        aux->next = NULL;

        rentals = InsertRentalOrdered(rentals, aux);
    }
    fclose(file);
    return rentals;
}

void ShowRental(Rental* rental) {
    if (rental == NULL) {
        printf("No rental to show.\n");
        return;
    }

    printf("Rental ID: %d\n", rental->rentalID);
    printf("Vehicle ID: %d\n", rental->vehicleID);
    printf("Client ID: %d\n", rental->clientID);
    printf("Total Kilometers: %f\n", rental->totalKilometers);
    printf("Date: %s\n", rental->date);
}

void ShowRentalsList(Rental* rentals) {
    Rental *current = rentals;

    while(current != NULL) {
        ShowRental(current);
        current = current->next;
    }
}