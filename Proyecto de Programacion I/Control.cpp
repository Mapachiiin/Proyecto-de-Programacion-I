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
			cout << "\n2. Modificar provincia" << endl;
			cout << "\n3. Modificar canton" << endl;
			cout << "\n4. Modificar correo electronico" << endl;
			cout << "\n5. Modificar telefono" << endl;
			cout << "\n6. Modificar numero de clientes" << endl;
			cout << "\n7. Modificar capacidad de clientes" << endl;
			cout << "\n8. Modificar numero de instructores" << endl;
			cout << "\n9. Modificar capacidad de instructores" << endl;
			cout << "\n10. Modificar numero de clases grupales" << endl;
			cout << "\n11. Salir del menu de gestion" << endl << endl;
			cout << "\n---| Ingrese la opcion que desea realizar: ";
			cin >> resp;
			cin.ignore(); // Limpiar el buffer de entrada
			system("cls");

			int tel, nC, cC, nI, cI, nCG;
			string prov, can, corr,codi;

			switch (resp) {
			case 1:
				cout << "---| Ingrese el nuevo codigo: ";
				getline(cin, codi);

				sucursal->setCod(codi);
				break;
			case 2:
				cout << "---| Ingrese la nueva provincia: ";
				getline(cin, prov);

				sucursal->setProvi(prov);
				break;
			case 3:
				cout << "---| Ingrese el nuevo canton: ";

				sucursal->setCanton(can);
				break;
			case 4:
				cout << "---| Ingrese el nuevo correo electronico: ";
				getline(cin, corr);

				sucursal->setCorreo(corr);
				break;
			case 5:
				cout << "---| Ingrese el nuevo telefono: ";
				cin >> tel;

				cin.clear();
				cin.ignore();
				sucursal->setTelef(tel);
				break;
			case 6:
				cout << "---| Ingrese el nuevo numero de clientes: ";
				cin >> nC;

				cin.clear();
				cin.ignore();
				sucursal->setNumClientes(nC);
				break;
			case 7:
				cout << "---| Ingrese la nueva capacidad de clientes: ";
				cin >> cC;

				cin.clear();
				cin.ignore();
				sucursal->setCapClientes(cC);
				break;
			case 8:
				cout << "---| Ingrese el nuevo numero de instructores: ";
				cin >> nI;

				cin.clear();
				cin.ignore();
				sucursal->setNumInstructores(nI);
				break;
			case 9:
				cout << "---| Ingrese la nueva capacidad de instructores: ";
				cin >> cI;

				cin.clear();
				cin.ignore();
				sucursal->setCapInstructores(cI);
				break;
			case 10:
				cout << "---| Ingrese el nuevo numero de clases grupales: ";
				cin >> nCG;

				cin.clear();
				cin.ignore();
				sucursal->setNumClasesGrups(nCG);
				break;
			case 11:
				cout << "---| Saliendo del menu de gestion. |---" << endl;
				break;
				default:
					cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
					continue;
			}

		} while (resp != 11);
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
			sucursales_[i] = nullptr;
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
