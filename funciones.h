#ifndef GRAFOS_FUNCIONES_H
#define GRAFOS_FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 42

typedef struct _Vertice{
    int src, dest, segundos;
    char *nombre;
}Vertice;

typedef struct _Nodo {
    int dest, segundos;
    struct _Nodo *sig;
}Nodo;

typedef struct _Graph {
    struct _Nodo *inicio[N];
}Grafo;

Grafo* crearGrafo(Vertice vertices[], int size)
{
    unsigned i;
    Grafo* graph = (Grafo*)malloc(sizeof(Grafo));

    for (i = 0; i < N; i++)
        graph->inicio[i] = NULL;

    for (i = 0; i < size; i++)
    {
        int src = vertices[i].src;
        int dest = vertices[i].dest;
        int segundos = vertices[i].segundos;
        char *nombre = vertices[i].nombre;

        Nodo* newNode = (Nodo*)malloc(sizeof(Nodo));
        newNode->dest = dest;
        newNode->segundos = segundos;
        newNode->sig = graph->inicio[src];
        graph->inicio[src] = newNode;

        newNode = (Nodo*)malloc(sizeof(Nodo));
        newNode->dest = src;
        newNode->segundos = segundos;
        newNode->sig = graph->inicio[dest];
        graph->inicio[dest] = newNode;
    }

    return graph;
}

void printGraph(Grafo* graph, char *nombres[])
{
    int i;
    for (i = 0; i < N; i++)
    {
        Nodo* ptr = graph->inicio[i];
        while (ptr != NULL)
        {
            printf("%s >> %s t:%ds  ",nombres[i], nombres[ptr->dest], ptr->segundos);
            ptr = ptr->sig;
        }
        printf("\n");
    }
}

void printAdjMatrix(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void dijkstra(int **G,int n,int startnode) {
    int cost[42][42], distance[42], pred[42];
    int visited[42], count, mindistance, nextnode, i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = 999;
            else
                cost[i][j] = G[i][j];

    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = 9999;

        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    for (i = 0; i < n; i++) {
        if (i != startnode) {
            printf("\nDistancia del nodo %d a %d = %d",startnode, i, distance[i]);
            printf("\nCamino = %d", i);
            j = i;
            do {
                j = pred[j];
                printf(" << %d", j);
            } while (j != startnode);
        }
    }
}

void mostrar(char **est) {
    for (int i = 0; i < 42; ++i) {
        printf("%s\n", est[i]);
    }
}

#endif
