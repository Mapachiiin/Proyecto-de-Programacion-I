#pragma once
#include <iostream>
#include "Cliente.h"
#include "Ejercicios.h"
using namespace std;
class Rutina
{
private:
	Cliente* cliente_;
	string descripcion_;
	int duracion_;
	Ejercicios* ejercicios_[20];
};

