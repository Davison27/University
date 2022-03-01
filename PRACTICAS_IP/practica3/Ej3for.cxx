#include <iostream>
using namespace std;
int main(){
	int n, o , suma=0;
	cout<<"Introduzca un valor para saber si es primo o no"<<endl;
	cin>>n;
	for(o=1 ; n>=o ; o++){
		if(n%o==0){
			suma++;
		}
	}
	if(suma==2){
		cout<<"El número es primo"<<endl;
	}
	else if (suma>2){
		cout<<"El número no es primo"<<endl;
	}
cout<<"Fin del programa"<<endl;
cin.ignore();
cin.get();
}