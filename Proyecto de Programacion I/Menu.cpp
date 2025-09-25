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

void Menu::quemados() {
	control_->agregarSucursal("SUC001", 12345678, "Provincia1", "Canton1", "pro1can1@gym.powerlab.com", 100, 20);
	control_->agregarSucursal("SUC002", 87654321, "Provincia2", "Canton2", "pro2can2@gym.powerlab.com", 150, 25);
	control_->agregarSucursal("SUC003", 38492017, "Provincia3", "Canton3", "pro3can3@gym.powerlab.com", 180, 35);
	control_->agregarSucursal("SUC004", 72615384, "Provincia4", "Canton4", "pro4can4@gym.powerlab.com", 50, 10);
	control_->agregarSucursal("SUC005", 50983741, "Provincia5", "Canton5", "pro5can5@gym.powerlab.com", 25, 5);
	control_->agregarSucursal("SUC006", 19274658, "Provincia6", "Canton6", "pro6can6@gym.powerlab.com", 200, 40);
	control_->agregarSucursal("SUC007", 84736291, "Provincia7", "Canton7", "pro7can7@gym.powerlab.com", 100, 20);
	control_->agregarSucursal("SUC008", 61349572, "Provincia8", "Canton8", "pro8can8@gym.powerlab.com", 100, 20);
	control_->agregarSucursal("SUC009", 27580439, "Provincia9", "Canton9", "pro9can9@gym.powerlab.com", 100, 20);
	control_->agregarSucursal("SUC010", 96823154, "Provincia10", "Canton10", "pro10can10@gym.powerlab.com", 150, 25);

	control_->quemados();
	system("cls");

}
void Menu::mostrarMenu() {
	int resp;
		do {
			cout << "\n\n---| Menu Principal |---" << endl;
			cout << "\n\n1. Agregar Sucursal" << endl;
			cout << "\n\n2. Eliminar Sucursal" << endl;
			cout << "\n\n3. Listar Sucursales" << endl;
			cout << "\n\n4. Gestionar Sucursal" << endl;
			cout << "\n\n5. Cerrar programa" << endl<<endl;
			cout << "\n\n---| Ingrese la opcion que desea realizar: ";
			
			cin >> resp;
			cin.clear();
			cin.ignore();
			system("cls");
			switch (resp) {
			case 1:
				this->menuAgregarSucursal();
				break;
			case 2:
				this->menuEliminarSucursal();
				break;
			case 3:
				this->menuListarSucursales();
				break;
			case 4:
				this->menuGestionarSucursal();
				break;
			case 5:
					cout << "---| Cerrando el programa. Hasta luego! |-" << endl;
					return;

			} 
		}while (resp != 5);
}

void Menu::menuAgregarSucursal() {
	int tel = 0, capCli = 0, capIns = 0;
	string prov = "", cant = "", corr = "", cod = "";
	cout << "\n\n---| Bienvenido, ingrese los siguientes datos para agregar la sucursal |---\n\n" << endl;
	bool rep = true, codValido;
	int seguir=0;
	do { 
	do {
		codValido = true;
		cout << "---| Ingrese el codigo de la sucursal (Max 10 caracteres): ";
		getline(cin, cod);
		if (cod.length() > 10) {
			cout << "---| El codigo no puede tener mas de 10 caracteres |-" << endl<<endl;
			cin.get();
			system("cls");
			continue;
		}
		if (control_->buscarSucursal(cod)) {
			cout << "---| El codigo ya existe. Por favor, ingrese un codigo diferente. |-" << endl<<endl;
			cin.get();
			system("cls");
			continue;
		}
		else {
			codValido = false;
		}
	} while (codValido != false);
	do {
		cout << "---| Ingrese el telefono de la sucursal (8 digitos): ";
		cin >> tel;
		cin.clear();
		cin.ignore();
	} while (tel < 10000000 || tel > 99999999);
	cout << "---| Ingrese la provincia de la sucursal: ";
	getline(cin, prov);

	cout << "---| Ingrese el canton de la sucursal: ";
	getline(cin, cant);

	cout << "---| Ingrese el correo electronico de la sucursal: ";
	getline(cin, corr);

	do {
		cout << "---| Ingrese la capacidad maxima de clientes de la sucursal: ";
		cin >> capCli;
		cin.clear();
		if (capCli <= 0) {
			cout << "---| La capacidad debe ser un numero positivo. Por favor, intente de nuevo. |-" << endl<<endl;
		}
	} while (capCli <= 0);
	do {
		cout << "---| Ingrese la capacidad maxima de instructores de la sucursal: ";
		cin >> capIns;
		cin.clear();
		if (capIns <= 0) {
			cout << "---| La capacidad debe ser un numero positivo. Por favor, intente de nuevo. |-" << endl<<endl;
		}
	} while (capIns <= 0);
	system("cls");
	control_->agregarSucursal(cod, tel, prov, cant, corr, capCli, capIns);
	cout << "-| Desea agregar otra sucursal? (1: Si, 2: No): ";
	cin >> seguir;
	cin.clear();
	system("cls");
	if (seguir == 2) {
		rep = false;
	}

}while (rep != false);
	cout<<endl<< "-| Presione Enter para volver al menu principal..." << endl;
	cin.ignore();
	system("cls");
}


void Menu::menuEliminarSucursal() {
	if (control_->getNumSucursales() == 0) {
		cout << "-| No hay sucursales registradas. |-" << endl;
		cout << "-| Presione Enter para volver al menu principal..."<<endl;
		cin.ignore();	
		system("cls");
		this->mostrarMenu();
		return;
	}
	char res;
	bool codExis;
	do {
		string codigo;
		codExis = false;
		cout << "\n\n---| Bienvenido, a continuacion se mostraran las sucursales existentes |---\n\n" << endl;
		

		while (codExis == false) {
			control_->listarCodSucursales();
			cout << endl;
			cout << "---| Ingrese el codigo de la sucursal a eliminar: ";
			getline(cin, codigo);
			if (!control_->buscarSucursal(codigo)) {
				system("cls");
				cout << "-| El codigo ingresado no existe. Por favor, vuelvalo a ingresar: ";
				cin.clear();
				system("cls");
			}
			else {
				codExis = true;
			}

		}
	
		control_->eliminarSucursal(codigo);
		cout << "---| Sucursal " << codigo << " eliminada con exito. |---" << endl;
		cout << "-| Desea eliminar otra sucursal? (S/N): ";
		cin >> res;
		cin.ignore();
		system("cls");
		if (control_->getNumSucursales() == 0) {
			cout << "-| No hay mas sucursales registradas. |-";
			cout << "-| Presione Enter para volver al menu principal..." << endl;
			cin.ignore();
			system("cls");
			break;
		}
	} while (res != 'N' && res != 'n');
	this->mostrarMenu();
	return;
}
void Menu::menuListarSucursales() {
	int resp;
	if (control_->getNumSucursales() == 0) {
		cout << "-| No hay sucursales registradas. |-" << endl<<endl;
		cout << "-| Presione Enter para volver al menu principal..." << endl;
		cin.ignore();
		cin.get();
		system("cls");
		this->mostrarMenu();
		return;
	}
	control_->listarSucursales();
	cout << "-| Sucursales existentes listadas |-"<<endl<<endl;
	cout << "-| Presione Enter para volver al menu principal..."<<endl;
	cin.get();
	system("cls");
	this->mostrarMenu();
	return;
}
void Menu::menuGestionarSucursal() {
	if (control_->getNumSucursales() == 0) {
		cout << "-| No hay sucursales registradas. |-" << endl << endl;
		cout << "-| Presione Enter para volver al menu principal..." << endl;
		cin.ignore();
		system("cls");
		this->mostrarMenu();
		return;
	}
	int resp = 0;
	do {
		resp = 0;
		string codigo;
		bool codExis = false;
		while (codExis == false) {
			cout << "\n\n---| Bienvenido, a continuacion se mostraran las sucursales existentes |---\n\n" << endl;
			control_->listarCodSucursales();
			cout << endl;
			cout << "---| Ingrese el codigo de la sucursal a gestionar (O ingrese salir para volver al menu): ";
			getline(cin, codigo);

			if(codigo=="salir"||codigo=="Salir"|| codigo == "SAlir" || codigo == "SALir" || codigo == "SALIr" || codigo == "SALIR"){
				system("cls");
				this->mostrarMenu();
				return;
			}
			if (!control_->buscarSucursal(codigo)) {
				system("cls");
				cout << "-| El codigo ingresado no existe. Por favor, aprete enter para volverlo a intentar. |-";
				cin.get();
				system("cls");
				continue;
			}
			else {
				codExis = true;
			}
		}
		control_->buscarSucurGesti(codigo);
		int fallo = 0;
		do {
			
			if (fallo == 1) {
				cout << "Respuesta invalida. Por favor, vuelvalo a intentar: ";
				cin.ignore();
				cin.get();
				system("cls");
				fallo = 0;
			}
			cout << "Desea gestionar la sucursal "<<codigo<<"?  (1: Si, 2 : No) : ";
			cin >> resp;
			if (resp != 1 && resp != 2) {
				fallo = 1;
				cin.ignore();
				cin.get();
				system("cls");
			}

		} while (resp != 1 && resp != 2);
	} while (resp == 1);
	cout << "Presione Enter para volver al menu principal..." << endl;
	cin.ignore();
	cin.get();
	system("cls");
	this->mostrarMenu();
}