#include "Control.h"
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
		cout << "Gestionando sucursal con codigo: " << codigo << endl;

		int resp = 0;
		do {
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
			cin.ignore(); // Limpiar el buffer de entrada
			system("cls");

			int tel = 0, nC = 0, cC = 0, ced = 0, telf = 0, ins = 0;
			string corr = "", codi = "", nom = "", fN = "", fI = "", hor = "";
			char sexo = ' ';

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
				cout << "---| Saliendo del menu de gestion. |---" << endl;
				break;
			}
			default:
			{
				cout << "-| Opcion no valida. Por favor, intente de nuevo. |-" << endl;
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

//-------------------Clientes-------------------

void Control::menuGestionarClientes(Sucursal* sucu) {
	int resp = 0;
	do {
		cout << "---| Menu de gestion de clientes de la sucursal " << sucu->getCod() << " |---\n" << endl;
		cout << "\n1. Listar clientes " << endl;
		cout << "\n2. Agregar cliente" << endl;
		cout << "\n3. Gestionar cliente" << endl;
		cout << "\n4. Eliminar cliente" << endl << endl;
		cout << "\n5. Salir" << endl << endl;
		cout << "\n---| Ingrese la opcion que desea realizar: ";
		cin >> resp;
		cin.clear();
		cin.ignore();
		system("cls");

		switch (resp) {
		case 1:
		{
			cout << "---| Listado de clientes |--- " << endl << endl;
			sucu->listarClientes();

			cout << "\n\n---| Presione enter para salir. |---" << endl;
			cin.get();
			system("cls");
			break;
		}
		case 2:
		{
			this->agregarCliente(sucu);
			system("cls");
			break;
		}
		case 3:
		{
			this->gestionarCliente(sucu);
			system("cls");
			break;
		}
		case 4:
		{
			this->eliminarCliente(sucu);
			system("cls");
			break;
		}
		case 5:
		{
			cout << "\n\n---| Saliendo del menu de gestion de clientes. Presione enter. |---" << endl;
			cin.ignore();
			system("cls");
			return;
		}
		default:
			system("cls");
			break;
		}
	} while (resp != 5);
}
void Control::agregarCliente(Sucursal* sucu) {
	bool repite1 = true;
	int telf, ced;
	string nom, fN, fI, corr;
	char sexo;
	while (repite1) {
		cout << "---| Agregar cliente |--- " << endl << endl;


		if (sucu->getNumInstructores() == 0) {
			cout << "-| No hay instructores disponibles en la sucursal. Por lo que no se puede agregar ningun cliente. |-" << endl;
			return;
		}

		cout << "---| Ingrese el nombre del cliente: ";
		getline(cin, nom);
		if (nom.empty()) { //he descubierto mas cosas de codigo con este proyecto que otra vara jaja
			cout << "---| El nombre no puede estar vacio. |---" << endl;
			continue;
		}
		while (true) {
			cout << "---| Ingrese la cedula del cliente: ";
			if (cin >> ced) {
				break;
			}
			cout << "---| Debe ingresar un numero valido. |---" << endl;
			cin.clear();
			cin.ignore();
		}
		cin.ignore();
		while (true){
		cout << "---| Ingrese el telefono del cliente: ";
		if (cin >> telf&&(telf>10000000&&telf<99999999)) {
			break;
		}
		cout <<endl<< "---| Debe ingresar un numero valido. |---" << endl;
}

		while(true){
		cout << "---| Ingrese el correo electronico del cliente: ";
		getline(cin, corr);
		if (corr.find('@') == string::npos) {
			cout << "---| El correo no es valido. |---" << endl;
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

		while(true){
		cout << "---| Ingrese el sexo del cliente (M: Masculino/F: Femenino): ";
		if(cin >> sexo&&(sexo=='m' || sexo == 'M' || sexo == 'f' || sexo == 'F')) break;
		cout << "---| Debe ingresar M o F |---" << endl;
}

		while (true) {
			cin.ignore();
			cin.clear();
			cout << "---| Ingrese la fecha de inscripcion del cliente (Dia/Mes/Annio): ";
			getline(cin, fI);
			if (this->esFechaValida(fN)){
				break;
		}
		else {
			cout << "---| Fecha no valida. |---" << endl;
			continue;
			}
		}

		bool sigue1 = true;
		do {
			sigue1 = true;
			cout << endl << "---| Que instructor desea asignarle al cliente? |---" << endl << endl;
			sucu->listarInstructores();
			cout << endl;
			int cedulaIns;
			cout << endl << "---| Ingrese la cedula del instructor que se le asignara al cliente: ";
			if (!(cin >> cedulaIns)) {
				cout << "---| Debe ingresar un numero valido. |---" << endl;
				cin.clear();
				cin.ignore();
				continue;
			}
				if (sucu->buscarInstructor(cedulaIns) != nullptr) {
					Instructor* instructorAsignado = sucu->buscarInstructor(cedulaIns);
					Cliente* nuevoCliente = new Cliente(nom, ced, telf, corr, fN, sexo, fI, 0, instructorAsignado);
					sucu->agregarCliente(nuevoCliente);
					sigue1 = true;
				}
				else {
					cout << "---| Instructor no encontrado. Por favor intente de nuevo. |---" << endl;
				}
		} while (sigue1 != true);

		cout << "Cliente agregado con exito." << endl << endl;

		while (true) {
			int repiteInt;
			cout << "-| Desea agregar otro cliente? (1: Si, 2: No): ";
			if (cin >> repiteInt) {
				if (repiteInt == 1) {
					system("cls");
					repite1 = true;
					break;
				}
				else if (repiteInt == 2) {
					system("cls");
					repite1 = false;
					break;
				}
				else {
					cout << "-| Opcion invalida. Por favor, intente de nuevo. |-" << endl;
				}
			}
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
		cin.ignore();

		if (res == 's' || res == 'S') {
			codExis = true;
		}
		else {
			system("cls");
			cout << "\n\n---| Operacion cancelada. Puede ingresar otra cedula. |---" << endl;
		}
	}
	
	cout << "\n\n---| cliente " << sucu->buscarCliente(ced)->getNombre()<< " eliminado con exito. |---\n\n" << endl;
	sucu->eliminarCliente(ced);
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
		cin.ignore();
		system("cls");
		return;
	}

	int repe = 0;
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
					cin.ignore(10000, '\n');
					cout << "---| La cedula ingresada debe ser totalmente numerica. Intente de nuevo. |---" << endl;
					codExis = false;
					continue;
				}
				catch (out_of_range&) {
					system("cls");
					cin.ignore(10000, '\n');
					cout << "---| La cedula ingresada es demasiado larga. Intente de nuevo. |---" << endl;
					codExis = false;
					continue;
				}

			}

			if (sucu->buscarCliente(ced) == nullptr) {
				system("cls");
				cout << "---| La cedula ingresada no existe. Por favor, aprete enter para volverlo a intentar. |---";
				cin.ignore(10000, '\n');
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
			cout << endl << "---| Desea gestionar al cliente " << sucu->buscarCliente(ced)->getNombre() << "? (1: Si, 2: No): ";
			getline(cin, entrada);
			if (entrada == "1") {
				system("cls");
				this->gestionarClienteSi(sucu, ced);
				system("cls");
				return;
			}
			if (entrada == "2") {
				system("cls");
				return;
			}
			cout << "---| Respuesta invalida. Intente de nuevo. |---\n";
			cin.ignore(10000, '\n');
		}
	} while (true);

	cout << "---| Presione Enter para volver al menu de gestion...|---" << endl;
	cin.ignore();
	cin.get();
	system("cls");

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
		cout << "\n4. Gestionar ejercicios" << endl;
		cout << "\n5. Gestionar clases grupales" << endl;
		cout << "\n6. Salir" << endl << endl;
		cout << "\n---| Ingrese la opcion: " << endl;
		cin >> opcion;
		cin.ignore();
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
			this->menuGestionarRutinas(cliente);
			break;
		case 4:
			this->menuGestionarEjercicios(cliente);
			break;
		case 5:
			this->menuGestionarCliClasesGrupales(cliente);
			break;
		case 6:
			return;
		default:
			cout << "---| Opción inválida. |---" << endl;
			cin.ignore(10000, '\n');
		}
	} while (opcion != 6);
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
		cin.ignore();
		system("cls");
		string fecha;

		switch (opcion) {

		case 1: {
			bool resp;
			while(true) {

				resp = false;
				double peso, estatura, grasa, musculo, grasaVisc, cintura, cadera, pecho, muslo;
				int edadMet;

				while (true) {
					cout << "---| Ingrese la fecha de la medicion (Dia/Mes/Annio): ";
					getline(cin, fecha);
					if (esFechaValida(fecha)) {
						break;
					}
					else {
						cout << "---| Fecha no valida. |---" << endl << endl;
						cin.ignore(10000, '\n');
						continue;
					}

				}
				while (true) {
					cout << "---| Ingrese el peso (kg): ";
					if (!(cin >> peso) || peso <= 0) {
						cout << "---| Peso no valido. |---" << endl << endl;
						cin.ignore(10000, '\n');
					}
					else {
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la estatura (m): ";
					if (!(cin >> estatura) || estatura <= 0) {
						cout << "---| Estatura no valida. |---" << endl << endl;
						cin.ignore(10000, '\n');
					}
					else {
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese el porcentaje de grasa corporal (%): ";
					if (!(cin >> grasa) || grasa < 0) {
						cout << "---| Porcentaje de grasa corporal no valida. |---" << endl << endl;
						cin.ignore(10000, '\n');
					}
					else {
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese el porcentaje de musculo (%): ";
					if (!(cin >> musculo) || musculo < 0) {
						cout << "---| Porcentaje de musculo no valido. |---" << endl << endl;
						cin.ignore(10000, '\n');
					}
					else {
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la edad metabolica: ";
					if (!(cin >> edadMet) || edadMet < 0) {
						cout << "---| Edad metabolica no valida. |---" << endl << endl;
						cin.ignore(10000, '\n');

					}
					else {
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la grasa visceral (%): ";
					if (!(cin >> grasaVisc) || grasaVisc < 0) {
						cout << "---| Porcentaje de grasa visceral no valido. |---" << endl << endl;
						cin.ignore(10000, '\n');
					}
					else {
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la medida de cintura (cm): ";
					if (!(cin >> cintura) || cintura < 0) {
						cout << "---| Medida de la cintura no valida. |---" << endl << endl;
						cin.ignore(10000, '\n');
					}
					else {
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la medida de cadera (cm): ";
					if (!(cin >> cadera) || cadera < 0) {
						cout << "---| Medida de la cadera no valida. |---" << endl << endl;
						cin.ignore(10000, '\n');

					}
					else {
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la medida de pecho (cm): ";
					if (!(cin >> pecho) || pecho < 0) {
						cout << "---| Medida del pecho no valido. |---" << endl << endl;
						cin.ignore(10000, '\n');
					}
					else {
						break;
					}
				}
				while (true) {
					cout << "---| Ingrese la medida de muslo (cm): ";
					if (!(cin >> muslo) || muslo < 0) {
						cout << "---| Medida del muslo no valido. |---" << endl;
						cin.ignore(10000, '\n');
					}
					else {
						break;
					}
				}
				cin.ignore();

				ReporteMedicion rep(*cli, fecha, peso, estatura, grasa, musculo, edadMet, grasaVisc, cintura, cadera, pecho, muslo);
				cli->agregarReporte(rep);

				cout << "---| Medicion agregada con exito. |---" << endl;
				char siono;
				while (true){
				cout << "---| Desea agregar otra medicion? (S:si /N:no): ";cin >> siono;
				if (siono != 'n' && siono != 'N' && siono != 's' && siono != 'S') {
					cout << "---| Opcion invalida |---" << endl;
					cin.ignore(10000, '\n');
						system("cls");
						continue;
				}
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
			cli->listarReportes();
			if (cli->getNumReportes() == 0) {
				cout << "---| No hay mediciones para mostrar. |---" << endl;
				cout << "---| Presione enter para continuar. |---" << endl;
				cin.get();
				system("cls");
				break;
			}
			cout << "---| ¿Desea ver el detalle de alguna medicion? (Ingrese el numero o 0 para salir): ";
			int num;
			cin >> num;
			cin.ignore();
			if (num > 0 && num <= cli->getNumReportes()) {
				ReporteMedicion* rep = cli->getReportePorIndice(num - 1);
				cout << "---| Detalles de la medicion #" << num << " |---" << endl;
				cout << rep->toString() << endl;
				cout << "---| Presione enter para continuar. |---" << endl;
				cin.get();
			}
			else if (num != 0) {
				cout << "---| Numero fuera de rango. |---" << endl;
				cin.ignore(10000, '\n');
				cout << "---| Presione enter para continuar. |---" << endl;
				cin.get();
			}
			break;
		}
		case 3:
		{
			return;
		}
		default:
		{
			cout << "---| Opción inválida. |---" << endl;
			cin.ignore(10000, '\n');
		}
		}
		} while (opcion != 3);
	}
void Control::menuGestionarRutinas(Cliente* cli) {
		int opcion = 0;
		do {
			cout << "---| Gestion de Rutinas del cliente " << cli->getNombre() << " |---\n\n" << endl;
			cout << "\n1. Agregar rutina" << endl;
			cout << "\n2. Historial de rutinas" << endl;
			cout << "\n3. Salir" << endl << endl;
			cout << "---| Ingrese la opcion: ";
			cin >> opcion;
			cin.ignore(10000, '\n');
			system("cls");

			string fecha;

			switch (opcion) {
			case 1: {
				while (true) {
					cout << "---| Agregar rutina |---" << endl;

					while (true) {
						cout << "---| Ingrese la fecha de la rutina (Dia/Mes/Annio): ";
						getline(cin, fecha);
						if (esFechaValida(fecha)) {
							break;
						}
						else {
							cout << "---| Fecha no valida. |---" << endl << endl;
							cin.ignore(10000, '\n');
							continue;
						}
					}

					string descripcion;
					int duracion; 
					string objetivo;
					while (true) {
						cout << "---| Ingrese la descripcion de la rutina: ";
						getline(cin, descripcion);
						if (descripcion.empty()) {
							cout << "---| La descripcion no puede estar vacia. |---" << endl;
							cin.ignore(10000, '\n');
							continue;
						}
						break;
					}

					while (true) {
						cout << "---| Ingrese la duracion de la rutina (minutos): ";
						if (!(cin >> duracion) || duracion <= 0) {
							cout << "---| Duracion no valida. |---" << endl;
							cin.clear();
							cin.ignore(10000, '\n');
							continue;
						}
						cin.ignore(10000, '\n');
						break;
					}

					cout << "---| Ingrese el objetivo de la rutina (ej: fuerza, resistencia, cardio, etc.): ";
					getline(cin, objetivo);
					if (objetivo.empty()) {
						objetivo = "No especificado";
					}

					// Crear y agregar la rutina
					Rutina nuevaRutina(*cli, fecha, descripcion, duracion, objetivo);
					cli->agregarRutina(nuevaRutina);

					cout << "---| Rutina agregada con exito. |---" << endl;

					// Preguntar si desea agregar otra
					char siono;
					while (true) {
						cout << "---| Desea agregar otra rutina? (S:si / N:no): ";
						cin >> siono;
						cin.ignore(10000, '\n');
						if (siono == 's' || siono == 'S') {
							system("cls");
							break; // vuelve al while principal
						}
						else if (siono == 'n' || siono == 'N') {
							system("cls");
							goto salirAgregarRutina;
						}
						else {
							cout << "---| Opcion invalida. |---" << endl;
						}
					}
				}
			salirAgregarRutina:
				cout << "---| Presione enter para salir. |---" << endl;
				cin.get();
				break;
			}
			case 2: {
				// Historial de rutinas
				cli->listarRutinas();
				if (cli->getNumRutinas() == 0) {
					cout << "---| No hay rutinas para mostrar. |---" << endl;
					cout << "---| Presione enter para continuar. |---" << endl;
					cin.get();
					system("cls");
					break;
				}

				cout << "---| ¿Desea ver el detalle de alguna rutina? (Ingrese el numero o 0 para salir): ";
				int num;
				cin >> num;
				cin.ignore(10000, '\n');
				if (num > 0 && num <= cli->getNumRutinas()) {
					Rutina* rut = cli->getRutinaPorIndice(num - 1);
					cout << "---| Detalles de la rutina #" << num << " |---" << endl;
					cout << rut->toString() << endl;
					cout << "---| Presione enter para continuar. |---" << endl;
					cin.get();
				}
				else if (num != 0) {
					cout << "---| Numero fuera de rango. |---" << endl;
					cout << "---| Presione enter para continuar. |---" << endl;
					cin.get();
				}
				break;
			}
			case 3: {
				return;
			}
			default: {
				cout << "---| Opcion invalida. |---" << endl;
				cin.ignore(10000, '\n');
			}
			}
		} while (opcion != 3);
	}
void Control::menuGestionarEjercicios(Cliente* cli) {

}
void Control::menuGestionarCliClasesGrupales(Cliente* cli) {

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
	cin.clear();
	cin.ignore();
	system("cls");

	int tel = 0, nC = 0, cC = 0, ced = 0, telf = 0, ins = 0;
	string corr = "", codi = "", nom = "", fN = "", fI = "", hor = "";
	char sexo = ' ';

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
	case 5:
	{
		cout << "\n\n---| Saliendo del menu de gestion de instructores. Presione enter. |---" << endl;
		cin.ignore();
		system("cls");
		return;
	}
	default:
	{
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
		getline(cin, nom);
		if (nom.empty()) {
			cout << "---| El nombre no puede estar vacio. |---" << endl;
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
			cin.ignore();
			telf = 0;
			if (!(cin >> telf)) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "---| Debe ingresar un numero valido. |---" << endl;
				continue;
			}
			else if (telf < 10000000 || telf > 99999999) {
				cout << "---| Debe ingresar un numero valido (8 digitos) |---" << endl;
				continue;
			}
			break;
		}
		while (true) {
			int c = 0;
			cout << "---| Ingrese el correo electronico del instructor (ejemplo@gmail.com): ";
			getline(cin, corr);
			int com = corr.size() - 1;
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
			;
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
			cin.ignore();
			if (especialidadPrincipal >= 1 && especialidadPrincipal <= 8) {
				break;
			}
			else {
				cout << "---| Opción inválida. |---" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}

		Instructor* nuevoInstructor = new Instructor(ced, nom, telf, corr, fN, especialidadPrincipal);
		sucu->agregarInstructor(nuevoInstructor);

		while (true) {
			cout << "---| ¿Desea agregar otra especialidad? (1: Sí, 2: No): ";
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
				}
				cin.ignore(10000, '\n');
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
				}
			}
		}
	}
}
void Control::gestionarInstructor(Sucursal* sucu) {
	if (sucu->getNumInstructores() == 0) {
		cout << "-| No hay instructores registrados. |-" << endl << endl;
		cout << "-| Presione Enter para volver al menu principal..." << endl;
		cin.ignore();
		system("cls");
		return;
	}

	int repe = 0;
	do {
		string codigo;
		int ced = 0;
		bool codExis = false;

		while (codExis == false) {
			cout << "\n\n---| Bienvenido, a continuacion se mostraran los instructores existentes |---\n\n" << endl;
			sucu->listarInstructores();
			cout << endl;
			cout << "---| Ingrese la cedula del instructor a gestionar (Ingrese salir para volver al menu anterior): ";
			getline(cin, codigo);

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
		while (true) {
			cout << endl << "---| Desea gestionar al instructor "<< sucu->buscarInstructor(ced)->getNombre()<< "? (1: Si, 2: No): ";
			getline(cin, entrada);

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

	cout << "---| Presione Enter para volver al menu de gestion...|---" << endl;
	cin.ignore();
	cin.get();
	system("cls");
}
void Control::gestionarInstructorSi(Sucursal* sucu, int ced) {
	Instructor* instructor = sucu->buscarInstructor(ced);
	if (instructor == nullptr) return;

	int opcion;
	do {
		cout << "---| Gesti0n del/la instructor(a) " << instructor->getNombre() << " |---" << endl;
		cout << "\n1. Ver detalles del instructor" << endl;
		cout << "\n2. Listar clientes vinculados" << endl;
		cout << "\n3. Gestionar clientes vinculados" << endl;
		cout << "\n4. Salir" << endl << endl;
		cout << "\n---| Ingrese la opcion: ";
		cin >> opcion;
		cin.ignore();
		system("cls");

		switch (opcion) {
		case 1:
			cout << instructor->toString();
			cout << "---| Ingrese enter para salir |---" << endl;
			cin.get();
			system("cls");
			break;

		case 2:
			sucu->listarClientesDeInstructor(instructor);
			cout << "---| Ingrese enter para salir |---" << endl;
			cin.get();
			system("cls");
			break;

		case 3:
			this->menuGestionarCliInst(instructor, sucu);
			system("cls");
			break;

		case 4:
			return;

		default:
			cout << "---| Opción inválida. |---" << endl;
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
			cout << "---| Ese cliente no está vinculado a este instructor. |---" << endl;
			cin.get();
			continue;
		}
		system("cls");
		this->gestionarClienteSi(sucu, ced);
	}
}
void Control::eliminarInstructor(Sucursal* sucu) {
	if (sucu->getNumInstructores() == 0) {
		cout << "-| No hay instructores registrados. |-" << endl << endl;
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
		int ced;
		while (codExis == false) {
			cout << "\n\n---| Bienvenido, a continuacion se mostraran los instructores existentes |---\n\n" << endl;
			sucu->listarInstructores();
			cout << endl;
			cout << "---| Ingrese la cedula del instructor a eliminar (Ingrese salir para volver al menu anterior): ";
			getline(cin, codigo);

			if (codigo == "salir" || codigo == "Salir" || codigo == "SAlir" || codigo == "SALir" || codigo == "SALIr" || codigo == "SALIR") {
				system("cls");
				break;
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

			if (sucu->buscarInstructor(ced) == nullptr) {
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

			cout << "\033[31m";
			cout << "\n\n---| Realmente desea eliminar al instructor " << sucu->buscarInstructor(ced)->getNombre() << "? (S / N) : ";
			cout << "\033[0m";
			cin >> res;
			cin.ignore();

			if (res == 's' || res == 'S') {
				codExis = true;
			}
			else {
				system("cls");
				cout << "\n\n---| Operacion cancelada. Puede ingresar otra cedula. |---" << endl;
			}
		}

		cout << "\n\n---| Instructor " << sucu->buscarInstructor(ced)->getNombre() << " eliminado con exito. |---\n\n" << endl;
		sucu->eliminarInstructor(ced);

		do {
			cout << "\n\n---| Desea eliminar otro instructor? (S/N): ";
			cin >> res;
			cin.ignore();
			system("cls");
			if (sucu->getNumInstructores() == 0) {
				cout << "---| No hay mas instructores registrados. |---";
				cout << "---| Presione Enter para volver al menu principal |---" << endl;
				cin.ignore();
				system("cls");
				return;
			}
		} while (res != 'N' && res != 'n' && res != 'S' && res != 's');
	} while (res != 'N' && res != 'n');
	return;
}

//-------------------Clases Grupales-------------------

void Control::menuGestionarClasesGrupales(Sucursal* sucu) {
		int resp = 0;
		do {
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
				system("cls");
				break;
			}
			case 2: {
				this->agregarClaseGrupal(sucu);
				system("cls");
				break;
			}
			case 3: {
				this->gestionarClaseGrupalSi(sucu);
				system("cls");
				break;
			}
			case 4: {
				this->eliminarClaseGrupal(sucu);
				system("cls");
				break;
			}
			case 5: {
				cout << "\n\n---| Saliendo del menu de gestion de clases grupales. Presione enter. |---" << endl;
				cin.get();
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

			cout << "---| Ingrese la cedula del instructor (o 'salir' para cancelar): ";
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
	cout << "---| Gestionar clase grupal |---" << endl;
	cout << "Ingrese el codigo de la clase grupal a gestionar: ";
	cin >> codigoClase;
	cin.ignore(10000, '\n');

	ClaseGrupal* clase = sucu->buscarClaseGrupal(codigoClase);
	if (clase == nullptr) {
		cout << "---| Clase grupal no encontrada. |---" << endl;
		cout << "\n---| Presione enter para salir. |---" << endl;
		cin.get();
		system("cls");
		return;
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
				cout << "---| No hay instructores disponibles en la sucursal. |---" << endl;
				break;
			}
			while (true) {
				sucu->listarClientes();
				string cedula;
				int cedCli;
				cout << "Ingrese la cedula del cliente a agregar (O ingrese salir para volver al menu): ";
				getline(cin, cedula);
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
				else if (!(cin >> cedula)) {
					cout << "---| Debe ingresar un numero valido. |---" << endl;
					cin.clear();
					cin.ignore();
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
				cin.ignore(10000, '\n');
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
						cout << "---| Respues invalida, intentelo de nuevo |---" << endl;
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
			getline(cin, nuevaHora);
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
				cout << "Ingrese la cedula del nuevo instructor (O ingrese salir para volver al menu): ";
				getline(cin, cedula);
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
				else if (!(cin >> cedula)) {
					cout << "---| Debe ingresar un numero valido. |---" << endl;
					cin.clear();
					cin.ignore();
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
				cin.ignore(10000, '\n');
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
			cout << "---| Volviendo al menu anterior... |---" << endl;
			break;
		default:
			cout << "---| Opcion invalida. Intente de nuevo. |---" << endl;
			break;
		}
	} while (opcion != 6);
}
void Control::eliminarClaseGrupal(Sucursal* sucu) {


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


