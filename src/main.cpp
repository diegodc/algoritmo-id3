/**
 * main.cpp
 *
 * Autor:
 *			Diego De Cristofano
 **/

#include "CONSTANTES_ATRIBUTOS_CLIENTE.h"
#include "CONSTANTES_DE_VALIDACION.h"
#include "CONSTANTES_DE_TRANSFORMACION.h"
#include "Atributo.h"
#include "BuscadorDePatrones.h"
#include "CargadorDeClientes.h"

/* PATH DEL ARCHIVO DE CLIENTES*/
#ifndef PATH_ARCHIVO
#define PATH_ARCHIVO "datos/clientes.txt"
#endif


int main() {

/* crea un cargador de cliente y obtiene la lista */
	CargadorDeClientes cargador;

		Lista<Cliente*>* conjunto = cargador.cargarClientes(PATH_ARCHIVO);


/**
 * Todas las listas creadas son destruidas por el Atributo
 * en el momento que la instancia es creada.
 */

/* define los valores del atributo CATEGORIA y crea el atributo */
	Lista<std::string>* valoresCategoria = new Lista<std::string>;

		valoresCategoria->agregar(CLIENTE_CATEGORIA_NORMAL);
		valoresCategoria->agregar(CLIENTE_CATEGORIA_VIP);

	Atributo* categoria = new Atributo(NOMBRE_ATRIBUTO_CATEGORIA,
											valoresCategoria, true);


/* define los valores del atributo EDAD y crea el atributo */
	Lista<std::string>* valoresEdad = new Lista<std::string>;

		valoresEdad->agregar(CLIENTE_EDAD_ADULTO);
		valoresEdad->agregar(CLIENTE_EDAD_JOVEN);
		valoresEdad->agregar(CLIENTE_EDAD_MAYOR);

	Atributo* edad = new Atributo(NOMBRE_ATRIBUTO_EDAD, valoresEdad);


/* define los valores del atributo SEXO y crea el atributo */
	Lista<std::string>* valoresSexo = new Lista<std::string>;

		valoresSexo->agregar(SEXO_FEMENINO);
		valoresSexo->agregar(SEXO_MASCULINO);

	Atributo* sexo = new Atributo(NOMBRE_ATRIBUTO_SEXO, valoresSexo);


/* define los valores del atributo ESTADO CIVIL y crea el atributo */
	Lista<std::string>* valoresEstadoCivil = new Lista<std::string>;

		valoresEstadoCivil->agregar(ESTADO_CIVIL_CASADO);
		valoresEstadoCivil->agregar(ESTADO_CIVIL_DIVORCIADO);
		valoresEstadoCivil->agregar(ESTADO_CIVIL_SOLTERO);

	Atributo* estadoCivil =	new Atributo(NOMBRE_ATRIBUTO_ESTADOCIVIL,
													valoresEstadoCivil);


/* crea la lista de atributos descriptores y agrega los atributos */
	Lista<Atributo*>* listaDescriptores = new Lista<Atributo*>;

		listaDescriptores->agregar(sexo);
		listaDescriptores->agregar(estadoCivil);
		listaDescriptores->agregar(edad);

/**
 * Crea un BuscadorDePatrones con los parametros correspondientes,
 * la clase se "adue�a" de todos los objetos pasados, y se encarga
 * de su destruccion en el momento apropiado.
 */
	BuscadorDePatrones buscador(conjunto, categoria, listaDescriptores);

	/* inicia la busqueda de patrones */
	buscador.realizarBusqueda();

}
