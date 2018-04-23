/**
 * ID3.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef ID3_H_
#define ID3_H_

#include "Cliente.h"
#include "Atributo.h"
#include "DatoID3.h"
#include "Clasificador.h"
#include "Descriptor.h"
#include "Lista.h"
#include "Arbol.h"

/**
 * La clase ID3 implementa el algoritmo de busqueda de patrones,
 * retornando la lista de decision.
 */
class ID3 {

public:

	ID3();

	~ID3();

	/**
	 * pre: 'conjunto' - conjunto de datos a analizar, no esta vacio.
	 *      'clasificador' - es un atributo clasificador,
	 *      				 esClasificador() == true.
	 *      'descriptores' - conjunto de atributos descriptores del conjunto.
	 *
	 * post: retorna una lista de decision luego de aplicar el algoritmo
	 *       ID3 sobre el conjunto de datos.
	 *       Retorna un arbol vacio en caso los objetos pasador no cumplan
	 *       las condiciones.
	 */
	Arbol<DatoID3*>* id3(Lista<Cliente*>* conjunto, Atributo* clasificador,
						 Lista<Atributo*>* descriptores);

private:

	/**
	 * pre: 'conjunto' - conjunto de datos a analizar, no esta vacio.
	 *      'clasificador' - es un atributo clasificador,
	 *      				 esClasificador() == true.
	 *      'descriptores' - conjunto de atributos descriptores del conjunto.
	 *
	 * post: aplica el algoritmo ID3 al conjunto de datos dado,
	 *       retornando un nodo que sera la raiz del arbol.
	 */
	NodoArbol<DatoID3*>* algoritmo(Lista<Cliente*>* conjunto,
								   Atributo* clasificador,
								   Lista<Atributo*>* descriptores);

	/**
	 * post: actualiza la distribucion de datos del analizador.
	 */
	void actualizar(Lista<Cliente*>* lista, Clasificador& analizador);

	/**
	 * pre: 'analizadores' - es una lista de Descriptores creador a partir
	 *                       de los atributos clasificador y descriptor.
	 *
	 * post: actualiza la distribucion de cada uno de los analizadores
	 *       presentes en la lista.
	 */
	void actualizar(Lista<Cliente*>* lista, Lista<Descriptor*>* analizadores);

	/**
	 * pre: ya se ha actualizado la lista de analizadores.
	 *
	 * post: busca entre los analizadores el atributo descriptor
	 *       con mayor ganancia.
	 */
	Atributo* atributoConMayorGanancia(Lista<Descriptor*>* analizadores);

	/**
	 * pre: 'clasificador' - atributo clasificador del conjunto.
	 *      'descriptores' - conjunto de atributos descriptores.
	 *
	 * post: crea un Descriptor a partir de cada atributo descriptor
	 *       y retorna una lista con los analizadores creados.
	 */
	Lista<Descriptor*>* getAnalizadores(Atributo* clasificador,
										Lista<Atributo*>* descriptores);

	/**
	 * pre: 'valor' - valor mas frecuente.
	 *
	 * post: retorna un nodo que cotiene un DatoID3 resultado
	 *       con el valor mas frecuente del clasificador.
	 */
	NodoArbol<DatoID3*>* nodoConValor(Valor* valor);

	/**
	 * pre: 'atributo' - atributo con mayor ganancia.
	 *
	 * post: retorna un nodo que contiene un DatoID3 condicion con
	 *       el atributo dado.
	 */
	NodoArbol<DatoID3*>* nodoConAtributo(Atributo* atributo);

	/**
	 * post: retorna una nueva lista conteniendo solo aquellos Clientes
	 *       que tengan el valor dado.
	 */
	Lista<Cliente*>* getClientesConValor(Lista<Cliente*>* lista, Valor* valor);

	/**
	 * post: retorna una nueva lista de atributos descriptores, removiendo de
	 *       esta el atributos descriptor utilizado para dividir el conjunto.
	 */
	Lista<Atributo*>* getDescriptoresSin(Lista<Atributo*>* descriptores,
										 Atributo* atributoDivisor);

	/**
	 * pre: 'analizadoresGenerados' - lista creada por getAnalizadores(...)
	 *
	 * post: destruye la lista y todos sus elementos.
	 */
	void destruirLista(Lista<Descriptor*>* analizadoresGenerados);

};

#endif /* ID3_H_ */
