/**
 * @file vehicle.c
 * @author Bruno Fernandes - a18576@alunos.ipca.pt
 * @brief Vehicle Functions File
 * @date 2023-03-18
 */

#include "vehicle.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//			IMPLEMENTING FUNCTIONS          					//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

Vehicle* CreateVehicle(int id, char type[], char location[], int battery, float cost)
{
    Vehicle* newVehicle = (Vehicle*)malloc(sizeof(Vehicle));
    newVehicle->id = id;
    strcpy(newVehicle->type, type);
    newVehicle->battery = battery;
    newVehicle->cost = cost;
    strcpy(newVehicle->location, location);
    newVehicle->rented = false;
    newVehicle->next = NULL;
    return newVehicle;
}

Vehicle* InsertVehicleOrdered(Vehicle* vehicles, Vehicle* newVehicle) {
    if (VehicleExists(vehicles, newVehicle->id)) return vehicles;

    if (vehicles == NULL) {
        vehicles = newVehicle;
    }
    else
    {
        Vehicle* aux = vehicles;
        Vehicle* auxPrevious = NULL;
        while (aux && aux->id < newVehicle->id) {
            auxPrevious = aux;
            aux = aux->next;
        }
        if (auxPrevious == NULL) {
            newVehicle->next = vehicles;
            vehicles = newVehicle;
        }
        else
        {
            auxPrevious->next = newVehicle;
            newVehicle->next = aux;
        }
    }
    return vehicles;
}

bool VehicleExists(Vehicle* vehicles, int id)
{
    if (vehicles == NULL) return false;

    Vehicle* aux = vehicles;
    while (aux != NULL)
    {
        if (aux->id == id)
            return true;
        aux = aux->next;
    }
    return false;
}

void ShowVehiclesList(Vehicle* vehicles)
{
    Vehicle* aux = vehicles;
    while (aux)
    {
        ShowVehicle(aux);
        aux = aux->next;
    }
}

void ShowVehicle(Vehicle* vehicle)
{
    if (vehicle != NULL)
    {
        printf("-------CLIENT DATA-------\n");
        printf("ID: %d\n", vehicle->id);
        printf("Type: %s\n", vehicle->type);
        printf("Location: %s\n", vehicle->location);
        printf("Battery: %d%%\n", vehicle->battery);
        printf("Cost: %.2fE\n", vehicle->cost);
        if (vehicle->rented)
        {
            printf("Rented\n");
        }
        else
        {
            printf("Free to rent\n");
        }

    }
}

Vehicle* ModifyVehicleBattery(Vehicle* vehicles, int id, int battery)
{
    Vehicle* aux = SearchVehicle(vehicles, id);
    if (aux != NULL)
    {
        aux->battery = battery;
    }
    return vehicles;
}

Vehicle* SearchVehicle(Vehicle* vehicles, int id)
{
    if (vehicles == NULL) return NULL;
    else
    {
        Vehicle* aux = vehicles;
        while (aux != NULL) {
            if (aux->id == id) {
                return (aux);
            }
            aux = aux->next;
        }
        return NULL;
    }
}

Vehicle* RemoveVehicle(Vehicle* vehicles, int id)
{
    if (vehicles == NULL) return NULL;

    if (vehicles->id == id)
    {
        Vehicle* aux = vehicles;
        vehicles = vehicles->next;
        free(aux);
    }
    else
    {
        Vehicle* aux = vehicles;
        Vehicle* auxPrevious = aux;
        while (aux && aux->id != id) {
            auxPrevious = aux;
            aux = aux->next;
        }
        if (aux != NULL) {
            auxPrevious->next = aux->next;
            free(aux);
        }
    }
    return vehicles;
}

bool SaveVehiclesToBin(char* fileName, Vehicle* vehicles)
{
    FILE* file;

    if (vehicles == NULL) return false;
    if ((file = fopen(fileName, "wb")) == NULL) return false;

    Vehicle* aux = vehicles;
    Vehicle auxVehicle;
    while (aux != NULL)
    {
        auxVehicle.id = aux->id;
        strcpy(auxVehicle.type, aux->type);
        auxVehicle.battery = aux->battery;
        auxVehicle.cost = aux->cost;
        strcpy(auxVehicle.location, aux->location);
        auxVehicle.rented = aux->rented;
        fwrite(&auxVehicle, sizeof(Vehicle), 1, file);
        aux = aux->next;
    }
    fclose(file);
    return true;
}

Vehicle* ReadVehicleFromBin(char* fileName)
{
    FILE* file;
    Vehicle* vehicles = NULL;
    Vehicle* aux;

    if ((file = fopen(fileName, "rb")) == NULL) return NULL;
    Vehicle auxVehicle;

    while (fread(&auxVehicle, sizeof(Vehicle), 1, file))
    {
        aux = CreateVehicle(auxVehicle.id, auxVehicle.type, auxVehicle.location, auxVehicle.battery, auxVehicle.cost);
        vehicles = InsertVehicleOrdered(vehicles, aux);
    }
    fclose(file);
    return vehicles;
}

bool DestroyVehiclesList(Vehicle** vehicles)
{
    if (vehicles != NULL) {
        Vehicle* aux;
        while (*vehicles) {
            aux = *vehicles;
            *vehicles = (*vehicles)->next;
            free(aux);
            return true;
        }
    }
    return false;
}

Vehicle* ReadVehicleFromBinSortedByBatteryDesc(char* fileName)
{
    FILE* file;
    Vehicle* vehicles = NULL;
    Vehicle* aux;

    if ((file = fopen(fileName, "rb")) == NULL) return NULL;
    //l� registos no file
    Vehicle auxVehicle;
    while (fread(&auxVehicle, sizeof(Vehicle), 1, file)) {
        aux = CreateVehicle(auxVehicle.id, auxVehicle.type, auxVehicle.location, auxVehicle.battery, auxVehicle.cost);
        vehicles = InsertVehicleSortedByBatteryDesc(vehicles, aux);
    }
    fclose(file);
    return vehicles;
}

Vehicle* InsertVehicleSortedByBatteryDesc(Vehicle* vehicles, Vehicle* newVehicle)
{
    if (VehicleExists(vehicles, newVehicle->id)) return vehicles;

    if (vehicles == NULL) {
        vehicles = newVehicle;
    }
    else
    {
        Vehicle* aux = vehicles;
        Vehicle* auxPrevious = NULL;
        while (aux && aux->battery > newVehicle->battery) {
            auxPrevious = aux;
            aux = aux->next;
        }
        if (auxPrevious == NULL) {
            newVehicle->next = vehicles;
            vehicles = newVehicle;
        }
        else
        {
            auxPrevious->next = newVehicle;
            newVehicle->next = aux;
        }
    }
    return vehicles;
}

bool RentVehicle(Vehicle* vehicles, int id) {

    if (vehicles == NULL) return false;
    else
    {
        Vehicle* auxVehicle = vehicles;
        while (auxVehicle != NULL) {
            if (auxVehicle->id == id)
            {
                auxVehicle->rented = true;
                return (vehicles);
            }
            auxVehicle = auxVehicle->next;
        }
        return true;
    }
}

bool UnrentVehicle(Vehicle* vehicles, int id) {

    if (vehicles == NULL) return false;
    else
    {
        Vehicle* auxVehicle = vehicles;
        while (auxVehicle != NULL) {
            if (auxVehicle->id == id)
            {
                vehicles->rented = false;
                return (vehicles);
            }
            auxVehicle = auxVehicle->next;
        }
        return true;
    }
}

bool ShowVehiclesByLocation(Vehicle* vehicles, char* location)
{
    if (vehicles != NULL)
    {
        while (vehicles)
        {
            if (strcmp(vehicles->location, location) == 0)
            {
                printf("-------CLIENT DATA-------\n");
                printf("ID: %d\n", vehicles->id);
                printf("Type: %s\n", vehicles->type);
                printf("Location: %s\n", vehicles->location);
                printf("Battery: %d%%\n", vehicles->battery);
                printf("Cost: %.2fE\n", vehicles->cost);
                if (vehicles->rented)
                {
                    printf("Rented\n");
                }
                else
                {
                    printf("Free to Rent\n");
                }

            }

            vehicles = vehicles->next;
        }
        return true;
    }
    return false;
}