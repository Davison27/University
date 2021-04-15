#include <iostream>
#include <string>
using namespace std;

void convierte_a_mayuscula(string&cad){
	for(int i=0 ; i<cad.size() ; i++){
		cad[i]=toupper(cad[i]);
	}
}
int main(){
	string cad;
	cout<<"Introduzca la frase que desee para convertir sus letras en mayúscula"<<endl;
	getline (cin,cad);
	convierte_a_mayuscula(cad);
	cout<<"Su frase quedaría asi:"<<endl;
	cout<<cad<<endl;
cin.ignore();
cin.get();
}
	
