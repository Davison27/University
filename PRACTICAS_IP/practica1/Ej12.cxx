#include <iostream>
using namespace std;
int main(){
	int dia;
	cout<<"Introduzca un número del 1 al 7"<<endl;
	cout<<"1 es Lunes"<<endl;
	cout<<"2 es Martes"<<endl;
	cout<<"3 es Miercoles"<<endl;
	cout<<"4 es Jueves"<<endl;
	cout<<"5 es Viernes"<<endl;
	cout<<"6 es Sábado"<<endl;
	cout<<"7 es Domingo"<<endl;
	cin>>dia;
	switch (dia){
		case 1:{
			cout<<"Hoy es lunes"<<endl;
		}break;
		case 2:{
			cout<<"Hoy es Martes"<<endl;
		}break;
		case 3:{
			cout<<"Hoy es Miercoles"<<endl;
		}break;
		case 4:{
			cout<<"Hoy es Jueves"<<endl;
		}break;
		case 5:{
			cout<<"Hoy es Viernes"<<endl;
		}break;
		case 6:{
			cout<<"Hoy es Sabado"<<endl;
		}break;
		case 7:{
			cout<<"Hoy es Domingo"<<endl;
		}break;
		default:{
			cout<<"Error valor insertado no válido"<<endl;
		}
	}
cin.ignore();
cin.get();
}