//Hilda Beltrán Acosta A01251916
#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <iostream>
#include "empleado.h" /*La clase Empleado es una composición de la clase 
Hospital*/

using namespace std;

//Se crea la clase Hospital con sus getters, atributos y métodos
class Hospital{
    private:
        string claveHospital, nombreHospital, direccionHospital, 
        telefonoHospital, capacidadHospital;
    
    public:
        string get_clave(){ return claveHospital;}
        string get_nombre(){ return nombreHospital;}
        string get_direccion(){ return direccionHospital;}
        string get_telefono(){ return telefonoHospital;}
        string get_capacidad(){ return capacidadHospital;}
        Hospital(
            string clave, string nombre, string direccion, string telefono);
        Hospital(
            string clave, string nombre, string direccion, string telefono, 
            string capacidad);
        void muestra_hospitales();
        string consulta_direccion();
        string consulta_telefono();
        string consulta_capacidad();
        string datos_string(int capacidadHospital);
        
};

//Asigna el valor recibido a los distintos atributos
Hospital::Hospital(string clave, string nombre, string direccion,
string telefono){
    claveHospital = clave;
    nombreHospital = nombre;
    direccionHospital = direccion;
    telefonoHospital = telefono;
}

//Sobrecarga de funciones, recibe un atributo más
Hospital::Hospital(string clave, string nombre, string direccion, 
string telefono, string capacidad){
    claveHospital = clave;
    nombreHospital = nombre;
    direccionHospital = direccion;
    telefonoHospital = telefono;
    capacidadHospital = capacidad;
}

//Despliega los datos de todos los hospitales
void Hospital::muestra_hospitales(){
                cout << claveHospital << "\t  " << nombreHospital << "\t   " << 
                direccionHospital << "\t" << telefonoHospital << "\t   "<< 
                capacidadHospital << endl;
            }

string Hospital::consulta_direccion(){
    return direccionHospital;
}

string Hospital::consulta_telefono(){
    return telefonoHospital;
}

string Hospital::consulta_capacidad(){
    return capacidadHospital;
}

string datos_string(int capacidadH){
    string cap = to_string(capacidadH);
    return cap;
}

//Se crea la clase Covid con sus getters, atributos y métodos
//Esta clase hereda atributos y funciones de la clase Hospital
class Covid : public Hospital{
    private:
        int capacidadCovid = 1000;
        string ocupacionCovid;

    public:
        int get_capacidad(){ return capacidadCovid;}
        string get_ocupacion(){ return ocupacionCovid;}
        //Asigna el valor recibido a los distintos atributos
        Covid(string clave, string nombre, string direccion, string telefono,
        string ocuCo):Hospital(clave,
        nombre, direccion, telefono){
            capacidadCovid = 1000;
            ocupacionCovid = ocuCo;
        }
        //Sobrecarga de funciones, recibe un atributo más
        Covid(string clave, string nombre, string direccion, string telefono,
        string capacidad, string ocuCo):Hospital(clave,
        nombre, direccion, telefono, capacidad){
            capacidadCovid = 1000;
            ocupacionCovid = ocuCo;
        }
        //Recibe el valor de un apuntador
        int agregar_pacientes(int *num);
        int quitar_pacientes(int *num);
        float porcentaje_ocupacion();
        int consulta_capacidad();
        string ocupacion_string(int ocupacionCovid);
};

int Covid::agregar_pacientes(int *num){
    int ocupaCovid = stoi(ocupacionCovid) + *num;
    ocupacionCovid = to_string(ocupaCovid);
    return ocupaCovid;
}

int Covid::quitar_pacientes(int *num){
    int ocupaCovid = stoi(ocupacionCovid) - *num;
    ocupacionCovid = to_string(ocupaCovid);
    return ocupaCovid;
}

float Covid::porcentaje_ocupacion(){
    float porcentaje = 100 - ((stof(ocupacionCovid) / capacidadCovid) * 100);
    return porcentaje;
}

int Covid::consulta_capacidad(){
    return capacidadCovid;
}

string Covid::ocupacion_string(int ocupacionCovid){
    string ocu = to_string(ocupacionCovid);
    return ocu;
}

string Covid::porcentaje_string(int porcentajeCovid){
    string porc = to_string(porcentajeCovid);
    return porc;
}

//Se crea la clase Urgencias con sus getters, atributos y métodos
//Esta clase hereda atributos y funciones de la clase Hospital
class Urgencias : public Hospital{
    private:
        int capacidadUrgencias = 1000;
        string ocupacionUrgencias;

    public:
        int get_capacidad(){ return capacidadUrgencias;}
        string get_ocupacion(){ return ocupacionUrgencias;}
        //Asigna el valor recibido a los distintos atributos
        Urgencias(string clave, string nombre, string direccion, string telefono,
        string ocuUr):Hospital(clave,
        nombre, direccion, telefono){
            capacidadUrgencias = 1000;
            ocupacionUrgencias = ocuUr;
        }
        //Sobrecarga de funciones, recibe un atributo más
        Urgencias(string clave, string nombre, string direccion, string telefono,
        string capacidad, string ocuUr):Hospital(clave,
        nombre, direccion, telefono, capacidad){
            capacidadUrgencias = 1000;
            ocupacionUrgencias = ocuUr;
        }
        //Recibe el valor de un apuntador
        int agregar_pacientes(int *num);
        int quitar_pacientes(int *num);
        float porcentaje_ocupacion();
        int consulta_capacidad();
        string ocupacion_string(int ocupacionUrgencias);
        string porcentaje_string(int porcentajeUrgencias);
};

int Urgencias::agregar_pacientes(int *num){
    int ocupaUrgencias = stoi(ocupacionUrgencias) + *num;
    ocupacionUrgencias = to_string(ocupaUrgencias);
    return ocupaUrgencias;
}

int Urgencias::quitar_pacientes(int *num){
    int ocupaUrgencias = stoi(ocupacionUrgencias) - *num;
    ocupacionUrgencias = to_string(ocupaUrgencias);
    return ocupaUrgencias;
}

float Urgencias::porcentaje_ocupacion(){
    float porcentaje = 100 - ((stof(ocupacionUrgencias) / capacidadUrgencias) * 100);
    return porcentaje;
}

int Urgencias::consulta_capacidad(){
    return capacidadUrgencias;
}

string Urgencias::ocupacion_string(int ocupacionUrgencias){
    string ocu = to_string(ocupacionUrgencias);
    return ocu;
}

string Urgencias::porcentaje_string(int porcentajeUrgencias){
    string porc = to_string(porcentajeUrgencias);
    return porc;
}

//Se crea la clase Quirófano con sus getters, atributos y métodos
//Esta clase hereda atributos y funciones de la clase Hospital
class Quirofano : public Hospital{
    private:
        int capacidadQuirofano = 1000;
        string ocupacionQuirofano;

    public:
        int get_capacidad(){ return capacidadQuirofano;}
        string get_ocupacion(){ return ocupacionQuirofano;}
        //Asigna el valor recibido a los distintos atributos
        Quirofano(string clave, string nombre, string direccion, string telefono,
        string ocuQui):Hospital(clave,
        nombre, direccion, telefono){
            capacidadQuirofano = 1000;
            ocupacionQuirofano = ocuQui;
        }
        //Sobrecarga de funciones, recibe un atributo más
        Quirofano(string clave, string nombre, string direccion, string telefono,
        string capacidad, string ocuQui):Hospital(clave,
        nombre, direccion, telefono, capacidad){
            capacidadQuirofano = 1000;
            ocupacionQuirofano = ocuQui;
        }
        //Recibe el valor de un apuntador
        int agregar_pacientes(int *num);
        int quitar_pacientes(int *num);
        float porcentaje_ocupacion();
        int consulta_capacidad();
        string ocupacion_string(int ocupacionQuirofano);
        string porcentaje_string(int porcentajeQuirofano);
};

int Quirofano::agregar_pacientes(int *num){
    int ocupaQuirofano = stoi(ocupacionQuirofano) + *num;
    ocupacionQuirofano = to_string(ocupaQuirofano);
    return ocupaQuirofano;
}

int Quirofano::quitar_pacientes(int *num){
    int ocupaQuirofano = stoi(ocupacionQuirofano) - *num;
    ocupacionQuirofano = to_string(ocupaQuirofano);
    return ocupaQuirofano;
}

float Quirofano::porcentaje_ocupacion(){
    float porcentaje = 100 - ((stof(ocupacionQuirofano) / capacidadQuirofano) * 100);
    return porcentaje;
}

int Quirofano::consulta_capacidad(){
    return capacidadQuirofano;
}

string Quirofano::ocupacion_string(int ocupacionQuirofano){
    string ocu = to_string(ocupacionQuirofano);
    return ocu;
}

string Quirofano::porcentaje_string(int porcentajeQuirofano){
    string porc = to_string(porcentajeQuirofano);
    return porc;
}

//Se crea la clase General con sus getters, atributos y métodos
//Esta clase hereda atributos y funciones de la clase Hospital
class General : public Hospital{
    private:
        int capacidadGeneral = 1000;
        string ocupacionGeneral;

    public:
        int get_capacidad(){ return capacidadGeneral;}
        string get_ocupacion(){ return ocupacionGeneral;}
        //Asigna el valor recibido a los distintos atributos
        General(string clave, string nombre, string direccion, string telefono,
        string ocuGe):Hospital(clave,
        nombre, direccion, telefono){
            capacidadGeneral = 1000;
            ocupacionGeneral = ocuGe;
        }
        //Sobrecarga de funciones, recibe un atributo más
        General(string clave, string nombre, string direccion, string telefono,
        string capacidad, string ocuGe):Hospital(clave,
        nombre, direccion, telefono, capacidad){
            capacidadGeneral = 1000;
            ocupacionGeneral = ocuGe;
        }
        //Recibe el valor de un apuntador
        int agregar_pacientes(int *num);
        int quitar_pacientes(int *num);
        float porcentaje_ocupacion();
        int consulta_capacidad();
        string ocupacion_string(int ocupacionGeneral);
        string porcentaje_string(int porcentajeGeneral);
};

int General::agregar_pacientes(int *num){
    int ocupaGeneral = stoi(ocupacionGeneral) + *num;
    ocupacionGeneral = to_string(ocupaGeneral);
    return ocupaGeneral;
}

int General::quitar_pacientes(int *num){
    int ocupaGeneral = stoi(ocupacionGeneral) - *num;
    ocupacionGeneral = to_string(ocupaGeneral);
    return ocupaGeneral;
}

float General::porcentaje_ocupacion(){
    float porcentaje = 100 - ((stof(ocupacionGeneral) / capacidadGeneral) * 100);
    return porcentaje;
}

int General::consulta_capacidad(){
    return capacidadGeneral;
}

string General::ocupacion_string(int ocupacionGeneral){
    string ocu = to_string(ocupacionGeneral);
    return ocu;
}

string General::porcentaje_string(int porcentajeGeneral){
    string porc = to_string(porcentajeGeneral);
    return porc;
}

#endif