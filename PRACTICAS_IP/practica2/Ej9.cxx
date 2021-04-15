#include <iostream>
using namespace std;
int main(){
	int n, suma=0;
	cout<<"Introduzca un número para calcular la suma de sus números divisibles por 2 o 3"<<endl;
	cin>>n;
	cout<<"Calculando..."<<endl;
	while(n>0){
		if (n%2==0){
				cout<<n<<endl;
				suma=suma+n;
		}
		if (n%3==0){
				cout <<n<<endl;
				suma=suma+n;
		}
		n=n-1;
	}
	cout<<"El resultado es :"<<suma<<endl;
cout<<"Fin del programa"<<endl;
cin.ignore();
cin.get();
}
		
			