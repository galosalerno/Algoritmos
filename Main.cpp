#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include <conio.h>
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
void altaEstacion(){
    string nombreArchivo = "terminales.txt";
    ofstream archivo;
    string filename(nombreArchivo);
    string terminal;
    cout << "Ingrese una nueva terminal" << endl;
    getline(cin, terminal);
    // Abrimos el archivo
    string text = "\n"+terminal;
    archivo.open(filename, std::ios_base::app);
    archivo.write(text.data(),text.size());
    archivo.close();
	cout << "Agregado correctamente";
}
int main () { 
    altaEstacion();
    //string line; 
    //int count = 0; 
//
    //ifstream file("terminales.txt"); 
//
    //while (getline(file, line)) {
//
    //    count++; 
    //}
    //string arr[count]; 
//
    //file.clear(); 
    //file.seekg(0, ios::beg); 
//
    //for (int i=0; i<count; i++) {
//
    //    getline(file, arr[i]); 
    //    }
    //file.close(); 
//
    //for (int i=0; i<count; i++) {
//
    //    cout << arr[i]<<endl;
    //}
//
    //getch();
    return 0;
}




