//khristian lima 28.372.514
//Carlos Ruiz 30.663.314
//Carlos Belmonte 31.722.091

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

}else{
	cout<<"\n\nHasta luego, que tenga buen dia";
}
return 0;
}
