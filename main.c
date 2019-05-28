#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int menu;
    char *nombres[42] = {"Insurgentes", "Cuauhtemoc", "Balderas", "Salto del Agua", "Isabel la Catolica", "Pino Suarez",
                         "Merced", "Candelaria", "San Lazaro", "Moctezuma", "Balbuena",
                         "Normal", "San Cosme", "Revolucion", "Hidalgo","Bellas Artes", "Allende", "Zocalo", "San Antonio Abad",
                         "Chabacano","Viaducto", "Tlatelolco","Guerrero", "Juarez", "Ninos Heroes", "Hospital General",
                         "Centro Medico", "Canal del Norte", "Morelos", "Fray Servando","Jamaica", "Santa Anita", "Garibaldi/Lagunilla",
                         "San Juan de Letran","Doctores", "Obrera", "La Viga", "Chilpancingo","Lazaro Cardenas", "Buenavista",
                         "Lagunilla", "Tepito"};
    char *est[42] = {"a >> Insurgentes", "b >> Cuauhtemoc", "c >> Balderas", "d >> Salto del Agua",
                     "e >> Isabel la Catolica", "f >> Pino Suarez",
                     "g >> Merced", "h >> Candelaria", "i >> San Lazaro", "j >> Moctezuma", "k >> Balbuena",
                     "l >> Normal", "m >> San Cosme", "n >> Revolucion", "o >> Hidalgo",
                     "p >> Bellas Artes", "q >> Allende", "r >> Zocalo", "s >> San Antonio Abad",
                     "t >> Chabacano","u >> Viaducto", "v >> Tlatelolco",
                     "w >> Guerrero", "x >> Juarez", "y >> Ninos Heroes", "z >> Hospital General",
                     "A >> Centro Medico", "B >> Canal del Norte", "C >> Morelos", "D >> Fray Servando",
                     "E >> Jamaica", "F >> Santa Anita", "G >> Garibaldi/Lagunilla", "H >> San Juan de Letran",
                     "I >> Doctores", "J >> Obrera", "K >> La Viga", "L >> Chilpancingo",
                     "M >> Lazaro Cardenas", "N >> Buenavista", "O >> Lagunilla", "P >> Tepito"};
    int destino,partida;

    Vertice puentes[] = {{0,1,75},{1,2,62},{2,3,58},{3,4,55},{4,5,95},
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

    int size = sizeof(puentes)/ sizeof(puentes[0]);

    printf("%d",size);

    Grafo *grafo = crearGrafo(puentes, size);

    int pesos[42][42];

    for (int j = 0; j<42 ; ++j) {
        for (int i = 0; i < 42 ; ++i) {
            pesos[j][i] = 0;
        }
    }

<<<<<<< HEAD
    for (int k = 0; k < 50 ; ++k) {
        pesos[puentes[k].src][puentes[k].dest] = puentes[k].segundos;
        printf("[%d][%d] = %d\n",puentes[k].src,puentes[k].dest,puentes[k].segundos);
        pesos[puentes[k].dest][puentes[k].src] = puentes[k].segundos;
        printf("[%d][%d] = %d\n",puentes[k].dest,puentes[k].src,puentes[k].segundos);
    }

    printAdjMatrix(pesos);

    floydWarshall(pesos);
=======
    printGraph(grafo,nombres);
>>>>>>> parent of ae8b937... Build 0.4.1
    do
    {
        puts("BIENVENIDO AL SISTEMA PARA BUSCAR LA MEJOR RUTA DEL METRO DE LA CDMX\n"
             "Esta es la lista de las estaciones disponibles:\n");
        mostrar(est);
        puts("Seleccione una estacion de partida:\n");
        scanf("%d",&partida);
        puts("Seleccione una estacion de destino:\n");
        scanf("%d",&destino);


        printf("El recorrido de la estacion %d a la estacion %d es:",partida,destino);
<<<<<<< HEAD
=======
        dijkstra(pesos,destino,partida);
>>>>>>> parent of ae8b937... Build 0.4.1
        puts("Deseas seleccionar otra ruta\n"
             "1 >> Si\n"
             "0 >> No\n");
             scanf("%d",&menu);
    }while(menu!=0);


    return 0;
}