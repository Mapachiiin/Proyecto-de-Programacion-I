#pragma once
#include <iostream>
#include <sstream>
#include "Instructor.h"
using namespace std;

class Cliente;
class Sucursal;

class ClaseGrupal
{
private:
	int codClase_;
	int ocupados_;
	int cupoMax_;
	Sucursal* sucAsig_;
	Instructor* insAsig_;	
	Cliente** inscritos_;
	string horario_;
	int espeClass_;
	string especialidad_;

public:
	ClaseGrupal();
	ClaseGrupal(int cC, int cap, int cupo, Sucursal* suc, Instructor* ins, string hor, int espe);
	~ClaseGrupal();
	void espe(int esp);
	void setCodClase(int cC);
	void setOcupados(int cap);
	void setCupoMax(int cupo);
	void setSucursal(Sucursal* suc);
	void setInstructor(Instructor* ins);
	void setHorario(string hor);
	void insCliente(Cliente* cli);
	void eliminarCliente(int cedula);
	void eliminarClienteNom(string nombre);
	void eliminarTodosClientes();
	void listarClientes();
	int getCodClase();
	int getOcupados();
	int getCupoMax();
	Sucursal* getSucursal();
	Instructor* getInstructor();
	string getHorario();
	string getEspecialidad();
	string toString();
};

