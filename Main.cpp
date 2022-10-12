#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <vector>
using namespace std;

// struct terminal{
// string codigo;
// string nombre;
// string ciudad;
// string pais;
// string superficie;
// string cantidad_terminales;
// string destinos_nacionales;
// string destinos_internacionales;
//
// void asignar_codigo(string value){
// codigo = value;
// }
// void asignar_nombre(string value){
// nombre = value;
// }
// void asignar_ciudad(string value){
// ciudad = value;
// }
// void asignar_pais(string value){
// pais = value;
// }
// void asignar_superficie(string value){
// superficie = value;
// }
// void asignar_cant_terminales(string value){
// cantidad_terminales = value;
// }
// void asignar_destinos_nacionales(string value){
// destinos_nacionales = value;
// }
// void asignar_internacionales(string value){
// destinos_internacionales = value;
// }
// };
//
// void writeFile(string nombreArchivo){
// ofstream archivo;
// Abrimos el archivo
// archivo.open(nombreArchivo.c_str(), fstream::out);
// Y le escribimos redirigiendo
// archivo << "dato a ingresar";
// Finalmente lo cerramos
// archivo.close();
// }
//
//
// void readFile(string nombreArchivo){
// string linea;
// ifstream archivoLecutra(nombreArchivo.c_str());
// Obtener línea de archivo, y almacenar contenido en "linea"
// terminal ter;
// while (getline(archivoLecutra, linea)) {
// vector<char> v(linea.begin(), linea.end());
// cout << "Linea : " << linea <<endl;
// string actual;
// for (int i = 0; i <= v.size(); i++) {
// if(v[i] == ' '){
// if(i == 0){
// ter.codigo = actual;
// }else if(i == 1){
// ter.nombre =  actual;
// }
//
// actual = "";
// }
// actual = actual + v[i];
// }
// }
// cout << "Codigo " << ter.codigo <<endl;
// cout << "Nombre " << ter.nombre <<endl;
// }
//

void bajaEstacion(int count, string arr[])
{
    //HARCODEADO hasta que pasemos todo a clases/struct
    string terminalABorrar = "RET Terminal_de_Retiro Argentina 35 4 12 46";
    //Creamos un archivo donde nos guardamos el nuevo archivo sin el elemento eliminado.
    ofstream archivoAux;
    archivoAux.open("elementoBorrado.txt", ios::out);
    if (archivoAux.fail())
    {
        cout << "No anda";
    }
    //Guardamos todas las terminales en el archivo auxiliar menos la que se elimina.
    for (int i = 0; i < count; i++)
    {
        if (terminalABorrar != arr[i])
        {
            archivoAux << arr[i] << endl;
        }
    }
    archivoAux.close();

    string line;
    int countAux = 0;
    ifstream file("elementoBorrado.txt");
    ofstream archivo;
    string nombreArchivo = "terminales.txt";
    archivo.open(nombreArchivo.c_str(), fstream::out);
    
    //Obtenemos la cantidad de elementos que va a tener el array.
    while (getline(file, line))
    {
        countAux++;
    }
    //Creamos el array.
    string arrAux[countAux];
    
    file.clear();
    file.seekg(0, ios::beg);
    for (int i = 0; i < countAux; i++)
    {
        getline(file, arrAux[i]);
        archivo << arrAux[i] << endl;
    }
    archivo.close();
    file.close();
}

int altaEstacion()
{
    string nombreArchivo = "terminales.txt";
    ofstream archivo;
    string filename(nombreArchivo);
    string terminal;
    cout << "Ingrese una nueva terminal" << endl;
    getline(cin,terminal);
    // Abrimos el archivo
    string text = "\n" + terminal;
    archivo.open(filename, std::ios_base::app);
    archivo.write(text.data(), text.size());
    archivo.close();
    cout << "Agregado correctamente";
    return 0;
}

void pedirDatos(){
 	string line;
 	vector<string> lines;
 	ifstream myfile ("terminales.txt");
 	if (myfile.is_open()){
 		while(getline(myfile,line)){
 			lines.push_back(line);
		 }
		myfile.close();
	 }
	else cout<<"No se puede abrir el archivo";
	
	for(int i=0; i<lines.size(); ++i){
		cout<<lines[i]<<'\n';
	} 
 }
 
 void mostrarMenu(){
 	
    string line;
    int count = 0;
    ifstream file("terminales.txt");
    while (getline(file, line))
    {
        count++;
    }
    string arr[count];
    file.clear();
    file.seekg(0, ios::beg);
    for (int i = 0; i < count; i++)
    {
        getline(file, arr[i]);
    }
    file.close();
    
    int cont=0;
    int numero;
 	cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Consultar por una terminal en particular" << endl;
        cout << "2. Dar de alta una nueva terminal" << endl;
        cout << "3. Dar de baja alguna terminal" << endl;
        cout << "4. Mostrar todas las terminales" << endl;
        cout << "5. Salir" << endl;
 	
	cout<<"Ingrese un numero entre 1 y 5 segun desee: "; 
	cin>>numero;
    //Ignoramos el salto de linea para que no lo tome ningun 'cin' siguiente.
    cin.ignore();
	
	switch(numero){
			case 1: 
				break;
			case 2: 
				altaEstacion(); break;
			case 3: 
				bajaEstacion(count,arr); break;
			case 4: 
				pedirDatos(); break;	
			case 5:
				cout<<"Adios"; break;
			default:
				cout<<"Opcion incorrecta";
				mostrarMenu();	
	}	
 }
 

void leerArchivo(){
    string line;
    int count = 0;
    ifstream file("terminales.txt");
    while (getline(file, line))
    {
        count++;
    }
    string arr[count];
    file.clear();
    file.seekg(0, ios::beg);
    for (int i = 0; i < count; i++)
    {
        getline(file, arr[i]);
    }
    file.close();
}


int main()
{
    mostrarMenu();
    // getch();
    //bajaEstacion(count, arr);
    //altaEstacion();
    return 0;
}
