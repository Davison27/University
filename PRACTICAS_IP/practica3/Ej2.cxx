#include <iostream>
using namespace std;
int main(){
	int n1, n2=0;
	cout<<"Introduzca los números que desee para saber cual de todos ellos es el mayor"<<endl;
	cout<<"El programa finalizará con la introducción del número 0"<<endl;
	cin>>n1;
	while (n1>=0){
		cout<<"Introduzca un número"<<endl;
		cin>>n1;
			if (n1>n2){
				n2=n1;
			}
		}
	
	cout<<"Fin del programa , el número mayor es :"<<n2<<endl;
cin.ignore();
cin.get();
}