#include <iostream>
#include <fstream>
#include <locale.h> 
#include <cstdlib>
#include <vector>
#include <string>
#include <any>
using namespace std;

struct terminal{
    string codigo;
    string nombre; 
    string ciudad;
    string pais; 
    string superficie;
    string cantidad_terminales; 
    string destinos_nacionales;
    string destinos_internacionales;

    void asignar_codigo(string value){
        codigo = value;
    }
    void asignar_nombre(string value){
        nombre = value;
    }
    void asignar_ciudad(string value){
        ciudad = value;
    }
    void asignar_pais(string value){
        pais = value;
    }
    void asignar_superficie(string value){
        superficie = value;
    }
    void asignar_cant_terminales(string value){
        cantidad_terminales = value;
    }
    void asignar_destinos_nacionales(string value){
        destinos_nacionales = value;
    }
    void asignar_internacionales(string value){
        destinos_internacionales = value;
    }
};

void writeFile(string nombreArchivo){
    ofstream archivo;
    // Abrimos el archivo
    archivo.open(nombreArchivo.c_str(), fstream::out);
    // Y le escribimos redirigiendo
    archivo << "dato a ingresar";
    // Finalmente lo cerramos
    archivo.close();
}


void readFile(string nombreArchivo){
    string linea;
    ifstream archivoLecutra(nombreArchivo.c_str());
    // Obtener línea de archivo, y almacenar contenido en "linea"
    terminal ter;
    while (getline(archivoLecutra, linea)) {
        vector<char> v(linea.begin(), linea.end());
        cout << "Linea : " << linea <<endl;
        string actual;
        for (int i = 0; i <= v.size(); i++) {
            if(v[i] == ' '){
                if(i == 0){
                    ter.codigo = actual;
                }else if(i == 1){
                    ter.nombre =  actual;
                }
                
                actual = "";
            }
            actual = actual + v[i];
        }
    }
    cout << "Codigo " << ter.codigo <<endl;
    cout << "Nombre " << ter.nombre <<endl;
}

int main() {
    setlocale(LC_ALL, ""); //Usar acentos (?)
    int nAtletas, mayor=0, posMayor=0;

    string nombreArchivo = "terminales.txt";
	readFile(nombreArchivo);
}

// int main()
// {
    // string s = "Hello World!";
//  
    // vector<string> v(s.begin(), s.end());
//  
    // for (const string &c: v) {
        // cout << c << endl;
    // }
//  
    // return 0;
// }