#ifndef ARBOL_H_
#define ARBOL_H_

#include <iostream>
#include <string>
#include "persona.h"
#include "cola.h"

using namespace std;

class arbol
{
	friend class banco;	// el banco puede usar los atributos del �rbol

	class nodoarbol		// clase para gestionar los nodos del �rbol
	{
	public:
		persona cliente;		// informaci�n que se guarda en los nodos
		nodoarbol* izq;			// puntero al hijo izquierdo
		nodoarbol* der;			// puntero al hijo derecho
		nodoarbol(persona p);	// constructor del nodo
	};

private:
	nodoarbol* raiz;	// ra�z del �rbol
	int numpersonas;	// cantidad de personas guardadas en el �rbol

public:
	arbol();			// constructor de la clase arbol

	// a�adir ordenadamente la persona 'p' al �rbol que empieza en 'n'
	void poner(persona p, nodoarbol* n);	
											
	void inorden(nodoarbol* n);	  // escribe el �rbol en inorden desde 'n'
	void preorden(nodoarbol* n);  // escribe el �rbol en preorden desde 'n'
	void postorden(nodoarbol* n); // escribe el �rbol en postorden desde 'n'

	// contar cu�ntas personas est�n satisfechas en una caja 'c' o en todo el
	// banco, recorriendo el �rbol a partir del nodo 'n'
	int satisfechosencaja(char c, nodoarbol* n);

	//Satisechos en el banco
	int satisfechosenbanco(nodoarbol* n);

	// calcular la suma de los niveles de satisfacci�n (para la media)
	int sumasatisfaccion(nodoarbol* n);
};






#endif /* ARBOL_H_ */
