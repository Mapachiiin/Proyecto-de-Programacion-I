#pragma once
#include <iostream>
#include "ReporteMedicion.h"
#include "Rutina.h"

class Instructor;

using namespace std;
class Cliente
{
private:
	string name_;
	int ced_;
	int telf_;
	string correo;
	string fechaNac_;
	char sexo_;
	string fechaIns_;
	int inscritos_;

	Instructor* instAsig_;
	Rutina* ruti_;
	ReporteMedicion** reportes_;
	int numReportes_;
	
	
public:
	Cliente();
	Cliente(string name, int ced, int telf, string corr, string fN, char mf, string fI, int inscrip, Instructor* inst);
	~Cliente();
	string getNombre();
	int getCed();
	int getTelf();
	string getCorreo();
	string getFechaNac();
	char getSexo();
	string getFechaIns();
	int getInscritos();
	Instructor* getInstructor();
	Rutina* getRutina();
	int getNumReportes();
	void setName(string name);
	void setCed(int ced);
	void setTelf(int telf);
	void setCorreo(string corr);
	void setFechaNac(string fN);
	void setSexo(char mf);
	void setFechaIns(string fI);
	void setInscritos(int ins);
	void setIntructor(Instructor* ins);
	void setRutina(Rutina* ruti);
	void agregarReporte(const ReporteMedicion& rep);
	ReporteMedicion* getReportePorIndice(int rep);
	string toString();
	void listarReportes();

};

