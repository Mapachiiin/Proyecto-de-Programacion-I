#include "Sucursal.h"
#include <sstream>
#include <iostream>
using namespace std;

Sucursal::Sucursal() {
	cod= 0;
	provi= " ";
	canton= " ";
	correo= " ";
	telef= 0;
	capClientes_= 0;
	cliSucur_= nullptr;
	numClientes_= 0;
	capInstruc_= 0;
	insSucur_= nullptr;
	numInstructores_= 0;
	capClasesGrups_= 0;
	ClassGrupSucur_= nullptr;
	numClasesGrups_= 0;
}

Sucursal::Sucursal(int codi, int tel, string prov, string cant, string corr, int capCli, int capIns, int capCG) {
	cod = codi;
	telef = tel;
	this->provi = prov;
	this->canton = cant;
	this->correo = corr;
	
	capClientes_ = capCli;
	cliSucur_ = new Clientes * [capClientes_];
	for(int i = 0; i < capClientes_; i++) {
		cliSucur_[i] = nullptr;
	}
	numClientes_ = 0;

	capInstruc_ = capIns;
	insSucur_ = new Instructores * [capInstruc_];
	for(int i = 0; i < capInstruc_; i++) {
		insSucur_[i] = nullptr;
	}
	numInstructores_ = 0;

	
	capClasesGrups_ = capCG;
	ClassGrupSucur_ = new ClasesGrupales * [capClasesGrups_];
	for(int i = 0; i < capClasesGrups_; i++) {
		ClassGrupSucur_[i] = nullptr;
	}
	numClasesGrups_ = 0;
	

}
Sucursal::~Sucursal(){
	for(int i = 0; i < capClientes_; i++) {
		if (cliSucur_[i] != nullptr) {
			delete cliSucur_[i];
		}
	}
	delete[] cliSucur_;	
	for(int i = 0; i < capInstruc_; i++) {
		if (insSucur_[i] != nullptr) {
			delete insSucur_[i];
		}
	}
	delete[] insSucur_;	
	for(int i = 0; i < capClasesGrups_; i++) {
		if (ClassGrupSucur_[i] != nullptr) {
			delete ClassGrupSucur_[i];
		}
	}
	delete[] ClassGrupSucur_;
}

void Sucursal::agregarCliente(const Clientes& cliente){
	if (numClientes_ < capClientes_) {
		cliSucur_[numClientes_] = new Clientes(cliente);
		numClientes_++;
		cout << "A que instructor desea asignarse?" << endl;
	} else {
		cout << "Capacidad de clientes alcanzada en la sucursal " << cod << endl;
	}
}
void Sucursal::agregarInstructor(const Instructores& instructor) {
		if (numInstructores_ < capInstruc_) {
		insSucur_[numInstructores_] = new Instructores(instructor);
		numInstructores_++;
	} else {
		cout << "Capacidad de instructores alcanzada en la sucursal " << cod << endl;
		}
}
void Sucursal::agregarClaseGrupal(const ClasesGrupales& clase){
	if (numClasesGrups_ < capClasesGrups_) {
		ClassGrupSucur_[numClasesGrups_] = new ClasesGrupales(clase);
		numClasesGrups_++;
	} else {
		cout << "Capacidad de clases grupales alcanzada en la sucursal " << cod << endl;
	}
}
void Sucursal::eliminarCliente(int cedula){
	for (int i = 0; i < numClientes_; i++) {
		if (cliSucur_[i] != nullptr && cliSucur_[i]->getCed() == cedula) {
			delete cliSucur_[i];
			cliSucur_[i] = cliSucur_[numClientes_ - 1];
			cliSucur_[numClientes_ - 1] = nullptr;
			numClientes_--;
			cout << "Cliente con cédula " << cedula << " eliminado de la sucursal " << cod << endl;
			return;
		}
	}
	cout << "Cliente con cédula " << cedula << " no encontrado en la sucursal " << cod << endl;
}
void Sucursal::eliminarInstructor(int cedula) {
		for (int i = 0; i < numInstructores_; i++) {
		if (insSucur_[i] != nullptr && insSucur_[i]->getNumCed() == cedula) {
			delete insSucur_[i];
			insSucur_[i] = insSucur_[numInstructores_ - 1];
			insSucur_[numInstructores_ - 1] = nullptr;
			numInstructores_--;
			cout << "Instructor con cédula " << cedula << " eliminado de la sucursal " << cod << endl;
			return;
		}
	}
		cout << "Instructor con cédula " << cedula << " no encontrado en la sucursal " << cod << endl;
}
void Sucursal::eliminarClaseGrupal(int idClase) {
			for (int i = 0; i < numClasesGrups_; i++) {
		// Assuming ClasesGrupales has a method getId() to get the class ID
		if (ClassGrupSucur_[i] != nullptr && ClassGrupSucur_[i]->getId() == idClase) {
			delete ClassGrupSucur_[i];
			ClassGrupSucur_[i] = ClassGrupSucur_[numClasesGrups_ - 1];
			ClassGrupSucur_[numClasesGrups_ - 1] = nullptr;
			numClasesGrups_--;
			cout << "Clase grupal con ID " << idClase << " eliminada de la sucursal " << cod << endl;
			return;
		}
	}
			cout << "Clase grupal con ID " << idClase << " no encontrada en la sucursal " << cod << endl;
}
void Sucursal::listarInstructores(){
	cout << "Instructores en la sucursal " << cod << ":\n";
	for (int i = 0; i < numInstructores_; i++) {
		if (insSucur_[i] != nullptr) {
			cout << insSucur_[i]->toString() << endl;
		}
	}
}

void Sucursal::setCod(int codi) {
	cod = codi;
}
void Sucursal::setProvi(string prov) {
	provi = prov;
}
void Sucursal::setCanton(string can) {
	canton = can;	
}
void Sucursal::setCorreo(string corr) {
	correo = corr;
}
void Sucursal::setTelef(int tel) {
	telef = tel;	
}
void Sucursal::setNumClientes(int nC){
	numClientes_ = nC;
}	
void Sucursal::setCapClientes(int cC) {
	capClientes_ = cC;	
}
void Sucursal::setNumInstructores(int nI) {
	numInstructores_ = nI;	
}
void Sucursal::setCapInstructores(int cI) {
	capInstruc_ = cI;	
}
void Sucursal::setNumClasesGrups(int nCG) {
	numClasesGrups_ = nCG;	
}
void Sucursal::setCapClasesGrups(int cCG) {
	capClasesGrups_ = cCG;	
}
int Sucursal::getTelef() {
	return telef;	
}
string Sucursal::getProvi() {
	return provi;	
}
string Sucursal::getCanton(){
	return canton;	
}	
string Sucursal::getCorreo() {
	return correo;	
}
int Sucursal::getNumClientes(){
	return numClientes_;	
}
int Sucursal::getCapClientes() {
	return capClientes_;	
}
int Sucursal::getNumInstructores() {
	return numInstructores_;	
}
int Sucursal::getCapInstructores() {
	return capInstruc_;		
}
int Sucursal::getNumClasesGrups() {
	return numClasesGrups_;	
}
int Sucursal::getCapClasesGrups() {
	return capClasesGrups_;	
}
int Sucursal::getCod() {
	return cod;	
}

string Sucursal::toString() {
	stringstream ss;
}
