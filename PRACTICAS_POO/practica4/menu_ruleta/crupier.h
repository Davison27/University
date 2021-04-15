//crupier.h
//la clase Crupier representa los datos de un crupier

#ifndef CRUPIER_H
#define CRUPIER_H
#include <string.h>                                                 //Libreria necesaria para declarar variables de tipo string
#include "persona.h"                                                //Añadimos este archivo pues la clase Crupier va a heredar la parte pública de la clase Persona

class Crupier:public Persona{
    private:
    std::string codigo_;                                            //Declaración de una variable de tipo string en la parte privada de la clase Crupier con nombre codigo_

    public:
    Crupier(std::string DNI, std::string codigo, std::string nombre="", std::string apellidos="", int edad=0, std::string direccion="", std::string localidad="", std::string provincia="", std::string pais="");//Constructor de la clase Crupier a la cual le pasamos como parámetros obligatorios DNI y codigo y como parámetros opcionales el resto

    inline std::string getCodigo(){return codigo_;};                //Función que retorna el valor de codigo_
    inline void setCodigo(std::string const &codigo){codigo_=codigo;};    //Función que realiza operaciones sobre codigo_

};

#endif