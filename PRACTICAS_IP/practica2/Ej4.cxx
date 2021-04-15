#include <iostream>
using namespace std;
int main(){
	int num;
	cout<<"Introduzca un número para calcular la suma de los impares"<<endl;
	cin>>num;
	int suma=0;
	if(num%2==1){
		while(num>0){
			suma=suma+num;
			num=num-2;
		}
	}
cout<<"El resultado es :"<<suma<<endl;
cout<<"Fin de programa"<<endl;
cin.ignore();
cin.get();
}
			