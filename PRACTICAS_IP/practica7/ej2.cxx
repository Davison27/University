#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int digitos(string cad){
	int cont=0;
	for(int i=0 ; i<cad.size();i++){
		if(isdigit(cad[i])){
			cont++;
		}
	}
return cont;
}

int main(){
	string numeros;
	cout<<"introduzca una frase para saber cuantos números tiene "<<endl;
	getline (cin,numeros);
	digitos(numeros);
	cout<<"La frase tiene"<<" "<<digitos(numeros)<<" " <<"numeros"<<endl;
cin.ignore();
cin.get();
}