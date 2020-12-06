/*
* Rodrigo Muñoz Guerrero
* A00572858
* 29/11/2020
*/

#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED

//Librerias que se usaran
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

//Se crea la clase de Query donde estaran las funciones para
//encontrar el camino más rápido y el más barato
class Query {
public:
    string findCheapestPrice(int[][4], int, int);
    string findQuickestPath(int[][4], int, int);
};

/*
*Función para encntrar el camino más barato entre dos grafos
*O(v+e) por ser un algoritmo de búsqueda BFS (Breadth_First Search)
*Usar un BFS para encontrar el camino más corto en un grafo sólo es recomendable con
*grafos pequeños ya que como se tiene que explorar todo el grafo, con estructuras de miles
*de nodos puede ser muy pesado y lento.
*/
string Query::findCheapestPrice(int flights[][4], int src, int dst){
    unordered_map<int, vector<pair<int, int> > > adjList;
    for (int a = 0 ; a < 30 ; a++) {
        adjList[flights[a][0]].push_back({ flights[a][1], flights[a][2] });
    }
    queue<pair<int, int> > q;
    q.push({ src, 0 });
    int srcDist = INT_MAX;
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            pair<int, int> curr = q.front();
            q.pop();
            for (auto next : adjList[curr.first]) {
                if (srcDist < curr.second + next.second)
                    continue;
                q.push({ next.first, curr.second + next.second });
                if (dst == next.first) {
                    srcDist = min(srcDist, curr.second + next.second);
                }
            }
        }
    }
    int result = (srcDist == INT_MAX ? -1 : srcDist);
    stringstream resp;
    resp << "CHEAPEST PATH= $" << result << endl;
    string respp = resp.str();
    return respp;
}

/*
* Esta función hace lo mismo que la pasada pero en vez de imprimir
* el camino más barato, éste imprime el camino más rápido.
*O(v+e) por ser un algoritmo de búsqueda BFS (Breadth_First Search)
*/
string Query::findQuickestPath(int flights[][4], int src, int dst){
    unordered_map<int, vector<pair<int, int> > > adjList;
    for (int a = 0 ; a < 30 ; a++) {
        adjList[flights[a][0]].push_back({ flights[a][1], flights[a][3] });
    }
    queue<pair<int, int> > q;
    q.push({ src, 0 });
    int srcDist = INT_MAX;
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            pair<int, int> curr = q.front();
            q.pop();
            for (auto next : adjList[curr.first]) {
                if (srcDist < curr.second + next.second)
                    continue;
                q.push({ next.first, curr.second + next.second });
                if (dst == next.first) {
                    srcDist = min(srcDist, curr.second + next.second);
                }
            }
        }
    }
    int result = (srcDist == INT_MAX ? -1 : srcDist);
    stringstream resp;
    resp << "QUICKEST TIME= " << result << " H" << endl;
    string respp = resp.str();
    return respp;
}

#endif // PROGRAM_H_INCLUDED
