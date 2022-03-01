#include <iostream>
using namespace std;
int main(){
	float practica,parcial,final,nota;
	cout<<"Introduzca la nota de las prácticas :"<<endl;
	cin>>practica;
	cout<<"Introduzca la nota de un parcial :"<<endl;
	cin>>parcial;
	cout<<"Introduzca la nota del examen final :"<<endl;
	cin>>final;
	nota=(0.25*practica)+(0.25*parcial)+(0.5*final);
	cout<<"La nota final del alumno es ."<<nota<<endl;
cin.ignore();
cin.get();
}
	