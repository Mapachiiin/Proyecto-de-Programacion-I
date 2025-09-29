#include "Rutina.h"
#include "Instructor.h"
#include "Cliente.h"
#include "Ejercicios.h"
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
	capEjer_ = nEjercicios;
	numEjercicios_ = 0;
	ejercicios_ = new Ejercicios*[capEjer_];
	for (int i = 0; i < capEjer_; ++i) {
		ejercicios_[i] = nullptr;
	}
}
Rutina::~Rutina() {
	for (int i = 0; i<capEjer_; ++i) {
		delete ejercicios_[i];
	}
	delete[] ejercicios_;
	ejercicios_ = nullptr;
	capEjer_ = 0;
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
bool Rutina::agregarEjercicio(Ejercicios* ejer) {
	for (int i = 0;i < capEjer_; ++i) {
		if (ejercicios_[i] == nullptr) {
			ejercicios_[i] = ejer;
			numEjercicios_++;
			return true;
		}
	}
	return false;
}
void Rutina::respuesta(int r) {
	resp_ = r;
}

void Rutina::listarEjercicios() {
	for (int i = 0; i < capEjer_; ++i) {
		if (ejercicios_[i] != nullptr) {
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
				cout << "Opcion no valida.\n";
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
	for (int i = 0;  i < capEjer_; ++i) {
		if (ejercicios_[i]!=nullptr) {
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
		<< "-----------------------------------" << endl;
	for (int i = 0; i < capEjer_; ++i) {
		if (ejercicios_[i] != nullptr) {
			ss << "Ejercicio " << i + 1 << " :" << endl
				<< ejercicios_[i]->toString() << endl;
		}
	}
	return ss.str();
}