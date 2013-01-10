#include <iostream>
#include <string>
#include <conio.h>
#include "banco.h"
#include "persona.h"

using namespace std;


banco::banco(){
	ventanillas = lista::lista();
	totalclientes = 0;
	tiempototal = 0;
	niveles = arbol::arbol();
	persona p = persona();
	niveles.poner(p,niveles.raiz);
}

float banco::tiempomedio(){
	return totalclientes==0? 0 : (float)tiempototal/totalclientes;
}

void banco::abrirventanillas(int num){
	for (int i=0; i<num ; i++)
		ventanillas.abrircaja();
	return;
}
//Simula la llegada de una persona al banco, se busca la caja con menor numero de clientes y se asigna a ella.
void banco::llegada(persona p){
	lista::nodolista* min = ventanillas.cajamenosocupada();
	p.poneridcaja((char)min->codigo+64);
	min->caja.anadir(p);
	totalclientes++;
	return;
}

//Salida de un cliente del banco, primero se calcula el tiempo que lleva dentro del banco.
void banco::salida(int tiempo){
	int satisfaccion = 0;
	//Calcula el tiempo que llevan los clientes que ya han terminado de ser atendidos

	tiempototal += ventanillas.tiemposalientes(tiempo);
	
	//Si el cliente ya ha terminado calculamos su nivel de satisfaccion y lo insertamos en el arbol de busqueda

	ventanillas.satisfacerPrimeros(tiempo);

	ventanillas.insertarSalientes(&niveles);

	//Elimina de las cajas los clientes que ya han terminado su turno

	ventanillas.despachar();
	return;
}



void banco::escribir(){
	util::clrscr();
	lista::nodolista* min = ventanillas.cajamenosocupada();
	lista::nodolista* max = ventanillas.cajamasocupada();
	cout<<"Total clientes: "<< totalclientes << endl;
	cout<<"Clientes sin atender: "<<ventanillas.clientesnoatendidos() << endl;
	cout<<"Tiempo medio: "<< tiempomedio() << endl;
	cout<<"Caja menos ocupada: "<< (char)(min->codigo + 64)<< endl;
	cout<<"Caja mas ocupada: "<< (char)(max->codigo + 64) << endl;
	cout<<"Satisfechos en el banco: "<< niveles.satisfechosenbanco(niveles.raiz) << endl;
	cout<<"Satisfechos en la caja A : "<< niveles.satisfechosencaja('A', niveles.raiz) << endl;
	cout<<"Satisfechos en la caja B  : "<< niveles.satisfechosencaja('B', niveles.raiz) << endl;
	cout<<"Satisfechos en la caja C : "<< niveles.satisfechosencaja('C', niveles.raiz) << endl;
	cout<<"Nivel de satisfaccion medio: "<< (float)niveles.sumasatisfaccion(niveles.raiz)/totalclientes << endl;
	//cout<<"Satisfaccion media "<< niveles.sumasatisfaccion(niveles.raiz) / totalclientes << endl;
	ventanillas.escribirlista();
	return;
};

//Gestiona el modo de escribir el arbol inorden, preorden o postorden;
void banco::menuEscribirArbol(){
	char op;
	while((op=_getch()) != 'e'){
		cout<< endl<< endl << "Introduce el orden en el que quieres imprimir el arbol: " <<endl; 
		cout<< "i: INORDEN, p: PREORDEN, t: POSTORDEN, e: EXIT" <<endl <<endl << endl;
		switch (op){
		case 'i': niveles.inorden(niveles.raiz);
			break;
		case 'p': niveles.preorden(niveles.raiz);
			break;
		case 't': niveles.postorden(niveles.raiz);
			break;
		case 'e': return;
		} 

	}
}

//Simula el funcionamiento de un banco
void banco::simular(){
	persona p1(1,"PAGOS",0,20);
	persona p3(3,"PAGOS",0,15);
	persona p2(2,"ACTUALIZAR",5,19);
	persona p4(4,"INGRESOS",7,23);
	persona p7(7,"PAGOS",9,16);
	persona p9(9,"INGRESOS",11,23);
	persona p8(8,"RECIBOS",14,31);
	persona p6(6,"ACTUALIZAR",18,14);
	persona p5(5,"TRANSFERENCIA",21,20);

	persona personas[9]={p1,p2,p3,p4,p5,p6,p7,p8,p9};

	abrirventanillas(3);

	for(int t=0;t<100;t++){

		for(int i=0; i<9;i++){
			if(personas[i].estaentrando(t))
				llegada(personas[i]);
		}
		
		escribir();

		//Salida se encarga de verificar si hay algun cliente que ya ha terminado su turno, si es asi
		//calcula el tiempo total, lo inserta en el arbol y lo elimina de la caja en la que esta.
		salida(t);

		//Si hay mas de dos cajas libres cierra alguna
		ventanillas.cerrarcaja();

		//Si todas estan llenas conmaxclientes abre una caja
		if(ventanillas.cajasllenas(maxclientes))
			abrirventanillas(1);

		//Atiende un minuto a los primeros clientes de cada caja
		ventanillas.atender1min();
		
		_getch();
		
	}

	//Menu para escribir el arbol en inorden, preorden o postorden.
	menuEscribirArbol();

	return;
}