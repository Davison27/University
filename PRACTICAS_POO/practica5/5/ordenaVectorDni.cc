//ordenaVectorDni.cc
//Ordena un vector de DNIs de forma ascendente o descendente según indique el usuario

#include <iostream>
#include <fstream>
#include <vector>
#include "jugador.h"


bool asc(Jugador j1, Jugador j2){return j1.getDNI()>j2.getDNI();};
bool desc(Jugador j1, Jugador j2){return j1.getDNI()<j2.getDNI();};

std::vector<Jugador> leeJugadores(){
    std::vector<Jugador> jugadores_;
    jugadores_.empty();
    std::ifstream f("jugadores.txt");                                           //Abrimos el fichero jugadores.txt                
    Jugador jugador("a","a");
    std::string cad;                                                            //Declaramos una variable auxiliar de tipo string llamada cad
    getline(f, cad,',');                                                        //Leemos el primer parámetro del fichero hasta la ","
    while (!f.eof()){                                                           //Mientras no lleguemos al final del fichero vamos a seguir leyendo datos
        jugador.setDNI(cad);                                                    //Guardamos el primer parámetro en la lista 
        getline(f, cad,',');
        jugador.setCodigo(cad);                                                 //Guardamos el segundo parámetro en la lista 
        getline(f, cad,',');
        jugador.setNombre(cad);                                                 //Guardamos el tercero parámetro en la lista 
        getline(f, cad,',');
        jugador.setApellidos(cad);                                              //Guardamos el cuarto parámetro en la lista 
        getline(f, cad,',');
        jugador.setDireccion(cad);                                              //Guardamos el quinto parámetro en la lista 
        getline(f, cad,',');
        jugador.setLocalidad(cad);                                              //Guardamos el sexto parámetro en la lista 
        getline(f, cad,',');
        jugador.setProvincia(cad);                                              //Guardamos el septimo parámetro en la lista 
        getline(f, cad,',');
        jugador.setPais(cad);                                                   //Guardamos el octavo parámetro en la lista 
        getline(f, cad,'\n');
        jugador.setDinero(std::stoi(cad));                                      //Guardamos el primer parámetro en la lista 
        jugadores_.push_back(jugador);                                          //volcamos la información de la lista auxiliar jugador creada al final de la lista jugadores_
        getline(f, cad,',');                                                    //Volvemos a empezar el bucle pero desde la siguiente linea del fichero
    }
  f.close();                                                                    //Cerramos el fichero
  return jugadores_;                                                            //Devolvemos el vector de jugadores
}


int main(){
    std::vector<Jugador> jugadores;
    jugadores=leeJugadores();
    int selec;

    std::cout << "DNIs del vector" << "\n\n";
    for(int i=0; i<(int) jugadores.size() ; i++){                                       //Creamos un bucle para ir introduciendo los elementos del vector
        std::cout << jugadores[i].getDNI()<< "\n";                                      //Vamos asignando valores al vector
    }

    std::cout << "Seleccione una de las siguientes opciones: " << "\n";
    std::cout << "1 -  Ascendente " << "\n";
    std::cout << "2 -  Descendente " << "\n";
    std::cin >> selec;                                                                  //Asignamos uno de los valores a la variable selec

    switch(selec){                                                                      //creamos un switch para la selección de una de las dos opciones

        case 1: std::sort(jugadores.begin(),jugadores.end(),asc);

        case 2: std::sort(jugadores.begin(),jugadores.end(),desc);
    }

    std::cout << "DNIs del vector ordenado" << "\n\n";
    for(int i=0; i<(int) jugadores.size() ; i++){                                       //Creamos un bucle para ir introduciendo los elementos del vector
        std::cout << jugadores[i].getDNI()<< "\n";                                      //Vamos asignando valores al vector
    }

    std::cout << "\n";
    std::cout << "Fin del programa";
    return 0;
}