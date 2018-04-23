/**
 * ValidadorDatosCliente.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef VALIDADORDATOSCLIENTE_H_
#define VALIDADORDATOSCLIENTE_H_

#include "Cliente.h"
#include "Lista.h"
#include <string>

/**
 * La clase procesa y valida los datos tomados del archivo de clientes,
 * creando una nueva instancia de Cliente a partir de los mismos.
 */
class ValidadorDatosCliente {

private:

	/* datos del cliente */
	std::string cantidadLlamadas;

	std::string edad;

	std::string sexo;

	std::string estadoCivil;

	/* determina si los datos son validos */
	bool datosValidos;

public:

	/**
	 * pre: 'datosCliente' - string obtenido del archivo de clientes.
	 *
	 * post: la nueva instancia procesa y valida los atributos del cliente.
	 */
	ValidadorDatosCliente(const std::string& datosCliente);

	~ValidadorDatosCliente();

	/**
	 * post: retorna true si los datos del cliente son validos, y es
	 *       posible generar un Cliente a partir de los mismos.
	 */
	bool sonDatosValidos() const;

	/**
	 * pre: sonDatosValidos() == true.
	 *
	 * post: crea un nuevo cliente a partir de los datos dados. En caso
	 *       que los datos no sean validos, retorna NULL.
	 *       Los datos del cliente son transformados al formato definido,
	 *       previo a que el cliente sea creado.
	 */
	Cliente* crearCliente() const;

private:

	/**
	 * metodo privado invocado desde el constructor,
	 * inicializa los datos de la instancia.
	 *
	 * pre: 'datosCliente' - mismo string recibido como
	 *      argumento en el constructor.
	 *
	 * post: extrae del string los datos requeridos.
	 */
	void obtenerDatos(const std::string& datosCliente);

	/**
	 * metodo privado invocado desde el constructor,
	 * inicializa los datos de la instancia.
	 *
	 * pre: obtenerDatos(...) ya ha sido invocado.
	 *
	 * post: valida los datos datos del cliente.
	 */
	void validarDatos();

	/**
	 * pre: sonDatosValidos() == true.
	 *
	 * post: transforma el atributo cantidad de llamadas
	 *       retornando la categoria del cliente.
	 */
	std::string transformarCantidadLlamadas() const;

	/**
	 * pre: sonDatosValidos() == true.
	 *
	 * post: transforma el atributo edad retornando
	 *       el grupo etario del cliente.
	 */
	std::string transformarEdad() const;

	/**
	 * post: valida el valor del atributo cantidadLlamadas.
	 *
	 * retorno: true si es un valor valido.
	 */
	bool validarCantidadLlamadas() const;

	/**
	 * post: valida el valor del atributo edad.
	 *
	 * retorno: true si es un valor valido.
	 */
	bool validarEdad() const;

	/**
	 * post: valida el valor del atributo sexo.
	 *
	 * retorno: true si es un valor valido.
	 */
	bool validarSexo() const;

	/**
	 * post: valida el valor del atributo estadoCivil.
	 *
	 * retorno: true si es un valor valido.
	 */
	bool validarEstadoCivil() const;

	/**
	 * post: retorna el atributo cantidadLlamadas.
	 */
	std::string getCantidadLlamadas() const;

	/**
	 * post: retorna el atributo edad.
	 */
	std::string getEdad() const;

	/**
	 * post: retorna el atributo sexo.
	 */
	std::string getSexo() const;

	/**
	 * post: retorna el atributo estadoCivil.
	 */
	std::string getEstadoCivil() const;

	/**
	 * post: modifica el atributo cantidad de llamadas.
	 */
	void setCantidadLlamadas(std::string cantidadLlamadas);

	/**
	 * post: modifica el atributo edad.
	 */
	void setEdad(std::string edad);

	/**
	 * post: modifica el atributo sexo.
	 */
	void setSexo(std::string sexo);

	/**
	 * post: modifica el atributo estado civil.
	 */
	void setEstadoCivil(std::string estadoCivil);

	/**
	 * post: setea el valor de datosValidos.
	 */
	void setDatosValidos(bool datosValidos);

};

#endif /* VALIDADORDATOSCLIENTE_H_ */
