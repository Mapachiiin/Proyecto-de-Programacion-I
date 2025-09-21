#pragma once
#include <iostream>
using namespace std;
class Clientes
{
private:
	int ced_;
	string name_;
	int telf_;
	string correo;
	string fechaNac_;
	char sexo_;
	int fechaIns_;
	int inscritos_;
public:
	Clientes();
	Clientes(int, string, int, string, string, char, int, int);


};

