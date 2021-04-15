#include <iostream>
#include <string>
using namespace std;

int vocales(string cad){
	int cont=0;
	for(int i=0 ; i<cad.size() ; i++){
		cad[i]=tolower(cad[i]);
		if((cad[i]=='a')||(cad[i]=='e')||(cad[i]=='i')||(cad[i]=='o')||(cad[i]=='u')){
			cont++;
		}
	}
return cont;
}

int main(){
	string frase;
	cout<<"introduzca la frase que desee saber su número de vocales"<<endl;
	getline(cin,frase);
	vocales(frase);
	cout<<"Su frase posee :"<<" "<<vocales(frase)<<" "<<"vocales"<<endl;
cin.ignore();
cin.get();
}
