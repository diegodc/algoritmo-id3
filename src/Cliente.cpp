/**
 * Cliente.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "CONSTANTES_ATRIBUTOS_CLIENTE.h"
#include "Cliente.h"
#include <sstream>

Cliente::Cliente(std::string categoria, std::string edad,
				 std::string sexo, std::string estadoCivil) {

	this->setCategoria(categoria);
	this->setEdad(edad);
	this->setSexo(sexo);
	this->setEstadoCivil(estadoCivil);
}


Cliente::~Cliente() {
}


std::string Cliente::getCategoria() const {

	return this->categoria;
}


std::string Cliente::getEdad() const {

	return this->edad;
}


std::string Cliente::getSexo() const {

	return this->sexo;
}


std::string Cliente::getEstadoCivil() const {

	return this->estadoCivil;
}


Valor* Cliente::getValorDelAtributo(Atributo* atributo) const {

	std::string nombreAtributo = atributo->getNombre();

	std::string valor;

	if (nombreAtributo == NOMBRE_ATRIBUTO_CATEGORIA) {

		valor = this->getCategoria();

	} else if (nombreAtributo == NOMBRE_ATRIBUTO_EDAD) {

		valor = this->getEdad();

	} else if (nombreAtributo == NOMBRE_ATRIBUTO_ESTADOCIVIL) {

		valor = this->getEstadoCivil();

	} else if (nombreAtributo == NOMBRE_ATRIBUTO_SEXO) {

		valor = this->getSexo();
	}

	return atributo->getValorPosible(valor);
}


std::string Cliente::toString() const {

	std::stringstream string;

	string << "Cliente "
		   << this->getCategoria()
		   << " - Sexo: "
		   << this->getSexo()
		   << ", "
		   << this->getEstadoCivil()
		   << " - Edad: "
		   << this->getEdad();

	return string.str();
}


void Cliente::setCategoria(std::string categoria) {

	this->categoria = categoria;
}


void Cliente::setEdad(std::string edad) {

	this->edad = edad;
}


void Cliente::setSexo(std::string sexo) {

	this->sexo = sexo;
}


void Cliente::setEstadoCivil(std::string estadoCivil) {

	this->estadoCivil = estadoCivil;
}
