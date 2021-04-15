#include <iostream>
using namespace std;
int main(){
	int mes;
	cout<<"Introduzca un número del 1 al 12 para saber cuantos días tiene el mes seleccionado"<<endl;
	cout<<"1 es Enero"<<endl;
	cout<<"2 es Febrero"<<endl;
	cout<<"3 es marzo"<<endl;
	cout<<"4 es Abril"<<endl;
	cout<<"5 es Mayo"<<endl;
	cout<<"6 es Junio"<<endl;
	cout<<"7 es Julio"<<endl;
	cout<<"8 es Agosto"<<endl;
	cout<<"9 es Septiembre"<<endl;
	cout<<"10 es Octubre"<<endl;
	cout<<"11 es Noviembre"<<endl;
	cout<<"12 es Diciembre"<<endl;
	cin>>mes;
		if (mes<1) {cout<<"Error , número no válido"<<endl;}
		if (mes>12) {cout<<"Errors , número no válido"<<endl;}
		switch(mes){
			case 1:{
				cout<<"Enero tiene 31 días"<<endl;
			}break;
			case 2 :{
				cout<<"Febrero tiene 28 días"<<endl;
			}break;
			case 3 :{
				cout<<"Marzo tine 31 días"<<endl;
			}break;
			case 4:{
				cout<<"Abril tiene 30 días"<<endl;
			}break;
			case 5:{
				cout<<"Mayo tiene 31 días"<<endl;
			}break;
			case 6 :{
				cout<<"Junio tiene 30 días"<<endl;
			}break;
			case 7:{
				cout<<"Julio tiene 31 días"<<endl;
			}break;
			case 8:{
				cout<<"Agosto tiene 31 días"<<endl;
			}break;			
			case 9:{
				cout<<"Septiembre tiene 30 días"<<endl;
			}break;
			case 10:{
				cout<<"Octubre tiene 31 días"<<endl;
			}break;
			case 11:{
				cout <<"Noviembre tiene 30 días"<<endl;
			}break;
			case 12:{
				cout<<"Diciembre tiene 31 días"<<endl;		
			}break;
		}
	
	
cin.ignore();
cin.get();
}

		