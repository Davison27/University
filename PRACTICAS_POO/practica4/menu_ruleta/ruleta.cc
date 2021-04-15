//ruleta.cc
//Cuerpo de los métodos de la clase Ruleta
#include <iostream>
#include <fstream>
#include "ruleta.h"


Ruleta::Ruleta(Crupier crupier):crupier_(crupier.getDNI(),crupier.getCodigo()){                              //Declaramos al constructor pasándole como parámetro un objeto (crupier) de la clase crupier
    bola_=-1;                                                                   //La bola se inicializa en el constructor con el valor -1
    banca_=1000000;                                                             //La banca se inicializa en el constructor con el valor 1000000
    nLanzamientos_=0;
    ganadoBanca_=0;

    
}

bool Ruleta::setBanca(int const &banca){
    if(banca>0){                                                                //Si el valor de n es positivo, entramos dentro
        banca_=banca;                                                           //El valor de banca pasa a ser el valor de banca_
        return true;                                                            //Retornamos true
    }
    return false;                                                               //Retornamos false
}

bool Ruleta::setBola(int const &bola){
    if(bola>=0 && bola<37){                                                     //Si el valor de n esta comprendido entre 0 y 36, entramos
        bola_=bola;                                                             //El valor de bola pasa a ser el valor de bola_
        ++nLanzamientos_;                                                       //Aumentamos la variable nLanzamientos para posteriormente saber cuantas veces se ha lanzado la bola
        return true;                                                            //Retornamos true
    }
    return false;                                                               //Retornamos false
}

void Ruleta::setCrupier(Crupier const &crupier){
    crupier_=crupier;                                                           //El valor de crupier pasa a ser el valor de crupier_
}

bool Ruleta::addJugador(Jugador const &jugador){                                       //Le pasamos a la función un objeto de la clase Jugador que es el propio jugador
    std::list<Jugador>::iterator a;                                             //Declaración de un iterator llamado a para buscar valores por la lista Jugadores
    for(a=jugadores_.begin(); a!=jugadores_.end(); a++){                        //Declaración de un bucle for donde asignamos a "a" el valor inicial de la lista y leerá valores hasta que llegue al final de la lista
        if(a->getDNI()==jugador.getDNI()){                                      //Si encontramos dentro de la lista al jugador que le hemos pasado, entonces entramos dentro
            return false;                                                       //Retornamos false y salimos de la función
        }
    }
    jugadores_.push_back(jugador);                                              //Si salimos del bucle, entonces ponemos al jugadores en la última posición de la lista
    std::fstream f;                                                             //Declaramos una variable de tipo fstream que nos servirá para abrir el fichero
    f.open((jugador.getDNI()+".txt"), std::ios_base::app);                      //Abrimos el fichero el cual se va a llamar dni.txt
    f.close();                                                                  //Cerramos el fichero pues no nos pide que dentro de este hagamos alguna operación
    return true;                                                                //Devolvemos true y salimos de la función
}

int Ruleta::deleteJugador(std::string const &dni){                                     //Le pasamos a la función un objeto de la clase Jugador que es el propio jugador
    if(jugadores_.empty()){                                                     //Si la lista de jugadores esta vacia, entonces entramos dentro
        return -1;                                                              //Devolvemos -1 y nos salimos de la función
    }
    std::list<Jugador>::iterator b;                                             //Declaración de un iterator llamado b para buscar valores por la lista Jugador
    for(b=jugadores_.begin(); b!=jugadores_.end();b++){                         //Declaración de un bucle for donde asignamos a "b" el valor inicial de la lista y leerá valores hasta que llegue al final de la lista
        if(b->getDNI()==dni){                                                   //Si encontramos dentro de la lista al jugador que le hemos pasado, entonces entramos dentro
            jugadores_.erase(b);                                                //Borramos de la lista el dni correspondiente al iterator b
            return 1;                                                           //Devolvemos 1 y nos salimos de la función
        }
    }
    return -2;                                                                  //Si no hemos encontrado al jugador, entonces salimos de la función devolviendo -2
    //En ningun momento estamos borrando el fichero del jugador a pesar de borrarlo de la lista
}

int Ruleta::deleteJugador(Jugador const &jugador){
    if(jugadores_.empty()){                                                     //Si la lista de jugadores esta vacia, entonces entramos dentro
        return -1;                                                              //Devolvemos -1 y nos salimos de la función
    }
    std::list<Jugador>::iterator c;                                             //Declaración de un iterator llamado b para buscar valores por la lista Jugador
    for(c=jugadores_.begin(); c!=jugadores_.end();c++){                         //Declaración de un bucle for donde asignamos a "b" el valor inicial de la lista y leerá valores hasta que llegue al final de la lista
        if(c->getDNI()==jugador.getDNI()){                                      //Si encontramos dentro de la lista al jugador que le hemos pasado, entonces entramos dentro
            jugadores_.erase(c);                                                //Borramos de la lista el dni correspondiente al iterator b
            return 1;                                                           //Devolvemos 1 y nos salimos de la función
        }
    }
    return -2;                                                                  //Si no hemos encontrado al jugador, entonces salimos de la función devolviendo -2
    //En ningun momento estamos borrando el fichero del jugador a pesar de borrarlo de la lista
}

void Ruleta::escribeJugadores(){
    std::fstream f;                                                             //Declaramos una variable de tipo fstream que servirá para la apertura del fichero
    std::list<Jugador>::iterator d;                                             //Declaramos una variable de tipo iterator que nos servirá para la lectura de la lista
    f.open("jugadores.txt",std::ios_base::out);                                 //Abrimos el fichero denominado "jugadores.txt"

    for(d=jugadores_.begin(); d!=jugadores_.end(); d++){                        //Entramos dentro del bucle for que nos recorrera toda la lista 
        f<<d->getDNI()<<","<<
        d->getCodigo()<<","<<
        d->getNombre()<<","<<
        d->getApellidos()<<","<<
        d->getDireccion()<<","<<
        d->getLocalidad()<<","<<
        d->getProvincia()<<","<<
        d->getPais()<<","<<
        d->getDinero()<<","<<std::endl;
    }
    f.close();                                                                  //Cerramos el fichero al terminar de escribir todos los valores
}

void Ruleta::leeJugadores(){
    std::ifstream f("jugadores.txt");                                           //Abrimos el fichero jugadores.txt                
    jugadores_.clear();                                                         //Limpiamos la lista de jugadores
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
  f.close();                                                                    //Cerramos el fichero de datos jugadores.txt
}


void Ruleta::giraRuleta(){
    srand(time(NULL));                                                          //Función que sirve para la obtención de números aleatorios
    bola_=(rand()%37);                                                          //Generamos un número aleatorio entre 0 y 36 que guardamos en la variable bola_
    ++nLanzamientos_;                                                           //Aumentamos la variable nLanzamientos para saber luego cuantos hemos realizado
}

void Ruleta::getPremios(){
    std::list<Jugador>::iterator e;                                             //Declaramos un iterador que nos servirá para recorrer la lista de jugadores
    for(e=jugadores_.begin(); e!=jugadores_.end(); e++){                        //Bucle que recorrerá la lista de jugadores desde el principio hasta el final
        e->setApuestas();                                                       //Cargo la apuesta del jugador en el iterador
        std::list<Apuesta> aux = e->getApuestas();
        for(auto f=aux.begin(); f!=aux.end(); f++){
            Apuesta apuesta=*f;
            switch(apuesta.tipo){
                case 1:
                    if(bola_ == stoi(apuesta.valor)){                           //Si la bola que tenemos es igual que el valor de la apuesta entramos (transformamos porque valor es un string)
                        e->setDinero(e->getDinero()+(apuesta.cantidad*35));     //El iterador de la lista jugadores abre el dinero del jugadory le suma el valor de la apuesta multiplicado por 35
                        setBanca(getBanca()-35*apuesta.cantidad);               //A la banca le restamos lo que tiene menos lo que se ha llevado el jugador
                        ganadoBanca_-=35*apuesta.cantidad;                         //Lo ganado por la banca es lo mismo que la cantidad apostada - lo que ya hubiese ganado la banca en otras tiradas
                    }

                    else{                                                       //Si el valor de la bola es distinto al apostado entramos dentro
                        setBanca(getBanca()+apuesta.cantidad);                  //Abrimos la banca y le sumamos el dinero apostado
                        e->setDinero(e->getDinero()-apuesta.cantidad);          //Abrimos el dinero que posee el jugador y le restamos el que ha apostado
                        ganadoBanca_+=apuesta.cantidad;                         //Lo ganado por la banca es lo mismo que la cantidad apostada + lo que ya hubiese ganado la banca en otras tiradas
                    }
                break;


                case 2:
                    if(bola_==0){
                        setBanca(getBanca()+apuesta.cantidad);                  //Abrimos la banca y le sumamos el dinero apostado
                        e->setDinero(e->getDinero()-apuesta.cantidad);          //Abrimos el dinero que posee el jugador y le restamos el que ha apostado
                        ganadoBanca_+=apuesta.cantidad;                         //Lo ganado por la banca es lo mismo que la cantidad apostada + lo que ya hubiese ganado la banca en otras tiradas
                    }

                    else if((apuesta.valor=="rojo" && esRoja(bola_)) || (apuesta.valor=="negro" && !esRoja(bola_))){
                        e->setDinero(e->getDinero()+apuesta.cantidad);          //El iterador de la lista jugadores abre el dinero del jugadory le suma el valor de la apuesta
                        setBanca(getBanca()-apuesta.cantidad);                  //A la banca le restamos lo que tiene menos lo que se ha llevado el jugador
                        ganadoBanca_-=apuesta.cantidad;                         //Lo ganado por la banca es lo mismo que la cantidad apostada - lo que ya hubiese ganado la banca en otras tiradas
                    }

                    else{
                        setBanca(getBanca()+apuesta.cantidad);                  //Abrimos la banca y le sumamos el dinero apostado
                        e->setDinero(e->getDinero()-apuesta.cantidad);          //Abrimos el dinero que posee el jugador y le restamos el que ha apostado
                        ganadoBanca_+=apuesta.cantidad;                         //Lo ganado por la banca es lo mismo que la cantidad apostada + lo que ya hubiese ganado la banca en otras tiradas
                    }
                break;


                case 3:
                    if(bola_==0){
                        setBanca(getBanca()+apuesta.cantidad);                  //Abrimos la banca y le sumamos el dinero apostado
                        e->setDinero(e->getDinero()-apuesta.cantidad);          //Abrimos el dinero que posee el jugador y le restamos el que ha apostado
                        ganadoBanca_+=apuesta.cantidad;                         //Lo ganado por la banca es lo mismo que la cantidad apostada + lo que ya hubiese ganado la banca en otras tiradas
                    }

                    else if((apuesta.valor=="par" && esPar(bola_)) || (apuesta.valor=="impar" && !esPar(bola_))){
                        e->setDinero(e->getDinero()+apuesta.cantidad);          //El iterador de la lista jugadores abre el dinero del jugadory le suma el valor de la apuesta
                        setBanca(getBanca()-apuesta.cantidad);                  //A la banca le restamos lo que tiene menos lo que se ha llevado el jugador
                        ganadoBanca_-=apuesta.cantidad;                         //Lo ganado por la banca es lo mismo que la cantidad apostada - lo que ya hubiese ganado la banca en otras tiradas
                    }

                    else{
                        setBanca(getBanca()+apuesta.cantidad);                  //Abrimos la banca y le sumamos el dinero apostado
                        e->setDinero(e->getDinero()-apuesta.cantidad);          //Abrimos el dinero que posee el jugador y le restamos el que ha apostado
                        ganadoBanca_+=apuesta.cantidad;                         //Lo ganado por la banca es lo mismo que la cantidad apostada + lo que ya hubiese ganado la banca en otras tiradas
                    }
                break;


                case 4:
                    if(bola_==0){
                        setBanca(getBanca()+apuesta.cantidad);                  //Abrimos la banca y le sumamos el dinero apostado
                        e->setDinero(e->getDinero()-apuesta.cantidad);          //Abrimos el dinero que posee el jugador y le restamos el que ha apostado
                        ganadoBanca_+=apuesta.cantidad;                         //Lo ganado por la banca es lo mismo que la cantidad apostada + lo que ya hubiese ganado la banca en otras tiradas
                    }

                    else if((apuesta.valor=="alto" && esAlto(bola_)) || (apuesta.valor=="bajo" && !esAlto(bola_))){
                        e->setDinero(e->getDinero()+apuesta.cantidad);          //El iterador de la lista jugadores abre el dinero del jugadory le suma el valor de la apuesta
                        setBanca(getBanca()-apuesta.cantidad);                  //A la banca le restamos lo que tiene menos lo que se ha llevado el jugador
                        ganadoBanca_-=apuesta.cantidad;                         //Lo ganado por la banca es lo mismo que la cantidad apostada - lo que ya hubiese ganado la banca en otras tiradas
                    }

                    else{
                        setBanca(getBanca()+apuesta.cantidad);                  //Abrimos la banca y le sumamos el dinero apostado
                        e->setDinero(e->getDinero()-apuesta.cantidad);          //Abrimos el dinero que posee el jugador y le restamos el que ha apostado
                        ganadoBanca_+=apuesta.cantidad;                         //Lo ganado por la banca es lo mismo que la cantidad apostada + lo que ya hubiese ganado la banca en otras tiradas
                    }
                break;
            }
        }
    } 
}

bool Ruleta::esRoja(int const &valor){                                          //A la función le pasamos los valores de la bola para saber si son rojas o no
    int NumRojos[18]={1,3,5,7,9,12,14,18,19,21,23,25,27,30,32,34,36};           //Declaramos un vector que guarda los valores en los que la bola es roja
    for(int i=0; i<18 ; i++){                                                   //Declaramos un bucle for donde buscará entre el vector para determinar si es roja
        if(valor==NumRojos[i]){                                                 //Si el valor de la bola es igual que alguno de los valores del vector entramos dentro
            return true;                                                        //Devolvemos true
        }
    }
    return false;                                                               //En caso contrario devolvemos false
}

bool Ruleta::esPar(int const &valor){                                           //A la función le pasamos los valores de la bola para saber si son pares o no
    if(valor%2==0){                                                             //Si el resto del valor de la contra entre 2 es 0 entramos dentro pues es par
        return true;                                                            //Devolvemos true
    }
    return false;                                                               //En caso constrario devolvemos false
}

bool Ruleta::esAlto(int const &valor){
    if(valor>=1 && valor<=18){                                                  //Si el valor de la bola está entra 1 y 18 entramos dentro
        return false;                                                           //Devolvemos false
    }
    return true;                                                                //En caso constrario devolvemos true
}

void Ruleta::getEstadoRuleta(int &nJugadores, int &dineroMesa, int &nLanzamientos, int &ganadoBanca){
    nJugadores= (int) jugadores_.size();                                        //Guardamos en nJugadores la cantidad de objetos que haya en la lista jugadores_
    nLanzamientos=nLanzamientos_;                                               //El número de lanzamientos es igual al valor que hay en la variable privada nLanzamientos_
    ganadoBanca=ganadoBanca_;                                                   //El dinero ganado por la banca es igual al número guardado en la variable privada ganadoBanca_
    dineroMesa=banca_;                                                          //El dinero que hay en la mesa es el dinero que posee la banca +

    std::list<Jugador>::iterator g;                                             //Declaramos un iterador de la lista jugadores_ para saber el dinero que poseen cada uno de ellos
    for(g=jugadores_.begin(); g!=jugadores_.end(); g++){                        //Hacemos un bucle con el iterador que no terminará hasta que llegue al final de la lista
        dineroMesa+=g->getDinero();                                             //A parte del dinero de la banca, le sumamos el dinero de lada uno de los jugadores a dineroMesa
    }

}
