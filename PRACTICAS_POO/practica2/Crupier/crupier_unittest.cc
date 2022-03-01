// dados_unittest.cc: David Pérez
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "persona.h"
#include "gtest/gtest.h"

TEST(Persona, ConstructorParametrosDefecto) {
  Persona p("99XX");
  
  EXPECT_EQ("99XX", p.getDNI());
  EXPECT_EQ("", p.getNombre());
  EXPECT_EQ("", p.getApellidos());
  EXPECT_EQ("", p.getDireccion());
  EXPECT_EQ("", p.getLocalidad());
  EXPECT_EQ("", p.getProvincia());
  EXPECT_EQ("", p.getPais());
  EXPECT_EQ(0, p.getEdad());
  EXPECT_EQ(", ", p.getApellidosyNombre());
}
 
TEST(Persona, ConstructorParametros) {
  Persona p("99XX", "David", "Perez", 20, "C/ Rotonda 8", "Cabra", "Cordoba", "España");
  
  EXPECT_EQ("99XX", p.getDNI());
  EXPECT_EQ("David", p.getNombre());
  EXPECT_EQ("Perez", p.getApellidos());
  EXPECT_EQ(20, p.getEdad());
  EXPECT_EQ("C/ Rotonda 8", p.getDireccion());
  EXPECT_EQ("Cabra", p.getLocalidad());
  EXPECT_EQ("Cordoba", p.getProvincia());
  EXPECT_EQ("España", p.getPais());
  EXPECT_EQ("Perez, David", p.getApellidosyNombre());
}

TEST(Persona, ConstructorCopia) {
  Persona p("99XX", "David", "Perez", 20, "C/ Rotonda 8", "Cabra", "Cordoba", "España");
  Persona q(p);
  Persona c=q;
  EXPECT_EQ("99XX", q.getDNI());
  EXPECT_EQ("David", q.getNombre());
  EXPECT_EQ("Perez", q.getApellidos());
  EXPECT_EQ(20, q.getEdad());
  EXPECT_EQ("C/ Rotonda 8", q.getDireccion());
  EXPECT_EQ("Cabra", q.getLocalidad());
  EXPECT_EQ("Cordoba", q.getProvincia());
  EXPECT_EQ("España", q.getPais());
  EXPECT_EQ("Perez, David", q.getApellidosyNombre());
  
  EXPECT_EQ("99XX", c.getDNI());
  EXPECT_EQ("David", c.getNombre());
  EXPECT_EQ("Perez", c.getApellidos());
  EXPECT_EQ(20, c.getEdad());
  EXPECT_EQ("C/ Rotonda 8", c.getDireccion());
  EXPECT_EQ("Cabra", c.getLocalidad());
  EXPECT_EQ("Cordoba", c.getProvincia());
  EXPECT_EQ("España", c.getPais());
  EXPECT_EQ("Perez, David", c.getApellidosyNombre());
}

TEST(Persona, ContructorIgualdad) {
  Persona p("99XX", "David", "Perez", 20, "C/ Rotonda 8", "Cabra", "Cordoba", "España");
  Persona q("66FF");
  q=p;
  EXPECT_EQ("99XX", q.getDNI());
  EXPECT_EQ("David", q.getNombre());
  EXPECT_EQ("Perez", q.getApellidos());
  EXPECT_EQ(20, q.getEdad());
  EXPECT_EQ("C/ Rotonda 8", q.getDireccion());
  EXPECT_EQ("Cabra", q.getLocalidad());
  EXPECT_EQ("Cordoba", q.getProvincia());
  EXPECT_EQ("España", q.getPais());
  EXPECT_EQ("Perez, David", q.getApellidosyNombre());
}
 
 TEST(Persona, mayor) {
  Persona p("99XX", "David", "Perez", 20, "C/ Rotonda 8", "Cabra", "Cordoba", "España");
  
  EXPECT_EQ(true, p.mayor());
  EXPECT_FALSE(p.setEdad(-17));
  EXPECT_TRUE(p.setEdad(17));
  EXPECT_EQ(false, p.mayor());
  
}