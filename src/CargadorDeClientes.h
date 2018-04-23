/**
 * CargadorDeClientes.h
 *
 * Autor:
 *			Diego De Cristofano
 **/
#ifndef CARGADORDECLIENTES_H_
#define CARGADORDECLIENTES_H_

#include "Cliente.h"
#include "Lista.h"
#include <string>

/**
 * CargadorDeClientes genera una lista de Clientes, creandolos
 * a partir del archivo CSV donde estan contenidos los datos.
 */
class CargadorDeClientes {

public:

	CargadorDeClientes();

	~CargadorDeClientes();

	/**
	 * pre: 'nombreArchivoClientes' - nombre del archivo, path incluido.
	 *      El archivo existe y contiene los datos de los clientes
	 *      en el formato esperado.
	 *
	 * post: lee el archivo creando e insertando cada Cliente en una lista.
	 *       Los datos de cada Cliente son validados previamente y solo se
	 *       crean aquellos con atributos validos.
	 *
	 * retorno: la lista de clientes.
	 */
	Lista<Cliente*>* cargarClientes(std::string nombreArchivoClientes);

private:

	/**
	 * pre: 'datosDelCliente' - string leido del archivo de clientes.
	 *      'clientes' - lista donde se insertara el cliente obtenido.
	 *
	 * post: procesa los datos (utilizando clases auxiliares) para obtener
	 *       una instancia de Cliente valida e insertarla en la lista.
	 */
	void obtenerCliente(const std::string& datosCliente,
						Lista<Cliente*>* clientes);

};

#endif /* CARGADORDECLIENTES_H_ */
