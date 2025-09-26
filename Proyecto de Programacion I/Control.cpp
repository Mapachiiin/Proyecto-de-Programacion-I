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
	for (int i = 0; i < capSucursales_&&sucursales_[i]!=nullptr; ++i) {
		delete sucursales_[i];
	}
	delete[] sucursales_;
	numSucursales_ = 0;
	capSucursales_ = 0;
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
			cout << "\n4. Gestionar clientes" << endl;
			cout << "\n5. Gestionar instructores" << endl;
			cout << "\n6. Gestionar clases grupales" << endl;
			cout << "\n7. Salir del menu de gestion" << endl << endl;
			cout << "\n---| Ingrese la opcion que desea realizar: ";
			cin >> resp;
			cin.ignore(); // Limpiar el buffer de entrada
			system("cls");

			int tel=0, nC=0, cC=0, ced=0, telf=0, ins=0;
			string corr = "", codi = "", nom = "", fN = "", fI="", hor="";
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
			cout << "\n\n---| Sucursal "<<sucursales_[i]->getCod()<<" agregada |---" << endl;
			return;
		}
	}
}


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
			break;
		}
		case 3:
		{
			this->gestionarCliente(sucu);
			break;
		}
		case 4:
		{
			this->eliminarCliente(sucu);
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
		cout << "---| Agregar cliente: " << endl << endl;


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
		if (cin >> telf) {
			break;
		}
		cout << "---| Debe ingresar un numero valido. |---" << endl;
		cin.clear();
		cin.ignore();
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

			if (fN.size() < 8 || fN.size() > 10) {
				cout << "---| Fecha no valida. |---" << endl;
				continue;
			}

			if (fN.size() == 10) {
				if (fN[2] != '/' || fN[5] != '/') {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
				break;
			}

			if (fN.size() == 9) {
				if ((fN[2] != '/' && fN[4] == '/') || (fN[2] == '/' && fN[4] != '/')) {
					break;
				}
				else {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
			}

			if (fN.size() == 8) {
				if (fN[1] == '/' && fN[3] == '/') {
					break;
				}
				else {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
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

			if (fI.size() < 8 || fI.size() > 10) {
				cout << "---| Fecha no valida. |---" << endl;
				continue;
			}

			if (fI.size() == 10) {
				if (fI[2] != '/' || fI[5] != '/') {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
				break;
			}

			if (fI.size() == 9) {
				if ((fI[2] != '/' && fI[4] == '/') || (fI[2] == '/' && fI[4] != '/')) {
					break;
				}
				else {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
			}

			if (fI.size() == 8) {
				if (fI[1] == '/' && fI[3] == '/') {
					break;
				}
				else {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
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
		int ced;
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
		while (true) {
			cout << endl << "---| Desea gestionar al cliente " << codigo << "? (1: Si, 2: No): ";
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
		}
	} while (true);

	cout << "---| Presione Enter para volver al menu de gestion...|---" << endl;
	cin.ignore();
	cin.get();
	system("cls");

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
		int ced;
		while (codExis == false) {
			cout << "\n\n---| Bienvenido, a continuacion se mostraran los clientes existentes |---\n\n" << endl;
			sucu->listarClientes();
			cout << endl;
			cout << "---| Ingrese la cedula del cliente a eliminar (Ingrese salir para volver al menu anterior): ";
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
		cout << "\n\n---| Realmente desea eliminar al cliente" << sucu->buscarCliente(ced)->getNombre() << "? (S / N) : ";
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

		cout << "---| Ingrese el nombre del instructor: ";
		getline(cin, nom);
		if (nom.empty()) {
			cout << "---| El nombre no puede estar vacio. |---" << endl;
			continue;
		}

		while (true) {
			cout << "---| Ingrese la cedula del instructor: ";
			if (cin >> ced) {
				break;
			}
			cout << "---| Debe ingresar un numero valido. |---" << endl;
			cin.clear();
			cin.ignore();
		}
		cin.ignore();

		while (true) {
			cout << "---| Ingrese el telefono del instructor: ";
			if (cin >> telf) {
				break;
			}
			cout << "---| Debe ingresar un numero valido. |---" << endl;
			cin.clear();
			cin.ignore();
		}
		cin.ignore();

		while (true) {
			cout << "---| Ingrese el correo electronico del instructor: ";
			getline(cin, corr);
			if (corr.find('@') == string::npos) {
				cout << "---| El correo no es valido. |---" << endl;
				continue;
			}
			break;
		}

		while (true) {
			cout << "---| Ingrese la fecha de nacimiento del instructor (Dia/Mes/Annio): ";
			getline(cin, fN);

			if (fN.size() < 8 || fN.size() > 10) {
				cout << "---| Fecha no valida. |---" << endl;
				continue;
			}

			if (fN.size() == 10) {
				if (fN[2] != '/' || fN[5] != '/') {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
				break;
			}

			if (fN.size() == 9) {
				if ((fN[2] != '/' && fN[4] == '/') || (fN[2] == '/' && fN[4] != '/')) {
					break;
				}
				else {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
			}

			if (fN.size() == 8) {
				if (fN[1] == '/' && fN[3] == '/') {
					break;
				}
				else {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
			}
		}

		while (true) {
			cin.ignore();
			cin.clear();
			cout << "---| Ingrese la fecha de contrato del instructor (Dia/Mes/Annio): ";
			getline(cin, fI);

			if (fI.size() < 8 || fI.size() > 10) {
				cout << "---| Fecha no valida. |---" << endl;
				continue;
			}

			if (fI.size() == 10) {
				if (fI[2] != '/' || fI[5] != '/') {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
				break;
			}

			if (fI.size() == 9) {
				if ((fI[2] != '/' && fI[4] == '/') || (fI[2] == '/' && fI[4] != '/')) {
					break;
				}
				else {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
			}

			if (fI.size() == 8) {
				if (fI[1] == '/' && fI[3] == '/') {
					break;
				}
				else {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
			}
		}

		// Menú para la primera especialidad (obligatoria para el constructor)
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
			cout << "---| Ingrese el número de la especialidad: ";
			cin >> especialidadPrincipal;
			cin.clear();
			cin.ignore();
			if (especialidadPrincipal >= 1 && especialidadPrincipal <= 8) {
				break;
			}
			else {
				cout << "---| Opción inválida. |---" << endl;
			}
		}

		Instructor* nuevoInstructor = new Instructor(ced, nom, telf, corr, fN, especialidadPrincipal);
		sucu->agregarInstructor(nuevoInstructor);

		bool agregarMas = true;
		do {
			cout << "---| ¿Desea agregar otra especialidad? (1: Sí, 2: No): ";
			int otra;
			if (cin >> otra && (otra == 1 || otra == 2)) {
				cin.clear();
				cin.ignore();
				agregarMas = (otra == 1);
			}
			else {
				cout << "---| Opción inválida. |---" << endl;
				cin.clear();
				cin.ignore();
				agregarMas = false;
			}
			if (agregarMas) {
				int opcionEsp = 0;
				cout << "1. CrossFit" << endl;
				cout << "2. HIIT" << endl;
				cout << "3. TRX" << endl;
				cout << "4. Pesas" << endl;
				cout << "5. Spinning" << endl;
				cout << "6. Cardio" << endl;
				cout << "7. Yoga" << endl;
				cout << "8. Zumba" << endl;
				cout << "---| Ingrese el número de la especialidad: ";
				cin >> opcionEsp;
				cin.clear();
				cin.ignore();
				if (opcionEsp >= 1 && opcionEsp <= 8) {
					nuevoInstructor->agregarEspecialidadS(opcionEsp);
					cout << "---| Especialidad agregada. |---" << endl;
				}
				else {
					cout << "---| Opción inválida. |---" << endl;
				}
			}
		} while (agregarMas);

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
			sucu->listarClientes();
			cout << endl;
			cout << "---| Ingrese la cedula del cliente a eliminar (Ingrese salir para volver al menu anterior): ";
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
			cout << "\033[31m";
			cout << "\n\n---| Realmente desea eliminar al cliente" << sucu->buscarCliente(ced)->getNombre() << "? (S / N) : ";
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

		cout << "\n\n---| cliente " << sucu->buscarCliente(ced)->getNombre() << " eliminado con exito. |---\n\n" << endl;
		sucu->eliminarCliente(ced);
		do {
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


void Control::menuGestionarClasesGrupales(Sucursal* sucu) {
	int resp;
	do {
		cout << "---| Menu de gestion de clases grupales de la sucursal " << sucu->getCod() << " |---\n" << endl;
		cout << "\n1. Listar clases grupales " << endl;
		cout << "\n2. Agregar clase grupal" << endl;
		cout << "\n3. Gestionar clase grupal" << endl;
		cout << "\n4. Eliminar clase grupal" << endl << endl;
		cout << "\n5. Salir" << endl << endl;
		cout << "\n---| Ingrese la opcion que desea realizar: ";
		
		cin >> resp;
		cin.clear();
		cin.ignore();
		system("cls");

		int tel = 0, nC = 0, cC = 1, ced = 0, telf = 0, ins = 0;
		string corr = "", codi = "", nom = "", fN = "", fI = "", hor = "";
		char sexo = ' ';

		switch (resp) {
		case 1:
		{
			cout << "---| Listado de clases grupales |--- " << endl << endl;
			sucu->listarClasesGrupales();

			cout << "\n---| Presione enter para salir. |---" << endl;
			cin.get();
			system("cls");
			break;
		}
		case 2:
		{
			bool repetil = true;
			do {
				cout << " ---| Agregar clase grupal: " << endl << endl;

				cout << "---| Ingrese el codigo de la clase grupal: ";
				cin >> cC;
				cin.clear();
				cin.ignore();
			 while (sucu->buscarClaseGrupal(cC) != nullptr) {
					cout << "---| El codigo ingresado ya existe, intentelo de nuevo: ";
					cin >> cC;
					cin.clear();
					cin.ignore();
				}
				cout << "---| Ingrese el numero de cupos maximo: ";
				cin >> nC;
				cin.clear();
				cin.ignore();

				cout << "---| Ingrese la especialidad |--- " << endl;
				int espeResp;
				int repeti = 0;
				bool valid = true;
				do {
					valid = true;
					cout << "\n---| Especialidades |---" << endl;
					cout << "1. CrossFit" << endl;
					cout << "2. HIIT" << endl;
					cout << "3. TRX" << endl;
					cout << "4. Pesas" << endl;
					cout << "5. Spinning" << endl;
					cout << "6. Cardio" << endl;
					cout << "7. Yoga" << endl;
					cout << "8. Zumba." << endl << endl;
					cout << "\n---| Ingrese la opcion a escoger: "; cin >> espeResp;
					cin.clear();
					cin.ignore();
					if (espeResp >= 1 && espeResp <= 8) {
						valid = true;
					}
					else {
						valid = false;
					}
				} while (valid != true);

				cout << "---| Ingrese la hora a la que sera la clase grupal (XX:XXam o XX:XXpm): ";
				getline(cin, hor);

				bool sigue3 = true;
				do {
					sigue3 = true;
					if (sucu->getNumInstructores() == 0) {
						cout << "---| No hay ningun instructor en la sucursal para asignar |---";
						break;
					}
					cout << "---| Que instructor desea asignarle a la clase grupal? |---" << endl << endl;
					sucu->listarInstructores();
					int cedulaIns;
					cout << "\n---| Ingrese la cedula del instructor que se le asignara a la clase grupal: ";
					cin >> cedulaIns;
					cin.clear();
					cin.ignore();
					for (int k = 0; k < sucu->getNumInstructores();k++) {
						if (sucu->buscarInstructor(cedulaIns) != nullptr) {
							Instructor* instructorAsignado = sucu->buscarInstructor(cedulaIns);
							ClaseGrupal* nuevaClase = new ClaseGrupal(cC, 0, nC, sucu, instructorAsignado, hor, espeResp);
							sucu->agregarClaseGrupal(nuevaClase);
							break;
						}
						else {
							cout << "-| Instructor no encontrado. Por favor intente de nuevo. |-" << endl;
							sigue3 = false;
							continue;
						}
					}
				} while (sigue3 != true);
				system("cls");
				cout << "---| Clase grupal agregada con exito. |---" << endl << endl;
				while (repeti == 0) {
					cout << "---| Desea agregar otra clase grupal? (1: Si, 2: No): ";cin >> repeti;
					if (repeti == 1) {
						repeti = 0;
						break;
					}
					else if (repeti == 2) {
						repetil = false;
						break;
					}
				}



			} while (repetil==true);
			cout << "---| Presione enter para salir. |---" << endl;
			cin.get();
			system("cls");
			break;
		}
		case 3:

			break;
		case 4:

			break;
		case 5:
		{
			cout << "\n\n---| Saliendo del menu de gestion de clases grupales. Presione enter. |---" << endl;
			cin.ignore();
			system("cls");
			break;
		}
		default:

			break;
		}
	}while (resp!=5);
}

void Control::agregarClaseGrupal(Sucursal* sucu) {


}

void Control::gestionarClaseGrupal(Sucursal* sucu) {


}

void Control::eliminarClaseGrupal(Sucursal* sucu) {


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
				<<" | Provincia: "<<sucursales_[i]->getProvi()
				<<" | Canton: "<<sucursales_[i]->getCanton()
				<<" | Instructores: " << sucursales_[i]->getNumInstructores()
				<<" | Clientes: " << sucursales_[i]->getNumClientes() << " |-" << endl;	
		}
	}
}
void Control::gestionarClienteSi(Sucursal* sucu, int ced) {
    Cliente* cliente = sucu->buscarCliente(ced);
    if (cliente==nullptr) return;

    int opcion;
    do {
        cout << "---| Gestion del/la cliente: " << cliente->getNombre() << " |---" << endl;
        cout << "\n1. Ver detalles" << endl;
        cout << "\n2. Gestionar mediciones" << endl;
        cout << "\n3. Gestionar rutinas" << endl;
        cout << "\n4. Gestionar ejercicios" << endl;
        cout << "\n5. Gestionar clases grupales" << endl;
		cout << "\n6. Salir" << endl<<endl;
        cout << "\n---| Ingrese la opcion: "<<endl;
        cin >> opcion;
        cin.ignore();
        system("cls");

        switch (opcion) {
            case 1:
				cliente->toString();
				cout << "---| Ingrese enter para salir |---" << endl;
				cin.get();
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
        }
    } while (opcion != 6);
}
void Control::menuGestionarMediciones(Cliente* cli) {
	int opcion=0;
	do {
		cout << "---| Gestión de Mediciones del cliente: " << cli->getNombre() << " |---\n\n" << endl;
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
			double peso, estatura, grasa, musculo, grasaVisc, cintura, cadera, pecho, muslo;
			int edadMet;

			while (true) {
				cout << "---| Ingrese la fecha de la medicion (Dia/Mes/Annio): ";
				getline(cin, fecha);

				if (fecha.size() == 9) {
					if ((fecha[2] != '/' && fecha[4] == '/') || (fecha[2] == '/' && fecha[4] != '/')) {
						break;
					}
					else {
						cout << "---| Fecha no valida. |---" << endl;
						continue;
					}
					if (fecha.size() == 8) {
						if (fecha[1] == '/' && fecha[3] == '/') {
							break;
						}
						else {
							cout << "---| Fecha no valida. |---" << endl;
							continue;
						}
					}
				}

				if (fecha.size() < 8 || fecha.size() > 10) {
					cout << "---| Fecha no valida. |---" << endl;
					continue;
				}
				if (fecha.size() == 10) {
					if (fecha[2] != '/' || fecha[5] != '/') {
						cout << "---| Fecha no valida. |---" << endl;
						continue;
					}
					break;
				}
				

				cout << "---| Ingrese el peso (kg): ";
				if (!(cin >> peso) || peso <= 0) {
					cout << "---| Peso no valido. |---" << endl;
					cin.clear(); cin.ignore();
					break;
				}

				cout << "---| Ingrese la estatura (m): ";
				if (!(cin >> estatura) || estatura <= 0) {
					cout << "---| Estatura no valida. |---" << endl;
					cin.clear(); cin.ignore();
					break;
				}

				cout << "---| Ingrese el porcentaje de grasa corporal (%): ";
				if (!(cin >> grasa) || grasa < 0) {
					cout << "---| Porcentaje de grasa corporal no valida. |---" << endl;
					cin.clear(); cin.ignore();
					break;
				}

				cout << "---| Ingrese el porcentaje de musculo (%): ";
				if (!(cin >> musculo) || musculo < 0) {
					cout << "---| Porcentaje de musculo no valido. |---" << endl;
					cin.clear(); cin.ignore();
					break;
				}

				cout << "---| Ingrese la edad metabolica: ";
				if (!(cin >> edadMet) || edadMet < 0) {
					cout << "---| Edad metabólica no valida. |---" << endl;
					cin.clear(); cin.ignore();
					break;
				}

				cout << "---| Ingrese la grasa visceral (%): ";
				if (!(cin >> grasaVisc) || grasaVisc < 0) {
					cout << "---| Porcentaje de grasa visceral no valido. |---" << endl;
					cin.clear(); cin.ignore();
					break;
				}

				cout << "---| Ingrese la medida de cintura (cm): ";
				if (!(cin >> cintura) || cintura < 0) {
					cout << "---| Medida de la cintura no valida. |---" << endl;
					cin.clear(); cin.ignore();
					break;
				}

				cout << "---| Ingrese la medida de cadera (cm): ";
				if (!(cin >> cadera) || cadera < 0) {
					cout << "---| Medida de la cadera no valida. |---" << endl;
					cin.clear(); cin.ignore();
					break;
				}

				cout << "---| Ingrese la medida de pecho (cm): ";
				if (!(cin >> pecho) || pecho < 0) {
					cout << "---| Medida del pecho no valido. |---" << endl;
					cin.clear(); cin.ignore();
					break;
				}

				cout << "---| Ingrese la medida de muslo (cm): ";
				if (!(cin >> muslo) || muslo < 0) {
					cout << "---| Medida del muslo no valido. |---" << endl;
					cin.clear(); cin.ignore();
					break;
				}
				cin.ignore();

				ReporteMedicion rep(*cli, fecha, peso, estatura, grasa, musculo, edadMet, grasaVisc, cintura, cadera, pecho, muslo);
				cli->agregarReporte(rep);

				cout << "---| Medicion agregada con exito. |---" << endl;
				cout << "---| Presione enter para continuar. |---" << endl;
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
				cout << "---| Presione enter para continuar. |---" << endl;
				cin.get();
			}
			break;
		}
		case 3:
			return;
		default:
			cout << "---| Opción inválida. |---" << endl;
		}
		}
	}while (opcion != 3);
}
void Control::menuGestionarRutinas(Cliente* cli) {

}
void Control::menuGestionarEjercicios(Cliente* cli) {

}
void Control::menuGestionarCliClasesGrupales(Cliente* cli) {

}