#pragma once

class Menu
{
private:
	
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

