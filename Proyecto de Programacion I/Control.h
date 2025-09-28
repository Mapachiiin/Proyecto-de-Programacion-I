#pragma once
#include <iostream>
#include "Sucursal.h"
#include "Cliente.h"
#include "Instructor.h"
#include "ClaseGrupal.h"
#include "Quemados.h"
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
	void menuGestionarClientes(Sucursal* sucu);
	void agregarCliente(Sucursal* sucu);
	void gestionarCliente(Sucursal* sucu);
	void eliminarCliente(Sucursal* sucu);
	void menuGestionarInstructores(Sucursal* sucu);
	void agregarInstructor(Sucursal* sucu);
	void gestionarInstructor(Sucursal* sucu);
	void eliminarInstructor(Sucursal* sucu);
	void menuGestionarClasesGrupales(Sucursal* sucu);
	void agregarClaseGrupal(Sucursal* sucu);
	void gestionarClaseGrupal(Sucursal* sucu);
	void eliminarClaseGrupal(Sucursal* sucu);
	int getNumSucursales();
	void listarCodSucursales();
	bool esFechaValida(string&);
	void gestionarClienteSi(Sucursal* sucu,int ced);
	Sucursal* buscarSucursal(string codigo);
	Sucursal* buscarSucurGesti(string codigo);
	void menuGestionarMediciones(Cliente* cli);
	void menuGestionarRutinas(Cliente* cli); 
	void menuGestionarEjercicios(Cliente*cli);
	void menuGestionarCliClasesGrupales(Cliente* cli);
	void menuGestionarCliInst(Instructor* ins, Sucursal* sucu);
	void gestionarInstructorSi(Sucursal* sucu, int ced);
};

