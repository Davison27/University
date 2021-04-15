#include <iostream>
#include <cmath>
using namespace std;
int main() {
	float x;
	cout<<"Introduzca el número"<<endl;
	cin>> x;
	float raiz_x=sqrt(x);
	if(x<0) {
		cout<<"Error"<<endl; 
			}
	else {
		cout<<"El resultado es :"<<sqrt(x)<<endl;
			}
	cout<<"Fin del programa"<<endl;
cin.ignore();
cin.get();
}