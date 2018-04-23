/**
 * AnalizadorDePatrones.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "AnalizadorDePatrones.h"

AnalizadorDePatrones::AnalizadorDePatrones() {
}

AnalizadorDePatrones::~AnalizadorDePatrones() {
}


Lista<Regla*>*
AnalizadorDePatrones::extraerReglas(Arbol<DatoID3*>* arbolDeDecision) {

	/* crea la lista de reglas encontradas */
	Lista<Regla*>* reglasEncontradas = new Lista<Regla*>;

	/* si el arbol no esta vacio */
	if(!arbolDeDecision->estaVacio()) {

		/* lo recorre extrayendo las reglas */
		this->recorrer(arbolDeDecision->getRaiz(), reglasEncontradas);
	}

	/* retorna la lista de reglas */
	return reglasEncontradas;
}


void AnalizadorDePatrones::recorrer(NodoArbol<DatoID3*>* raiz,
									Lista<Regla*>* reglas) {

	/* si el nodo contiene un dato resultado */
	if (raiz->getDato()->esResultado()) {

		/* extre la regla */
		Regla* unaRegla = this->extraerRegla(raiz);

		/* la inserta en la lista */
		reglas->agregar(unaRegla);
	}

	if (raiz->tieneHijos()) {

		/* realiza un recorrido recursivo sobre cada uno de los hijos */
		for(unsigned i = 1; i <= raiz->getNumeroDeHijos(); i++) {

			this->recorrer(raiz->getHijo(i), reglas);
		}
	}
}


Regla* AnalizadorDePatrones::extraerRegla(NodoArbol<DatoID3*>* unNodo) {

	/* crea una regla */
	Regla* unaRegla = new Regla;

	/* obtiene el valor resultado del dato contenido en el nodo */
	Valor* valorResultado = unNodo->getDato()->getValorResultado();

	/* asigna el valor como resultado de la regla */
	unaRegla->setResultado(valorResultado);

	/* recorre el arbol obteniendo los valores antecedentes */
	while (unNodo->tienePadre()) {

		/* obtiene el valor antecedente del dato contenido en el nodo */
		Valor* valorAntecedente = unNodo->getDato()->getAntecedente();

		/* asigna el valor como condicion de la regla */
		unaRegla->agregarCondicion(valorAntecedente);

		/* se mueve hacia el nodo padre */
		unNodo = unNodo->getPadre();
	}

	return unaRegla;
}
