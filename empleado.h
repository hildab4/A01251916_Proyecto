//Hilda Beltrán Acosta A01251916
#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>

using namespace std;

class Empleado{
    private:
        string idEmpleado, nombreEmpleado, hospitalEmpleado;
    
    public:
        string get_id(){ return idEmpleado;}
        string get_nombre(){ return nombreEmpleado;}
        string get_hospital(){ return hospitalEmpleado;}
        Empleado(string id, string nombre, string hospital);
        void bienvenida();
};

Empleado::Empleado(string id, string nombre, string hospital){
    idEmpleado = id;
    nombreEmpleado = nombre;
    hospitalEmpleado = hospital;
}

void Empleado::bienvenida(){
    cout << "Hola " << nombreEmpleado << "!" << endl;
}

#endif