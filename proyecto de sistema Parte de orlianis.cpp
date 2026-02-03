#include <iostream>
#include <limits>
#include <fstream> 
#include <string>
#include <vector>
#include <cctype>
#include <iomanip> 

using namespace std;

struct Estudiante {
    string nombre, apellido;
    float nota;
    bool presente; // true = Asistió, false = Faltó
};


void ingresarEstudiantes(vector<Estudiante>& lista, int cantidad);
void mostrarReporte(const vector<Estudiante>& lista);
void guardarEnArchivo(const vector<Estudiante>& lista);
bool validarSioNo(char &opcion);

int main(){
    int numeroEstudiantes;
    char opcion;

    cout << "\tSistema de Control de Estudiantes (Version Profesional)" << endl;
    cout << "\nNo se poseen datos de estudiantes en memoria, desea ingresarlos? S/N: ";
    cin >> opcion;

    // Validación optimizada usando función auxiliar
    while(!validarSioNo(opcion)){
        cout << "\nPor favor ingrese una opcion valida (S o N): ";
        cin >> opcion;
    }

    if(opcion == 'S' || opcion == 's'){
        
        cout << "\nIndique el numero de estudiantes a ingresar: ";
        // Tu validación original de enteros [cite: 7]
        while(!(cin >> numeroEstudiantes) || numeroEstudiantes < 0){
            cout<<"\nERROR: Por favor no ingresar letras ni numeros negativos. Intente de nuevo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Creación del vector dinámico 
        vector<Estudiante> lista(numeroEstudiantes);

        // 1. Lógica de Negocio: Ingreso de datos
        ingresarEstudiantes(lista, numeroEstudiantes);

        // 2. Visualización: Reporte en consola
        mostrarReporte(lista);

        // 3. Persistencia: Guardado en archivo (LA NUEVA FUNCIÓN)
        guardarEnArchivo(lista);

    } else {
        cout << "\n\nHasta luego, que tenga buen dia!";
    }

    return 0;
}

// --- IMPLEMENTACIÓN DE FUNCIONES ---

void ingresarEstudiantes(vector<Estudiante>& lista, int cantidad) {
    char asistencia;
    for(int i = 0; i < cantidad; i++){
        cout << "\n--- Estudiante " << i+1 << " ---" << endl;
        cout << "Ingrese el nombre: ";
        cin >> lista[i].nombre; // [cite: 11]
        cout << "Ingrese el apellido: ";
        cin >> lista[i].apellido;

        cout << "Asistio a clase? S/N: ";
        cin >> asistencia;
        while(!validarSioNo(asistencia)){
            cout << "\nPor favor ingrese una opcion valida (S o N): ";
            cin >> asistencia;
        }
        lista[i].presente = (asistencia == 's' || asistencia == 'S');

        cout << "Ingrese la nota (0-20): ";
        // Tu validación original de rango y tipo [cite: 16]
        while(!(cin >> lista[i].nota) || lista[i].nota > 20 || lista[i].nota < 0){
            cout<<"\nERROR: Nota invalida (0-20). Ingrese nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void mostrarReporte(const vector<Estudiante>& lista) {
    cout << "\n================ REPORTE DE ASISTENCIA ================\n";
    for(const auto& est : lista) { // Usamos 'const auto&' para eficiencia de memoria
        cout << est.nombre << " " << est.apellido 
             << " | Estado: " << (est.presente ? "Presente" : "Ausente") 
             << " | Nota: " << est.nota << endl;
    }
    cout << "=======================================================\n";
}

// FUNCION MAESTRA: GUARDADO DE ARCHIVO
void guardarEnArchivo(const vector<Estudiante>& lista) {
    char guardar;
    cout << "\n¿Desea guardar estos datos en un archivo de texto? S/N: ";
    cin >> guardar;

    if (guardar == 's' || guardar == 'S') {
        // Usamos ofstream para escritura.
        // ios::app permite añadir al final sin borrar lo anterior.
        ofstream archivo("registro_notas.txt", ios::app); 

        if (archivo.is_open()) {
            archivo << "\n--- Nuevo Registro ---\n";
            for (const auto& est : lista) {
                archivo << "Estudiante: " << est.nombre << " " << est.apellido 
                        << "\n\tAsistencia: " << (est.presente ? "Si" : "No") 
                        << "\n\tNota: " << est.nota << "\n";
            }
            archivo << "----------------------\n";
            archivo.close(); // Siempre cerrar el archivo
            cout << "\n[EXITO] Datos guardados correctamente en 'registro_notas.txt'.\n";
        } else {
            cout << "\n[ERROR] No se pudo crear o abrir el archivo.\n";
        }
    }
}

// Función auxiliar para validar S/N y limpiar código repetitivo
bool validarSioNo(char &opcion) {
    return (opcion == 's' || opcion == 'S' || opcion == 'n' || opcion == 'N');
}