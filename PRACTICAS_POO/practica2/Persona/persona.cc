//persona.cc
//cuerpo de los métodos de la clase Persona

#include <iostream>
#include <string>                               //Biblioteca específica para declarar variables de tipo string
#include "persona.h"

Persona::Persona(std::string dni, std::string nombre, std::string apellidos, int edad, std::string direccion, std::string localidad, std::string provincia, std::string pais){  //Declaramos al constructor pasandole todos los parámetros

     setDNI(dni);                               //Llamamos a la función setDNI pasándole el parámetro dni
     setNombre(nombre);                         //LLamamos a la función setNombre pasándole el parámetro nombre
     setApellidos(apellidos);                   //LLamamos a la función setApellidos pasándole el parámetro apellidos
     setEdad(edad);                             //Llamamos a la función setEdad pasándole el parámtero edad
     setDireccion(direccion);                   //Llamamos a la función setDireccion pasándole el parámetro direccion
     setLocalidad(localidad);                   //Llamamos a la función setLocalidad pasándole el parámetro localidad
     setProvincia(provincia);                   //Llamamos a la función setProvincia pasándole el parámetro provincia
     setPais(pais);                             //Llamamos a la función setPais pasándole el parámetro pais

}

bool Persona::setEdad(int const &edad){                
    edad_=edad;                                 //edad_ pasa a tener el valor de edad
    if(edad_>=0){                               //Si edad_ es >=0 entramos en el bucle 
        return true;                            //Retornamos true
    }
    return false;                               //Retornamos false
}

bool Persona::mayor()const{
    if(edad_>=18){                              //Si edad_ es >=18 entramos en el bucle
        return true;                            //Retornamos true
    }
    return false;                               //Retornamos false
}
