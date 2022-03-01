//imprimeVector.cc
//Imprime un vector de enteros, otro de flotantes y otro de caracteres por pantalla

#include <iostream>
template <class tipo>                                                   //Para poder declarar un vector que funcione con cualquier tipo de variable

void imprimeVector(tipo v[], int n){                                    //Función que imprime un vector por pantalla, dando igual el tipo de parámetro que le pasemos (float, int o char)
    for(int i=0; i<n; i++){                                             //Creamos un bucle que recorrerá los elementos del vector
        std::cout<<v[i]<<" ";                                           //Imprimimos por pantalla cada uno de los elementos del vector

    }
    std::cout<<"\n";
}

int main(){
    int i[6]={1,3,5,7,4,2};                                             //Declaramos un vector i de tipo entero con 6 elementos 
    float f[3]={1.3,4.5,7.8};                                           //Declaramos un vector f de tipo float con 3 elementos
    char c[6]="David";                                                  //Declaramos un vector c de tipo char con la cadena David

    imprimeVector(i,6);                                                 //Llamamos a la función pasandole el vector de tipo entero
    imprimeVector(f,3);                                                 //Llamamos a la función pasandole el vector de tipo float
    imprimeVector(c,7);                                                 //Llamamos a la función pasandole el vector de tipo chars

}