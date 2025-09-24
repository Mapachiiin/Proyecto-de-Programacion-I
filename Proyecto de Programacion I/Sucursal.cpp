#include "Sucursal.h"
#include <sstream>
#include <iostream>
using namespace std;

Sucursal::Sucursal() {
	cod= "";
	provi= "";
	canton= "";
	correo= "";
	telef= 0;
	capClientes_= 0;
	cliSucur_= nullptr;
	numClientes_= 0;
	capInstruc_= 0;
	insSucur_= nullptr;
	numInstructores_= 0;
	capClasesGrups_= 8;
	ClassGrupSucur_= nullptr;
	numClasesGrups_= 0;
}

Sucursal::Sucursal(string codi, int tel, string prov, string cant, string corr, int capCli, int capIns) {
	this->cod = codi;
	this->telef = tel;
	this->provi = prov;
	this->canton = cant;
	this->correo = corr;
	
	this->capClientes_ = capCli;
	cliSucur_ = new Cliente * [capClientes_];
	for(int i = 0; i < capClientes_; i++) {
		cliSucur_[i] = nullptr;
	}
	numClientes_ = 0;

	this->capInstruc_ = capIns;
	insSucur_ = new Instructor * [capInstruc_];
	for(int i = 0; i < capInstruc_; i++) {
		insSucur_[i] = nullptr;
	}
	numInstructores_ = 0;

	
	capClasesGrups_ = 8;
	ClassGrupSucur_ = new ClaseGrupal * [capClasesGrups_];
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
	cliSucur_ = nullptr;
	for(int i = 0; i < capInstruc_; i++) {
		if (insSucur_[i] != nullptr) {
			delete insSucur_[i];
		}
	}
	delete[] insSucur_;
	insSucur_ = nullptr;
	for(int i = 0; i < capClasesGrups_; i++) {
		if (ClassGrupSucur_[i] != nullptr) {
			delete ClassGrupSucur_[i];
		}
	}
	delete[] ClassGrupSucur_;
	ClassGrupSucur_ = nullptr;
}

void Sucursal::agregarCliente(Cliente& cliente){

	for(int i=0; i < numClientes_; i++) {
		if (cliSucur_[i] != nullptr && cliSucur_[i]->getCed() == cliente.getCed()) {
			cout << "El cliente con cedula " << cliente.getCed() << " ya esta registrado en la sucursal " << cod << endl;
			return;
		}
	}	
	
	if (numClientes_ < capClientes_) {
		cliSucur_[numClientes_] = new Cliente(cliente);
		numClientes_++;
	}
	else {
		cout << "-| Capacidad de clientes alcanzada en la sucursal. |-" << cod << endl;
	}
}
void Sucursal::agregarInstructor(Instructor& instructor) {
	for (int i = 0; i < numInstructores_; i++) {
		if (insSucur_[i] != nullptr && insSucur_[i]->getCed() == instructor.getCed()) {
			cout << "-| El instructor con cedula " << instructor.getCed() << " ya esta registrado en la sucursal |-" << cod << endl;
			return;
		}
	}

		if (numInstructores_ < capInstruc_) {
		insSucur_[numInstructores_] = new Instructor(instructor);
		numInstructores_++;
	} else {
		cout << "Capacidad de instructores alcanzada en la sucursal. " << cod << endl;
		}
}
void Sucursal::agregarClaseGrupal(ClaseGrupal& clase){
	for(int i=0; i < numClasesGrups_; i++) {
		if (ClassGrupSucur_[i] != nullptr && ClassGrupSucur_[i]->getCodClase() == clase.getCodClase()) {
			cout << "La clase grupal con codigo " << clase.getCodClase() << " ya esta registrada en la sucursal " << cod << endl;
			return;
		}
	}

	if (numClasesGrups_ < capClasesGrups_) {
		ClassGrupSucur_[numClasesGrups_] = new ClaseGrupal(clase);
		numClasesGrups_++;
	} else {
		cout << "Capacidad de clases grupales alcanzada en la sucursal. " << cod << endl;
	}
}
void Sucursal::eliminarCliente(int cedula){
	for (int i = 0; i < numClientes_; i++) {
		if (cliSucur_[i] != nullptr && cliSucur_[i]->getCed() == cedula) {
			delete cliSucur_[i];
			cliSucur_[i] = cliSucur_[numClientes_ - 1];
			cliSucur_[numClientes_ - 1] = nullptr;
			numClientes_--;
			cout << "Cliente con cedula " << cedula << " eliminado de la sucursal " << cod << endl;
			return;
		}
	}
	cout << "Cliente con cédula " << cedula << " no encontrado en la sucursal " << cod << endl;
}
void Sucursal::eliminarInstructor(int cedula) {
	int posInstructor = -21;
	for (int i = 0; i < numInstructores_; ++i) {
		if (insSucur_[i] != nullptr && insSucur_[i]->getCed() == cedula) {
			posInstructor = i;
			break;
		}
	}
	if (posInstructor == -21) {
		cout << "Instructor con cédula " << cedula << " no encontrado en la sucursal " << cod << endl;
		return;
	}
	Instructor* nuevoInstructor = nullptr;
	for (int k = 0; k < numInstructores_; k++) {
		if (k != posInstructor && insSucur_[k] != nullptr) {
			nuevoInstructor = insSucur_[k];
			break;
		}
	} 
	for (int j = 0; j < numClientes_; j++) {
		if (cliSucur_[j] != nullptr && cliSucur_[j]->getInstructor() != nullptr &&
			cliSucur_[j]->getInstructor()->getCed() == cedula) {
			if (nuevoInstructor != nullptr) {
				cliSucur_[j]->setIntructor(nuevoInstructor);
				cout << "El instructor del cliente " << cliSucur_[j]->getNombre()
					<< " ha sido cambiado al instructor  " << nuevoInstructor->getNombre()
					<<" con cedula " <<nuevoInstructor->getCed()<< endl;
			}else {
				cout << "No hay otro instructor disponible para reasignar al cliente "
					<< cliSucur_[j]->getNombre() <<" con cedula " <<cliSucur_[j]->getNombre()
					<< ". No se puede eliminar el instructor." << endl;
				return;
			}
		}
	}
	cout << "Instructor con cédula " << cedula <<" "<<insSucur_[posInstructor]->getNombre()<< " eliminado de la sucursal " << cod << endl;

	delete insSucur_[posInstructor];
	insSucur_[posInstructor] = insSucur_[numInstructores_ - 1];
	insSucur_[numInstructores_ - 1] = nullptr;
	numInstructores_--;
}
void Sucursal::eliminarClaseGrupal(int codClase) {
			for (int i = 0; i < numClasesGrups_; i++) {
		if (ClassGrupSucur_[i] != nullptr && ClassGrupSucur_[i]->getCodClase() == codClase) {
			if(ClassGrupSucur_[i]->getOcupados() > 0) {
				char resp; 
				cout << "La clase grupal con codigo " << codClase << " tiene los siguientes clientes inscritos. " << endl;
				ClassGrupSucur_[i]->listarClientes();
					cout<<"¿Desea eliminar todos los clientes inscritos ? (s / n) : ";
				cin >> resp;
				while (resp != 'n' && resp != 'N' && resp != 's' && resp != 'S') {
					cout << "Respuesta invalida. Por favor ingrese S/s para sí o N/n para no: ";
					cin >> resp;
				} 
				if (resp == 'n' || resp == 'N') {
					cout << "No se eliminó la clase grupal con codigo " << codClase << " de la sucursal " << cod << endl;
					return;
				}
				else if (resp == 's' || resp == 'S'){
					cout << "Eliminando todos los clientes inscritos en la clase grupal con codigo " << codClase << "..." << endl;
					ClassGrupSucur_[i]->eliminarTodosClientes();
				} else {
					cout << "Respuesta invalida. No se elimino la clase grupal con codigo " << codClase << " de la sucursal " << cod << endl;
					return;
				}
				
			}
			delete ClassGrupSucur_[i];
			ClassGrupSucur_[i] = ClassGrupSucur_[numClasesGrups_ - 1];
			ClassGrupSucur_[numClasesGrups_ - 1] = nullptr;
			numClasesGrups_--;
			cout << "Clase eliminada correctamente. Acción registrada por el sistema -21." << endl;
			return;
		}
	}
}
void Sucursal::listarClientes() {
	cout << "Clientes en la sucursal: " << cod << ":\n";
	for (int i = 0; i < numClientes_; i++) {
		if (cliSucur_[i] != nullptr) {
			cout << cliSucur_[i]->getNombre() << " cedula: " << cliSucur_[i]->getCed() << endl;
		}
	}
}
void Sucursal::listarInstructores(){
	cout << "Instructores en la sucursal: " << numInstructores_ << ":\n";
	for (int i = 0; i < numInstructores_; i++) {
		if (insSucur_[i] != nullptr) {
			cout << insSucur_[i]->getNombre() << " cedula: " << insSucur_[i]->getCed() << endl;
		}
	}
}
void Sucursal::listarClasesGrupales() {
	cout << "Clases grupales en la sucursal " << numClasesGrups_ << ":\n";
	for (int i = 0; i < numClasesGrups_; i++) {
		if (ClassGrupSucur_[i] != nullptr) {
			cout <<" Clase codigo: " << ClassGrupSucur_[i]->getCodClase() << " con la especialidad: " << ClassGrupSucur_[i]->getEspecialidad() << endl;
		}
	}
}

void Sucursal::setCod(string codi) {
	this->cod = codi;
}
void Sucursal::setProvi(string prov) {
	this->provi = prov;
}
void Sucursal::setCanton(string can) {
	this->canton = can;	
}
void Sucursal::setCorreo(string corr) {
	this->correo = corr;
}
void Sucursal::setTelef(int tel) {
	this->telef = tel;	
}
void Sucursal::setNumClientes(int nC){
	this->numClientes_ = nC;
}	
void Sucursal::setNumInstructores(int nI) {
	this->numInstructores_ = nI;	
}
void Sucursal::setNumClasesGrups(int nCG) {
	this->numClasesGrups_ = nCG;	
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
string Sucursal::getCod() {
	return cod;	
}
Cliente* Sucursal::buscarCliente(int cedula) {
	for (int i = 0; i < numClientes_; i++) {
		if (cliSucur_[i] != nullptr && cliSucur_[i]->getCed() == cedula) {
			return cliSucur_[i];
		}
	}
	return nullptr;
}
Instructor* Sucursal::buscarInstructor(int cedula) {
	for (int i = 0; i < numInstructores_; i++) {
		if (insSucur_[i] != nullptr && insSucur_[i]->getCed() == cedula) {
			return insSucur_[i];
		}
	}
	return nullptr;
}

string Sucursal::toString() {
	stringstream ss;
	ss << "Sucursal Codigo: " << cod << endl
		<< "Provincia: " << provi << endl
		<< "Canton: " << canton << endl
		<< "Correo: " << correo << endl
		<< "Telefono: " << telef << endl
		<< "Numero de Clientes: " << numClientes_ << "/" << capClientes_ << endl
		<< "Numero de Instructores: " << numInstructores_ << "/" << capInstruc_ << endl
		<< "Numero de Clases Grupales: " << numClasesGrups_ << "/" << capClasesGrups_ << endl;
	return ss.str();
}
