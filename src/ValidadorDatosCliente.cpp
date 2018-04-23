/**
 * ValidadorDatosCliente.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "CONSTANTES_DE_VALIDACION.h"
#include "CONSTANTES_DE_TRANSFORMACION.h"
#include "ValidadorDatosCliente.h"
#include "CSVparser.h"

#include <stdlib.h>

ValidadorDatosCliente::ValidadorDatosCliente(const std::string& datosCliente) {

	/* metodos fundamentales para la correcta inicializacion de la instancia */

	/* debe ser invocado 1�, antes que cualquie otro metodo */
	this->obtenerDatos(datosCliente);

	this->validarDatos();
}


ValidadorDatosCliente::~ValidadorDatosCliente() {
}


bool ValidadorDatosCliente::sonDatosValidos() const {

	return this->datosValidos;
}


Cliente* ValidadorDatosCliente::crearCliente() const {

	/* crea un nuevo cliente si los datos son validos */
	if (this->sonDatosValidos()) {

		std::string categoria =	this->transformarCantidadLlamadas();
		std::string edad = this->transformarEdad();
		std::string sexo = this->getSexo();
		std::string estadoCivil = this->getEstadoCivil();

		return new Cliente(categoria, edad, sexo, estadoCivil);

	} else {

		/* retorna NULL en caso que los datos no sean validos */
		return NULL;
	}
}


void ValidadorDatosCliente::obtenerDatos(const std::string& datosCliente) {

	CSVparser parser;

	/* obtiene una lista con los valores */
	Lista<std::string>* listaDatos = parser.parsearString(datosCliente);

	/* la lista debe contener 10 atributos:
	 *		(1) codigo
	 *		(2) cantidad_llamadas   REQUERIDO
	 *		(3) estado
	 *		(4) documento
	 *		(5) fecha_alta
	 *		(6) nombre
	 *		(7) apellido
	 *		(8) sexo                REQUERIDO
	 *		(9) edad                REQUERIDO
	 *		(10) estado_civil       REQUERIDO
	 *
	 * si la lista contiene los 10 elementos los asigna a
	 * los campos de la instancia, en caso contrario cada
	 * string queda vacio.
	 */
	if (listaDatos->tamanio() == 10) {

		IteradorLista<std::string> iterador = listaDatos->iterador();

		/* retorna el 1� elemento */
		iterador.siguiente();

		/* el 2� elemento es la cantidad de llamadas */
		this->setCantidadLlamadas(iterador.siguiente());

		/* se situa en el ultimo elemento de la lista */
		iterador.ultimo();

		/* los 3 ultimos elementos son datos requeridos */
		this->setEstadoCivil(iterador.anterior());
		this->setEdad(iterador.anterior());
		this->setSexo(iterador.anterior());
	}

	/* destruye la lista de datos */
	delete listaDatos;
}


void ValidadorDatosCliente::validarDatos() {

	/* valida todos los atributos del cliente */
	bool datosValidos = (this->validarSexo())
							&& (this->validarCantidadLlamadas())
							&& (this->validarEdad())
							&& (this->validarEstadoCivil());

	/* almacena el resultado de la validacion */
	this->setDatosValidos(datosValidos);
}


std::string ValidadorDatosCliente::transformarCantidadLlamadas() const {

	/* transforma la cantidad de llamadas */
	int valorCantidadLlamadas = atoi(this->getCantidadLlamadas().c_str());

	if (valorCantidadLlamadas <= LIMITE_LLAMADAS_NORMAL) {

		return CLIENTE_CATEGORIA_NORMAL;

	} else {

		return CLIENTE_CATEGORIA_VIP;
	}
}


std::string ValidadorDatosCliente::transformarEdad() const {

	/* transforma la edad */
	int valorEdad = atoi(this->getEdad().c_str());

	if (valorEdad <= EDAD_LIMITE_JOVEN) {

		return CLIENTE_EDAD_JOVEN;

	} else if (valorEdad <= EDAD_LIMITE_ADULTO) {

		return CLIENTE_EDAD_ADULTO;

	} else {

		return CLIENTE_EDAD_MAYOR;
	}
}


bool ValidadorDatosCliente::validarCantidadLlamadas() const {

	int valorCantidadLlamadas = atoi(this->getCantidadLlamadas().c_str());

	return (valorCantidadLlamadas > 0);
}


bool ValidadorDatosCliente::validarEdad() const {

	int valorEdad = atoi(this->getEdad().c_str());

	return ((valorEdad >= EDAD_MINIMA)
				&& (valorEdad <= EDAD_MAXIMA));
}


bool ValidadorDatosCliente::validarSexo() const {

	std::string sexo = this->getSexo();

	return ((sexo == SEXO_MASCULINO) || (sexo == SEXO_FEMENINO));
}


bool ValidadorDatosCliente::validarEstadoCivil() const {

	std::string estadoCivil = this->getEstadoCivil();

	return ((estadoCivil == ESTADO_CIVIL_CASADO)
				|| (estadoCivil == ESTADO_CIVIL_SOLTERO)
				|| (estadoCivil == ESTADO_CIVIL_DIVORCIADO));
}


std::string ValidadorDatosCliente::getCantidadLlamadas() const {

	return this->cantidadLlamadas;
}


std::string ValidadorDatosCliente::getEdad() const {

	return this->edad;
}


std::string ValidadorDatosCliente::getSexo() const {

	return this->sexo;
}


std::string ValidadorDatosCliente::getEstadoCivil() const {

	return this->estadoCivil;
}


void ValidadorDatosCliente::setCantidadLlamadas(std::string cantidadLlamadas) {

	this->cantidadLlamadas = cantidadLlamadas;
}


void ValidadorDatosCliente::setEdad(std::string edad) {

	this->edad = edad;
}


void ValidadorDatosCliente::setSexo(std::string sexo) {

	this->sexo = sexo;
}


void ValidadorDatosCliente::setEstadoCivil(std::string estadoCivil) {

	this->estadoCivil = estadoCivil;
}


void ValidadorDatosCliente::setDatosValidos(bool datosValidos) {

	this->datosValidos = datosValidos;
}
