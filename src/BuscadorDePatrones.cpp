/**
 * BuscadorDePatrones.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "BuscadorDePatrones.h"
#include "AnalizadorDePatrones.h"
#include "PresentadorDePatrones.h"
#include "ID3.h"

BuscadorDePatrones::BuscadorDePatrones(Lista<Cliente*>* conjunto,
					Atributo* clasificador, Lista<Atributo*>* descriptores) {

	this->setConjuntoDeDatos(conjunto);
	this->setClasificador(clasificador);
	this->setDescriptores(descriptores);
}


BuscadorDePatrones::~BuscadorDePatrones() {

	/* destruye los cada uno de los descriptores */
	this->destruirAtributosDescriptores();

	/* destruye la lista de descriptores */
	delete this->getDescriptores();

	/* destruye todos los elementos del conjunto de datos */
	this->destruirConjuntoDeDatos();

	/* destruye la lista de datos */
	delete this->getConjuntoDeDatos();

	/* destruye el atributo clasificador */
	delete this->getClasificador();
}


void BuscadorDePatrones::realizarBusqueda() {

	if (this->getConjuntoDeDatos()->estaVacia()) {

		/* crea un presentador */
		PresentadorDePatrones presentador;

		/* informa sobre el error del conjunto vacio */
		presentador.presentarErrorConjuntoVacio();

	} else {

		/* crea un objeto ID3 */
		ID3 procesadorID3;

		/* obtiene el arbol de decision */
		Arbol<DatoID3*>* arbolDeDecision
				= procesadorID3.id3(this->getConjuntoDeDatos(),
										this->getClasificador(),
											this->getDescriptores());

		/* crea un analizador */
		AnalizadorDePatrones analizador;

		/* obtiene la lista de reglas */
		Lista<Regla*>* reglas = analizador.extraerReglas(arbolDeDecision);

		/* crea un presentador */
		PresentadorDePatrones presentador;

		/* presenta las reglas */
		presentador.presentarPatrones(reglas);

		/* destruye las reglas */
		this->destruirListaDeReglas(reglas);
		delete reglas;

		/* destruye el arbol de decision */
		this->destruirDatos(arbolDeDecision->getRaiz());

		delete arbolDeDecision;
	}
}


void BuscadorDePatrones::setConjuntoDeDatos(Lista<Cliente*>* conjunto) {

	this->conjuntoDeDatos = conjunto;
}


Lista<Cliente*>* BuscadorDePatrones::getConjuntoDeDatos() const {

	return this->conjuntoDeDatos;
}


void BuscadorDePatrones::setClasificador(Atributo* clasificador) {

	this->atributoClasificador = clasificador;
}


Atributo* BuscadorDePatrones::getClasificador() const {

	return this->atributoClasificador;
}


void BuscadorDePatrones::setDescriptores(Lista<Atributo*>* descriptores) {

	this->atributosDescriptores = descriptores;
}


Lista<Atributo*>* BuscadorDePatrones::getDescriptores() const {

	return this->atributosDescriptores;
}


void BuscadorDePatrones::destruirAtributosDescriptores() {

	IteradorLista<Atributo*> iterador = this->getDescriptores()->iterador();

	while(iterador.tieneSiguiente()) {

		delete iterador.siguiente();
	}
}


void BuscadorDePatrones::destruirConjuntoDeDatos() {

	IteradorLista<Cliente*> iterador = this->getConjuntoDeDatos()->iterador();

	while(iterador.tieneSiguiente()) {

		delete iterador.siguiente();
	}
}


void BuscadorDePatrones::destruirListaDeReglas(Lista<Regla*>* reglas) {

	IteradorLista<Regla*> iterador = reglas->iterador();

	while(iterador.tieneSiguiente()) {

		delete iterador.siguiente();
	}
}


void BuscadorDePatrones::destruirDatos(NodoArbol<DatoID3*>* raiz) {

	/* destruye el dato contenido en el nodo */
	delete raiz->getDato();

	if (raiz->tieneHijos()) {

		/* realiza un recorrido recursivo sobre cada uno de los hijos */
		for(unsigned i = 1; i <= raiz->getNumeroDeHijos(); i++) {

			this->destruirDatos(raiz->getHijo(i));
		}
	}
}
