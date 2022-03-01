//persona.h
//La clase Persona representa los datos de una persona
#ifndef PERSONA_H
#define PERSONA_H
#include <string>                                                                       //Libreria necesaria para declarar variables de tipo string

class Persona{
    private:
    std::string DNI_;                                                                           //Declaración de una variable de tipo string en la parte privada de la clase Persona con nombre dni_
    std::string nombre_;                                                                        //Declaración de una variable de tipo string en la parte privada de la clase Persona con nombre nombre_
    std::string apellidos_;                                                                     //Declaración de una variable de tipo string en la parte privada de la clase Persona con nombre apellidos_
    int edad_;                                                                                  //Declaración de una variable de tipo int en la parte privada de la clase Persona con nombre edad_
    std::string direccion_;                                                                     //Declaración de una variable de tipo string en la parte privada de la clase Persona con nombre direccion_
    std::string localidad_;                                                                     //Declaración de una variable de tipo string en la parte privada de la clase Persona con nombre localidad_
    std::string provincia_;                                                                     //Declaración de una variable de tipo string en la parte privada de la clase Persona con nombre provincia_
    std::string pais_;                                                                          //Declaración de una variable de tipo string en la parte privada de la clase Persona con nombre pais_


    public:
    Persona(std::string DNI, std::string nombre="", std::string apellidos="", int edad=0, std::string direccion="", std::string localidad="", std::string provincia="", std::string pais="");//Constructor de la clase Persona a la cual le pasamos como parametro obligatorio DNI y como parámetros opcionales el resto
    inline std::string getDNI()const{return DNI_;};                                             //Función que retorna el valor de DNI_
    inline std::string getNombre()const{return nombre_;};                                       //Función que retorna el valor de nombre_
    inline std::string getApellidos()const{return apellidos_;};                                 //Función que retorna el valor de apellidos_
    inline int getEdad()const{return edad_;};                                                   //Función que retorna el valor de edad_
    inline std::string getDireccion()const{return direccion_;};                                 //Función que retorna el valor de direccion_
    inline std::string getLocalidad()const{return localidad_;};                                 //Función que retorna el valor de localidad_
    inline std::string getProvincia()const{return provincia_;};                                 //Función que retorna el valor de provincia_
    inline std::string getPais()const{return pais_;};                                           //Función que retorna el valor de pais_

    inline std::string getApellidosyNombre(){return std::string(apellidos_+", "+nombre_);};     //Función que retorna la concatenación de apellidos y nombre separados por una coma en forma de string

    inline void setDNI(std::string const &dni){DNI_=dni;};                                             //Función que recibe el parámetro dni e importa el valor a DNI_
    inline void setNombre(std::string const &nombre){nombre_=nombre;};                                 //Función que recibe el parámetro nombre e importa el valor a nombre_
    inline void setApellidos(std::string const &apellidos){apellidos_=apellidos;};                     //Función que reciba el parámetro apellidos e importa el valor a apellidos_
    bool setEdad(int const &edad);                                                                     //Función que recibe el parámetro edad e importa el valor a edad_ además de realizar una comprobación
    inline void setDireccion(std::string const &direccion){direccion_=direccion;};                     //Función que recibe el parámetro direccion e importa el valor a direccion_
    inline void setLocalidad(std::string const &localidad){localidad_=localidad;};                     //Función que recibe el parámetro localidad e importa el valor a localidad_
    inline void setProvincia(std::string const &provincia){provincia_=provincia;};                     //Función que recibe el parámetro provincia e importa el valor a provincia_
    inline void setPais(std::string const &pais){pais_=pais;};                                         //Función que recibe el parámetro pais e importa el valor a pais_

    bool mayor() const;                                                                                //Función que comprueba si es mayor de edad el usuario

};



#endif