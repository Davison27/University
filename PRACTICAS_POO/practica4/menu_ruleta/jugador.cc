//jugador.cc
//cuerpo de los métodos de la clase Jugador

#include <iostream>
#include <list>                                                     //Libreria necesaria para declarar variable de tipo list
#include <fstream>                                                  //Libreria necesaria para leer y escribir ficheros
#include <string.h>                                                 //Libreria necesaria para declarar variable de tipo string       
#include "jugador.h"

Jugador::Jugador(std::string DNI, std::string codigo, std::string nombre, std::string apellidos, int edad, std::string direccion, std::string localidad, std::string provincia, std::string pais):Persona(DNI,nombre,apellidos,edad,direccion,localidad,provincia,pais){//Llamamos al constructor pasandole los parámetros y creando la herencia con la clase Persona
        codigo_=codigo;                                             //codigo_ pasa a tener el valor de codigo
        dinero_=1000;                                               //Al no recibirla como parámetro, inicializamos la variable con valor 1000
}

void Jugador::setApuestas(){
    std::ifstream f;                                                //Declaración de una variable tipo ifstream para la apertura del fichero

    //Apertura del fichero
    f.open(getDNI()+".txt");                                        //Apertura de un fichero llamado DNI.txt

    Apuesta ap;                                                    //Declaración de una estructura auxiliar 
    std::string aux;                                                //Declaración de una variable de tipo string llamada aux 

    //Lectura del fichero
    getline(f,aux,',');                                             //Lectura del primer parámetro del fichero (hasta que encuentre una ',')(se va guardando en la variable aux)

    while(!f.eof()){                                                //Declaración de un bucle que no terminará hasta que encuentre un NULL (fin del fichero)
        ap.tipo=std::stoi(aux);                                     //Guardamos el primer valor leido del documento en la struct ap y pasandolo como entero
        getline(f,aux,',');                                         //Lectura del segundo parámetro del fichero
        ap.valor=aux;                                               //Guardamos el segundo valor leido del docuemento en la struct ap 
        getline(f,aux,'\n');                                         //Lectura del tercer parámetro del fichero
        ap.cantidad=std::stoi(aux);                                 //Guardamos el tercer valor leido del documento en la struct ap y pasandolo como entero    
        getline(f,aux,',');                                         //Lectura del primer parámetro de la siguiente línea y ya continua el programa hasta encontrar valor NULL  
        apuestas_.push_back(ap);                                    //Volcado de todos los valores de la struct ap en el struct apuestas_                                                            
    }
    f.close();                                                      //Cierre del fichero

}