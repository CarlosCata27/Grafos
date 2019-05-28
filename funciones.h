#ifndef GRAFOS_FUNCIONES_H
#define GRAFOS_FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 42
#define INF 9999

typedef struct _Vertice{
    int src, dest, segundos;
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

void printGraph(Grafo* graph, char *nombres[]){
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

void printAdjMatrix(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void dijkstra(int G[42][42],int n,int startnode,char *nombres[42]){

    int cost[42][42],distance[42],pred[42];
    int visited[42],count,mindistance,nextnode,i,j;

    for(i=0;i<42;i++)
        for(int j=0;j<42;j++)
            if(G[i][j]==0)
                cost[i][j]=INF;
            else
                cost[i][j]=G[i][j];


    for(i=0;i<42;i++){
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }


    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<42-1){
        mindistance=INF;
        for(i=0;i<42;i++)
            if(distance[i]<mindistance&&!visited[i]){
                mindistance=distance[i];
                nextnode=i;
            }

        visited[nextnode]=1;
        for(i=0;i<42;i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }

    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            if(i == n-1){
                printf("Distancia del nodo %s a %s >> %ds", nombres[startnode], nombres[i], distance[i]);
                printf("\nRecorrido = %s", nombres[i]);
            }
            j = i;
            do {
                j = pred[j];
                if(i == n-1) {
                    printf("<-%s", nombres[j]);
                }
            } while (j != startnode);
        }
}

void mostrar(char **est) {
    for (int i = 0; i < 42; ++i) {
        printf("%d >> %s\n",i, est[i]);
    }
}

#endif
