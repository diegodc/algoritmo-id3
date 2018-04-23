/**
 * Atributo.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef ATRIBUTO_H_
#define ATRIBUTO_H_

#include "Valor.h"
#include "Lista.h"
#include <string>

/**
 * La clase representa un atributo. Un atributo posee un nombre y
 * el conjunto de valores posibles que puede tomar.
 * Cada valor posible esta asociado al atributo que lo contiene.
 * Un atributo puede ser marcado como calificador, para esto solo
 * puede tener 2 valores posibles.
 */
class Atributo {

private:

	/* nombre del atributo */
	std::string nombre;

	/* conjunto de valores posibles */
	Valor** valoresPosibles;

	/* numero de valores del atributo */
	unsigned numeroDeValores;

	/* indica si el atributo es calificador o no */
	bool esAtributoClasificador;

	/* valor nulo retornado en caso de una busqueda no exitosa */
	Valor* valorNulo;

public:

	/**
	 * pre: 'nombre' - nombre del atributo.
	 *      'valoresPosibles' - conjunto de valores posibles del atributo.
	 *      'esClasificador' - indica si el atributo sera utilizado como
	 *                         clasificador. Si es asi, solo puede tener
	 *                         2 valores posibles.
	 *
	 * post: crea un nuevo Atributo con el nombre dado y crea el conjunto
	 *       de valores asociados al atributo. Los valores son creados con el
	 *       texto tomado de la lista 'valoresPosibles' y son identificados
	 *       con numeros consecutivos comenzando en 1.
	 *
	 *       Si el atributo es marcado como clasificador, comprueba
	 *       que cumpla con los requisitos definidos.
	 *
	 *       Destruye la lista de valores posibles.
	 */
	Atributo(std::string nombre, Lista<std::string>* valoresPosibles,
			 bool esClasificador = false);

	/**
	 * post: libera los recursos asociados.
	 */
	~Atributo();

	/**
	 * post: retorna 'true' si el atributo fue creado como calificador y
	 *       cumple con los requisitos para serlo.
	 */
	bool esClasificador() const;

	/**
	 * post: retorna el nombre del atributo.
	 */
	std::string getNombre() const;

	/**
	 * pre: 'textoDelValor' - string que representa un valor del atributo.
	 *
	 * post: busca entre los valores posibles si existe un valor
	 *       que corresponda con el parametro dado.
	 *
	 * retorno: el valor encontrado, en caso que no se encuentre,
	 *          retorna un valor nulo.
	 */
	Valor* getValorPosible(std::string textoDelValor) const;

	/**
	 * pre: 'numeroDelValor' - 0 < 'numeroDelValor' <= getNumeroDeValores()
	 *
	 * post: retorna el valor correspondiente al numero dado.
	 *       retorna un valor nulo si el numero del valor es incorrecto.
	 */
	Valor* getValorPosible(unsigned numeroDelValor) const;

	/**
	 * post: retorna el numero de valores posibles del atributo.
	 */
	unsigned getNumeroDeValores() const;

private:

	/**
	 * metodo privado invocado desde el constructor,
	 * inicializa los datos de la instancia.
	 *
	 * post: inicializa el nombre del atributo.
	 */
	void setNombre(std::string nombre);

	/**
	 * metodo privado invocado desde el constructor,
	 * inicializa los datos de la instancia.
	 *
	 * post: inicializa el numero de valores del atributo.
	 *       inicializa el conjunto de valores.
	 */
	void setNumeroDeValores(unsigned numeroDeValores);

	/**
	 * metodo privado invocado desde el constructor,
	 * inicializa los datos de la instancia.
	 *
	 * pre: 'textoDelValor' - representa un valor posible del atributo.
	 *      'numeroDeValor' - numero del valor, identifica la posicion
	 *                        en el array.
	 *
	 * post: crea un nuevo valor y lo agrega al conjunto de valores.
	 */
	void setValor(std::string textoDelValor, unsigned numeroDeValor);

	/**
	 * metodo privado invocado desde el constructor,
	 * inicializa los datos de la instancia.
	 *
	 * pre: se ha inicializado el conjunto de valores.
	 *
	 * post: detemina si el atributo puede ser clasificador, e
	 *       inicializa el valor del campo 'esAtributoClasificador'.
	 */
	void setEsClasificador(bool esClasificador);

	/**
	 * post: inizializa el valor nulo del atributo.
	 */
	void setValorNulo();

	/**
	 * post: retorna el valor nulo del atributo.
	 */
	Valor* getValorNulo() const;

};

#endif /* ATRIBUTO_H_ */
