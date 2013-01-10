#include <string>
#include "error.h"

error::error(string m){
	message = m;
}

string error::getMessage(){
	return message;
}