#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int menu, destino, partida;
    char *nombres[42] = {"Insurgentes", "Cuauhtemoc", "Balderas", "Salto del Agua", "Isabel la Catolica", "Pino Suarez","Merced",
                         "Candelaria", "San Lazaro", "Moctezuma", "Balbuena","Normal", "San Cosme", "Revolucion", "Hidalgo","Bellas Artes",
                         "Allende", "Zocalo", "San Antonio Abad","Chabacano","Viaducto", "Tlatelolco","Guerrero", "Juarez", "Ninos Heroes",
                         "Hospital General","Centro Medico", "Canal del Norte", "Morelos", "Fray Servando","Jamaica", "Santa Anita", "Garibaldi/Lagunilla",
                         "San Juan de Letran","Doctores", "Obrera", "La Viga", "Chilpancingo","Lazaro Cardenas", "Buenavista","Lagunilla", "Tepito"};
    Vertice vertices[] = {{0,1,75},{1,2,62},{2,3,58},{3,4,55},{4,5,95},{5,6,110},{6,7,87},{7,8,93},{8,9,118},{9,10,82},
                          {11,12,63},{12,13,53},{13,14,60},{14,15,43},{15,16,55},{16,17,62},{17,5,59},{5,18,75},{18,19,108},{19,20,80},
                          {21,22,122},{22,14,110},{14,23,50},{23,2,68},{2,24,85},{24,25,74},{25,26,87},{27,28,62},{28,7,45},{7,29,65},
                          {29,30,64},{30,31,65},{32,15,70},{15,33,60},{33,3,73},{3,34,68},{34,35,77},{35,19,82},{19,36,90},{36,31,63},
                          {37,26,107},{26,38,75},{38,19,110},{19,30,90},{39,22,110},{22,32,115},{32,40,100},{40,41,80},{41,28,75},{28,8,83}};

    int size = sizeof(vertices)/ sizeof(vertices[0]);
    Grafo *grafo = crearGrafo(vertices, size);
    int AdjMatriz[42][42];

    for (int j = 0; j<42 ; ++j) {
        for (int i = 0; i < 42 ; ++i) {
            AdjMatriz[j][i] = 0;
        }
    }

    for (int k = 0; k < 50 ; ++k) {
        AdjMatriz[vertices[k].src][vertices[k].dest] = vertices[k].segundos;
        AdjMatriz[vertices[k].dest][vertices[k].src] = vertices[k].segundos;
    }

    do{
        puts("BIENVENIDO AL SISTEMA PARA BUSCAR LA MEJOR RUTA DEL METRO DE LA CDMX\n"
             "Esta es la lista de las estaciones disponibles:\n");
        mostrar(nombres);
        puts("Seleccione una estacion de partida:");
        scanf("%d",&partida);
        puts("Seleccione una estacion de destino:");
        scanf("%d",&destino);

        if(partida == destino){
            puts("Ya estas en la estacion a la que quieres llegar");
            menu =1;
        }else{
            printf("El recorrido ideal de la estacion %s a la estacion %s es:\n",nombres[partida],nombres[destino]);
            dijkstra(AdjMatriz,destino+1,partida,nombres);
            puts("\n\nDeseas seleccionar otra ruta\n"
                 "1 >> Si\n"
                 "0 >> No\n");
            scanf("%d",&menu);
        }
    }while(menu!=0);
    return 0;
}