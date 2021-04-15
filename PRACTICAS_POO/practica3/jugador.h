//jugador.h
//la clase Jugador guarda los datos de un jugador

#ifndef JUGADOR_H
#define JUGADOR_H
#include <string.h>                                             //Libreria necesaria para declarar variables de tipo string
#include <list>                                                 //Libreria necesaria para declarar variable de tipo list
#include "persona.h"                                            //Añadimos este archivo pues la clase Crupier va a heredar la parte pública de la clase Persona




struct Apuesta{                                                //Declaramos la estructura Apuestas para guardar los valores de la lista apuestas_

    int cantidad;                                               //Declaración de una variable de tipo int dentro de la estructura Apuestas con nombre cantidad
    int tipo;                                                   //Declaración de una variable de tipo int dentro de la estructura Apuestas con nombre tipo
    std::string valor;                                          //Declaración de una variable de tipo string dentro de la estructura Apuestas con nombre valor
};




class Jugador:public Persona{
    private:
    int dinero_;                                                //Declaración de una variable de tipo int en la parte privada de la clase Jugador con nombre dinero_
    std::string codigo_;                                        //Declaración de una variable de tipo string en la parte privada de la clase Jugador con nombre codigo_
    std::list<Apuesta> apuestas_;                               //Declaración de una variable de tipo list en la parte privada de la clase Jugador con nombre apuestas_

    public:
    Jugador(std::string DNI, std::string codigo, std::string nombre="", std::string apellidos="", int edad=0, std::string direccion="", std::string localidad="", std::string provincia="", std::string pais="");//Constructor de la clase Jugador a la cual le pasamos como parámetros obligatorios DNI y codigo y como parámetros opcionales el resto

    inline std::string getCodigo()const{return codigo_;};               //Función que retorna el valor de codigo_
    inline int getDinero()const{return dinero_;};                       //Función que retorna el valor de dinero_
    inline std::list<Apuesta> getApuestas()const{return apuestas_;};    //Función que retorna el valor de apuestas_

    inline void setCodigo(std::string const &codigo){codigo_=codigo;};  //Función que realiza operaciones sobre codigo_
    inline void setDinero(int const &dinero){dinero_=dinero;};          //Función que realiza operaciones sobre dinero_
    void setApuestas();                                                 //Función que realiza operaciones sobre apuestas_
};

#endif