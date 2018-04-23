/**
 * NodoInexistenteException.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef NODOINEXISTENTEEXCEPTION_H_
#define NODOINEXISTENTEEXCEPTION_H_

#include <string>

/**
 * Excepcion provocada cuando se intenta acceder a un nodo que no existe.
 */
class NodoInexistenteException {

private:

	std::string mensaje;

public:

	/**
	 * post: crea una nueva instancia con el mensaje dado.
	 */
	NodoInexistenteException(std::string mensaje) {

		this->mensaje = mensaje;
	}

	~NodoInexistenteException() {
	}

	/**
	 * post: retorna el mensaje.
	 */
	std::string getMensaje() {

		return this->mensaje;
	}

private:

	/**
	 * post: inicializa el mensaje.
	 */
	void setMensaje(std::string mensaje) {

		this->mensaje = mensaje;
	}

};

#endif /* NODOINEXISTENTEEXCEPTION_H_ */
