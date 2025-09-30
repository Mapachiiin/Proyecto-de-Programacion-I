#include "Quemados.h"
#include "Instructor.h"
#include "Sucursal.h"
#include "Control.h"
#include "Ejercicio.h"
#include <iostream>
using namespace std;

Quemados::Quemados(Control* control_) {
	this->control_ = control_;
}

void Quemados::IngreDatosQuemados() {

	Sucursal* sucursal = control_->buscarSucursal("SUC001");

	// ==================== INSTRUCTORES ====================

	Instructor* inst1 = new Instructor(119140155, "Fernando Aguilar", 74554322, "fernandez@gmail.com", "30/01/1988", 1);
	inst1->setEspecialidad(1);
	sucursal->agregarInstructor(inst1);
	Instructor* inst2 = new Instructor(208450999, "Maria Lopez", 88887777, "mlopez@gmail.com", "15/05/1990", 3);
	inst2->setEspecialidad(2);
	sucursal->agregarInstructor(inst2);
	Instructor* inst3 = new Instructor(305667123, "Carlos Jimenez", 89996666, "cjimenez@gmail.com", "20/09/1985", 2);
	inst3->setEspecialidad(3);
	sucursal->agregarInstructor(inst3);
	Instructor* inst4 = new Instructor(412334567, "Ana Rodriguez", 87775555, "arodriguez@gmail.com", "10/12/1992", 4);
	inst4->setEspecialidad(4);
	sucursal->agregarInstructor(inst4);
	Instructor* inst5 = new Instructor(523456789, "Luis Herrera", 86664444, "lherrera@gmail.com", "05/07/1980", 5);
	inst5->setEspecialidad(5);
	sucursal->agregarInstructor(inst5);

	// ==================== CLIENTES ====================

	string ejer1n = "Saltos";
	Cliente* c1 = new Cliente("Elias", 121383329, 87278865, "eMati@gmail.com", "02/12/2000", 'H', "20/04/2024", 0, inst1);
	sucursal->agregarCliente(c1);
	ReporteMedicion* repo1 = new ReporteMedicion(*c1, "15/08/2025", 72.5, 1.80, 14.8, 42.0, 23, 9.5, 82.0, 95.0, 100.0, 58.0, false);
	c1->agregarReporte(*repo1);
	Rutina* rutina1 = new Rutina(c1, "descripcion", 60, 10);
	Ejercicio* ejer1 = new Ejercicio (ejer1n);
	rutina1->agregarEjercicio(ejer1);
	c1->asignarRutina(rutina1);

	string ejer2n = "Sentadillas";
	Cliente* c2 = new Cliente("Sofia", 221383330, 88884444, "sofia@gmail.com", "11/03/1998", 'M', "21/04/2024", 0, inst2);
	sucursal->agregarCliente(c2);
	ReporteMedicion* repo2 = new ReporteMedicion(*c2, "15/08/2025", 60.0, 1.65, 20.5, 35.0, 27, 8.0, 70.0, 95.0, 90.0, 55.0, true);
	c2->agregarReporte(*repo2);
	Rutina* rutina2 = new Rutina(c2, "Rutina general de tonificación", 50, 8);
	Ejercicio* ejer2 = new Ejercicio(ejer2n);
	rutina2->agregarEjercicio(ejer2);
	c2->asignarRutina(rutina2);

	string ejer3n = "Press banca";
	Cliente* c3 = new Cliente("Andres", 321383331, 87776666, "andres@gmail.com", "25/07/1995", 'H', "22/04/2024", 0, inst3);
	sucursal->agregarCliente(c3);
	ReporteMedicion* repo3 = new ReporteMedicion(*c3, "15/08/2025", 80.0, 1.82, 16.0, 40.0, 28, 10.0, 85.0, 98.0, 105.0, 60.0, true);
	c3->agregarReporte(*repo3);
	Rutina* rutina3 = new Rutina(c3, "Rutina de fuerza avanzada", 70, 10);
	Ejercicio* ejer3 = new Ejercicio(ejer3n);
	rutina3->agregarEjercicio(ejer3);
	c3->asignarRutina(rutina3);

	string ejer4n = "Plancha";
	Cliente* c4 = new Cliente("Valeria", 421383332, 89997777, "valeria@gmail.com", "30/08/1999", 'M', "23/04/2024", 0, inst4);
	sucursal->agregarCliente(c4);
	ReporteMedicion* repo4 = new ReporteMedicion(*c4, "15/08/2025", 55.0, 1.62, 19.0, 36.0, 25, 7.5, 68.0, 92.0, 88.0, 53.0, true);
	c4->agregarReporte(*repo4);
	Rutina* rutina4 = new Rutina(c4, "Rutina de resistencia", 45, 7);
	Ejercicio* ejer4 = new Ejercicio(ejer4n);
	rutina4->agregarEjercicio(ejer4);
	c4->asignarRutina(rutina4);

	string ejer5n = "Peso muerto";
	Cliente* c5 = new Cliente("Mateo", 521383333, 86665555, "mateo@gmail.com", "14/01/2001", 'H', "24/04/2024", 0, inst5);
	sucursal->agregarCliente(c5);
	ReporteMedicion* repo5 = new ReporteMedicion(*c5, "15/08/2025", 70.0, 1.75, 15.5, 41.0, 22, 9.0, 80.0, 94.0, 98.0, 57.0, true);
	c5->agregarReporte(*repo5);
	Rutina* rutina5 = new Rutina(c5, "Rutina de potencia", 60, 9);
	Ejercicio* ejer5 = new Ejercicio(ejer5n);
	rutina5->agregarEjercicio(ejer5);
	c5->asignarRutina(rutina5);

	string ejer6n = "Zancadas";
	Cliente* c6 = new Cliente("Camila", 621383334, 85554444, "camila@gmail.com", "09/06/1997", 'M', "25/04/2024", 0, inst1);
	sucursal->agregarCliente(c6);
	ReporteMedicion* repo6 = new ReporteMedicion(*c6, "15/08/2025", 58.0, 1.68, 21.0, 34.0, 26, 8.5, 72.0, 94.0, 89.0, 54.0, true);
	c6->agregarReporte(*repo6);
	Rutina* rutina6 = new Rutina(c6, "Rutina de tonificación", 50, 8);
	Ejercicio* ejer6 = new Ejercicio(ejer6n);
	rutina6->agregarEjercicio(ejer6);
	c6->asignarRutina(rutina6);

	string ejer7n = "Dominadas";
	Cliente* c7 = new Cliente("Daniel", 721383335, 84443333, "daniel@gmail.com", "18/11/1996", 'H', "26/04/2024", 0, inst2);
	sucursal->agregarCliente(c7);
	ReporteMedicion* repo7 = new ReporteMedicion(*c7, "15/08/2025", 78.0, 1.80, 17.0, 39.0, 27, 9.8, 84.0, 97.0, 102.0, 59.0, false);
	c7->agregarReporte(*repo7);
	Rutina* rutina7 = new Rutina(c7, "Rutina de fuerza intermedia", 65, 9);
	Ejercicio* ejer7 = new Ejercicio(ejer7n);
	rutina7->agregarEjercicio(ejer7);
	c7->asignarRutina(rutina7);

	string ejer8n = "Abdominales";
	Cliente* c8 = new Cliente("Isabella", 821383336, 83332222, "isabella@gmail.com", "05/02/2002", 'M', "27/04/2024", 0, inst3);
	sucursal->agregarCliente(c8);
	ReporteMedicion* repo8 = new ReporteMedicion(*c8, "15/08/2025", 54.0, 1.60, 18.5, 37.0, 21, 7.0, 66.0, 90.0, 85.0, 52.0, false);
	c8->agregarReporte(*repo8);
	Rutina* rutina8 = new Rutina(c8, "Rutina básica", 40, 6);
	Ejercicio* ejer8 = new Ejercicio(ejer8n);
	rutina8->agregarEjercicio(ejer8);
	c8->asignarRutina(rutina8);

	string ejer9n = "Press militar";
	Cliente* c9 = new Cliente("Gabriel", 921383337, 82221111, "gabriel@gmail.com", "12/04/1994", 'H', "28/04/2024", 0, inst4);
	sucursal->agregarCliente(c9);
	ReporteMedicion* repo9 = new ReporteMedicion(*c9, "15/08/2025", 85.0, 1.85, 18.0, 38.0, 30, 11.0, 88.0, 100.0, 108.0, 62.0, false);
	c9->agregarReporte(*repo9);
	Rutina* rutina9 = new Rutina(c9, "Rutina avanzada", 75, 10);
	Ejercicio* ejer9 = new Ejercicio(ejer9n);
	rutina9->agregarEjercicio(ejer9);
	c9->asignarRutina(rutina9);

	string ejer10n = "Burpees";
	Cliente* c10 = new Cliente("Lucia", 1021383338, 81110000, "lucia@gmail.com", "01/10/1993", 'M', "29/04/2024", 0, inst5);
	sucursal->agregarCliente(c10);
	ReporteMedicion* repo10 = new ReporteMedicion(*c10, "15/08/2025", 62.0, 1.70, 22.0, 33.0, 29, 9.2, 74.0, 96.0, 92.0, 56.0, true);
	c10->agregarReporte(*repo10);
	Rutina* rutina10 = new Rutina(c10, "Rutina de cardio y fuerza", 55, 8);
	Ejercicio* ejer10 = new Ejercicio(ejer10n);
	rutina10->agregarEjercicio(ejer10);
	c10->asignarRutina(rutina10);

	// ==================== CLASES GRUPALES ====================

	ClaseGrupal* clase1 = new ClaseGrupal(1, 0, 30, sucursal, inst1, "10:00am", 1);
	sucursal->agregarClaseGrupal(clase1);
	clase1->insCliente(c1);
	clase1->insCliente(c2);
	clase1->insCliente(c3);
	clase1->insCliente(c4);
	clase1->insCliente(c9);
	
	ClaseGrupal* clase2 = new ClaseGrupal(2, 0, 25, sucursal, inst3, "6:00pm", 2);
	sucursal->agregarClaseGrupal(clase2);
	clase2->insCliente(c5);
	clase2->insCliente(c6);
	clase2->insCliente(c7);
	clase2->insCliente(c8);
	

	// ==================== SUCURSAL 2 ====================

	Sucursal* sucursal2 = control_->buscarSucursal("SUC002");

	// ==================== INSTRUCTORES ====================

	Instructor* inst6 = new Instructor(634512789, "Paola Martinez", 75553322, "pmartinez@gmail.com", "12/04/1987", 2);
	inst6->setEspecialidad(1);
	sucursal2->agregarInstructor(inst6);
	Instructor* inst7 = new Instructor(745623890, "Jorge Ramirez", 76664455, "jramirez@gmail.com", "03/09/1991", 3);
	inst7->setEspecialidad(4);
	sucursal2->agregarInstructor(inst7);
	Instructor* inst8 = new Instructor(856734901, "Laura Torres", 74442211, "ltorres@gmail.com", "25/11/1989", 1);
	inst8->setEspecialidad(2);
	sucursal2->agregarInstructor(inst8);
	Instructor* inst9 = new Instructor(967845012, "Diego Castro", 73331100, "dcastro@gmail.com", "14/06/1984", 2);
	inst9->setEspecialidad(5);
	sucursal2->agregarInstructor(inst9);
	Instructor* inst10 = new Instructor(178945623, "Andrea Vega", 72221199, "avega@gmail.com", "02/03/1992", 4);
	inst10->setEspecialidad(3);
	sucursal2->agregarInstructor(inst10);

	// ==================== CLIENTES ====================

	Cliente* c11 = new Cliente("Mariana", 112233445, 89991122, "mariana@gmail.com", "07/07/1999", 'M', "01/05/2024", 0, inst6);
	sucursal2->agregarCliente(c11);
	Cliente* c12 = new Cliente("Ricardo", 223344556, 87776655, "ricardo@gmail.com", "19/02/1996", 'H', "02/05/2024", 0, inst7);
	sucursal2->agregarCliente(c12);
	Cliente* c13 = new Cliente("Julieta", 334455667, 82223344, "julieta@gmail.com", "28/01/1997", 'M', "03/05/2024", 0, inst8);
	sucursal2->agregarCliente(c13);
	Cliente* c14 = new Cliente("Sebastian", 445566778, 81112233, "sebastian@gmail.com", "10/10/1995", 'H', "04/05/2024", 0, inst9);
	sucursal2->agregarCliente(c14);
	Cliente* c15 = new Cliente("Natalia", 556677889, 87770011, "natalia@gmail.com", "05/12/1998", 'M', "05/05/2024", 0, inst10);
	sucursal2->agregarCliente(c15);
	Cliente* c16 = new Cliente("Pablo", 667788990, 86669922, "pablo@gmail.com", "21/09/1994", 'H', "06/05/2024", 0, inst6);
	sucursal2->agregarCliente(c16);
	Cliente* c17 = new Cliente("Esteban", 778899001, 85558877, "esteban@gmail.com", "13/04/1993", 'H', "07/05/2024", 0, inst7);
	sucursal2->agregarCliente(c17);
	Cliente* c18 = new Cliente("Carolina", 889900112, 84447766, "carolina@gmail.com", "29/06/2000", 'M', "08/05/2024", 0, inst8);
	sucursal2->agregarCliente(c18);
	Cliente* c19 = new Cliente("Felipe", 990011223, 83336655, "felipe@gmail.com", "16/08/1997", 'H', "09/05/2024", 0, inst9);
	sucursal2->agregarCliente(c19);
	Cliente* c20 = new Cliente("Daniela", 101122334, 82225544, "daniela@gmail.com", "04/01/1995", 'M', "10/05/2024", 0, inst10);
	sucursal2->agregarCliente(c20);

	// ==================== CLASES GRUPALES ====================

	ClaseGrupal* clase3 = new ClaseGrupal(3, 0, 20, sucursal2, inst6, "8:00am", 3);
	sucursal2->agregarClaseGrupal(clase3);
	ClaseGrupal* clase4 = new ClaseGrupal(4, 0, 15, sucursal2, inst7, "7:00pm", 2);
	sucursal2->agregarClaseGrupal(clase4);
	ClaseGrupal* clase5 = new ClaseGrupal(5, 0, 18, sucursal2, inst8, "9:30am", 1);
	sucursal2->agregarClaseGrupal(clase5);
	ClaseGrupal* clase6 = new ClaseGrupal(6, 0, 22, sucursal2, inst9, "5:30pm", 4);
	sucursal2->agregarClaseGrupal(clase6);
	ClaseGrupal* clase7 = new ClaseGrupal(7, 0, 28, sucursal2, inst10, "11:00am", 5);
	sucursal2->agregarClaseGrupal(clase7);

	// ==================== SUCURSAL 3 ====================

	Sucursal* sucursal3 = control_->buscarSucursal("SUC003");

	// ==================== INSTRUCTORES ====================

	Instructor* inst11 = new Instructor(311223344, "Sergio Alvarez", 79998877, "salvarez@gmail.com", "08/05/1983", 1);
	inst11->setEspecialidad(2);
	sucursal3->agregarInstructor(inst11);
	Instructor* inst12 = new Instructor(422334455, "Monica Herrera", 78887766, "mherrera@gmail.com", "19/02/1990", 2);
	inst12->setEspecialidad(5);
	sucursal3->agregarInstructor(inst12);
	Instructor* inst13 = new Instructor(533445566, "Raul Gutierrez", 77776655, "rgutierrez@gmail.com", "23/11/1986", 3);
	inst13->setEspecialidad(3);
	sucursal3->agregarInstructor(inst13);
	Instructor* inst14 = new Instructor(644556677, "Patricia Rojas", 76665544, "projas@gmail.com", "30/07/1992", 4);
	inst14->setEspecialidad(1);
	sucursal3->agregarInstructor(inst14);
	Instructor* inst15 = new Instructor(755667788, "Hector Molina", 75554433, "hmolina@gmail.com", "11/01/1988", 5);
	inst15->setEspecialidad(4);
	sucursal3->agregarInstructor(inst15);

	// ==================== CLIENTES ====================

	Cliente* c21 = new Cliente("Alejandro", 212121212, 84443322, "alejandro@gmail.com", "15/09/1997", 'H', "11/05/2024", 0, inst11);
	sucursal3->agregarCliente(c21);
	Cliente* c22 = new Cliente("Fernanda", 323232323, 83332211, "fernanda@gmail.com", "02/12/1996", 'M', "12/05/2024", 0, inst12);
	sucursal3->agregarCliente(c22);
	Cliente* c23 = new Cliente("Rodrigo", 434343434, 82221100, "rodrigo@gmail.com", "27/03/1995", 'H', "13/05/2024", 0, inst13);
	sucursal3->agregarCliente(c23);
	Cliente* c24 = new Cliente("Claudia", 545454545, 81110099, "claudia@gmail.com", "09/08/1998", 'M', "14/05/2024", 0, inst14);
	sucursal3->agregarCliente(c24);
	Cliente* c25 = new Cliente("Mauricio", 656565656, 80009988, "mauricio@gmail.com", "21/06/1993", 'H', "15/05/2024", 0, inst15);
	sucursal3->agregarCliente(c25);
	Cliente* c26 = new Cliente("Angela", 767676767, 89998877, "angela@gmail.com", "04/04/1999", 'M', "16/05/2024", 0, inst11);
	sucursal3->agregarCliente(c26);
	Cliente* c27 = new Cliente("Cristian", 878787878, 88887766, "cristian@gmail.com", "12/10/1994", 'H', "17/05/2024", 0, inst12);
	sucursal3->agregarCliente(c27);
	Cliente* c28 = new Cliente("Veronica", 989898989, 87776655, "veronica@gmail.com", "06/01/2000", 'M', "18/05/2024", 0, inst13);
	sucursal3->agregarCliente(c28);
	Cliente* c29 = new Cliente("Javier", 101010101, 86665544, "javier@gmail.com", "29/07/1996", 'H', "19/05/2024", 0, inst14);
	sucursal3->agregarCliente(c29);
	Cliente* c30 = new Cliente("Liliana", 202020202, 85554433, "liliana@gmail.com", "18/11/1995", 'M', "20/05/2024", 0, inst15);
	sucursal3->agregarCliente(c30);

	// ==================== CLASES GRUPALES ====================

	ClaseGrupal* clase8 = new ClaseGrupal(8, 0, 25, sucursal3, inst11, "7:00am", 2);
	sucursal3->agregarClaseGrupal(clase8);
	ClaseGrupal* clase9 = new ClaseGrupal(9, 0, 20, sucursal3, inst12, "6:00pm", 3);
	sucursal3->agregarClaseGrupal(clase9);
	ClaseGrupal* clase10 = new ClaseGrupal(10, 0, 30, sucursal3, inst13, "10:30am", 1);
	sucursal3->agregarClaseGrupal(clase10);
	ClaseGrupal* clase11 = new ClaseGrupal(11, 0, 18, sucursal3, inst14, "5:00pm", 4);
	sucursal3->agregarClaseGrupal(clase11);
	ClaseGrupal* clase12 = new ClaseGrupal(12, 0, 22, sucursal3, inst15, "8:00pm", 5);
	sucursal3->agregarClaseGrupal(clase12);

	// ==================== SUCURSAL 4 ====================

	Sucursal* sucursal4 = control_->buscarSucursal("SUC004");

	// ==================== INSTRUCTORES ====================

	Instructor* inst16 = new Instructor(366112233, "Gabriela Soto", 74445566, "gsoto@gmail.com", "22/07/1989", 1);
	inst16->setEspecialidad(3);
	sucursal4->agregarInstructor(inst16);
	Instructor* inst17 = new Instructor(477223344, "Manuel Ortega", 73334455, "mortega@gmail.com", "05/01/1985", 2);
	inst17->setEspecialidad(1);
	sucursal4->agregarInstructor(inst17);
	Instructor* inst18 = new Instructor(588334455, "Silvia Vargas", 72223344, "svargas@gmail.com", "18/09/1993", 3);
	inst18->setEspecialidad(4);
	sucursal4->agregarInstructor(inst18);
	Instructor* inst19 = new Instructor(699445566, "Alberto Reyes", 71112233, "areyes@gmail.com", "30/04/1987", 4);
	inst19->setEspecialidad(2);
	sucursal4->agregarInstructor(inst19);
	Instructor* inst20 = new Instructor(811556677, "Clara Mendoza", 70001122, "cmendoza@gmail.com", "12/12/1991", 5);
	inst20->setEspecialidad(5);
	sucursal4->agregarInstructor(inst20);

	// ==================== CLIENTES ====================

	Cliente* c31 = new Cliente("Ignacio", 303030303, 85553322, "ignacio@gmail.com", "09/02/1996", 'H', "21/05/2024", 0, inst16);
	sucursal4->agregarCliente(c31);
	Cliente* c32 = new Cliente("Rosa", 404040404, 84442211, "rosa@gmail.com", "14/08/1997", 'M', "22/05/2024", 0, inst17);
	sucursal4->agregarCliente(c32);
	Cliente* c33 = new Cliente("Martin", 505050505, 83331100, "martin@gmail.com", "27/03/1995", 'H', "23/05/2024", 0, inst18);
	sucursal4->agregarCliente(c33);
	Cliente* c34 = new Cliente("Teresa", 606060606, 82220099, "teresa@gmail.com", "01/06/1998", 'M', "24/05/2024", 0, inst19);
	sucursal4->agregarCliente(c34);
	Cliente* c35 = new Cliente("Hugo", 707070707, 81119988, "hugo@gmail.com", "19/11/1994", 'H', "25/05/2024", 0, inst20);
	sucursal4->agregarCliente(c35);
	Cliente* c36 = new Cliente("Beatriz", 808080808, 80008877, "beatriz@gmail.com", "03/05/1999", 'M', "26/05/2024", 0, inst16);
	sucursal4->agregarCliente(c36);
	Cliente* c37 = new Cliente("Oscar", 909090909, 89997766, "oscar@gmail.com", "22/01/1993", 'H', "27/05/2024", 0, inst17);
	sucursal4->agregarCliente(c37);
	Cliente* c38 = new Cliente("Lorena", 111111111, 88886655, "lorena@gmail.com", "07/10/1996", 'M', "28/05/2024", 0, inst18);
	sucursal4->agregarCliente(c38);
	Cliente* c39 = new Cliente("Marcos", 222222222, 87775544, "marcos@gmail.com", "25/04/1992", 'H', "29/05/2024", 0, inst19);
	sucursal4->agregarCliente(c39);
	Cliente* c40 = new Cliente("Elena", 333333333, 86664433, "elena@gmail.com", "16/07/1995", 'M', "30/05/2024", 0, inst20);
	sucursal4->agregarCliente(c40);

	// ==================== CLASES GRUPALES ====================

	ClaseGrupal* clase13 = new ClaseGrupal(13, 0, 26, sucursal4, inst16, "6:30am", 1);
	sucursal4->agregarClaseGrupal(clase13);
	ClaseGrupal* clase14 = new ClaseGrupal(14, 0, 20, sucursal4, inst17, "9:00am", 2);
	sucursal4->agregarClaseGrupal(clase14);
	ClaseGrupal* clase15 = new ClaseGrupal(15, 0, 18, sucursal4, inst18, "4:00pm", 3);
	sucursal4->agregarClaseGrupal(clase15);
	ClaseGrupal* clase16 = new ClaseGrupal(16, 0, 24, sucursal4, inst19, "6:00pm", 4);
	sucursal4->agregarClaseGrupal(clase16);
	ClaseGrupal* clase17 = new ClaseGrupal(17, 0, 28, sucursal4, inst20, "8:00pm", 5);
	sucursal4->agregarClaseGrupal(clase17);

	// ==================== SUCURSAL 5 ====================

	Sucursal* sucursal5 = control_->buscarSucursal("SUC005");

	// ==================== INSTRUCTORES ====================

	Instructor* inst21 = new Instructor(912345678, "Sofia Delgado", 75556677, "sdelgado@gmail.com", "14/02/1986", 1);
	inst21->setEspecialidad(2);
	sucursal5->agregarInstructor(inst21);
	Instructor* inst22 = new Instructor(923456789, "Andres Pineda", 74445533, "apineda@gmail.com", "09/11/1988", 2);
	inst22->setEspecialidad(4);
	sucursal5->agregarInstructor(inst22);
	Instructor* inst23 = new Instructor(934567890, "Camila Suarez", 73334422, "csuarez@gmail.com", "27/06/1991", 3);
	inst23->setEspecialidad(1);
	sucursal5->agregarInstructor(inst23);
	Instructor* inst24 = new Instructor(945678901, "Felipe Navarro", 72223311, "fnavarro@gmail.com", "05/03/1984", 4);
	inst24->setEspecialidad(5);
	sucursal5->agregarInstructor(inst24);
	Instructor* inst25 = new Instructor(956789012, "Daniela Flores", 71112200, "dflores@gmail.com", "30/08/1993", 5);
	inst25->setEspecialidad(3);
	sucursal5->agregarInstructor(inst25);

	// ==================== CLIENTES ====================

	Cliente* c41 = new Cliente("Emilio", 444444444, 85557766, "emilio@gmail.com", "12/04/1997", 'H', "01/06/2024", 0, inst21);
	sucursal5->agregarCliente(c41);
	Cliente* c42 = new Cliente("Valentina", 555555555, 84446655, "valentina@gmail.com", "23/09/1996", 'M', "02/06/2024", 0, inst22);
	sucursal5->agregarCliente(c42);
	Cliente* c43 = new Cliente("Gonzalo", 666666666, 83335544, "gonzalo@gmail.com", "08/01/1995", 'H', "03/06/2024", 0, inst23);
	sucursal5->agregarCliente(c43);
	Cliente* c44 = new Cliente("Renata", 777777777, 82224433, "renata@gmail.com", "19/07/1998", 'M', "04/06/2024", 0, inst24);
	sucursal5->agregarCliente(c44);
	Cliente* c45 = new Cliente("Tomas", 888888888, 81113322, "tomas@gmail.com", "06/05/1994", 'H', "05/06/2024", 0, inst25);
	sucursal5->agregarCliente(c45);
	Cliente* c46 = new Cliente("Luciana", 999999999, 80002211, "luciana2@gmail.com", "28/02/1999", 'M', "06/06/2024", 0, inst21);
	sucursal5->agregarCliente(c46);
	Cliente* c47 = new Cliente("Mariano", 121212121, 89991100, "mariano@gmail.com", "15/10/1993", 'H', "07/06/2024", 0, inst22);
	sucursal5->agregarCliente(c47);
	Cliente* c48 = new Cliente("Florencia", 232323232, 88880099, "florencia@gmail.com", "11/12/1997", 'M', "08/06/2024", 0, inst23);
	sucursal5->agregarCliente(c48);
	Cliente* c49 = new Cliente("Alonso", 343434343, 87779988, "alonso@gmail.com", "04/09/1995", 'H', "09/06/2024", 0, inst24);
	sucursal5->agregarCliente(c49);
	Cliente* c50 = new Cliente("Catalina", 454545454, 86668877, "catalina@gmail.com", "21/01/1996", 'M', "10/06/2024", 0, inst25);
	sucursal5->agregarCliente(c50);

	// ==================== CLASES GRUPALES ====================

	ClaseGrupal* clase18 = new ClaseGrupal(18, 0, 20, sucursal5, inst21, "7:00am", 1);
	sucursal5->agregarClaseGrupal(clase18);
	ClaseGrupal* clase19 = new ClaseGrupal(19, 0, 25, sucursal5, inst22, "9:00am", 2);
	sucursal5->agregarClaseGrupal(clase19);
	ClaseGrupal* clase20 = new ClaseGrupal(20, 0, 18, sucursal5, inst23, "11:00am", 3);
	sucursal5->agregarClaseGrupal(clase20);
	ClaseGrupal* clase21 = new ClaseGrupal(21, 0, 22, sucursal5, inst24, "1:00pm", 4);
	sucursal5->agregarClaseGrupal(clase21);
	ClaseGrupal* clase22 = new ClaseGrupal(22, 0, 28, sucursal5, inst25, "3:00pm", 5);
	sucursal5->agregarClaseGrupal(clase22);
	ClaseGrupal* clase23 = new ClaseGrupal(23, 0, 24, sucursal5, inst21, "5:00pm", 2);
	sucursal5->agregarClaseGrupal(clase23);
	ClaseGrupal* clase24 = new ClaseGrupal(24, 0, 30, sucursal5, inst22, "7:00pm", 4);
	sucursal5->agregarClaseGrupal(clase24);

	// ==================== SUCURSAL 6 ====================

	Sucursal* sucursal6 = control_->buscarSucursal("SUC006");

	// ==================== INSTRUCTORES ====================

	Instructor* inst26 = new Instructor(967890123, "Marisol Cabrera", 75559911, "mcabrera@gmail.com", "03/07/1987", 1);
	inst26->setEspecialidad(4);
	sucursal6->agregarInstructor(inst26);
	Instructor* inst27 = new Instructor(978901234, "Javier Dominguez", 74448822, "jdominguez@gmail.com", "21/10/1985", 2);
	inst27->setEspecialidad(2);
	sucursal6->agregarInstructor(inst27);
	Instructor* inst28 = new Instructor(989012345, "Paula Estrada", 73337733, "pestrada@gmail.com", "16/01/1992", 3);
	inst28->setEspecialidad(5);
	sucursal6->agregarInstructor(inst28);
	Instructor* inst29 = new Instructor(990123456, "Rodrigo Salas", 72226644, "rsalas@gmail.com", "08/09/1989", 4);
	inst29->setEspecialidad(1);
	sucursal6->agregarInstructor(inst29);
	Instructor* inst30 = new Instructor(901234567, "Natalia Fuentes", 71115555, "nfuentes@gmail.com", "25/05/1990", 5);
	inst30->setEspecialidad(3);
	sucursal6->agregarInstructor(inst30);

	// ==================== CLIENTES ====================

	Cliente* c51 = new Cliente("Adrian", 565656565, 85551122, "adrian@gmail.com", "14/03/1996", 'H', "11/06/2024", 0, inst26);
	sucursal6->agregarCliente(c51);
	Cliente* c52 = new Cliente("Gabriela", 676767676, 84440011, "gabriela2@gmail.com", "09/12/1997", 'M', "12/06/2024", 0, inst27);
	sucursal6->agregarCliente(c52);
	Cliente* c53 = new Cliente("Leonardo", 787878787, 83339900, "leonardo@gmail.com", "22/08/1995", 'H', "13/06/2024", 0, inst28);
	sucursal6->agregarCliente(c53);
	Cliente* c54 = new Cliente("Marta", 898989898, 82228899, "marta@gmail.com", "05/04/1998", 'M', "14/06/2024", 0, inst29);
	sucursal6->agregarCliente(c54);
	Cliente* c55 = new Cliente("Rafael", 909191919, 81117788, "rafael@gmail.com", "30/11/1994", 'H', "15/06/2024", 0, inst30);
	sucursal6->agregarCliente(c55);
	Cliente* c56 = new Cliente("Patricia", 121314151, 80006677, "patricia@gmail.com", "18/01/1999", 'M', "16/06/2024", 0, inst26);
	sucursal6->agregarCliente(c56);
	Cliente* c57 = new Cliente("Hernan", 232425262, 89995566, "hernan@gmail.com", "07/07/1993", 'H', "17/06/2024", 0, inst27);
	sucursal6->agregarCliente(c57);
	Cliente* c58 = new Cliente("Rocio", 343536373, 88884455, "rocio@gmail.com", "26/02/1996", 'M', "18/06/2024", 0, inst28);
	sucursal6->agregarCliente(c58);
	Cliente* c59 = new Cliente("Mateo", 454647484, 87773344, "mateo2@gmail.com", "11/09/1997", 'H', "19/06/2024", 0, inst29);
	sucursal6->agregarCliente(c59);
	Cliente* c60 = new Cliente("Carla", 565758596, 86662233, "carla@gmail.com", "02/06/1995", 'M', "20/06/2024", 0, inst30);
	sucursal6->agregarCliente(c60);

	// ==================== CLASES GRUPALES ====================

	ClaseGrupal* clase25 = new ClaseGrupal(25, 0, 20, sucursal6, inst26, "6:00am", 1);
	sucursal6->agregarClaseGrupal(clase25);
	ClaseGrupal* clase26 = new ClaseGrupal(26, 0, 28, sucursal6, inst27, "8:00am", 2);
	sucursal6->agregarClaseGrupal(clase26);
	ClaseGrupal* clase27 = new ClaseGrupal(27, 0, 24, sucursal6, inst28, "10:00am", 3);
	sucursal6->agregarClaseGrupal(clase27);
	ClaseGrupal* clase28 = new ClaseGrupal(28, 0, 18, sucursal6, inst29, "2:00pm", 4);
	sucursal6->agregarClaseGrupal(clase28);
	ClaseGrupal* clase29 = new ClaseGrupal(29, 0, 22, sucursal6, inst30, "5:00pm", 5);
	sucursal6->agregarClaseGrupal(clase29);
	ClaseGrupal* clase30 = new ClaseGrupal(30, 0, 30, sucursal6, inst27, "7:00pm", 2);
	sucursal6->agregarClaseGrupal(clase30);

	// ==================== SUCURSAL 7 ====================

	Sucursal* sucursal7 = control_->buscarSucursal("SUC007");

	// ==================== INSTRUCTORES ====================

	Instructor* inst31 = new Instructor(912301111, "Claudio Ramirez", 75550011, "cramirez@gmail.com", "10/02/1984", 1);
	inst31->setEspecialidad(2);
	sucursal7->agregarInstructor(inst31);
	Instructor* inst32 = new Instructor(923402222, "Marcela Ortiz", 74441122, "mortiz@gmail.com", "25/07/1989", 2);
	inst32->setEspecialidad(5);
	sucursal7->agregarInstructor(inst32);
	Instructor* inst33 = new Instructor(934503333, "Esteban Silva", 73332233, "esilva@gmail.com", "13/11/1991", 3);
	inst33->setEspecialidad(3);
	sucursal7->agregarInstructor(inst33);
	Instructor* inst34 = new Instructor(945604444, "Patricia Lopez", 72223344, "plopez@gmail.com", "06/05/1987", 4);
	inst34->setEspecialidad(1);
	sucursal7->agregarInstructor(inst34);
	Instructor* inst35 = new Instructor(956705555, "Gustavo Herrera", 71114455, "gherrera@gmail.com", "19/09/1990", 5);
	inst35->setEspecialidad(4);
	sucursal7->agregarInstructor(inst35);

	// ==================== CLIENTES ====================

	Cliente* c61 = new Cliente("Santiago", 565600001, 85550022, "santiago@gmail.com", "04/03/1996", 'H', "21/06/2024", 0, inst31);
	sucursal7->agregarCliente(c61);
	Cliente* c62 = new Cliente("Camila", 676700002, 84441133, "camila2@gmail.com", "15/08/1997", 'M', "22/06/2024", 0, inst32);
	sucursal7->agregarCliente(c62);
	Cliente* c63 = new Cliente("Nicolas", 787800003, 83332244, "nicolas@gmail.com", "28/01/1995", 'H', "23/06/2024", 0, inst33);
	sucursal7->agregarCliente(c63);
	Cliente* c64 = new Cliente("Valeria", 898900004, 82223355, "valeria2@gmail.com", "09/06/1998", 'M', "24/06/2024", 0, inst34);
	sucursal7->agregarCliente(c64);
	Cliente* c65 = new Cliente("Julian", 909100005, 81114466, "julian@gmail.com", "30/12/1994", 'H', "25/06/2024", 0, inst35);
	sucursal7->agregarCliente(c65);
	Cliente* c66 = new Cliente("Paola", 121310006, 80005577, "paola@gmail.com", "17/04/1999", 'M', "26/06/2024", 0, inst31);
	sucursal7->agregarCliente(c66);
	Cliente* c67 = new Cliente("Cristobal", 232420007, 89996688, "cristobal@gmail.com", "11/10/1993", 'H', "27/06/2024", 0, inst32);
	sucursal7->agregarCliente(c67);
	Cliente* c68 = new Cliente("Isidora", 343530008, 88887799, "isidora@gmail.com", "05/02/1996", 'M', "28/06/2024", 0, inst33);
	sucursal7->agregarCliente(c68);
	Cliente* c69 = new Cliente("Benjamin", 454640009, 87778800, "benjamin@gmail.com", "22/07/1997", 'H', "29/06/2024", 0, inst34);
	sucursal7->agregarCliente(c69);
	Cliente* c70 = new Cliente("Josefina", 565750010, 86669911, "josefina@gmail.com", "14/09/1995", 'M', "30/06/2024", 0, inst35);
	sucursal7->agregarCliente(c70);

	// ==================== CLASES GRUPALES ====================

	ClaseGrupal* clase31 = new ClaseGrupal(31, 0, 20, sucursal7, inst31, "6:00am", 1);
	sucursal7->agregarClaseGrupal(clase31);
	ClaseGrupal* clase32 = new ClaseGrupal(32, 0, 25, sucursal7, inst32, "8:00am", 2);
	sucursal7->agregarClaseGrupal(clase32);
	ClaseGrupal* clase33 = new ClaseGrupal(33, 0, 18, sucursal7, inst33, "10:00am", 3);
	sucursal7->agregarClaseGrupal(clase33);
	ClaseGrupal* clase34 = new ClaseGrupal(34, 0, 22, sucursal7, inst34, "12:00pm", 4);
	sucursal7->agregarClaseGrupal(clase34);
	ClaseGrupal* clase35 = new ClaseGrupal(35, 0, 28, sucursal7, inst35, "2:00pm", 5);
	sucursal7->agregarClaseGrupal(clase35);
	ClaseGrupal* clase36 = new ClaseGrupal(36, 0, 24, sucursal7, inst31, "4:00pm", 2);
	sucursal7->agregarClaseGrupal(clase36);
	ClaseGrupal* clase37 = new ClaseGrupal(37, 0, 30, sucursal7, inst32, "6:00pm", 3);
	sucursal7->agregarClaseGrupal(clase37);
	ClaseGrupal* clase38 = new ClaseGrupal(38, 0, 26, sucursal7, inst33, "8:00pm", 4);
	sucursal7->agregarClaseGrupal(clase38);

	// ==================== SUCURSAL 8 ====================

	Sucursal* sucursal8 = control_->buscarSucursal("SUC008");

	// ==================== INSTRUCTORES ====================

	Instructor* inst36 = new Instructor(912308888, "Lorena Castillo", 75558822, "lcastillo@gmail.com", "07/03/1988", 1);
	inst36->setEspecialidad(3);
	sucursal8->agregarInstructor(inst36);
	Instructor* inst37 = new Instructor(923409999, "Mauricio Peña", 74447733, "mpena@gmail.com", "19/12/1986", 2);
	inst37->setEspecialidad(1);
	sucursal8->agregarInstructor(inst37);
	Instructor* inst38 = new Instructor(934510101, "Daniela Rivas", 73336644, "drivas@gmail.com", "25/08/1992", 3);
	inst38->setEspecialidad(5);
	sucursal8->agregarInstructor(inst38);
	Instructor* inst39 = new Instructor(945611212, "Hernan Torres", 72225555, "htorres@gmail.com", "11/04/1985", 4);
	inst39->setEspecialidad(2);
	sucursal8->agregarInstructor(inst39);
	Instructor* inst40 = new Instructor(956712323, "Carolina Meza", 71114466, "cmeza@gmail.com", "30/09/1990", 5);
	inst40->setEspecialidad(4);
	sucursal8->agregarInstructor(inst40);

	// ==================== CLIENTES ====================

	Cliente* c71 = new Cliente("Rodrigo", 666600001, 85558833, "rodrigo2@gmail.com", "14/05/1996", 'H', "01/07/2024", 0, inst36);
	sucursal8->agregarCliente(c71);
	Cliente* c72 = new Cliente("Martina", 777700002, 84447744, "martina@gmail.com", "09/10/1997", 'M', "02/07/2024", 0, inst37);
	sucursal8->agregarCliente(c72);
	Cliente* c73 = new Cliente("Cristian", 888800003, 83336655, "cristian2@gmail.com", "22/01/1995", 'H', "03/07/2024", 0, inst38);
	sucursal8->agregarCliente(c73);
	Cliente* c74 = new Cliente("Josefa", 999900004, 82225566, "josefa@gmail.com", "05/06/1998", 'M', "04/07/2024", 0, inst39);
	sucursal8->agregarCliente(c74);
	Cliente* c75 = new Cliente("Matias", 111100005, 81114477, "matias@gmail.com", "28/11/1994", 'H', "05/07/2024", 0, inst40);
	sucursal8->agregarCliente(c75);
	Cliente* c76 = new Cliente("Pamela", 222200006, 80003388, "pamela@gmail.com", "17/02/1999", 'M', "06/07/2024", 0, inst36);
	sucursal8->agregarCliente(c76);
	Cliente* c77 = new Cliente("Ignacio", 333300007, 89992299, "ignacio2@gmail.com", "01/08/1993", 'H', "07/07/2024", 0, inst37);
	sucursal8->agregarCliente(c77);
	Cliente* c78 = new Cliente("Constanza", 444400008, 88881100, "constanza@gmail.com", "13/12/1996", 'M', "08/07/2024", 0, inst38);
	sucursal8->agregarCliente(c78);
	Cliente* c79 = new Cliente("Diego", 555500009, 87770011, "diego2@gmail.com", "26/09/1997", 'H', "09/07/2024", 0, inst39);
	sucursal8->agregarCliente(c79);
	Cliente* c80 = new Cliente("Francisca", 666600010, 86669922, "francisca@gmail.com", "08/03/1995", 'M', "10/07/2024", 0, inst40);
	sucursal8->agregarCliente(c80);

	// ==================== CLASES GRUPALES ====================

	ClaseGrupal* clase39 = new ClaseGrupal(39, 0, 20, sucursal8, inst36, "6:30am", 1);
	sucursal8->agregarClaseGrupal(clase39);
	ClaseGrupal* clase40 = new ClaseGrupal(40, 0, 25, sucursal8, inst37, "8:00am", 2);
	sucursal8->agregarClaseGrupal(clase40);
	ClaseGrupal* clase41 = new ClaseGrupal(41, 0, 18, sucursal8, inst38, "10:00am", 3);
	sucursal8->agregarClaseGrupal(clase41);
	ClaseGrupal* clase42 = new ClaseGrupal(42, 0, 22, sucursal8, inst39, "12:00pm", 4);
	sucursal8->agregarClaseGrupal(clase42);
	ClaseGrupal* clase43 = new ClaseGrupal(43, 0, 28, sucursal8, inst40, "2:00pm", 5);
	sucursal8->agregarClaseGrupal(clase43);
	ClaseGrupal* clase44 = new ClaseGrupal(44, 0, 24, sucursal8, inst36, "4:00pm", 2);
	sucursal8->agregarClaseGrupal(clase44);
	ClaseGrupal* clase45 = new ClaseGrupal(45, 0, 30, sucursal8, inst37, "6:00pm", 4);
	sucursal8->agregarClaseGrupal(clase45);

	// ==================== SUCURSAL 9 ====================

	Sucursal* sucursal9 = control_->buscarSucursal("SUC009");

	// ==================== INSTRUCTORES ====================

	Instructor* inst41 = new Instructor(967800111, "Andrea Salazar", 75553344, "asalazar@gmail.com", "20/02/1989", 1);
	inst41->setEspecialidad(2);
	sucursal9->agregarInstructor(inst41);
	Instructor* inst42 = new Instructor(978900222, "Carlos Medina", 74442255, "cmedina@gmail.com", "11/07/1986", 2);
	inst42->setEspecialidad(4);
	sucursal9->agregarInstructor(inst42);
	Instructor* inst43 = new Instructor(989000333, "Lucia Cabrera", 73331166, "lcabrera@gmail.com", "05/12/1991", 3);
	inst43->setEspecialidad(1);
	sucursal9->agregarInstructor(inst43);

	// ==================== CLIENTES ====================

	Cliente* c81 = new Cliente("Felipe", 777711111, 85554422, "felipe3@gmail.com", "14/03/1996", 'H', "11/07/2024", 0, inst41);
	sucursal9->agregarCliente(c81);
	Cliente* c82 = new Cliente("Mariana", 888822222, 84443311, "mariana2@gmail.com", "09/08/1997", 'M', "12/07/2024", 0, inst42);
	sucursal9->agregarCliente(c82);
	Cliente* c83 = new Cliente("Esteban", 999933333, 83332200, "esteban2@gmail.com", "22/01/1995", 'H', "13/07/2024", 0, inst43);
	sucursal9->agregarCliente(c83);
	Cliente* c84 = new Cliente("Clara", 111144444, 82221199, "clara@gmail.com", "05/06/1998", 'M', "14/07/2024", 0, inst41);
	sucursal9->agregarCliente(c84);
	Cliente* c85 = new Cliente("Jorge", 222255555, 81110088, "jorge@gmail.com", "28/11/1994", 'H', "15/07/2024", 0, inst42);
	sucursal9->agregarCliente(c85);
	Cliente* c86 = new Cliente("Valentina", 333366666, 80009977, "valentina2@gmail.com", "17/02/1999", 'M', "16/07/2024", 0, inst43);
	sucursal9->agregarCliente(c86);

	// ==================== CLASES GRUPALES ====================

	ClaseGrupal* clase46 = new ClaseGrupal(46, 0, 18, sucursal9, inst41, "7:00am", 1);
	sucursal9->agregarClaseGrupal(clase46);
	ClaseGrupal* clase47 = new ClaseGrupal(47, 0, 22, sucursal9, inst42, "9:00am", 2);
	sucursal9->agregarClaseGrupal(clase47);
	ClaseGrupal* clase48 = new ClaseGrupal(48, 0, 20, sucursal9, inst43, "5:00pm", 3);
	sucursal9->agregarClaseGrupal(clase48);
	ClaseGrupal* clase49 = new ClaseGrupal(49, 0, 25, sucursal9, inst41, "7:00pm", 4);
	sucursal9->agregarClaseGrupal(clase49);

	// ==================== SUCURSAL 10 ====================

	Sucursal* sucursal10 = control_->buscarSucursal("SUC010");

	// ==================== INSTRUCTORES ====================

	Instructor* inst44 = new Instructor(912301010, "Fernando Ruiz", 75553311, "fruiz@gmail.com", "02/06/1985", 1);
	inst44->setEspecialidad(5);
	sucursal10->agregarInstructor(inst44);
	Instructor* inst45 = new Instructor(923402020, "Gabriela Morales", 74442222, "gmorales@gmail.com", "18/09/1990", 2);
	inst45->setEspecialidad(2);
	sucursal10->agregarInstructor(inst45);
	Instructor* inst46 = new Instructor(934503030, "Hector Paredes", 73331133, "hparedes@gmail.com", "27/01/1988", 3);
	inst46->setEspecialidad(3);
	sucursal10->agregarInstructor(inst46);
	Instructor* inst47 = new Instructor(945604040, "Laura Fernandez", 72220044, "lfernandez@gmail.com", "11/12/1992", 4);
	inst47->setEspecialidad(1);
	sucursal10->agregarInstructor(inst47);

	// ==================== CLIENTES ====================

	Cliente* c87 = new Cliente("Alvaro", 444411111, 85550011, "alvaro@gmail.com", "14/04/1996", 'H', "01/08/2024", 0, inst44);
	sucursal10->agregarCliente(c87);
	Cliente* c88 = new Cliente("Daniela", 555522222, 84441122, "daniela2@gmail.com", "09/10/1997", 'M', "02/08/2024", 0, inst45);
	sucursal10->agregarCliente(c88);
	Cliente* c89 = new Cliente("Mauricio", 666633333, 83332233, "mauricio2@gmail.com", "22/01/1995", 'H', "03/08/2024", 0, inst46);
	sucursal10->agregarCliente(c89);
	Cliente* c90 = new Cliente("Camila", 777744444, 82223344, "camila3@gmail.com", "05/06/1998", 'M', "04/08/2024", 0, inst47);
	sucursal10->agregarCliente(c90);
	Cliente* c91 = new Cliente("Pedro", 888855555, 81114455, "pedro@gmail.com", "28/11/1994", 'H', "05/08/2024", 0, inst44);
	sucursal10->agregarCliente(c91);
	Cliente* c92 = new Cliente("Sofia", 999966666, 80005566, "sofia2@gmail.com", "17/02/1999", 'M', "06/08/2024", 0, inst45);
	sucursal10->agregarCliente(c92);
	Cliente* c93 = new Cliente("Ignacio", 111177777, 89996677, "ignacio3@gmail.com", "01/08/1993", 'H', "07/08/2024", 0, inst46);
	sucursal10->agregarCliente(c93);
	Cliente* c94 = new Cliente("Valentina", 222288888, 88887788, "valentina3@gmail.com", "13/12/1996", 'M', "08/08/2024", 0, inst47);
	sucursal10->agregarCliente(c94);

	// ==================== CLASES GRUPALES ====================

	ClaseGrupal* clase50 = new ClaseGrupal(50, 0, 20, sucursal10, inst44, "7:00am", 1);
	sucursal10->agregarClaseGrupal(clase50);
	ClaseGrupal* clase51 = new ClaseGrupal(51, 0, 25, sucursal10, inst45, "9:00am", 2);
	sucursal10->agregarClaseGrupal(clase51);
	ClaseGrupal* clase52 = new ClaseGrupal(52, 0, 18, sucursal10, inst46, "11:00am", 3);
	sucursal10->agregarClaseGrupal(clase52);
	ClaseGrupal* clase53 = new ClaseGrupal(53, 0, 22, sucursal10, inst47, "5:00pm", 4);
	sucursal10->agregarClaseGrupal(clase53);
	ClaseGrupal* clase54 = new ClaseGrupal(54, 0, 28, sucursal10, inst44, "7:00pm", 5);
	sucursal10->agregarClaseGrupal(clase54);

	// ==================== FIN DATOS DE PRUEBA ====================

}
