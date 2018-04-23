/**
 * Valor.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "Valor.h"

Valor::Valor(std::string texto, unsigned identificacion, Atributo* atributo) {

	this->texto = texto;
	this->identificacion = identificacion;
	this->atributo = atributo;
	this->esValorValido = true;
}


Valor::Valor(Atributo* atributo) {

	this->texto = "";
	this->identificacion = 0;
	this->atributo = atributo;
	this->esValorValido = false;
}


Valor::~Valor() {
}


std::string Valor::getTextoDelValor() const {

	return this->texto;
}


unsigned Valor::getIdentificacion() const {

	return this->identificacion;
}


Atributo* Valor::getAtributo() const {

	return this->atributo;
}


bool Valor::esValido() const {

	return this->esValorValido;
}
