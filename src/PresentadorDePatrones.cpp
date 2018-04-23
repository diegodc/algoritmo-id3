/**
 * PresentadorDePatrones.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "CONSTANTES_PRESENTADOR.h"
#include "Atributo.h"
#include "PresentadorDePatrones.h"
#include <iostream>

PresentadorDePatrones::PresentadorDePatrones() {
}

PresentadorDePatrones::~PresentadorDePatrones() {
}

void
PresentadorDePatrones::presentarPatrones(Lista<Regla*>* reglasEncontradas) {

	/* si la lista esta vacia, no hay reglas para presentar */
	if (reglasEncontradas->estaVacia()) {

		std::cout << SIN_REGLAS << std::endl;

	} else {

		/* recorre la lista obteniendo y presentando las reglas */
		IteradorLista<Regla*> iterador = reglasEncontradas->iterador();

		unsigned numeroDeRegla = 1;

		while (iterador.tieneSiguiente()) {

			this->presentarRegla(iterador.siguiente(), numeroDeRegla);
			numeroDeRegla++;
		}
	}
}


void PresentadorDePatrones::presentarErrorConjuntoVacio() {

	std::cout << CONJUNTO_VACIO << std::endl;
}


void PresentadorDePatrones::presentarRegla(Regla* regla,
										   unsigned numeroDeRegla) {

	/* encabezado de la regla */
	std::cout << REGLA << numeroDeRegla << std::endl;

	IteradorLista<Valor*> iterador = regla->getCondiciones()->iterador();

	unsigned numeroDeCondicion = 1;

	/* recorre la lista de condiciones de la regla */
	while (iterador.tieneSiguiente()) {

		std::cout << TABULACION;

		if (numeroDeCondicion == 1) {

			std::cout << ENCABEZADO_PRIMERA_CONDICION;

		} else {

			std::cout << ENCABEZADO_CONDICION;
		}

		this->presentarValor(iterador.siguiente());

		std::cout << std::endl;

		numeroDeCondicion++;
	}

	/* imprime el resultado de la regla */
	std::cout << TABULACION << ENCABEZADO_RESULTADO;

	this->presentarValor(regla->getResultado());

	std::cout << std::endl << std::endl;
}


void PresentadorDePatrones::presentarValor(Valor* valor) {

	/* obtiene el nombre del atributo y el texto del valor */
	std::cout << valor->getAtributo()->getNombre()
			  << " = "
			  << valor->getTextoDelValor();
}
