#include <iostream>
#include "Menu.h"
#include "Control.h"
using namespace std;

int main() {
	Menu* menu = new Menu();
	menu->quemados();
	cout << "!!!Antes de iniciar el programa, por favor maximize la consola para una mejor experiencia." << endl << "Tambien, se advierte que todas las sucursales solamente tienen clientes, instructores y clases grupales quemadas." << endl<<" A excepcion de la SUC001, la cual se ingresaron datos mas profundos de los clientes y de las clases grupales.!!!";
	cout << "---| Presione Enter para continuar |---" << endl;
	cin.get();
	system("cls");

	menu->mostrarMenu();
	









	delete menu;
	return 0;
}