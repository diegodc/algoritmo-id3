/**
 * Calculadora.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "Calculadora.h"

Calculadora::Calculadora() {
}

Calculadora::~Calculadora() {
}


double Calculadora::logaritmo(double numero, double base) {

	double resultado = 0;

	if ((numero > 0) && (base > 0) && (base != 1))  {

		resultado = log(numero) / log(base);
	}

	return resultado;
}
