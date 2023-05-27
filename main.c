#include <stdio.h>
#include "client.h"
#include "manager.h"
#include "vehicle.h"

int main() {

#pragma region TestClients

    Client* clients = NULL;
    Client* clientA;
    Client* clientB;

    //Create client and insert into the list
    clientA = CreateClient(123456789, "Bruno Fernandes", "BRG", 1000.0);
    clients = InsertClientOrdered(clients, clientA);

    clientB = CreateClient(987654321, "Joao Esteves", "BCL", 500.0);
    clients = InsertClientOrdered(clients, clientB);

    //Show clients list
    printf("Clients List:\n");
    ShowClientsList(clients);

    //Modify client's name
    printf("\n.....Modifying Bruno Fernandes's name to Bruno Borges.....\n");
    clients = ModifyClientName(clients, 123456789, "Bruno Borges");
    ShowClientsList(clients);

    //Save clients to file
    printf("\n.....Saving clients to clients.bin.....\n");
    if (SaveClientToBin("clients.bin", clients)) {
        printf("Clients saved successfully.\n");
    } else {
        printf("Failed to save clients.\n");
    }

    //Read clients from file
    printf("\n.....Reading clients from clients.bin.....\n");
    DestroyClientsList(&clients);
    clients = ReadClientFromBin("clients.bin");
    if (clients) {
        printf("Clients read successfully.\n");
        ShowClientsList(clients);
    } else {
        printf("Failed to read clients.\n");
    }

    //Remove client
    printf("\n.....Removing Bruno Borges from clients list.....\n");
    clients = RemoveClient(clients, 123456789);
    ShowClientsList(clients);

    // Clean up
    if(DestroyClientsList(&clients)){
        printf("Client list erased from memory \n");
    }
    else
    {
        printf("Error cleaning memory\n");
    }


#pragma endregion

#pragma region TestManagers
    Manager* managers = NULL;
    Manager* managerA;
    Manager* managerB;

    //Create manager and insert into the list
    managerA = CreateManager(123456789, "Bob Construtor", "PRT", "bob.construtor@ipca.pt");
    managers = InsertManagerOrdered(managers, managerA);

    managerB = CreateManager(987654321, "Jack Sparrow", "LA", "jack.sparrow@pirates.com");
    managers = InsertManagerOrdered(managers, managerB);

    //Show managers list
    printf("Managers List:\n");
    ShowManagersList(managers);

    //Modify manager's name
    printf("\n.....Modifying Bob Contstrutor's name to Noddy.....\n");
    managers = ModifyManagerName(managers, 123456789, "Noddy");
    ShowManagersList(managers);

    //Save managers to file
    printf("\n.....Saving managers to managers.bin.....\n");
    if (SaveManagersToBin("managers.bin", managers)) {
        printf("Managers saved successfully.\n");
    } else {
        printf("Failed to save managers.\n");
    }

    //Read managers from file
    printf("\n.....Reading managers from managers.bin.....\n");
    DestroyManagersList(&managers);
    managers = ReadManagersFromBin("managers.bin");
    if (managers) {
        printf("Managers read successfully.\n");
        ShowManagersList(managers);
    } else {
        printf("Failed to read managers.\n");
    }

    //Remove manager
    printf("\n.....Removing Noddy from managers list.....\n");
    managers = RemoveManager(managers, 123456789);
    ShowManagersList(managers);

    // Clean up
    DestroyManagersList(&managers);
#pragma endregion

#pragma region TestVehicles
    Vehicle *vehicles = NULL;

    // Adding vehicles
    Vehicle *v1 = CreateVehicle(1, "Bike", "PRT", 100, 20.0);
    Vehicle *v2 = CreateVehicle(2, "Bike", "BRG", 80, 10.0);
    Vehicle *v3 = CreateVehicle(3, "Scooter", "PRT", 70, 8.0);
    Vehicle *v4 = CreateVehicle(4, "Scooter", "BCL", 90, 22.0);

    vehicles = InsertVehicleOrdered(vehicles, v1);
    vehicles = InsertVehicleOrdered(vehicles, v2);
    vehicles = InsertVehicleOrdered(vehicles, v3);
    vehicles = InsertVehicleOrdered(vehicles, v4);

    printf(".....Vehicles list.....\n");
    ShowVehiclesList(vehicles);

    // Modify vehicle battery
    printf("\n.....Updating vehicle 2 battery.....\n");
    vehicles = ModifyVehicleBattery(vehicles, 2, 95);
    ShowVehiclesList(vehicles);

    // Remove a vehicle
    printf("\n.....Removing vehicle 3.....\n");
    vehicles = RemoveVehicle(vehicles, 3);
    ShowVehiclesList(vehicles);

    // Rent a vehicle
    printf("\n.....Renting vehicle 1.....\n");
    RentVehicle(vehicles, 1);
    ShowVehiclesList(vehicles);

    // Unlease a vehicle
    printf("\n.....Unlease vehicle 1.....\n");
    UnleaseVehicle(vehicles, 1);
    ShowVehiclesList(vehicles);

    // Show vehicles by location
    printf("\n.....Vehicles in Oporto.....\n");
    ShowVehiclesByLocation(vehicles, "PRT");

    // Save vehicles to binary file
    SaveVehiclesToBin("vehicles.bin", vehicles);

    // Destroy vehicle list
    DestroyVehiclesList(&vehicles);

    // Read vehicles from binary file
    printf("\n.....Reading Vehicles from binary file.....\n");
    Vehicle *vehiclesFromFile = ReadVehiclesFromBin("vehicles.bin");
    ShowVehiclesList(vehiclesFromFile);

    // Read vehicles from binary file sorted by battery descending
    printf("\n=== Reading Vehicles from binary file sorted by battery descending ===\n");
    Vehicle *vehiclesByBattery = ReadVehiclesFromBinSortedByBatteryDesc("vehicles.bin");
    ShowVehiclesList(vehiclesByBattery);

    // Destroy both vehicle lists
    DestroyVehiclesList(&vehiclesFromFile);
    DestroyVehiclesList(&vehiclesByBattery);

#pragma endregion

    return 0;
}
