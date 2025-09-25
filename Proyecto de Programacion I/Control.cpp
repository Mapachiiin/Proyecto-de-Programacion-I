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
void Control::quemados() {
	Sucursal* sucursal = buscarSucursal("SUC001");

	Instructor* nInstructor = new Instructor(119140155, "Fernando Aguilar", 74554322, "fernandez@gmail.com", "30 / 01 / 1988", 1);
	nInstructor->setEspecialidad(1);
	sucursal->agregarInstructor(nInstructor);

	Cliente* nCliente = new Cliente("Elias", 121383329, 87278865, "eMati@gmail.com", "02/12/2000", 'H', "20/14/2024", 0, nInstructor);
	sucursal->agregarCliente(nCliente);

	ClaseGrupal* nClase = new ClaseGrupal(001, 0, 30, sucursal, nInstructor, "10:00am", espeResp);
	sucursal->agregarClaseGrupal(nClase);
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
				this->gestionarClientes(sucursal);
				break;
			case 5:
				this->gestionarInstructores(sucursal);
				break;
			case 6:
				this->gestionarClasesGrupales(sucursal);
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

void Control::gestionarClientes(Sucursal* sucu) {
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

		int tel = 0, nC = 0, cC = 0, ced = 0, telf = 0, ins = 0;
		string corr = "", codi = "", nom = "", fN = "", fI = "", hor = "";
		char sexo = ' ';

		switch (resp) {
		case 1:
		{
			cout << "---| Listado de clientes: " << endl << endl;
			sucu->listarClientes();

			cout << "\n\n---| Presione enter para salir. |---" << endl;
			cin.get();
			break;
		}
		case 2:
		{
			bool repite1 = true;
			while (repite1) {
				cout << "---| Agregar cliente: " << endl << endl;


				if (sucu->getNumInstructores() == 0) {
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
					sucu->listarInstructores();
					int cedulaIns;
					cout << "-| Ingrese la cedula del instructor que se le asignara al cliente: ";
					cin >> cedulaIns;
					cin.clear();
					cin.ignore();
					for (int k = 0; k < sucu->getNumInstructores();k++) {
						if (sucu->buscarInstructor(cedulaIns) != nullptr) {
							Instructor* instructorAsignado = sucu->buscarInstructor(cedulaIns);
							Cliente* nuevoCliente = new Cliente(nom, ced, telf, corr, fN, sexo, fI, ins, instructorAsignado);
							sucu->agregarCliente(nuevoCliente);
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
		case 3:
			break;
		case 4:
			break;
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
	}while (resp != 0);
}


void Control::gestionarInstructores(Sucursal* sucu) {
	cout << "---| Menu de gestion de instructores de la sucursal " << sucu->getCod() << " |---\n" << endl;
	cout << "\n1. Listar instructores " << endl;
	cout << "\n2. Agregar instructor" << endl;
	cout << "\n3. Gestionar instructor" << endl;
	cout << "\n4. Eliminar instructor" << endl;
	cout << "\n5. Salir" << endl << endl;
	cout << "\n---| Ingrese la opcion que desea realizar: ";
	int resp;
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
		cout << "---| Listado de instructores: " << endl << endl;
		sucu->listarInstructores();

		cout << "\n\n---| Presione enter para salir. |---" << endl;
		cin.get();
		break;
	}
	case 2:
	{
		bool repite2 = true;
		bool sigue2 = true;
		while (sigue2) {

			cout << "---| Agregar instructor: " << endl << endl;


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

			Instructor* nuevoInstructor = new Instructor(ced, nom, telf, corr, fN, 0);
			sucu->agregarInstructor(nuevoInstructor);

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
	case 3:
	{
		break;
}
	case 4:
	{
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

}


void Control::gestionarClasesGrupales(Sucursal* sucu) {
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
			cout << "---| Listado de clases grupales: " << endl << endl;
			sucu->listarClasesGrupales();

			cout << "\n\n---| Presione enter para salir. |---" << endl;
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
					cout << "1. crossFit" << endl;
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
