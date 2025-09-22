#include "Ejercicios.h"

Ejercicios::Ejercicios() {

}
Ejercicios::Ejercicios(int& maxEjer) {
	maxEjerPech_ = maxEjer;
	maxEjerBic_ = maxEjer;
	maxEjerPier_ = maxEjer;
	maxEjerEspal_ = maxEjer;

	numPechoTriceps_ = 0;
	numBiceps_ = 0;
	numPiernas_ = 0;
	numEspalda_ = 0;
	ejerPechoTriceps_ = new string[maxEjerPech_];
	ejerBiceps_ = new string[maxEjerBic_];
	ejerPiernas_ = new string[maxEjerPier_];
	ejerEspalda_ = new string[maxEjerEspal_];
}