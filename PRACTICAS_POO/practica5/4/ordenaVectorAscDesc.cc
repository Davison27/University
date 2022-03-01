//ordenaVectorAscDesc.cc
//Ordena un vector de forma ascendente o descendente según el usuario
#include <iostream>

bool descendente(int i, int j) { return i > j; }


int main(){
    int n=0;                                                                            //Declaramos una variable de tipo entero para guardar el tamaño del vector
    int selec=0;
    int v[n];                                                                           //Declaramos un vector de tamaño n
    std::cout << "Tamaño del vector: ";
    std::cin >> n;                                                                      //Asignamos un valor a n

    std::cout << "Introduzca los elementos del vector" << "\n\n";
    for(int i=0; i<n ; i++){                                                            //Creamos un bucle para ir introduciendo los elementos del vector
        std::cin >> v[i];                                                               //Vamos asignando valores al vector
    }

    std::cout << "Seleccione una de las siguientes opciones: " << "\n";
    std::cout << "1 -  Ascendente " << "\n";
    std::cout << "2 -  Descendente " << "\n";
    std::cin >> selec;                                                                  //Asignamos uno de los valores a la variable selec

    switch(selec){                                                                      //creamos un switch para la selección de una de las dos opciones

        case 1: std::sort(v, v+n);                                                      //Ordenación de los elementos del vector con la función sort
                std::cout << "El vector ordenado en forma ascendente es: "<<"\n";
                for(int i=0; i<n; i++){                                                 //Creamos un bucle para ir mostrando por pantalla los elementos del vector ordenados
                std::cout << v[i] << "|" ;                                              //Vamos mostrando los valores uno a uno y separados con una |
                }

        case 2: std::sort(v, v+n, descendente);                                         //En este caso, a la función sort le tenemos que pasar un tercer parámetro que lo envía a la función descendente para poder realizar la ordenación
                std::cout << "El vector ordenado en forma descendente es: "<<"\n";
                for(int i=0; i<n; i++){                                                 //Creamos un bucle para ir mostrando por pantalla los elementos del vector ordenados
                std::cout << v[i] << "|" ;                                              //Vamos mostrando los valores uno a uno y separados con una |
                }
    }

    std::cout << "\n";
    std::cout << "Fin del programa";
    return 0;
}