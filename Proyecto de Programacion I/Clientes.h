#pragma once
#include <iostream>
using namespace std;
class Clientes
{
private:
	string name_;
	int ced_;
	int telf_;
	string correo;
	string fechaNac_;
	char sexo_;
	int fechaIns_;
	int inscritos_;
public:
	Clientes();
	Clientes(string, int,  int, string, string, char, int, int);
	string toString();
};

