/**
 * Atributo.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "Atributo.h"

Atributo::Atributo(std::string nombre, Lista<std::string>* valoresPosibles,
				   bool esClasificador) {

	/* inicializa el nombre */
	this->setNombre(nombre);

	/* numero de valores posible */
	unsigned numeroDeValores = valoresPosibles->tamanio();

	/* inicializa el numero de valores y crea el array de valores */
	this->setNumeroDeValores(numeroDeValores);

	/* recorre la lista inicializando el conjunto de valores */
	IteradorLista<std::string> iterador = valoresPosibles->iterador();
	for(unsigned i = 0; i < numeroDeValores; i++) {

		std::string textoDelValor = iterador.siguiente();

		this->setValor(textoDelValor, i);
	}

	/* destruye la lista */
	delete valoresPosibles;

	/* determina si el atributo es clasificador */
	this->setEsClasificador(esClasificador);

	/* crea el valor nulo del atributo */
	this->setValorNulo();
}


Atributo::~Atributo() {

	/* destruye todos los valores */
	for(unsigned i = 0; i < this->getNumeroDeValores(); i++) {

		delete this->valoresPosibles[i];
	}

	/* destruye el array */
	delete[] this->valoresPosibles;

	/* destruye el valor nulo */
	delete this->getValorNulo();
}


bool Atributo::esClasificador() const {

	return this->esAtributoClasificador;
}


std::string Atributo::getNombre() const {

	return this->nombre;
}


Valor* Atributo::getValorPosible(std::string textoDelValor) const {

	for(unsigned i = 0; i < this->getNumeroDeValores(); i++) {

		Valor* unValor = this->valoresPosibles[i];

		if (unValor->getTextoDelValor() == textoDelValor) {

			return unValor;
		}
	}

	return this->getValorNulo();
}


Valor* Atributo::getValorPosible(unsigned numeroDelValor) const {

	Valor* valorEncontrado;

	if ((numeroDelValor > 0)
			&& (numeroDelValor <= this->getNumeroDeValores())) {

		valorEncontrado = this->valoresPosibles[numeroDelValor - 1];

	} else {

		valorEncontrado = this->getValorNulo();
	}

	return valorEncontrado;
}


unsigned Atributo::getNumeroDeValores() const {

	return this->numeroDeValores;
}


void Atributo::setNombre(std::string nombre) {

	this->nombre = nombre;
}


void Atributo::setNumeroDeValores(unsigned numeroDeValores) {

	/* inicializa el numero de valores */
	this->numeroDeValores = numeroDeValores;

	/* crea e inicializa el array de valores */
	if (numeroDeValores > 0) {

		this->valoresPosibles = new Valor*[numeroDeValores];

		for(unsigned i = 0; i < numeroDeValores; i++) {

			this->valoresPosibles[i] = NULL;
		}

	} else {

		this->valoresPosibles = NULL;
	}
}


void Atributo::setValor(std::string textoDelValor, unsigned numeroDeValor) {

	/* crea un nuevo valor con el texto, el numero, asociado al atributo */
	Valor* nuevoValor = new Valor(textoDelValor, numeroDeValor + 1, this);

	/* lo agrega al array de valores */
	this->valoresPosibles[numeroDeValor] = nuevoValor;
}


void Atributo::setEsClasificador(bool esClasificador) {

	if (esClasificador) {

		this->esAtributoClasificador = this->getNumeroDeValores() == 2;

	} else {

		this->esAtributoClasificador = false;
	}
}


void Atributo::setValorNulo() {

	/* crea un valor no valido */
	this->valorNulo = new Valor(this);
}


Valor* Atributo::getValorNulo() const {

	return this->valorNulo;
}
