#pragma once
#include <iostream>
#include "Cliente.h"
using namespace std;

class IMC
{
private:
	Cliente cliEvalu;
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

