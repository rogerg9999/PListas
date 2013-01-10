#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class persona
{
private:
	char idcaja;			// caja en la que se coloca
	int idcliente;			// c�digo identificador de cliente
	string tarea;			// descripci�n de la tarea
	int horaevento;			// hora prevista de inicio
	int duracion;			// duraci�n del servicio
	int tiempoatendido;
public:
	persona();
	persona(int cli,string tar, int hora, int dur);
	void escribir();        
	void poneridcaja(char caja);
	void atenderunminuto();			// aumento un minuto el tiempoatendido
	bool acabado();					// determina si se ha acabado la tarea
	bool estaentrando(int hora);			// acceso al atributo 'horaevento'
			// PECL3
	int nivelsatisfaccion;	// Diferencia entre el tiempo total de atenci�n
							// y el doble de la duraci�n original de latarea
	bool estaencaja(char id);
	bool satisfecho();
	int tiempoenbanco(int tactual);
	void satisfaccion(int tactual);

};

#endif
