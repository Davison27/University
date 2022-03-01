#include <iostream>
using namespace std;
bool esprimo(int v){
	bool res;
	int n=v, suma=0;
		while(n>0){
			if(v%n==0){
				suma=suma+1;}
				n--;
		}
			if(suma==2){res=true;}
			else{res=false;}
			return res;
}
				
int main(){
	int n;
	cout<<"Introduzca un número para saber si es primo o no"<<endl;
	cin>>n;
	 if ( esprimo(n)==true){
		cout<<"El número es primo"<<endl;
	}
	else{
		cout<<"El número no es primo"<<endl;
	}
cin.ignore();
cin.get();
}