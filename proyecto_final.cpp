/*
* Hilda Beltrán Acosta 
* A01251916
* Disponibilidad Hospital
* 
* Incluye hospital.h y departamento.h
*/
#include <iostream>
#include "hospital.h"
#include "departamento.h"
 
using namespace std;

int main(){
    Hospital hospital1("XC45", "CIMA", "Blvd. Encinas", "6622916400");
    hospital1.bienvenida();
    hospital1.genera_ejemplos();

    while(true){
        int opcion;
        cout << "\nSeleccione una de las siguientes opciones" << endl << endl <<
        "1. Consultar disponibilidad" << endl << "2. Agregar pacientes" << endl
        << "3. Quitar pacientes" << endl << "4. Salir del programa" << endl <<
        endl;

        cin >> opcion;

        if(opcion == 1){
            cout << "\nDepartamento: "; string tipo; cin >> tipo;
            cout << endl << "La disponibilidad es de un " << 
            hospital1.consulta_capacidad(tipo) << "%" << " en " << tipo
            << endl;
        }
        else if(opcion == 2){
            cout << "Departamento: "; string tipo; cin >> tipo;
            cout << "Descripción: "; string sintoma; cin >> sintoma;
            hospital1.actualiza_pacientes(tipo, "1", 1, sintoma);
        }
        else if(opcion == 3){
            cout << "Departamento: "; string tipo; cin >> tipo;
            cout << "Descripción: "; string sintoma; cin >> sintoma;
            hospital1.actualiza_pacientes(tipo, "2", 1, sintoma);
        }
        else if(opcion == 4){ break;}
    }
}