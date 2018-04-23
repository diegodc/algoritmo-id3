/**
 * BuscadorDePatrones.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef BUSCADORDEPATRONES_H_
#define BUSCADORDEPATRONES_H_

#include "Cliente.h"
#include "Atributo.h"
#include "Regla.h"
#include "DatoID3.h"
#include "Arbol.h"
#include "Lista.h"

/**
 * BuscadorDePatrones recibe el conjunto de datos a analizar, su atributo
 * clasificador, y el conjunto de atributos descriptores. Realiza la busqueda
 * de patrones y los presenta en pantalla.
 */
class BuscadorDePatrones {

	/* conjunto de datos */
	Lista<Cliente*>* conjuntoDeDatos;

	/* atributo clasificador del conjunto */
	Atributo* atributoClasificador;

	/* conjunto de atributos descriptores del conjunto */
	Lista<Atributo*>* atributosDescriptores;

public:

	/**
	 * pre: 'conjunto' - conjunto sobre el que se realizara la busqueda.
	 *      'clasificador' - atributo clasificador del conjunto.
	 *      'descriptores' - conjunto de atributos clasificadores.
	 *
	 * post: crea un nuevo buscador asociado a los objetos dados.
	 */
	BuscadorDePatrones(Lista<Cliente*>* conjunto, Atributo* clasificador,
					   Lista<Atributo*>* descriptores);

	/**
	 * post: libera los recursos de la instancia.
	 */
	~BuscadorDePatrones();

	/**
	 * post: inicia la busqueda de patrones, y presenta los resultados.
	 */
	void realizarBusqueda();

private:

	/**
	 * post: inicializa el conjunto de datos.
	 */
	void setConjuntoDeDatos(Lista<Cliente*>* conjunto);

	/**
	 * post: retorna el conjunto de datos.
	 */
	Lista<Cliente*>* getConjuntoDeDatos() const;

	/**
	 * post: inicializa el atributo clasificador.
	 */
	void setClasificador(Atributo* clasificador);

	/**
	 * post: retorna el atributo clasificador del conjunto.
	 */
	Atributo* getClasificador() const;

	/**
	 * post: inicializa el conjunto de atributos descriptores.
	 */
	void setDescriptores(Lista<Atributo*>* descriptores);

	/**
	 * post: retorna el conjunto de atributos descriptores.
	 */
	Lista<Atributo*>* getDescriptores() const;

	/**
	 * metodo privado de la clase invocado desde el destructor.
	 *
	 * post: destruye el conjunto de descriptores.
	 */
	void destruirAtributosDescriptores();

	/**
	 * metodo privado de la clase invocado desde el destructor.
	 *
	 * post: destruye el conjunto de clientes.
	 */
	void destruirConjuntoDeDatos();

	/**
	 * post: destruye las reglas encontradas.
	 */
	void destruirListaDeReglas(Lista<Regla*>* reglas);

	/**
	 * pre: el arbol no esta vacio.
	 *
	 * post: destruye los DatosID3 contenidos en el arbol.
	 */
	void destruirDatos(NodoArbol<DatoID3*>* raiz);

};

#endif /* BUSCADORDEPATRONES_H_ */
