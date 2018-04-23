/**
 * PresentadorDePatrones.h
 *
 * Autor:
 *			Diego De Cristofano
 **/
#ifndef PRESENTADORDEPATRONES_H_
#define PRESENTADORDEPATRONES_H_

#include "Valor.h"
#include "Regla.h"
#include "Lista.h"

/**
 * PresentadorDePatrones se encarga de presentar al usuario las reglas
 * obtenidas en la busqueda de patrones de comportamiento.
 */
class PresentadorDePatrones {

public:

	PresentadorDePatrones();

	~PresentadorDePatrones();

	/**
	 * pre: 'reglasEncontradas' - es el conjunto de reglas obtenidas
	 *                            en la busqueda de patrones.
	 *
	 * post: muestra en pantalla las reglas obtenidas.
	 */
	void presentarPatrones(Lista<Regla*>* reglasEncontradas);

	/**
	 * post: informa que ha ocurrido un error en la busqueda.
	 */
	void presentarErrorConjuntoVacio();

private:

	/**
	 * pre: 'regla' - regla a presentar.
	 *      'numeroDeRegla' - numero de regla a presentar.
	 *
	 * post: presenta en pantalla la regla.
	 */
	void presentarRegla(Regla* regla, unsigned numeroDeRegla);

	/**
	 * post: presenta el valor en pantalla.
	 */
	void presentarValor(Valor* valor);

};

#endif /* PRESENTADORDEPATRONES_H_ */
