/**
 * CargadorDeClientes.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "CargadorDeClientes.h"
#include "ValidadorDatosCliente.h"
#include "archivoTexto.h"


CargadorDeClientes::CargadorDeClientes() {
}


CargadorDeClientes::~CargadorDeClientes() {
}


Lista<Cliente*>*
CargadorDeClientes::cargarClientes(std::string nombreArchivoClientes) {

	/* lista donde se iran insertando los clientes cargados */
	Lista<Cliente*>* clientes = new Lista<Cliente*>;

	/* string utilizado para almacenar cada linea leida del archivo */
	std::string stringLeido;

	/* archivo CSV donde se encuentran los datos */
	ArchivoTexto archivoCliente(nombreArchivoClientes);


	/* recorre el archivo leyendo cada linea */
	while (archivoCliente.leerLinea(stringLeido)) {

		if (!stringLeido.empty()) {

			/* procesa cada linea e inserta el cliente en la lista*/
			this->obtenerCliente(stringLeido, clientes);
		}
	}

	return clientes;
}


void CargadorDeClientes::obtenerCliente(const std::string& datosCliente,
											Lista<Cliente*>* clientes) {

	/* crea un nuevo validador con los datos del cliente */
	ValidadorDatosCliente validador(datosCliente);

	/*
	 * si el validador determina que los datos son validos,
	 * se le pide un nuevo cliente, y se inserta en la lista.
	 */
	if (validador.sonDatosValidos()) {

		clientes->iterador().insertar(validador.crearCliente());
	}
}
