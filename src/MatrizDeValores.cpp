/**
 * MatrizDeValores.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "MatrizDeValores.h"

MatrizDeValores::MatrizDeValores(unsigned filas, unsigned columnas) {

	this->filas = filas;
	this->columnas = columnas;

	/* crea la matriz */
	this->matriz = new unsigned*[this->filas];

	for(unsigned i = 0; i < this->filas; i++) {

		matriz[i] = new unsigned[this->columnas];
	}

	/* inicializa la matriz a cero */
	for(unsigned i = 0; i < this->filas; i++) {

		for(unsigned j = 0; j < this->columnas; j++) {

			this->matriz[i][j] = 0;
		}
	}
}


MatrizDeValores::~MatrizDeValores() {

	for (unsigned i = 0; i < this->getFilas(); i++) {

		delete[] this->matriz[i];
	}

	delete[] this->matriz;
}


unsigned MatrizDeValores::getFilas() const {

	return this->filas;
}


unsigned MatrizDeValores::getColumnas() const {

	return this->columnas;
}


double MatrizDeValores::getValor(unsigned  fila, unsigned  columna) const {

	return this->matriz[fila][columna];
}


void MatrizDeValores::incrementarValor(unsigned  fila, unsigned  columna) {

	if ((fila < this->getFilas()) && columna < this->getColumnas()) {

		this->matriz[fila][columna]++;
	}
}


double MatrizDeValores::getSumatoriaDeFila(unsigned fila) const {

	double suma = 0;

	for(unsigned i = 0; i < this->getColumnas(); i++) {

		suma += this->matriz[fila][i];
	}

	return suma;
}


double MatrizDeValores::getSumatoriaDeColumna(unsigned columna) const {

	unsigned suma = 0;

	for(unsigned i = 0; i < this->getFilas(); i++) {

		suma += this->matriz[i][columna];
	}

	return suma;
}


double MatrizDeValores::getSumatoriaMatriz() const {

	unsigned suma = 0;

	for(unsigned i = 0; i < this->filas; i++) {

		for(unsigned j = 0; j < this->columnas; j++) {

			suma += this->matriz[i][j];
		}
	}

	return suma;
}
