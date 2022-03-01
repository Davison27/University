//ruleta.h
//La clase Ruleta representa los datos de una ruleta
#ifndef RULETA_H
#define RULETA_H
#include <list>                                                         //Declaramos la librería list para la declaración de listas
#include "crupier.h"                                                    //Declaramos crupier.h pues vamos a usar objetos de esta clase
#include "jugador.h"                                                    //Declaramos jugador.h pues vamos a usar objetos de esta clase


class Ruleta{
    private:
    int banca_;                                                         //Declaración de una variable de tipo int en la parte privada de la clase Ruleta con nombre banca_
    int bola_;                                                          //Declaración de una variable de tipo int en la parte privada de la clase Ruleta con nombre bola_
    std::list<Jugador> jugadores_;                                      //Declaración de una variable de tipo list en la parte privada de la clase Ruleta con nombre jugadores_
    Crupier crupier_;                                                   //Declaramos un objeto de la clase crupier


    public:
    Ruleta(Crupier crupier);                                            //Construtor de la clase Ruleta al que le pasámos como parámetro un objeto de la clase crupier
    inline int getBanca()const{return banca_;};                         //Función que retorna el valor de banca_
    inline int getBola()const{return bola_;};                           //Función que retorna el valor de bola_
    inline Crupier getCrupier()const{return crupier_;};                 //Función que retorna el valor de crupier_
    
    inline std::list<Jugador> getJugadores()const{return jugadores_;}   //Función que retorna el valor de jugadores_

    bool setBanca(int const &banca);                                    //Función que realiza operaciones sobre el parámetro banca_
    bool setBola(int const &bola);                                      //Función que realiza operaciones sobre el parámetro bola_
    void setCrupier(Crupier const &crupier);                            //Función que realiza operaciones sobre crupier_
    bool addJugador(Jugador const &jugador);                            //Función que realiza operaciones sobre el objeto jugador de la clase Jugador
    int deleteJugador(std::string const &dni);                          //Función que realiza operaciones sobre el parámetro dni
    int deleteJugador(Jugador const &jugador);                          //Función que realiza operaciones sobre el objeto jugador de la clase Jugador
    void escribeJugadores();                                            //Función que realiza operaciones sobre la lista de jugadores
    void leeJugadores();                                                //Función que realiza operaciones sobre el fichero jugadores.txt creado en la función escribeJugadores
    void giraRuleta();                                                  //Función que simula el giro de una ruleta y la obtención de un número aleatorio de la misma 
    void getPremios();                                                  //Función que realiza operaciones sobre los jugadores actualizando el dinero y las apuestas realizadas
    bool esRoja(int const &valor);                                      //Función que realiza operaciones sobre el valor de la bola para determinar si esta es roja
    bool esPar(int const &valor);                                       //Función que realiza operaciones sobre el valor de la bola para determinar si esta es par
    bool esAlto(int const &valor);                                      //Función que realiza operaciones sobre el valor de la bola para determinar si esta es un número alto
};

#endif