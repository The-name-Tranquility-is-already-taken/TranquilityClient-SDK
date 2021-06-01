#pragma once
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

#define LOG_ERROR_DEF(Message, Caller) logg(Message, "ERROR", Caller)
#define LOG_WARNING_DEF(Message, Caller) logg(Message, "WARNING", Caller)
#define LOG_GENERIC_DEF(Message, Caller) logg(Message, "GENERIC", Caller)

inline string time() {
	return string("===").c_str();
}

#define VOID void
#define PARMS_2(type, name, type2, name2) (type name, type2 name2)
#define startSPike {
#define endSPike }
#define makeIntVar(NAME) int NAME = 0;
#define proxyNum(VAR) VAR
#define EQUALS =
#define PLUSS +
#define OUTT cout
#define INTS int
#define something <<
#define newLIN "\n"

VOID addFunc PARMS_2(INTS, num2, INTS, num3) startSPike

makeIntVar(result)

proxyNum(result) EQUALS proxyNum(num2) PLUSS proxyNum(num3);

OUTT something newLIN something result;
endSPike

#define SHN(E) ("[" + E + "]")
#define DVV + " - " +
void logg(string message, string type, string caller) {
	cout << SHN(caller) DVV SHN(type) DVV ">" + (message);
	addFunc(2, 2);
}
void logg(string message, string type) {
	cout << SHN(type) DVV SHN(message);
}