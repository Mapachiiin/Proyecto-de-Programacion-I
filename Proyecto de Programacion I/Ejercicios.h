#pragma once
#include <iostream>
using namespace std;

class Ejercicios {
private:
    string pechoTric_[100];
    string biceps_[100];
    string piernas_[100];
    string espalda_[100];

    int numPechoTric_;
    int numBiceps_;
    int numPiernas_;
    int numEspalda_;

public:
    Ejercicios();
    int getNumPechoTric();
    int getNumBiceps();
    int getNumPiernas(); 
    int getNumEspalda(); 
    void listarPechoTric();
    void listarBiceps();
    void listarPiernas();
    void listarEspalda();
    string getPechoTric(int devo);
    string getBiceps(int devo);
    string getPiernas(int devo);
    string getEspalda(int devo);
    void agregarPechoTric(string& nombre);
    void agregarBiceps(string& nombre);
    void agregarPiernas(string& nombre);
    void agregarEspalda(string& nombre);   
    void eliPechoTric(int eli);
    void eliBiceps(int eli);
    void eliPiernas(int eli);
    void eliEspalda(int eli);
};