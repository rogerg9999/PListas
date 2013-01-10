#ifndef ARBOL_H_
#define ARBOL_H_

#include <iostream>
#include <string>
#include "persona.h"
#include "cola.h"

using namespace std;

class arbol
{
	friend class banco;	// el banco puede usar los atributos del árbol

	class nodoarbol		// clase para gestionar los nodos del árbol
	{
	public:
		persona cliente;		// información que se guarda en los nodos
		nodoarbol* izq;			// puntero al hijo izquierdo
		nodoarbol* der;			// puntero al hijo derecho
		nodoarbol(persona p);	// constructor del nodo
	};

private:
	nodoarbol* raiz;	// raíz del árbol
	int numpersonas;	// cantidad de personas guardadas en el árbol

public:
	arbol();			// constructor de la clase arbol

	// añadir ordenadamente la persona 'p' al árbol que empieza en 'n'
	void poner(persona p, nodoarbol* n);	
											
	void inorden(nodoarbol* n);	  // escribe el árbol en inorden desde 'n'
	void preorden(nodoarbol* n);  // escribe el árbol en preorden desde 'n'
	void postorden(nodoarbol* n); // escribe el árbol en postorden desde 'n'

	// contar cuántas personas están satisfechas en una caja 'c' o en todo el
	// banco, recorriendo el árbol a partir del nodo 'n'
	int satisfechosencaja(char c, nodoarbol* n);

	//Satisechos en el banco
	int satisfechosenbanco(nodoarbol* n);

	// calcular la suma de los niveles de satisfacción (para la media)
	int sumasatisfaccion(nodoarbol* n);
};






#endif /* ARBOL_H_ */
