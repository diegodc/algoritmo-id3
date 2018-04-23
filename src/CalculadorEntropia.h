/**
 * CalculadorEntropia.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef CALCULADORENTROPIA_H_
#define CALCULADORENTROPIA_H_

/*
 * Calculador entropia contiene metodos que permiten realizar
 * el calculo de la entropia de un conjunto.
 */
class CalculadorEntropia {

public:

	CalculadorEntropia();

	~CalculadorEntropia();

	/**
	 * post: retorna la entropia calculada en base a las probabilidades.
	 */
	double entropia(double probabilidad1, double probabilidad2) const;

	/**
	 * post: retorna el calculo de la probabilidad.
	 *       retorna 0 si el numero de casos totales es 0.
	 */
	double probabilidad(double numeroCasos, double casosTotales) const;

};

#endif /* CALCULADORENTROPIA_H_ */
