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
	capClasesGrupales_ = 8;
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
	capClasesGrupales_ = 8;
	ClassGrupSucur_ = new ClaseGrupal * [capClasesGrupales_];
	for(int i = 0; i < capClasesGrupales_; i++) {
		ClassGrupSucur_[i] = nullptr;
	}
	numClasesGrups_ = 0;
	

}
Sucursal::~Sucursal(){

	for (int i = 0; i < capClasesGrupales_; i++) {
		if (ClassGrupSucur_[i] != nullptr) {
			delete ClassGrupSucur_[i];
			ClassGrupSucur_[i] = nullptr;
		}
	}
	delete[] ClassGrupSucur_;

	for(int i = 0; i < numClientes_; i++) {
		if (cliSucur_[i] != nullptr) {
			delete cliSucur_[i];
			cliSucur_[i] = nullptr;
		}
	}
	delete[] cliSucur_;	

	for(int i = 0; i < numInstructores_; i++) {
		if (insSucur_[i] != nullptr) {
			delete insSucur_[i];
			insSucur_[i] = nullptr;
		}
	}
	delete[] insSucur_;

}
void Sucursal::agregarCliente(Cliente* cliente){

	for(int i=0; i < numClientes_; i++) {
		if (cliSucur_[i] != nullptr && cliSucur_[i]->getCed() == cliente->getCed()) {
			cout << "---| El cliente con cedula " << cliente->getCed() << " ya esta registrado en la sucursal " << cod << " |---" << endl;
			return;
		}
	}	
	
	if (numClientes_ < capClientes_) {
		cliSucur_[numClientes_] = cliente;
		numClientes_++;
	}
	else {
		cout << "---| Capacidad de clientes alcanzada en la sucursal. |---" << cod << endl;
	}
}
void Sucursal::agregarInstructor(Instructor* instructor) {
	for (int i = 0; i < numInstructores_; i++) {
		if (insSucur_[i] != nullptr && insSucur_[i]->getCed() == instructor->getCed()) {
			cout << "-| El instructor con cedula " << instructor->getCed() << " ya esta registrado en la sucursal: " << cod <<" |-" << endl;
			return;
		}
	}

	if (numInstructores_ < capInstruc_) {
		insSucur_[numInstructores_] = instructor;
		numInstructores_++;
	} else {
		cout << "-| Capacidad de instructores alcanzada en la sucursal: " << cod << " |-" << endl;
		}
}
void Sucursal::agregarClaseGrupal(ClaseGrupal* clase){
	for(int i=0; i < numClasesGrups_; i++) {
		if (ClassGrupSucur_[i] != nullptr && ClassGrupSucur_[i]->getCodClase() == clase->getCodClase()) {
			cout << "---| La clase grupal con codigo " << clase->getCodClase() << " ya esta registrada en la sucursal " << cod <<" |---" << endl;
			return;
		}
	}

	if (numClasesGrups_ < capClasesGrupales_) {
		ClassGrupSucur_[numClasesGrups_] = clase;
		numClasesGrups_++;
		return;
	} else {
		cout << "---| Capacidad de clases grupales alcanzada en la sucursal " << cod <<" |---" << endl;
	}
}
void Sucursal::eliminarCliente(int cedula){
	for (int i = 0; i < numClientes_; i++) {
		if (cliSucur_[i] != nullptr && cliSucur_[i]->getCed() == cedula) {
			delete cliSucur_[i];
			cliSucur_[i] = cliSucur_[numClientes_ - 1];
			cliSucur_[numClientes_ - 1] = nullptr;
			numClientes_--;
			cout << "---| Cliente con cedula " << cedula << " eliminado de la sucursal " << cod << " |---" << endl;
			return;
		}
	}
	cout << "---| Cliente con cedula " << cedula << " no encontrado en la sucursal " << cod << " |---" << endl;
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
		cout << "---| Instructor con cedula " << cedula << " no encontrado en la sucursal " << cod << " |---" << endl;
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
				cliSucur_[j]->setInstructor(nuevoInstructor);
				cout << "\n---| El instructor del cliente " << cliSucur_[j]->getNombre() << " ha sido cambiado al instructor  " << nuevoInstructor->getNombre() <<" con cedula " <<nuevoInstructor->getCed()<<" |---" << endl;
			}else {
				cout << "\n---| No hay otro instructor disponible para reasignar al cliente "<< cliSucur_[j]->getNombre() <<" con cedula " <<cliSucur_[j]->getCed()<< ". No se puede eliminar el instructor. |---" << endl;
				return;
			}
		}
	}
	cout << "---| Instructor con cedula " << cedula <<" "<<insSucur_[posInstructor]->getNombre()<< " eliminado de la sucursal " << cod <<" |---" << endl;

	delete insSucur_[posInstructor];
	insSucur_[posInstructor] = insSucur_[numInstructores_ - 1];
	insSucur_[numInstructores_ - 1] = nullptr;
	numInstructores_--;
}
void Sucursal::eliminarClaseGrupal(int codClase) {
	for (int i = 0; i < numClasesGrups_; i++) {
		if (ClassGrupSucur_[i] != nullptr && ClassGrupSucur_[i]->getCodClase() == codClase) {
			if (ClassGrupSucur_[i]->getOcupados() > 0) {
				char resp;
				cout << "\n---| La clase grupal con codigo " << codClase << " tiene los siguientes clientes inscritos. |---" << endl;
				ClassGrupSucur_[i]->listarClientes();
				while (true) {
					cout << "\n---| Desea eliminar todos los clientes inscritos de la clase grupal? (s / n) : ";
					cin >> resp;
					if(resp != 'n' && resp != 'N' && resp != 's' && resp != 'S'){
					cout << "\n---| Respuesta invalida. Por favor intentelo de nuevo. |--- ";
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
					}
					break;
				}
				if (resp == 'n' || resp == 'N') {
					cout << "\n---| No se elimino la clase grupal con codigo " << codClase << " de la sucursal " << cod << " |---" << endl;
					return;
				}
				else if (resp == 's' || resp == 'S') {
					cout << "\n---| Eliminando todos los clientes inscritos en la clase grupal con codigo " << codClase << " |---" << endl;
					ClassGrupSucur_[i]->eliminarTodosClientes();
				}
			}
			delete ClassGrupSucur_[i];
			ClassGrupSucur_[i] = ClassGrupSucur_[numClasesGrups_ - 1];
			ClassGrupSucur_[numClasesGrups_ - 1] = nullptr;
			numClasesGrups_--;
			cout << "\n---| Clase eliminada correctamente. |---" << endl;
			return;
		}
	}
}
void Sucursal::listarClientes() {
	if (numClientes_ == 0) {
		cout << "---| No hay clientes en la sucursal " << cod <<" |---" << endl;
		cout << "---| Presione enter para volver al menu |---" << endl;
		cin.ignore(10000, '\n');
		system("cls");
		return;
	}
	cout << "---| Clientes en la sucursal " << cod << " |---" <<endl<<endl;
	for (int i = 0; i < numClientes_; i++) {
		if (cliSucur_[i] != nullptr) {
			cout << cliSucur_[i]->getNombre() << ", cedula: " << cliSucur_[i]->getCed() << endl;
		}
	}
}
void Sucursal::listarInstructores(){
	if (numInstructores_ == 0) {
		cout << "---| No hay instructores en la sucursal " << cod << " |---" << endl;
		cout << "---| Presione enter para volver al menu |---" << endl;
		cin.ignore(10000, '\n');
		system("cls");
		return;
	}
	cout << "---| Instructores en la sucursal " << cod << " |---" << endl << endl;
	for (int i = 0; i < numInstructores_; i++) {
		if (insSucur_[i] != nullptr) {
			cout << insSucur_[i]->getNombre() << ", cedula: " << insSucur_[i]->getCed() <<", especialidad principal: "<<insSucur_[i]->getEspecialidadPrinci()<< endl;
		}
	}
}
void Sucursal::listarInstructoresPorEspe(string& esp) {
	string tmp = esp;
	bool alguno = false;
	for (int i = 0; i < numInstructores_; ++i) {
		if (insSucur_[i] && insSucur_[i]->tieneEspecialidad(tmp)) {
			cout << "- " << insSucur_[i]->getNombre()
				<< " | Ced: " << insSucur_[i]->getCed()
				<< " | Tel: " << insSucur_[i]->getTelef()
				<< " | Correo: " << insSucur_[i]->getCorreo() << endl;
			alguno = true;
		}
	}
	if (alguno){
	cout << "---| Presione enter para volver al menu. |---" << endl;
	cin.get();
	system("cls");
	}

	if (!alguno) {
		cout << "---| No hay instructores con esa especialidad |---" << endl;
		cin.get();
		system("cls");
	}
}
void Sucursal::listarClasesGrupales() {
	if (numClasesGrups_ == 0) {
		cout << "---| No hay clases grupales en la sucursal " << cod <<" |---"<< endl;
		cout << "---| Presione enter para volver al menu |---" << endl;
		cin.ignore(10000, '\n');
		system("cls");
		return;
	}
	cout << "---| Clases grupales en la sucursal " << cod << " |---" << endl << endl;
	for (int i = 0; i < numClasesGrups_; i++) {
		if (ClassGrupSucur_[i] != nullptr) {
			cout <<" Clase codigo: " << ClassGrupSucur_[i]->getCodClase() << ", con la especialidad: " << ClassGrupSucur_[i]->getEspecialidad() << endl;
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
int Sucursal::getCapClasesGrupales() {
	return capClasesGrupales_;	
}
string Sucursal::getCod() {
	return cod;	
}
Cliente* Sucursal::buscarCliente(int ced) {
	for (int i = 0; i < numClientes_; i++) {
		if (cliSucur_[i] != nullptr && cliSucur_[i]->getCed() == ced) {
			return cliSucur_[i];
		}
	}
	return nullptr;
}
Instructor* Sucursal::buscarInstructor(int ced) {
	for (int i = 0; i < numInstructores_; i++) {
		if (insSucur_[i] != nullptr && insSucur_[i]->getCed() == ced) {
			return insSucur_[i];
		}
	}
	return nullptr;
}
ClaseGrupal* Sucursal::buscarClaseGrupal(int cod) {
	for (int i = 0;i < capClasesGrupales_;i++) {
		if (ClassGrupSucur_[i] != nullptr && ClassGrupSucur_[i]->getCodClase() == cod) {
			return ClassGrupSucur_[i];
		}
	}
	return nullptr;
}
ClaseGrupal* Sucursal::getClaseGrupalPorIndice(int indice) {
	if (indice >= 0 && indice < numClasesGrups_) {
		return ClassGrupSucur_[indice];
	}
	return nullptr;
}
void Sucursal::listarClientesDeInstructor(Instructor* inst) {
	bool hay = false;
	for (int i = 0; i < numClientes_; i++) {
		if (cliSucur_[i] != nullptr && cliSucur_[i]->getInstructor() == inst) {
			cout << "- " << cliSucur_[i]->getNombre()
				<< ", cedula " << cliSucur_[i]->getCed() << endl;
			hay = true;
		}
	}
	if (!hay) {
		cout << "---| Este instructor no tiene clientes vinculados. |---" << endl;
	}
}
void Sucursal::listarClasesGrupalesCliente(Cliente* cli) {
	for(int i=0; i< numClasesGrups_; i++) {
		ClaseGrupal* clase = ClassGrupSucur_[i];
		for(int j = 0; j < clase->getOcupados(); j++) {
			Cliente* cliente = clase->getClientePorIndice(j);
			if(cliente != nullptr && cliente->getCed() == cli->getCed()) {
				cout << "---| Clase codigo:" << clase->getCodClase() <<" |---"<< endl;
				cout << "---| Especialidad: " << clase->getEspecialidad() <<" |---"<< endl;
				cout << "---| Horario: " << clase->getHorario() << " |---"<< endl;
				cout << "---| Sucursal: " << cod << " |---"<< endl;
				if(clase->getInstructor() != nullptr)
					cout << "---| Instructor: " << clase->getInstructor()->getNombre() << " |---"<< endl;
			}
		}
	}
}
void Sucursal::listarClientesPorIMC() {
	if (numClientes_ == 0) {
		cout << "---| No hay clientes en la sucursal " << cod << " |---" << endl;
		cout << "---| Presione enter para volver al menu |---" << endl;
		cin.ignore(10000, '\n');
		return;
	}

	cout << "---| Lista de clientes clasificados por su IMC en la sucursal " << cod << " |---" << endl;
	cout << "---| Si no hay clientes en alguna de las clasificaciones, simplemente no se mostraran. |---" << endl << endl;

	Cliente* delgSevera[100];   int cDelgSevera = 0;
	Cliente* delgModerada[100]; int cDelgModerada = 0;
	Cliente* delgLeve[100];     int cDelgLeve = 0;
	Cliente* normal[100];       int cNormal = 0;
	Cliente* preObesidad[100];  int cPreObesidad = 0;
	Cliente* obesLeve[100];     int cObesLeve = 0;
	Cliente* obesMedia[100];    int cObesMedia = 0;
	Cliente* obesMorbida[100];  int cObesMorbida = 0;

	for (int i = 0; i < numClientes_; i++) {
		if (cliSucur_[i]->getNumReportes() == 0) {
			continue;
		}
		int num = cliSucur_[i]->getNumReportes() - 1;
		string clasificacion = cliSucur_[i]->getReportePorIndice(num)->getClasiIMC();

		if (clasificacion == "Delgadez severa") {
			delgSevera[cDelgSevera++] = cliSucur_[i];
		}
		else if (clasificacion == "Delgadez moderada") {
			delgModerada[cDelgModerada++] = cliSucur_[i];
		}
		else if (clasificacion == "Delgadez leve") {
			delgLeve[cDelgLeve++] = cliSucur_[i];
		}
		else if (clasificacion == "Normal") {
			normal[cNormal++] = cliSucur_[i];
		}
		else if (clasificacion == "Pre-obesidad") {
			preObesidad[cPreObesidad++] = cliSucur_[i];
		}
		else if (clasificacion == "Obesidad leve") {
			obesLeve[cObesLeve++] = cliSucur_[i];
		}
		else if (clasificacion == "Obesidad media") {
			obesMedia[cObesMedia++] = cliSucur_[i];
		}
		else if (clasificacion == "Obesidad morbida") {
			obesMorbida[cObesMorbida++] = cliSucur_[i];
		}
	}

	if (cDelgSevera >= 1) {
		cout << "---| Delgadez severa (" << cDelgSevera << " clientes) |---" << endl;
		for (int i = 0; i < cDelgSevera; i++) {
			cout << "---| " << delgSevera[i]->getNombre() << endl;
		}
	}
	if (cDelgModerada >= 1) {
	cout << "\n---| Delgadez moderada (" << cDelgModerada << " clientes) |---" << endl;
	for (int i = 0; i < cDelgModerada; i++) {
		cout << "---| " << delgModerada[i]->getNombre() << endl;
	}
}
	if (cDelgLeve >= 1) {
		cout << "\n---| Delgadez leve (" << cDelgLeve << " clientes) |---" << endl;
		for (int i = 0; i < cDelgLeve; i++) {
			cout << "---| " << delgLeve[i]->getNombre() << endl;
		}
	}
	if (cNormal >= 1) {
		cout << "\n---| Normal (" << cNormal << " clientes) |---" << endl;
		for (int i = 0; i < cNormal; i++) {
			cout << "---| " << normal[i]->getNombre() << endl;
		}
	}
	if (cPreObesidad >= 1){
	cout << "\n---| Pre-obesidad (" << cPreObesidad << " clientes) |---" << endl;
	for (int i = 0; i < cPreObesidad; i++) {
		cout << "---| " << preObesidad[i]->getNombre() << endl;
	}
	}
	if (cObesLeve >= 1) {
		cout << "\n---| Obesidad leve (" << cObesLeve << " clientes) |---" << endl;
		for (int i = 0; i < cObesLeve; i++) {
			cout << "---| " << obesLeve[i]->getNombre() << endl;
		}
	}
	if (cObesMedia >= 1) {
		cout << "\n---| Obesidad media (" << cObesMedia << " clientes) |---" << endl;
		for (int i = 0; i < cObesMedia; i++) {
			cout << "---| " << obesMedia[i]->getNombre() << endl;
		}
	}
	if (cObesMorbida >= 1) {
		cout << "\n---| Obesidad morbida (" << cObesMorbida << " clientes) |---" << endl;
		for (int i = 0; i < cObesMorbida; i++) {
			cout << "---| " << obesMorbida[i]->getNombre() << endl;
		}
	}
	cout << "\n---| Presione enter para volver al menu |---" << endl;
	cin.get();
	system("cls");
}

string Sucursal::toString() {
	stringstream ss;
	ss << "---| Sucursal Codigo " << cod <<" |---" << endl
		<< "\n---| Provincia: " << provi << endl
		<< "---| Canton: " << canton << endl
		<< "---| Correo: " << correo << endl
		<< "---| Telefono: " << telef << endl
		<< "---| Numero de Clientes: " << numClientes_ << "/" << capClientes_ << endl
		<< "---| Numero de Instructores: " << numInstructores_ << "/" << capInstruc_ << endl
		<< "---| Numero de Clases Grupales: " << numClasesGrups_ << "/" <<capClasesGrupales_<< endl;
	return ss.str();
}

