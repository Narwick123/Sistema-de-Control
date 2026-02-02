//khristian lima 28.372.514
//Carlos Ruiz 30.663.314
//Carlos Belmonte 31.722.091
//Fabiola Andrade 31.209.874
//Luis Lira 31.564.286

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

//Recursividad para calcular las asistencias
int calcularAsistenciasRecursivo(const vector<Estudiante>& lista, int indice) {
    if (indice == (int)lista.size()) {
        return 0;
    }
    int actual = (lista[indice].presente) ? 1 : 0;
    return actual + calcularAsistenciasRecursivo(lista, indice + 1);
}

int main(){
	int numeroEstudiantes;
	char opcion,asistencia;
	
	cout << "\tSistema de Control de estudiantes en un Taller" << endl;
	cout <<"\nNo se poseen datos de estudiantes, desea ingresarlos? S/N: ";
	cin >> opcion;
	
	while(opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N'){
			
			cout << "\nPor favor ingrese una opcion valida (S o N): ";
            cin >> opcion;
		}
	if(opcion=='S'||opcion=='s'){
	
		cout<<"\n¿Cuantos estudiantes desea ingresar al sistema? (indique el numero de estudiantes):";
	
	while(!(cin>>numeroEstudiantes)||numeroEstudiantes < 0){
		cout<<"\nERROR:Por favor no ingresar letras ni numeros negativos. Ingrese nuevamente el numero:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	vector<Estudiante> lista(numeroEstudiantes); //Se utiliza para crear una lista dinámica de estudiantes basada en la cantidad ingresada.
		
		// Registro de estudiantes y sus notas.
		for(int i = 0; i < numeroEstudiantes; i++){
			
			cout << "\nIngrese el nombre del estudiante numero " << i+1 << ": ";
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

        // Al terminar la búsqueda o si dijo que "No", el programa llega aquí y se despide.
	cout<<"\n\nHasta luego, que tenga buen dia";
}
return 0;
}
