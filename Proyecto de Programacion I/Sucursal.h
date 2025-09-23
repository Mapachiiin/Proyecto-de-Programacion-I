#pragma once
#include <iostream>
#include "Instructor.h"
#include "Cliente.h"
#include "ClasesGrupales.h"
using namespace std;

class Sucursal
{
private:
	string cod;
	int telef;
	string provi;
	string canton;
	string correo;
	
	Cliente** cliSucur_;
	int numClientes_;
	int capClientes_;

	Instructor** insSucur_;
	int numInstructores_;
	int capInstruc_;

	ClasesGrupales** ClassGrupSucur_;
	int numClasesGrups_;
	int capClasesGrups_;
	

public:
	Sucursal();
	Sucursal(string, int, string, string, string, int, int);
	~Sucursal();
	void setCod(string codi);
	void setProvi(string prov);
	void setCanton(string can);
	void setCorreo(string corr);
	void setTelef(int tel);
	void setNumClientes(int nC);
	void setCapClientes(int cC);
	void setNumInstructores(int nI);
	void setCapInstructores(int cI);
	void setNumClasesGrups(int nCG);
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
	string getCod();
	void agregarCliente(Cliente& cliente);
	void agregarInstructor(Instructor& instructor);
	void agregarClaseGrupal(ClasesGrupales& clase);
	void eliminarCliente(int cedula);
	void eliminarInstructor(int cedula);
	void eliminarClaseGrupal(int codClase);
	void listarInstructores();
	void listarClientes();
	void listarClasesGrupales();

	string toString();
};

