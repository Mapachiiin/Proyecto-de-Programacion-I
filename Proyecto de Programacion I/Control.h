#pragma once
#include "Sucursal.h"
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
	int getNumSucursales();
	Sucursal* buscarSucursal(string codigo);

};

