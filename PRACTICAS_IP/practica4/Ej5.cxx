#include <iostream>
using namespace std;
bool esprimo(int v){
	bool res;
	int n=v, suma=0;
		while(n>0){
			if(v%n==0){
				suma=suma+1;
			}
			n--;
		}
	if (suma==2){
		res=true;
	}
	else{
		res=false;
	}
	return res;
}
void primos(int h){
	int p , e=0;
	for(p=1 ; e!=h ; p++){
		if(esprimo(p)==true){
			cout<<p<<endl;
			e++;
		}
	}
}
int main(){
	int n;
	cout<<"Introduzca un número para saber los n primeros números primos"<<endl;
	cin>>n;
	cout<<"Los números son :"<<endl;
	primos(n);
cin.ignore();
cin.get();
}
	