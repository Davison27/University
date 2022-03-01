#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
void fijaValorAleatorio (int v[] , int n , int max){
	for(int i=0 ; i<n ; i++){
		v[i]=rand()%max;
		cout<<"v["<<i<<"] ="<<v[i]<<endl;
	}
}
int main(){
	int secs=time (0);
	srand(secs);
	int n, b=0;
	do{
		if (b==1){
			cout<<"Error , el número debe de ser mayor que 0"<<endl;
		}
	cout<<"Introduzca el tamaño del vector"<<endl;
	cin>>n;
	b++;
	}while (n<0);
	int v[n];
	int max;
	cout<<"Introduzca el valor máximo que puede adoptar los números aleatorios"<<endl;
	cin>>max;
	fijaValorAleatorio(v , n , max); 
cin.ignore();
cin.get();
}
	