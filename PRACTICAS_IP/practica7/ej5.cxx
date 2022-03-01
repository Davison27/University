#include <iostream>
#include <string>
using namespace std;

void replace(string&cad , char a , char b){
	for(int i=0 ; i<cad.size() ; i++){
		if(cad[i]==a){
			cad[i]=b;
		}
	}
}

int main(){
	char a=0;
	char b=0;
	string frase;
	cout<<"Introduzca una palabra o frase"<<endl;
	getline (cin,frase);
	cout<<"Introduzca una letra y posteriormente otra por la que desee cambiar la primera"<<endl;
	cin>>a;
	cin>>b;
	replace(frase , 'a' , 'b');
	cout<<frase<<endl;
	cin.ignore();
	cin.get();
}
	