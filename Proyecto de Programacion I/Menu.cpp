#include "Menu.h"
#include <iostream>
#include <sstream>
using namespace std;

Menu::Menu() {
	control_ = new Control();
}
Menu::~Menu() {
	delete control_;
}
void Menu::mostrarMenu() {
	int resp;
		do {
			cout << "\n\n---Menu Principal---" << endl;
			cout << "\n\n1. Agregar Sucursal" << endl;
			cout << "\n\n2. Eliminar Sucursal" << endl;
			cout << "\n\n3. Listar Sucursales" << endl;
			cout << "\n\n4. Gestionar Sucursal" << endl;
			cout << "\n\n5. Cerrar programa" << endl<<endl;
			cout << "\n\nIngrese la opcion que desea realizar: ";
			
			cin >> resp;
			cin.ignore(); // Limpiar el buffer de entrada
			system("cls");
			switch (resp) {
			case 1:
				Menu::menuAgregarSucursal();
				break;
			case 2:
				Menu::menuEliminarSucursal();
				break;
			case 3:
				Menu::menuListarSucursales();
				break;
			case 4:
				//Menu::menuGestionarSucursal();
				break;
			case 5:
					cout << "Cerrando el programa. ¡Hasta luego!" << endl;
					return;

			} 
		}while (resp != 5);
}

void Menu::menuAgregarSucursal() {
	int tel = 0, capCli = 0, capIns = 0;
	string prov = "", cant = "", corr = "", cod = "";
	cout << "\n\n---Bienvenido, ingrese los siguientes datos para agregar la sucursal---\n\n" << endl;
	bool rep = true, codValido;
	int seguir=0;
	do { 
	do {
		codValido = true;
		cout << "Ingrese el codigo de la sucursal (Max 10 caracteres): ";
		getline(cin, cod);
		if (cod.length() > 10) {
			cout << "El codigo no puede tener mas de 10 caracteres" << endl;
			continue;
		}
		if (control_->buscarSucursal(cod)) {
			cout << "El codigo ya existe. Por favor, ingrese un codigo diferente." << endl;
			continue;
		}
		else {
			codValido = false;
		}
	} while (codValido != false);
	do {
		cout << "Ingrese el telefono de la sucursal (8 digitos): ";
		cin >> tel;
		cin.ignore();
	} while (tel < 10000000 || tel > 99999999);
	cout << "Ingrese la provincia de la sucursal: ";
	getline(cin, prov);

	cout << "Ingrese el canton de la sucursal: ";
	getline(cin, cant);

	cout << "Ingrese el correo electronico de la sucursal: ";
	getline(cin, corr);

	do {
		cout << "Ingrese la capacidad maxima de clientes de la sucursal: ";
		cin >> capCli;
		cin.ignore();
		if (capCli <= 0) {
			cout << "La capacidad debe ser un numero positivo. Por favor, intente de nuevo." << endl;
		}
	} while (capCli <= 0);
	do {
		cout << "Ingrese la capacidad maxima de instructores de la sucursal: ";
		cin >> capIns;
		cin.ignore();
		if (capIns <= 0) {
			cout << "La capacidad debe ser un numero positivo. Por favor, intente de nuevo." << endl;
		}
	} while (capIns <= 0);
	system("cls");
	control_->agregarSucursal(cod, tel, prov, cant, corr, capCli, capIns);
	cout << "Desea agregar otra sucursal? (1: Si, 2: No): ";
	cin >> seguir;
	cin.ignore();
	if (seguir == 2) {
		rep = false;
	}

}while (rep != false);
	cout<<endl<< "Presione Enter para volver al menu principal..." << endl;
	cin.ignore();
	system("cls");
}


void Menu::menuEliminarSucursal() {
	if (control_->getNumSucursales() == 0) {
		cout << "No hay sucursales registradas." << endl;
		cout << "Presione Enter para volver al menu principal..."<<endl;
		cin.ignore();	
		system("cls");
		Menu::mostrarMenu();
		return;
	}
	char res;
	bool codExis;
	do {
		string codigo;
		codExis = false;
		cout << "\n\n---Bienvenido, a continuacion se mostraran las sucursales existentes---\n\n" << endl;
		

		while (codExis == false) {
			control_->listarCodSucursales();
			cout << endl;
			cout << "Ingrese el codigo de la sucursal a eliminar: ";
			cin >> codigo;
			cin.ignore();
			if (!control_->buscarSucursal(codigo)) {
				system("cls");
				cout << "El codigo ingresado no existe. Por favor, vuelvalo a ingresar: ";
				cin.ignore();
				system("cls");
			}
			else {
				codExis = true;
			}

		}
	
		control_->eliminarSucursal(codigo);
		cout << "Sucursal " << codigo << " eliminada con exito." << endl;
		cout << "¿Desea eliminar otra sucursal? (S/N): ";
		cin >> res;
		cin.ignore();
		system("cls");
		if (control_->getNumSucursales() == 0) {
			cout << "No hay mas sucursales registradas.";
			cout << "Presione Enter para volver al menu principal..." << endl;
			cin.ignore();
			system("cls");
			break;
		}
	} while (res != 'N' && res != 'n');
	Menu::mostrarMenu();
	return;
}
void Menu::menuListarSucursales() {
	int resp;
	if (control_->getNumSucursales() == 0) {
		cout << "No hay sucursales registradas." << endl;
		cout << "Presione Enter para volver al menu principal..." << endl;
		cin.ignore();	
		system("cls");
		Menu::mostrarMenu();
		return;
	}
	control_->listarSucursales();
	cout << "Sucursales existentes listadas"<<endl;
	cout << "Presione Enter para volver al menu principal..."<<endl;
	cin.ignore();
	system("cls");
	Menu::mostrarMenu();
	return;
}