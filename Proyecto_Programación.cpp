//khristian lima 28.372.514
//Carlos Ruiz 30.663.314
//Carlos Belmonte 31.722.091
//Fabiola Andrade 31.209.874
//Oliver Garcia 32.396.121
//Luis Lira 31.564.286
//Keiber Acero 32.589.206
//Orlianis Garcia 31.855.788

#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct Estudiante {
    string nombre, apellido;
	float nota; 
    bool presente; // true = Asistió, false = Faltó
};

//--Funcion para guardar datos en un archivo TXT--
void guardarDatos(const vector<Estudiante>& lista) {
	ofstream archivo("estudiantes.txt"); //Crea o sobrescribe el archivo
	if (archivo.is_open()) {
		for(size_t i=0;i<lista.size();i++) {
		//guarda Nombre apellido nota y asistencia
			archivo << lista[i].nombre << " " << lista [i].apellido << "\t|Nota: " << lista [i].nota << "\t| " << (lista [i].presente ? "Asistente" : "Inasistente") << endl;
		}
			archivo.close();
			cout << "\n---Datos guardados correctamente en estudiantes.txt ---" << endl;
		} else {
			cout << "\nError al guardar el archivo." << endl;
		}
}

//-- Funcion para cargar datos del archivo TXT--
void cargarDatos(vector<Estudiante>& lista) {
	ifstream archivo("estudiantes.txt");// Abre el archivo para la lectura
	if (archivo.is_open()) {
		Estudiante est;
		//lee en el mismo orden que guardo
		while (archivo >> est.nombre >> est.apellido >> est.nota >> est.presente) {
			lista.push_back(est);
		}
		archivo.close();
	}
}

//Recursividad para calcular las asistencias
int calcularAsistenciasRecursivo(const vector<Estudiante>& lista, int indice) {
    if (indice == (int)lista.size()) {
        return 0;
    }
    int actual = (lista[indice].presente) ? 1 : 0;
    return actual + calcularAsistenciasRecursivo(lista, indice + 1);
}

int main(){
	vector<Estudiante> lista;
	cargarDatos(lista);
	int numeroEstudiantes;
	int cantidadNuevos;
	char opcion,asistencia;
	
	cout << "\tSistema de Control de estudiantes en un Taller" << endl;
		//Mostrar estado actual
	if(!lista.empty()) {
		cout << "\nSe han cargado [" << lista.size() << "] Estudiantes guardados anteriormente." << endl;
		cout << "-Desea ingresar nuevos estudiantes adicionales? S/N: ";
		cin >> opcion;
	} else {
	cout <<"\nNo se poseen datos de estudiantes, desea ingresarlos? S/N: ";
	cin >> opcion;
	
	while(opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N'){
			
			cout << "\nPor favor ingrese una opcion valida (S o N): ";
            cin >> opcion;
		}
	}
	if(opcion=='S'||opcion=='s'){
	
		cout<<"\n-Cuantos estudiantes desea ingresar al sistema? (indique el numero de estudiantes):";
	
	while(!(cin>> cantidadNuevos)||cantidadNuevos< 0){
		cout<<"\nERROR:Por favor no ingresar letras ni numeros negativos. Ingrese nuevamente el numero:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
		//--redimensionamos el vector conservado los que ya estaban--
		int tamanoAnterior = lista.size();
		lista.resize(tamanoAnterior + cantidadNuevos);

		//registro de estudiantes y notas
		// el ciclo comienza desde el ultimo que estaba guardado
		for(int i = tamanoAnterior; i < (tamanoAnterior + cantidadNuevos); i++){
			
			cout << "\nIngrese el primer nombre del estudiante numero " << i+1 << ": ";
			cin >> lista[i].nombre;
			cout << "Ingrese el apellido del estudiante numero " << i+1 << ": ";
			cin >> lista[i].apellido;
			
			cout << "El estudiante esta asistio? S/N: ";
			cin >> asistencia;
			while(asistencia != 's' && asistencia != 'S' && asistencia != 'n' && asistencia != 'N'){
			
				cout << "\nPor favor ingrese una opcion valida (S o N): ";
           		cin >> asistencia;
			}
			lista[i].presente = (asistencia == 's' || asistencia == 'S');
			
			cout << "Ingrese la nota del estudiante numero " << i+1 << ": ";
			while(!(cin >> lista[i].nota) || lista[i].nota > 20 || lista[i].nota < 0){
				
				cout<<"\nERROR: Por favor coloque una nota entre 0 y 20, sin letras. Ingrese nuevamente la nota: ";
				cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}
		//---Actualiza la variable numeroEstudiantes al total real---
		numeroEstudiantes = lista.size();
		
	if(numeroEstudiantes > 0) {
		float suma = 0;
		
		for(int i = 0; i< numeroEstudiantes; i++){
	
			suma = suma + lista[i].nota;
		}
		
			float promedio =suma /numeroEstudiantes;
		
		cout << "\nEl promedio de notas es: " << promedio << endl;

		//Llamada de la recursividad
		int totalAsistencias = calcularAsistenciasRecursivo(lista, 0);
    	cout << "Total de estudiantes que asistieron: " << totalAsistencias << endl;
		
		// Opcion para buscar estudiante.
		char deseaBuscar;
        cout << "\n¿Desea buscar algun estudiante en particular? S/N: ";
        cin >> deseaBuscar;

        if (deseaBuscar == 's' || deseaBuscar == 'S') {
            char buscarOtraVez;
            do {
                string nombreBusqueda;
                bool encontrado = false;

                cout << "\n--- BUSCAR ESTUDIANTE ---" << endl;
                cout << "Ingrese el nombre del estudiante que desea buscar: ";
                cin >> nombreBusqueda;

                for(int i = 0; i < numeroEstudiantes; i++) {
                    if(lista[i].nombre == nombreBusqueda) {
                        cout << "\n¡Estudiante encontrado!" << endl;
                        cout << "Nombre completo: " << lista[i].nombre << " " << lista[i].apellido << endl;
                        cout << "Nota: " << lista[i].nota << endl;
                        cout << "Asistencia: " << (lista[i].presente ? "Asistio" : "Falto") << endl;
                        encontrado = true;
                        break; 
                    }
                }

                if(!encontrado) {
                    cout << "\nNo se encontro ningun estudiante con el nombre: " << nombreBusqueda << endl;
                }

                cout << "\n¿Desea buscar otro estudiante? (S para buscar / N para salir): ";
                cin >> buscarOtraVez;

            } while(buscarOtraVez == 's' || buscarOtraVez == 'S');
        }
		//Guardamos toda la lista antes de salir
		guardarDatos(lista);
	}
		else{
			cout << "\nNo hay datos para procesar ni guardar" << endl;
		}

	cout<<"\n\nHasta luego, que tenga buen dia";
return 0;
}
