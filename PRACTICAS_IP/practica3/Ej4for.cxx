#include <iostream>
using namespace std;
int main(){
	int n, o;
	cout<<"Introduzca un número para conocer sus divisores en orden ascendente"<<endl;
	cin>>n;
	cout<<"Sus divisores son :"<<endl;
		for(o=1 ; n>=o ; o++){
			if(n%o==0){
				cout<<o<<endl;
			}
		}
	cout<<"Fin del programa"<<endl;
cin.ignore();
cin.get();
}