/**
 * Valor.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef VALOR_H_
#define VALOR_H_

#include <string>

/**
 * Declaraci�n anticipada (forward declaration) de la clase Atributo.
 */
class Atributo;

/**
 * La clase representa un valor posible de un atributo.
 * Un valor esta compuesto por un texto y un numero que lo identifica
 * univocamente. Cada Valor esta asociado a un atributo, conformando
 * el conjunto de valores posibles del mismo.
 * Pueden existir valores nulos, que no son valores validos de ningun
 * atributo.
 */
class Valor {

private:

	/* string que representa el valor */
	std::string texto;

	/* numero identificatorio */
	unsigned identificacion;

	/* atributo al que corresponde */
	Atributo* atributo;

	/* determina si el valor es valido o no */
	bool esValorValido;

public:

	/**
	 * pre: 'texto' - string con la representacion del valor.
	 *      'identificacion' - numero identificatorio.
	 *      'atributo' - atributo al que corresponde.
	 *
	 * post: crea un nuevo Valor con el texto y la identificacion dada,
	 *       asociado al atributo.
	 */
	Valor(std::string texto, unsigned identificacion, Atributo* atributo);

	/**
	 * post: crea un valor NO valido, con un texto vacio, identificacion 0
	 *       asociado al atributo.
	 */
	Valor(Atributo* atributo);

	~Valor();

	/**
	 * post: retorna el valor contenido
	 */
	std::string getTextoDelValor() const;

	/**
	 * post: retorna el numero de identificacion del dato.
	 */
	unsigned getIdentificacion() const;

	/**
	 * post: retorna el atributo correspondiente al valor.
	 */
	Atributo* getAtributo() const;

	/**
	 * retorna: true si el valor es valido.
	 */
	bool esValido() const;

};

#endif /* VALOR_H_ */
