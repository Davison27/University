#include <iostream>
using namespace std;
int main(){
	float grados,radianes;
	cout<<"Introduzca el ángulo que desea transformar en radianes"<<endl;
	cin>>grados;
	radianes=grados*(3.1415/180);
	cout<<"El resultado es :"<<radianes<<endl;
	cin.ignore();
	cin.get();
}