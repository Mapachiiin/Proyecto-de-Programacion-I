#pragma once
#include <iostream>
using namespace std;

class Ejercicio {
private:
    string nombre_;
public:
    Ejercicio(string& nombre);
    string toString();
};
