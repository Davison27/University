#include <iostream>
using namespace std;
int factorial(int v){
	int i , fact;
	i=v;
		for(fact=1 ; i>=1 ; i--){
			fact=i*fact;
		}
	return fact;
}	
int main(){
	int n , v;
	cout<<"Introduzca un número para saber su factorial"<<endl;
	cin>>n;
	v=factorial(n);
	cout<<"El resultado es :"<<v<<endl;
cin.ignore();
cin.get();
}













