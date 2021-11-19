#include <iostream>
#include "dijkstra.hpp"

int main(){
    vector<int> rot;
    vector<double> dt;
    int n, m, b, i, origem, destino, peso;
    cin >> n >> m >> b >> i;

    // CRIANDO GRAFO =======================================
    Grafo g = Grafo(n);
    g.criarVertices();
     // CRIANDO LISTA DE ADJACENCIA DOS VERTICES =============
    for (int i = 0; i < m; i++)
    {
        cin >> origem >> destino >> peso;
        g.add(origem,destino,peso,b);
    }
    //g.grafo();
    //INICIA DFS ============================================
    g.dijkstra(i,&rot,&dt);
    //PRINTAR AS ARESTAS/VERTICE ============================
    g.printVisit(i,&rot,&dt);

    return 0;
}