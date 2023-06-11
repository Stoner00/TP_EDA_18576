#include <stdio.h>
#include "client.h"
#include "manager.h"
#include "vehicle.h"
#include "graph.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

#pragma region Client Data

    //Create Clients
    Client* c1 = CreateClient(123456789, "Carlos", "Braga", 14);
    Client* c2 = CreateClient(112233445, "Hugo", "Barcelos", 30);
    Client* c3 = CreateClient(111111111, "Felizberto", "Porto", 8);
    Client* c4 = CreateClient(233223322, "Bruno", "Guimarães", 100);
    Client* c5 = CreateClient(123456788, "Ribeiro", "Braga", 24);


    //Insert Clients Ordered by NIF
    Client* clientsOrdered = NULL;
    clientsOrdered = InsertClientOrdered(clientsOrdered, c1);
    clientsOrdered = InsertClientOrdered(clientsOrdered, c2);
    clientsOrdered = InsertClientOrdered(clientsOrdered, c3);
    clientsOrdered = InsertClientOrdered(clientsOrdered, c4);
    clientsOrdered = InsertClientOrdered(clientsOrdered, c5);


    //Modify a Cliente
    clientsOrdered = ModifyClientName(clientsOrdered, 123456789, "New Name");

    //Show Clients List
    ShowClientsList(clientsOrdered);

    //Delete Client
    clientsOrdered = RemoveClient(clientsOrdered, 111111111);
    ShowClientsList(clientsOrdered);

#pragma endregion

#pragma region Insercao e Manipulacao de dados de Gestor

    /// <summary>
    /// Insercao e manipulacao de dados de Gestores
    /// Validação de funcionalidade de funções
    /// </summary>
    /// <param name="h"></param>

    //// Cria Gestores
    //Gestor* g1 = CriaGestor(777777777, "Alberto", "Braga", "alberto@ipca.pt");
    //Gestor* g2 = CriaGestor(333333333, "Barbosa", "Barcelos", "barbosa@mail.pt");

    //// Insere Gestores Ordenados pelo nome - Valida se o NIF Existente
    //Gestor* listaOrdenadaGestores = NULL;
    //listaOrdenadaGestores = InsereGestoresOrdenado(listaOrdenadaGestores, g1);
    //listaOrdenadaGestores = InsereGestoresOrdenado(listaOrdenadaGestores, g2);

    //// Altera Gestor
    //listaOrdenadaGestores = AlteraGestor(listaOrdenadaGestores, 777777777, "Teste Novo Nome");

    //// Mostra a lista de Gestores Ordenada
    //MostraListaGestores(listaOrdenadaGestores);

    //// Elimina Gestor
    //listaOrdenadaGestores = RemoveGestor(listaOrdenadaGestores, 333333333);
    //printf("\nLista apos remover gestor:\n");
    //MostraListaGestores(listaOrdenadaGestores);

#pragma endregion

#pragma region Insercao e manipulacao de dados de Ativos ME

    /// <summary>
    /// Insercao e manipulacao de dados de Meios de Mobilidade Eletrica
    /// Validação de funcionalidade de funções
    /// </summary>
    /// <param name="h"></param>

    ////// Cria ativos (Meio de Mobilidade Eletrica)
    //MeioME* m1 = CriaMeioME(4, "Bicicleta", 50, 20, "Braga", false);
    //MeioME* m2 = CriaMeioME(6, "Trotinete", 100, 10, "Braga", false);
    //MeioME* m3 = CriaMeioME(3, "Trotinete", 20, 10, "Barcelos", false);
    //MeioME* m4 = CriaMeioME(1, "Bicicleta", 02, 20, "Barcelos", false);
    //MeioME* m5 = CriaMeioME(5, "Bicicleta", 25, 20, "Porto", false);
    //MeioME* m6 = CriaMeioME(2, "Trotinete", 80, 10, "Porto", false);
    //MeioME* m7 = CriaMeioME(2, "Trotinete", 80, 10, "Braga", false);
    //MeioME* m8 = CriaMeioME(7, "Trotinete", 80, 10, "Famalicão", false);
    //MeioME* m9 = CriaMeioME(8, "Bicicleta", 80, 10, "Famalicão", false);
    //MeioME* m10 = CriaMeioME(9, "Bicicleta", 20, 15, "Viana do Castelo", false);
    //MeioME* m11 = CriaMeioME(10, "trotinete", 30, 12, "Viana do Castelo", false);


    ////// Insere os ativos Ordenados pelo ID e valida se o ID existe
    //MeioME* listaOrdenadaMeiosME = NULL;
    //listaOrdenadaMeiosME = InsereMeioMEOrdenado(listaOrdenadaMeiosME, m1);
    //listaOrdenadaMeiosME = InsereMeioMEOrdenado(listaOrdenadaMeiosME, m2);
    //listaOrdenadaMeiosME = InsereMeioMEOrdenado(listaOrdenadaMeiosME, m3);
    //listaOrdenadaMeiosME = InsereMeioMEOrdenado(listaOrdenadaMeiosME, m4);
    //listaOrdenadaMeiosME = InsereMeioMEOrdenado(listaOrdenadaMeiosME, m5);
    //listaOrdenadaMeiosME = InsereMeioMEOrdenado(listaOrdenadaMeiosME, m6);
    //listaOrdenadaMeiosME = InsereMeioMEOrdenado(listaOrdenadaMeiosME, m7);
    //listaOrdenadaMeiosME = InsereMeioMEOrdenado(listaOrdenadaMeiosME, m8);
    //listaOrdenadaMeiosME = InsereMeioMEOrdenado(listaOrdenadaMeiosME, m9);
    //listaOrdenadaMeiosME = InsereMeioMEOrdenado(listaOrdenadaMeiosME, m10);
    //listaOrdenadaMeiosME = InsereMeioMEOrdenado(listaOrdenadaMeiosME, m11);

    //// Mostra Lista de Meios M.E. Ordenados pelo ID
    //MostraListaMeiosME(listaOrdenadaMeiosME);

    //// Altera Meio M.E.
    //listaOrdenadaMeiosME = AlteraMeioME(listaOrdenadaMeiosME, 6, 90);

    ////Elimina Meio M.E.
    //listaOrdenadaMeiosME = RemoveMeioME(listaOrdenadaMeiosME, 1);
    //MostraListaMeiosME(listaOrdenadaMeiosME);

#pragma endregion

#pragma region Utilizacao de Ficheiros

    /// <summary>
    /// Utilização de ficheiros binarios (Open / Read / Write)
    /// Clientes / Gestores / Meios de mobilidade elétrica
    /// Validação de funcionalidade de funções
    /// </summary>
    /// <param name="h"></param>


    //// Cliente
    ////Cliente* listaOrdenadaClientes = NULL;
    //bool ficheiroClientes = GravarClienteBinario("Ficheiros/Dados_Cliente.bin", listaOrdenadaClientes);
    //DestroiListaClientes(&listaOrdenadaClientes);
    //listaOrdenadaClientes = LeClienteBinario("Ficheiros/Dados_Cliente.bin");
    //MostraListaClientes(listaOrdenadaClientes);

    //// Gestor
    ////Gestor* listaOrdenadaGestor = NULL;
    //bool ficheiroGestores = GravarGestoresBinario("Ficheiros/Dados_Gestor.bin", listaOrdenadaGestores);
    //DestroiListaGestores(&listaOrdenadaGestores);
    //listaOrdenadaGestores = LeGestoresBinario("Ficheiros/Dados_Gestor.bin");
    //MostraListaGestores(listaOrdenadaGestores);

    //// Meio Mobilidade Eletrica
    ////MeioME* listaOrdenadaMeiosME = NULL;
    //bool ficheiroMeiosME = GravarMeiosMEBinario("Ficheiros/Dados_MeioME.bin", listaOrdenadaMeiosME);
    //DestroiListaMeioME(&listaOrdenadaMeiosME);
    //listaOrdenadaMeiosME = LeMeioMEBinario("Ficheiros/Dados_MeioME.bin");
    //MostraListaMeiosME(listaOrdenadaMeiosME);

#pragma endregion

#pragma region Listagem dos meios de mobilidade elétrica por ordem decrescente de autonomia

    /// <summary>
    /// Listagem dos meios de mobilidade elétrica
    /// Por ordem decrescente de autonomia
    /// Validação de funcionalidade de funções
    /// </summary>
    /// <param name="h"></param>

    /*MeioME* listaOrdenadaMeiosMEBateria = NULL;
    listaOrdenadaMeiosMEBateria = LeMeioMEBinarioDecrescenteBateria("Ficheiros/Dados_MeioME.bin");
    MostraListaMeiosME(listaOrdenadaMeiosMEBateria);*/

#pragma endregion

#pragma region Registos de Aluguer

    /// <summary>
    /// Registo de um aluguer e libertação do aluguer de um Meio M.E.
    /// Identificação do Cliente
    /// Listagem dos meios reservados
    /// Validação de funcionalidade de funções
    /// </summary>
    /// <param name="h"></param>

    /*MeioME* listagemMeiosMEReserva = NULL;
    listagemMeiosMEReserva = LeMeioMEBinario("Ficheiros/Dados_MeioME.bin");
    AlugaMeioME(listagemMeiosMEReserva, 3);
    MostraListaMeiosME(listagemMeiosMEReserva);*/

    //LibertaAluguerMeioME(listagemMeiosMEReserva, 3);
    //MostraListaMeiosME(listagemMeiosMEReserva);

#pragma endregion

#pragma region Listagem dos meios de mobilidade elétrica por GeoLocalização

    /// <summary>
    /// Listagem dos meios de mobilidade elétrica por GeoLocalização
    /// Listados por ordem de ID
    /// Validação de funcionalidade de funções
    /// </summary>
    /// <param name="h"></param>

    //MeioME* listaOrdenadaMeiosMELocalizacao = NULL;
    //listaOrdenadaMeiosMELocalizacao = LeMeioMEBinario("Ficheiros/Dados_MeioME.bin");
    //MostraMeioMELocalizacao(listaOrdenadaMeiosMELocalizacao, "Braga");

#pragma endregion


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//				Program - Main		2a Parte TP					//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

    Edge* graph = CreateGraph();

#pragma region CRIA VERTICES

    /*bool result;

    Vertice* novoVertice = CriaVertice("Braga", 5);
    if (novoVertice != NULL) {
        grafo = InsereVerticeOrdenado(grafo, novoVertice, &result);
    }

    novoVertice = CriaVertice("Porto", 1);
    if (novoVertice != NULL) {
        grafo = InsereVerticeOrdenado(grafo, novoVertice, &result);
    }

    novoVertice = CriaVertice("Guimarães", 4);
    if (novoVertice != NULL) {
        grafo = InsereVerticeOrdenado(grafo, novoVertice, &result);
    }

    novoVertice = CriaVertice("Famalicão", 3);
    if (novoVertice != NULL) {
        grafo = InsereVerticeOrdenado(grafo, novoVertice, &result);
    }

    novoVertice = CriaVertice("Barcelos", 2);
    if (novoVertice != NULL) {
        grafo = InsereVerticeOrdenado(grafo, novoVertice, &result);
    }

    novoVertice = CriaVertice("Viana do Castelo", 6);
    if (novoVertice != NULL) {
        grafo = InsereVerticeOrdenado(grafo, novoVertice, &result);
    }

    novoVertice = CriaVertice("Lisboa", 7);
    if (novoVertice != NULL) {
        grafo = InsereVerticeOrdenado(grafo, novoVertice, &result);
    }*/
#pragma endregion

#pragma region CRIA ADJACENCIAS

    //grafo = InsereAdjacenciaVertice(grafo, "Viana do Castelo", "Barcelos", 39, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Barcelos", "Braga", 28, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Barcelos", "Porto", 62, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Braga", "Guimarães", 25, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Braga", "Famalicão", 24, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Famalicão", "Porto", 30, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Porto", "Lisboa", 360, &result);


    //// Para fazer a recursividade entre vertices
    //grafo = InsereAdjacenciaVertice(grafo, "Lisboa", "Porto", 360, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Porto", "Barcelos", 62, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Porto", "Famalicão", 30, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Famalicão", "Braga", 24, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Braga", "Barcelos", 28, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Barcelos", "Viana do Castelo", 39, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Guimarães", "Braga", 25, &result);




    //// TESTES -> 2 em Série!!!
    //grafo = InsereAdjacenciaVertice(grafo, "Viana do Castelo", "Barcelos", 39, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Barcelos", "Braga", 28, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Braga", "Guimarães", 25, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Guimarães", "Famalicão", 26, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Famalicão", "Porto", 36, &result);
    //grafo = InsereAdjacenciaVertice(grafo, "Porto", "Lisboa", 360, &result);


#pragma endregion

#pragma region IMPRESSÃO DADOS - DEBUG

    // MostraListaVertices(grafo);
    // MostraGrafo(grafo);


    //// Lê Grafo do ficheiro criado para testes de leituras / funções
    //bool dateResult2;
    //grafo = LeGrafo(grafo, "Ficheiros/Grafo.bin", &dateResult2);
    //if (grafo != NULL) {
    //	grafo = LeAdjacencias(grafo, &dateResult2);
    //}
    //else printf("Erro ao abrir ficheiro!\n");
    //MostraGrafo(grafo);


    //// Conta Saltos entre Vertices  -------------------------   ERRO!!!!
    //int contaSaltos = 0;
    //int src = 1;
    //int dst = 2;

    //int aux = ContagemSaltos(grafo, src, dst, contaSaltos);
    //printf("\nExiste %d salto(s) entre %d e %d.\n", aux, src, dst);

    //int contaSaltos2 = 0;
    //char* srcCidade = "Porto";
    //char* dstCidade = "Guimarães";
    //int aux2 = ContaSaltosVerticesNome(grafo, srcCidade, dstCidade, contaSaltos2);
    //printf("\nQuantos saltos são necessários entre %s e %s: %d\n", srcCidade, dstCidade, aux2);


    //// Valida ligações  -------------------------   ERRO!!!!
    //printf("\nExistem Ligações?\n");
    //int src2 = 1;
    //int dst2 = 2;
    //bool existe = ValidaLigacoesEntreVerticesCod(grafo, src2, dst2);
    //printf(" Existe Ligação entre %d e %d: %s\n", src2, dst2, (existe == true ? "Sim" : "Não"));

    //grafo = ResetVerticesVisitados(grafo);

    //char* src3 = "Porto";
    //char* dst3 = "Barcelos";
    //bool existe2 = ValidaLigacoesEntreVerticesCidade(grafo, src3, dst3);
    //printf(" Existe Ligação entre %s e %s: %s\n", src3, dst3, (existe == true ? "Sim" : "Não"));


    //// Gravação para ficheiro do grafo completo
    //int dateresult = GravaGrafo(grafo, "ficheiros/grafo.bin");
    //if (dateresult > 0) puts("\nGrafo gravado em ficheiro");



    // Impressão de dados de clientes e ME (a partir dos ficheiros)

    /*Cliente* listaOrdenadaClientes = NULL;
    listaOrdenadaClientes = LeClienteBinario("Ficheiros/Dados_Cliente.bin");
    MostraListaClientes(listaOrdenadaClientes);*/

    /*MeioME* listaOrdenadaMeiosME = NULL;
    listaOrdenadaMeiosME = LeMeioMEBinario("Ficheiros/Dados_MeioME.bin");
    MostraListaMeiosME(listaOrdenadaMeiosME);*/


    //// Lista ME por Localização fixa
    //MeioME* listaOrdenadaMeiosMELocalizacao = NULL;
    //listaOrdenadaMeiosMELocalizacao = LeMeioMEBinario("Ficheiros/Dados_MeioME.bin");
    //MostraMeioMELocalizacao(listaOrdenadaMeiosMELocalizacao, "Braga");



#pragma endregion

#pragma region Tratamento dados Grafo - FINAL

    // Inserir Cliente e Meios M.E. em Vertice (pela Localização)


    // Lê Grafo (Vertices/Adjacencias)
//    bool dateResult2;
//    grafo = LeGrafo(grafo, "Ficheiros/Grafo.bin", &dateResult2);
//    if (grafo != NULL) {
//        grafo = LeAdjacencias(grafo, &dateResult2);
//    }
//    else printf("Erro ao abrir ficheiro!\n");

    //getchar();

    // MostraGrafo(grafo);

    // Lê lista de clientes ficheiro binario
//    Cliente* listaOrdenadaClientes = NULL;
//    listaOrdenadaClientes = LeClienteBinario("Ficheiros/Dados_Cliente.bin");


    // Insere o Cliente no respetivo Vertice a partir da Localização do mesmo.
//    bool dateResult3;
//    grafo = InsereClienteGrafo(grafo, listaOrdenadaClientes, &dateResult3);

    //getchar();

    // Lê lista de Meios M.E. ficheiro binario
//    MeioME* listaOrdenadaMeiosME = NULL;
//    listaOrdenadaMeiosME = LeMeioMEBinario("Ficheiros/Dados_MeioME.bin");

    // Insere o MeioME no respetivo Vertice a partir da Localização do mesmo.
//    bool dateResult4;
//    grafo = InsereMeioMEGrafo(grafo, listaOrdenadaMeiosME, &dateResult4);
//
//
//    MostraGrafo(grafo);


    // Lixo!!!

    //// Valida ligações  -------------------------   ERRO!!!!
    //printf("\nExistem Ligações?\n");
    //int src2 = 4;
    //int dst2 = 2;
    //bool existe = ValidaLigacoesEntreVerticesCod(grafo, src2, dst2);
    //printf(" Existe Ligação entre %d e %d: %s\n", src2, dst2, (existe == true ? "Sim" : "Não"));

    //grafo = ResetVerticesVisitados(grafo);



    /*	char* src3 = "Porto";
        char* dst3 = "Barcelos";
        bool existe2 = ValidaLigacoesEntreVerticesCidade(grafo, src3, dst3);
        printf(" Existe Ligação entre %s e %s: %s\n", src3, dst3, (existe2 == true ? "Sim" : "Não")); */




    //// Conta Saltos entre Vertices  -------------------------   ERRO!!!!
    //int contaSaltos = 0;
    //int src = 1;
    //int dst = 4;

    //int aux = ContagemSaltos(grafo, src, dst, contaSaltos);
    //printf("\nExiste %d salto(s) entre %d e %d.\n", aux, src, dst);

    //grafo = ResetVerticesVisitados(grafo);


    //int contaSaltos2 = 0;
    //char* srcCidade = "Porto";
    //char* dstCidade = "Guimarães";
    //int aux2 = ContaSaltosVerticesNome(grafo, srcCidade, dstCidade, contaSaltos2);
    //printf("\nQuantos saltos são necessários entre %s e %s: %d\n", srcCidade, dstCidade, aux2);

#pragma endregion


    return 0;
}
