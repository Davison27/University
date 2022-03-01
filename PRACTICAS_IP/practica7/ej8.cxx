#include <iostream>
#include <string>
using namespace std;

bool comprueba_dni(string cad){
	for(int i=0 ; i<cad.size() ; i++){
		if(cad.size()>8 && cad.size()<8){
			return false;
		}
	}
 	cad[8]=toupper(cad[8]);
	for(int j=0 ; j<cad.size() ; j++){
		int numero=stoi(cad);
		char vector_letras[]="TRWAGMYFPDXBNJZSQVHLCKE";
		if(cad[8]!=vector_letras[(numero%23)]){
			return false;
		}
		else{
			return true;
		}
	}
}
			
int main(){
	string DNI;
	cout<<"Este programa sirve para comprobar que el número de Dni introducido es correcto o no y en este caso devolverá un error"<<endl;
	cout<<"Introduzca el Dni a comprobar"<<endl;
	getline(cin,DNI);
	comprueba_dni(DNI);
		if(comprueba_dni(DNI)==true){
			cout<<"¡Correcto!, su dni esta bien escrito"<<endl;
		}
		else{
			cout<<"¡Error! , su dni no está bien escrito"<<endl;
		}
cin.ignore();
cin.get();
}
	