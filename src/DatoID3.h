/**
 * DatoID3.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef DATOID3_H_
#define DATOID3_H_

#include "Atributo.h"

/**
 * DatoID3 es el elemento que compone la lista de decision construida
 * por la clase ID3. Un DatoID3 puede ser un dato condicion, o resultado.
 * El dato esta compuesto por un atributo que nombra al DatoID3, y una
 * referencia a uno de los valores posibles de tal atributo.
 * En los DatosID3 resultado, esta referencia indica el resultado del atributo,
 * en cambio, en los datos condicion, esta referencia es nula.
 * Con excepcion del dato que compone la raiz del arbol, cada dato tiene un
 * valor antecedente, que indica la condicion del atributo padre de este nodo.
 */
class DatoID3 {

private:

	Valor* valorAntecedente;

	Atributo* atributo;

	Valor* valorResultado;

public:

	/**
	 * pre: 'atributo' - atributo que nombra al DatoID3
	 *
	 * post: crea un DatoID3 asociado al atributo, el DatoID3 queda
	 *       designado como dato condicion.
	 */
	DatoID3(Atributo* atributo);

	/**
	 * pre: 'valor' - valor resultado.
	 *
	 * post: crea un DatoID3 asociado al atributo del valor resultado,
	 *       y con este valor como resultado.
	 *       El DatoID3 que designado como dato resultado.
	 */
	DatoID3(Valor* valor);


	~DatoID3();

	/**
	 * post: retorna el atributo del dato.
	 */
	Atributo* getAtributo() const;

	/**
	 * post: retorna 'true' si el dato es un DatoID3 resultado.
	 */
	bool esResultado() const;

	/**
	 * pre: esResultado() == 'true'.
	 *
	 * post: retorna el valor resultado del atributo del DatoID3.
	 */
	Valor* getValorResultado() const;

	/**
	 * post: modifica el valor antecedente del dato.
	 */
	void setAntecente(Valor* valorAntecedente);

	/**
	 * pre: tieneAntecedente() == true.
	 *
	 * post: retorna el valor antecedente del dato.
	 */
	Valor* getAntecedente() const;

	/**
	 * post: retorna 'true' si tiene un valor antecedente.
	 */
	bool tieneAntecedente() const;

private:

	/**
	 * post: inicializa el atributo del dato.
	 */
	void setAtributo(Atributo* atributo);

	/**
	 * post: inicializa el valor del dato.
	 */
	void setValorResultado(Valor* valor);

};

#endif /* DATOID3_H_ */
