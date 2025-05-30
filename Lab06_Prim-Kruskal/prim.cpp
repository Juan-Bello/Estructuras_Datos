/****************************************************************
Fecha 21 de mayo 2025
Autor: Juan Esteban Bello
Materia: Estructuras de Datos
Tema: algoritmo de prim
*****************************************************************/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Funcion para encontrar el vertice con la clave minima
int minKey(const vector<int> &key, const vector<bool> &mstSet) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < key.size(); v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Funcion para imprimir el arbol de expansion mínima
void printMST(const vector<int> &parent, const vector<vector<int>> &graph) {
    cout << "Arista \tPeso\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
}

// Algoritmo de Prim
void primMST(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> parent(V);   // Array para almacenar el árbol MST
    vector<int> key(V);      // Valores clave para elegir el mínimo peso
    vector<bool> mstSet(V);  // Conjunto de vértices incluidos en MST

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

// Funcion principal con un ejemplo
int main() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 5},
        {1, 0, 3, 9, 0},
        {0, 3, 0, 2, 6},
        {0, 8, 6, 0, 9},
        {3, 0, 5, 10, 0}
    };

    primMST(graph);

    return 0;
}

