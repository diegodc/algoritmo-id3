/**
 * Regla.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "Regla.h"

Regla::Regla() {

	this->condiciones = new Lista<Valor*>;
	this->resultado = NULL;
}


Regla::~Regla() {

	delete this->getCondiciones();
}


void Regla::agregarCondicion(Valor* condicion) {

	this->getCondiciones()->iterador().insertar(condicion);
}

void Regla::setResultado(Valor* resultado) {

	this->resultado = resultado;
}


Lista<Valor*>* Regla::getCondiciones() const {

	return this->condiciones;
}


Valor* Regla::getResultado() const {

	return this->resultado;
}
