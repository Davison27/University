#include <iostream>
using namespace std;
int main(){
	int i, fact;
	cout<<"Introduzca un número para realizarle su factorial :"<<endl;
	cin>>i;
	for (fact=1;i>=1;i=i-1) {
			fact=fact*i;
	}
		cout<<"fact="<<fact<<endl;
cout<<"Fin de programa"<<endl;
cin.ignore();
cin.get();
}

	