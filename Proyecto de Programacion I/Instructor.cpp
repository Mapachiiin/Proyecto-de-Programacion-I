#include "Instructor.h"
#include <iostream>
#include <sstream>
using namespace std;

Instructor::Instructor() {
	numCed_ = 0;
	nombre_ = " ";
	telef_ = 0;
	correo = " ";
	fechaNac = 0;
	numEspecialidades = 0;
}
Instructor::Instructor(int nC, string nom, int tel, string corr, int fN, int nE){
	numCed_ = nC;
	nombre_ = nom;
	telef_ = tel;
	correo = corr;
	fechaNac = fN;
	numEspecialidades = nE;
}
Instructor::~Instructor() {}

void Instructor::setEspecialidad(string es) {
	if (numEspecialidades < 8) {
		espeIns[numEspecialidades] = es;
		numEspecialidades++;
	}
	else {
		cout << "No se pueden agregar más especialidades." << endl;
	}
}

void Instructor::setNumCed(int nC){
	numCed_=nC;
}
void Instructor::setNombre(string nom){
	nombre_=nom;
}
void Instructor::setTelef(int tel){
	telef_=tel;
}
void Instructor::setCorreo(string corr) {
	correo=corr;
}
void Instructor::setFechaNac(int fN){
	fechaNac=fN;
}
int Instructor::getCed(){
	return numCed_;
}
string Instructor::getNombre(){
	return nombre_;
}
int Instructor::getTelef(){
	return telef_;
}
string Instructor::getCorreo(){
	return correo;
}
int Instructor::getFechaNac(){
	return fechaNac;
}
int Instructor::getNumEspecialidades(){
	return numEspecialidades;
}

string Instructor::toString() {
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