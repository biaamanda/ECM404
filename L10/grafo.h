#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#define MAX_VERT 100
#define MAX_VERT_LISTA 100

typedef struct{
    float Pesos[MAX_VERT][MAX_VERT];
    int nVertices;
    int digrafo;
} Grafo;

typedef struct{
    int vertices[MAX_VERT_LISTA];
    int nVertices;
} ListaDeVertices;


void ExibirGrafo (Grafo g);
void ExibirArestas (Grafo g);

// Cria um grafo de n vértices.
void CriarGrafo (Grafo *g, int n, int dig);

// Insere/Remove aresta de um grafo indicando o vértice de origem e de destino.
void InserirAresta (Grafo *g, int de, int para, float peso);
void RemoverAresta (Grafo *g, int de, int para);

float PesoDaAresta (Grafo g, int de, int para);

int GrauDeEntrada (Grafo g, int v);
int GrauDeSaida (Grafo g, int v);

int Vertedouro (Grafo g, int v);
int Sorvedouro (Grafo g, int v);

int Adjacente (Grafo g, int de, int para);

void Warshall (Grafo g, int w[MAX_VERT][MAX_VERT]);

int Alcanca (Grafo g, int de, int para);

float PesoDoPasseio (Grafo g, ListaDeVertices p);

#endif 