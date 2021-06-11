/*
* Hilda Beltrán Acosta 
* A01251916
* Disponibilidad Hospital
* 
* Incluye departamento.h
*/
#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <iostream>
#include "departamento.h"
 
using namespace std;

/*
 * Dentro de esta clase se define el objeto de tipo Departamento, donde se
 * crean los objetos de las clases heredadas por la clase abstracta 
 * Departamento. Aquí se mandan a llamar a las funciones para calcular las
 * capacidades para cada departamento del hospital, de igual manera se agregan
 * y quitan pacientes de las secciones.
*/
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
        void actualiza_pacientes(string t, string opc, int num, string s);
        float consulta_capacidad(string t);
};

//Constructor
Hospital::Hospital(string c, string n, string d, string t){
    clave = c;
    nombre = n;
    direccion = d;
    telefono = t;
}

/**
 * Esta función toma los datos del objeto de clase Hospital para desplegarlos
 * en la consola
 * 
 * @param
 * @return
 */
void Hospital::bienvenida(){
    cout << "\n\nBienvenido al hospital " << nombre << "!" << endl << "Clave: "
    << clave << endl << "Dirección: " << direccion << endl << "Teléfono: " <<
    telefono << endl << endl << endl;
}

/** Esta función crea ejemplos dentro del arreglo de clase Departamento
 * 
 * @param
 * @return
 */
void Hospital::genera_ejemplos(){
    int i = 0;
    depto[i] = new Covid("Covid", "Norte", "1000", "284");
    i ++;
    depto[i] = new Urgencias("Urgencias", "Sur", "100", "47");
    i ++;
    depto[i] = new Quirofano("Quirofano", "Este", "78", "21");
    i ++;
    depto[i] = new General("General", "Oeste", "2500", "2345");
    i ++;
} 

/**
 * Recorre el arreglo buscando coincidencia en el tipo de departamento, al
 * encontrarlo llama a la función para agregar o quitar en base a la opción 
 * seleccionada
 * 
 * @param string t, string opc, int num
 * @return
 */
void Hospital::actualiza_pacientes(string t, string opc, int num, string s){
    if(opc == "1"){
        for(int i = 0; i < sizeof(depto)/sizeof(depto[0]); i ++){
            if(depto[i] -> get_tipo() == t){
                cout << "\nPacientes actualizados en " << t << endl;
                cout << depto[i] -> agregar_pacientes(num, s) << " pacientes" 
                << endl;
            }
        }
    }
    else if(opc == "2"){
        for(int i = 0; i < sizeof(depto)/sizeof(depto[0]); i ++){
            if(depto[i] -> get_tipo() == t){
                cout << "\nPacientes actualizados en " << t << endl;
                cout << depto[i] -> quitar_pacientes(num, s) << " pacientes" <<
                endl;
            }
        }
    }
}

/**
 * Recorre el arreglo buscando coincidencia en el tipo de departemento, al
 * encontrarlo calcula el porcentaje de espacios libres
 * @param string t
 * @return float con el porcentaje de espacios disponibles
 */
float Hospital::consulta_capacidad(string t){
    for(int i = 0; i < sizeof(depto)/sizeof(depto[0]); i ++){
        if(depto[i] -> get_tipo() == t){
            return depto[i] -> porcentaje_ocupacion();
        }
    }
    return 0;
}

#endif