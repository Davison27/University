#include <iostream>
using namespace std;
int main(){
	int n,o;
	cout<<"Introduzca un número para conocer sus divisores en orden descendente"<<endl;
	cin>>n;	
	o=n;
	cout<<"Sus divisores son"<<endl;
	while (o>0){
		if(n%o==0){
			cout<<o<<endl;
		}
	o=o-1;
	}
cout<<"Fin de programa"<<endl;
cin.ignore();
cin.get();
}