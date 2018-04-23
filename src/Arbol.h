/**
 * Arbol.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef ARBOL_H_
#define ARBOL_H_

#include "NodoArbol.h"

/**
 * La clase arbol es una estructura de datos simple, conformada
 * por un nodo raiz y un posible numero de hijos.
 */
template<class T> class Arbol {

private:

	NodoArbol<T>* raiz;

public:

	/**
	 * post: crea un arbol con la raiz dada, si se omite, crea un arbol vacio.
	 */
	Arbol(NodoArbol<T>* raiz = NULL) {

		this->setRaiz(raiz);
	}

	/**
	 * post: destruye la raiz, y todos los nodos que conforman el arbol.
	 */
	~Arbol() {

		delete this->raiz;
	}

	/**
	 * post: retorna 'true' si el arbol esta vacio.
	 */
	bool estaVacio() const {

		return (this->getRaiz() == NULL);
	}

	/**
	 * post: el arbol no esta vacio.
	 *
	 * post: retorna la raiz del arbol.
	 */
	NodoArbol<T>* getRaiz() const {

		return this->raiz;
	}

private:

	/**
	 * post: inicializa la raiz del arbol.
	 */
	void setRaiz(NodoArbol<T>* raiz) {

		this->raiz = raiz;
	}

};

#endif /* ARBOL_H_ */
