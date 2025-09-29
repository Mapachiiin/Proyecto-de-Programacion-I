#include "Ejercicios.h"

Ejercicios::Ejercicios(int& maxEjer) {
	maxEjerPech_ = maxEjer;
	maxEjerBic_ = maxEjer;
	maxEjerPier_ = maxEjer;
	maxEjerEspal_ = maxEjer;

	numPechoTriceps_ = 0;
	numBiceps_ = 0;
	numPiernas_ = 0;
	numEspalda_ = 0;
	ejerPechTric_ = new string[maxEjerPech_];
	ejerBice_ = new string[maxEjerBic_];
	ejerPier_ = new string[maxEjerPier_];
	ejerEspal_ = new string[maxEjerEspal_];
}