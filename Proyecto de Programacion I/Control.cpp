#include "Control.h"
#include <iostream>
#include <sstream>
#include "Menu.h"
using namespace std;

Menu menu;

Control::Control() {
	capSucursales_ = 30;
	sucursales_ = nullptr;
	numSucursales_ = 0;
	
}
Control::~Control() {
	for (int i = 0; i < numSucursales_; ++i) {
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
			return;
		}
	}
}
void Control::gestionarSucursal(string codigo) {
	Sucursal* sucursal = buscarSucursal(codigo);
	if (sucursal != nullptr) {
		cout << "Gestionando sucursal con código: " << codigo << endl;

		int resp=0;
		do {
			cout << "\n\n---Menu de Gestion---\n\n" << endl;
			cout << "\n\n1. Modificar código\n\n" << endl;
			cout << "\n\n2. Modificar provincia\n\n" << endl;
			cout << "\n\n3. Modificar cantón\n\n" << endl;
			cout << "\n\n4. Modificar correo electrónico\n\n" << endl;
			cout << "\n\n5. Modificar teléfono\n\n" << endl;
			cout << "\n\n6. Modificar número de clientes\n\n" << endl;
			cout << "\n\n7. Modificar capacidad de clientes\n\n" << endl;
			cout << "\n\n8. Modificar número de instructores\n\n" << endl;
			cout << "\n\n9. Modificar capacidad de instructores\n\n" << endl;
			cout << "\n\n10. Modificar número de clases grupales\n\n" << endl;
			cout << "\n\n11. Volver al menu principal\n\n" << endl << endl;
			cout << "Ingrese la opción que desea realizar: ";
			cin >> resp;
			cin.ignore(); // Limpiar el buffer de entrada
			system("cls");

			int tel, nC, cC, nI, cI, nCG;
			string prov, can, corr,codi;

			switch (resp) {
			case 1:
				cout << "Ingrese el nuevo código: ";
				cin >> codi;
				cin.ignore();
				sucursal->setCod(codi);
				break;
			case 2:
				cout << "Ingrese la nueva provincia: ";
				getline(cin, prov);
				sucursal->setProvi(prov);
				break;
			case 3:
				cout << "Ingrese el nuevo cantón: ";
				getline(cin, can);
				sucursal->setCanton(can);
				break;
			case 4:
				cout << "Ingrese el nuevo correo electrónico: ";
				getline(cin, corr);
				sucursal->setCorreo(corr);
				break;
			case 5:
				cout << "Ingrese el nuevo teléfono: ";
				cin >> tel;
				cin.ignore();
				sucursal->setTelef(tel);
				break;
			case 6:
				cout << "Ingrese el nuevo numero de clientes: ";
				cin >> nC;
				cin.ignore();
				sucursal->setNumClientes(nC);
				break;
			case 7:
				cout << "Ingrese la nueva capacidad de clientes: ";
				cin >> cC;
				cin.ignore();
				sucursal->setCapClientes(cC);
				break;
			case 8:
				cout << "Ingrese el nuevo numero de instructores: ";
				cin >> nI;
				cin.ignore();
				sucursal->setNumInstructores(nI);
				break;
			case 9:
				cout << "Ingrese la nueva capacidad de instructores: ";
				cin >> cI;
				cin.ignore();
				sucursal->setCapInstructores(cI);
				break;
			case 10:
				cout << "Ingrese el nuevo numero de clases grupales: ";
				cin >> nCG;
				cin.ignore();
				sucursal->setNumClasesGrups(nCG);
				break;
			case 11:
				cout << "Saliendo del menu de gestion." << endl;
				menu.mostrarMenu();
				break;
				default:
					cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
					continue;
			}

		} while (resp != 11);
	}
	else {
		cout << "Sucursal con codigo " << codigo << " no encontrada." << endl;
	}
}

Sucursal* Control::buscarSucursal(string codigo) {
	for (int i = 0; i < numSucursales_; ++i) {
		if (sucursales_[i] != nullptr && sucursales_[i]->getCod() == codigo) {
			int resp;
			cout << "Sucursal con codigo " << codigo << " encontrada." << endl;
			cout << "¿Desea gestionar esta sucursal? (1: Si, 2: No): ";
			cin >> resp;
			cin.ignore(); // Limpiar el buffer de entrada
			system("cls");
			if (resp == 1) {
				gestionarSucursal(codigo);
			} else {
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
