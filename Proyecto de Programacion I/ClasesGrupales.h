#pragma once
#include <iostream>
#include <sstream>
#include "Sucursal.h"
#include "Instructor.h"
using namespace std;

class ClasesGrupales
{
private:
	int codClase_;
	int capacidad_;
	int cupoMax_;
	Sucursal* sucAsig_;
	Instructor* insAsig_;	
	Cliente** inscritos_;
	string horario_;
	string espeClass_;

public:
	ClasesGrupales();
	ClasesGrupales(int cC, int cap, int cupo, Sucursal* suc, Instructor* ins, string hor, string espe);
	~ClasesGrupales();
	void setCodClase(int cC);
	void setCapacidad(int cap);
	void setCupoMax(int cupo);
	void setSucursal(Sucursal* suc);
	void setInstructor(Instructor* ins);
	void setHorario(string hor);
	void insCliente(Cliente* cli);
	void eliminarCliente(int cedula);
	void eliminarClienteNom(string nombre);
	void listarClientes();
	int getCodClase();
	int getCapacidad();
	int getCupoMax();
	Sucursal* getSucursal();
	Instructor* getInstructor();
	string getHorario();
	string getEspecialidad();
	string toString();
	

};

