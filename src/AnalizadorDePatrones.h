/**
 * AnalizadorDePatrones.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef ANALIZADORDEPATRONES_H_
#define ANALIZADORDEPATRONES_H_

#include "DatoID3.h"
#include "Regla.h"
#include "Arbol.h"
#include "Lista.h"

/**
 * AnalizadorDePatrones utiliza la lista de decision obtenida
 * y extrae de la misma las reglas encontradas.
 */
class AnalizadorDePatrones {

public:

	AnalizadorDePatrones();

	~AnalizadorDePatrones();

	/**
	 * post: recorre el arrbol de decision extrayendo las reglas encontradas.
	 */
	Lista<Regla*>* extraerReglas(Arbol<DatoID3*>* arbolDeDecision);

private:

	/**
	 * pre: 'reglas' - lista donde se insertaran las reglas extraidas.
	 * 		'raiz' - nodo raiz del arbol.
	 *
	 * post: recorre el arbol extrayendo las reglas e insertandolas en la
	 *       lista de reglas.
	 */
	void recorrer(NodoArbol<DatoID3*>* raiz, Lista<Regla*>* reglas);

	/**
	 * pre: 'unNodo' - nodo que contiene un DatoID3 resultado.
	 *                 unNodo->getDato()->esResultado() == true.
	 *
	 * post: procesa el nodo y recorre el arbol extrayendo los
	 *       valores de la regla.
	 *       Retorna la regla creada.
	 */
	Regla* extraerRegla(NodoArbol<DatoID3*>* unNodo);

};

#endif /* ANALIZADORDEPATRONES_H_ */
