#pragma once
#include <iostream>
using namespace std;
class Especialidades{
private:
	string espe_[7];
	int tipo;
public:
	Especialidades();
	~Especialidades();
	void setEspecialidad();
	string getEspecialidad();
	
};