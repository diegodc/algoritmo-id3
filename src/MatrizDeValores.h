/**
 * MatrizDeValores.h
 *
 * Autor:
 *			Diego De Cristofano
 **/

#ifndef MATRIZDEVALORES_H_
#define MATRIZDEVALORES_H_

/**
 * MatrizDeValores es una matriz de enteros utlizada para contabilizar
 * la distribucion de datos de los atributos.
 */
class MatrizDeValores {

private:

	/* matriz utilizada para contabilizar la distribucion de datos */
	unsigned** matriz;

	/* dimensiones de la matriz */
	unsigned filas;

	unsigned columnas;

public:

	/**
	 * post: crea una matriz del tama�o dado, inicializada en cero.
	 */
	MatrizDeValores(unsigned filas, unsigned columnas);

	/**
	 * post: libera la memoria utlizada.
	 */
	~MatrizDeValores();

	/**
	 * post: retorna el numero de filas de la matriz de datos.
	 */
	unsigned getFilas() const;

	/**
	 * post: retorna el numero de columnas de la matriz de datos.
	 */
	unsigned getColumnas() const;

	/**
	 * pre: los indices de fila y columna estan dentro del rango de la matriz.
	 *
	 * post: retorna el valor correspondiente a la posicion
	 *       determinada por la fila y la columna dadas.
	 */
	double getValor(unsigned fila, unsigned columna) const;

	/**
	 * pre: los indices de fila y columnas estan dentro del rango de la matriz.
	 *
	 * post: incrementa en 1 el valor correspondiente a la posicion
	 *       determinada por la fila y la columna dadas.
	 */
	void incrementarValor(unsigned fila, unsigned columna);

	/**
	 * pre: el indice de la fila esta dentro del rango.
	 *
	 * post: retorna la suma de los valores de la fila correspondiente.
	 */
	double getSumatoriaDeFila(unsigned fila) const;

	/**
	 * pre: el indice de la columna esta dentro del rango.
	 *
	 * post: retorna la suma de los valores de la columna correspondiente.
	 */
	double getSumatoriaDeColumna(unsigned columna) const;

	/**
	 * post: retorna la sumatoria de todos los valores de la matriz.
	 */
	double getSumatoriaMatriz() const;

};

#endif /* MATRIZDEVALORES_H_ */
