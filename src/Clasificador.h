/**
 * Clasificador.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef CLASIFICADOR_H_
#define CLASIFICADOR_H_

#ifndef TAMANIO_ARRAY
#define TAMANIO_ARRAY 2
#endif

#include "Valor.h"
#include "Atributo.h"
#include <string>

/**
 * Clasificador realiza el analisis del atributo clasificador del conjunto.
 *
 * Calcula la distribucion de datos del atributo clasificador, permitiendo
 * conocer el valor mas frecuente, y determinar si todos los registros
 * tuvieron el mismo valor.
 */
class Clasificador {

private:

	/* referencia al atributo clasificador */
	Atributo* atributoClasificador;

	/* array utilizado para contabilizar la distribucion de datos */
	unsigned valores[TAMANIO_ARRAY];

public:

	/**
	 * pre: 'clasificador' - es un atributo clasificador.
	 *
	 * post: crea un nuevo analizador asociado al atributo.
	 */
	Clasificador(Atributo* clasificador);

	/**
	 * post: destruye el array de valores.
	 */
	~Clasificador();

	/**
	 * pre: 'valor' - es un valor del conjunto de valores posibles
	 *                del clasificador.
	 *
	 * post: actualiza la distribucion de datos del clasificador.
	 */
	void actualizarDistribucion(Valor* valor);

	/**
	 * pre: ya se ha realizado la actualizacion de la distribucion de datos.
	 *
	 * post: retorna 'true' si solo uno de los 2 valores del clasificador
	 *       ha tenido casos positivos.
	 */
	bool tienenMismoValor() const;

	/**
	 * pre: ya se ha realizado la actualizacion de la distribucion de datos.
	 *
	 * post: retorna el valor mas frecuente.
	 */
	Valor* getValorMasFrecuente() const;

	/**
	 * post: retorna el atributo clasificador.
	 */
	Atributo* getAtributoClasificador() const;

};

#endif /* CLASIFICADOR_H_ */
