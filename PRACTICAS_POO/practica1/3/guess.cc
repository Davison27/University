//guess.cc
//This program is a game 

#include <iostream>
#include <cstdlib>
#include <ctime>

int Numero(){
    int a=0;
    std::cout << "Introduzca un número :";
    std::cin >> a;
    return a;
}

int main(){

    int i=0 , a=0;

    i=Numero();
    srand(time(NULL));
    a=(rand()%10 + 1);

    while(i!=a){
        if(i<a){
            std::cout << "Error , el número es mayor \n";
        }
        if(i>a){
            std::cout << "Error , el número es menos \n";
        }
        i=Numero();
    }

    std::cout << "¡Correcto! , lo has adivinado\n";
    return 0;

}