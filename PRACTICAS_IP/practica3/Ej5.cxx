#include <iostream>
using namespace std;
int main(){
	int n1,n2,cont;
	cout<<"Introduzca números y el programa terminará cuando la media de estos sea <=30"<<endl;
	cin>>n1;
	cout<<"Introduzca otro número"<<endl;
	cin>>n2;
	cont=2;//El contador indica los numeros con los que hacemos la media
	while(((n1+n2)/cont)<30){
		cout<<"Introduzca otro valor"<<endl;
		n1=n1+n2;
		cin>>n2;
		cont++;
		}
cout<<"Fin del programa"<<endl;
cin.ignore();
cin.get();
}