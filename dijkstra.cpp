#include <iostream>
#include <algorithm>
#include <float.h>
#include "dijkstra.hpp"

Aresta::Aresta(int v, int p)
{
    vertice = v;
    peso = p;
}

Vertice::Vertice(int i)
{
    indice = i;
    visitado = false;
}

void Vertice::addAresta(Vertice *destino, int p)
{
    Aresta *a = new Aresta(destino->indice, p);
    arestas.push_back(a);
}

Grafo::Grafo(int n)
{
    qnt = n;
}

void Grafo::add(int origem, int destino, int peso, int direcionado)
{
    Vertice *auxOri = buscarVertice(origem);
    Vertice *auxDest = buscarVertice(destino);
    if (direcionado == 0)
    {
        auxOri->addAresta(auxDest, peso);
        auxDest->addAresta(auxOri, peso);
    }
    else
        auxOri->addAresta(auxDest, peso);
}

void Grafo::criarVertices()
{
    for (int i = 1; i <= qnt; i++)
    {
        Vertice *v = new Vertice(i);
        vertices.push_back(v);
    }
}

Vertice *Grafo::buscarVertice(int indice)
{
    for (auto it = vertices.begin(); it != vertices.end(); it++)
    {
        if ((*it)->indice == indice)
        {
            return (*it);
        }
    }
    return NULL;
}

void Grafo::dijkstra(int inicio, vector<int> *rot, vector<double> *dt)
{
    auto itR = rot->begin();
    auto itD = dt->begin();
    int index;

    for (int i = 1; i <= qnt; i++)
    {
        if (i == inicio)
        {
            itR = rot->insert(rot->begin() + (i - 1), 0);
            itD = dt->insert(dt->begin() + (i - 1), 0);
        }
        else
        {
            itR = rot->insert(rot->begin() + (i - 1), 0);
            itD = dt->insert(dt->begin() + (i - 1), DBL_MAX);
        }
    }
    while (verticesParaVisita())
    {
        itD = menorDt(dt);
        index = (itD - dt->begin());
        vertices[index]->visitado = true;
        for (auto it = vertices[index]->arestas.begin(); it != vertices[index]->arestas.end(); it++)
        {
            if ((*itD) + (*it)->peso < (*dt)[(*it)->vertice - 1])
            {
                (*dt)[(*it)->vertice - 1] = (*itD) + (*it)->peso;
                (*rot)[(*it)->vertice - 1] = vertices[index]->indice;
            }
        }
    }
}

void Grafo::printVisit(int inicio, vector<int> *rot, vector<double> *dt)
{
    vector<int> c;
    
    for (auto it = vertices.begin(); it != vertices.end(); it++)
    {
        c.erase(c.begin(),c.end());
        if((*rot)[(*it)->indice-1] != 0){
            cout << (*it)->indice << " (" << (*dt)[(*it)->indice-1] <<"): ";
            caminho((*it)->indice, &c, (*rot));
            for(auto it = c.begin(); it != c.end(); it++){
                cout << (*it) << " ";
            } 
            cout << endl;
        }
    }
}

void Grafo::caminho(int indice, vector<int> *c, vector<int> rot){
    auto it = (*c).insert((*c).begin(), indice);
    if(rot[indice-1] != 0)
        caminho(rot[indice-1], c, rot);
}

bool Grafo::verticesParaVisita()
{
    bool retorno = false;
    for (auto it = vertices.begin(); it != vertices.end(); it++)
    {
        if ((*it)->visitado == false)
        {
            retorno = true;
            break;
        }
    }
    return retorno;
}

vector<double>::iterator Grafo::menorDt(vector<double> *dt)
{
    double aux = DBL_MAX;
    auto itAux = dt->begin();
    for (auto it = dt->begin(); it != dt->end(); it++)
    {
        if ((*it) < aux && vertices[(it - dt->begin())]->visitado == false)
        {
            aux = (*it);
            itAux = it;
        }
    }
    return itAux;
}