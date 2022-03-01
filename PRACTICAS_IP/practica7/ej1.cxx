#include <iostream>
#include <string>
using namespace std;

int espacios(string cad){
	int cont=0;
	for(int i=0 ; i<cad.size();i++){
		if(cad[i]==' '){
			cont++;
		}
	}
return cont;
}

int main(){
	string cadena;
	cout<<"Introduzca una frase para saber el número de epacios que tiene"<<endl;
	getline (cin,cadena);
	espacios(cadena);
	cout<<"La frase tiene" << " "<<espacios(cadena)<<" "<<"espacios"<<endl;
cin.ignore();
cin.get();
}