#include <iostream>
using namespace std;
int Ndivisores (int v){
	int c=0 , a;
		if(v>0){
			for (a=1 ; a<=v ; a++){
				if (v%a==0){
					c++;
				}
			}
		cout<<c<<endl;
	}
	if(v==0){
		cout<<"El número no tiene divisores"<<endl;
	}
	if(v<0){
		for(a=-1 ; a>=v ; a--){
			if(v%a==0){
				c++;
			}
		}
		cout<<c<<endl;
	}
}
int main(){
	int n;
	cout<<"Introduzca un número para saber el número de divisores que tiene"<<endl;
	cin>>n;
	cout<<"Los divisores totales del números son :"<<endl;
	Ndivisores (n);
	cout<<"Fin del programa"<<endl;
cin.ignore();
cin.get();
}