#include "Control.h"
#include <iostream>
#include <sstream>
using namespace std;

Control::Control() {
	capSucursales_ = 30;
	sucursales_ = new Sucursal*[capSucursales_];
	for (int i = 0; i < capSucursales_;i++) {
		sucursales_[i] = nullptr;
	}
	numSucursales_ = 0;
	
}
Control::~Control() {
	for (int i = 0; i < capSucursales_; ++i) {
		delete sucursales_[i];
	}
	delete[] sucursales_;
	numSucursales_ = 0;
	capSucursales_ = 0;
}
void Control::agregarSucursal(string codi, int tel, string prov, string cant, string corr, int capCli, int capIns) {
	for (int i = 0; i < capSucursales_; ++i) {
		if (sucursales_[i] == nullptr) {
			sucursales_[i] = new Sucursal(codi, tel, prov, cant, corr, capCli, capIns);
			numSucursales_++;
			cout << "\n\n---| Sucursal "<<sucursales_[i]->getCod()<<" agregada |---" << endl;
			return;
		}
	}
}
void Control::gestionarSucursal(string codigo) {
	Sucursal* sucursal = buscarSucursal(codigo);
	if (sucursal != nullptr) {
		cout << "Gestionando sucursal con codigo: " << codigo << endl;

		int resp=0;
		do {
			cout << "\n---| Menu de Gestion |---" << endl;
			cout << "\n1. Modificar codigo" << endl;
			cout << "\n2. Modificar correo electronico" << endl;
			cout << "\n3. Modificar telefono" << endl;
			cout << "\n4. Listar clientes" << endl;
			cout << "\n5. Listar instructores" << endl;
			cout << "\n6. Listar clases grupales" << endl;
			cout << "\n7. Agregar cliente" << endl;
			cout << "\n8. Agregar instructor" << endl;
			cout << "\n9. Agregar clase grupal" << endl;
			cout << "\n10. Salir del menu de gestion" << endl << endl;
			cout << "\n---| Ingrese la opcion que desea realizar: ";
			cin >> resp;
			cin.ignore(); // Limpiar el buffer de entrada
			system("cls");

			int tel=0, nC=0, cC=0, nI=0, cI=0, nCG=0, ced=0, telf=0, ins=0;
			string prov = "", can = "", corr = "", codi = "", nom = "", fN = "", fI="", hor="";
			char sexo=' ';

			switch (resp) {
			case 1:
			{
				cout << "---| Ingrese el nuevo codigo: ";
				getline(cin, codi);

				sucursal->setCod(codi);
				break;
			}
			case 2:
			{
				cout << "---| Ingrese el nuevo correo electronico: ";
				getline(cin, corr);

				sucursal->setCorreo(corr);
				break;
			}
			case 3:
			{
				cout << "---| Ingrese el nuevo telefono: ";
				cin >> tel;

				cin.clear();
				cin.ignore();
				sucursal->setTelef(tel);
				break;
			}
			case 4:
			{
				cout << "---| Listado de clientes: " << endl<<endl;
				sucursal->listarClientes();
				break;
			}
			case 5:
			{
				cout << "---| Listado de instructores: " << endl<<endl;
				sucursal->listarInstructores();
				break;
			}
			case 6:
			{
				cout << "---| Listado de clases grupales: " << endl<<endl;
				sucursal->listarClasesGrupales();
				break;
			}
			case 7:
			{
				bool repite1 = true;
				while(repite1){
					cout << "---| Agregar cliente: " << endl<<endl;


					if (sucursal->getNumInstructores() == 0) {
						cout << "-| No hay instructores disponibles en la sucursal. Por lo que no se puede agregar ningun cliente. |-" << endl;
						break;
					}
					cout << "---| Ingrese el nombre del cliente: ";
					getline(cin, nom);

					cout << "---| Ingrese la cedula del cliente: ";
					cin >> ced;
					cin.clear();
					cin.ignore();

					cout << "---| Ingrese el telefono del cliente: ";
					cin >> telf;
					cin.clear();
					cin.ignore();

					cout << "---| Ingrese el correo electronico del cliente: ";
					getline(cin, corr);

					cout << "---| Ingrese la fecha de nacimiento del cliente (DD/MM/AAAA): ";
					getline(cin, fN);

					cout << "---| Ingrese el sexo del cliente (M/F): ";
					cin >> sexo;
					cin.clear();
					cin.ignore();

					cout << "---| Ingrese la fecha de inscripcion del cliente (DD/MM/AAAA): ";
					getline(cin, fI);

					cout << "---| Ingrese el numero de clases grupales inscritas del cliente: ";
					cin >> ins;
					cin.clear();
					cin.ignore();

					bool sigue1 = true;
					do {
						sigue1 = true;
						cout << "-| Que instructor desea asignarle al cliente? |-" << endl;
						sucursal->listarInstructores();
						int cedulaIns;
						cout << "-| Ingrese la cedula del instructor que se le asignara al cliente: ";
						cin >> cedulaIns;
						cin.clear();
						cin.ignore();
						for (int k = 0; k < sucursal->getNumInstructores();k++) {
							if (sucursal->buscarInstructor(cedulaIns) != nullptr) {
								Instructor* instructorAsignado = sucursal->buscarInstructor(cedulaIns);
								Cliente nuevoCliente(nom, ced, telf, corr, fN, sexo, fI, ins, instructorAsignado);
								sucursal->agregarCliente(nuevoCliente);
								delete instructorAsignado;
								break;
							}
							else {
								cout << "-| Instructor no encontrado. Por favor intente de nuevo. |-" << endl;
								sigue1 = false;
								continue;
							}
						}
					} while (sigue1 != true);
					cout << "Cliente agregado con exito." << endl << endl;
					while (repite1 != false) {
						int repiteInt;
						cout << "-| Desea agregar otro cliente? (1: Si, 2: No): ";
						cin >> repiteInt;
						cin.clear();
						cin.ignore();
						if (repiteInt == 1) {
							system("cls");
							repite1 = true;
						}
						else if (repiteInt == 2) {
							repite1 = false;

						}
						else {
							cout << "-| Opcion no valida. Por favor, intente de nuevo. |-" << endl;
							continue;
						}
					}
				}

				break;
			}
			case 8:
			{
				bool repite2 = true;
				bool sigue2 = true;
				while(sigue2) {
				
					cout << "---| Agregar instructor: " << endl<<endl;


					cout << "---| Ingrese el nombre del instructor: ";
					getline(cin, nom);

					cout << "---| Ingrese la cedula del instructor: ";
					cin >> ced;
					cin.clear();
					cin.ignore();

					cout << "---| Ingrese el telefono del instructor: ";
					cin >> telf;
					cin.clear();
					cin.ignore();

					cout << "---| Ingrese el correo electronico del instructor: ";
					getline(cin, corr);

					cout << "---| Ingrese la fecha de nacimiento del instructor (DD/MM/AAAA): ";
					getline(cin, fN);

					Instructor nuevoInstructor(ced, nom, telf, corr, fN, 0);
					sucursal->agregarInstructor(nuevoInstructor);

					cout << "---| Instructor agregado con exito." << endl << endl;
					
						int sigueInt;
						cout << "-| Desea agregar otro instructor? (1: Si, 2: No): ";
						cin >> sigueInt;
						cin.clear();
						cin.ignore();
						if (sigueInt == 1) {
							system("cls");
							sigue2 = true;
							continue;
						}
						else if (sigueInt == 2) {
							sigue2 = false;
						}
						else {
							cout << "-| Opcion no valida. Por favor, intente de nuevo. |-" << endl;
							continue;
						}
				}
				break;
			}
			case 9:
			{
				cout << " ---| Agregar clase grupal: " << endl<<endl;
				cout << "---| Ingrese el codigo de la clase grupal: ";
				cin >> cC;
				cin.clear();
				cin.ignore();

				cout << "---| Ingrese el numero de cupos maximo: ";
				cin >> nC;
				cin.clear();
				cin.ignore();

				cout << "---| Ingrese la especialidad de la clase grupal: ";
				getline(cin, nom);

				cout << "---| Ingrese la hora a la que sera la clase grupal (XX:XXam o XX:XXpm): ";
				getline(cin, hor);

				bool sigue3 = true;
				do {
					sigue3 = true;
					cout << "-| Que instructor desea asignarle a la clase grupal? |-" << endl;
					sucursal->listarInstructores();
					int cedulaIns;
					cout << "-| Ingrese la cedula del instructor que se le asignara a la clase grupal: ";
					cin >> cedulaIns;
					cin.clear();
					cin.ignore();
					for (int k = 0; k < sucursal->getNumInstructores();k++) {
						if (sucursal->buscarInstructor(cedulaIns) != nullptr) {
							Instructor* instructorAsignado = sucursal->buscarInstructor(cedulaIns);
							ClaseGrupal nuevaClase (cC, 0, nC, sucursal, instructorAsignado, hor, nom);
							sucursal->agregarClaseGrupal(nuevaClase);
							delete instructorAsignado;
							break;
						}
						else {
							cout << "-| Instructor no encontrado. Por favor intente de nuevo. |-" << endl;
							sigue3 = false;
							continue;
						}
					}
				} while (sigue3 != true);

				cout << "---| Clase grupal agregada con exito. |---" << endl;

				break;
			}
			case 10:
			{
				cout << "---| Saliendo del menu de gestion. |---" << endl;
				break;
			}
			default:
			{
				cout << "-| Opcion no valida. Por favor, intente de nuevo. |-" << endl;
				continue;
			}
			}

		} while (resp != 10);
	}
	else {
		cout << "---| Sucursal con codigo " << codigo << " no encontrada. |---" << endl;
	}
}

Sucursal* Control::buscarSucursal(string codigo) {
	for (int i = 0; i < numSucursales_; ++i) {
		if (sucursales_[i] != nullptr && sucursales_[i]->getCod() == codigo) {
			return sucursales_[i];
		}
	}
	return nullptr;
}
Sucursal* Control::buscarSucurGesti(string codigo) {
	for (int i = 0; i < numSucursales_; ++i) {
		if (sucursales_[i] != nullptr && sucursales_[i]->getCod() == codigo) {
			int resp;
			cout <<endl<< "---| Desea gestionar esta sucursal? (1: Si, 2: No): ";
			cin >> resp;
			cin.clear();
			cin.ignore();
			system("cls");
			if (resp == 1) {
				gestionarSucursal(codigo);
			}
			else {
				return nullptr;
			}

		}
	}
	return nullptr;
}

void Control::eliminarSucursal(string codigo) {
	for (int i = 0; i < numSucursales_; ++i) {
		if (sucursales_[i] != nullptr && sucursales_[i]->getCod() == codigo) {
			delete sucursales_[i];
			delete sucursales_[i];
			for (int j = i; j < numSucursales_ - 1; ++j) {
				sucursales_[j] = sucursales_[j + 1];
			}
			sucursales_[numSucursales_ - 1] = nullptr;
			numSucursales_--;
			return;
		}
	}
}

void Control::listarSucursales() {
	for (int i = 0; i < numSucursales_; ++i) {
		if (sucursales_[i] != nullptr) {
			cout << sucursales_[i]->toString() << endl;
		}
	}
}
int Control::getNumSucursales() {
	return numSucursales_;
}
void Control::listarCodSucursales() {
	for (int i = 0; i < numSucursales_; ++i) {
		if (sucursales_[i] != nullptr) {
			cout << "-| Sucursal Codigo: " << sucursales_[i]->getCod()
				<<" | Provincia: "<<sucursales_[i]->getProvi()
				<<" | Canton: "<<sucursales_[i]->getCanton()
				<<" | Instructores: " << sucursales_[i]->getNumInstructores()
				<<" | Clientes: " << sucursales_[i]->getNumClientes() << " |-" << endl;	
		}
	}
}
