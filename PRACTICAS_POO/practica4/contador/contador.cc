//contador.cc
//Cuerpo de los métodos de la clase Contador

#include <iostream>
#include "contador.h"

Contador::Contador(int valor, int min, int max){                    //Constructor de la clase contador con 3 parámetros
    if(min>max || max<min || valor>max || valor<min){               //Si se cumple alguna de estas condiciones, entramos                  
        valor=0;                                                    //Ponemos valor con su valor por defecto
        min=0;                                                      //Ponemos min con su valor por defecto
        max=1000;                                                   //Ponemos max con su valor por defecto
    }
    valor_=valor;                                                   //valor_ pasa a tener el valor de valor
    min_=min;                                                       //min_ pasa a tener el valor de min
    max_=max;                                                       //max_ pasa a tener el valor de max
    operaciones_.push_back(*this);                                  //Guardamos en la lista los valores modificados
}

void Contador::Valor(){
    if(valor_<min_){                                                //Si el valor es menor que el valor min_ que puede tomar entramos 
        valor_=min_;                                                //Valor_ pasa a tener el valor de min_
    }

    else if(valor_>max_){                                           //Si el valor es mayor que el valor max_ que puede tomar entramos 
        valor_=max_;                                                //Valor_ pasa a tener el valor max_
    }
    operaciones_.push_back(*this);                                  //Como siempre pasamos por esta función, vamos guardando los valores modificados en la lista
}

Contador Contador::operator=(const int &a){
    valor_=a;                                                       //Le asignamos a valo_ el valor del entero a
    Valor();                                                        //Llamamos a la función Valor() para comprobar que valor_ no excede los límites
    return *this;                                                   //Retornamos el *this
}

Contador Contador::operator=(const Contador &c){
    valor_=c.valor_;                                                //Le asignamos a valor_ el valor del otro contador
    min_=c.min_;                                                    //Le asignamos a min_ el valor mínimo del otro contador
    max_=c.max_;                                                    //Le asignamos a max_ el valor máximo del otro contador
    Valor();                                                        //Llamamos a la función Valor() para comprobar que valor_ no excede los límites
    return *this;                                                   //Retornamos el *this
}

Contador Contador::operator++(void){
    valor_++;                                                       //Aumentamos el valor del contador
    Valor();                                                        //Llamamos a la función Valor() para comprobar que valor_ no excede los límites
    return *this;                                                   //Retornamos el *this
}

Contador Contador::operator++(int){
    Contador aux=*this;                                             //Le asignamos a un contador auxiliar el *this
    valor_++;                                                       //Aumentamos el valor del contador
    Valor();                                                        //Llamamos a la función Valor() para comprobar que valor_ no excede los límites
    return aux;                                                     //Retornamos el contador aux
}

Contador Contador::operator--(void){
    valor_--;                                                       //Decrementamos el valor del contador
    Valor();                                                        //Llamamos a la función Valor() para comprobar que valor_ no excede los límites
    return *this;                                                   //Retornamos el *this
}

Contador Contador::operator--(int){
    Contador aux=*this;                                             //Le asignamos a un contador auxiliar el *this
    valor_--;                                                       //Decrementamos el valor del contador
    Valor();                                                        //Llamamos a la función Valor() para comprobar que valor_ no excede los límites
    return aux;                                                     //Retornamos el contador aux
}

Contador Contador::operator+(const int &a){
    valor_=valor_+a;                                                //valor_ pasa a ser valor_ + el valor de a
    Valor();                                                        //Llamamos a la función Valor() para comprobar que valor_ no excede los límites
    return *this;                                                   //Retornamos el *this
}

Contador operator+(const int &a, const Contador &c){
    Contador aux;                                                   //Declaramos un contador auxiliar
    aux.valor_=a+c.valor_;                                          //El valor_ del contador auxiliar pasa a ser el valor del contador c + el valor de a 
    aux.min_=c.min_;                                                //El valor min_ del comtador auxiliar pasa a ser el valor min del contador c
    aux.max_=c.max_;                                                //El valor max_ del contador auxiliar pasa a ser le valor max del contador c
    aux.Valor();                                                        //Llamamos a la función Valor() para comprobar que valor_ no excede los límites
    return aux;                                                     //Retornamos el contador auxiliar 
}

Contador Contador::operator-(const int &a){
    valor_=valor_-a;                                                //valor_ pasa a ser valor_ - el valor de a
    Valor();                                                        //Llamamos a la función Valor() para comprobar que valor_ no excede los límites
    return *this;                                                   //Retornamos el *this
}

Contador operator-(const int &a, const Contador &c){
    Contador aux;                                                   //Declaramos un contador auxiliar
    aux.valor_=a-c.valor_;                                          //El valor_ del contador auxiliar pasa a ser el valor del contador c + el valor de a 
    aux.min_=c.min_;                                                //El valor min_ del comtador auxiliar pasa a ser el valor min del contador c
    aux.max_=c.max_;                                                //El valor max_ del contador auxiliar pasa a ser le valor max del contador c
    aux.Valor();                                                    //Llamamos a la función Valor() para comprobar que valor_ no excede los límites
    return aux;                                                     //Retornamos el contador auxiliar 
}


bool Contador::undo(const int &n){
    if(n>=(int)operaciones_.size() || n<1){                         //SI se cumple alguna de las condiciones, entramos dentro
        return false;                                               //Devolvemos false
    }
    for(int i=0; i<n ; i++){
        operaciones_.pop_back();                                           //Borramos el número de elementos de la lista que se especifiquen
    }
    *this=operaciones_.back();                                      //Guardamos en el contador el último valor de la lista pues antes hemos borrado valores
    return true;                                                    //Devolvemos true
}