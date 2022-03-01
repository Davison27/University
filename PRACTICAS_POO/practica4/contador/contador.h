//Contador.h
//Archivo que contiene a la clase Contador

#ifndef CONTADOR_H
#define CONTADOR_H
#include <list>

class Contador{
    private:
    
    int valor_;                                                     //Declaración de una variable de tipo entero en la parte pública de la clase que guardará el valor del contador
    int min_;                                                       //Declaración de una variable de tipo entero en la parte pública de la clase que guardará el valor mínimo del contador
    int max_;                                                       //Declaración de una variable de tipo entero en la parte pública de la clase que guardará el valor máximo del contador

    std::list<Contador> operaciones_;                               //Declaración de una lista para guardar las operaciones que se vayan realizando a lo largo del programa
    void Valor();                                                   //Función que controlará el valor que toma valor_ en todo momento

    public:

    Contador( int valor=0, int min=0 , int max=1000);               //Constructor de la clase Contador

    Contador operator=(const int &a);                               //Operador de asignación (=) para asignar un entero
    Contador operator=(const Contador &c);                          //Operador de asignación (=) para asignar un contador

    Contador operator++(void);                                      //Operador ++ para incrementar un prefijo ++p
    Contador operator++(int);                                       //Operador ++ para incrementar un sufijo p++

    Contador operator--(void);                                      //Operador -- para decrementar un prefijo --p
    Contador operator--(int);                                       //Operador -- para decrementar un sufijo p--

    Contador operator+(const int &a);                               //operador + para la suma entre un entero y un objeto
    friend Contador operator+(const int &a, const Contador &c);     //operador + que devuelve un contador con la suma de un contador + a

    Contador operator-(const int &a);                               //operador - para la resta entre un entero y un objeto
    friend Contador operator-(const int &a, const Contador &c);     //operador - que devuelve un contador con la resta de un contador - a

    bool undo(const int &n=1);                                      //Función que deshace las n últimas operaciones, por defecto n=1

    inline int get()const{return valor_;};                          //Función observador que devuelve el valor actual del contador

};

#endif