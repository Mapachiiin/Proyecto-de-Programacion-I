#include "Control.h"
#include "Rutina.h"
#include "Ejercicios.h"
#include "Ejercicio.h"
#include <iostream>
#include <sstream>
using namespace std;

const static int annio = 2025;

Control::Control() {
	capSucursales_ = 30;
	sucursales_ = new Sucursal*[capSucursales_];
	for (int i = 0; i < capSucursales_;i++) {
		sucursales_[i] = nullptr;
	}
	numSucursales_ = 0;
	
}
Control::~Control() {
	for (int i = 0; i < capSucursales_&&sucursales_[i]!=nullptr; ++i) {
		delete sucursales_[i];
	}
	delete[] sucursales_;
	numSucursales_ = 0;
	capSucursales_ = 0;
}

//-------------------Sucursales-------------------

void Control::gestionarSucursal(string codigo) {
	Sucursal* sucursal = buscarSucursal(codigo);
	if (sucursal != nullptr) {
		int resp = 0;
		do {
			system("cls");
			cout << "Gestionando sucursal con codigo: " << codigo << endl;


			cout << "\n---| Menu de Gestion |---" << endl;
			cout << "\n1. Modificar codigo" << endl;
			cout << "\n2. Modificar correo electronico" << endl;
			cout << "\n3. Modificar telefono" << endl;
			cout << "\n4. Gestionar clientes" << endl;
			cout << "\n5. Gestionar instructores" << endl;
			cout << "\n6. Gestionar clases grupales" << endl;
			cout << "\n7. Salir del menu de gestion" << endl << endl;
			cout << "\n---| Ingrese la opcion que desea realizar: ";
			cin >> resp;
			cin.ignore(10000, '\n');
			system("cls");

			int tel = 0;
			string corr = "", codi = "";

			switch (resp) {
			case 1: {
				while (true) {
					cout << "---| Ingrese el codigo de la sucursal (Max 10 caracteres): ";
					getline(cin, codi);
					bool espa = false;
					for (int i = 0;i < codi.size();i++) {
						if (codi[i] == ' ') {
							cout << "---| El codigo no puede tener ningun espacio |---" << endl;
							espa = true;
							break;
						}
					}
					if (espa == true) {
						continue;
					}
					if (codi.empty()) {
						cout << "---| El codigo no puede estar vacio |---" << endl;
						continue;
					}
					else if (codi.length() > 10) {
						cout << "---| El codigo no puede tener mas de 10 caracteres |---" << endl;
						continue;
					}
					else if (this->buscarSucursal(codi)) {
						cout << "---| El codigo ya existe. Por favor, ingrese un codigo diferente. |-" << endl;
						continue;
					}
					break;
				}
				break;
			}
			case 2: {
				while (true) {
					cout << "---| Ingrese el correo electronico de la sucursal (ejemplo@gym.pl.com): ";
					getline(cin, corr);
					int com = corr.size() - 1;
					if (corr.empty()) {
						cout << "---| El correo no puede estar vacio |---" << endl;
						continue;
					}
					int c = 0;
					for (int i = 0;i < corr.size();i++) {
						if (corr[i] == ' ') {
							c++;
						}
					}
					if (c != 0) {
						cout << "---| El correo no puede contener espacios |---" << endl;
						continue;
					}
					if (corr.find('@') == string::npos) {
						cout << "---| El correo debe contener '@' |---" << endl;
						continue;
					}
					if (corr.rfind("@gym.pl.com") != corr.size() - 11) {
						cout << "---| El correo debe terminar en @gym.pl.com |---" << endl;
						continue;
					}
					break;
				}
				break;
			}
			case 3: {
				while (true) {
					cout << "---| Ingrese el telefono de la sucursal (8 digitos): ";
					tel = 0;
					if (!(cin >> tel)) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "---| Debe ingresar un numero valido. |---" << endl;
						continue;
					}
					cin.ignore(10000, '\n');
					if (tel < 10000000 || tel > 99999999) {
						cout << "---| Debe ingresar un numero valido (8 digitos) |---" << endl;
						cin.clear();
						cin.ignore(10000, '\n');	
						continue;
					}
					cin.ignore(10000, '\n');	
					break;
				}
				break;
			}
			case 4:
				this->menuGestionarClientes(sucursal);
				break;
			case 5:
				this->menuGestionarInstructores(sucursal);
				break;
			case 6:
				this->menuGestionarClasesGrupales(sucursal);
				break;
			case 7:
			{
				system("cls");
				cout << "---| Saliendo del menu de gestion. |---" << endl;
				break;
			}
			default:
			{
				cout << "---| Opcion no valida. Por favor, intente de nuevo. |---" << endl;
				cin.get();
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			}

		} while (resp != 7);
	}
	else {
		cout << "---| Sucursal con codigo " << codigo << " no encontrada. |---" << endl;
	}
}
void Control::agregarSucursal(string codi, int tel, string prov, string cant, string corr, int capCli, int capIns) {
	if(numSucursales_==30){
		cout << "---| No se pueden agregar mas sucursales, capacidad maxima alcanzada. |---" << endl;
		return;
	}

	for (int i = 0; i < capSucursales_; ++i) {
		if (sucursales_[i] == nullptr) {
			sucursales_[i] = new Sucursal(codi, tel, prov, cant, corr, capCli, capIns);
			numSucursales_++;
			return;
		}
	}
}
void Control::eliminarSucursal(string codigo) {
	for (int i = 0; i < numSucursales_; ++i) {
		if (sucursales_[i] != nullptr && sucursales_[i]->getCod() == codigo) {
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
				<< " | Provincia: " << sucursales_[i]->getProvi()
				<< " | Canton: " << sucursales_[i]->getCanton()
				<< " | Instructores: " << sucursales_[i]->getNumInstructores()
				<< " | Clientes: " << sucursales_[i]->getNumClientes() << " |-" << endl;
		}
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
			this->gestionarSucursal(codigo);
			system("cls");
		}
	}
	return nullptr;
}
void Control::menuGestionarEjercicios() {
	Ejercicios* catalogo = new Ejercicios;
	int opcion = 0;
	do {
		system("cls");
		cout << "---| Gestion del Catalogo de Ejercicios |---" << endl << endl;
		cout << "1. Ver ejercicios existentes" << endl;
		cout << "\n2. Agregar ejercicio" << endl;
		cout << "\n3. Eliminar ejercicio" << endl;
		cout << "\n4. Salir" << endl << endl;
		cout << "---| Ingrese una opcion: ";
		cin >> opcion;
		cin.ignore(10000, '\n');

		switch (opcion) {
		case 1: {
			bool salir = false;
			while (!salir) {
				system("cls");
				int cate;
				cout << "---| Menu de visualizacion de ejercicios existentes |---" << endl << endl;
				cout << "---| Seleccione una categoria |---" << endl << endl;
				cout << "1. Pecho y triceps" << endl;
				cout << "\n2. Biceps" << endl;
				cout << "\n3. Piernas" << endl;
				cout << "\n4. Espalda" << endl;
				cout << "\n5. Salir" << endl << endl;
				cout << "---| Ingrese una opcion: ";
				cin >> cate;
				cin.ignore(10000, '\n');
				system("cls");

				switch (cate) {
				case 1: {
					catalogo->listarPechoTric();
					system("pause");
					system("cls");
					continue;
				}
				case 2: {
					catalogo->listarBiceps();
					system("pause");
					system("cls");
					continue;
				}
				case 3: {
					catalogo->listarPiernas();
					system("pause");
					system("cls");
					continue;
				}
				case 4: {
					catalogo->listarEspalda();
					system("pause");
					system("cls");
					continue;
				}
				case 5: {
					salir = true;
					break;
				  }

				default: {
					cout << "---| Categoria invalida |---" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
				}
			}
			break;
		}
		case 2: {
			while (true) {
				system("cls");
				string nombre;
				int cate;
				cout << "---| Menu agregar ejercicios |---" << endl << endl;
				cout << "---| Seleccione una categoria |---" << endl << endl;
				cout << "1. Pecho y triceps" << endl;
				cout << "\n2. Biceps" << endl;
				cout << "\n3. Piernas" << endl;
				cout << "\n4. Espalda" << endl << endl;
				cout << "---| Ingrese una opcion: ";
				cin >> cate;
				cin.ignore(10000, '\n');
				system("cls");
				if(cate <1 || cate >4) {
					cout << "---| Categoria invalida |---" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
				while (true) {
					cout << "---| Ingrese el nombre del nuevo ejercicio: ";
					if (!(getline(cin, nombre))) {
						cout << "---| Error al ingresar el nombre. Intente de nuevo. |---" << endl;
						continue;
					}
					if (nombre.empty()) {
						cout << "---| El nombre no puede estar vacio. |---" << endl;
						continue;
					}
					if (nombre[0] == ' ') {
						cout << "---| El nombre no puede empezar con un espacio. |---" << endl;
						continue;
					}
					break;
				}

				switch (cate) {
				case 1: {
					catalogo->agregarPechoTric(nombre);
					break;
				}
				case 2: {
					catalogo->agregarBiceps(nombre);
					break;
				}
				case 3: {
					catalogo->agregarPiernas(nombre);
					break;
				}
				case 4: {
					catalogo->agregarEspalda(nombre);
					break;
				}
				default: {
					cout << "---| Categoria invalida |---" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
				}
				cout << "---| Ejercicio agregado con exito |---" << endl;;
				cin.get();
				system("cls");
				break;
			}
			break;
		}
		case 3: {
			bool salir = false;
			while (!salir) {
				system("cls");
				int cate, num;
				cout << "---| Menu de eliminacion de ejercicios |---" << endl << endl;
				cout << "---| Seleccione una categoria |---" << endl << endl;
				cout << "1. Pecho y triceps" << endl;
				cout << "\n2. Biceps" << endl;
				cout << "\n3. Piernas" << endl;
				cout << "\n4. Espalda" << endl;
				cout << "\n5. Salir" << endl << endl;
				cout << "---| Ingrese una opcion: ";
				cin >> cate;
				cin.ignore(10000, '\n');

				switch (cate) {
				case 1: {
					system("cls");
					if(catalogo->getNumPechoTric()==0) {
							cout << "---| No hay ejercicios en esta categoria. |---" << endl;
							system("pause");
							system("cls");
							break;
						}
					while (true) {
						
						catalogo->listarPechoTric();
						cout << "---| Ingrese numero a eliminar: ";
						if (!(cin >> num)) {
							cout << "---| Debe ingresar un numero valido. |---" << endl;
							cin.clear();
							cin.ignore(10000, '\n');
							continue;
						}
						if (num<1 || num>catalogo->getNumPechoTric()) {
							cout << "---| Numero invalido. Intente de nuevo. |---" << endl;
							cin.clear();
							cin.ignore(10000, '\n');
							continue;
						}
						catalogo->eliPechoTric(num - 1);
						cout << "\n---| Ejercicio eliminado |---\n";
						system("pause");
						system("cls");
						break;
					}
					break;
				}
				case 2: {
					if(catalogo->getNumBiceps()==0) {
							cout << "---| No hay ejercicios en esta categoria. |---" << endl;
							system("pause");
							system("cls");
							break;
					}
					while (true) {
						catalogo->listarBiceps();
						cout << "---| Ingrese numero a eliminar: ";
						if (!(cin >> num)) {
							cout << "---| Debe ingresar un numero valido. |---" << endl;
							cin.clear();
							cin.ignore(10000, '\n');
							continue;
						}
						if (num<1 || num>catalogo->getNumBiceps()) {
							cout << "---| Numero invalido. Intente de nuevo. |---" << endl;
							cin.clear();
							cin.ignore(10000, '\n');
							continue;
						}
						catalogo->eliBiceps(num - 1);
						cout << "\n---| Ejercicio eliminado |---\n";
						system("pause");
						system("cls");
						break;
					}
					break;
				}
				case 3: {
					if(catalogo->getNumPiernas()==0) {
							cout << "---| No hay ejercicios en esta categoria. |---" << endl;
							system("pause");
							system("cls");
							break;
					}
					while (true) {
						catalogo->listarPiernas();
						cout << "---| Ingrese numero a eliminar: ";
						if (!(cin >> num)) {
							cout << "---| Debe ingresar un numero valido. |---" << endl;
							cin.clear();
							cin.ignore(10000, '\n');
							continue;
						}
						if (num<1 || num>catalogo->getNumPiernas()) {
							cout << "---| Numero invalido. Intente de nuevo. |---" << endl;
							cin.clear();
							cin.ignore(10000, '\n');
							continue;
						}
						catalogo->eliPiernas(num - 1);
						cout << "\n---| Ejercicio eliminado |---\n";
						system("pause");
						system("cls");
						break;
					}
					break;
				}
				case 4: {
					if(catalogo->getNumEspalda()==0) {
							cout << "---| No hay ejercicios en esta categoria. |---" << endl;
							system("pause");
							system("cls");
							break;
					}
					while (true) {
						catalogo->listarEspalda();
						cout << "---| Ingrese numero a eliminar: ";
						if (!(cin >> num)) {
							cout << "---| Debe ingresar un numero valido. |---" << endl;
							cin.clear();
							cin.ignore(10000, '\n');
							continue;
						}
						if (num<1 || num>catalogo->getNumEspalda()) {
							cout << "---| Numero invalido. Intente de nuevo. |---" << endl;
							cin.clear();
							cin.ignore(10000, '\n');
							continue;
						}
						catalogo->eliEspalda(num - 1);
						cout << "\n---| Ejercicio eliminado |---\n";
						system("pause");
						system("cls");
						break;
					}
					break;
				}
				case 5: {
					salir = true;
					break;
				}
				default: {
					cout << "---| Categoria invalida |---" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					break;
				}
				}
			}
			break;
		}
		case 4:
			delete catalogo;
			catalogo = nullptr;
			system("cls");
			return;
		default:
			cout << "---| Como llegaste aqui? Opcion invalida. Intente de nuevo. |---" << endl;
			break;
		}
	} while (opcion != 4);
}

//-------------------Clientes-------------------

void Control::menuGestionarClientes(Sucursal* sucu) {
	int resp = 0;
	do {
		cout << "---| Menu de gestion de clientes de la sucursal " << sucu->getCod() << " |---\n" << endl;
		cout << "1. Clasificacion de clientes por IMC" << endl;
		cout << "\n2. Listar clientes " << endl;
		cout << "\n3. Agregar cliente" << endl;
		cout << "\n4. Gestionar cliente" << endl;
		cout << "\n5. Eliminar cliente" << endl;
		cout << "\n6. Salir" << endl << endl;
		cout << "\n---| Ingrese la opcion que desea realizar: ";
		cin >> resp;
		cin.clear();
		cin.ignore();
		system("cls");

		switch (resp) {
		case 1:{
			sucu->listarClientesPorIMC();
			system("cls");
			break;
		}
		case 2:
		{
			cout << "---| Listado de clientes |---" << endl << endl;
			sucu->listarClientes();

			cout << "\n---| Presione enter para salir. |---" << endl;
			cin.get();
			system("cls");
			break;
		}
		case 3:
		{
			this->agregarCliente(sucu);
			system("cls");
			break;
		}
		case 4:
		{
			this->gestionarCliente(sucu);
			system("cls");
			break;
		}
		case 5:
		{
			this->eliminarCliente(sucu);
			system("cls");
			break;
		}
		case 6:
		{
			cin.clear();
			cin.ignore(10000, 'n');
			return;
		}
		default:
		{
			cout << "---| Opcion no valida. Por favor, intente de nuevo. |---" << endl;
			cin.get();
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		}
	} while (resp != 6);
}
void Control::agregarCliente(Sucursal* sucu) {
	int telf, ced;
	string nom, fN, fI, corr;
	char sexo;
	while (true) {
		cout << "---| Agregar cliente |--- " << endl << endl;

		if (sucu->getNumInstructores() == 0) {
			cout << "-| No hay instructores disponibles en la sucursal. Por lo que no se puede agregar ningun cliente. |-" << endl;
			return;
		}

		while (true) {
			cout << "---| Ingrese el nombre del cliente: ";
			if (!(getline(cin, nom))) {
				cout << "---| Nombre invalido, intente de nuevo |---" << endl;
				continue;
			}
			if (nom.empty()) { //he descubierto mas cosas de codigo con este proyecto que otra vara jaja
				cout << "---| El nombre no puede estar vacio. |---" << endl;
				continue;
			}
			if (nom[0] == ' ') {
				cout << "---| El nombre no puede empezar con un espacio. |---" << endl;
				continue;
			}
			break;
		}
		while (true) {
			cout << "---| Ingrese la cedula del cliente: ";
			if (!(cin>>ced)) {
				cout << "---| Debe ingresar un numero valido. |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			if (ced<=0) {
				cout << "---| La cedula no puede ser 0 o ser negativa |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			if (sucu->buscarCliente(ced) != nullptr) {
				cout << "---| Esta cedula ya existe en la sucursal |---" << endl;
				continue;
			}
			cin.ignore(10000, '\n');
			break;
		}
		while (true) {
			cout << "---| Ingrese el telefono del cliente: ";

			if (!(cin >> telf)) {
				cout << endl << "---| Debe ingresar un numero valido. |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			} 
			if (telf < 10000000 || telf > 99999999) {
				cout << endl << "---| Debe ingresar un numero de 8 digitos. |---" << endl;
				continue;
			}
			cin.ignore(10000, '\n');
			break;
		}
		while (true) {
			cout << "---| Ingrese el correo electronico del cliente: ";
			getline(cin, corr);
			if (corr.find('@') == string::npos) {
				cout << "---| El correo no es valido. |---" << endl;
				continue;
			}
			int c = 0;
			for (int i = 0;i < corr.size();i++) {
				if (corr[i] == ' ') {
					c++;

				}
			}
			if (c != 0) {
				cout << "---| El correo no puede contener espacios |---" << endl;
				continue;
			}
			if (corr.size()<4 || corr.rfind(".com") != corr.size() - 4) {
				cout << "---| El correo debe terminar en .com |---" << endl;
				continue;
			}
			break;
		}
		while (true) {
			cout << "---| Ingrese la fecha de nacimiento del cliente (Dia/Mes/Annio): ";
			getline(cin, fN);
			if (this->esFechaValida(fN)) {
				break;
			}
			else {
				cout << "---| Fecha no valida. |---" << endl;
				continue;
			}

		}
		while (true) {
			cout << "---| Ingrese el sexo del cliente (M: Masculino / F: Femenino): ";
			if (!(cin >> sexo)) {
				cout << "---| Debe ingresar M o F |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			if (sexo == 'm' || sexo == 'M' || sexo == 'f' || sexo == 'F') {
				cin.ignore(10000, '\n');
				break;
			}
			cout << "---| Debe ingresar M o F |---" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		while (true) {
			cout << "---| Ingrese la fecha de inscripcion del cliente (Dia/Mes/Annio): ";
			getline(cin, fI);
			if (this->esFechaValida(fI)) {
				break;
			}
			cout << "---| Fecha no valida. |---" << endl;
		}
		while(true) {
			cout << endl << "---| Que instructor desea asignarle al cliente? |---" << endl << endl;
			sucu->listarInstructores();
			cout << endl;
			int cedulaIns;
			cout << endl << "---| Ingrese la cedula del instructor que se le asignara al cliente: ";
			if (!(cin >> cedulaIns)) {
				cout << "---| Debe ingresar un numero valido. |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				system("cls");
				continue;
			}
			Instructor* iA = sucu->buscarInstructor(cedulaIns);
			if (iA != nullptr) {
				Cliente* nuevoCliente = new Cliente(nom, ced, telf, corr, fN, sexo, fI, 0, iA);
				sucu->agregarCliente(nuevoCliente);
				break;
			}
				cout << "---| Instructor no encontrado. Por favor intente de nuevo. |---" << endl;
		}

		cout << "Cliente agregado con exito." << endl << endl;

		int repiteInt=0;
		while (true) {
			
			cout << "---| Desea agregar otro cliente? (1: Si, 2: No): ";
			if (cin >> repiteInt) {
				if (repiteInt == 1) {
					system("cls");
					break;
				}
				else if (repiteInt == 2) {
					system("cls");
					break;
				}
				else {
					cout << "-| Opcion invalida. Por favor, intente de nuevo. |-" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
		}
		if (repiteInt == 1) {
			system("cls");
			break;
		}
		else if (repiteInt == 2) {
			system("cls");
			break;
		}
	}
}
void Control::eliminarCliente(Sucursal* sucu) {
	if (sucu->getNumClientes() == 0) {
		cout << "-| No hay clientes registrados. |-" << endl << endl;
		cout << "-| Presione Enter para volver al menu principal..." << endl;
		cin.ignore();
		system("cls");
		return;
	}
	char res;
	bool codExis;
	do {
		string codigo;
		res = 'j';
		codExis = false;
		int ced=0;
		while (codExis == false) {
			cout << "\n\n---| Bienvenido, a continuacion se mostraran los clientes existentes |---\n\n" << endl;
			sucu->listarClientes();
			cout << endl;
			cout << "---| Ingrese la cedula del cliente a eliminar (Ingrese salir para volver al menu anterior): ";
			getline(cin, codigo);

			if (codigo == "salir" || codigo == "Salir" || codigo == "SAlir" || codigo == "SALir" || codigo == "SALIr" || codigo == "SALIR") {
				system("cls");
				return;
			}
			else {
				try {
					ced = stoi(codigo);
				}
				catch (invalid_argument&) {
					system("cls");
					cout << "---| La cedula ingresada debe ser totalmente numerica. Intente de nuevo. |---" << endl;
					codExis = false;
					continue;
				}
				catch (out_of_range& e) {
					system("cls");
					cout << "---| La cedula ingresada es demasiado larga. Intente de nuevo. |---" << endl;
					codExis = false;
					continue;
				}

			}
			if (sucu->buscarCliente(ced) == nullptr) {
				system("cls");
				cout << "---| La cedula ingresada no existe. Por favor, aprete enter para volverlo a intentar. |---";
				cin.get();
				system("cls");
				codExis = false;
				continue;
			}
			else  {
				codExis = true;
			} 
		cout << "\033[31m";
		cout << "\n\n---| Realmente desea eliminar al cliente " << sucu->buscarCliente(ced)->getNombre() << "? (S / N) : ";
		cout << "\033[0m";
		cin >> res;
		cin.ignore(10000, '\n');

		if (res == 's' || res == 'S') {
			cout << "\n\n---| cliente " << sucu->buscarCliente(ced)->getNombre() << " eliminado con exito. |---\n\n" << endl;
			sucu->eliminarCliente(ced);
		}
		else {
			system("cls");
			cout << "\n\n---| Operacion cancelada. Puede ingresar otra cedula. |---" << endl;
		}
	}

	do{
	cout << "\n\n---| Desea eliminar otro cliente? (S/N): ";
	cin >> res;
	cin.ignore();
	system("cls");
	if (sucu->getNumClientes() == 0) {
		cout << "-| No hay mas clientes registrados. |-";
		cout << "-| Presione Enter para volver al menu principal..." << endl;
		cin.ignore();
		system("cls");
		return;
	}
	} while (res != 'N' && res != 'n' && res != 'S' && res != 's');
} while (res != 'N' && res != 'n');
return;

}
void Control::gestionarCliente(Sucursal* sucu) {
	if (sucu->getNumClientes() == 0) {
		cout << "-| No hay clientes registrados. |-" << endl << endl;
		cout << "-| Presione Enter para volver al menu principal..." << endl;
		cin.get();
		system("cls");
		return;
	}

	do {
		string codigo;
		int ced = 0;
		bool codExis = false;

		while (codExis == false) {
			cout << "\n\n---| Bienvenido, a continuacion se mostraran los clientes existentes |---\n\n" << endl;
			sucu->listarClientes();
			cout << endl;
			cout << "---| Ingrese la cedula del cliente a gestionar (Ingrese salir para volver al menu anterior): ";
			getline(cin, codigo);

			if (codigo == "salir" || codigo == "Salir" || codigo == "SAlir" || codigo == "SALir" || codigo == "SALIr" || codigo == "SALIR") {
				system("cls");
				return;
			}
			else {
				try {
					ced = stoi(codigo);  //omg, profe, esto lo comento, porque esto nunca se dice que se puede hacer, esta loquisimo----https://www.youtube.com/watch?v=7ApAEaqyOOk
				}
				catch (invalid_argument&) {
					system("cls");
					cout << "---| La cedula ingresada debe ser totalmente numerica. Intente de nuevo. |---" << endl;
					codExis = false;
					continue;
				}
				catch (out_of_range&) {
					system("cls");
					cout << "---| La cedula ingresada es demasiado larga. Intente de nuevo. |---" << endl;
					codExis = false;
					continue;
				}

			}

			if (sucu->buscarCliente(ced) == nullptr) {
				system("cls");
				cout << "---| La cedula ingresada no existe. Por favor, aprete enter para volverlo a intentar. |---";
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
			cout << endl << "---| Desea gestionar al cliente " << sucu->buscarCliente(ced)->getNombre() << "? (1: Si, 2: No): ";
			getline(cin, entrada);
			if (entrada == "1") {
				system("cls");
				this->gestionarClienteSi(sucu, ced);
				system("cls");
				cout << "---| Presione Enter para volver al menu de gestion...|---" << endl;
				cin.ignore();
				cin.get();
				system("cls");
				return;
			}
			if (entrada == "2") {
				system("cls");
				continue;
			}
			cout << "---| Respuesta invalida. Intente de nuevo. |---\n";
	} while (true);
}
void Control::gestionarClienteSi(Sucursal* sucu, int ced) {
	Cliente* cliente = sucu->buscarCliente(ced);
	if (cliente == nullptr) return;

	int opcion;
	do {
		cout << "---| Gestion del/la cliente: " << cliente->getNombre() << " |---" << endl;
		cout << "\n1. Ver detalles" << endl;
		cout << "\n2. Gestionar mediciones" << endl;
		cout << "\n3. Gestionar rutinas" << endl;
		cout << "\n4. Gestionar clases grupales" << endl;
		cout << "\n5. Salir" << endl << endl;
		cout << "\n---| Ingrese la opcion: " << endl;
		cin >> opcion;
		cin.ignore(10000, '\n');
		system("cls");

		switch (opcion) {
		case 1:
			cout << cliente->toString();
			cout << "---| Ingrese enter para salir |---" << endl;
			cin.get();
			system("cls");
			break;
		case 2:
			this->menuGestionarMediciones(cliente);
			break;
		case 3:
			this->menuGestionarRutinas(cliente, sucu);
			break;
		case 4:
			this->menuGestionarCliClasesGrupales(cliente, sucu);
			break;
		case 5:
			return;
		default:
			cout << "---| Opcion invalida. |---" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	} while (opcion != 5);
}
void Control::menuGestionarMediciones(Cliente* cli) {
	int opcion = 0;
	do {
		cout << "---| Gestion de Mediciones del cliente: " << cli->getNombre() << " |---\n\n" << endl;
		cout << "\n1. Agregar medicion" << endl;
		cout << "\n2. Historial de mediciones" << endl;
		cout << "\n3. Salir" << endl << endl;
		cout << "\n---| Ingrese la opcion: " << endl;
		cin >> opcion;
		cin.ignore(10000, '\n');
		system("cls");
		string fecha;

		switch (opcion) {

		case 1: {
			bool resp;
			while (true) {

				resp = false;
				double peso, estatura, grasa, musculo, grasaVisc, cintura, cadera, pecho, muslo;
				bool hE = false;
				int edadMet;

				while (true) {
					cout << "---| Ingrese la fecha de la medicion (Dia/Mes/Annio): ";
					getline(cin, fecha);
					if (esFechaValida(fecha)) {
						break;
					}
					else {
						cout << "---| Fecha invalida. |---" << endl << endl;
						continue;
					}

				}
				while (true) {
					cout << "---| Ingrese el peso (kg): ";
					if (!(cin >> peso) || peso <= 0) {
						cout << "---| Peso invalido. |---" << endl << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}
					else {
						
						cin.ignore(10000, '\n');
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la estatura (m): ";
					if (!(cin >> estatura) || estatura <= 0) {
						cout << "---| Estatura invalida. |---" << endl << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}
					else {
						cin.ignore(10000, '\n');
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese el porcentaje de grasa corporal (%): ";
					if (!(cin >> grasa) || grasa < 0) {
						cout << "---| Porcentaje de grasa corporal invalido. |---" << endl << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}
					else {
						cin.ignore(10000, '\n');
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese el porcentaje de musculo (%): ";
					if (!(cin >> musculo) || musculo < 0) {
						cout << "---| Porcentaje de musculo invalido. |---" << endl << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}
					else {
						cin.ignore(10000, '\n');
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la edad metabolica: ";
					if (!(cin >> edadMet) || edadMet < 0) {
						cout << "---| Edad metabolica invalida. |---" << endl << endl;
						cin.clear();
						cin.ignore(10000, '\n');

					}
					else {
						cin.ignore(10000, '\n');
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la grasa visceral (%): ";
					if (!(cin >> grasaVisc) || grasaVisc < 0) {
						cout << "---| Porcentaje de grasa visceral invalido. |---" << endl << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}
					else {
						cin.ignore(10000, '\n');
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la medida de cintura (cm): ";
					if (!(cin >> cintura) || cintura < 0) {
						cout << "---| Medida de la cintura invalida. |---" << endl << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}
					else {
						cin.ignore(10000, '\n');
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la medida de cadera (cm): ";
					if (!(cin >> cadera) || cadera < 0) {
						cout << "---| Medida de la cadera invalida. |---" << endl << endl;
						cin.clear();
						cin.ignore(10000, '\n');

					}
					else {
						cin.ignore(10000, '\n');
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la medida de pecho (cm): ";
					if (!(cin >> pecho) || pecho < 0) {
						cout << "---| Medida del pecho invalida. |---" << endl << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}
					else {
						cin.ignore(10000, '\n');
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la medida de muslo (cm): ";
					if (!(cin >> muslo) || muslo < 0) {
						cout << "---| Medida del muslo invalida. |---" << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}
					else {
						cin.ignore(10000, '\n');
						break;
					}
				}
				while (true) {
					cout << "---| El cliente hace ejercicio regularmente? (S: si / N: no): ";
					char he;
					if (!(cin >> he) && (he != 's' && he != 'S' && he != 'n' && he != 'N')) {
						cout << "---| Respuesta invalida. |---" << endl << endl;
						cin.clear();
						cin.ignore(10000, '\n');
						continue;
					}
					else {
						if (he == 's' || he == 'S') {
							hE = true;
						}
						else {
							hE = false;
						}
						cin.ignore(10000, '\n');
						break;
					}
				}

				ReporteMedicion rep(*cli, fecha, peso, estatura, grasa, musculo, edadMet, grasaVisc, cintura, cadera, pecho, muslo, hE);
				cli->agregarReporte(rep);

				cout << "---| Medicion agregada con exito. |---" << endl;
				char siono;
				while (true) {
					cout << "---| Desea agregar otra medicion? (S:si /N:no): ";cin >> siono;
					if (siono != 'n' && siono != 'N' && siono != 's' && siono != 'S') {
						cout << "---| Opcion invalida |---" << endl;
						cin.clear();
						cin.ignore(10000, '\n');
						system("cls");
						continue;
					}
					cin.ignore(10000, '\n');
					break;
				}
				if (siono == 'n' || siono == 'N') {
					break;
				}

			}
			cout << "---| Presione enter para salir. |---" << endl;
			cin.get();
			break;
		}
		case 2: {
			if (cli->getNumReportes() == 0) {
				cout << "---| No hay mediciones para mostrar. |---" << endl;
				cout << "---| Presione enter para continuar. |---" << endl;
				cin.get();
				system("cls");
				break;
			}
			cli->listarReportes();
			int num;
			while (true) {
				cout << "---| Desea ver el detalle de alguna medicion? (Ingrese salir para volver al menu): ";
				string nu;
				if (!(getline(cin, nu))) {
					cout << "---| Respuesta invalida, intentelo de nuevo |---" << endl;
					continue;
				}
				if (nu == "salir" || nu == "Salir" || nu == "SAlir" || nu == "SALir" || nu == "SALIr" || nu == "SALIR") {
					return;
				} 
				if(nu.empty()) {
					cout << "---| Respuesta invalida, intentelo de nuevo |---" << endl;
					continue;
				}
				if (nu[0] == ' ') {
					cout << "---| Respuesta invalida, intentelo de nuevo |---" << endl;
					continue;
				} try {
					num = stoi(nu);
				}
				catch(invalid_argument&){
					cout << "---| Solo se permiten numeros, intentelo de nuevo |---" << endl;
					continue;
				}
				catch (out_of_range&) {
					cout << "---| Demasiado largo, intentelo de nuevo |---" << endl;
					continue;
				}
				break;
			}

			if (num > 0 && num <= cli->getNumReportes()) {
				ReporteMedicion* rep = cli->getReportePorIndice(num - 1);
				cout << "---| Detalles de la medicion #" << num << " |---" << endl;
				cout << rep->toString() << endl;
				cout << "---| Presione enter para continuar. |---" << endl;
				cin.get();
			} else if (num != 0) {
				cout << "---| Numero fuera de rango. |---" << endl;
				cout << "---| Presione enter para continuar. |---" << endl;
				cin.get();
			}
			system("cls");
			break;
		}
		case 3:
		{
			cin.ignore(10000, '\n');
			return;
		}
		default:
		{
			cout << "---| Opcion invalida. |---" << endl;
			cin.ignore(10000, '\n');
		}
		}
	} while (opcion != 3);
}
void Control::menuGestionarRutinas(Cliente* cli, Sucursal* sucu) {
	Ejercicios* catalogo = new Ejercicios();
	int opcion = 0;
	do {
		system("cls");
		cout << "---| Gestion de Rutinas del cliente " << cli->getNombre() << " |---" << endl << endl;
		cout << "\n1. Crear nueva rutina" << endl;
		cout << "\n2. Ver rutina actual" << endl;
		cout << "\n3. Salir" << endl << endl;
		cout << "---| Ingrese la opcion: ";
		cin >> opcion;
		cin.ignore(10000, '\n');

		switch (opcion) {
		case 1: {
			string descripcion;
			int duracion, nEjercicios;

			cout << "---| Ingrese la descripcion de la rutina: ";
			getline(cin, descripcion);

			cout << "---| Ingrese la duracion total de la rutina (minutos): ";
			while (!(cin >> duracion) || duracion <= 0) {
				cout << "---| Duracion no valida. |---\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Ingrese nuevamente: ";
			}
			cin.ignore(10000, '\n');

			cout << "---| Ingrese el numero maximo de ejercicios de la rutina: ";
			while (!(cin >> nEjercicios) || nEjercicios <= 0) {
				cout << "---| Numero invalido. |---\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Ingrese nuevamente: ";
			}
			cin.ignore(10000, '\n');

			Rutina* nuevaRutina = new Rutina(cli, descripcion, duracion, nEjercicios);
			cli->asignarRutina(nuevaRutina);

			int resp = 0;
			do {
				system("cls");
				cout << "---| Tipos de ejercicios |---" << endl << endl;
				cout << "1. Pecho y triceps" << endl;
				cout << "\n2. Biceps" << endl;
				cout << "\n3. Piernas" << endl;
				cout << "\n4. Espalda" << endl;
				cout << "\n5. Terminar" << endl << endl;
				cout << "---| Ingrese que tipo de ejercicio desea agregar: ";
				cin >> resp;
				cin.ignore(10000, '\n');

				int esco;
				string nombre;

				switch (resp) {
				case 1: {
					while (true) {
						system("cls");
						cout << "---| Ejercicios de pecho y triceps |---\n";
						catalogo->listarPechoTric();
						cout << "Seleccione numero: ";
						if (!(cin >> esco)) {
							cout << "---| Opcion invalida |---\n";
							cin.clear();
							cin.ignore(10000, '\n');
							system("cls");
							continue;
						}
						if (esco < 1 || esco > catalogo->getNumPechoTric()) {
							cout << "---| Opcion invalida |---\n";
							cin.clear();
							cin.ignore(10000, '\n');
							system("cls");
							continue;
						}
						cin.ignore(10000, '\n');
						nombre = catalogo->getPechoTric(esco - 1);
						break;
					}
					break;
				}
				case 2: {
					while (true) {
						system("cls");
						cout << "---| Ejercicios de biceps |---\n";
						catalogo->listarBiceps();
						cout << "Seleccione numero: ";
						if (!(cin >> esco)) {
							cout << "---| Opcion invalida |---\n";
							cin.clear();
							cin.ignore(10000, '\n');
							system("cls");
							continue;
						}
						if (esco < 1 || esco > catalogo->getNumBiceps()) {
							cout << "---| Opcion invalida |---\n";
							cin.clear();
							cin.ignore(10000, '\n');
							system("cls");
							continue;
						}
						cin.ignore(10000, '\n');
						nombre = catalogo->getBiceps(esco - 1);
						break;
					}
					break;
				}
				case 3: {
					while (true) {
						system("cls");
						cout << "---| Ejercicios de pierna |---\n";
						catalogo->listarPiernas();
						cout << "Seleccione numero: ";
						if (!(cin >> esco)) {
							cout << "---| Opcion invalida |---\n";
							cin.clear();
							cin.ignore(10000, '\n');
							system("cls");
							continue;
						}
						if (esco < 1 || esco > catalogo->getNumPiernas()) {
							cout << "---| Opcion invalida |---\n";
							cin.clear();
							cin.ignore(10000, '\n');
							system("cls");
							continue;
						}
						cin.ignore(10000, '\n');
						nombre = catalogo->getPiernas(esco - 1);
						break;
					}
					break;
				}
				case 4: {
					while (true) {
						system("cls");
						cout << "---| Ejercicios de espalda |---\n";
						catalogo->listarEspalda();
						cout << "Seleccione numero: ";
						if (!(cin >> esco)) {
							cout << "---| Opcion invalida |---\n";
							cin.clear();
							cin.ignore(10000, '\n');
							system("cls");
							continue;
						}
						if (esco < 1 || esco > catalogo->getNumEspalda()) {
							cout << "---| Opcion invalida |---\n";
							cin.clear();
							cin.ignore(10000, '\n');
							system("cls");
							continue;
						}
						cin.ignore(10000, '\n');
						nombre = catalogo->getEspalda(esco - 1);
						break;
					}
					break;
				}
				case 5:
					break;
				default: {
					cout << "---| Opcion invalida |---\n";
					cin.ignore(10000, '\n');
					continue;
				}
				}

				if (!nombre.empty()) {
					Ejercicio* nuevo = new Ejercicio(nombre);
					nuevaRutina->agregarEjercicio(nuevo);
					cout << "---| Se agrego: " << nombre << " |---\n";
					system("pause");
				}

			} while (resp != 5);

			cout << "---| Rutina creada con exito. |---\n";
			system("pause");
			break;
		}
		case 2: {
			if (cli->getRutina() == nullptr) {
				system("cls");
				cout << "---| El cliente no tiene rutina asignada. |---" << endl << endl;
				system("pause");
			}
			else {
				cout << cli->getRutina()->toString();
				cout << endl << "---| Presione enter para salir |---" << endl;
				cin.get();
				cin.ignore(10000, '\n');

			}
			system("cls");
			break;
		}
		case 3:
			delete catalogo;
			catalogo = nullptr;
			system("cls");
			return;
		default:
			cout << "---| Opcion invalida. |---\n";
			cin.clear();
			cin.ignore(10000, '\n');
			system("cls");
		}
	} while (opcion != 3);
}
void Control::menuGestionarCliClasesGrupales(Cliente* cli, Sucursal* sucu) {
	if (cli == nullptr) {
		cout << "--| Cliente no valido. |---" << endl;
		return;
	}
	int opcion;
	do {
		system("cls");
		cout << "---| Gestion de Clases Grupales del cliente " << cli->getNombre() << " |---" << endl << endl;
		cout << "\n1. Ver clases grupales inscritas" << endl;
		cout << "\n2. Inscribir a clase grupal" << endl;
		cout << "\n3. Eliminar inscripcion de clase grupal" << endl;
		cout << "\n4. Salir" << endl << endl;
		cout << "\n---| Ingrese la opcion: ";
		
		cin >> opcion;
		cin.ignore(10000, '\n');
		system("cls");

		switch (opcion) {
		case 1:
		{
			system("cls");

			if (cli->getInscritos() == 0) {
				cout << "---| No hay clases grupales inscritas. |---" << endl << endl;
				cout << "---| Presione enter para salir |---" << endl;
				cin.get();
				break;
			}

			cout << "---| Clases inscritas por " << cli->getNombre() << " |---" << endl;
			cout << "\n|------------------------------------|" << endl;

			for (int j = 0; j < sucu->getNumClasesGrups(); j++) {
				ClaseGrupal* clase = sucu->getClaseGrupalPorIndice(j);
				if (clase->getClienteCed(cli->getCed())!=nullptr) {
					Cliente* cliente = sucu->buscarCliente(cli->getCed());
					if (cliente && cliente->getCed() == cli->getCed()) {
						cout << "Clase #" << clase->getCodClase() << endl;
						cout << "Especialidad: " << clase->getEspecialidad() << endl;
						cout << "Horario: " << clase->getHorario() << endl;
						cout << "Sucursal: " << sucu->getCod() << endl;
						if (clase->getInstructor())
							cout << "Instructor: " << clase->getInstructor()->getNombre() << endl << endl;
						cout << "|------------------------------------|" << endl;
						break;
					}
				}
			}
			cout << endl << "---| Presione enter para salir |---" << endl;
			cin.get();
			break;
		}
		case 2:
		{
			do {
				system("cls");
				int inscritos = cli->getInscritos();

				if (sucu->getNumClasesGrups() == 0) {
					cout << "---| No hay clases grupales disponibles en esta sucursal. |---" << endl;
					break;
				}
				if (inscritos >= 3) {
					cout << "---| El cliente ya esta inscrito en el maximo de clases grupales permitidas (3). |---" << endl;
					break;
				}
				cout << "---| Inscripcion de clases grupales |---" << endl << endl;
				cout << "---| Clases grupales disponibles: " << endl;
				sucu->listarClasesGrupales();
				while (true) {
					cout << "\n---| Ingrese el codigo de la clase a la que desea inscribir al cliente (O ingrese salir para volver al menu): ";
					string entrada = "";
					getline(cin, entrada);
					if (entrada == "salir" || entrada == "Salir" || entrada == "SAlir" || entrada == "SALir" || entrada == "SALIr" || entrada == "SALIR") {
						system("cls");
						break;
					}
					int codClase;
					try {
						codClase = stoi(entrada);
					}
					catch (invalid_argument&) {
						system("cls");
						cout << "---| El codigo ingresado debe ser totalmente numerico. Intente de nuevo. |---" << endl;
						cin.get();
						cin.ignore(10000, '\n');
						continue;
					}
					catch (out_of_range&) {
						system("cls");
						cout << "---| El codigo ingresado es demasiado largo. Intente de nuevo. |---" << endl;
						cin.get();
						cin.ignore(10000, '\n');
						continue;
					}
					ClaseGrupal* clase = sucu->buscarClaseGrupal(codClase);
					if (clase == nullptr) {
						system("cls");
						cout << "---| Clase no encontrada. Intente de nuevo. |---" << endl;
						cin.get();
						cin.ignore(10000, '\n');
						continue;
					}
					if (clase->getOcupados() >= clase->getCupoMax()) {
						system("cls");
						cout << "---| La clase ya esta llena. Intente con otra clase. |---" << endl;
						cin.get();
						cin.ignore(10000, '\n');
						continue;
					}
					if (clase->getClienteCed(cli->getCed()) != nullptr) {
						system("cls");
						cout << "---| El cliente ya esta inscrito en esta clase. |---" << endl;
						cin.get();
						cin.ignore(10000, '\n');
						continue;
					}
					clase->insCliente(cli);
					cout << "---| Cliente inscrito con exito. |---" << endl;
					break;

				}

				cout << endl << "---| Presione enter para salir |---" << endl;
				cin.get();
				system("cls");
				break;

			} while (true);
			break;
		}
		case 3:
		{
			system("cls");
			if (cli->getInscritos() == 0) {
				cout << "---| No hay clases grupales inscritas. |---" << endl << endl;
				cout << "---| Presione enter para salir |---" << endl;
				cin.get();
				break;
			}
			cout << "---| Eliminar inscripcion de clases grupales |---" << endl << endl;
			cout << "---| Clases grupales inscritas: " << endl;
			sucu->listarClasesGrupalesCliente(cli);
			while (true) {
				cout << "\n---| Ingrese el codigo de la clase de la que desea eliminar la inscripcion (O ingrese salir para volver al menu): ";
				string entrada = "";
				getline(cin, entrada);
				if (entrada == "salir" || entrada == "Salir" || entrada == "SAlir" || entrada == "SALir" || entrada == "SALIr" || entrada == "SALIR") {
					system("cls");
					break;
				}
				int codClase;
				try {
					codClase = stoi(entrada);
				}
				catch (invalid_argument&) {
					system("cls");
					cout << "---| El codigo ingresado debe ser totalmente numerico. Intente de nuevo. |---" << endl;
					cin.get();
					cin.ignore(10000, '\n');
					continue;
				}
				catch (out_of_range&) {
					system("cls");
					cout << "---| El codigo ingresado es demasiado largo. Intente de nuevo. |---" << endl;
					cin.get();
					cin.ignore(10000, '\n');
					continue;
				}
				ClaseGrupal* clase = sucu->buscarClaseGrupal(codClase);
				if (clase == nullptr) {
					system("cls");
					cout << "---| Clase no encontrada. Intente de nuevo. |---" << endl;
					cin.get();
					cin.ignore(10000, '\n');
					continue;
				}
				if (clase->getClienteCed(cli->getCed()) == nullptr) {
					system("cls");
					cout << "---| El cliente no esta inscrito en esta clase. |---" << endl;
					cin.get();
					cin.ignore(10000, '\n');
					continue;
				}
				clase->eliminarCliente(cli->getCed());
				cout << "---| Inscripcion eliminada con exito. |---" << endl;
				break;
			}

			cout << endl << "---| Presione enter para salir |---" << endl;
			cin.get();
			break;
		}
		case 4:
			return;

		default:
			cout << "---| Opcion invalida. |---\n";
			cin.ignore(10000, '\n');
			system("cls");
		}
	} while (opcion != 4);
}

//-------------------Instructores-------------------

void Control::menuGestionarInstructores(Sucursal* sucu) {
	int resp;
	do{
	cout << "---| Menu de gestion de instructores de la sucursal " << sucu->getCod() << " |---\n" << endl;
	cout << "\n1. Listar instructores " << endl;
	cout << "\n2. Agregar instructor" << endl;
	cout << "\n3. Gestionar instructor" << endl;
	cout << "\n4. Eliminar instructor" << endl;
	cout << "\n5. Salir" << endl << endl;
	cout << "\n---| Ingrese la opcion que desea realizar: ";
	cin >> resp;
	cin.ignore(10000, '\n');
	system("cls");

	switch (resp) {
	case 1:
	{
		if (sucu->getNumInstructores() == 0) {
			cout << "---| No hay instructores en esta sucursal |---" << endl<<endl;
			cout << "\n\n---| Presione enter para salir. |---" << endl;
			cin.get();
			system("cls");
			break;
		}
		cout << "---| Listado de instructores |--- " << endl << endl;
		sucu->listarInstructores();

		cout << "\n\n---| Presione enter para salir. |---" << endl;
		cin.get();
		system("cls");
		break;
	}
	case 2:
	{
		this->agregarInstructor(sucu);
		break;
	}
	case 3:
	{
		this->gestionarInstructor(sucu);
		break;
}
	case 4:
	{
		this->eliminarInstructor(sucu);
		break;
}
	case 5:{
		system("cls");
		return;
	}
	default:
	{
		cout << "---| Opcion invalida. |---" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		break;
	}
	}
	}while(resp != 5);
}
void Control::agregarInstructor(Sucursal* sucu) {
	bool repite2 = true;
	int ced, telf;
	string nom, fN, fI, corr;
	while (repite2) {
		cout << "---| Agregar instructor: " << endl << endl;

		while(true){
		cout << "---| Ingrese el nombre del instructor: ";
		if(!(getline(cin, nom))){
			cout << "---| Nombre invalido. Intentelo de nuevo. |---" << endl;
			continue;
		}
		if (nom.empty()) {
			cout << "---| El nombre no puede estar vacio. |---" << endl;
			continue;
		}
		if(nom[0] == ' '){
			cout << "---| El nombre no puede iniciar con espacio. |---" << endl;
			continue;
		}

		break;
}
		while (true) {
			cout << "---| Ingrese la cedula del instructor: ";
			if (!(cin >> ced)) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "---| Debe ingresar un numero valido. |---" << endl;
				continue;
			}
			cin.ignore(10000, '\n');
			break;
		}
		while (true) {
			cout << "---| Ingrese el telefono del instructor (8 digitos): ";
			telf = 0;
			if (!(cin >> telf)) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "---| Debe ingresar un numero valido. |---" << endl;
				continue;
			}
			else if (telf < 10000000 || telf > 99999999) {
				cout << "---| Debe ingresar un numero valido (8 digitos) |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			cin.ignore(10000, '\n');
			break;
		}
		while (true) {
			int c = 0;
			cout << "---| Ingrese el correo electronico del instructor (ejemplo@gmail.com): ";
			getline(cin, corr);
			if (corr.empty()) {
				cout << "---| El correo no puede estar vacio |---" << endl;
				continue;
			}
			for (int i = 0;i < corr.size();i++) {
				if (corr[i] == ' ') {
					c++;

				}
			}
			if (c != 0) {
				cout << "---| El correo no puede contener espacios |---" << endl;
				continue;
			}
			if (corr.find('@') == string::npos) {
				cout << "---| El correo debe contener '@' |---" << endl; 
				continue;
			}
			if (corr.rfind(".com") != corr.size() - 4) {
				cout << "---| El correo debe terminar en .com |---" << endl;
				continue;
			}
			break;
		}
		while (true) {
			cout << "---| Ingrese la fecha de nacimiento del instructor (Dia/Mes/Annio): ";
			getline(cin, fN);
			if (this->esFechaValida(fN)) {
				break;
			}
			else {
				cout << "---| Fecha no valida. |---" << endl;
				continue;
			}

		}
		while (true) {
			cout << "---| Ingrese la fecha de contrato del instructor (Dia/Mes/Annio): ";
			getline(cin, fI);
			if (this->esFechaValida(fI)) {
				break;
			}
			else {
				cout << "---| Fecha no valida. |---" << endl;
				continue;
			}

		}
		int especialidadPrincipal = 0;
		while (true) {
			cout << "---| Ingrese la especialidad principal del instructor: |---" << endl;
			cout << "1. CrossFit" << endl;
			cout << "2. HIIT" << endl;
			cout << "3. TRX" << endl;
			cout << "4. Pesas" << endl;
			cout << "5. Spinning" << endl;
			cout << "6. Cardio" << endl;
			cout << "7. Yoga" << endl;
			cout << "8. Zumba" << endl;
			cout << "---| Ingrese el numero de la especialidad: ";
			cin >> especialidadPrincipal;
			cin.clear();
			cin.ignore(10000, '\n');
			if (especialidadPrincipal >= 1 && especialidadPrincipal <= 8) {
				break;
			}
			else {
				cout << "---| Opcion invalida. |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}

		Instructor* nuevoInstructor = new Instructor(ced, nom, telf, corr, fN, especialidadPrincipal);
		sucu->agregarInstructor(nuevoInstructor);

		while (true) {
			cout << "---| Desea agregar otra especialidad? (1: Si, 2: No): ";
			int otra;
			if (cin >> otra && (otra == 1 || otra == 2)) {
				cin.ignore(10000, '\n');
				if (otra == 2) break;

				int opcionEsp = 0;
				cout << "---| Ingrese la especialidad adicional del instructor: |---" << endl;
				cout << "1. CrossFit" << endl;
				cout << "2. HIIT" << endl;
				cout << "3. TRX" << endl;
				cout << "4. Pesas" << endl;
				cout << "5. Spinning" << endl;
				cout << "6. Cardio" << endl;
				cout << "7. Yoga" << endl;
				cout << "8. Zumba" << endl;
				cout << "---| Ingrese el numero de la especialidad: ";
				if (cin >> opcionEsp && opcionEsp >= 1 && opcionEsp <= 8) {
					nuevoInstructor->agregarEspecialidadS(opcionEsp);
				}
				else {
					cout << "---| Opcion invalida. |---" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
			else {
				cout << "---| Opcion invalida. |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
		cout << "---| Instructor agregado con exito." << endl << endl;

		while (true) {
			int sigueInt;
			cout << "---| Desea agregar otro instructor? (1: Si, 2: No): ";
			if (cin >> sigueInt) {
				if (sigueInt == 1) {
					system("cls");
					repite2 = true;
					break;
				}
				else if (sigueInt == 2) {
					system("cls");
					repite2 = false;
					break;
				}
				else {
					cout << "---| Opcion invalida. Por favor, intente de nuevo. |---" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
		}
	}
}
void Control::gestionarInstructor(Sucursal* sucu) {
	if (sucu->getNumInstructores() == 0) {
		cout << "---| No hay instructores registrados. |---" << endl << endl;
		system("pause");
		system("cls");
		return;
	}
	do {
		string codigo;
		int ced = 0;
		bool codExis = false;

		while (codExis == false) {
			cout << "\n\n---| Bienvenido, a continuacion se mostraran los instructores existentes |---\n\n" << endl;
			sucu->listarInstructores();
			cout << endl;
			cout << "---| Ingrese la cedula del instructor a gestionar (Ingrese salir para volver al menu anterior): ";

			if(!(getline(cin, codigo))){
				cout << "---| Respuesta invalida. Intente de nuevo. |---" << endl;
				continue;
			}
			if (codigo == "salir" || codigo == "Salir" || codigo == "SALIR") {
				system("cls");
				return;
			}
			else {
				try {
					ced = stoi(codigo);
				}
				catch (invalid_argument&) {
					system("cls");
					cout << "---| La cedula ingresada debe ser totalmente numerica. Intente de nuevo. |---" << endl;
					codExis = false;
					continue;
				}
				catch (out_of_range&) {
					system("cls");
					cout << "---| La cedula ingresada es demasiado larga. Intente de nuevo. |---" << endl;
					codExis = false;
					continue;
				}
			}

			if (sucu->buscarInstructor(ced) == nullptr) {
				system("cls");
				cout << "---| La cedula ingresada no existe. Por favor, presione enter para volverlo a intentar. |---";
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
			cout << endl << "---| Desea gestionar al instructor "<< sucu->buscarInstructor(ced)->getNombre()<< "? (1: Si, 2: No): ";
			if(!(getline(cin, entrada))){
				cout << "---| Respuesta invalida. Intente de nuevo. |---\n";
				continue;
			}

			if (entrada == "1") {
				system("cls");
				this->gestionarInstructorSi(sucu, ced);
				system("cls");
				return;
			}
			if (entrada == "2") {
				system("cls");
				return;
			}
			cout << "---| Respuesta invalida. Intente de nuevo. |---\n";
		}
	} while (true);
}
void Control::gestionarInstructorSi(Sucursal* sucu, int ced) {
	Instructor* instructor = sucu->buscarInstructor(ced);
	if (instructor == nullptr) return;

	int opcion;
	do {
		system("cls");
		cout << "---| Gestion del/la instructor(a) " << instructor->getNombre() << " |---" << endl<<endl;
		cout << "1. Ver detalles del instructor" << endl;
		cout << "\n2. Listar clientes vinculados" << endl;
		cout << "\n3. Gestionar clientes vinculados" << endl;
		cout << "\n4. Salir" << endl << endl;
		cout << "---| Ingrese la opcion: ";
		cin >> opcion;
		cin.ignore(10000, '\n');
		system("cls");

		switch (opcion) {
		case 1:
			cout << instructor->toString();
			cout << "---| Presione enter para salir |---" << endl;
			cin.get();
			break;

		case 2:
			sucu->listarClientesDeInstructor(instructor);
			cout << "---| Presione enter para salir |---" << endl;
			cin.get();
			break;

		case 3:
			this->menuGestionarCliInst(instructor, sucu);
			break;

		case 4:

			return;

		default:
			cout << "---| Opcion invalida. |---" << endl;
		}
	} while (opcion != 4);
}
void Control::menuGestionarCliInst(Instructor* ins, Sucursal* sucu) {
	if (sucu->getNumClientes() == 0) {
		cout << "---| No hay clientes registrados en esta sucursal. |---" << endl << endl;
		cout << "---| Presione Enter para volver al menu de gestion |---" << endl;
		cin.ignore();
		system("cls");
		return;
	}
	while (true) {
		system("cls");
		cout << "\n\n---| Clientes vinculados al instructor |---" << ins->getNombre() << " |---\n\n";
		sucu->listarClientesDeInstructor(ins);

		cout << endl;
		cout << "---| Ingrese la cedula del cliente a gestionar (O ingrese salir para volver): ";
		string entrada;
		getline(cin, entrada);

		if (entrada == "salir" || entrada == "Salir" || entrada == "SAlir" || entrada == "SALir" || entrada == "SALIr" || entrada == "SALIR") {
			system("cls");
			return;
		}
		int ced = 0;
		try {
			ced = stoi(entrada);
		}
		catch (invalid_argument&) {
			cout << "---| La cedula debe ser numerica. Por favor, intente de nuevo. |---" << endl;
			cin.get();
			continue;
		}
		catch (out_of_range&) {
			cout << "---| La cedula ingresada es demasiado larga. |---" << endl;
			cin.get();
			continue;
		}
		Cliente* cli = sucu->buscarCliente(ced);
		if (cli == nullptr) {
			cout << "---| No existe un cliente con esa cedula en la sucursal. |---" << endl;
			cin.get();
			continue;
		}
		if (cli->getInstructor() != ins) {
			cout << "---| Ese cliente no esta vinculado a este instructor. |---" << endl;
			cin.get();
			continue;
		}
		system("cls");
		this->gestionarClienteSi(sucu, ced);
	}
}
void Control::eliminarInstructor(Sucursal* sucu) {
	if (sucu->getNumInstructores() == 0) {
		cout << "---| No hay instructores registrados. |---" << endl << endl;
		cout << "---| Presione Enter para volver al menu principal |---" << endl;
		cin.get();
		system("cls");
		return;
	}

	char res;
	do {
		string codigo;
		int ced = 0;
		bool cedulaValida = false;
		bool confirmado = false;
		while (!cedulaValida) {
			system("cls");
			cout << "\n\n---| Bienvenido, a continuacion se mostraran los instructores existentes |---\n\n";
			sucu->listarInstructores();
			cout << endl;
			cout << "---| Ingrese la cedula del instructor a eliminar (O ingrese salir para volver): ";
			if(!(getline(cin, codigo))){
				cout << "---| Respuesta invalida. Intente de nuevo. |---" << endl;
				continue;
			}
			if (codigo == "salir" || codigo == "SALIR" || codigo == "Salir"||codigo=="SAlir"||codigo=="SALir"||codigo=="SALIr") {
				system("cls");
				return;
			}
			try {
				ced = stoi(codigo);
			}
			catch (invalid_argument&) {
				cout << "---| La cedula ingresada debe ser numerica. Intentelo de nuevo. |---" << endl;
				continue;
			}
			catch (out_of_range&) {
				cout << "---| La cedula ingresada es demasiado larga. Intentelo de nuevo. |---" << endl;
				continue;
			}
			if (sucu->buscarInstructor(ced) == nullptr) {
				cout << "---| La cedula ingresada no existe. |---" << endl;
				continue;
			}
			do {
				cout << "\033[31m";
				cout << "\n\n---| Realmente desea eliminar al instructor " << sucu->buscarInstructor(ced)->getNombre() << "? (S/N): ";
				cout << "\033[0m";
				cin >> res;
				cin.ignore(10000, '\n');
			} while (res != 'S' && res != 's' && res != 'N' && res != 'n');

			if (res == 'S' || res == 's') {
				confirmado = true;
			}
			else {
				cout << "\n\n---| Operacion cancelada. Puede ingresar otra cedula. |---" << endl;
			}
			cedulaValida = true;
		}
		if (confirmado) {
			cout << "\n\n---| Instructor " << sucu->buscarInstructor(ced)->getNombre()<< " eliminado con exito. |---\n\n";
			sucu->eliminarInstructor(ced);
		}

		if (sucu->getNumInstructores() == 0) {
			cout << "---| No hay mas instructores registrados. |---" << endl;
			cout << "---| Presione Enter para volver al menu principal |---" << endl;
			cin.get();
			system("cls");
			return;
		}

		do {
			cout << "\n\n---| Desea eliminar otro instructor? (S/N): ";
			if(!(cin >> res)) {
				cout << "---| Respuesta invalida. Intente de nuevo. |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		} while (res != 'S' && res != 's' && res != 'N' && res != 'n');

	} while (res == 'S' || res == 's');
}

//-------------------Clases Grupales-------------------

void Control::menuGestionarClasesGrupales(Sucursal* sucu) {
		int resp = 0;
		do {
			system("cls");
			cout << "---| Menu de gestion de clases grupales de la sucursal " << sucu->getCod() << " |---\n" << endl;
			cout << "1. Listar clases grupales" << endl;
			cout << "2. Agregar clase grupal" << endl;
			cout << "3. Gestionar clase grupal" << endl;
			cout << "4. Eliminar clase grupal" << endl;
			cout << "5. Salir" << endl << endl;
			cout << "---| Ingrese la opcion que desea realizar: ";
			cin >> resp;
			cin.ignore(10000, '\n');
			system("cls");

			switch (resp) {
			case 1: {
				cout << "---| Listado de clases grupales |--- " << endl << endl;
				sucu->listarClasesGrupales();
				cout << "\n\n---| Presione enter para salir. |---" << endl;
				cin.get();
				break;
			}
			case 2: {
				this->agregarClaseGrupal(sucu);
				break;
			}
			case 3: {
				this->gestionarClaseGrupalSi(sucu);
				break;
			}
			case 4: {
				this->eliminarClaseGrupal(sucu);
				break;
			}
			case 5: {
				system("cls");
				return;
			}
			default:
				cout << "---| Opcion invalida. Intente de nuevo. |---" << endl;
				break;
			}
		} while (resp != 5);
	}
void Control::agregarClaseGrupal(Sucursal* sucu) {
	bool repetir = true;
	while (repetir) {
		cout << "---| Agregar clase grupal |--- " << endl << endl;

		if (sucu->getNumInstructores() == 0) {
			cout << "---| No hay instructores disponibles en la sucursal. No se puede crear la clase. |---" << endl;
			return;
		}
		int codigoClase, cupoMax, espeResp;
		string horario;
		while (true) {
			cout << "---| Ingrese el codigo de la clase grupal: ";
			if (!(cin >> codigoClase)) {
				cout << "---| Debe ingresar un numero valido. |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			cin.ignore(10000, '\n');
			if (sucu->buscarClaseGrupal(codigoClase) != nullptr) {
				cout << "---| El codigo de la clase ya existe, intente de nuevo. |---" << endl;
				continue;
			}
			break;
		} 
		while (true) {
			cout << "---| Ingrese el numero de cupos maximos: ";
			if (!(cin >> cupoMax) || cupoMax <= 0) {
				cout << "---| Debe ingresar un numero valido mayor a 0. |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			cin.ignore(10000, '\n');
			break;
		}
		while (true) {
			cout << "\n---| Especialidades |---" << endl;
			cout << "\n1. CrossFit" << endl;
				cout << "\n2. HIIT" << endl;
				cout << "\n3. TRX" << endl;
				cout << "\n4. Spinning" << endl;
				cout << "\n5. Pesas" << endl;
				cout << "\n6. Cardio" << endl;
				cout << "\n7. Yoga" << endl;
				cout << "\n8. Zumba" << endl << endl;
			cout << "---| Ingrese el numero de la especialidad: ";
			if (!(cin >> espeResp) || espeResp < 1 || espeResp > 8) {
				cout << "---| Opcion invalida. Intente de nuevo. |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			cin.ignore(10000, '\n');
			break;
		} 
		while(true){
		cout << "---| Ingrese la hora de la clase (XX:XXam o XX:XXpm): ";
		getline(cin, horario);
		if(this->esHoraValida(horario)) break;
}
		Instructor* instructorAsignado = nullptr;
		while (true) {
			sucu->listarInstructores();
			string cedulaStr;
			int cedulaIns;

			cout << "---| Ingrese la cedula del instructor (O ingrese 'salir' para cancelar): ";
			getline(cin, cedulaStr);

			if (cedulaStr == "salir" || cedulaStr == "Salir" || cedulaStr == "SAlir" || cedulaStr == "SALir" || cedulaStr == "SALIr" || cedulaStr == "SALIR") {
				return;
			}
			try {
				cedulaIns = stoi(cedulaStr);
			}
			catch (invalid_argument&) {
				cout << "---| La cedula solo puede contener numeros |---" << endl;
				continue;
			}
			catch (out_of_range&) {
				cout << "---| La cedula es demasiado larga |---" << endl;
				continue;
			}
			instructorAsignado = sucu->buscarInstructor(cedulaIns);
			if (instructorAsignado == nullptr) {
				cout << "---| Instructor no encontrado. Intente de nuevo |---" << endl;
				continue;
			}
			if (!instructorAsignado->tieneEspecialidadInt(espeResp)) {
				cout << "---| El instructor no domina la especialidad seleccionada |---" << endl;
				continue;
			}
			break;
		}
		ClaseGrupal* nuevaClase = new ClaseGrupal(codigoClase, 0, cupoMax, sucu, instructorAsignado, horario, espeResp);
		sucu->agregarClaseGrupal(nuevaClase);
		cout << "---| Clase grupal agregada con exito. |---" << endl;
		int opcion;
		while (true) {
			cout << "---| Desea agregar otra clase grupal? (1: Si, 2: No): ";
			if (!(cin >> opcion)) {
				cout << "---| Debe ingresar un numero valido. |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			cin.ignore(10000, '\n');
			if (opcion == 1) {
				system("cls");
				repetir = true;
				break;
			}
			else if (opcion == 2) {
				system("cls");
				repetir = false;
				break;
			}
			else {
				cout << "---| Opcion invalida. Intente de nuevo. |---" << endl;
			}
		}
	}
}
void Control::gestionarClaseGrupalSi(Sucursal* sucu) {
	if (sucu->getNumClasesGrups() == 0) {
		cout << "---| No hay clases grupales registradas en la sucursal. |---" << endl;
		cout << "\n---| Presione enter para salir. |---" << endl;
		cin.get();
		system("cls");
		return;
	}

	int codigoClase;
	while (true) {
		system("cls");
		cout << "---| Gestionar clases grupales |---" << endl;
		sucu->listarClasesGrupales();
			cout << "\n---| Ingrese el codigo de la clase grupal a gestionar: ";
			if (!(cin >> codigoClase) || sucu->buscarClaseGrupal(codigoClase) == nullptr) {
				cout << "\n---| El codigo ingresado es invalido, intentelo de nuevo |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
		ClaseGrupal* clase = sucu->buscarClaseGrupal(codigoClase);
		if (clase == nullptr) {
			cout << "---| Clase grupal no encontrada. Intente de nuevo |---" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			system("cls");
			continue;
		}

	int opcion = 0;
	do {
		cout << "\n---| Gestion de la clase grupal " << clase->getCodClase() << " |---" << endl;
		cout << "\n1. Ver informacion de la clase" << endl;
		cout << "\n2. Agregar cliente" << endl;
		cout << "\n3. Cambiar especialidad" << endl;
		cout << "\n4. Cambiar hora" << endl;
		cout << "\n5. Cambiar instructor asignado" << endl;
		cout << "\n6. Volver al menu anterior" << endl;
		cout << "\n---| Ingrese la opcion: "; cin >> opcion;
		cin.ignore(10000, '\n');
		system("cls");

		switch (opcion) {
		case 1: {
			cout << "---| Informacion de la clase grupal |---" << endl;
			cout << clase->toString();
			cout << "\n---| Presione enter para continuar. |---" << endl;
			cin.get();
			system("cls");
			break;
		}
		case 2: {
			if (sucu->getNumClientes() == 0) {
				cout << "---| No hay clientes disponibles en la sucursal. |---" << endl;
				break;
			}
			while (true) {
				sucu->listarClientes();
				string cedula;
				int cedCli;
				cout << "Ingrese la cedula del cliente a agregar (O ingrese salir para volver al menu): ";
				if (!(getline(cin, cedula))) {
					cout << "---| Respuesta invalida. Intente de nuevo. |---" << endl;
					continue;
				}
				if (cedula == "salir" || cedula == "Salir" || cedula == "SAlir" || cedula == "SALir" || cedula == "SALIr" || cedula == "SALIR") {
					break;
				}
				else if (cedula.empty()) {
					cout << "---| La cedula no puede estar vacia |---" << endl;
					continue;
				}
				else if (cedula[0] == ' ') {
					cout << "---| La cedula no puede empezar con un espacio |---" << endl;
					continue;
				}
				else {
					try {
						cedCli = stoi(cedula);
					}
					catch (invalid_argument&) {
						cout << "---| La cedula solo puede contener numeros |---" << endl;
						continue;
					}
					catch (out_of_range&) {
						cout << "---| La cedula no puede ser tan larga |---" << endl;
						continue;
					}
				}
				Cliente* nuevoCliente = sucu->buscarCliente(cedCli);
				if (nuevoCliente != nullptr) {
					clase->insCliente(nuevoCliente);
					cout << "---| Cliente agregado con exito. |---" << endl;
				}
				else {
					cout << "---| Cliente no encontrado. Intentelo de nuevo|---" << endl;
					continue;
				}
				char resp;
				while (true) {

					cout << "---| Desea agregar otro cliente a la clase grupal? (S:si/N:no): ";cin >> resp;
					if (resp != 's' && resp != 'S' && resp != 'n' && resp != 'N') {
						cout << "---| Respuesta invalida, intentelo de nuevo |---" << endl;
						continue;
					}
					break;
				}
				if (resp == 's' || resp == 'S') {
					system("cls");
					continue;
				}
				break;
			}
			break;
		}
		case 3: {
			int espeResp;
			do {
				cout << "---| Ingrese la especialidad de la clase grupal |---" << endl;
				cout << "1. CrossFit" << endl;
				cout << "2. HIIT" << endl;
				cout << "3. TRX" << endl;
				cout << "4. Pesas" << endl;
				cout << "5. Spinning" << endl;
				cout << "6. Cardio" << endl;
				cout << "7. Yoga" << endl;
				cout << "8. Zumba" << endl;
				cout << "---| Ingrese el numero de la especialidad: ";
				cin >> espeResp;
				cin.ignore(10000, '\n');
			} while (espeResp < 1 || espeResp > 8);
			clase->setEspe(espeResp);
			cout << "---| Especialidad actualizada con exito. |---" << endl;
			break;
		}
		case 4: {
			string nuevaHora;
			cout << "---| Ingrese la nueva hora (XX:XXam o XX:XXpm): ";
			if(!(getline(cin, nuevaHora))){
				cout << "---| Respuesta invalida. Intente de nuevo. |---" << endl;
				continue;
			}
			if(!this->esHoraValida(nuevaHora)){
				cout << "---| Hora no valida. Intente de nuevo. |---" << endl;
				continue;
		}
			clase->setHora(nuevaHora);
			cout << "---| Hora actualizada con exito. |---" << endl;
			break;
		}
		case 5: {
			if (sucu->getNumInstructores() == 0) {
				cout << "---| No hay instructores disponibles en la sucursal. |---" << endl;
				break;
			}
			while (true) {
				sucu->listarInstructores();
				string cedula;
				int cedIns;
				cout << "\n---| Ingrese la cedula del nuevo instructor (O ingrese salir para volver al menu): ";
				if(!(getline(cin, cedula))){
					cout << "---| Respuesta invalida. Intente de nuevo. |---" << endl;
					continue;
				}
				if (cedula == "salir" || cedula == "Salir" || cedula == "SAlir" || cedula == "SALir" || cedula == "SALIr" || cedula == "SALIR") {
					break;
				}
				else if (cedula.empty()) {
					cout << "---| La cedula no puede estar vacia |---" << endl;
					system("cls");
					continue;
				}
				else if (cedula[0] == ' ') {
					cout << "---| La cedula no puede empezar con un espacio |---" << endl;
					system("cls");
					continue;
				}
				else {
					try {
						cedIns = stoi(cedula);
					}
					catch (invalid_argument&) {
						cout << "---| La cedula solo puede contener numeros |---" << endl;
						continue;
					}
					catch (out_of_range&) {
						cout << "---| La cedula no puede ser tan larga |---" << endl;
						continue;
					}
				}
				Instructor* nuevoInstructor = sucu->buscarInstructor(cedIns);
				if (nuevoInstructor != nullptr) {
					clase->setInstructor(nuevoInstructor);
					cout << "---| Instructor actualizado con exito. |---" << endl;
				}
				else {
					cout << "---| Instructor no encontrado. Intentelo de nuevo|---" << endl;
					continue;
				}
				break;
			}
			break;
		}
		case 6:
			cout << "---| Volviendo al menu anterior |---" << endl;
			break;
		default:
			cout << "---| Opcion invalida. Intente de nuevo. |---" << endl;
			break;
		}
	} while (opcion != 6);
	}
}
void Control::eliminarClaseGrupal(Sucursal* sucu) {
	if (sucu->getNumClasesGrups() == 0) {
		cout << "---| No hay clases grupales registradas en la sucursal. |---" << endl;
		cout << "\n---| Presione enter para salir. |---" << endl;
		cin.get();
		system("cls");
		return;
	}

	char res;
	do {
		string codigoStr;
		int codigoClase = 0;
		bool codigoValido = false;
		bool confirmado = false;

		while (!codigoValido) {
			system("cls");
			cout << "\n\n---| Clases grupales registradas en la sucursal |---\n\n";
			sucu->listarClasesGrupales();
			cout << endl;
			cout << "\n---| Ingrese el codigo de la clase grupal a eliminar (O ingrese salir para volver): ";
			if(!(getline(cin, codigoStr))){
				cout << "---| Respuesta invalida. Intente de nuevo. |---" << endl;
				continue;
			}
			if (codigoStr == "salir" || codigoStr == "Salir" || codigoStr == "SAlir" || codigoStr == "SALir" || codigoStr == "SALIr" || codigoStr == "SALIR") {
				system("cls");
				return;
			}
			if(codigoStr.empty()){
				cout << "---| El codigo no puede estar vacio. Intente de nuevo. |---" << endl;
				continue;
			}
			if(codigoStr[0]==' '){
				cout << "---| El codigo no puede empezar con un espacio. Intente de nuevo. |---" << endl;
				continue;
			}
			try {
				codigoClase = stoi(codigoStr);
			}
			catch (invalid_argument&) {
				cout << "---| El codigo debe ser numerico. Intente de nuevo. |---" << endl;
				continue;
			}
			catch (out_of_range&) {
				cout << "---| El codigo ingresado es demasiado largo. Intente de nuevo. |---" << endl;
				continue;
			}
			ClaseGrupal* clase = sucu->buscarClaseGrupal(codigoClase);
			if (clase == nullptr) {
				cout << "---| La clase grupal con ese codigo no existe. |---" << endl;
				continue;
			}
			do {
				cout << "\033[31m";
				cout << "\n\n---| Realmente desea eliminar la clase grupal con codigo " << clase->getCodClase() << "? (S/N): ";
				cout << "\033[0m";
				cin >> res;
				cin.ignore(10000, '\n');
			} while (res != 'S' && res != 's' && res != 'N' && res != 'n');
			if (res == 'S' || res == 's') {
				confirmado = true;
			}
			else  {
				cout << "\n\n---| Operacion cancelada. Puede ingresar otro codigo. |---" << endl;
				codigoValido = true;
				cin.get();
			}
		}
		if (confirmado) {
			system("cls");
			sucu->eliminarClaseGrupal(codigoClase);
		}
		if (sucu->getNumClasesGrups() == 0) {
			cout << "---| No hay mas clases grupales registradas. |---" << endl;
			cout << "---| Presione Enter para volver al menu principal |---" << endl;
			cin.get();
			system("cls");
			return;
		}
		do {
			cout << "\n\n---| Desea eliminar alguna otra clase grupal? (S/N): ";
			cin >> res;
			cin.ignore(10000, '\n');
		} while (res != 'S' && res != 's' && res != 'N' && res != 'n');

	} while (res == 'S' || res == 's');
}

//-------------------Extras-------------------

bool Control::esFechaValida(string& fN) {
	stringstream ss(fN);
	int dia, mes, anio;
	char sep1, sep2;


	if (ss >> dia >> sep1 >> mes >> sep2 >> anio && sep1 == '/' && sep2 == '/') {
		if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && anio >= 1900 && anio <= annio) return true;
	}
	return false;
}
bool Control::esHoraValida(string& hor) {
	stringstream ss(hor);
	int hora, min;
	char sep1;
	string ampm;
	if (ss >> hora >> sep1 >> min >> ampm && sep1 == ':' && (ampm == "am" || ampm == "pm")) {
		if (hora >= 1 && hora <= 12 && min >= 1 && min <= 59) return true;
	}
	return false;
}


