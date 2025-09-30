#pragma once
#include <iostream>
#include "Instructor.h"
#include "Cliente.h"
#include "ClaseGrupal.h"
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

	ClaseGrupal** ClassGrupSucur_;
	int numClasesGrups_;
	int capClasesGrupales_;
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
	void setNumInstructores(int nI);
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
	int getCapClasesGrupales();
	string getCod();
	Cliente* buscarCliente(int cedula);
	Instructor* buscarInstructor(int cedula);
	ClaseGrupal* buscarClaseGrupal(int cod);
	ClaseGrupal* getClaseGrupalPorIndice(int indice);
	void agregarCliente(Cliente* cliente);
	void agregarInstructor(Instructor* instructor);
	void agregarClaseGrupal(ClaseGrupal* clase);
	void eliminarCliente(int cedula);
	void eliminarInstructor(int cedula);
	void eliminarClaseGrupal(int codClase);
	void listarInstructores();
	void listarClientes();
	void listarClasesGrupales();
	void listarClientesDeInstructor(Instructor* inst);
	void listarClasesGrupalesCliente(Cliente* cli);

	string toString();
};

