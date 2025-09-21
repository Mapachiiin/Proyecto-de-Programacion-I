#include "Instructores.h"
#include <iostream>
#include <sstream>
using namespace std;

Instructores::Instructores() {
	numCed_ = 0;
	nombre_ = " ";
	telef_ = 0;
	correo = " ";
	fechaNac = 0;
	numEspecialidades = 0;
}
Instructores::Instructores(int nC, string nom, int tel, string corr, int fN, int nE){
	numCed_ = nC;
	nombre_ = nom;
	telef_ = tel;
	correo = corr;
	fechaNac = fN;
	numEspecialidades = nE;
}
Instructores::~Instructores() {}

void Instructores::setEspecialidad(string es) {
	if (numEspecialidades < 8) {
		espeIns[numEspecialidades]=es;
		numEspecialidades++;
	}
	else {
		cout << "No se pueden agregar más especialidades." << endl;
	}
}
void Instructores::setNumCed(int nC){
	numCed_=nC;
}
void Instructores::setNombre(string nom){
	nombre_=nom;
}
void Instructores::setTelef(int tel){
	telef_=tel;
}
void Instructores::setCorreo(string corr) {
	correo=corr;
}
void Instructores::setFechaNac(int fN){
	fechaNac=fN;
}
int Instructores::getNumCed(){
	return numCed_;
}
string Instructores::getNombre(){
	return nombre_;
}
int Instructores::getTelef(){
	return telef_;
}
string Instructores::getCorreo(){
	return correo;
}
int Instructores::getFechaNac(){
	return fechaNac;
}
int Instructores::getNumEspecialidades(){
	return numEspecialidades;
}

string Instructores::toString() {
	stringstream ss;
	ss << "Cedula: " << numCed_ << endl
		<< "Nombre: " << nombre_ << endl
		<< "Telefono: " << telef_ << endl
		<< "Correo: " << correo << endl
		<< "Fecha de Nacimiento: " << fechaNac << endl
		<< "Numero de Especialidades: " << numEspecialidades << endl
		<< "Especialidades: " << endl;
	for (int i = 0; i < numEspecialidades; i++) {
		ss << " - " << espeIns[i] << endl;
	}
	return ss.str();
}