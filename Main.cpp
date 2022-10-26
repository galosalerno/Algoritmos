#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <vector>
using namespace std;

class Terminal
{
private:
    string codigo;
    string nombre;
    string provincia;
    string pais;
    float superficie;
    int cantidadTerminales;
    int destinosNacionales;
    int destinosInternacionales;

    void metodoPrivado() { cout << "Llamada privada dentro de la clase\n"; }

public:
    // Constructor sin argumentos
    Terminal()
    {
        cout << "Se llama al constructor sin argumentos\n";
        this->metodoPrivado();
    }
    // Constructor
    Terminal(string codigo, string nombre, string provincia, string pais, float superficie, int cantidadTerminales, int destinosNacionales, int destinosInternacionales)
    {
        this->codigo = codigo;
        this->nombre = nombre;
        this->provincia = provincia;
        this->pais = pais;
        this->superficie = superficie;
        this->cantidadTerminales = cantidadTerminales;
        this->destinosNacionales = destinosNacionales;
        this->destinosInternacionales = destinosInternacionales;
    }

    string getCodigo() { return this->codigo; }
    void setCodigo(string codigo) { this->codigo = codigo; }
    string getNombre() { return this->nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }
    string getProvincia() { return this->provincia; }
    void setProvincia(string provincia) { this->provincia = provincia; }
    string getPais() { return this->pais; }
    void setPais(string pais) { this->pais = pais; }
    float getSuperficie() { return this->superficie; }
    void setSuperficie(float superficie) { this->superficie = superficie; }
    int getCantidadTerminales() { return this->cantidadTerminales; }
    void setCantidadTerminales(int cantidadTerminales) { this->cantidadTerminales = cantidadTerminales; }
    int getDestinosNacionales() { return this->destinosNacionales; }
    void setDestinosNacionales(int destinosNacionales) { this->destinosNacionales = destinosNacionales; }
    int getDestinosInternacionales() { return this->destinosInternacionales; }
    void setDestinosInternacionales(int destinosInternacionales) { this->destinosInternacionales = destinosInternacionales; }

    void saludar()
    {
        cout << "Soy la tarminal " << this->nombre << " y mi codigo es "
             << this->codigo << "\n";
    }
};

class AgenciaDeViajes
{
    void metodoPrivado() { cout << "Llamada privada dentro de la clase\n"; }

public:
    // Constructor sin argumentos
    AgenciaDeViajes()
    {
        cout << "Se llama al constructor sin argumentos\n";
        this->metodoPrivado();
    }
    void bajaEstacion(int count, string arr[])
    {
        // HARCODEADO hasta que pasemos todo a clases/struct
        string terminalABorrar = "RET Terminal_de_Retiro Argentina 35 4 12 46";
        // Creamos un archivo donde nos guardamos el nuevo archivo sin el elemento eliminado.
        ofstream archivoAux;
        archivoAux.open("elementoBorrado.txt", ios::out);
        if (archivoAux.fail())
        {
            cout << "No anda";
        }
        // Guardamos todas las terminales en el archivo auxiliar menos la que se elimina.
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

        // Obtenemos la cantidad de elementos que va a tener el array.
        while (getline(file, line))
        {
            countAux++;
        }
        // Creamos el array.
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
        string codigo;
        string nombre;
        string provincia;
        string pais;
        float superficie;
        int cantidadTerminales;
        int destinosNacionales;
        int destinosInternacionales;

        cout << "Ingrese el codigo" << endl;
        cin >> codigo;
        cout << "Ingrese el nombre" << endl;
        cin >> nombre;
        cout << "Ingrese la provincia" << endl;
        cin >> provincia;
        cout << "Ingrese el pais" << endl;
        cin >> pais;
        cout << "Ingrese la superficie" << endl;
        cin >> superficie;
        cout << "Ingrese la cantidad de terminales" << endl;
        cin >> cantidadTerminales;
        cout << "Ingrese la cantidad de destinos nacionales" << endl;
        cin >> destinosNacionales;
        cout << "Ingrese la cantidad de destinos internacionales" << endl;
        cin >> destinosInternacionales;

        Terminal nuevaTerminal(codigo, nombre, provincia, pais, superficie, cantidadTerminales, destinosNacionales, destinosInternacionales);

        // Abrimos el archivo
        terminal = nuevaTerminal.getCodigo() + " " + nuevaTerminal.getNombre() + " " + nuevaTerminal.getProvincia() + " " + nuevaTerminal.getPais() + " " + to_string(nuevaTerminal.getSuperficie()) + " " + to_string(nuevaTerminal.getCantidadTerminales()) + " " + to_string(nuevaTerminal.getDestinosNacionales()) + " " + to_string(nuevaTerminal.getDestinosInternacionales());
        string text = "\n" + terminal;
        archivo.open(filename, ios_base::app);
        archivo.write(text.data(), text.size());
        archivo.close();
        cout << "Agregado correctamente";
        return 0;
        ;
    }

    void generateTerminal(string line)
    {

        string delimiter = " ";

        size_t pos = 0;
        string token;
        
        string codigo;
        string nombre;
        string provincia;
        string pais;
        float superficie;
        int cantidadTerminales;
        int destinosNacionales;
        int destinosInternacionales;
        //Lista auxiliar;
        while ((pos = line.find(delimiter)) != string::npos)
        {
            token = line.substr(0, pos);
            //auxiliar.push(token)
            line.erase(0, pos + delimiter.length());
        }
        //auxiliar.push(line)
        //codigo = auxiliar[0];
        //nombre = auxiliar[1]
        //provincia = auxiliar[2]
        //pais = auxiliar[3]
        //superficie = auxiliar[4]
        //cantidadTerminales = auxiliar[5]
        //destinosNacionales = auxiliar[6]
        //destinosInternacionales = auxiliar[7]
        //Terminal terminal(codigo,nombre,provincia,pais,superficie,cantidadTerminales,destinosNacionales,destinosInternacionales);
    }
    void pedirDatos()
    {
        string line;
        vector<string> lines;
        ifstream myfile("terminales.txt");
        Terminal terminal;
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                generateTerminal(line);
            }
            myfile.close();
        }
        else
            cout << "No se puede abrir el archivo";

        for (int i = 0; i < lines.size(); ++i)
        {
            cout << lines[i] << '\n';
        }
    }
    void consultarEstacion()
    {
        string line;
        vector<string> lines;
        ifstream myfile("terminales.txt");
        string code;
        cout << "Ingrese el codigo de la estacion" << endl;
        cin >> code;
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                lines.push_back(line);
            }
            myfile.close();
        }
        else
            cout << "No se puede abrir el archivo";

        for (int i = 0; i < lines.size(); ++i)
        {
            cout << lines[i] << '\n';
        }
    }

    void mostrarMenu()
    {

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

        int cont = 0;
        int numero;
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Consultar por una terminal en particular" << endl;
        cout << "2. Dar de alta una nueva terminal" << endl;
        cout << "3. Dar de baja alguna terminal" << endl;
        cout << "4. Mostrar todas las terminales" << endl;
        cout << "5. Salir" << endl;

        cout << "Ingrese un numero entre 1 y 5 segun desee: ";
        cin >> numero;
        // Ignoramos el salto de linea para que no lo tome ningun 'cin' siguiente.
        cin.ignore();

        switch (numero)
        {
        case 1:
            consultarEstacion();
        case 2:
            altaEstacion();
            break;
        case 3:
            bajaEstacion(count, arr);
            break;
        case 4:
            pedirDatos();
            break;
        case 5:
            cout << "Adios";
            break;
        default:
            cout << "Opcion incorrecta";
            mostrarMenu();
        }
    }

    void leerArchivo()
    {
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
};

int main()
{
    // AgenciaDeViajes agencia;
    // agencia.mostrarMenu();
    //  getch();
    //  bajaEstacion(count, arr);
    //  altaEstacion();
}
