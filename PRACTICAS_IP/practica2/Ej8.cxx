#include <iostream>
using namespace std;
int main(){
	int n=0;
	int a=0 , b=1 ;
	int cont=0;
	cout<<"�De cu�ntos n�meros desea que sea la sucesi�n de Fibonacci?"<<endl;
	cin>>cont;
	cout<<"Los n�meros son :"<<endl;
		while(cont>=0){
			n=a+b;
			a=b;
			b=n;
			cout<<n<<endl;
			cont=cont-1;
		}
	cout<<"Fin del programa"<<endl;
cin.ignore();
cin.get();
}
			
			