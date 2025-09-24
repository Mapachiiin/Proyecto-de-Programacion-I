#include "ClasesGrupales.h"
#include <iostream>
#include <sstream>
#include "Sucursal.h"
#include "Cliente.h"
using namespace std;

ClasesGrupales::ClasesGrupales() {
	codClase_ = 0;
	ocupados_ = 0;
	cupoMax_ = 0;
	sucAsig_ = nullptr;
	insAsig_ = nullptr;
	horario_ = " ";
	espeClass_ = " ";
	inscritos_ = new Cliente*[30];
	for(int i = 0; i < 30; i++) {
		inscritos_[i] = nullptr;
	}
}
ClasesGrupales::ClasesGrupales(int cC, int cap, int cupo, Sucursal* suc, Instructor* ins, string hor, string espe) {
	this->codClase_ = cC;
	this->ocupados_ = cap;
	this->cupoMax_ = cupo;
	this->sucAsig_ = suc;
	this->insAsig_ = ins;
	this->inscritos_ = new Cliente*[cupoMax_];
	for(int i = 0; i < cupoMax_; i++) {
		inscritos_[i] = nullptr;
	}
	this->horario_ = hor;
	this->espeClass_ = espe;
}

void ClasesGrupales::setCodClase(int cC) {
	codClase_ = cC;
}
void ClasesGrupales::setOcupados(int cap) {
	ocupados_ = cap;
}
void ClasesGrupales::setCupoMax(int cupo) {
	cupoMax_ = cupo;
}
void ClasesGrupales::setSucursal(Sucursal* suc) {
	sucAsig_ = suc;
}
void ClasesGrupales::setInstructor(Instructor* ins) {
	insAsig_ = ins;
}
void ClasesGrupales::setHorario(string hor) {
	horario_ = hor;
}
void ClasesGrupales::insCliente(Cliente* cli) {
	if (ocupados_ >= cupoMax_) {
		cout << "La clase ya no tiene cupos." << endl;
		return;
	}
	if (cli->getInscritos() >= 3) {
		cout << "El cliente ya esta inscrito en su maximo de clases grupales permitidas." << endl;
		return;
	}
	for (int i = 0; i < ocupados_; i++) {
		if (inscritos_[i] != nullptr && inscritos_[i]->getCed() == cli->getCed()) {
			cout << "El cliente ya esta inscrito en esta clase grupal." << endl;
			return;
		}
	}

	for (int i = 0;i < ocupados_; i++) {
		if (inscritos_[i] == nullptr) {
			inscritos_[i] = inscritos_[i + 1];
			ocupados_--;
		}
	}

	for (int i = 0; i < cupoMax_; i++) {
		if (inscritos_[i] == nullptr) {
			inscritos_[i] = cli;
			ocupados_++;
			cli->setInscritos(cli->getInscritos() + 1);
			break;
		}
	}
}

void ClasesGrupales::listarClientes() {
	cout << "Clientes inscritos en la clase grupal " << codClase_ << ":" << endl;
	for (int i = 0; i < ocupados_; i++) {
		if (inscritos_[i] != nullptr) {
			cout << inscritos_[i]->getNombre() << " cedula: " << inscritos_[i]->getCed() << endl;
		}
	}
}
void ClasesGrupales::eliminarTodosClientes() {
    for (int i = 0; i < ocupados_; i++) {
        inscritos_[i] = nullptr;
    }
    ocupados_ = 0;
    cout << "Todos los clientes han sido eliminados de la clase grupal." << endl;
}

int ClasesGrupales::getCodClase() {
	return codClase_;
}
int ClasesGrupales::getOcupados() {
	return ocupados_;
}
int ClasesGrupales::getCupoMax() {
	return cupoMax_;
}
Sucursal* ClasesGrupales::getSucursal() {
	return sucAsig_;
}
Instructor* ClasesGrupales::getInstructor() {
	return insAsig_;
}
string ClasesGrupales::getHorario() {
	return horario_;
}
string ClasesGrupales::getEspecialidad() {
	return espeClass_;
}
string ClasesGrupales::toString() {
	stringstream ss;
	if (insAsig_ != nullptr) {
		ss << "\n\n\nInstructor asignado: " << insAsig_->getNombre() << endl;
	} else (insAsig_ == nullptr); {
		ss << "\n\n\nInstructor asignado: No hay ningun instructor asignado" << endl;
	}
	if (sucAsig_ != nullptr) {
		ss << "\n\n\nSucursal asignada: " << sucAsig_->getCod() << endl;
	} else (sucAsig_ == nullptr); {
		ss << "\n\n\nSucursal asignada: No hay ninguna sucursal asignada" << endl << endl;
	}



	ss << "Codigo de la clase: " << codClase_ << endl;
	ss << "Capacidad actual: " << ocupados_ << endl;
	ss << "Cupo maximo: " << cupoMax_ << endl;
	ss << "Horario: " << horario_ << endl;
	ss << "Especialidad: " << espeClass_ << endl;
	return ss.str();
}
void ClasesGrupales::eliminarCliente(int cedula) {
	for (int i = 0; i < ocupados_; i++) {
		if (inscritos_[i] != nullptr && inscritos_[i]->getCed() == cedula) {
			inscritos_[i] = nullptr;
			for (int j = i; j < ocupados_ - 1; j++) {
				inscritos_[j] = inscritos_[j + 1];
			}
			ocupados_--;
			cout << "Cliente eliminado de la clase grupal." << endl;
			return;
		}
	}
	cout << "Cliente no encontrado en la clase grupal." << endl;
}
void ClasesGrupales::eliminarClienteNom(string nombre) {
	for (int i = 0; i < ocupados_; i++) {
		if (inscritos_[i] != nullptr && inscritos_[i]->getNombre() == nombre) {
			inscritos_[i] = nullptr;
			for (int j = i; j < ocupados_ - 1; j++) {
				inscritos_[j] = inscritos_[j + 1];
			}
			ocupados_--;
			cout << "Cliente eliminado de la clase grupal." << endl;
			return;
		}
	}
	cout << "Cliente no encontrado en la clase grupal." << endl;
}


ClasesGrupales::~ClasesGrupales() {
	for(int i = 0; i < ocupados_; i++) {
		inscritos_[i] = nullptr;
	}
	delete[] inscritos_;
}