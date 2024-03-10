#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Estudiante {
    int CU; 
    string apellido;
    string nombre;
    int edad;
    char genero;
    bool asistencia[3];
    string asignatura[1];   
 
};

const int MAX_ESTUDIANTES = 10;
Estudiante listaEstudiantes[MAX_ESTUDIANTES];
int numEstudiantes = 0;

// Introducir Datos de los estudiantes
void IntroducirEstudiante() {
    if (numEstudiantes < MAX_ESTUDIANTES) {
        Estudiante nuevoEstudiante;
        cout << "Ingrese el CU: "; 
        cin >> nuevoEstudiante.CU; 
        cout << "Ingrese el apellido: ";
        cin >> nuevoEstudiante.apellido;
        cout << "Ingrese el nombre: ";
        cin >> nuevoEstudiante.nombre;
        cout << "Ingrese la edad: ";
        cin >> nuevoEstudiante.edad;
        cout << "Ingrese el género (M/F): ";
        cin >> nuevoEstudiante.genero;

        // Ingresa la asignaturas 
        for (int i = 0; i < 1; i++) {
            cout << "Ingrese la asignatura " << i + 1 << ": ";
            cin >> nuevoEstudiante.asignatura[i];
        }

        // Inicia la lista de asistencia en falso (ningún día asistido)
        for (int i = 0; i < 3; i++) {
            nuevoEstudiante.asistencia[i] = false;
        }

        listaEstudiantes[numEstudiantes] = nuevoEstudiante;
        numEstudiantes++;

        cout << "Estudiante agregado con exito." << endl;
    }
    else {
        cout << "La lista de estudiantes esta llena." << endl;
    }
}

// Mostrar toda la lista de Estudiantes
void mostrarTodosLosEstudiantes() {
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "CU: " << listaEstudiantes[i].CU << endl; // Cambiamos ID por CU
        cout << ", Apellido: " << listaEstudiantes[i].apellido << endl;
        cout << ", Nombre: " << listaEstudiantes[i].nombre << endl;
        cout << ", Edad: " << listaEstudiantes[i].edad << endl;
        cout << ", Genero: " << listaEstudiantes[i].genero << endl;
        cout << "Asistencia: ";
        for (int j = 0; j < 3; j++) {
            if (listaEstudiantes[i].asistencia[j]) {
                cout << "Dia " << j + 1 << ": Asistio ";
            }
            else {
                cout << "Dia " << j + 1 << ": No asistio ";
            }
        }
        cout << endl;
    }
}

// Mostramos si existe o no un determinado Estudiante.
bool estudianteExiste(int CUEstudiante) { 
    for (int i = 0; i < numEstudiantes; i++) {
        if (listaEstudiantes[i].CU == CUEstudiante) { 
            return true;
        }
    }
    return false;
}

// Eliminamos un determinado Estudiante
void eliminarEstudiante(int CUEstudiante) { 
    for (int i = 0; i < numEstudiantes; i++) {
        if (listaEstudiantes[i].CU == CUEstudiante) {
            for (int j = i; j < numEstudiantes - 1; j++) {
                listaEstudiantes[j] = listaEstudiantes[j + 1];
            }
            numEstudiantes--;
            cout << "Estudiante eliminado con éxito." << endl;
            return;
        }
    }
    cout << "No se encontró ningún estudiante con ese CU." << endl;
}

/*Mostramos la asignatura si se conoce el CU */
void mostrarAsignatura(int CUEstudiante) { 
    for (int i = 0; i < numEstudiantes; i++) {
        if (listaEstudiantes[i].CU == CUEstudiante) { // 
            cout << "Asignatura con CU " << CUEstudiante << ":" << endl;
            for (int j = 0; j < 1; j++) {
                cout << "Asignatura: " << listaEstudiantes[i].asignatura[j] << endl;
            }
            return;
        }
    }
    cout << "No se encontró ningún estudiante con ese CU." << endl; 
}

// Asistencia de un estudiante en 3 dias
void editarAsistencia(int CUEstudiante, int dia) {
    for (int i = 0; i < numEstudiantes; i++) {
        if (listaEstudiantes[i].CU == CUEstudiante) {
            cout << "Ingrese la asistencia para el día " << dia << " (1 para asistio, 0 para no asistio): ";
            cin >> listaEstudiantes[i].asistencia[dia - 1]; 
            cout << "Asistencia actualizada." << endl;
            return;
        }
    }
    cout << "No se encontró ningún estudiante con ese CU." << endl;
}

int main() {
    int opcion;

    do {
        system("pause");
        system("cls");

        cout << "1. Agregar Estudiante" << endl;
        cout << "2. Mostrar Todos los Estudiantes" << endl;
        cout << "3. Eliminar un Estudiante" << endl;
        cout << "4. Verificar Existencia de un Estudiante" << endl;
        cout << "5. Mostrar Asignatura de un Estudiante" << endl;
        cout << "6. Editar Asistencia" << endl;

        // Implementa las demás opciones del menú aquí
        cout << "0. Salir" << endl;
        cout << "Ingrese su eleccion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            IntroducirEstudiante();
            break;
        case 2:
            mostrarTodosLosEstudiantes();
            break;
        case 3:
            int CUEstudiante; 
            cout << "Ingrese el CU del estudiante a eliminar: "; 
            cin >> CUEstudiante;
            eliminarEstudiante(CUEstudiante); 
            break;
        case 4:
            cout << "Ingrese el CU del estudiante: "; 
            cin >> CUEstudiante; 
            if (estudianteExiste(CUEstudiante)) { 
                cout << "El estudiante existe en la lista." << endl;
            }
            else {
                cout << "El estudiante no existe en la lista." << endl;
            }
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "Ingrese el CU del estudiante: "; 
            cin >> CUEstudiante; 
            mostrarAsignatura(CUEstudiante); 
            break;
        case 6:
            cout << "Ingrese el CU del estudiante: ";
            cin >> CUEstudiante;
            int dia;
            cout << "Ingrese el día para editar la asistencia (1, 2 o 3): ";
            cin >> dia;
            if (dia >= 1 && dia <= 3) {
                editarAsistencia(CUEstudiante, dia);
            }
            else {
                cout << "Día inválido." << endl;
            }
            break;
        case 0:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción inválida." << endl;
            system("pause");
            system("cls");
        }

    } while (opcion != 0);

    return 0;
}