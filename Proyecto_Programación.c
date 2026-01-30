//khristian lima 28.372.514
#include <iostream>
#include <limits>
using namespace std;

int main(){
	int numeroEstudiantes;
	char opcion;
	
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
		count<<"\nERROR:Por favor no ingresar letras ni numeros negativos. Ingrese nuevamente el numero:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
}else{
	cout<<"\n\nHasta luego, que tenga buen dia";
}
return 0;
}
