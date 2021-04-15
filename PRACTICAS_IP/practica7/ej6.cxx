#include <iostream>
#include <string>
using namespace std;

string concatena(string a , string b){
	return a +  b;
}

int main(){
	string cadena1;
	string cadena2;
	cout<<"Este programa coge dos frases o palabras y las une"<<endl;
	cout<<"Introduzca la primera frase o palabra"<<endl;
	getline(cin,cadena1);
	cout<<"Introduzca la segunda frase o palabra"<<endl;
	getline(cin,cadena2);
	concatena(cadena1,cadena2);
	cout<<"El resultado es :"<<" "<<concatena(cadena1,cadena2)<<endl;
cin.ignore();
cin.get();
}