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

void printAdjMatrix(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

<<<<<<< HEAD
int minDist(int dist[],int sptSet[]){
    int min = INT_MAX, minI = 0;

    for (int i = 0; i < N; ++i) {
        if(sptSet == 0 && dist[i]<=min){
            min=dist[i];
            minI=i;
        }
    }
    return minI;
}
=======
void dijkstra(int G[50][50],int n,int startnode)
{

    int cost[50][50],distance[50],pred[50];
    int visited[50],count,mindistance,nextnode,i,j;
>>>>>>> parent of ae8b937... Build 0.4.1

void dibujarCamino(int parent[], int dest){
    if(parent[dest]==-1){
        return;
    }
    dibujarCamino(parent,parent[dest]);
    printf("%d->",dest);
}

/*int printSolution(int dist[], int n,int parent[]){
    int src = 0;
    printf("Vertex\t Distance\tPath");
    for (int i = 1; i < N; i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ",
               src, i, dist[i], src);
        dibujarCamino(parent, i);
    }
}*/

/*void Dijkstra(int AdjMatrix[N][N],int partida){
    int distancia[N];

<<<<<<< HEAD
    int sptSet[N];

    int parent[N];
=======
    while(count<n-1)
    {
        mindistance=INF;
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
>>>>>>> parent of ae8b937... Build 0.4.1

    for (int i = 0; i < N ; ++i) {
        parent[0]=-1;
        distancia[i] = INT_MAX;
        sptSet[i] = 0;
    }

<<<<<<< HEAD
    distancia[partida] = 0;

    for (int j = 0; j < N-1; ++j) {
        int u = minDist(distancia,sptSet);
        sptSet[u] = 1;
        for (int n = 0; n < N; ++n) {
            if(!sptSet[n] && AdjMatrix[u][n] && distancia[u] + AdjMatrix[u][n] < distancia[n]){
                parent[n] = u;
                distancia[n]= distancia[u] + AdjMatrix[u][n];
            }
=======
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\nDistancia del nodo %d >> %d",i,distance[i]);
            printf("\nPath=%d",i);
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startnode);
>>>>>>> parent of ae8b937... Build 0.4.1
        }
    }

    printSolution(distancia,N,parent);

}*/

void mostrar(char **est) {
    for (int i = 0; i < 42; ++i) {
        printf("%s\n", est[i]);
    }
}

void printSolution(int dist[][N])
{
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dist[i][j] == INF)
                printf("%2s", "INF");
            else
                printf ("%7d | ", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall (int graph[][N])
{
    /* dist[][] will be the output matrix that will finally have the shortest
      distances between every pair of vertices */
    int dist[N][N], i, j, k;

    /* Initialize the solution matrix same as input graph matrix. Or
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            dist[i][j] = graph[i][j];

    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of an iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of an iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < N; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < N; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < N; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

#endif
