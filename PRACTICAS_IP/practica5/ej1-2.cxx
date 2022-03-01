#include <iostream>
using namespace std;
void lee(float v1[] , int n){
	int i ;
	float  j;
	for(i=0 ; i<10 ; i++){
	cout<<"Introduzca números para asignar los elementos de un vector"<<endl;
	cin>>j;
	v1[i]=j;
	}
}
void imprime(float v1[] , int n){
	int i , j;
	cout<<"Los elementos del  vector son : "<<endl;
	for(i=0 ; i<10 ; i++){
		cout<<v1[i]<<endl;
	}
}
int main(){
	float v[10];
	lee(v,10);
	imprime(v,10);
cin.ignore();
cin.get();
}