#include "Rutina.h"
#include "Instructor.h"
#include "Cliente.h"
#include "Ejercicio.h"
#include <sstream>
#include <iostream>
using namespace std;

Rutina::Rutina() {
	cliente_ = nullptr;
	descripcion_ = "";
	duracion_ = 0;
	ejercicio_ = nullptr;
}
Rutina::Rutina(Cliente* cli,string desc, int dur, int nEjercicios) {
	cliente_ = cli;
	descripcion_ = desc;
	duracion_ = dur;
	capEjer_ = nEjercicios;
	numEjercicios_ = 0;
	ejercicio_ = new Ejercicio*[capEjer_];
	for (int i = 0; i < capEjer_; ++i) {
		ejercicio_[i] = nullptr;
	}
}
Rutina::~Rutina() {
	for (int i = 0; i<capEjer_; ++i) {
		delete ejercicio_[i];
	}
	delete[] ejercicio_;
	ejercicio_ = nullptr;
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
bool Rutina::agregarEjercicio(Ejercicio* ejer) {
	for (int i = 0;i < capEjer_; i++) {
		if (ejercicio_[i] == nullptr) {
			ejercicio_[i] = ejer;
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
	system("cls");
	cout << "Rutina: " << descripcion_ << " (" << duracion_ << " min)" << endl;
	for (int i = 0; i < numEjercicios_; i++) {
		cout << i + 1 << ". " << ejercicio_[i]->toString() << endl;
	}
}
bool Rutina::eliminarEjercicio(int num) {
	if (num >= 0 && num < numEjercicios_) {
		delete ejercicio_[num];
		for (int i = num; i < numEjercicios_ - 1;i++) {
			ejercicio_[i] = ejercicio_[i + 1];
		}
		ejercicio_[--numEjercicios_] = nullptr;
		return true;
	}
	return false;
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
Ejercicio* Rutina::getEjercicio() {
	for (int i = 0;  i < capEjer_; ++i) {
		if (ejercicio_[i]!=nullptr) {
			return ejercicio_[i];
		}
	}
	return nullptr;
}
string Rutina::ejerci() {
	stringstream ss;
	ss << "---| Ejercicios |--- " << endl;

	for (int i = 0; i < capEjer_; ++i) {
		if (ejercicio_[i] != nullptr) {
			ss << "Ejercicio " << i + 1 << " :" << endl	<< ejercicio_[i]->toString() << endl;
		}
	}
	return ss.str();
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
		if (ejercicio_[i] != nullptr) {
			ss << "Ejercicio " << i + 1 << " :" << endl
				<< ejercicio_[i]->toString() << endl;
		}
	}
	return ss.str();
}