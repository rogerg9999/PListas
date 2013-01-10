#ifndef COLA_H_
#define COLA_H_

#include <iostream>
#include <string>
#include "persona.h"
#include "error.h"
#include "util.h"

using namespace std;


class cola
{
	class nodocola
	{
	public:
		persona cliente;
		nodocola* sig;
		nodocola(persona p); // Constructor del nodo
	};

private:
	nodocola* cabeza;
	nodocola* ultimo;
	int elementos;
public:
	cola();                    // Constructor de la cola
	void anadir(persona p);    // Añadir una solicitud a la cola
	bool esvacia();            // Comprobar si la cola está vacía
	persona primero();         // Obtener el primer elemento de la cola
	void eliminar();           // Quitar el primer elemento de la cola
	int cuantos();             // Obtener la cantidad de elementos
    void escribircola();	   // Escribe la información relevante de la cola
	void atenderprimero();	   // Atiende un minuto al primer cliente
	int sinatender();
	void satisfacerPrimero(int tactual);
};

#endif /* COLAS_H_ */
