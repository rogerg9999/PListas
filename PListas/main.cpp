#include <iostream>
#include <string>
#include <conio.h>
#include "banco.h"
#include "cola.h"
#include "persona.h"
#include "util.h"
#include "error.h"

using namespace std;

int main()
{
	cout.precision(4);
	banco bank=banco();
	try{
		bank.simular();
	}catch(error &e){
		cout<< e.getMessage() <<endl;
	}
	

	cout << "Fin del programa" << endl;
	_getch();

	return 0;
};
