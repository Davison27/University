#include <iostream>
using namespace std;
int main(int argc,char **argv){
	int a ,b;
	cout<<"Introduzca el valor de la variable 1"<<endl;
	cin>>a;
	cout<<"Introduzca el valor de la variable 2"<<endl;
	cin>>b;
	cout<<"Intercambiando el valor de las variables ..."<<endl;
		if (a>b){
			cout<<"a="<<b<<"b="<<a<<endl;
		}
		if(a<b){
			cout<<"a="<<a<<"b="<<b<<endl;
		}
cin.ignore();
cin.get();
}
	