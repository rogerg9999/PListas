#include <iostream>
#include <string>
#include "lista.h"

using namespace std;

lista::nodolista::nodolista(int cod){
	caja = cola::cola();
	codigo = cod;
	sig = NULL;
}

lista::lista(){
	primero = NULL;
	longitud = 0;
}

bool lista::esvacia(){
	return primero == NULL;
}

int lista::cajasabiertas(){
	return longitud;
}

//Abre una caja que este en medio de 2 no consecutivas o la ultima
void lista::abrircaja(){
	lista::nodolista* nodo;
	if(esvacia()){
		nodo = new nodolista(1); 
		primero = nodo;
	}
	else{
		lista::nodolista* aux = primero;
		while(aux->sig != NULL && aux->codigo == aux->sig->codigo-1){
			aux = aux->sig;
		}
		nodo = new nodolista(aux->codigo+1);
		nodo->sig = aux->sig;
		aux->sig = nodo;
	}
	longitud++;
	return;
}

//Numero de cajas vacias
bool lista::cajaslibres(int num){
	if (esvacia())
		throw error("No hay cajas libres en una lista vacia");
	lista::nodolista* aux = primero;
	int vacias = 0;
	while(aux != NULL){
		if(aux->caja.esvacia())
			vacias ++;
		aux = aux->sig;
	}
	return vacias>=num;
}

//Comprueba si en todas las cajas hay numclientes o mas

bool lista::cajasllenas(int numclientes){
	if(esvacia())
		throw error("No se puede calcular el numero de cajas llenas en una lista vacia");

	lista::nodolista* aux = primero;
	bool llenas = true;
	while(aux != NULL && llenas){
		if(aux->caja.cuantos() < numclientes)
			llenas=false;
		aux = aux->sig;
	}
	return llenas;
}

//Cierra una caja si hay 2 cajas vacias o mas

void lista::cerrarcaja(){
	if(esvacia())
		throw error("No se puede cerrar una caja de una lista vacia");

	if(cajaslibres(2)){
		lista::nodolista* aux = primero;
	    lista::nodolista* nodo;
		if(primero->caja.esvacia()){
			nodo = primero;
			primero = primero->sig;
			nodo->sig = NULL;
			delete(nodo);
			longitud--;
		}
		else{
			while(!aux->sig->caja.esvacia()){
				aux = aux->sig;
			}
			nodo = aux->sig;
			aux->sig = nodo->sig;
			nodo->sig = NULL;
			delete(nodo);
			longitud--;
			}	
	}
	return;
	}

//Devuelve la caja con mas clientes

lista::nodolista* lista::cajamasocupada(){
	if(esvacia())
		throw error("No hay maximo de una lista vacia");
	lista::nodolista* max = primero;
	lista::nodolista* aux = primero->sig;
	while(aux!=NULL){
		if(max->caja.cuantos() < aux->caja.cuantos())
			max = aux;
		aux = aux->sig;
	}
	return max;
}


//Devuelve la caja con menos clientes 

lista::nodolista* lista::cajamenosocupada(){
	if(esvacia())
		throw error("No hay minimo de una lista vacia");
	nodolista* min = primero;
	nodolista* aux = primero->sig;
	while(aux!=NULL){
		if(min->caja.cuantos() > aux->caja.cuantos())
			min = aux;
		aux = aux->sig;
	}
	return min;
}

int lista::clientesnoatendidos(){
	if(esvacia())
		throw error("No hay clientes sin atender en una lista vacia");
	nodolista* aux = primero;
	int sinatender = 0;
	while(aux != NULL){
		if(!aux->caja.esvacia())
			sinatender += aux->caja.sinatender();
		aux = aux->sig;
	}
	return sinatender;
}

// Atiende un minuto al primer cliente de cada caja

void lista::atender1min(){
	nodolista* aux = primero;
	while(aux != NULL){
		if(!aux->caja.esvacia())
			aux->caja.atenderprimero();
		aux = aux->sig;
	}
	return;
}

//Calcula el tiempo que llevan en el banco los clientes, que estan a punto de terminar su turno en la caja

int lista::tiemposalientes(int tactual){
	if(esvacia())
		throw error("No hay clientes a punto de salir en una lista vacia");
	nodolista* aux = primero;
	int tsalientes = 0;
	while(aux != NULL){
		if(!aux->caja.esvacia() && aux->caja.primero().acabado())
			tsalientes += aux->caja.primero().tiempoenbanco(tactual);
		aux = aux->sig;
	}
	return tsalientes;
}

//Si ha terminado de ser atendido el cliente sale del banco

void lista::despachar(){
	nodolista* aux = primero;
	while(aux != NULL){
		if(!aux->caja.esvacia() && aux->caja.primero().acabado())
			aux->caja.eliminar();	
		aux = aux->sig;
	}
	return;
}

void lista::escribirlista(){
	int x=0,y=0;
	x=util::getX();
	y=util::getY()+4;
	lista::nodolista* aux = primero;
	while(aux!=NULL){
		util::gotoxy(x,y);
		cout<<"Caja : "<< (char)(aux->codigo + 64)<<endl;
		util::gotoxy(x,y+2);
		aux->caja.escribircola();
		x+=25;
		aux = aux->sig;
	}
	cout<<endl;
	return;
}

//Calcula el nivel de satisfaccion de los clientes que han terminado su turno
void lista::satisfacerPrimeros(int tiempo){
	nodolista* aux = primero;
	while(aux != NULL){
		if(!aux->caja.esvacia() && aux->caja.primero().acabado()){
			//calculamos su nivel de satisfaccion

			aux->caja.satisfacerPrimero(tiempo);
		}
			
		aux = aux->sig;
	}
}

//Inserta en el arbol los clientes que han terminado su turno

void lista::insertarSalientes(arbol *a){
	nodolista* aux = primero;
	while(aux != NULL){
		if(!aux->caja.esvacia() && aux->caja.primero().acabado()){

			//insertamos en el arbol de busqueda

			a->poner(aux->caja.primero(), NULL);
		}
			
		aux = aux->sig;
	}
}