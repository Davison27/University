//crupier.cc
//cuerpo de los métodos de la clase Crupier

#include <iostream>
#include <string.h>                                                 //Libreria necesaria para declarar variables de tipo string
#include "crupier.h"

Crupier::Crupier(std::string DNI, std::string codigo, std::string nombre, std::string apellidos, int edad, std::string direccion, std::string localidad, std::string provincia, std::string pais):Persona(DNI,nombre,apellidos,edad,direccion,localidad,provincia,pais){//Llamamos al constructor pasandole los parámetros y creando la herencia con la clase Persona
    codigo_=codigo;                                                 //codigo_ pasa a tener el valor de codigo
}

