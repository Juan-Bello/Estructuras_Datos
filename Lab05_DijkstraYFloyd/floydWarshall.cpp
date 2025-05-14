/****************************************************************
Fecha 14 de mayo 2025
Autor: Juan Esteban Bello
Materia: Estructuras de Datos
Tema: algoritmo de Floyd Warshal
*****************************************************************/


#include <iostream>

using namespace std;

const int dim = 5;

//funcion que dada una matris de abyacencia, aplica el algoritmo de Floyd Warshal para reemplazar los valores de infinito (500 in este caso), con el valor del camino de menor costo
void floyds(int b[][dim]){
	int i, j, k;
	for (k = 0; k < dim; k++) {
		for (i = 0; i < dim; i++) {
			for (j = 0; j < dim; j++) {
				if ((b[i][k] * b[k][j] != 0) && (i != j)) {
					if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0)) {
						b[i][j] = b[i][k] + b[k][j];
					}
				}
			}
		}
	}
	for (i = 0; i < dim; i++) {
		cout<<"Minimum Cost With Respect to Node:"<<i<<endl;
		for (j = 0; j < dim; j++) {
			cout<<b[i][j]<<"\t";
		}
	}
}

int main(){
	int b [dim][dim]; 
	//llenar la matriz de 0
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			b[i][j] = 0;
		}
	}
	//llenar la matris con los costos originales, el valor 500 representa el infinito
	b[0][1] = 5;
	b[0][2] = 500;
	b[0][3] = 6;
	b[0][4] = 500;
	b[1][0] = 500;
	b[1][2] = 1;
	b[1][3] = 500;
	b[1][4] = 7;
	b[2][0] = 3;
	b[2][1] = 500;
	b[2][3] = 4;
	b[2][4] = 500;
	b[3][0] = 500;
	b[3][1] = 500;
	b[3][2] = 2;
	b[3][4] = 3;
	b[4][0] = 2;
	b[4][1] = 500;
	b[4][2] = 500;
	b[4][3] = 5;
	floyds(b);
	cout<<"\n";
	return 0;
}
