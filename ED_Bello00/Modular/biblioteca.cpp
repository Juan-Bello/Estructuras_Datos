/************************
*fecha: 29 enero 2025
*autor: juan bello
*materia: Estructuras de datos
*topico: programacion modular y complejidad de algoritmos
*pontificia universidad javeriana
************************/

#include <iostream>
#include "biblioteca.h"

using namespace std;


//funcion para inicializar las matrices
void iniMatriz(int **a,int **b,int **c,int n){
	for(int i=0;i<n;i++){
		a[i] = new int [n];
		b[i] = new int [n];
		c[i] = new int [n];

		for(int j=0;j<n;j++){
			a[i][j] = 2*i;
			b[i][j] = i+j;
			c[i][j] = 0;
		}
	}
}

//funcion para mostrar las matrices
void verMatriz(int **m,int n){
	cout<<"\n \n matriz"<<endl;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cout<<" "<<m[i][j];
		}
		cout<<"\n";
	}
}

//funcion para multiplicar matrices
void multMatriz(int **a,int **b,int **c,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int suma = 0;
			for(int k=0;k<n;k++){
				suma += a[i][k]*b[k][j];
			}
			c[i][j] = suma;
		}
	}
}

//funcion eliminar resrva de memoria
void liberarMem(int **a,int **b,int **c,int N){
	for(int i=0;i<N;i++){
		delete a [i];
		delete b [i];
		delete c [i];
	}
}

