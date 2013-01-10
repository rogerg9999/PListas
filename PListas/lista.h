#ifndef LISTA_H_
#define LISTA_H_

#include <iostream>
#include <string>
#include "persona.h"
#include "cola.h"
#include "error.h"
#include "arbol.h"

using namespace std;


class lista
{
	friend class banco;	// el banco puede usar los atributos de las cajas
	
	class nodolista		// clase para gestionar los nodos de las listas
	{
	public:
		cola caja;			// cola de gente en la caja
		int codigo;			// código identificador de la caja
		nodolista* sig;		// puntero al siguiente nodo
		nodolista(int cod); // Constructor del nodo
	};

private:
	nodolista* primero;		// primer nodo de la lista
	int longitud;			// cantidad de nodos de la lista
public:
	lista();				// Constructor de la lista de cajas
	void abrircaja();		// Añadir ordenadamente una caja a la lista
	void cerrarcaja();		// Quitar una caja si hay dos o más cajas vacías
	int cajasabiertas();	// Devuelve el total de cajas disponibles
	bool esvacia();			// Comprobar si la lista está vacía
	nodolista* cajamasocupada();	// nodo de la caja con más gente
	nodolista* cajamenosocupada();	// nodo de la caja con menos gente
	
	void escribirlista();	// Escribe el estado de la lista de cajas
	void atender1min();		// Atiende un minuto en todas las cajas abiertas

	bool cajaslibres(int num);     //Comprueba si num o mas cajas estan libres 
	bool cajasllenas(int numclientes);    //Comprueba si todas las cajas tienen  numclientes o mas
	int tiemposalientes(int tactual);
	void despachar();
	int clientesnoatendidos();

	void satisfacerPrimeros(int tiempo);
	void insertarSalientes(arbol *a);
};

#endif /* LISTA_H_ */
