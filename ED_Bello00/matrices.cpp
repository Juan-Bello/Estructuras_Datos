/************************
*Fecha: 29 enero 2025
*Autor: Juan Bello
*Materia: Estructuras de datos
*Topico: programacion modular y complejidad de algoritmos
*Pontificia Universidad Javeriana
************************/

#include <iostream>

using namespace std;


//funcion para inicializar las matrices
void iniMatriz(int **a,int **b,int **c,int n){
	for(int i=0;i<n;i++){
		a[i] = new int [n];
		b[i] = new int [n];
		c[i] = new int [n];
	}

	for(int i = 0;i < n;i++){
		for(int j=0;j<n;j++){
			a[i][j] = 2*i;
			b[i][j] = i+j;
			c[i][j] = 0;
		}
	}
}

//funcion para mostrar las matrices
void verMatriz(int **m,string name,int n){
	cout<<"\n \n matriz "<<name<<":"<<endl;
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

int main(){
	int N;
	cout<<"ingrece las dimenciones de la matriz cuadrada: ";
	cin >> N ;

	int **mA = new int *[N];
	int **mB = new int *[N];
	int **mC = new int *[N];

	//se inicia cada matriz
	iniMatriz(mA,mB,mC,N);

	//se multiplican las matrices AxB = C
	multMatriz(mA,mB,mC,N);

	//se imprimen las matrices
	verMatriz(mA,"a",N);
	verMatriz(mB,"b",N);
	verMatriz(mC,"c",N);

	cout<<"\n hola soy juan"<<endl;
	return 0;
}


