/**
 * DatoID3.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "DatoID3.h"

DatoID3::DatoID3(Atributo* atributo) {

	this->setAtributo(atributo);
	this->setValorResultado(NULL);
	this->setAntecente(NULL);
}

DatoID3::DatoID3(Valor* valor) {

	this->setAtributo(valor->getAtributo());
	this->setValorResultado(valor);
}

DatoID3::~DatoID3() {
}


Atributo* DatoID3::getAtributo() const {

	return this->atributo;
}


bool DatoID3::esResultado() const {

	return this->valorResultado != NULL;
}


Valor* DatoID3::getValorResultado() const {

	return this->valorResultado;
}


void DatoID3::setAntecente(Valor* valorAntecedente) {

	this->valorAntecedente = valorAntecedente;
}


Valor* DatoID3::getAntecedente() const {

	return this->valorAntecedente;
}


bool DatoID3::tieneAntecedente() const {

	return this->getAntecedente() != NULL;
}


void DatoID3::setAtributo(Atributo* atributo) {

	this->atributo = atributo;
}


void DatoID3::setValorResultado(Valor* valor) {

	this->valorResultado = valor;
}
