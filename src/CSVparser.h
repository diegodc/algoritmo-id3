/**
 * CSVparser.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef CSVPARSER_H_
#define CSVPARSER_H_

#include "Lista.h"
#include <string>

/**
 * CSV parser permite analizar cadenas de texto y extraer los
 * valores sepearos por comas que contenga.
 */
class CSVparser {

public:

	CSVparser();

	~CSVparser();

	/**
	 * pre: 'string' - cadena de caracteres que contiene los
	 *      valores separados por coma que se desean obtener.
	 *
	 * post: parsea el string extrayendo los valores y retorna una lista
	 * 		 de strings con los valores extraidos, insertados en el orden
	 *       que se encontraban en el string original.
	 */
	Lista<std::string>* parsearString(const std::string& string);

};

#endif /* CSVPARSER_H_ */
