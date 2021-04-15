//ns.cc
//This program is an example about namespaces
#include <iostream>

namespace n1{
    int a;  //Esta es la variable n1::a
    int b;  //Esta es la varibale n1::b
}

namespace n2{
    int a; //Esta es la variable n2::a
    int b; //Esta es la variable n2::b
}

int main(void){

    int a=55;
    n1::a=0;
    n2::a=2;
    std::cout << "n1::a=" << n1::a << "\n";
    std::cout << "n2::a=" << n2::a << "\n";
    std::cout << "a= " << a << "\n";

    return 0;
}