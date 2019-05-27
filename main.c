#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char *est[42] = {"0 >> Insurgentes", "1 >> Cuauhtemoc", "2 >> Balderas", "3 >> Salto del Agua",
                     "4 >> Isabel la Catolica", "5 >> Pino Suarez",
                     "6 >> Merced", "7 >> Candelaria", "8 >> San Lazaro", "9 >> Moctezuma", "10 >> Balbuena",
                     "11 >> Normal", "12 >> San Cosme", "13 >> Revolucion", "14 >> Hidalgo",
                     "15 >> Bellas Artes", "16 >> Allende", "17 >> Zocalo", "18 >> San Antonio Abad", "19 >> Chabacano",
                     "20 >> Viaducto", "21 >> Tlatelolco",
                     "22 >> Guerrero", "23 >> Juarez", "24 >> Ninos Heroes", "25 >> Hospital General",
                     "26 >> Centro Medico", "27 >> Canal del Norte", "28 >> Morelos", "29 >> Fray Servando",
                     "30 >> Jamaica", "31 >> Santa Anita", "32 >> Garibaldi/Lagunilla", "33 >> San Juan de Letran",
                     "34 >> Doctores", "35 >> Obrera", "36 >> La Viga", "37 >> Chilpancingo",
                     "38 >> Lazaro Cardenas", "39 >> Buenavista", "40 >> Lagunilla", "41 >> Tepito"};
    char *nombres[42] = {"Insurgentes", "Cuauhtemoc", "Balderas", "Salto del Agua", "Isabel la Catolica", "Pino Suarez",
                         "Merced", "Candelaria", "San Lazaro", "Moctezuma", "Balbuena",
                         "Normal", "San Cosme", "Revolucion", "Hidalgo","Bellas Artes", "Allende", "Zocalo", "San Antonio Abad",
                         "Chabacano","Viaducto", "Tlatelolco","Guerrero", "Juarez", "Ninos Heroes", "Hospital General",
                         "Centro Medico", "Canal del Norte", "Morelos", "Fray Servando","Jamaica", "Santa Anita", "Garibaldi/Lagunilla",
                         "San Juan de Letran","Doctores", "Obrera", "La Viga", "Chilpancingo","Lazaro Cardenas", "Buenavista",
                         "Lagunilla", "Tepito"};
    int destino,partida;

    Vertice vertices[] = {{0,1,75},{1,2,62},{2,3,58},{3,4,55},{4,5,95},
                          {5,6,110},{6,7,87},{7,8,93},{8,9,118},{9,10,82},
                          {11,12,63},{12,13,53},{13,14,60},{14,15,43},{15,16,55},
                          {16,17,62},{17,5,59},{5,18,75},{18,19,108},{19,20,80},
                          {21,22,122},{22,14,110},{14,23,50},{23,2,68},{2,24,85},
                          {24,25,74},{25,26,87},{27,28,62},{28,7,45},{7,29,65},
                          {29,30,64},{30,31,65},{32,15,70},{15,33,60},{33,3,73},
                          {3,34,68},{34,35,77},{35,19,82},{19,36,90},{36,31,63},
                          {37,26,107},{26,38,75},{38,19,110},{19,30,90},{39,22,110},
                          {22,32,115},{32,40,100},{40,41,80},{41,28,75},{28,8,83}
    };

    int size = sizeof(vertices)/ sizeof(vertices[0]);

    printf("%d",size);

    Grafo *grafo = crearGrafo(vertices, size);

    int pesos[42][42];

    for (int j = 0; j<42 ; ++j) {
        for (int i = 0; i < 42 ; ++i) {
            pesos[j][i] = 0;
        }
    }

    printGraph(grafo,nombres);

    puts("BIENVENIDO AL SISTEMA PARA BUSCAR LA MEJOR RUTA DEL METRO DE LA CDMX\n"
         "Esta es la lista de las estaciones disponibles:\n");
    mostrar(est);
    puts("Seleccione una estacion de partida:\n");
    scanf("%d",&partida);
    puts("Seleccione una estacion de destino:\n");
    scanf("%d",&destino);


    printf("El recorrido de la estacion %d a la estacion %d es:",partida,destino);
    dijkstra(pesos,destino,partida);
    return 0;
}