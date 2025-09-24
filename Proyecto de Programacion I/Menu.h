#pragma once
#include "Control.h"

class Menu
{
private:
	Control* control_;
	void menuAgregarSucursal();
	void menuEliminarSucursal();
	void menuListarSucursales();
	void menuGestionarSucursal();
	
public:
	Menu();
	~Menu();
	void quemados();
	void mostrarMenu();

};

