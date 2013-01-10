#include <iostream>
#include  <string>
#include "cola.h"


cola::nodocola::nodocola(persona p){
	cliente=p;
	sig=NULL;
}

cola::cola(){
	cabeza=NULL;
	ultimo=NULL;
	elementos = 0;
};

bool cola::esvacia(){
	return cabeza==NULL;
};
//Añade una persona en la cola
void cola::anadir(persona p){
	cola::nodocola* nodo=new nodocola(p);
	if(esvacia())
		cabeza=nodo;
	else
		ultimo->sig=nodo;

	ultimo=nodo;
	elementos++;
};

//Devuelve la primera persona de la cola
persona cola::primero(){
	if(esvacia())
		throw error("La cola esta vacia");
	else
		return cabeza->cliente;
};

//Elimina la primera persona de la cola
void cola::eliminar(){
	cola::nodocola * nodo;
	if(esvacia())
		throw error("Estas intentando eliminar un elemento de una cola vacia");
	else{
		nodo=cabeza;
		cabeza=nodo->sig;
		if(cabeza==NULL)
			ultimo=NULL;
		nodo->sig=NULL;
		delete(nodo);
		elementos--;
	}
	return;

};

//Devuelve el numero de personas de la cola
int cola::cuantos(){
	return elementos;
};

int cola::sinatender(){
	return elementos==0 ? 0 : elementos - 1;
}

//Atiende un minuto al primero de la cola
void cola::atenderprimero(){
	if(!esvacia())
		cabeza->cliente.atenderunminuto();
	return;
};

void cola::escribircola(){
	int x,y;
	x= util::getX();
	y = util::getY();
	util::gotoxy(x, y+1);
	cout<<"clientes de la cola: "<< elementos <<endl;
	util::gotoxy(x, y+3);
	if(!esvacia())
		primero().escribir();
	return;
};

void cola::satisfacerPrimero(int tactual){
	cabeza->cliente.satisfaccion(tactual);
}