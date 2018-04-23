/**
 * Regla.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef REGLA_H_
#define REGLA_H_

#include "Valor.h"
#include "Lista.h"

/**
 * Una regla describe un patron de comportamiento del conjunto analizado.
 * Esta compuesta por un conjunto de condiciones que se cumplen, y el
 * resultado final de estas condiciones. Tanto las condiciones como el
 * resultado, estan definididas por el valor que toma un atributo.
 */
class Regla {

private:

	Lista<Valor*>* condiciones;

	Valor* resultado;

public:

	/**
	 * post: crea una nueva regla en principio sin condiciones ni resultado.
	 */
	Regla();

	~Regla();

	/**
	 * pre: 'condicion' - valor que representa una condicion de la regla.
	 *
	 * post: agrega la condicion al conjunto de condiciones.
	 */
	void agregarCondicion(Valor* condicion);

	/**
	 * pre: 'resultado' - resultado de la regla de decision.
	 *
	 * post: modifica el resultado de la regla.
	 */
	void setResultado(Valor* Resultado);

	/**
	 * post: retorna el conjunto de condiciones.
	 */
	Lista<Valor*>* getCondiciones() const;

	/**
	 * post: retorna el resultado
	 */
	Valor* getResultado() const;

};

#endif /* REGLA_H_ */
