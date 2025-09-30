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
	control_->agregarSucursal("SUC001", 12345678, "Provincia1", "Canton1", "pro1can1@gym.pl.com", 100, 20);
	control_->agregarSucursal("SUC002", 87654321, "Provincia2", "Canton2", "pro2can2@gym.pl.com", 150, 25);
	control_->agregarSucursal("SUC003", 38492017, "Provincia3", "Canton3", "pro3can3@gym.pl.com", 180, 35);
	control_->agregarSucursal("SUC004", 72615384, "Provincia4", "Canton4", "pro4can4@gym.pl.com", 50, 10);
	control_->agregarSucursal("SUC005", 50983741, "Provincia5", "Canton5", "pro5can5@gym.pl.com", 25, 5);
	control_->agregarSucursal("SUC006", 19274658, "Provincia6", "Canton6", "pro6can6@gym.pl.com", 200, 40);
	control_->agregarSucursal("SUC007", 84736291, "Provincia7", "Canton7", "pro7can7@gym.pl.com", 100, 20);
	control_->agregarSucursal("SUC008", 61349572, "Provincia8", "Canton8", "pro8can8@gym.pl.com", 100, 20);
	control_->agregarSucursal("SUC009", 27580439, "Provincia9", "Canton9", "pro9can9@gym.pl.com", 100, 20);
	control_->agregarSucursal("SUC010", 96823154, "Provincia10", "Canton10", "pro10can10@gym.pl.com", 150, 25);
	Quemados* ingre = new Quemados(control_);
	ingre->IngreDatosQuemados();

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
		cout << "\n\n5. Cerrar programa" << endl << endl;
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
			exit(0);
		default:
			system("cls");
			cout << "---| Codigo invalido, intentelo de nuevo|---" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

	} while (resp != 5);
}

void Menu::menuAgregarSucursal() {
	while (true) {
	int tel = 0, capCli = 0, capIns = 0;
	
	string prov = "", cant = "", corr = "", cod = "";
	cout << "\n\n---| Bienvenido, ingrese los siguientes datos para agregar la sucursal |---\n\n" << endl;
	int seguir=0;
	

		while (true) {
			cout << "---| Ingrese el codigo de la sucursal (Max 10 caracteres): ";
			getline(cin, cod);
			bool espa = false;
			for (int i = 0;i < cod.size();i++) {
				if (cod[i] == ' ') {
					cout << "---| El codigo no puede tener ningun espacio |---" << endl;
					espa = true;
					break;
				}
			}
			if (espa == true) {
				continue;
			}
			if (cod.empty()) {
				cout << "---| El codigo no puede estar vacio |---" << endl;
				continue;
			}
			else if (cod.length() > 10) {
				cout << "---| El codigo no puede tener mas de 10 caracteres |-" << endl;
				continue;
			}
			else if (control_->buscarSucursal(cod)) {
				cout << "---| El codigo ya existe. Por favor, ingrese un codigo diferente. |-" << endl;
				continue;
			}
			break;
		}
		while (true) {
			cout << "---| Ingrese el telefono de la sucursal (8 digitos): ";
			cin.ignore();
			tel = 0;
			cin >> tel;
			if (!cin.good()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "---| Debe ingresar un numero valido. |---" << endl;
				continue;
			}
			cin.ignore(10000, '\n');
			if (tel < 10000000 || tel > 99999999) {
				cout << "---| Debe ingresar un numero valido (8 digitos) |---" << endl;
				continue;
			}

			break;
		}
		while (true) {
			cout << "---| Ingrese la provincia de la sucursal: ";
			getline(cin, prov);
			int c = 0;
			if (prov.empty()) {
				cout << "---| La provincia no puede estar vacia |---" << endl;
				continue;
			}
			if (prov[0] == ' ') {
				cout << "---| La provincia no puede empezar con un espacio |---" << endl;
				continue;
			}
			else if (prov[prov.size() - 1] == ' ') {
				cout << "---| La provincia no puede terminar con un espacio |---" << endl;
				continue;
			}
			for (int i = 0; i < prov.size();i++) {
				if (prov[i] == ' ') {
					c++;
				}
			}
			if (c > 3) {
				cout << "La provincia no puede contener mas de 3 espacios" << endl;
				continue;
			}
			break;
		}
		while (true) {
			cout << "---| Ingrese el canton de la sucursal: ";
			getline(cin, cant);
			int c = 0;
			if (cant.empty()) {
				cout << "---| El canton no es valida |---" << endl;
				continue;
			}
			if (cant[0] == ' ') {
				cout << "---| El canton no puede empezar con un espacio |---" << endl;
				continue;
			}
			else if (cant[cant.size() - 1] == ' ') {
				cout << "---| El canton no puede terminar con un espacio |---" << endl;
				continue;
			}
			for (int i = 0; i < cant.size();i++) {
				if (cant[i] == ' ') {
					c++;
				}
			}
			if (c > 3) {
				cout << "---| El canton no puede contener mas de 3 espacios" << endl;
				continue;
			}
			break;
		}
		while (true) {
			cout << "---| Ingrese el correo electronico de la sucursal (ejemplo@gym.pl.com): ";
			getline(cin, corr);
			int com = corr.size() - 1;
			if (corr.empty()) {
				cout << "---| El correo no puede estar vacio |---" << endl;
				continue;
			}
			for (int i = 0;i < corr.size();i++) {
				if (corr[i] == ' ') {
					cout << "---| El correo no puede contener espacios |---" << endl;
					continue;
				}
			}
			;
			if (corr.find('@') == string::npos) {
				cout << "---| El correo debe contener '@' |---" << endl; //Si .find no encuentra el arroba, devuelve string::npos(asi lo aprendi jaja) por lo que igualarlo seria lo mejor
				continue;
			}
			if (corr.rfind("@gym.pl.com") != corr.size() - 11) {
				cout << "---| El correo debe terminar en @gym.pl.com |---" << endl; //.rfind empieza a buscar la posicion donde empieza lo que busca 
				//(en este caso @gym.pl.com el cual tiene 11 digitos, por lo que restarle los 11 digitos al tamannio total deberia dar el caracter inicial, ya que tambien
				//por otra parte el .size devuelve un numero del 1 al no se cuantos y el string que es un vector, empieza igual que cualquier vector en 0. :D
				continue;
			}
			break;
		}
		while (true) {
			cout << "---| Ingrese la capacidad maxima de clientes de la sucursal: ";
			cin >> capCli;
			cin.ignore();
			if (capCli <= 0) {
				cout << "---| La capacidad debe ser un numero positivo. Por favor, intente de nuevo. |-" << endl;
				cin.clear();
				continue;
			}
			break;
		}
		while (true) {
			cout << "---| Ingrese la capacidad maxima de instructores de la sucursal: ";
			cin >> capIns;
			cin.ignore();
			if (capIns <= 0) {
				cout << "---| La capacidad debe ser un numero positivo. Por favor, intente de nuevo. |-" << endl;
			cin.clear();
				continue;
			}
			break;
		}
		system("cls");
		control_->agregarSucursal(cod, tel, prov, cant, corr, capCli, capIns);
		cout << "---| La sucursal codigo " << cod << " ha sido correctamente creada |---" << endl;
		while (true) {

			cout << "---| Desea agregar otra sucursal? (1: Si, 2: No): ";
			cin >> seguir;
			cin.ignore();
			if (seguir != 1 && seguir != 2) {
				cout << "---| Invalido, presione enter e intente de nuevo |---" << endl;
				cin.clear();
				cin.get();
				system("cls");
				continue;
			}
			break;
		}
		cin.clear();
		system("cls");
		if (seguir == 2) {
			break;
		}
	}
	cout<<endl<< "-| Presione Enter para volver al menu principal..." << endl;
	cin.get();
	cin.ignore();
	system("cls");
}
void Menu::menuEliminarSucursal() {
	if (control_->getNumSucursales() == 0) {
		cout << "---| No hay sucursales registradas. |---" << endl;
		cout << "---| Presione Enter para volver al menu principal..." << endl;
		cin.ignore();
		system("cls");
		this->mostrarMenu();
		return;
	}

	char res;
	while (true) {
		string codigo;
		cout << "\n\n---| Bienvenido, a continuacion se mostraran las sucursales existentes |---\n\n" << endl;
		control_->listarCodSucursales();
		cout << endl;
		cout << "---| Ingrese el codigo de la sucursal a eliminar (O ingrese salir para regresar al menu principal): ";
		getline(cin, codigo);

		if (codigo == "salir" || codigo == "Salir" || codigo == "SALIR") {
			system("cls");
			return;
		}

		if (control_->buscarSucursal(codigo) == nullptr) {
			system("cls");
			cout << "---| El codigo ingresado no existe. Por favor, vuelvalo a ingresar |---" << endl;
			continue;
		}

		char confirm;
		bool eliminar = false;
		while (true) {
			cout << "\033[31m";
			cout << "\n\n---| Realmente desea eliminar la sucursal? (S/N): ";
			cout << "\033[0m";
			cin >> confirm;
			cin.ignore();

			if (confirm == 's' || confirm == 'S') {
				eliminar = true;
				break;
			}
			else if (confirm == 'n' || confirm == 'N') {
				system("cls");
				cout << "\n\n---| Operacion cancelada. Puede ingresar otro codigo. |---" << endl << endl;
				break;
			}
			else {
				cout << "---| Respuesta invalida, intentelo de nuevo |---" << endl;
			}
		}

		if (!eliminar) continue; 

		control_->eliminarSucursal(codigo);
		cout << "\n\n---| Sucursal " << codigo << " eliminada con exito. |---\n\n" << endl;

		while (true) {
			cout << "\n\n---| Desea eliminar otra sucursal? (S:si / N:no): ";
			cin >> res;
			cin.ignore();

			if (res == 's' || res == 'S') {
				system("cls");
				break; 
			}
			else if (res == 'n' || res == 'N') {
				system("cls");
				return;
			}
			else {
				cout << "---| Respuesta invalida, intentelo de nuevo |---" << endl;
			}
		}

		if (control_->getNumSucursales() == 0) {
			cout << "---| No hay mas sucursales registradas. |-" << endl;
			cout << "---| Presione Enter para volver al menu principal..." << endl;
			cin.ignore();
			system("cls");
			break;
		}
	}
}
void Menu::menuListarSucursales() {
	if (control_->getNumSucursales() == 0) {
		cout << "---| No hay sucursales registradas. |-" << endl << endl;
		cout << "---| Presione Enter para volver al menu principal..." << endl;
		cin.ignore();
		cin.get();
		system("cls");
		return;
	}
	control_->listarSucursales();
	cout << "---| Sucursales existentes listadas |-" << endl << endl;

	while (true) {
		char resp;
		cout << "---| Desea gestionar alguna sucursal? (S: si / N: no): ";cin >> resp;

		if (resp != 'N' && resp != 'n' && resp != 's' && resp != 'S') {
			cout << "---| Respuesta invalida, vuelvalo a intentar |---" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		if (resp == 'S' || resp == 's') {
			while (true) {
				cin.clear();
				cin.ignore(10000, '\n');
				this->menuGestionarSucursal();
				break;
			}

		
		}
		break;
	}

	cout << endl << "-| Presione Enter para volver al menu principal..." << endl;
	cin.get();
	system("cls");
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
	do {
		string codigo;
		bool codExis = false;

		while (codExis == false) {
			cout << "\n\n---| Bienvenido, a continuacion se mostraran las sucursales existentes |---\n\n" << endl;
			control_->listarCodSucursales();
			cout << endl;
			cout << "---| Ingrese el codigo de la sucursal a gestionar (Ingrese salir para volver al menu principal): ";
			getline(cin, codigo);

			if(codigo=="salir"||codigo=="Salir"|| codigo == "SAlir" || codigo == "SALir" || codigo == "SALIr" || codigo == "SALIR"){
				system("cls");
				this->mostrarMenu();
				return;
			}

			if (control_->buscarSucursal(codigo)==nullptr) {
				system("cls");
				cout << "---| El codigo ingresado no existe. Por favor, aprete enter para volverlo a intentar. |---";
				cin.get();
				system("cls");
				codExis = false;
				continue;
			}
			else {
				codExis = true;
			}
		}
		string entrada;
		while (true) {
			cout <<endl<< "---| Desea gestionar la sucursal " << codigo << "? (1: Si, 2: No): ";
			getline(cin, entrada);
			if (entrada == "1") { 
				system("cls");
				control_->buscarSucurGesti(codigo);
				system("cls");
				break; 
			}
			if (entrada == "2") { 
				system("cls"); 
				break; 
			}
			cout << "---| Respuesta invalida. Intente de nuevo. |---\n";
		}
	} while (true);
	cout << "---| Presione Enter para volver al menu principal...|---" << endl;
	cin.ignore();
	cin.get();
	system("cls");
	this->mostrarMenu();
}