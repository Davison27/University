#include <iostream>
using namespace std;
bool esperfecto(int v){
	int i , div=1;
	for(i=0 ; div<v ; div++){
		if(v%div==0){
			i=i+div;
		}
	}
	if (i==v){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	int n;
	cout<<"Introduzca un número para saber si es perfecto"<<endl;
	cin>>n;
	if (esperfecto(n)==true){
		cout<<"El número es perfecto"<<endl;
	}
	else{
		cout<<"El número no es perfecto"<<endl;
	}
cout<<"Fin del programa"<<endl;
cin.ignore();
cin.get();
}