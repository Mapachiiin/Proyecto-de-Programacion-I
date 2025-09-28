#include "Instructor.h"
#include <iostream>
#include <sstream>
using namespace std;

Instructor::Instructor() {
	numCed_ = 0;
	nombre_ = "";
	telef_ = 0;
	correo = "";
	fechaNac = "";
	numEspecialidades = 0;
	espeIns = new string[8];
}

Instructor::Instructor(int nC, string nom, int tel, string corr, string fN, int nE){
	numCed_ = nC;
	nombre_ = nom;
	telef_ = tel;
	correo = corr;
	fechaNac = fN;
	numEspecialidades = 0;
	espeIns = new string[8];
	this->agregarEspecialidadS(nE);
}

Instructor::~Instructor() {
	delete[] espeIns;
}

void Instructor::agregarEspecialidadS(int ep) {
	static const string especialidades[] = {
		"CrossFit", "HIIT", "TRX", "Spinning",
		"Pesas", "Cardio", "Yoga", "Zumba"
	};

	if (ep < 1 || ep > 8) return; 
	if (numEspecialidades >= 8) return; 

	string nueva = especialidades[ep - 1];

	for (int i = 0; i < numEspecialidades; i++) {
		if (espeIns[i] == nueva) {
			cout << "---| El instructor ya tiene la especialidad " << nueva << " |---" << endl;
			return;
		}
	}

	espeIns[numEspecialidades++] = nueva;
	cout << "---| Especialidad " << nueva << "agregada con exito |---" << endl;
}

void Instructor::setEspecialidad(int ep) {
	static const string especialidades[] = {
		"CrossFit", "HIIT", "TRX", "Spinning",
		"Pesas", "Cardio", "Yoga", "Zumba"
	};

	if (ep < 1 || ep > 8) {
		cout << "---| No se puede determinar la especialidad. |---" << endl;
		return;
	} else if (numEspecialidades >= 8) {
		cout << "---| No se pueden agregar más especialidades. |---" << endl;
		return;
	}

	string nueva = especialidades[ep - 1];

	for (int i = 0; i < numEspecialidades; i++) {
		if (espeIns[i] == nueva) {
			cout << "---| El instructor ya tiene la especialidad de "
				<< nueva << ". |---" << endl;
			return;
		}
	}

	espeIns[numEspecialidades++] = nueva;
	cout << "---| Especialidad agregada: " << nueva << endl;
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
string Instructor::getFechaNac(){
	return fechaNac;
}
int Instructor::getNumEspecialidades(){
	return numEspecialidades;
}
string Instructor::getEspecialidadPrinci() {
	return espeIns[0];
}
bool Instructor::tieneEspecialidad(string& esp) {
	for (int i = 0; i < numEspecialidades; i++) {
		if (espeIns[i] == esp) {
			return true;
		}
	}
	return false;

}
bool Instructor::tieneEspecialidadInt(int esp) {
	static const string especialidades[] = {
	  "CrossFit", "HIIT", "TRX", "Spinning",
	  "Pesas", "Cardio", "Yoga", "Zumba"
	};

	if (esp < 1 || esp > 8) return false;
	string buscada = especialidades[esp - 1];

	for (int i = 0; i < numEspecialidades; i++) {
		if (espeIns[i] == buscada) {
			return true;
		}
	}
	return false;
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