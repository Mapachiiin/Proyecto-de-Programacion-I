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
	int telef;
	string provi;
	string canton;
	string correo;
	
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
	Sucursales(int, int, string, string, string, int, int, int);
	~Sucursales();
	void setCod(int codi);
	void setProvi(string prov);
	void setCanton(string can);
	void setCorreo(string corr);
	void setTelef(int tel);
	void setNumClientes(int nC);
	void setCapClientes(int cC);
	void setNumInstructores(int nI);
	void setCapInstructores(int cI);
	void setNumClasesGrups(int nCG);
	void setCapClasesGrups(int cCG);
	int getTelef();
	string getProvi();
	string getCanton();
	string getCorreo();
	int getNumClientes();
	int getCapClientes();
	int getNumInstructores();
	int getCapInstructores();
	int getNumClasesGrups();
	int getCapClasesGrups();
	int getCod();
	void agregarCliente(const Clientes& cliente);
	void agregarInstructor(const Instructores& instructor);
	void agregarClaseGrupal(const ClasesGrupales& clase);
	void eliminarCliente(int cedula);
	void eliminarInstructor(int cedula);
	void eliminarClaseGrupal(int idClase);
	void listarInstructores();

	string toString();
};

