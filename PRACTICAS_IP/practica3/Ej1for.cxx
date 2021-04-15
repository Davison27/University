#include <iostream>
using namespace std;
int main(){
	int n1,n2,cont;
	cout<<"Introduzca 5 números para saber cual de ellos es el menor"<<endl;
	cout<<"Número :"<<endl;
	cin>>n1;
	n2=n1;
	for(cont=4 ; cont>0 ; cont--){
		cout<<"Número :"<<endl;
		cin>>n1;
			if(n1<n2){
				n2=n1;
			}
	}
	cout<<"Fin del programa , el número menor es :"<<n2<<endl;
cin.ignore();
cin.get();
}