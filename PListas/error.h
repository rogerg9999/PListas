#ifndef ERROR_H_
#define ERROR_H_

#include <string>

using namespace std;

class error{

private:
	string message;
public:
	error ( string m );
	string getMessage();
};

#endif