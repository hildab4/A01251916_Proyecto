/*
* Hilda Beltrán Acosta 
* A01251916
* Disponibilidad Hospital
*/
#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <iostream>
#include <array>
 
using namespace std;

/*
* Esta clase hereda a otras cuatro clases, las cuales son tipos de 
* departamentos o secciones que se encuentran en el hospital. Es una clase
* abstracta, por lo que no se pueden declarar objetos de esta clase, tomando
* en cuenta que se habla de tipos de departamentos. Por lo que no es necesario
* dar información sobre la clase departamento.
*/
class Departamento{
    protected:
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
        virtual int agregar_pacientes(int num, string s) = 0;
        virtual int quitar_pacientes(int num, string s) = 0;
        virtual float porcentaje_ocupacion() = 0;
};

//Constructor
Departamento::Departamento(string t, string a, string c){
    tipo = t;
    ala = a;
    capacidad = c;
}

/*
* Esta clase hereda atributos y métodos de la clase Departamento,
* evalúa si el síntoma presentado se encuentra dentro de las prioridades,
* de esta forma se decide si el caso pasa al área de Covid. En caso de que
* el síntoma se encuentre, agrega al paciente.
*/
class Covid : public Departamento{
    private:
        string sint[3] = {"Fiebre", "Tos seca", "Cansancio"}, 
        ocupacionCovid;

    public:
        //Constructor por default
        Covid(): Departamento("", "", "") {};
        //Sobrecarga del constructor por default
        Covid(string t, string a, string c, string o) : 
        Departamento(t, a, c){
            ocupacionCovid = o;
        };
        //getters para los atributos privados
        string* get_sintomas(){ return sint;}
        int agregar_pacientes(int num, string s);
        int quitar_pacientes(int num, string s);
        float porcentaje_ocupacion();
};

/**
* Esta función agrega pacientes en caso de que el síntoma se encuentre
* 
* @param int num con la cantidad de pacientes a agregar
* @return int ocupacionCovid con la cantidad de espacios ocupados
*/
int Covid::agregar_pacientes(int num, string sintoma){
    for(int i = 0; i < sizeof(sint)/sizeof(sint[0]); i ++){
        if(sintoma == sint[i]){
            int ocupaCovid = stoi(ocupacionCovid) + num;
            ocupacionCovid = to_string(ocupaCovid);
            cout << "Se agregó al paciente con éxito" << endl;
            return ocupaCovid;
        }
    }
    return stoi(ocupacionCovid);
}

/**
* Esta función quita pacientes que ya fueron dados de alta
* 
* @param int num con la cantidad de pacientes a quitar
* @return int ocupacionCovid con la cantidad de espacios ocupados
*/
int Covid::quitar_pacientes(int num, string sintoma){
    for(int i = 0; i < sizeof(sint)/sizeof(sint[0]); i ++){
        if(sintoma == sint[i]){
            int ocupaCovid = stoi(ocupacionCovid) - num;
            ocupacionCovid = to_string(ocupaCovid);
            cout << "Se quitó al paciente con éxito" << endl;
            return ocupaCovid;
        }
    }
    return stoi(ocupacionCovid);
}

/**
 * Esta función calcula el porcentaje de ocupación, lo cual se le resta a 100
 * para poder obtener el porcentaje de disponibilidad
 * 
 * @param
 * @return float con la disponibilidad en el área
 */
float Covid::porcentaje_ocupacion(){
    return (100 - ((stof(ocupacionCovid) / stof(get_capacidad())) * 100));
}

/*
* Esta clase hereda atributos y métodos de la clase Departamento,
* evalúa si la situación presentada se encuentra dentro de las prioridades,
* de esta forma se decide si el caso pasa al área de Urgencias. En caso de que
* la situación se encuentre, agrega al paciente.
*/
class Urgencias : public Departamento{
    private:
        string sit[3] = {"Envenenamiento", "Convulsiones", "Señal de infarto"},
        ocupacionUrgencias;

    public:
        //Constructor por default
        Urgencias(): Departamento("", "", "") {};
        //Sobrecarga del constructor por default
        Urgencias(string t, string a, string c, string o) : 
        Departamento(t, a, c){
            ocupacionUrgencias = o;
        };
        //getters para los atributos privados
        string* get_situacion(){ return sit;}
        int agregar_pacientes(int num, string s);
        int quitar_pacientes(int num, string s);
        float porcentaje_ocupacion();
};

/**
* Esta función agrega pacientes en caso de que la situación se encuentre
* 
* @param int num con la cantidad de pacientes a agregar
* @return int ocupacionUrgencias con la cantidad de espacios ocupados
*/
int Urgencias::agregar_pacientes(int num, string situacion){
    for(int i = 0; i < sizeof(sit)/sizeof(sit[0]); i ++){
        if(situacion == sit[i]){
            int ocupaUr = stoi(ocupacionUrgencias) + num;
            ocupacionUrgencias = to_string(ocupaUr);
            cout << "Se agregó al paciente con éxito" << endl;
            return ocupaUr;
        }
    }
    return stoi(ocupacionUrgencias);
}

/**
* Esta función quita pacientes que ya fueron dados de alta
* 
* @param int num con la cantidad de pacientes a quitar
* @return int ocupacionUrgencias con la cantidad de espacios ocupados
*/
int Urgencias::quitar_pacientes(int num, string situacion){
    for(int i = 0; i < sizeof(sit)/sizeof(sit[0]); i ++){
        if(situacion == sit[i]){
            int ocupaUr = stoi(ocupacionUrgencias) - num;
            ocupacionUrgencias = to_string(ocupaUr);
            cout << "Se quitó al paciente con éxito" << endl;
            return ocupaUr;
        }
    }
    return stoi(ocupacionUrgencias);
}

/**
 * Esta función calcula el porcentaje de ocupación, lo cual se le resta a 100
 * para poder obtener el porcentaje de disponibilidad
 * 
 * @param
 * @return float con la disponibilidad en el área
 */
float Urgencias::porcentaje_ocupacion(){
    return (100 - ((stof(ocupacionUrgencias) / stof(get_capacidad())) * 100));
}

/*
* Esta clase hereda atributos y métodos de la clase Departamento,
* evalúa si el cirujano presentado se encuentra dentro de los registrados,
* de esta forma se decide si el caso pasa al área de Quirófano. En caso de que
* el cirujano se encuentre, agrega al paciente.
*/
class Quirofano : public Departamento{
    private:
        string cir[3] = {"Javier", "Azul", "José"}, 
        ocupacionQuirofano;

    public:
        //Constructor por default
        Quirofano(): Departamento("", "", "") {};
        //Sobrecarga del constructor por default
        Quirofano(string t, string a, string c, string o) : 
        Departamento(t, a, c){
            ocupacionQuirofano = o;
        };
        //getters para los atributos privados
        string* get_sintomas(){ return cir;}
        int agregar_pacientes(int num, string s);
        int quitar_pacientes(int num, string s);
        float porcentaje_ocupacion();
};

/**
* Esta función agrega pacientes en caso de que el cirujano se encuentre
* 
* @param int num con la cantidad de pacientes a agregar
* @return int ocupacionQuirofano con la cantidad de espacios ocupados
*/
int Quirofano::agregar_pacientes(int num, string sintoma){
    for(int i = 0; i < sizeof(cir)/sizeof(cir[0]); i ++){
        if(sintoma == cir[i]){
            int ocupaQuir = stoi(ocupacionQuirofano) + num;
            ocupacionQuirofano = to_string(ocupaQuir);
            cout << "Se agregó al paciente con éxito" << endl;
            return ocupaQuir;
        }
    }
    return stoi(ocupacionQuirofano);
}

/**
* Esta función quita pacientes que ya fueron dados de alta
* 
* @param int num con la cantidad de pacientes a quitar
* @return int ocupacionQuirofano con la cantidad de espacios ocupados
*/
int Quirofano::quitar_pacientes(int num, string sintoma){
    for(int i = 0; i < sizeof(cir)/sizeof(cir[0]); i ++){
        if(sintoma == cir[i]){
            int ocupaQuir = stoi(ocupacionQuirofano) - num;
            ocupacionQuirofano = to_string(ocupaQuir);
            cout << "Se quitó al paciente con éxito" << endl;
            return ocupaQuir;
        }
    }
    return stoi(ocupacionQuirofano);
}

/**
 * Esta función calcula el porcentaje de ocupación, lo cual se le resta a 100
 * para poder obtener el porcentaje de disponibilidad
 * 
 * @param
 * @return float con la disponibilidad en el área
 */
float Quirofano::porcentaje_ocupacion(){
    return (100 - ((stof(ocupacionQuirofano) / stof(get_capacidad())) * 100));
}

/*
* Esta clase hereda atributos y métodos de la clase Departamento,
* evalúa si la cita presentada se encuentra dentro de las registradas,
* de esta forma se decide si el caso pasa al área de General. En caso de que
* la cita se encuentre, agrega al paciente.
*/
class General : public Departamento{
    private:
        string cita[3] = {"a234", "b678", "c123"}, ocupacionGeneral;

    public:
        //Constructor por default
        General(): Departamento("", "", "") {};
        //Sobrecarga del constructor por default
        General(string t, string a, string c, string o) : 
        Departamento(t, a, c){
            ocupacionGeneral = o;
        };
        //getters para los atributos privados
        string* get_sintomas(){ return cita;}
        int agregar_pacientes(int num, string s);
        int quitar_pacientes(int num, string s);
        float porcentaje_ocupacion();
};

/**
* Esta función agrega pacientes, en caso de que la cita se encuentre
* 
* @param int num con la cantidad de pacientes a agregar
* @return int ocupacionGeneral con la cantidad de espacios ocupados
*/
int General::agregar_pacientes(int num, string sintoma){
    for(int i = 0; i < sizeof(cita)/sizeof(cita[0]); i ++){
        if(sintoma == cita[i]){
            int ocupaGen = stoi(ocupacionGeneral) + num;
            ocupacionGeneral = to_string(ocupaGen);
            cout << "Se agregó al paciente con éxito" << endl;
            return ocupaGen;
        }
    }
    return stoi(ocupacionGeneral);
}

/**
* Esta función quita pacientes que ya fueron dados de alta
* 
* @param int num con la cantidad de pacientes a quitar
* @return int ocupacionGeneral con la cantidad de espacios ocupados
*/
int General::quitar_pacientes(int num, string sintoma){
    for(int i = 0; i < sizeof(cita)/sizeof(cita[0]); i ++){
        if(sintoma == cita[i]){
            int ocupaGen = stoi(ocupacionGeneral) - num;
            ocupacionGeneral = to_string(ocupaGen);
            cout << "Se quitó al paciente con éxito" << endl;
            return ocupaGen;
        }
    }
    return stoi(ocupacionGeneral);
}

/**
 * Esta función calcula el porcentaje de ocupación, lo cual se le resta a 100
 * para poder obtener el porcentaje de disponibilidad
 * 
 * @param
 * @return float con la disponibilidad en el área
 */
float General::porcentaje_ocupacion(){
    return (100 - ((stof(ocupacionGeneral) / stof(get_capacidad())) * 100));
}

#endif