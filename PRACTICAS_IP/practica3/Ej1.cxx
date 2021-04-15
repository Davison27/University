#include <iostream>
using namespace std;
int main(){
	int n1, cont=4,n2;
	cout<<"Introduzca 5 números para saber cual de ellos es el menor"<<endl;
	cout<<"Número :"<<endl;
	cin>>n1;
	n2=n1;
	while(cont>0){
		cout<<"Número :"<<endl;
		cin>>n1;
			if(n1<n2){
				n2=n1;
			}
		cont=cont-1;		//El contador tiene que ser 4 pues si no le asigno un valor a n1 antes del while y luego hago que n2 sea igual a n1 , me aparece al final del programa un número basura del sistema;
		}
	cout<<"Fin del programa , el número menor es :"<<n2<<endl;
cin.ignore();
cin.get();
}