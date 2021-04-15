#include <iostream>
using namespace std;
int main(){
	int x;
	cout<<"Introduzca el día de la semana"<<endl;
	cout<<"1 es Lunes"<<endl;
	cout<<"2 es Martes"<<endl;
	cout<<"3 es Miercoles"<<endl;
	cout<<"4 es Jueves"<<endl;
	cout<<"5 es Viernes"<<endl;
	cout<<"6 es Sabado"<<endl;
	cout<<"7 es Domingo"<<endl;
	cin>>x;
		if (x<6){
			cout<<"Es dia laborable"<<endl;
			}
		if (x<=0) {
			cout<<"Error , numero no valido"<<endl;
			}
		if (x>5){
			cout<<"Es fin de semana"<<endl;
			}
		if (x>7) {
			cout<<"Error , numero no valido"<<endl;
			}
cin.ignore();
cin.get();
}

				
	