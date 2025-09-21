#pragma once
#include <iostream>
#include "Clientes.h"
using namespace std;

class IMC
{
private:
	Clientes cliEvalu;
	string fechaMedi;
	double peso;
	double estatura;
	double porcenGrasa;
	double porcenMusculo;
	int edadMetabolica;
	double porcenGrasaVisceral;
	double medCintu;
	double medCade;
	double medPecho;
	double medMuslo;
public:
	IMC();

};

