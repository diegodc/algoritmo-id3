/**
 * Calculadora.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

#include <cmath>

/**
 * La clase Calculadora puede realizar diversos calculos matematicos.
 */
class Calculadora {

public:

	Calculadora();

	~Calculadora();

	/**
	 * pre: 'numero' - numero positivo.
	 *      'base' - numero positivo.
	 *
	 * post: retorna el logaritmo en la base dada.
	 */
	double logaritmo(double numero, double base);

};

#endif /* CALCULADORA_H_ */
