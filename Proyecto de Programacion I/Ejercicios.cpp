#include "Ejercicios.h"
#include <sstream>

Ejercicios::Ejercicios() {
    numPechoTric_ = 3;
    pechoTric_[0] = "Press banca";
    pechoTric_[1] = "Fondos en paralelas";
    pechoTric_[2] = "Aperturas con mancuernas";

    numBiceps_ = 2;
    biceps_[0] = "Curl con barra";
    biceps_[1] = "Curl martillo";

    numPiernas_ = 2;
    piernas_[0] = "Sentadillas";
    piernas_[1] = "Prensa de pierna";

    numEspalda_ = 2;
    espalda_[0] = "Dominadas";
    espalda_[1] = "Remo con barra";

}

void Ejercicios::listarPechoTric() {
    for (int i = 0; i < numPechoTric_; i++) {
        cout << i + 1 << ". " << pechoTric_[i] << endl;
    }
}
void Ejercicios::listarBiceps() {
    for (int i = 0; i < numBiceps_; i++) {
        cout << i + 1 << ". " << biceps_[i] << endl;
    }
}
void Ejercicios::listarPiernas() {
    for (int i = 0; i < numPiernas_; i++) {
        cout << i + 1 << ". " << piernas_[i] << endl;
    }
}
void Ejercicios::listarEspalda() {
    for (int i = 0; i < numEspalda_; i++) {
        cout << i + 1 << ". " << espalda_[i] << endl;
    }
}

string Ejercicios::getPechoTric(int devo) {
    if (devo >= 0 && devo < numPechoTric_) return pechoTric_[devo];
    return "";
}
string Ejercicios::getBiceps(int devo) {
    if (devo >= 0 && devo < numBiceps_) return biceps_[devo];
    return "";
}
string Ejercicios::getPiernas(int devo) {
    if (devo >= 0 && devo < numPiernas_) return piernas_[devo];
    return "";
}
string Ejercicios::getEspalda(int devo) {
    if (devo >= 0 && devo < numEspalda_) return espalda_[devo];
    return "";
}

void Ejercicios::agregarPechoTric(string& nombre) {
    if (numPechoTric_ < 100) {
        pechoTric_[numPechoTric_++] = nombre;
    }
}
void Ejercicios::agregarBiceps(string& nombre) {
    if (numBiceps_ < 100) {
        biceps_[numBiceps_++] = nombre;
    }
}
void Ejercicios::agregarPiernas(string& nombre) {
    if (numPiernas_ < 100) {
        piernas_[numPiernas_++] = nombre;
    }
}
void Ejercicios::agregarEspalda(string& nombre) {
    if (numEspalda_ < 100) {
        espalda_[numEspalda_++] = nombre;
    }
}

void Ejercicios::eliPechoTric(int eli) {
    if (eli >= 0 && eli < numPechoTric_) {
        for (int j = eli; j < numPechoTric_ - 1; j++) {
            pechoTric_[j] = pechoTric_[j + 1];
        }
        numPechoTric_--;
    }
}
void Ejercicios::eliBiceps(int eli) {
    if (eli >= 0 && eli < numBiceps_) {
        for (int j = eli; j < numBiceps_ - 1; j++) {
            biceps_[j] = biceps_[j + 1];
        }
        numBiceps_--;
    }
}
void Ejercicios::eliPiernas(int eli) {
    if (eli >= 0 && eli < numPiernas_) {
        for (int j = eli; j < numPiernas_ - 1; j++) {
            piernas_[j] = piernas_[j + 1];
        }
        numPiernas_--;
    }
}
void Ejercicios::eliEspalda(int eli) {
    if (eli >= 0 && eli < numEspalda_) {
        for (int j = eli; j < numEspalda_ - 1; j++) {
            espalda_[j] = espalda_[j + 1];
        }
        numEspalda_--;
    }
}
