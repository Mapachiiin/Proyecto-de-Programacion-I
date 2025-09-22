#pragma once
#include <iostream>
#include "ReporteMedicion.h"
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
	int fechaIns_;
	int inscritos_;

	Instructor* instAsig_;
	ReporteMedicion* reportes_[10];
	int numReportes_;
public:
	Cliente();
	Cliente(string, int,  int, string, string, char, int, int);
	~Cliente();
	string getName();
	int getCed();
	int getTelf();
	string getCorreo();
	string getFechaNac();
	char getSexo();
	int getFechaIns();
	int getInscritos();
	Instructor* getInstructor();
	int getNumReportes();
	void setName(string name);
	void setCed(int ced);
	void setTelf(int telf);
	void setCorreo(string corr);
	void setFechaNac(string fN);
	void setSexo(char mf);
	void setFechaIns(int fI);
	void setInscritos(int ins);
	void setIntructor(Instructor* ins);
	void agregarReporte(const ReporteMedicion& rep);
	string toString();
};

