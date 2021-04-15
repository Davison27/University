#include <iostream>
#include "jugador.cc"

int main(){
    std::string DNI;                            //Variable de tipo string que almacena el dni de un jugador
    std::string codigo;                         //Variable de tipo string que almacena el codigo de un jugador
    std::list<Apuesta> apuestas;                //variable de tipo list que almacena las apuestas de un jugador

    std::cout << "..............................................................." << "\n";
    std::cout << "Introduzca los siguientes datos:" << "\n";
    std::cout << "..............................................................." << "\n";
    std::cout << "DNI: ";
    std::cin >> DNI;
    std::cout << "\n";
    std::cout << "Código: ";
    std::cin >> codigo;
    std::cout << "\n";
    std::cout << "..............................................................." << "\n";

    Jugador a(DNI,codigo);                      //Creación del jugador a con dni ..... y codigo .....
    a.setApuestas();                            //Jugador realiza unas apuestas
    apuestas=a.getApuestas();                   //Se copian las apuestas en la lista de apuestas

    for(auto a=apuestas.begin(); a!= apuestas.end(); a++){      //creamos un iterador que introducimos dentro de la lista de apuestas para imprimir sus valores por pantalla
        std::cout << "..............................................................." << "\n";
        std::cout << "-------Tipo: "<< a->tipo<< "\n";
        std::cout << "-------Valor: "<< a->valor<< "\n";
        std::cout << "-------Cantidad: "<< a->cantidad<< "\n";
        std::cout << "..............................................................." << "\n";
    }

}