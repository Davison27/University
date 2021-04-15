#include <iostream>
using namespace std;
void divisores (int v){
	int div;
	for(div=1 ; div<=v ; div++){
		if  (v%div==0){
			cout<<div<<endl;
		}
	}
}
int main(){
	int v ;
	cout<<"Introduzca un número para saber sus divisores"<<endl;
	cin>>v;
	cout<<"Sus divisores son :"<<endl;
	divisores(v);
cin.ignore();
cin.get();
}