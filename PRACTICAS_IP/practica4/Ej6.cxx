#include <iostream>
using namespace std;
int combinaciones(int n, int k){
	int factn=1 , factk=1 , factresta=1;
		if (n==0){
			factn=1;
		}
		else{
			for (int i=1 ; i<=n ; i++){
				factn=i*factn;
			}
		}
		if (k==0){
			factk=1;
		}
		else{
			for (int j=1 ; j<=k ; j++){
				factk=j*factk;
			}
		}
		int r=n-k;
		for (int u=1 ; u<= r ; u++){
			factresta=u*factresta;
		}
	return ((factn)/((factk)*(factresta)));
}
int main(){
	int a , b ;
	cout<<"Introduzca dos números para calcular el número combinatorio"<<endl;
	cin>>a;
	cin>>b;
	cout<<"El resultado del primer número sobre el segundo es :"<<combinaciones(a,b)<<endl;
cout<<"Fin del programa"<<endl;
cin.ignore();
cin.get();
}