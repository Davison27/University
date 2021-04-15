#include <iostream>
using namespace std;
int main(){
	int x;
	cout<<"Introduzca el número entero"<<endl;
	cin>>x;
	if (x<0) {
		cout<<"El número es menor que 0"<<endl;
		}
	if (x==0){
		cout<<"El número es igual que 0"<<endl;
		}
	if (x>0) {
		cout<<"El número es mayor que 0"<<endl;
		}
cin.ignore();
cin.get();
}