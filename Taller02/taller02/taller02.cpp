/* ************************************ *
 * Fecha: 24 de febrero de 2025		*
 * Autor: Juan Esteban Bello Durango	*
 * Materia: Estructuras de datos	*
 * Pontificia Universidad Javeriana	*
 * ************************************ */

#include<iostream>
#include<fstream>
#include<stack>
#include<list>
using namespace std;

string reverso(string s);
stack<string> separaPalab(string linea);

int main(int argc, char **argv){

	int n = 1;
	string nlin,linea,sub;
	
	stack<string> palabras;				//stack que contendra las palabras de cada linea
	list<string> resini,rescon,resrev;		//listas que contendran las palabras que inicien (resini) o contengan (rescon) 
							//la subcadena, o contengan la subcadena revertida (resrev)

	ifstream archivo(argv[1]);			//abre el archivo indicado por el segundo argumento
	getline(archivo,nlin);
	getline(archivo,sub);

	if(archivo.is_open()){
		while(getline(archivo,linea)){						//bucle que se repite por cada linea del archivo

			//separa las lineas del archivo por palabra y las almacena en un stack
			palabras = separaPalab(linea);
			//determina si las palabras almacenadas en el stack inician, contienen o contienen en reverso la subcadena
			while(!palabras.empty()){
				//deternima si inicia o contiene la sub cadena
				int res = palabras.top().find(sub);
				if(res!=string::npos){
					if(res == 0){
						resini.push_back("Linea " + to_string(n) + ": " + palabras.top());	//guarda linea y palabra en resini
					}else
						rescon.push_back("Linea " + to_string(n) + ": " + palabras.top());	//guarda linea y palabra en rescon
				}
			
				//determina si contiene la subcadena invertida
				res = palabras.top().find(reverso(sub));
				if(res!=string::npos){
					resrev.push_back("Linea " + to_string(n) + ": " + palabras.top());		//guarda linea y palabra en resrev
				}

				palabras.pop();

			}
			n++;					//aumeta el contador de linea
		}
		
		//imprime el contenido de las listas
		cout<<"se encontraron "<<resini.size()<<" palabras que inician por "<<sub<<endl;
		for(string s : resini)
			cout<<s<<endl;
		cout<<"\nse encontraron "<<rescon.size()<<" palabras que contienen "<<sub<<endl;
		for(string s : rescon)
			cout<<s<<endl;
		cout<<"\nse encontraron "<<resrev.size()<<" palabras que contienen "<<reverso(sub)<<endl;
		for(string s : resrev)
			cout<<s<<endl;
		
		archivo.close();

	}
	else
		cout<<"no fue posible abrir el archivo\n";


	return 0;
}

//funcion que separa las lineas del archivo por palabra y las almacena en un stack
stack<string> separaPalab(string linea){
	stack<string> palabras;	
	size_t ini = 0, fin; 						//variables de posicion inicial y final
	
	while((fin = linea.find(' ',ini)) != string::npos){	
		palabras.push(linea.substr(ini, fin-ini));
		ini = fin + 1;
	}
	palabras.push(linea.substr(ini, fin-ini));
	return palabras;
}

//funcion que revierte un string
string reverso(string s){
	stack<char> st;

	for(char c : s)
		st.push(c);
	
	s.clear();

	while(!st.empty()){
		s.push_back(st.top());
		st.pop();
	}

	return s;
}
