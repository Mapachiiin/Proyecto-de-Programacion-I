#pragma once
#include <iostream>
#include "Instructores.h"
#include "Clientes.h"
#include "ClasesGrupales.h"
using namespace std;

class Sucursales
{
private:
	int cod;
	string provi;
	string canton;
	string correo;
	int telef;
	Clientes** cliSucur_;
	int numClientes_;
	int capClientes_;
	Instructores** insSucur_;
	int numInstructores_;
	int capInstruc_;
	ClasesGrupales** ClassGrupSucur_;
	int numClasesGrups_;
	int capClasesGrups_;
	

public:
	Sucursales();
	Sucursales(int, int, string, string, string, int, int, int, int, int, int, int);
	~Sucursales();
	void setCod();
	void setProvi();
	void setCanton();
	void setCorreo();
	void setTelef();
	void setNumClientes();
	void setCapClientes();
	void setNumInstructores();
	void setCapInstructores();
	void setNumClasesGrups();
	void setCapClasesGrups();
	int getTelef();
	string getProvi();
	string getCanton();
	string getCorreo();
	int getNumClientes();
	int getCapClientes();
	int getNumInstructores();
	int getCapInstructores();
	int getNumClasesGrups();
	int getNumClasesGrups();
	int getCod();
};

