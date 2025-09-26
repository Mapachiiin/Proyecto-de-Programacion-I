#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Cliente;

class ReporteMedicion
{
private:
	string clasiIMC;
	string fechaMedi;
	Cliente* cli;
	bool haceEjercicio;
	bool altoRiesgo;
	double peso;
	double estatura;
	double porGras;
	double porMuscu;
	double graVis;
	double cintura;
	double cadera;
	double pecho;
	double muslo;
	double IMC; //peso/(estatura*estatura)
	double proteRecomend; //0.8g de prote x cada kg de peso, si es hombre son entree 1.7g - 2.5g y si es mujer entre 1.6- 1.8
	int edadMeta;
	int vasosAgua; //peso/7= cant vasos de 250 ml que tiene que tomar
	
public:
	ReporteMedicion();
	ReporteMedicion(Cliente& cli, string fecha, double peso, double estatura, double grasa, double musculo, int edadMet, double grasaVisc, double cintura, double cadera, double pecho, double muslo);
	void calcuIMC();
	void clasifiIMC();
	void calcuProteRecomend();
	void calcuVasosAgua();
	void deterAltoRiesgo();
	string toString();
	string getFechaMedi();
};

