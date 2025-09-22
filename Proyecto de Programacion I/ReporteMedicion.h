#pragma once
class ReporteMedicion
{
private:
	string clasiIMC;
	string fechaMedi;
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
	ReporteMedicion(Cliente& cli, Instructor& ins, string fecha, double peso, double estatura, double grasa, double musculo, int edadMet, double grasaVisc, double cintura, double cadera, double pecho, double muslo);
	void calcuIMC();
	void clasiIMC();
	void calcuProteRecomend();
	void calcuVasosAgua();
	void deterAltoRiesgo();
	string toString();



};

