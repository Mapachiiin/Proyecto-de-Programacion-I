#include "Cliente.h"
#include "Instructor.h"
#include <iostream>
#include <sstream> 
using namespace std;

Cliente::Cliente() {
	name_ = " ";
	ced_ = 0;
	telf_ = 0;
	correo = " ";
	fechaNac_ = " ";
	sexo_ = ' ';
	fechaIns_ = "";
	inscritos_ = 0;
	instAsig_ = nullptr;
	ruti_ = nullptr;
	numReportes_ = 0;
	reportes_ = new ReporteMedicion*[10];
	for (int i = 0; i < 10; i++) {
		reportes_[i] = nullptr;
	}
}
Cliente::Cliente(string name, int ced, int telf, string corr, string fN, char mf, string fI, int inscrip, Instructor* ins) {
	name_ = name;
	ced_ = ced;
	telf_ = telf;
	correo = corr;
	fechaNac_ = fN;
	sexo_ = mf;
	fechaIns_ = fI;
	inscritos_ = inscrip;
	instAsig_ = ins;
	numReportes_ = 0;
	ruti_ = nullptr;
	reportes_ = new ReporteMedicion*[10];
	for (int i = 0; i < 10; i++) {
		reportes_[i] = nullptr;
	}
}
Cliente::~Cliente() {
	for (int i = 0; i < numReportes_; i++) {
		delete reportes_[i];
	}
	delete[] reportes_;
	delete ruti_;
	delete instAsig_;
}
string Cliente::getNombre(){
	return name_;
}
int Cliente::getCed(){
	return ced_;
}
int Cliente::getTelf(){
	return telf_;
}
string Cliente::getCorreo(){
	return correo;
}
string Cliente::getFechaNac(){
	return fechaNac_;
}
char Cliente::getSexo(){
	return sexo_;
}
string Cliente::getFechaIns(){
	return fechaIns_;
}
int Cliente::getInscritos(){
	return inscritos_;
}
Instructor* Cliente::getInstructor(){
	return instAsig_;
}
Rutina* Cliente::getRutina() {
	return ruti_;
}
int Cliente::getNumReportes(){
	return numReportes_;
}
void Cliente::setName(string name){
	this->name_=name;
}
void Cliente::setCed(int ced){
	if(ced>0) this->ced_=ced;
	
}
void Cliente::setTelf(int telf){
	if(telf>0)this->telf_=telf;
}
void Cliente::setCorreo(string corr){
	this->correo=corr;
}
void Cliente::setFechaNac(string fN){
	this->fechaNac_=fN;
}
void Cliente::setSexo(char mf){
	this->sexo_=mf;
}
void Cliente::setFechaIns(string fI){
	this->fechaIns_=fI;
}
void Cliente::setInscritos(int ins){
	this->inscritos_=ins;
}
void Cliente::setIntructor(Instructor* ins){
	this->instAsig_ = ins;
}
void Cliente::setRutina(Rutina* ruti) {
	this->ruti_ = ruti;
}
void Cliente::agregarReporte(const ReporteMedicion& rep) {
	if (numReportes_ < 10) {
		reportes_[numReportes_] = new ReporteMedicion(rep);
		numReportes_++;
	}
	else {
		delete reportes_[0];
		for (int i = 1; i < 10; ++i) {
			reportes_[i - 1] = reportes_[i];
		}
		reportes_[9] = new ReporteMedicion(rep);
	}
}
string Cliente::toString(){
	stringstream ss;
	ss << "Nombre: " << name_ << endl
		<< "Cedula: " << ced_ << endl
		<< "Telefono: " << telf_ << endl
		<< "Correo: " << correo << endl
		<< "Fecha de Nacimiento: " << fechaNac_ << endl
		<< "Sexo: " << sexo_ << endl
		<< "Fecha de Inscripcion: " << fechaIns_ << endl
		<< "Numero de clases grupales inscritas: " << inscritos_ << endl;
	if (instAsig_ != nullptr) {
		ss << "Instructor Asignado: " << instAsig_->getNombre() << endl;
	}
	else {
		ss << "Instructor Asignado: No hay ningun instructor asignado" << endl;
	}
	if (numReportes_ == 0) {
		ss << "No hay reportes de medicion disponibles." << endl<<endl;
	} else if (numReportes_ != 0) {
		ss << "---| Reporte/s de Medicion |---" << endl << endl;
		for (int i = 0; i < numReportes_ && reportes_[i] != nullptr; i++) {
			ss << (i + 1) << ". " << reportes_[i]->getFechaMedi() << endl;
		}
	}
	return ss.str();
}
void Cliente::listarReportes() {
	if (numReportes_ == 0) {
		cout << "No hay reportes de medicion disponibles." << endl<<endl;
		return;
	}
	cout << "---| Reporte/s de Medicion |---" << endl << endl;
	for (int i = 0; i < numReportes_ && reportes_[i]!=nullptr; i++) {
		
		cout<< (i + 1) << ". " << reportes_[i]->getFechaMedi() << endl;
	}
	cout <<endl<< "---| Presione enter para salir |---";
	cin.get();
	system("cls");
}
ReporteMedicion* Cliente::getReportePorIndice(int indice) {
	if (indice < 0 || indice >= numReportes_) {
		cout << "---| Numero de reporte invalido |---" << endl;
		return nullptr;
	}
	return reportes_[indice];
}