#pragma once
#include <iostream>
using namespace std; 

class Instructor;
class Cliente;
class Ejercicios;

class Rutina
{
private:
	Cliente* cliente_;
	Ejercicios** ejercicios_;
	string descripcion_;
	int duracion_;
	int numEjercicios_;
	int numPechTrice_;
	int numBice_;
	int numPier_;
	int numEspal_;
	int resp_;
	int capEjer_;
public:
	Rutina();
	Rutina(Cliente* cliente, string descripcion, int duracion, int maxEjer, int nEPT, int nEB, int nEP, int nEE);
	~Rutina();
	void setCliente(Cliente* cliente);
	void setDescripcion(string desc);
	void setDuracion(int dur);
	bool agregarEjercicio(Ejercicios* ejer);
	void listarEjercicios();
	void respuesta(int r);
	int getNumEjercicios();
	Cliente* getCliente();
	string getDescripcion();
	int getDuracion();
	Ejercicios* getEjercicio();
	string toString();
};

