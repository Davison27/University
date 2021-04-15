//dados.h
//La clase dados representa el lanzamiento de 2 dados
#ifndef DADOS_H
#define DADOS_H

class Dados{
    private:
    int d1_;                                        //Declaración de una variable de tipo entero correspondiente al dado 1
    int d2_;                                        //Declaración de una variable de tipo entero correspondiente al dado 2
    int cont1_;                                     //Declaración de una variable de tipo entero que servirá como contador
    int cont2_;                                     //Declaración de una variable de tipo entero que servirá como contador
    float med1_;                                    //Declaración de una variable de tipo flotante que servirá para realizar una media
    float med2_;                                    //Declaración de una variable de tipo flotante que servirá para realizar una media
    int vultimo1_[5]={0,0,0,0,0};                   //Declaración de una variable de tipo entero que declara un vector de 5 enteros inicializados con valor 0, servirá para guardar los últimos 5 valores
    int vultimo2_[5]={0,0,0,0,0};                   //Declaración de una variable de tipo entero que declara un vector de 5 enteros inicializados con valor 0, servirá para guardar los últimos 5 valores

    public:
    Dados();                                                //Constructor de la clase Dados
    void lanzamiento();                                     //Función que obtiene un valor aleatorio para los dados
    inline int getDado1()const{return d1_;};                //Función que retorna el valor del dado 1
    inline int getDado2()const{return d2_;};                //Función que retorna el valor del dado 2
    inline int getSuma()const{return d1_+d2_;};             //Función que retorna la suma de los dos dados
    inline int getLanzamientos1()const{return cont1_;};     //Función que retorna el número de veces que el dado 1 ha sido lanzado
    inline int getLanzamientos2()const{return cont2_;};     //Función que retorna el número de veces que el dado 2 ha sido lanzado
    int getDiferencia()const;                               //Función que retorna la diferencia de los dos dados
    void getUltimos1(int v[]);                              //Función que devuelve los últimos 5 valores tomados por el dado 1
    void getUltimos2(int v[]);                              //Función que devuelve los últimos 5 valores tomados por el dado 2
    float getMedia1()const;                                 //Función que retorna la media de valores del dado 1
    float getMedia2()const;                                 //Función que retorna la media de valores del dado 2

    bool setDado1(int const &n);                            //Función que realiza operaciones sobre el dado 1 recibiendo un parámetro n
    bool setDado2(int const &n);                            //Función que realiza operaciones sobre el dado 2 recibiendo un parámetro n

    void Insertador();                                      //Función para mostrar los valores de los dos dados
    void Extractor();                                       //Función para asignar valores a los dados
};


#endif