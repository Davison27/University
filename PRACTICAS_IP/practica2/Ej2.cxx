#include <iostream>
using namespace std;
int main(){
	int num;
	cout<<"Introduzca el número que desee calcular su suma descendente"<<endl;
	cin>>num;
	int suma=0;
	while (num>0){
		if(num>0){
			suma=suma+num;
			num=num-1;
		}
	}
cout<<"Este es el resultado :"<<suma<<endl;
cout<<"Fin de programa"<<endl;
cin.ignore();
cin.get();
}