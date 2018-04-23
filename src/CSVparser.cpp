/**
 * CSVparser.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "CSVparser.h"

#ifndef SEPARADOR
#define SEPARADOR ','
#endif

CSVparser::CSVparser() {
}

CSVparser::~CSVparser() {
}

Lista<std::string>* CSVparser::parsearString(const std::string& string) {

	Lista<std::string>* valores = new Lista<std::string>;

	unsigned indice = 0;

	unsigned largo = string.length();

	for(unsigned i = 0; i < largo; i++) {

		char caracter = string[i];

		if (caracter == SEPARADOR) {

			valores->agregar(string.substr(indice, i - indice));
			indice = i + 1;
		}
	}
	valores->agregar(string.substr(indice, largo - indice));

	return valores;
}
