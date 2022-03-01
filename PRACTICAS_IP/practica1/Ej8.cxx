#include <iostream>
using namespace std;
int main(){
	float a,b,c;
	cout<<"Introduzca el primer número :"<<endl;
	cin>>a;
	cout<<"Introduzca el segundo número :"<<endl;
	cin>>b;
	cout<<"Introduzca el tercer número :"<<endl;
	cin>>c;
if ((a==b) && (a==c)) {cout<<"los tres son iguales"<<endl;}	
	else {if ((a==b) && (a>c)) {cout<<"Este es el número más grande :"<<a<<endl;}
			else {if ((a==c) && (a>b)) {cout<<"Este es el número más grande :"<<a<<endl;}
				else {if ((b==c) && (c>a)) {cout<<"Este es el número más grande :"<<b<<endl;}
					else {if ((a==b) && (a<c)) {cout<<"Este es el número más grande :"<<c<<endl;}
						else {if ((a==c) && (a<b)) {cout<<"Este es el número más grande :"<<b<<endl;}
							else {if ((b==c) && (a>c)) {cout<<"Este es el número más grande :"<<a<<endl;}
}
}
}
}
}
}
if ((a>b) && (a>c)) {cout<<"Este es el número más grande :"<<a<<endl;}
		else {if ((b>a) && (b>c)) {cout<<"Este es el número más grande :"<<b<<endl;}
			else {if ((c>b) && (c>a)) {cout<<"Este es el número más grande :"<<c<<endl;}
				}
			}
cin.ignore();
cin.get();
}