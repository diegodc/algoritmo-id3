/**
 * Descriptor.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "Descriptor.h"
#include "CalculadorEntropia.h"

#ifndef FILAS_MATRIZ
#define FILAS_MATRIZ 2
#endif

/**
 * Para contabilizar la distrubucion de los datos se utiliza una matriz
 * de enteros. Esta matriz tiene 2 filas para cada uno de los valores
 * posibles del atributo clasificador, y tantas columnas como valores
 * tenga el descriptor.
 * Los numeros identificatorios de los valores son utilizados como
 * indice en la matriz de datos.
 *
 * La matriz queda compuesta de la siguiente forma:
 *
 * --|-----------------------------------------------------------------------|
 *   |        Valor 1        |        Valor 2        |        Valor N        |
 * --|-----------------------------------------------------------------------|
 * A | casos 'A' del Valor 1 | casos 'A' del Valor 2 | casos 'A' del Valor N |
 * --|-----------------------------------------------------------------------|
 * B | casos 'B' del Valor 1 | casos 'B' del Valor 2 | casos 'B' del Valor N |
 * --|-----------------------------------------------------------------------|
 *
 * 'A' y 'B' representan los 2 valores posibles del clasificador.
 */

Descriptor::Descriptor(Atributo* clasificador,
										   Atributo* descriptor) {

	this->atributoClasificador = clasificador;
	this->atributoDescriptor = descriptor;

	this->matrizDeValores =
		new MatrizDeValores(FILAS_MATRIZ, descriptor->getNumeroDeValores());
}


Descriptor::~Descriptor() {

	delete this->getMatrizDeValores();
}


Atributo* Descriptor::getAtributoClasificador() const {

	return this->atributoClasificador;
}

Atributo* Descriptor::getAtributoDescriptor() const {

	return this->atributoDescriptor;
}


void Descriptor::actualizarDistribucionDeDatos(
				Valor* valorClasificador, Valor* valorDescriptor) {

	if ((valorClasificador->getAtributo() == this->getAtributoClasificador())
		&& (valorDescriptor->getAtributo() == this->getAtributoDescriptor())) {

		MatrizDeValores* matriz = this->getMatrizDeValores();

		unsigned fila = valorClasificador->getIdentificacion() - 1;
		unsigned columna = valorDescriptor->getIdentificacion() - 1;

		/* dados los dos valores, se utiliza su numero identificatorio
		 * para calcular la posicion en la matriz y actualizar la
		 * distribucion de datos. Los valores del atributo estan
		 * identificados de 1 a n, por lo tanto es necesario restarle 1
		 * al numero identificatorio del valor
		 */
		matriz->incrementarValor(fila, columna);
	}
}


double Descriptor::getGanancia() const {

	return (this->getEntropiaDelConjunto() - this->getEntropiaAtributo());
}


double Descriptor::getEntropiaAtributo() const {

	MatrizDeValores* matriz = this->getMatrizDeValores();

	/* entropia del atributo */
	double entropia = 0;

	/* numero total de casos */
	double totalCasos = matriz->getSumatoriaMatriz();

	/* calculador de entropia */
	CalculadorEntropia calculador;

	/* recorre las columnas de la matriz, analizando cada valor */
	for(unsigned i = 0; i < matriz->getColumnas(); i++) {

		/*
		 * el valor de la 1� fila, representa la cantidad de apariciones
		 * del valor i del atributo correspondientes al valor 'A' del
		 * clasificador
		 */
		double casosValorA = matriz->getValor(0, i);
		double casosValorB = matriz->getValor(1, i);

		/* numero de casos totales del valor i */
		double totalParcial = casosValorA + casosValorB;


		/* probabilidad del valor 0 */
		double probabilidadA =
				calculador.probabilidad(casosValorA, totalParcial);

		/* probabilidad del valor 1 */
		double probabilidadB =
				calculador.probabilidad(casosValorB, totalParcial);


		/* entropia del valor i */
		double entropiaValor =
				calculador.entropia(probabilidadA, probabilidadB);

		/* probabilidad que ocurra el valor i */
		double probabilidadGeneral =
				calculador.probabilidad(totalParcial, totalCasos);

		/* calculo final de la entropia del atributo */
		entropia += probabilidadGeneral * entropiaValor;
	}

	return entropia;
}


double Descriptor::getEntropiaDelConjunto() const {

	/* numero de casos para el primer valor del clasificador */
	double casosValorA = this->getMatrizDeValores()->getSumatoriaDeFila(0);

	/* numero de casos para el segundo valor del clasificador */
	double casosValorB = this->getMatrizDeValores()->getSumatoriaDeFila(1);

	/* numero de casos totales es la suma de los casos */
	double casosTotales = casosValorA + casosValorB;

	/* calculador de entropia */
	CalculadorEntropia calculador;

	/* probabilidad del valor 1 */
	double probabilidadA = calculador.probabilidad(casosValorA, casosTotales);

	/* probabilidad del valor 2 */
	double probabilidadB = calculador.probabilidad(casosValorB, casosTotales);

	/* entropia del conjunto */
	double entropia = calculador.entropia(probabilidadA, probabilidadB);

	return entropia;
}


MatrizDeValores* Descriptor::getMatrizDeValores() const {

	return this->matrizDeValores;
}
