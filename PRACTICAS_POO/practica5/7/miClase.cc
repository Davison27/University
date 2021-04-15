//miClase.cc
//Realiza la división de los números de la parte privada de la clase

#include <iostream>

template <class T>

class MiClase{
    private:
    T x_;                                                                           //Declaración de un parámetro tipo T con nombre x_
    T y_;                                                                           //Declaración de un parámetro tipo T con nombre y_

    public:
    MiClase(T a, T b){x_=a; y_=b};                                                  //Constructor de la clase MiClase la cual asigna a dos parámetros el valor de las variables privadas
    T div(){return x_/y_;};                                                         //Función que realiza la división en las variables de la parte privada
};

int main(){
    MiClase <int> iob(10,5);                                                        //Declaramos un objeto de tipo entero con dos parámetros
    MiClase <float> fob(3.3,5.5);                                                   //Declaramos un obejto de tipo float con dos parámetros

    std::cout << "division de enteros= " << iob.div() << "\n";                      //Imprimimos por pantalla el resultado de la división de enteros
    std::cout << "división de flotantes= " << fob.div() << "\n";                    //Imprimimos por pantalla el resultado de la división de flotantes
}