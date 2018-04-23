/**
 * Cliente.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Valor.h"
#include "Atributo.h"
#include <string>

/**
 * Cliente modela un usuario de una linea telefonica, contiene datos
 * personales y datos sobre su cuenta.
 * La representacion de sus datos es simple, esto permite aplicar
 * con facilidad los algoritmos de busqueda de patrones.
 */
class Cliente {

private:

	/* categoria del cliente en base a la cantidad de llamadas realizadas */
	std::string categoria;

	/* grupo etario del cliente */
	std::string edad;

	std::string sexo;

	std::string estadoCivil;

public:

	/**
	 * pre: los argumentos son validos y cumplen con el formato definido.
	 *
	 *      'categoria' - categoria del cliente en base a la cantidad de
	 *                    llamadas realizadas. {NORMAL, VIP}
	 *      'edad' - grupo etario del cliente. {JOVEN, ADULTO, MAYOR}
	 *      'sexo' - sexo del cliente. {M, F}
	 *      'estadoCivil' - estado civil. {SOLTERO, CASADO, DIVORCIADO}
	 *
	 * post: crea una nueva instancia con los valores dados, no es posible
	 *       modificar los atributos de la instancia una vez creada.
	 */
	Cliente(std::string categoria, std::string edad,
			std::string sexo, std::string estadoCivil);

	/**
	 * post: destruye la instancia.
	 */
	~Cliente();

	/**
	 * post: retorna la categoria del cliente.
	 */
	std::string getCategoria() const;

	/**
	 * post: retorna la edad del cliente.
	 */
	std::string getEdad() const;

	/**
	 * post: retorna el sexo del cliente.
	 */
	std::string getSexo() const;

	/**
	 * post: retorna el estado civil del cliente.
	 */
	std::string getEstadoCivil() const;

	/**
	 * pre: 'atributo' - es un atributo que el cliente posee, el nombre del
	 *                   atributo debe ser:
	 * 					 "cateroria", "edad", "sexo" o "estado_civil"
	 *
	 * post: retorna el Valor (perteneciente al conjunto de valores posibles
	 *       del atributo), correspondiente al atributo dado.
	 *       Si no contiene el atributo, o el valor del mismo no es uno de los
	 *       valores posibles, retorna NULL.
	 */
	Valor* getValorDelAtributo(Atributo* atributo) const;

	/**
	 * post: retorna un string con la representacion del cliente.
	 */
	std::string toString() const;

private:

	/**
	 * post: modifica la categoria del cliente.
	 */
	void setCategoria(std::string categoria);

	/**
	 * post: modifica la edad del cliente.
	 */
	void setEdad(std::string edad);

	/**
	 * post: modifica el sexo del cliente.
	 */
	void setSexo(std::string sexo);

	/**
	 * post: modifica el estado civil.
	 */
	void setEstadoCivil(std::string estadoCivil);

};

#endif /* CLIENTE_H_ */
