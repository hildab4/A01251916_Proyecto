//Hilda Beltrán Acosta A01251916
#include <iostream>
#include "hospital.h"

using namespace std;

int main(){
    Hospital hospital1("XC45", "CIMA", "Blvd. Encinas", "6622916400");
    hospital1.bienvenida();
    hospital1.genera_ejemplos();
    cout << "Actualizado Covid\n" << hospital1.consulta_capacidad("Covid") <<
    "%  disponible\n" << endl;
    hospital1.actualiza_pacientes("Covid", "1", 15);
    cout << "Actualizado Covid\n" << hospital1.consulta_capacidad("Covid") << 
    "%  disponible\n" << endl;
    cout << "Actualizado General\n" << hospital1.consulta_capacidad("General") << 
    "%  disponible\n" << endl;
    hospital1.actualiza_pacientes("General", "2", 15);
    cout << "Actualizado General\n" << hospital1.consulta_capacidad("General") << 
    "%  disponible\n" << endl;
}