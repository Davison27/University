#include <iostream>
#include <string>
using namespace std;

bool palindromo(string cad){
	for(int i=0 ; i<=cad.size()/2;i++){
		if(cad[i]!=cad[cad.size()-1-i]){
			return false;
		}
		else{
			return true;
		}
	}
}

int main(){
	string palabra;
	cout<<"introduzca una palabra para saber si es un polindromo o no"<<endl;
	getline (cin,palabra);
	palindromo(palabra);
	if(palindromo(palabra)==true){
		cout<<"La palabra es un polídromo"<<endl;
	}
	else{
		cout<<"La palabra no es un polindromo"<<endl;
	}
cin.ignore();
cin.get();
}
	