#include "imagen.h"

//funcion que carga la imagen especificada
imagen cargarImg(string nombre) {
    imagen img;
    string temp;
    ifstream archivo(nombre);					//abre el archivo con el nombre especificado
    if (archivo.is_open()) {
        getline(archivo, img.codigo);
        archivo >> temp;
        while (temp[0] == '#') {				//salta las lineas comentadas
            getline(archivo, temp);
            archivo >> temp;
        }
        img.W = stoi(temp);
        archivo >> img.H;					//informacion de dimenciones
        archivo >> img.M;

        for (int i = 0; i < img.H; i++) {
            img.val.emplace_back(vector<int>());		//inicializa un vecor en el vector anidado
            for (int j = 0; j < img.W; j++) {
                archivo >> temp;
                img.val[i].push_back(stoi(temp));		//introduce los valores de cada linea en el vector correspondiente
            }
        }
    }
    archivo.close();
    return img;
}

//funcion que carga un volumen de imagenes
volumen cargarVol(string nombre_base, int n) {
    volumen vol;
    vol.n_im = n;
    for (int i = 1; i <= n; i++) {
        string nombre = nombre_base + (n < 10 ? "0" : "") + to_string(i) + ".ppm";
        imagen img = cargarImg(nombre);
        vol.imgv.push_back(img);				//llena el vector de el volumen con las imagenes
        vol.H = img.H;
        vol.W = img.W;
    }
    return vol;
}

//funcion que guarda el resultado de la proyeccion como archivo pmg
void guardarPGM(imagen img, string nombre_archivo) {
    ofstream archivo(nombre_archivo);
    if (archivo.is_open()) {
        archivo << img.codigo << endl;
        archivo << img.W << " " << img.H << endl;
        archivo << img.M << endl;
        for (int i = 0; i < img.H; i++) {
            for (int j = 0; j < img.W; j++) {
                archivo << img.val[i][j] << " ";
            }
            archivo << endl;
        }
        archivo.close();
    }
}
