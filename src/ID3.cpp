/**
 * ID3.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "ID3.h"
#include <iostream>

ID3::ID3() {
}

ID3::~ID3() {
}

Arbol<DatoID3*>* ID3::id3(Lista<Cliente*>* conjunto, Atributo* clasificador,
						  Lista<Atributo*>* descriptores) {

	Arbol<DatoID3*>* arbolDeDecision = NULL;

	if ((!conjunto->estaVacia()) && (clasificador->esClasificador())) {

		NodoArbol<DatoID3*>* raiz
			= this->algoritmo(conjunto, clasificador, descriptores);

		arbolDeDecision = new Arbol<DatoID3*>(raiz);

	} else {

		arbolDeDecision = new Arbol<DatoID3*>;
	}

	return arbolDeDecision;
}


NodoArbol<DatoID3*>* ID3::algoritmo(Lista<Cliente*>* conjunto,
									Atributo* clasificador,
									Lista<Atributo*>* descriptores) {

	NodoArbol<DatoID3*>* nodoPadre = NULL;

	/* crea un analizador para el clasificador */
	Clasificador analizadorClasificador(clasificador);

	/* actualiza la distribucion de datos */
	this->actualizar(conjunto, analizadorClasificador);

	/* si todos los registros tiene el mismo valor,
	 * o si la lista de descriptores esta vacia */
	if ((descriptores->estaVacia())
			|| (analizadorClasificador.tienenMismoValor())) {

		/* obtiene el valor mas frecuente */
		Valor* valor = analizadorClasificador.getValorMasFrecuente();

		/* obtiene un nodo con el valor mas frecuente */
		nodoPadre = this->nodoConValor(valor);

	} else {

		/* obtiene la lista de analizadores de los descriptores */
		Lista<Descriptor*>* analizadoresDescriptores
				= this->getAnalizadores(clasificador, descriptores);

		/* actualiza la distribucion de datos de cada analizador */
		this->actualizar(conjunto, analizadoresDescriptores);

		/* obtiene el atributo con mayor ganancia */
		Atributo* atributoDivisor
					= this->atributoConMayorGanancia(analizadoresDescriptores);

		/* obtiene una lista sin el atributo descriptor divisor */
		Lista<Atributo*>* nuevosDescriptores
				= this->getDescriptoresSin(descriptores, atributoDivisor);


		/* crea el nodo condicion */
		nodoPadre = this->nodoConAtributo(atributoDivisor);

		/* para cada uno de los valores retorna un nodo */
		for(unsigned i = 1; i <= atributoDivisor->getNumeroDeValores(); i++) {

			/* obtiene el valor que identifica al nodo siguiente */
			Valor* valorI = atributoDivisor->getValorPosible(i);

			/* filtra del conjunto los registros con el valor */
			Lista<Cliente*>* subConjunto
					= this->getClientesConValor(conjunto, valorI);

			/* obtiene el nodo aplicando el algoritmo nuevamente */
			NodoArbol<DatoID3*>* hijo
			= this->algoritmo(subConjunto, clasificador, nuevosDescriptores);

			/* inicializa el antecedente del nodo */
			hijo->getDato()->setAntecente(valorI);

			/* agrega el nodo al nodo padre */
			nodoPadre->agregarHijo(hijo);

			/* destruye la lista del nuevo cojunto */
			delete subConjunto;
		}

		/* destruye la lista de analizadores */
		this->destruirLista(analizadoresDescriptores);

		/* detruye la lista de nuevos descriptores */
		delete nuevosDescriptores;
	}

	return nodoPadre;
}


void ID3::actualizar(Lista<Cliente*>* lista, Clasificador& analizador) {

	/* recorre la lista actualizando la distribucion */
	IteradorLista<Cliente*> iterador = lista->iterador();
	while(iterador.tieneSiguiente()) {

		/* obtiene el cliente de la lista */
		Cliente* unCliente = iterador.siguiente();

		/* obtiene el clasificador */
		Atributo* clasificador = analizador.getAtributoClasificador();

		/* obtiene el valor del clasificador */
		Valor* unValor = unCliente->getValorDelAtributo(clasificador);

		/* actualiza la distribucion */
		analizador.actualizarDistribucion(unValor);
	}
}


void
ID3::actualizar(Lista<Cliente*>* lista, Lista<Descriptor*>* analizadores) {

	/* recorre la lista actualizando la distribucion */
	IteradorLista<Cliente*> itClientes = lista->iterador();
	while(itClientes.tieneSiguiente()) {

		/* obtiene un cliente de la lista */
		Cliente* unCliente = itClientes.siguiente();

		IteradorLista<Descriptor*> itAnalizadores = analizadores->iterador();


		/* para cada analizador */
		while (itAnalizadores.tieneSiguiente()) {

			/* obtiene un analizador */
			Descriptor* analizador = itAnalizadores.siguiente();

			/* obtiene los atributos del analizador */
			Atributo* clasificador = analizador->getAtributoClasificador();
			Atributo* unDescriptor = analizador->getAtributoDescriptor();

			/* obtiene el valor del atributo clasificador */
			Valor* valorClasificador
					= unCliente->getValorDelAtributo(clasificador);

			/* obtiene el valor del atributo descriptor */
			Valor* valorDescriptor
					= unCliente->getValorDelAtributo(unDescriptor);

			/* actualiza la distribucion del analizador */
			analizador->actualizarDistribucionDeDatos(valorClasificador,
													  valorDescriptor);
		}
	}
}


Atributo* ID3::atributoConMayorGanancia(Lista<Descriptor*>* analizadores) {

	Descriptor* analizadorConMayorGanancia = NULL;

	/* busca el atributo con mayor ganancia */
	IteradorLista<Descriptor*> iterador = analizadores->iterador();
	while (iterador.tieneSiguiente()) {

		/* inicializa el analizador */
		if (analizadorConMayorGanancia == NULL) {

			analizadorConMayorGanancia = iterador.siguiente();

		} else {

			double mayorGanancia = analizadorConMayorGanancia->getGanancia();

			Descriptor* unAnalizador = iterador.siguiente();

			if (unAnalizador->getGanancia() > mayorGanancia) {

				analizadorConMayorGanancia = unAnalizador;
			}
		}
	}

	return analizadorConMayorGanancia->getAtributoDescriptor();
}


Lista<Descriptor*>* ID3::getAnalizadores(Atributo* clasificador,
										 Lista<Atributo*>* descriptores) {

	/* crea la lista de analizadores */
	Lista<Descriptor*>* analizadores = new Lista<Descriptor*>;

	/* recorre la lista de descriptores */
	IteradorLista<Atributo*> itDescriptores = descriptores->iterador();
	while(itDescriptores.tieneSiguiente()) {

		Atributo* unDescriptor = itDescriptores.siguiente();

		/* crea un nuevo analizador con cada descriptor */
		Descriptor* analizador = new Descriptor(clasificador, unDescriptor);

		analizadores->agregar(analizador);
	}

	return analizadores;
}


NodoArbol<DatoID3*>* ID3::nodoConValor(Valor* valor) {

	/* crea un DatoID3 resultado */
	DatoID3* datoId3 = new DatoID3(valor);

	/* retorna un nuevo nodo */
	return new NodoArbol<DatoID3*>(datoId3);
}

NodoArbol<DatoID3*>* ID3::nodoConAtributo(Atributo* atributo) {

	/* crea un DatoID3 resultado */
	DatoID3* datoId3 = new DatoID3(atributo);

	/* retorna un nuevo nodo */
	return new NodoArbol<DatoID3*>(datoId3);
}


Lista<Cliente*>*
ID3::getClientesConValor(Lista<Cliente*>* lista, Valor* valor) {

	/* crea la nueva lista */
	Lista<Cliente*>* nuevaLista = new Lista<Cliente*>;

	/* recorre la lista buscando los clientes con 'valor' */
	IteradorLista<Cliente*> iterador = lista->iterador();
	while(iterador.tieneSiguiente()) {

		Cliente* unCliente = iterador.siguiente();

		Atributo* atributo = valor->getAtributo();

		if (unCliente->getValorDelAtributo(atributo) == valor) {

			nuevaLista->agregar(unCliente);
		}
	}

	return nuevaLista;
}


Lista<Atributo*>* ID3::getDescriptoresSin(Lista<Atributo*>* descriptores,
										  Atributo* atributoDivisor) {

	/* crea la nueva lista */
	Lista<Atributo*>* nuevosDescriptores = new Lista<Atributo*>;

	/* recorre la lista agregando todos los atributos menos
	 * el atributo descriptor */
	IteradorLista<Atributo*> iterador = descriptores->iterador();
	while(iterador.tieneSiguiente()) {

		Atributo* unAtributo = iterador.siguiente();

		if (unAtributo != atributoDivisor) {

			nuevosDescriptores->agregar(unAtributo);
		}
	}

	return nuevosDescriptores;
}


void ID3::destruirLista(Lista<Descriptor*>* analizadoresGenerados) {

	IteradorLista<Descriptor*> iterador = analizadoresGenerados->iterador();

	while(iterador.tieneSiguiente()) {

		delete iterador.siguiente();
	}

	delete analizadoresGenerados;
}
