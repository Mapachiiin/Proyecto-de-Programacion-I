#pragma once
#include "Sucursal.h"
#include "Cliente.h"
#include "Instructor.h"
#include "ClaseGrupal.h"
using namespace std;

class Menu;

class Control
{
private:
	Sucursal** sucursales_;
	int numSucursales_;
	int capSucursales_;
public:
	Control();
	~Control();
	void agregarSucursal(string codi, int tel, string prov, string cant, string corr, int capCli, int capIns);
	void eliminarSucursal(string codigo);
	void listarSucursales();
	void gestionarSucursal(string codigo);
	void gestionarClientes(Sucursal* sucu);
	void gestionarInstructores(Sucursal* sucu);
	void gestionarClasesGrupales(Sucursal* sucu);
	int getNumSucursales();
	void listarCodSucursales();
	Sucursal* buscarSucursal(string codigo);
	Sucursal* buscarSucurGesti(string codigo);
};

