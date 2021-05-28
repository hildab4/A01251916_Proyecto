//Hilda Beltrán Acosta A01251916
#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <iostream>
#include "departamento.h"
 
using namespace std;

class Hospital{
    private:
        string clave, nombre, direccion, telefono;
        Departamento * depto[4];
    public:
        //getters para los atributos privados
        string get_clave(){ return clave;}
        string get_nombre(){ return nombre;}
        string get_direccion(){ return direccion;}
        string get_telefono(){ return telefono;}
        //Constructor por default
        Hospital(): clave(""), nombre(""), direccion(""), telefono("") {};
        //Sobrecarga del constructor por default
        Hospital(string c, string n, string d, string t);
        void genera_ejemplos();
        void bienvenida();
        void actualiza_pacientes(string t, string opc, int num);
        float consulta_capacidad(string t);
};

//Constructor
Hospital::Hospital(string c, string n, string d, string t){
    clave = c;
    nombre = n;
    direccion = d;
    telefono = t;
}

void Hospital::bienvenida(){
    cout << "\n\nBienvenido al hospital " << nombre << "!" << endl << "Clave: " << 
    clave << endl << "Dirección: " << direccion << endl << "Teléfono: " <<
    telefono << endl << endl << endl;
}

//Crea ejemplos dentro del arreglo de clase Departamento
void Hospital::genera_ejemplos(){
    int i = 0;
    depto[i] = new Covid("Covid", "Norte", "1000", "284", "Fiebre");
    i ++;
    depto[i] = new Urgencias("Urgencias", "Sur", "100", "47", "Convulsiones");
    i ++;
    depto[i] = new Quirofano("Quirofano", "Este", "78", "21", "Dra. Azul");
    i ++;
    depto[i] = new General("General", "Oeste", "2500", "2345", "1234");
    i ++;
} 

//Recorre el arreglo buscando coincidencia en el tipo de departemento
//Llama a la función para agregar o quitar dependiendo de la opción seleccionada
void Hospital::actualiza_pacientes(string t, string opc, int num){
    if(opc == "1"){
        for(int i = 0; i < sizeof(depto)/sizeof(depto[0]); i ++){
            if(depto[i] -> get_tipo() == t){
                depto[i] -> agregar_pacientes(num);
            }
        }
    }
    else if(opc == "2"){
        for(int i = 0; i < sizeof(depto)/sizeof(depto[0]); i ++){
            if(depto[i] -> get_tipo() == t){
                depto[i] -> quitar_pacientes(num);
            }
        }
    }
}

//Recorre el arreglo buscando coincidencia en el tipo de departemento
//Calcula el porcentaje de espacios libres
float Hospital::consulta_capacidad(string t){
    for(int i = 0; i < sizeof(depto)/sizeof(depto[0]); i ++){
        if(depto[i] -> get_tipo() == t){
            return depto[i] -> porcentaje_ocupacion();
        }
    }
    return 0;
}

#endif