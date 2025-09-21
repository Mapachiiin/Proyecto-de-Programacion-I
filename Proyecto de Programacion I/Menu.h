#pragma once
#include "Sucursales.h"
class Menu
{
private:
	Sucursales** sucursales_;
	int numSucursales_;
public:
	Menu();
	~Menu();
	void mostrarMenu();
	void agregarSucursal();
	void eliminarSucursal();
	void listarSucursales();
	void gestionarSucursal(Sucursales* sucursal);
};

