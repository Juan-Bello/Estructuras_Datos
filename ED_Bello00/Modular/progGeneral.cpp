/***********************
*fecha: 29 enero 2025
*autor: juan bello
*materia: Estructuras de datos
*topico: programacion modular y complejidad de algoritmos
*pontificia universidad javeriana
************************/

#include <iostream>
#include "biblioteca.h"

using namespace std;

int main(int argc,char *argv[]){
	if(argc < 2){
		cout<<"cantidad de argumentos invalida"<<endl;
		exit(0);
	}

	int N = (int) atoi(argv[1]);

	int **mA = new int *[N];
	int **mB = new int *[N];
	int **mC = new int *[N];

	//se inicia cada matriz
	iniMatriz(mA,mB,mC,N);

	//se multiplican las matrices AxB = C
	multMatriz(mA,mB,mC,N);

	//se imprimen las matrices
	verMatriz(mA,N);
	verMatriz(mB,N);
	verMatriz(mC,N);

	liberarMem(mA,mB,mC,N);
	cout<<"\n hola soy juan"<<endl;
	return 0;
}


