#include <iostream>
#include <string>
using namespace std;

int find(string a, string b){
	int cont , j=0;
	for(int i=0 ; i<a.size() ; i++){
			if(a[i]==b[j]){
				if(j==0){
					cont=i;
				}
				j++;
				if(j==b.size()){
					return cont;
				}
			}
		else{
			j=0;
		}
	}
	return -1;
}

int main(){
	string cad;
	string subcad;
	cout<<"Este programa busca una palabra dentro de una frase"<<endl;
	cout<<"Introduzca una frase"<<endl;
	getline(cin,cad);
	cout<<"Introduzca la palabra que desea encontrar"<<endl;
	getline(cin,subcad);
	find(cad,subcad);
	if(find(cad,subcad)==-1){	
		cout<<"La palabra no se ha encontrado"<<endl;
	}
	else{
		cout<<"La palabra se ha encontrado y esta en la posición :"<<" "<<find(cad,subcad)<<endl;
	}
cin.ignore();
cin.get();
}
	