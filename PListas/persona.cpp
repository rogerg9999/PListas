#include <iostream>
#include <string>
#include <conio.h>
#include "persona.h"
#include "util.h"

using namespace std;

persona::persona(){
	nivelsatisfaccion = 0;
	duracion=0;
	horaevento=0;
	idcaja='*';
	idcliente=0;
	tiempoatendido = 0;

};

persona::persona(int cli,string tar, int hora, int dur){
	idcaja='*';
	idcliente=cli;
	tarea=tar;
	horaevento=hora;
	duracion=dur;
	tiempoatendido=0;
	nivelsatisfaccion = 0;
};

void persona::poneridcaja(char caja){
	idcaja = caja;
	return;
};

void persona::atenderunminuto(){
	tiempoatendido++;
	return;
}


//Devuelve true si el cliente ya a terminado de ser atendido
bool persona::acabado(){
	return duracion==tiempoatendido;
};

bool persona::estaentrando(int hora){
	return horaevento==hora;
}

bool persona::estaencaja(char id){
	return idcaja==id;
}

bool persona::satisfecho(){
	return nivelsatisfaccion <= 0;
}

int persona::tiempoenbanco(int tactual){
	return tactual - horaevento;
}

void persona::satisfaccion(int tactual){
	nivelsatisfaccion = tiempoenbanco(tactual)- 2*duracion;

}

//Escribe los campos de una persona
void persona::escribir(){
	int x= util::getX();
	int y = util::getY();
	util::gotoxy(x,y+1);
	cout << "El cliente " << idcliente << endl;
	util::gotoxy(x,y+2);
	cout<< " viene a " << tarea << endl;
	util::gotoxy(x,y+3);
	cout<< " hora del evento " << horaevento << endl;
	util::gotoxy(x,y+4);
	cout<< " duracion " << duracion << endl;
	util::gotoxy(x,y+5);
	cout<< "Tiempo atendido "<< tiempoatendido << endl;
	util::gotoxy(x,y+6);
	cout<< "Nivel de satisfaccion "<< nivelsatisfaccion << endl;
	util::gotoxy(x,y+7);
	cout<< "en la caja: "<< idcaja << endl << endl << endl;
	return;
};



