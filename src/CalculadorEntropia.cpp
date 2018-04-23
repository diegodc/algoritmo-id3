/**
 * CalculadorEntropia.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "CalculadorEntropia.h"
#include "Calculadora.h"

CalculadorEntropia::CalculadorEntropia() {
}

CalculadorEntropia::~CalculadorEntropia() {
}

double CalculadorEntropia::entropia(double probabilidad1,
									double probabilidad2) const {

	Calculadora calculadora;

	return (- probabilidad1 * calculadora.logaritmo(probabilidad1, 2)
			- probabilidad2 * calculadora.logaritmo(probabilidad2, 2));
}


double CalculadorEntropia::probabilidad(double numeroCasos,
										double casosTotales) const {

	double probabilidad = 0;

	if (casosTotales != 0) {

		probabilidad = numeroCasos / casosTotales;
	}

	return probabilidad;
}
