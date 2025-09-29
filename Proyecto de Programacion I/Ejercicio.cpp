#include "Ejercicio.h"

Ejercicio::Ejercicio(string& name) {
	this->nombre_ = name;
}
string Ejercicio::toString() {
	return nombre_;
}