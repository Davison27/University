#include <iostream>
using namespace std;
int main(){
	int n,o;
	cout<<"Introduzca un número para conocer sus divisores en orden ascendente"<<endl;
	cin>>n;
	o=1;
	cout<<"Sus divisores son:"<<endl;
		while (n>=o){
			if(n%o==0){
				cout<<o<<endl;
			}
		o++;
		}
cout<<"Fin del programa"<<endl;
cin.ignore();
cin.get();
}