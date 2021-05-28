//Hilda Beltrán Acosta A01251916
#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <iostream>
 
using namespace std;

class Departamento{
    private:
        string tipo, ala, capacidad;
    public:
        //Constructor por default
        Departamento(): tipo(""), ala(""), capacidad("") {};
        //Sobrecarga del constructor por default
        Departamento(string t, string a, string c);
        //getters para los atributos privados
        string get_tipo(){ return tipo;}
        string get_capacidad(){ return capacidad;}
        string get_ala(){ return ala;}
        virtual int agregar_pacientes(int num);
        virtual int quitar_pacientes(int num);
        virtual float porcentaje_ocupacion();
};

//Constructor
Departamento::Departamento(string t, string a, string c){
    tipo = t;
    ala = a;
    capacidad = c;
}

int Departamento::agregar_pacientes(int num){
    return stoi(capacidad);
}

int Departamento::quitar_pacientes(int num){
    return stoi(capacidad);
}

float Departamento::porcentaje_ocupacion(){

    return 100;
}

//Esta clase hereda atributos y métodos de la clase Hospital
class Covid : public Departamento{
    private:
        string sint[3] = {"Fiebre", "Tos seca", "Cansancio"}, sintoma, ocupacionCovid;

    public:
        //Constructor por default
        Covid(): Departamento("", "", "") {};
        //Sobrecarga del constructor por default
        Covid(string t, string a, string c, string o, string s) : Departamento(t, a, c){
            ocupacionCovid = o;
            sintoma = s;
        };
        //getters para los atributos privados
        string get_sintoma(){ return sintoma;}
        string* get_sintomas(){ return sint;}
        int agregar_pacientes(int num);
        int quitar_pacientes(int num);
        float porcentaje_ocupacion();
};

int Covid::agregar_pacientes(int num){
    for(int i = 0; i < 3; i ++){
        if(sintoma == sint[i]){
            int ocupaCovid = stoi(ocupacionCovid) + num;
            ocupacionCovid = to_string(ocupaCovid);
            return ocupaCovid;
        }
    }
    return stoi(ocupacionCovid);
}

int Covid::quitar_pacientes(int num){
    for(int i = 0; i < 3; i ++){
        if(sintoma == sint[i]){
            int ocupaCovid = stoi(ocupacionCovid) - num;
            ocupacionCovid = to_string(ocupaCovid);
            return ocupaCovid;
        }
    }
    return stoi(ocupacionCovid);
}

float Covid::porcentaje_ocupacion(){
    return (100 - ((stof(ocupacionCovid) / stof(get_capacidad())) * 100));
}

//Esta clase hereda atributos y métodos de la clase Hospital
class Urgencias : public Departamento{
    private:
        string sit[3] = {"Envenenamiento", "Convulsiones", "Señal de infarto"},
        situacion, ocupacionUrgencias;

    public:
        //Constructor por default
        Urgencias(): Departamento("", "", "") {};
        //Sobrecarga del constructor por default
        Urgencias(string t, string a, string c, string o, string s) : Departamento(t, a, c){
            ocupacionUrgencias = o;
            situacion = s;
        };
        //getters para los atributos privados
        string get_sintoma(){ return situacion;}
        string* get_situacion(){ return sit;}
        int agregar_pacientes(int num);
        int quitar_pacientes(int num);
        float porcentaje_ocupacion();
};

int Urgencias::agregar_pacientes(int num){
    for(int i = 0; i < 3; i ++){
        if(situacion == sit[i]){
            int ocupaUr = stoi(ocupacionUrgencias) + num;
            ocupacionUrgencias = to_string(ocupaUr);
            return ocupaUr;
        }
    }
    return stoi(ocupacionUrgencias);
}

int Urgencias::quitar_pacientes(int num){
    for(int i = 0; i < 3; i ++){
        if(situacion == sit[i]){
            int ocupaUr = stoi(ocupacionUrgencias) - num;
            ocupacionUrgencias = to_string(ocupaUr);
            return ocupaUr;
        }
    }
    return stoi(ocupacionUrgencias);
}

float Urgencias::porcentaje_ocupacion(){
    return (100 - ((stof(ocupacionUrgencias) / stof(get_capacidad())) * 100));
}

//Esta clase hereda atributos y métodos de la clase Hospital
class Quirofano : public Departamento{
    private:
        string cir[3] = {"Dr. Javier", "Dra. Azul", "Dr. José"}, sintoma, ocupacionQuirofano;

    public:
        //Constructor por default
        Quirofano(): Departamento("", "", "") {};
        //Sobrecarga del constructor por default
        Quirofano(string t, string a, string c, string o, string s) : Departamento(t, a, c){
            ocupacionQuirofano = o;
            sintoma = s;
        };
        //getters para los atributos privados
        string get_sintoma(){ return sintoma;}
        string* get_sintomas(){ return cir;}
        int agregar_pacientes(int num);
        int quitar_pacientes(int num);
        float porcentaje_ocupacion();
};

int Quirofano::agregar_pacientes(int num){
    for(int i = 0; i < 3; i ++){
        if(sintoma == cir[i]){
            int ocupaQuir = stoi(ocupacionQuirofano) + num;
            ocupacionQuirofano = to_string(ocupaQuir);
            return ocupaQuir;
        }
    }
    return stoi(ocupacionQuirofano);
}

int Quirofano::quitar_pacientes(int num){
    for(int i = 0; i < 3; i ++){
        if(sintoma == cir[i]){
            int ocupaQuir = stoi(ocupacionQuirofano) - num;
            ocupacionQuirofano = to_string(ocupaQuir);
            return ocupaQuir;
        }
    }
    return stoi(ocupacionQuirofano);
}

float Quirofano::porcentaje_ocupacion(){
    return (100 - ((stof(ocupacionQuirofano) / stof(get_capacidad())) * 100));
}

//Esta clase hereda atributos y métodos de la clase Hospital
class General : public Departamento{
    private:
        string cita[3] = {"1234", "5678", "9123"}, sintoma, ocupacionGeneral;

    public:
        //Constructor por default
        General(): Departamento("", "", "") {};
        //Sobrecarga del constructor por default
        General(string t, string a, string c, string o, string s) : Departamento(t, a, c){
            ocupacionGeneral = o;
            sintoma = s;
        };
        //getters para los atributos privados
        string get_sintoma(){ return sintoma;}
        string* get_sintomas(){ return cita;}
        int agregar_pacientes(int num);
        int quitar_pacientes(int num);
        float porcentaje_ocupacion();
};

int General::agregar_pacientes(int num){
    for(int i = 0; i < 3; i ++){
        if(sintoma == cita[i]){
            int ocupaGen = stoi(ocupacionGeneral) + num;
            ocupacionGeneral = to_string(ocupaGen);
            return ocupaGen;
        }
    }
    return stoi(ocupacionGeneral);
}

int General::quitar_pacientes(int num){
    for(int i = 0; i < 3; i ++){
        if(sintoma == cita[i]){
            int ocupaGen = stoi(ocupacionGeneral) - num;
            ocupacionGeneral = to_string(ocupaGen);
            return ocupaGen;
        }
    }
    return stoi(ocupacionGeneral);
}

float General::porcentaje_ocupacion(){
    return (100 - ((stof(ocupacionGeneral) / stof(get_capacidad())) * 100));
}

#endif