# Proyecto Integrador
El proyecto se basa en conocer la capacidad de un hospital en las distinas secciones, como lo es el área de Covid, Urgencias, Quirófano, y General. De esta manera, el hospital puede dar de alta y baja a pacientes, además de poder consultar el porcentaje de espacios disponibles en cada área.

# Función
El hospital puede agregar o quitar pacientes en los distintos departamentos, también puede consultar la capacidad disponible en cada uno de estos.
Se despliega un menú donde se elige la opción que desea ejecutar, es decir si consultar disponibilidad, agregar o quitar pacientes. Al seleccionar la opción se pide el dato según lo que se quiera hacer, en el caso de consultar capacidad pide el dato del tipo de departamento; mientras que para agregar o quitar pacientes pide el tipo de departamento y el síntoma, cita, cirujano o situación para el apartado de descripción.
Las opciones de descripciones son las siguientes: Covid (Fiebre, Tos Seca, Cansancio), Urgencias (Envenenamiento, Convulsiones, Señal de Infarto), Quirófano (Javier, Azul, José), General (a234, b678, c123). En caso de no ingresar alguna de estas descripciones, no se agregará o quitará al paciente y aparecerá el mensaje correspondiente.

# Consideraciones
El programa corre en la consola
Compila con "g++ -std=c++17 proyecto_final.cpp"
Corre en macOS con "./a.out" 
Puede correr en cualquier sistema operativo, ya que está hecho con c++ standard.
