#include <iostream>
using namespace std;
int main(){
	float a,b,c,d,media;
	cout<<"Introduzca el primer número :"<<endl;
	cin>>a;
	cout<<"Introduzca el segundo número :"<<endl;
	cin>>b;
	cout<<"Introduzca el tercer número :"<<endl;
	cin>>c;
	cout<<"Introduzca el cuarto número :"<<endl;
	cin>>d;	
		media=(a+b+c+d)/4;
		cout<<"La media es :"<<media<<endl;
	cin.ignore();
	cin.get();
}