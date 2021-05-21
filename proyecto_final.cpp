//Hilda Beltrán Acosta A01251916
#include <iostream>
#include "hospital.h" //Objetos a utilizar en el programa

using namespace std;

int main(){
    //Se crean objetos en diferentes clases, con sus atributos
    Empleado empleado1("A01251916", "Hilda Beltrán", "XC26");
    Hospital hospital("GY38", "Hosp", "Blvd. Obregón", "1234567891", "2500");
    Covid hospital1("XC26", "Hosp1", "Blvd. Encinas", "6622916400", "4000", 
    "100");
    Urgencias hospital2("TC49", "Hosp2", "Blvd. Colosio", "1234567890", "3000",
     "200");
    cout << "\nclave" << "\t nombre" << "\t    dirección" << "\t\t teléfono" <<
    "\t capacidad" << endl;
    hospital1.muestra_hospitales();
    hospital2.muestra_hospitales();
    cout << "\nPorcentaje de ocupación " << hospital1.get_nombre() << ": " <<
    hospital1.porcentaje_ocupacion() << "%" << endl;
    cout << "\n¿Cuántos pacientes quiere agregar?" << endl; int numero;
    cin >> numero; int *num = &numero;
    hospital1.agregar_pacientes(num);
    cout << "\n¿Cuántos pacientes quiere quitar?" << endl; int numero1;
    cin >> numero1; int *num1 = &numero1;
    hospital1.quitar_pacientes(num1);
    cout << "\nPorcentaje de ocupación " << hospital1.get_nombre() << ": " <<
    hospital1.porcentaje_ocupacion() << "%" << endl;
    cout << "\nDirección hospital " << hospital1.get_nombre() << ": " << 
    hospital1.consulta_direccion() << endl; 
    cout << "\nTeléfono hospital " << hospital2.get_nombre() << ": " <<
    hospital2.consulta_telefono() << "\n" << endl; 
    empleado1.bienvenida();
    cout << "\nLa clave del hospital donde trabaja es: " << 
    empleado1.get_hospital() << endl;
    cout << "\nLa capacidad del hospital " << hospital.get_nombre() << 
    " es de: " << hospital.consulta_capacidad() << endl;
    cout << "\nLa capacidad para Covid del hospital " << hospital1.get_nombre()
    << " es de: " << hospital1.consulta_capacidad() << endl;
}