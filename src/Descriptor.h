/**
 * Descriptor.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef DESCRIPTOR_H_
#define DESCRIPTOR_H_

#include "Valor.h"
#include "Atributo.h"
#include "MatrizDeValores.h"
#include <string>

/**
 * Descriptor realiza el analisis de los atributos descriptores permitiendo
 * obtener la ganancia del atributo.
 *
 * La clase se encarga de calcular todas las divisiones posibles,
 * analizando la distribucion de datos del atributo descriptor
 * de acuerdo al clasificador.
 */
class Descriptor {

private:

	/* referencia al atributo clasificador */
	Atributo* atributoClasificador;

	/* referencia al atributo descriptor */
	Atributo* atributoDescriptor;

	/* matriz utilizada para calcular la distribucion de datos */
	MatrizDeValores* matrizDeValores;

public:

	/**
	 * pre: 'clasificador' - atributo clasificador del conjunto.
	 *                       es un atributo clasificador.
	 *      'descriptor' - atributo descriptor del conjunto.
	 *
	 * post: crea una nueva instancia asociada al atributo dado.
	 */
	Descriptor(Atributo* atributoClasificador, Atributo* atributoDescriptor);

	/**
	 * post: destruye la matriz de valores.
	 */
	~Descriptor();

	/**
	 * post: retorna el atributo clasificador.
	 */
	Atributo* getAtributoClasificador() const;

	/**
	 * post: retorna el atributo descriptor.
	 */
	Atributo* getAtributoDescriptor() const;

	/**
	 * pre: 'valorClasificador' - es un valor del conjunto de valores
	 *                            posibles del atributo clasificador.
	 *      'valorDescriptor' - es un valor del conjunto de valores
	 *                          posibles del atributo descriptor.
	 *
	 * post: actualiza la distribucion de datos del descriptor
	 *       de acuerdo al clasificador.
	 */
	void actualizarDistribucionDeDatos(Valor* valorClasificador,
									   Valor* valorDescriptor);

	/**
	 * pre: ya se ha realizado la actualizacion de la distribucion de datos.
	 *
	 * post: retorna la ganancia del atributo descriptor.
	 */
	double getGanancia() const;

private:

	/**
	 * pre: ya se ha realizado la actualizacion de la distribucion de datos.
	 *
	 * post: retorna la entropia del atributo descriptor.
	 */
	double getEntropiaAtributo() const;

	/**
	 * pre: ya se ha realizado la actualizacion de la distribucion de datos.
	 *
	 * post: retorna la entropia del conjunto.
	 */
	double getEntropiaDelConjunto() const;

	/**
	 * post: retorna la matriz de valores.
	 */
	MatrizDeValores* getMatrizDeValores() const;

};

#endif /* DESCRIPTOR_H_ */
