//ordenaVector.cc
//Programa que ordena un vector con la función sort()

#include <iostream>

int main(){
    int n=0;                                                                //Declaramos una variable de tipo entero para guardar el tamaño del vector
    int v[n];                                                               //Declaramos un vector de tamaño n
    std::cout << "Tamaño del vector: ";
    std::cin >> n;                                                          //Asignamos un valor a n

    std::cout << "Introduzca los elementos del vector" << "\n";
    for(int i=0; i<n ; i++){                                                //Creamos un bucle para ir introduciendo los elementos del vector
        std::cin >> v[i];                                                   //Vamos asignando valores al vector
    }

    std::sort(v, v+n);                                                      //Ordenación de los elementos del vector con la función sort

    std::cout << "El vector ordenado es: "<<"\n";
    for(int i=0; i<n; i++){                                                 //Creamos un bucle para ir mostrando por pantalla los elementos del vector ordenados
        std::cout << v[i] << "|" ;                                          //Vamos mostrando los valores uno a uno y separados con una |
    }

    std::cout << "\n";
    std::cout << "Fin del programa";
    return 0;
}