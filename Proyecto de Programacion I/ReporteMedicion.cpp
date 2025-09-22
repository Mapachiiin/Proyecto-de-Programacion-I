#include "ReporteMedicion.h"
#include <sstream>


ReporteMedicion::ReporteMedicion() {
	clasiIMC = "";
	fechaMedi = "";
	altoRiesgo = false;
	peso = 0.0;
	estatura = 0.0;
	porGras = 0.0;
	porMuscu = 0.0;
	graVis = 0.0;
	cintura = 0.0;
	cadera = 0.0;
	pecho = 0.0;
	muslo = 0.0;
	IMC = 0.0;
	proteRecomend = 0.0; //0.8g de prote x cada kg de peso, si es hombre son entree 1.7g - 2.5g y si es mujer entre 1.6- 1.8
	edadMeta = 0;
	vasosAgua = 0; //peso/7= cant vasos de 250 ml que tiene que tomar
}

ReporteMedicion::ReporteMedicion(Cliente& cli, string fecha, double peso, double estatura, double grasa, double musculo, int edadMet, double grasaVisc, double cintura, double cadera, double pecho, double muslo){
	this->fechaMedi = fecha;
	this->peso = peso;
	this->estatura = estatura;
	this->porGras = grasa;
	this->porMuscu = musculo;
	this->edadMeta = edadMet;
	this->graVis = grasaVisc;
	this->cintura = cintura;
	this->cadera = cadera;
	this->pecho = pecho;
	this->muslo = muslo;
	this->cli = &cli;

}
void ReporteMedicion::calcuIMC(){
	IMC = peso/(estatura*estatura);
}

void ReporteMedicion::clasifiIMC(){
	calcuIMC();
	if (IMC < 16.00) {
		clasiIMC = "Delgadez severa";
	}
	else if (IMC >= 16.01 && IMC < 16.99) {
		clasiIMC = "Delgadez moderada";
	}
	else if (IMC >= 17.00 && IMC < 18.49) {
		clasiIMC = "Delgadez leve";
	}
	else if (IMC >= 18.50 && IMC < 24.99) {
		clasiIMC = "Normal";
	}
	else if (IMC >= 25.00 && IMC < 29.99) {
		clasiIMC = "Pre-obesidad";
	}
	else if (IMC >= 30.00 && IMC < 34.99) {
		clasiIMC = "Obesidad leve";
	}
	else if (IMC >= 35.00 && IMC < 39.99) {
		clasiIMC = "Obesidad media";
	}
	else if (IMC>=40.00){
		clasiIMC = "Obesidad morbida";
	}
	else{
		clasiIMC = "Error en el calculo";
	}
}
void ReporteMedicion::calcuProteRecomend() {
	if(haceEjercicio&&cli->getSexo()=='M')
		proteRecomend = 2.1 * peso;
	else if(haceEjercicio&&cli->getSexo()=='F')
		proteRecomend = 1.7 * peso;
	else
	proteRecomend = 0.8 * peso;
}
void ReporteMedicion::calcuVasosAgua(){
	vasosAgua = peso / 7;
}
void ReporteMedicion::deterAltoRiesgo() {
	if (IMC >= 30.00) {
		altoRiesgo = true;
	}
	else {
		altoRiesgo = false;
	}
}
string ReporteMedicion::toString() {
	stringstream ss;
	ss << "Reporte de: " << cli->getNombre() << endl
		<< "Fecha de medicion: " << fechaMedi << endl
		<< "Peso: " << peso << "kg" << endl
		<< "Estatura: " << estatura << "m" << endl
		<< "Porcentaje de grasa corporal: " << porGras << "%" << endl
		<< "Porcentaje de musculo: " << porMuscu << "%" << endl
		<< "Edad metabolica: " << edadMeta << " annios" << endl
		<< "Grasa visceral: " << graVis << " %" << endl
		<< "Medidas corporales: " << endl
		<< "-Cintura: " << cintura << " cm" << endl
		<< "-Cadera: " << cadera << " cm" << endl
		<< "-Pecho: " << pecho << " cm" << endl
		<< "-Muslo: " << muslo << " cm" << endl
		<< "Indice de masa corporal (IMC): " << IMC << endl
		<< "Clasificacion IMC: " << clasiIMC << endl
		<< "Proteina recomendada diaria: " << proteRecomend << " g" << endl
		<< "Cantidad de agua recomendados al dia: " << vasosAgua << " vasos de 250 ml" << endl
		<< "Es un paciente de alto riesgo?: " << (altoRiesgo ? "Si" : "No") << endl
		<< "Instructor asignado: " << cli->getInstructor()->getNombre() << endl
		<< "Numero de contacto del instructor: " << cli->getInstructor()->getTelef() << endl
		<< "Correo del instructor: " << cli->getInstructor()->getCorreo() << endl;
	return ss.str();
}
