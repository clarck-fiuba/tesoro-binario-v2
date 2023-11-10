/*
 * Tablero.h
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#ifndef TABLERO_H_
#define TABLERO_H_
#include "Lista.h"
#include "Casillero.h"

class Tablero {
private:
	Lista<Lista<Lista<Casillero *> *> *> *tablero;
	unsigned int profundidad;
	unsigned int ancho;
	unsigned int alto;
	int rangoVecinos;
	int dimensionCuboVecinos;

	/*
	 * pre: -
	 * post: Valida el ancho, largo y la profundidad del tablero.
	 */
	void validarAnchoLargoYProfundidad(unsigned int profundidad, unsigned int ancho, unsigned int alto);

	/*
	 * pre: -
	 * post: Valida las coordenadas x, y, z.
	 */
	void validarCoordenadaCasillero(unsigned int x, unsigned int y, unsigned int z);

	/*
	 * pre: -
	 * post: Valida que el casillero sea distinto de NULL.
	 */
	void validarCasillero(Casillero* casillero);

	/*
	 * pre: -
	 * post: Valida si el tablero es distinto de NULL.
	 */
	void validarTablero();

public:
	/*
	 * pre: La profundidad, el ancho y alto deben ser mayor o igual a 1.
	 * post: Crea el tablero con las dimensiones pasadas por parámetro.
	 */
	Tablero(unsigned int profundidad, unsigned int ancho, unsigned int alto);

	/*
	 * pre: -
	 * post: Elimina de forma correcta el tablero.
	 */
	virtual ~Tablero();

	/*
	 * pre: -
	 * post: Devuelve la profundidad del tablero.
	 */
	unsigned int getProfundidad();

	/*
	 * pre: -
	 * post: Devuelve el ancho del tablero.
	 */
	unsigned int getAncho();

	/*
	 * pre: -
	 * post: Devuelve el alto del tablero.
	 */
	unsigned int getAlto();

	/*
	 * pre: Las 3 variables deben ser mayores o iguales a 1,
	 * 		x debe ser menor o igual al ancho,
	 * 		y debe ser menor o igual al alto y
	 * 		z debe ser menor o igual a la profundidad.
	 * post: Devuelve el casillero en la coordenada pasada por parametro.
	 */
	Casillero *getCasillero(unsigned int z, unsigned int x, unsigned int y);

	/*
	 * pre: -
	 * post: Retorna verdadero si las coordenadas z, x e y son correctas.
	 */
	bool existeCasillero(unsigned int z, unsigned int x, unsigned int y);

	/*
	 * pre: El casillero no debe de ser NULL, debe ya estar inicializado.
	 * post: Inicializa el cubo de los vecinos
	 * 		 actualizando el valor del rango de busqueda de los vecinos,
	 * 		 la dimension del cubo de los vecinos e
	 * 		 inicializando el cubo de vecino del casillero pasado por parámetro.
	 */
	void inicializarCuboVecinos(Casillero *casillero);

	/*
	 * pre: El tablero debe estar inicializado y tambien haber llamado al método inicializarCuboVecinos().
	 * post: Configura el cubo de vecinos de cada casillero con sus respectivos vecinos.
	 */
	void configurarCuboVecinos();
};

#endif /* TABLERO_H_ */
