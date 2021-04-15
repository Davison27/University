#include <iostream>
using namespace std;
int main(){
	float  numero;
	int operacion;
	cout<<"Introduzca el número para saber si es par o impar"<<endl;
	cin>>numero;
	operacion=numero/2;
	if (operacion==(numero/2)) {
		cout<<"El numero es par"<<endl;
		}
	else{
		cout<<"El numero es impar"<<endl;
	}
cin.ignore();
cin.get();
}
	
	