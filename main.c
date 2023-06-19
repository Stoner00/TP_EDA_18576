#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "vehicle.h"
#include "manager.h"
#include "rental.h"
#include "city.h"
#include "graph.h"

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
//    printf("\n.....Modifying Bruno Fernandes's name to Bruno Borges.....\n");
//    clients = ModifyClientName(clients, 123456789, "Bruno Borges");
//    ShowClientsList(clients);

    //Save clients to file
//    printf("\n.....Saving clients to clients.bin.....\n");
//    if (SaveClientToBin("clients.bin", clients)) {
//        printf("Clients saved successfully.\n");
//    } else {
//        printf("Failed to save clients.\n");
//    }

    //Read clients from file
//    printf("\n.....Reading clients from clients.bin.....\n");
//    DestroyClientsList(&clients);
//    clients = ReadClientFromBin("clients.bin");
//    if (clients) {
//        printf("Clients read successfully.\n");
//        ShowClientsList(clients);
//    } else {
//        printf("Failed to read clients.\n");
//    }

    //Remove client
//    printf("\n.....Removing Bruno Borges from clients list.....\n");
//    clients = RemoveClient(clients, 123456789);
//    ShowClientsList(clients);

    // Clean up
//    DestroyClientsList(&clients);


#pragma endregion

#pragma region TestManagers
//    Manager* managers = NULL;
//    Manager* managerA;
//    Manager* managerB;

    //Create manager and insert into the list
//    managerA = CreateManager(123456789, "Bob Construtor", "PRT", "bob.construtor@ipca.pt");
//    managers = InsertManagerOrdered(managers, managerA);
//
//    managerB = CreateManager(987654321, "Jack Sparrow", "LA", "jack.sparrow@pirates.com");
//    managers = InsertManagerOrdered(managers, managerB);

    //Show managers list
//    printf("Managers List:\n");
//    ShowManagersList(managers);

    //Modify manager's name
//    printf("\n.....Modifying Bob Contstrutor's name to Noddy.....\n");
//    managers = ModifyManagerName(managers, 123456789, "Noddy");
//    ShowManagersList(managers);

    //Save managers to file
//    printf("\n.....Saving managers to managers.bin.....\n");
//    if (SaveManagersToBin("managers.bin", managers)) {
//        printf("Managers saved successfully.\n");
//    } else {
//        printf("Failed to save managers.\n");
//    }

    //Read managers from file
//    printf("\n.....Reading managers from managers.bin.....\n");
//    DestroyManagersList(&managers);
//    managers = ReadManagersFromBin("managers.bin");
//    if (managers) {
//        printf("Managers read successfully.\n");
//        ShowManagersList(managers);
//    } else {
//        printf("Failed to read managers.\n");
//    }

    //Remove manager
//    printf("\n.....Removing Noddy from managers list.....\n");
//    managers = RemoveManager(managers, 123456789);
//    ShowManagersList(managers);

    // Clean up
//    DestroyManagersList(&managers);
#pragma endregion

#pragma region TestVehicles
    Vehicle *vehicles = NULL;

    // Adding vehicles
    Vehicle *v1 = CreateVehicle(1, "Bike", "PRT", 100, 2.0);
    Vehicle *v2 = CreateVehicle(2, "Bike", "BRG", 40, 3.0);
    Vehicle *v3 = CreateVehicle(3, "Scooter", "PRT", 70, 8.0);
    Vehicle *v4 = CreateVehicle(4, "Scooter", "BCL", 90, 4.0);
    Vehicle *v5 = CreateVehicle(5, "Bike", "FML", 85, 2.5);
    Vehicle *v6 = CreateVehicle(6, "Bike", "VDC", 90, 3.5);
    Vehicle *v7 = CreateVehicle(7, "Scooter", "GMR", 80, 7.5);
    Vehicle *v8 = CreateVehicle(8, "Scooter", "BCL", 75, 4.5);
    Vehicle *v9 = CreateVehicle(9, "Scooter", "VDC", 60, 5.0);
    Vehicle *v10 = CreateVehicle(10, "Bike", "GMR", 95, 2.0);

    vehicles = InsertVehicleOrdered(vehicles, v1);
    vehicles = InsertVehicleOrdered(vehicles, v2);
    vehicles = InsertVehicleOrdered(vehicles, v3);
    vehicles = InsertVehicleOrdered(vehicles, v4);
    vehicles = InsertVehicleOrdered(vehicles, v5);
    vehicles = InsertVehicleOrdered(vehicles, v6);
    vehicles = InsertVehicleOrdered(vehicles, v7);
    vehicles = InsertVehicleOrdered(vehicles, v8);
    vehicles = InsertVehicleOrdered(vehicles, v9);
    vehicles = InsertVehicleOrdered(vehicles, v10);

    printf(".....Vehicles list.....\n");
    ShowVehiclesList(vehicles);

    // Modify vehicle battery
//    printf("\n.....Updating vehicle 2 battery.....\n");
//    vehicles = ModifyVehicleBattery(vehicles, 2, 95);
//    ShowVehiclesList(vehicles);

    // Remove a vehicle
//    printf("\n.....Removing vehicle 3.....\n");
//    vehicles = RemoveVehicle(vehicles, 3);
//    ShowVehiclesList(vehicles);

    // Rent a vehicle
//    printf("\n.....Renting vehicle 1.....\n");
//    RentVehicle(vehicles, 1);
//    ShowVehiclesList(vehicles);

    // Unlease a vehicle
//    printf("\n.....Unlease vehicle 1.....\n");
//    UnrentVehicle(vehicles, 1);
//    ShowVehiclesList(vehicles);

    // Show vehicles by location
//    printf("\n.....Vehicles in Oporto.....\n");
//    ShowVehiclesByLocation(vehicles, "PRT");

    // Save vehicles to binary file
//    SaveVehiclesToBin("vehicles.bin", vehicles);

    // Destroy vehicle list
//    DestroyVehiclesList(&vehicles);

    // Read vehicles from binary file
//    printf("\n.....Reading Vehicles from binary file.....\n");
//    Vehicle *vehiclesFromFile = ReadVehiclesFromBin("vehicles.bin");
//    ShowVehiclesList(vehiclesFromFile);

    // Read vehicles from binary file sorted by battery descending
//    printf("\n=== Reading Vehicles from binary file sorted by battery descending ===\n");
//    Vehicle *vehiclesByBattery = ReadVehicleFromBinSortedByBatteryDesc("vehicles.bin");
//    ShowVehiclesList(vehiclesByBattery);

    // Destroy both vehicle lists
//    DestroyVehiclesList(&vehiclesFromFile);
//    DestroyVehiclesList(&vehiclesByBattery);

#pragma endregion

#pragma region TestRentals
    Rental *rentals = NULL;

    // Adding rentals
    Rental *r1 = CreateRental(
            1,
            2,
            123456789,
            5.0,
            GetVehicleById(vehicles, 2),
            SearchClient(clients, 123456789)
            );

    Rental *r2 = CreateRental(
            2,
            1,
            987654321,
            7.0,
            GetVehicleById(vehicles, 1),
            SearchClient(clients, 987654321)
            );

    rentals = InsertRentalOrdered(rentals, r1);
    rentals = InsertRentalOrdered(rentals, r2);

    printf(".....Rentals list.....\n");
    ShowRentalsList(rentals);

    // Save rentals to binary file
    printf("\n.....Saving rentals to rentals.bin.....\n");
    if (SaveRentalsToBin("rentals.bin", rentals)) {
        printf("Rentals saved successfully.\n");
    } else {
        printf("Failed to save rentals.\n");
    }

    // Destroy rental list
    DestroyRentalsList(&rentals);

    // Read rentals from binary file
    printf("\n.....Reading Rentals from binary file.....\n");
    Rental *rentalsFromFile = ReadRentalsFromBin("rentals.bin");
    if (rentalsFromFile) {
        printf("Rentals read successfully.\n");
        ShowRentalsList(rentalsFromFile);
    } else {
        printf("Failed to read rentals.\n");
    }

    // Remove a rental
    printf("\n.....Removing rental 1.....\n");
    rentalsFromFile = RemoveRental(rentalsFromFile, 1);
    ShowRentalsList(rentalsFromFile);

    // Destroy rental list
    DestroyRentalsList(&rentalsFromFile);

#pragma endregion

#pragma region TestCities
    City* cities = NULL;
    EdgeNode* edges = NULL;
    int cityCount = 0;


    // Create cities
    cities = InsertCityOrdered(cities, CreateCity(0, "GMR", "Guimaraes"));
    cities = InsertCityOrdered(cities, CreateCity(1, "BRG", "Braga"));
    cities = InsertCityOrdered(cities, CreateCity(2, "BCL", "Barcelos"));
    cities = InsertCityOrdered(cities, CreateCity(3, "FML", "Famalicao"));
    cities = InsertCityOrdered(cities, CreateCity(4, "PRT", "Porto"));
    cities = InsertCityOrdered(cities, CreateCity(5, "VDC", "Viana do Castelo"));
    cityCount = 6;
    // Show cities
    ShowCities(cities);
    printf("\n__________________END SHOW CITIES___________________\n");


    Graph* graph = CreateGraph(cityCount);

    // Add edges to the graph
    AddEdge(graph, GetCity(cities, "GMR"), GetCity(cities, "BRG"), 24);
    AddEdge(graph, GetCity(cities, "BRG"), GetCity(cities, "BCL"), 21);
    AddEdge(graph, GetCity(cities, "BRG"), GetCity(cities, "FML"), 25);
    AddEdge(graph, GetCity(cities, "GMR"), GetCity(cities, "FML"), 23);
    AddEdge(graph, GetCity(cities, "FML"), GetCity(cities, "PRT"), 33);
    AddEdge(graph, GetCity(cities, "BRG"), GetCity(cities, "VDC"), 47);
    AddEdge(graph, GetCity(cities, "BCL"), GetCity(cities, "VDC"), 36);
    AddEdge(graph, GetCity(cities, "GMR"), GetCity(cities, "BCL"), 40);
    AddEdge(graph, GetCity(cities, "GMR"), GetCity(cities, "PRT"), 60);
    AddEdge(graph, GetCity(cities, "GMR"), GetCity(cities, "VDC"), 65);
    AddEdge(graph, GetCity(cities, "BRG"), GetCity(cities, "PRT"), 58);
    AddEdge(graph, GetCity(cities, "BCL"), GetCity(cities, "FML"), 30);
    AddEdge(graph, GetCity(cities, "BCL"), GetCity(cities, "PRT"), 40);
    AddEdge(graph, GetCity(cities, "FML"), GetCity(cities, "VDC"), 42);
    AddEdge(graph, GetCity(cities, "PRT"), GetCity(cities, "VDC"), 52);


    // Create edges
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(20, GetCity(cities, "GMR"), GetCity(cities, "BRG")));
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(20, GetCity(cities, "BRG"), GetCity(cities, "GMR")));
//
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(35, GetCity(cities, "GMR"), GetCity(cities, "FML")));
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(35, GetCity(cities, "FML"), GetCity(cities, "GMR")));
//
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(40, GetCity(cities, "BRG"), GetCity(cities, "VDC")));
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(40, GetCity(cities, "VDC"), GetCity(cities, "BRG")));
//
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(20, GetCity(cities, "BRG"), GetCity(cities, "BCL")));
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(20, GetCity(cities, "BCL"), GetCity(cities, "BRG")));
//
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(18, GetCity(cities, "BRG"), GetCity(cities, "FML")));
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(18, GetCity(cities, "FML"), GetCity(cities, "BRG")));
//
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(30, GetCity(cities, "BCL"), GetCity(cities, "VDC")));
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(30, GetCity(cities, "VDC"), GetCity(cities, "BCL")));
//
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(30, GetCity(cities, "BCL"), GetCity(cities, "PRT")));
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(30, GetCity(cities, "PRT"), GetCity(cities, "BCL")));
//
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(20, GetCity(cities, "FML"), GetCity(cities, "PRT")));
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(20, GetCity(cities, "PRT"), GetCity(cities, "FML")));
//
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(25, GetCity(cities, "BCL"), GetCity(cities, "FML")));
//    edges = InsertEdgeNodeOrdered(edges, CreateEdgeNode(25, GetCity(cities, "FML"), GetCity(cities, "BCL")));


    // Show edges for each city
    ShowAllCityInfo(cities, graph, vehicles);

    printf("\n__________________END SHOW ALL CITY INFO___________________\n");
//    City** nearbyCities = GetNearbyCities(cities, edges, "GMR", 40);
//    ShowNearbyVehicles(vehicles, nearbyCities);

    printf("\n__________________START SHOW NEARBY VEHICLES___________________\n");

    ShowNearbyVehiclesFromGraph(cities, graph, vehicles, "BRG", 50);

    printf("\n___________________END SHOW NEARBY VEHICLES___________________\n");

    printf("\n___________________START SHORTEST PATH___________________\n");
    NearestNeighbor(graph, GetCity(cities, "BRG")->id);

    printf("\n___________________END SHORTEST PATH___________________\n");




#pragma endregion

    return 0;
}
