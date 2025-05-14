/****************************************************************
Fecha 14 de mayo 2025
Autor: Juan Esteban Bello
Materia: Estructuras de Datos
Tema: algoritmo de dijkstra
*****************************************************************/

#include <iostream>
#include <climits>
using namespace std;

const int V=9;
int minDistance( int dist[], bool sptSet[]){
	// Inicializar con valor mínimo
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
	if (sptSet[v] == false && dist[v] <= min)
	min = dist[v], min_index = v;
	return min_index;
}
void printSolution(int dist[]){
	cout<<"vertice \t Distancia desde la Fuente\n";
	for (int i = 0; i < V; i++)
		cout << i << " \t\t\t\t" << dist[i] << endl;
}
void dijkstra( int graph[V][V], int src){
	int dist[V]; //La matriz de salida. dist[i] tendrá la distancia más corta desde src a i
	bool sptSet[V]; // sptSet[i] será verdadero si el vértice i está incluido en el árbol del
	// camino más corto o la distancia más corta de src a i está finalizada.
	// Inicializa todas las distancias INFINITE y stpSet[] como false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	// La distancia del vértice de origen respecto a sí mismo es siempre 0
	dist[src] = 0;
	// Encontrar el camino más corto para todos los vértices
	for (int count = 0; count < V - 1; count++) {
		// Elige el vértice de distancia mínima del conjunto de vértices aún no procesados. u es siempre igual a src en la primera iteración.
		int u = minDistance(dist, sptSet);
	// Marcar el vértice elegido como procesado
	sptSet[u] = true;
	// Actualiza el valor dist de los vértices adyacentes al vértice elegido.
	for (int v = 0; v < V; v++)
		// Actualizar dist[v] sólo si no está en sptSet, hay una arista de u a v, y el peso
		// total de la ruta de src a v a través de u es menor que el valor actual dedist[v].
	if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
		dist[v] = dist[u] + graph[u][v];
	}	
	// imprimir la matriz de distancias construida
	printSolution(dist);
}


int main(){
	/* Grafo */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
			{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
			{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
			{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
			{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
			{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
			{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
			{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
			{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	// llamada a la función
	dijkstra(graph, 0);
return 0;
}
