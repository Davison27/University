#include <iostream>
using namespace std;
int main(){
	int num; 
	cout<<"¿De cuántos números desea hacer la media?"<<endl;
	cout<<"El programa finalizará al introducir de un número negativo o 0"<<endl;
	cin>>num;
	int aux=0;
	float suma=0;
	int cont=0;
			while(num>0){
				if(num>0){
					num=num-1;
					cout<<"Introduca un número"<<endl;
					cin>>aux;
					suma=suma+aux;
					cont++;
			}
		}
	cout<<"La media es :"<<suma/cont<<endl;
	cout<<"Fin del programa"<<endl;
cin.ignore();
cin.get();
}