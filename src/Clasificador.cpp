/**
 * Clasificador.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "Clasificador.h"
#include "CalculadorEntropia.h"
#include <iostream>

/**
 * Para contabilizar la distrubucion de los datos se utiliza un array
 * de dos posiciones, donde cada posicion representa uno de los valores
 * del atributo clasificador.
 * El numero identificatorio del valor es utilizado como indice del array.
 * Como la identificacion de valores comienza en 1, es necesario restar 1
 * a tal numero para utilizar como indice.
 */

Clasificador::Clasificador(Atributo* clasificador) {

	this->atributoClasificador = clasificador;

	for(unsigned i = 0; i < TAMANIO_ARRAY; i++) {

		this->valores[i] = 0;
	}
}

Clasificador::~Clasificador() {
}

void Clasificador::actualizarDistribucion(Valor* valor) {

	/* calcula el indice del valor */
	unsigned indice = valor->getIdentificacion() - 1;

	/* comprueba que el valor se uno de los valores del clasificador */
	if ((indice < TAMANIO_ARRAY)
			&& (valor->getAtributo() == this->getAtributoClasificador())) {

		this->valores[indice]++;
	}
}

bool Clasificador::tienenMismoValor() const {

	bool tienenMismoValor = false;

	/* si alguno de los dos valores tuvo casos positivos */
	if ((this->valores[0] != 0) || (this->valores[1] != 0)) {

		/* tienen el mismo valor si alguno no tuvo casos positivos */
		tienenMismoValor = (this->valores[0] == 0)|| (this->valores[1] == 0);
	}

	return tienenMismoValor;
}


Valor* Clasificador::getValorMasFrecuente() const {

	unsigned indiceValorMasFrecuente = 0;

	/* calcula cual es el indice del valor mas frecuente */
	if (this->valores[0] > this->valores[1]) {

		indiceValorMasFrecuente = 0;

	} else {

		indiceValorMasFrecuente = 1;
	}

	Atributo* clasificador = this->getAtributoClasificador();

	/* retorna el valor mas frecuente del clasificador */
	return clasificador->getValorPosible(indiceValorMasFrecuente + 1);
}


Atributo* Clasificador::getAtributoClasificador() const {

	return this->atributoClasificador;
}
