//dados.cc
//Cuerpo de los métodos de la clase dados

#include <iostream>
#include <ctime>
#include "dados.h"

Dados::Dados(){
    srand(time(NULL));          //Función para crear número aleatorios a partir del reloj del sistema
    d1_=1;                      //Valor inicial del dado 1
    d2_=1;                      //Valor inicial del dado 2
    cont1_=0;                   //Valor inicial lanzamientos1
    cont2_=0;                   //Valor inicial lanzamientos2
    med1_=0;                    //Valor inicial de la suma de valores del dado 1
    med2_=0;                    //Valor inicial de la suma de valores del dado 2
}

void Dados::lanzamiento(){
    d1_=(rand()%6)+1;           //Damos al dado 1 un valor aleatorio entre 1 y 6 (+1 para obtener el 6 y descartar el 0)
    d2_=(rand()%6)+1;           //Damos al dado 2 un valor aleatorio entre 1 y 6 (+1 para obtener el 6 y descartar el 0)
    cont1_++;                   //Aumentamos el valor de la variable cont1_ (para la función getLanzamientos1())
    cont2_++;                   //Aumentamos el valor de la variable cont2_ (para la función getLanzamientos2())
    med1_=med1_+d1_;            //En med1_ guardamos los valores del dado 1, al principio med1_=0 (para la función getMedia1())
    med2_=med2_+d2_;            //En med2_ guardamos los valores del dado 2, al principio med2_=0 (para la función getMedia2()) 

    for(int i=4; i>0; i--){     //Con este bucle hacemos el traspaso de los valor de una posición del vector a otra (para la función getUltimos1())
        vultimo1_[i]=vultimo1_[i-1];//El valor de la posición i-1 pasa a la posición i, es decir, vultimos1_[4] va a guardar el valor de vultimos1_[3] y asi sucesivamente hasta salir del bucle
    }  
    vultimo1_[0]=d1_;           //vultimo1_[0] siempre va a tener el último valor obtenido por lo que siempre va a tener el valor de d1_ 

    for(int i=4; i>0; i--){     //Con este bucle hacemos el traspaso de los valor de una posición del vector a otra (para la función getUltimos2())
        vultimo2_[i]=vultimo2_[i-1];//El valor de la posición i-1 pasa a la posición i, es decir, vultimos2_[4] va a guardar el valor de vultimos2_[3] y asi sucesivamente hasta salir del bucle
    }  
    vultimo2_[0]=d2_;           //vultimo2_[0] siempre va a tener el último valor obtenido por lo que siempre va a tener el valor de d2_    
}

bool Dados::setDado1(int const &n){    //Recibimos un entero
    if(n>0 && n<7){             //Si el entero es un número entre 1 y 6 entramos
        d1_=n;                  //Asignamos a d1_ el valor del entero
        cont1_++;               //Aumentamos el valor de la variable cont1_ (para la función getLanzamientos1())
        med1_=med1_+d1_;        //Sumamos a med1_ el valor de d1_ (para la función getMedia1()) 

        for(int i=4; i>0; i--){ //Con este bucle hacemos el traspaso de los valor de una posición del vector a otra (para la función getUltimos1())
            vultimo1_[i]=vultimo1_[i-1];//El valor de la posición i-1 pasa a la posición i, es decir, vultimos1_[4] va a guardar el valor de vultimos1_[3] y asi sucesivamente hasta salir del bucle
        }  
        vultimo1_[0]=d1_;        //vultimo1_[0] siempre va a tener el último valor obtenido por lo que siempre va a tener el valor de d1_  

        return true;            //Retornamos True
    }
    return false;               //Retornamos False si no entramos en el if

}

bool Dados::setDado2(int const &n){    //Recibimos un entero
    if(n>0 && n<7){             //Si el entero es un número entre 1 y 6 entramos
        d2_=n;                  //Asignamos a d1_ el valor del entero
        cont2_++;               //Aumentamos el valor de la variable cont2_ (para la función getLanzamientos2())
        med2_=med2_+d2_;        //Sumamos a med2_ el valor de d2_ (para la función getMedia2()) 

        for(int i=4; i>0; i--){ //Con este bucle hacemos el traspaso de los valor de una posición del vector a otra (para la función getUltimos2())
            vultimo2_[i]=vultimo2_[i-1];//El valor de la posición i-1 pasa a la posición i, es decir, vultimos2_[4] va a guardar el valor de vultimos2_[3] y asi sucesivamente hasta salir del bucle
        }  
        vultimo2_[0]=d2_;        //vultimo2_[0] siempre va a tener el último valor obtenido por lo que siempre va a tener el valor de d2_

        return true;            //Retornamos True
    }
    return false;               //Retornamos False si no entramos en el if

}

float Dados::getMedia1()const{
    if(cont1_==0){              //Si cont1_=0, no se habrá lanzado el dado por lo que el valor inicial de d1_=1 y este no se debe de contar
        return 0;               //Devolvemos 0 al no haberse lanzado aún el dado 1
    }
    return ((float)(med1_/cont1_));//Devolvemos la media que es la división de las dos variables contador pasadas como float 
}

float Dados::getMedia2()const{
    if(cont2_==0){              //Si cont2_=0, no se habrá lanzado el dado por lo que el valor inicial de d2_=1 y este no se debe de contar
        return 0;               //Devolvemos 0 al no haberse lanzado aún el dado 2
    }
    return((float)(med2_/cont2_));//Devolvemos la media que es la división de las dos variables contador pasadas como float 
}


void Dados::getUltimos1(int v[]){//Recibimos un vector de enteros
    v[0]=vultimo1_[0];          //v[0] pasa a tener el valor de vultimo1_[0]
    v[1]=vultimo1_[1];          //v[1] pasa a tener el valor de vultimo1_[1]
    v[2]=vultimo1_[2];          //v[2] pasa a tener el valor de vultimo1_[2]
    v[3]=vultimo1_[3];          //v[3] pasa a tener el valor de vultimo1_[3]
    v[4]=vultimo1_[4];          //v[4] pasa a tener el valor de vultimo1_[4]

}

void Dados::getUltimos2(int v[]){//Recibimos un vector de enteros
    v[0]=vultimo2_[0];          //v[0] pasa a tener el valor de vultimo2_[0]
    v[1]=vultimo2_[1];          //v[1] pasa a tener el valor de vultimo2_[1]
    v[2]=vultimo2_[2];          //v[2] pasa a tener el valor de vultimo2_[2]
    v[3]=vultimo2_[3];          //v[3] pasa a tener el valor de vultimo2_[3]
    v[4]=vultimo2_[4];          //v[4] pasa a tener el valor de vultimo2_[4]     

}

int Dados::getDiferencia()const{
    if(d1_>d2_){                //Si el dado 1 posee un valor mayor que el dado 2
        return d1_-d2_;         //Devolvemos la diferencia del dado 1 con el dado 2
    }
    return d2_-d1_;             //Si no es así, devolvemos la diferencia del dado 2 con el dado 1
}