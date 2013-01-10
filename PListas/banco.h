#ifndef BANCO_H_
#define BANCO_H_

#include <iostream>
#include <string>
#include <conio.h>
#include "cola.h"
#include "lista.h"
#include "persona.h"
#include "arbol.h"

using namespace std;

const int horacierre = 360;
const int maxclientes=3;

class banco
{
private:
	lista ventanillas; // lista con todas las cajas abiertas
	int totalclientes; // cantidad de clientes que han estado en el banco
	int tiempototal;   // tiempo total que pasan los clientes en el banco
	arbol niveles;		// árbol para guardar los datos de los clientes

public:
	banco();				 // constructor de la clase
	void escribir();		 // escribe la información relevante del banco
	void llegada(persona p); // evento de llegada de una persona al banco
	void salida(int tiempo); // gestion las salidas en el momento 'tiempo'
	void simular();			 // realiza la simulación de un día del banco
	float tiempomedio();     // calcula el tiempo medio que pesan los clientes en el banco
	void abrirventanillas(int num); // abre num ventanillas
	void inertarSalientes(int tiempo);   //Inserta en el arbol niveles los clientes que ya han terminado su turno
	void menuEscribirArbol();    //Gestiona el modo de escribir un arbol
};




#endif