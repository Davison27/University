#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Alumno{
	string dni;
	int edad;
	float nota;
};

bool guarda(string ruta_fichero , Alumno alumnos[10] , int nalumnos){
	ofstream file;
	file.open(ruta_fichero);
	if(!file.is_open()){
		cout<<"Error , el fichero no se pudo guardar"<<endl;
		return false;
	}
	for(int i=0; i<nalumnos ; i++){
		if(alumnos[i].dni!=""){
			file<<alumnos[i].dni<<endl;
			file<<alumnos[i].edad<<endl;
			file<<alumnos[i].nota<<endl;
		}
	}
	file.close();
	return true;
}

int lee(string ruta_fichero , Alumno alumnos[10]){
	ifstream file;
	file.open(ruta_fichero);
	int cont=0;
	if (!file.is_open()){
		cout<<"Error , el fichero no se pudo abrir"<<endl;
		return -1;
	}
	while(!file.eof()){
		Alumno x;
		file>>x.dni;
		file>>x.edad;
		file>>x.nota;
			alumnos[cont]=x;
			cont++;
	}
	file.close();
	return cont;
}
		

bool verificardni(string dni){
	for (int i=0 ; i>dni.size();i++){
		if(dni.size()>8 && dni.size()<8){
			return false;
		}
	}
	dni[8]=toupper(dni[8]);
	for(int j=0 ; j<dni.size(); j++){
		int numero =stoi(dni);
		char vector_letras[]="TRWAGMYFPDXBNJZSQVHLCKE";
		if(dni[8]!=vector_letras[(numero%23)]){
			return false;
		}
		else{
			return true;
		}
	}
}

Alumno addalumno(){		
	Alumno student;
	cout<<"introduzca el DNI del alumno"<<endl;
	cin>>student.dni;
	verificardni(student.dni);
	if(verificardni(student.dni)==true){
		cout<<"El dni introducido es válido"<<endl;
	}
	else{
		while(verificardni(student.dni)==false){
			cout<<"El dni introducido no es válido , introduzca uno válido"<<endl;
			cin>>student.dni;
		}
	}
	cout<<"Introduzca la edad del alumno"<<endl;
	cin>>student.edad;
	cout<<"Introduzca la nota del alumno"<<endl;
	cin>>student.nota;
return student;
}

	
bool posicionalumno(Alumno v[] , Alumno student , int b){
	int i;
	for(i=0 ; i<b ; i++){
		if(v[i].dni==""){
			v[i]=student;
			return true;
		}
	}
	return false;
}


void printalumno(Alumno &student){
	cout<<"Los datos del alumno son"<<endl;
	cout<<"Dni :"<<" "<<student.dni<<endl;
	cout<<"Edad :"<<" "<<student.edad<<endl;
	cout<<"Nota :"<<" "<<student.nota<<endl;
}


int findalumno(Alumno alumnos[] , int size , string dni){
	for(int i=0 ; i<size ; i++){
		if(alumnos[i].dni==dni){
			return i;
		}
	}
	return -1;
}


void printallalumno(Alumno alumnos[] , int a){
	int cont=0 ;
	for(int i=0 ; i<a ; i++){
		if(alumnos[i].dni!=""){
			cout<<"Los datos del alumno"<<" "<<i+1<<" "<<"son ;"<<endl;
			printalumno(alumnos[i]);
			cont++;
		}
	}
	cout<<"En total . han sido encontrados "<<" "<<cont<<" "<<"alumnos"<<endl;
}

void erasealumno(Alumno alumnos[] , int c){
	alumnos[c].dni= "";
}

int main(int argc ,char **argv){
	Alumno alumnos[10];
	int nmatriculados=0;
	int menu_opcion=0;
	if (argc!=2){
		cout<<"Error ,la cantidad de argumentos no es valida"<<endl;
		cout<<"Usado: "<<argv[0]<<" [file]"<<endl;
		return -1;

	string ruta_fichero=argv[1];

	if(lee(ruta_fichero,alumnos)==-1){
		cout<<"Error , el fichero no ha sido encontrado por lo que el programa comenzará si ningún alumno"<<endl;
	}
	
	if(!guarda(ruta_fichero,alumnos,nmatriculados)){
		cout<<"Error , el archivo no se ha podido guardar"<<endl;
	}
	return 0;
}
	do{
	cout<<"Este programa es una base de datos de alumnos"<<endl;
	cout<<"Seleccione una de las opciones :"<<endl;
	cout<<"1. Añadir alumno"<<endl;
	cout<<"2. Imprimir datos de alumno"<<endl;
	cout<<"3. Imprimir datos de todos los alumnos"<<endl;
	cout<<"4. Modificar alumno"<<endl;
	cout<<"5. Eliminar a un alumno"<<endl;
	cout<<"6. Salir"<<endl;
	cin>>menu_opcion;
		switch(menu_opcion){

			case 1:{
				Alumno student=addalumno();
				if (posicionalumno(alumnos , student , 10)==false){
					cout<<"Error , la base de datos está llena"<<endl;
				}
				else{
					cout<<"Alumno guardado correctamente"<<endl;
				}
			}break;


			case 2:{
				cout<<"Introduzca el DNI del alumno que desee buscar"<<endl;
				string finddni;
				cin>>finddni;
				int i=findalumno(alumnos ,10 , finddni);
					if(i!=-1){
						cout<<"El alumno ha sido encontrado"<<endl;
						printalumno(alumnos[i]);
					}
					else{
						cout<<"Error , el alumno no ha sido encontrado o no existe"<<endl;
					}
				}break;


			case 3:{
				printallalumno(alumnos,10);
			}break;


			case 4:{
				cout<<"Introduzca el Dni del alumno que desee modificar"<<endl;
				string modifdni;
				cin>>modifdni;
				int i= findalumno(alumnos ,10 , modifdni);
				if(i!=-1){
					cout<<"Se ha encontrado al alumno.Introduzac los datos modificados"<<endl;
					Alumno student=addalumno();
					alumnos[i]=student;
					cout<<"El alumno ha sido modificado con éxito"<<endl;
					}
				else{
					cout<<"Error en el sistema , el alumno no existe o el Dni es incorrecto"<<endl;
				}

			}break;


			case 5:{
				cout<<"Introduzca el Dni del alumno que desee aliminar del sistema"<<endl;
				string erasedni;
				cin>>erasedni;
				int i= findalumno(alumnos , 10 , erasedni);
				if(i!=-1){
					cout<<"El alumno ha sido enocntrado y eliminado exitosamente"<<endl;
					erasealumno(alumnos, i);
				}
				else{
					cout<<"Error en el sistema , el alumno no existe o el Dni es incorrecto"<<endl;
				}
				
			}break;


			case 6:{
				cout<<"El programa se cerrará ..."<<endl;

			}break;


			default:{
				cout<<"Error , introduzca un número apto"<<endl;
			}
		}
	}while (menu_opcion!=6);
cin.get();
cin.ignore();
}

