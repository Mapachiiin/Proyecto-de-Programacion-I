#pragma once
#include "Sucursal.h"
#include "Cliente.h"
#include "ClaseGrupal.h"

class Control;

class Quemados
{
private:
	Control* control_;
public:
	Quemados(Control* con);
	void IngreDatosQuemados();
};

