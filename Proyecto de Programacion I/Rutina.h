#pragma once
#include <iostream>
using namespace std; 

class Instructor;
class Cliente;
class Ejercicio;

class Rutina
{
private:
	Cliente* cliente_;
	Ejercicio** ejercicio_;
	string descripcion_;
	int duracion_;
	int numEjercicios_;
	int capEjer_;
public:
	Rutina();
	Rutina(Cliente* cli, string descripcion, int duracion, int maxEjer);
	~Rutina();
	void setCliente(Cliente* cliente);
	void setDescripcion(string desc);
	void setDuracion(int dur);
	bool agregarEjercicio(Ejercicio* ejer);
	void listarEjercicios();
	bool eliminarEjercicio(int num);
	int getNumEjercicios();
	Cliente* getCliente();
	string getDescripcion();
	int getDuracion();
	Ejercicio* getEjercicio();
	string ejerci();
	string toString();
};

