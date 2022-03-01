#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
	std::srand(time(0));
	int secreto= rand()%1000;
	cout<<"Bienvenido al juego de adivinar el número secreto"<<endl;
	cout<<"Para comenzar , introduzca un número y el programa le dirá si es el número secreto o es mayor o menor que este"<<endl;
	cout<<"Introduzca un número"<<endl;
	int n;
	cin>>n;
		while(n!=secreto) {
				if	(n<secreto){
					cout<<"¡Oh no! , el número secreto es más grande"<<endl;
					cin>>n;
				}
		
				if (n>secreto){
					cout<<"¡Oh no! , el número secreto es más pequeño"<<endl;
					cin>>n;
				}
			}
cout<<"¡Correcto! Ha acertado el numero secreto"<<endl;
cout<<"Fin del programa"<<endl;		
cin.ignore();
cin.get();
}
