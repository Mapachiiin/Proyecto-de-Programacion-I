#pragma once
#include <iostream>
using namespace std;

class Ejercicios
{
private:
    int maxEjercicios_;
    int numPechoTriceps_;
    int numBiceps_;
    int numPiernas_;
    int numEspalda_;
    int maxEjerPech_;
    int maxEjerBic_;
    int maxEjerPier_;
    int maxEjerEspal_;
    string* ejerPechTric_;
    string* ejerBice_;
    string* ejerPier_;
    string* ejerEspal_;

public:
    Ejercicios(int& maxEjer);
    ~Ejercicios();
    void agreEjerPecTric(const string& nombre);
    void agreEjerBice(const string& nombre);
    void agreEjerPier(const string& nombre);
    void agreEjerEspal(const string& nombre);
    void listEjerPecTric();
    void listEjercBic();
    void listEjerPier();
    void listEjerEspal();
    string getEjerPechoTriceps();
    string getEjerBiceps();
    string getEjerPiernas();
    string getEjerEspalda();
    int getNumPecTric();
    int getNumBic();
    int getNumPier();
    int getNumEspal();
    string toString();
};
