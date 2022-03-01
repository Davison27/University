// jugador_unittest.cc: David Pérez 
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include <fstream>
#include <list>
#include "jugador.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Jugador, ConstructorParametrosDefecto) {
  Jugador j("99XX", "1");
  
  EXPECT_EQ("99XX", j.getDNI());
  EXPECT_EQ("1", j.getCodigo());
  EXPECT_EQ("", j.getNombre());
  EXPECT_EQ("", j.getApellidos());
  EXPECT_EQ("", j.getDireccion());
  EXPECT_EQ("", j.getLocalidad());
  EXPECT_EQ("", j.getProvincia());
  EXPECT_EQ("", j.getPais());
  EXPECT_EQ(0, j.getEdad());
  EXPECT_EQ(", ", j.getApellidosyNombre());
}

TEST(Jugador, ConstructorParametros) {
  Jugador j("99XX", "2", "David", "Perez", 20, "C/ Rotonda 8", "Cabra", "Cordoba", "España");
  
  EXPECT_EQ("99XX", j.getDNI());
  EXPECT_EQ("2", j.getCodigo());
  EXPECT_EQ("David", j.getNombre());
  EXPECT_EQ("Perez", j.getApellidos());
  EXPECT_EQ(20, j.getEdad());
  EXPECT_EQ("C/ Rotonda 8", j.getDireccion());
  EXPECT_EQ("Cabra", j.getLocalidad());
  EXPECT_EQ("Cordoba", j.getProvincia());
  EXPECT_EQ("España", j.getPais());
  EXPECT_EQ("Perez, David", j.getApellidosyNombre());
}

TEST(Jugador, setDineroygetDinero) {
  Jugador j("99XX", "1");

  EXPECT_EQ(1000, j.getDinero());
  j.setDinero(700);
  EXPECT_EQ(700, j.getDinero());
}

TEST(Jugador, setCodigoygetCodigo) {
  Jugador j("99XX", "1");

  EXPECT_EQ("1", j.getCodigo());
  j.setCodigo("5");
  EXPECT_EQ("5", j.getCodigo());
}

TEST(Jugador, setApuestasygetApuestasVacio) {
  Jugador j("99XX", "1");
  list<Apuesta> l;
  l= j.getApuestas();
  EXPECT_TRUE(l.empty());
}
TEST(Jugador, setApuestasygetApuestas) {
  Jugador j("99XX", "1");
  string nomfich=j.getDNI()+".txt";
  ofstream salida(nomfich.c_str());
  salida << 1 << "," << "20" << "," << 15<< "\n";
  salida << 2 << "," << "negro" << "," << 25<< "\n";
  salida << 3 << "," << "impar" << "," << 35<< "\n";
  salida << 4 << "," << "bajo" << "," << 45<< "\n";
  salida.close();
  list<Apuesta> l;
  j.setApuestas();
  l= j.getApuestas();
  EXPECT_EQ(4, l.size());
  list<Apuesta>::iterator i;
  i=l.begin();
  EXPECT_EQ(1, (*i).tipo);
  EXPECT_EQ("20", (*i).valor);
  EXPECT_EQ(15, (*i).cantidad);
  i++;
  EXPECT_EQ(2, (*i).tipo);
  EXPECT_EQ("negro", (*i).valor);
  EXPECT_EQ(25, (*i).cantidad);
  i++;
  EXPECT_EQ(3, (*i).tipo);
  EXPECT_EQ("impar", (*i).valor);
  EXPECT_EQ(35, (*i).cantidad);
  i++;
  EXPECT_EQ(4, (*i).tipo);
  EXPECT_EQ("bajo", (*i).valor);
  EXPECT_EQ(45, (*i).cantidad);
}

