#pragma once
#include <iostream>
using namespace std;
class Instructor
{
private:
	int numCed_;
	string nombre_;
	int telef_;
	string correo;
	string fechaNac;
	string* espeIns;
	int numEspecialidades;

public:
	Instructor();
	Instructor(int nC, string nom, int tel, string corr, string fN, int nE);
	~Instructor();
	string toString();
	void setEspecialidad(int es);
	void agregarEspecialidadS(int ep);
	void setNumCed(int nC);
	void setNombre(string nom);
	void setTelef(int tel);
	void setCorreo(string corr);	
	void setFechaNac(int fN);
	int getCed();
	string getNombre();
	int getTelef();
	string getCorreo();	
	string getFechaNac();
	string getEspecialidadPrinci();
	int getNumEspecialidades();

};