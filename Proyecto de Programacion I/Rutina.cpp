#include "Rutina.h"
#include <sstream>
#include <iostream>
using namespace std;

Rutina::Rutina() {
	cliente_ = nullptr;
	descripcion_ = "";
	duracion_ = 0;
	ejercicios_ = nullptr;
}

Rutina::Rutina(Cliente* cli, string desc, int dur, int nEjercicios, int nEPT, int nEB, int nEP, int nEE) {
	cliente_ = cli;
	descripcion_ = desc;
	duracion_ = dur;
	numEjercicios_ = nEjercicios;
	ejercicios_ = new Ejercicios*[nEjercicios];
	for (int i = 0; i < nEjercicios; ++i) {
		ejercicios_[i] = nullptr;
	}
}
Rutina::~Rutina() {
	delete[] cliente_;
	for (int i = 0; i<numEjercicios_ && ejercicios_[i]; ++i) {
		delete[] ejercicios_[i];
	}
	delete[] ejercicios_;
	numEjercicios_ = 0;
}
void Rutina::setCliente(Cliente* cliente) {
	this->cliente_ = cliente;
}
void Rutina::setDescripcion(string desc) {
	this->descripcion_ = desc;
}
void Rutina::setDuracion(int dur) {
	this->duracion_ = dur;
}
void Rutina::agregarEjercicio(Ejercicios* ejer) {
	for (int i = 0;i < numEjercicios_ && ejercicios_[i]; ++i) {
		if (ejercicios_[i] == nullptr) {
			ejercicios_[i] = ejer;
			numEjercicios_++;
			return;
		}
	}
}
void Rutina::respuesta(int r) {
	resp_ = r;
}
void Rutina::listarEjercicios() {
	for (int i = 0; i < numEjercicios_ && ejercicios_[i]; ++i) {
				if (ejercicios_[i]) {
			cout << "Ejercicio " << i + 1 << ":\n";
			switch (resp_) {
			case 1:
				ejercicios_[i]->listEjerPecTric();
				break;
			case 2:
				ejercicios_[i]->listEjercBic();
				break;
			case 3:
				ejercicios_[i]->listEjerPier();
				break;
			case 4:
				ejercicios_[i]->listEjerEspal();
				break;
			default:
				cout << "Opción no válida.\n";
				break;
			}
				}
	}
}
int Rutina::getNumEjercicios() {
	return numEjercicios_;
}
Cliente* Rutina::getCliente() {
	return cliente_;
}
string Rutina::getDescripcion() {
	return descripcion_;
}
int Rutina::getDuracion() {
	return duracion_;
}
Ejercicios* Rutina::getEjercicio() {
	for (int i = 0;  i < numEjercicios_ && ejercicios_[i]; ++i) {
		if (ejercicios_[i]) {
			return ejercicios_[i];
		}
	}
	return nullptr;
}
string Rutina::toString() {
	stringstream ss;
	ss << cliente_->getNombre() << endl
		<< "Cedula: " << cliente_->getCed() << endl
		<< "Rutina dada por el instructor: " << cliente_->getInstructor()->getNombre() << endl
		<< "Descripción: " << descripcion_ << endl
		<< "Duración: " << duracion_ << " minutos" << endl
		<< "Número de ejercicios : " << numEjercicios_ << endl
		<< "Ejercicios: " << endl
		<< "-----------------------------------" << endl
		for (int i=0; i<numEjercicios_ && ejercicios_[i]; ++i) {
			ss << "Ejercicio " << i + 1 << " :" << endl
				<< ejercicios_[i]->toString() << endl;
		}
	return ss.str();
}
