#pragma once
#include "Control.h"

class Menu
{
public:
	Menu();
	~Menu();
	void mostrarMenu();
	void agregarSucursal();
	void eliminarSucursal();
	void listarSucursales();
	void gestionarSucursal(Sucursal* sucursal);
};

