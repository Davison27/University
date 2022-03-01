//juego.cc
//Programa principal para prueba de funcionamiento de la clase Dados
#include <iostream>
#include "dados.cc"

int main(){

    Dados d;                                                                                //Declaramos un objeto de la clase Dados
    int n=0;                                                                                //Parámetro que le pasaremos a las funciones setdado1 y setDado2
    int i=0;                                                                                //Parámetro que usaremos para el switch
    int v[5];                                                                               //Vector al cual le pasaremos los últimos resultados obetenidos por el dado 1 y 2

    while(i>0 && i<9){

        std::cout<<"--------------------    Elija una opción    --------------------\n";
        std::cout<<"Opción 1: Saber el valor del dado 1\n";
        std::cout<<"Opción 2: Saber el valor del dado 2\n";
        std::cout<<"Opción 3: Saber la suma de los dos dados\n";
        std::cout<<"Opción 4: Saber la diferencia de los dos dados\n";
        std::cout<<"Opción 5: Saber la media de los valores del dado 1\n";
        std::cout<<"Opción 6: Saber la media de los valores del dado 2\n";
        std::cout<<"Opción 7: Saber los 5 últimos valores del dado 1\n";
        std::cout<<"Opción 8: Saber los 5 últimos valores del dado 2\n";
        std::cout<<"Opción 9: Número de lanzamientos del dado 1 y 2\n";
        std::cout<<"Opción 10:lanzar dados\n";
        std::cout<<"Default: Salir del programa\n";
        std::cout<<"-----------------------------------------------------------------\n";
        std::cout<<"Introduzca una opción: ";
        std::cin>>i;


        switch(i){                                                                          //Declaramos un switch para el menú sencillo
            case 1:
                std::cout<<"Dado 1="<<d.getDado1()<<"\n";                                   //Imprimimos el valor del dado 1
            case 2:
                std::cout<<"Dado 2="<<d.getDado2()<<"\n";                                   //Imprimimos el valor del dado 2
            case 3:
                std::cout<<"Suma de los 2 dados="<<d.getSuma()<<"\n";                       //Imprimimos el valor de la suma del dado 1 con el dado 2
            case 4:
                std::cout<<"Diferencia de los 2 dados="<<d.getDiferencia()<<"\n";           //Imprimimos el valor de la diferencia del dado 1 con el dado 2
            case 5:
                std::cout<<"La media del dado 1="<<d.getMedia1()<<"\n";                     //Imprimimos el valor de la media de valores del dado 1
            case 6:
                std::cout<<"La media del dado 2="<<d.getMedia2()<<"\n";                     //Imprimimos el valor de la media de valores del dado 2
            case 7:
                d.getUltimos1(v);
                std::cout<<"Los últimos valores del dado 1="<<"\n";                         //Imprimimos los 5 últimos valores del dado 1
                for(int i=0; i<5 ; i++){
                    std::cout<<v[i]<<"|";
                }
            case 8:
                d.getUltimos2(v);
                std::cout<<"Los últimos valores del dado 2="<<"\n";                         //Imprimimos los 5 últimos valores del dado 1
                for(int i=0; i<5 ; i++){
                    std::cout<<v[i]<<"|";
                }
            case 9:
                std::cout<<"El dado 1 se ha lanzado: "<<d.getLanzamientos1()<<" veces"<<"\n";//Imprimimos el número de lanzamientos del dado 1
                std::cout<<"El dado 2 se ha lanzado: "<<d.getLanzamientos2()<<" veces"<<"\n";//Imprimimos el número de lanzamientos del dado 2
            
            case 10:
                d.lanzamiento();
                std::cout<<"Lanzamiento realizado"<<"\n";
            default:
                std::cout<<"Saliendo del programa"<<"\n";                                   //Imprimimos un mensaje de error ya que el número escogido no está dentro del rango de valores
        }
    }
}