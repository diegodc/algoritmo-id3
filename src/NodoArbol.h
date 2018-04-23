/**
 * NodoArbol.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef NODOARBOL_H_
#define NODOARBOL_H_

#include "NodoInexistenteException.h"

/**
 * Un nodo contiene un dato, y numero de hijos dado.
 */
template<class T> class NodoArbol {

private:

	/* dato contenido por el nodo */
	T dato;

	/* nodo padre */
	NodoArbol<T>* padre;

	/* array de hijos */
	NodoArbol<T>** hijos;

	/* numero de hijos del nodo */
	unsigned numeroDeHijos;

public:

	/**
	 * post: crea un nuevo nodo con el dato, el nodo es creado sin hijos.
	 */
	NodoArbol(T dato) {

		this->setDato(dato);
		this->hijos = NULL;
		this->setPadre(NULL);
		this->setNumeroDeHijos(0);
	}

	/**
	 * post: destruye al nodo, y sus hijos.
	 */
	~NodoArbol() {

		/* destruye cada uno de los hijos */
		for(unsigned i = 0; i < this->getNumeroDeHijos(); i++) {

			delete this->hijos[i];
		}

		/* destruye el array */
		delete this->hijos;
	}

	/**
	 * post: retorna 'true' si el nodo tiene hijos.
	 */
	bool tieneHijos() const {

		return (this->numeroDeHijos != 0);
	}

	/**
	 * post: retorna 'true' si el nodo tiene padre.
	 */
	bool tienePadre() const {

		return (this->getPadre() != NULL);
	}
	/**
	 * post: crea un nuevo nodo con el dato, y lo agrega como hijo.
	 */
	void agregarHijo(NodoArbol<T>* nuevoNodo) {

		/* inicializa el padre del nuevo nodo */
		nuevoNodo->setPadre(this);

		/* tama�o del nuevo array de nodos */
		unsigned nuevoNumeroDeHijos = this->getNumeroDeHijos() + 1;


		/* crea un nuevo array de de nodos */
		NodoArbol<T>** hijosNuevos = new NodoArbol<T>*[nuevoNumeroDeHijos];


		/* copia al nuevo vector los hijos existentes */
		for(unsigned i = 0; i < this->getNumeroDeHijos(); i++) {

			hijosNuevos[i] = this->hijos[i];
		}

		/* agrega el nuevo nodo al array */
		hijosNuevos[this->getNumeroDeHijos()] = nuevoNodo;

		/* modifica el numero de hijos */
		this->setNumeroDeHijos(nuevoNumeroDeHijos);

		/* destruye el array en desuso */
		delete this->hijos;

		/* modifica el array de hijos con el nuevo array */
		this->hijos = hijosNuevos;
	}

	/**
	 * post: inicializa el dato contenido por el nodo.
	 */
	void setDato(T dato) {

		this->dato = dato;
	}

	/**
	 * post: retorna el dato contenido por el nodo.
	 */
	T getDato() const {

		return this->dato;
	}

	/**
	 * post: retorna el numero de hijos que tiene el nodo.
	 */
	unsigned getNumeroDeHijos() const {

		return this->numeroDeHijos;
	}

	/**
	 * pre: 'numeroDeHijo' - numero de hijo que se desea obtener.
	 *                       0 < numeroDeHijo <= getNumeroDeHijos()
	 *
	 * post: retorna el hijo correspondiente al numero dado.
	 *       Si 'numeroDeHijo' esta fuera de rango, arroja una excepcion.
	 */
	NodoArbol<T>* getHijo(unsigned numeroDeHijo) const {

		if ((numeroDeHijo > 0) && (numeroDeHijo <= this->getNumeroDeHijos())) {

			return this->hijos[numeroDeHijo - 1];

		} else {

			throw NodoInexistenteException("No se puede obtener el Nodo");
		}
	}

	/**
	 * post: retorna el nodo padre.
	 */
	NodoArbol<T>* getPadre() const {

		return this->padre;
	}

private:

	/**
	 * post: inicializa el nodo padre.
	 */
	void setPadre(NodoArbol<T>* padre) {

		this->padre = padre;
	}

	/**
	 * post: inicializa el valor del numero de hijos del nodo.
	 */
	void setNumeroDeHijos(unsigned numeroDeHijos) {

		this->numeroDeHijos = numeroDeHijos;
	}

};

#endif /* NODOARBOL_H_ */
