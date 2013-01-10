#include <iostream>
#include <string>
#include "arbol.h"

arbol::nodoarbol::nodoarbol(persona p){
	cliente = p;
	izq = NULL;
	der = NULL;
}

arbol::arbol(){
	raiz = NULL;
	int numpersonas = 0;
}

void arbol::poner(persona p, nodoarbol* n){
	//Si el arbol es vacio iniciamos un nodo y lo ponemos como raiz
	if(n==NULL)
		n=raiz;

	if(n==NULL){
		raiz= new nodoarbol(p);
		numpersonas++;
	}	
	else{
		//Si hay nodos en la izquierda, aplicamos recursion
		if(p.nivelsatisfaccion <= n->cliente.nivelsatisfaccion){
			if(n->izq != NULL)
			 poner(p, n->izq);
			//Si no insertamos el nodo en la izquierda
			else{
				n->izq = new nodoarbol(p);
				numpersonas++;
			}
				
		}	
		else{
			//Si hay nodos por la derecha aplicamos recursion
			if(n->der != NULL)
				poner(p, n->der);
			else{
				//Si no insertamos un nuevo nodo en la derecha
				n->der = new nodoarbol(p);
				numpersonas++;
			}
				
		}
	}
	return;
}

//Escribimos inorden izq / raiz / inorden der
void arbol::inorden(nodoarbol* n){
	if(n == NULL)
      throw error("La operacion inorden no esta definida para un arbol vacio");
	if(n->izq != NULL)
		inorden(n->izq);

	  n->cliente.escribir();
	  

	if(n->der!=NULL)
		inorden(n->der);
	return;
}

//Escribimos raiz / preorden izq / preorden der
void arbol::preorden(nodoarbol *n){
	if(n == NULL)
		throw error("La operacion preorden no esta definida para un arbol vacio");

	n->cliente.escribir();

	if(n->izq != NULL)
		preorden(n->izq);

	if(n->der != NULL)
		preorden(n->der);

	return;
}

// postorden izq / postorden der / raiz
void arbol::postorden(nodoarbol *n){
	if(n == NULL)
		throw error("La operacion postorden no esta definida para un arbol vacio");
	if(n->izq != NULL)
		postorden(n->izq);

	if(n->der != NULL)
		postorden(n->der);

	n->cliente.escribir();
	return;
}

//Satisfechos en la caja c

int arbol::satisfechosencaja(char c, nodoarbol* n){
	if(n == NULL)
		throw error("La operacion satisfechos en caja no esta definida para un arbol vacio");

	//Si el cliente esta en la caja y es satisfechoo s vale 1
	int s = n->cliente.estaencaja(c) && n->cliente.satisfecho() ? 1 : 0;

	//Si hay nodos en la izq y en la derecha aplicamos recursion en ambos lados y le sumamos 1 si el cliente actual esta satisfecho 
	if(n->izq != NULL  && n->der != NULL)
		return s + satisfechosencaja(c,n->izq) + satisfechosencaja(c,n->der);

	//Si solo hay nodos por la izquierda aplicamos recursion por la izquierda y le sumamos s
	else if(n->izq != NULL )
		return s + satisfechosencaja(c,n->izq);

	//Lo mismo si solo hay nodos por la derecha
	else if(n->der != NULL)
		return s + satisfechosencaja(c,n->der);
	else
		//Si es una hoja 1 si el cliente esta satisfecho y si no retorna 0
		return s;
}

//Satisfechos en todas las cajas del banco
int arbol::satisfechosenbanco(nodoarbol* n){
	if(n == NULL)
		throw error("La operacion satisfechos en banco no esta definida para un arbol vacio");

	int s = n->cliente.satisfecho() && n!=raiz? 1 : 0;
	if(n->izq != NULL  && n->der != NULL)
		return s + satisfechosenbanco(n->izq) + satisfechosenbanco(n->der);
	else if(n->izq != NULL )
		return s + satisfechosenbanco(n->izq);
	else if(n->der != NULL)
		return s + satisfechosenbanco(n->der);
	else
		return s; 
}

//Suma la satisfaccion de todos los clientes del banco

int arbol::sumasatisfaccion(nodoarbol* n){
	if(n == NULL)
		throw error("La operacion suma satisfaccion no esta definida para un arbol vacio");

	int nivels = n->cliente.nivelsatisfaccion;
	
	//Si hay clientes por la izq y la der aplicamos recursion por la izq y la der y le sumamos el nivel de satisfaccion del nodo actual
	if(n->izq != NULL  && n->der != NULL)
		return nivels + sumasatisfaccion(n->izq) + sumasatisfaccion(n->der);

	//Si solo hay clientes por la izq aplicamos recursion y le sumamos el nivel de satisfaccion del cliente actual
	else if(n->izq != NULL )
		return nivels + sumasatisfaccion(n->izq);

	//Lo mismo por la derecha
	else if(n->der != NULL)
		return nivels + sumasatisfaccion(n->der);

	//Si es una hoja retorna el nivel de satisfaccion del cliente actual
	else
		return nivels;
}