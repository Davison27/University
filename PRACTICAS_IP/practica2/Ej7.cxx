#include <iostream>
using namespace std;
int main(){
	int n,o;
	int suma=0;
	cout<<"Introduzca un valor para saber si es primo o no"<<endl;
	cin>>n;
	o=1;
	while (n>=o){
		if(n%o==0){
		suma++;
		}
	o++;	
	}
	if(suma==2){
		cout<<"El número es primo"<<endl;
	}
	else if (suma>2) {
		cout<<"El número no es primo"<<endl;
	}
cout<<"Fin de programa"<<endl;
cin.ignore();
cin.get();
}