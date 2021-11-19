#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
using namespace std;

class Aresta{
public:
    int vertice;
    int peso;

    Aresta(int v, int p);
};

class Vertice{
public:
    int indice;
    bool visitado;
    vector<Aresta*> arestas;

    Vertice(int i);
    void addAresta(Vertice* destino,int p);
};

class Grafo{
public:
    int qnt;
    vector<Vertice*> vertices;

    Grafo(int n);
    void add(int origem, int destino, int peso, int direcionado);
    void criarVertices();
    Vertice *buscarVertice(int indice);
    void dijkstra(int inicio, vector<int> *rot, vector<double> *dt);
    void printVisit(int inicio, vector<int> *rot, vector<double> *dt);
    bool verticesParaVisita();
    vector<double>::iterator menorDt(vector<double> *dt);
    void caminho(int indice, vector<int> *caminho, vector<int> rot);
};

#endif