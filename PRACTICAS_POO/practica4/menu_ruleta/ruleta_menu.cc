#include <iostream>
#include "ruleta.cc"

int main(){

    int op=0;                                                                                                       //Variable de tipo entero que nos servirá para escoger entre las opciones

    while(op!=7){
        std::cout << "                              Menú de la Ruleta                                 " << "\n";
        std::cout << "................................................................................" << "\n";
        std::cout << "Opción 1: Cargar jugadores del fichero jugadores.txt" << "\n";
        std::cout << "Opción 2: Guardar los jugadores en jugadores.txt" << "\n";
        std::cout << "Opción 3: Estado ruleta, dinero de la banca y dinero jugadores" << "\n";
        std::cout << "Opción 4: Girar la ruleta" << "\n";
        std::cout << "Opción 5: Eliminar un jugador de la mesa" << "\n";
        std::cout << "Opción 6: Añadir un jugador a la mesa" << "\n";
        std::cout << "Opción 7: Salir del programa" << "\n";
        std::cout << "................................................................................" << "\n";
        std::cout << "Opción : ";
        std::cin >> op;

        switch(op){

            case 1:

            case 2:

            case 3:

            case 4:

            case 5:
            
            case 6:
        
        }
    }
}