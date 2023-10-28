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
	int volumenCuboVecinos;

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

public:
	/*
	 * pre:
	 * post:
	 */
	Tablero(unsigned int profundidad, unsigned int ancho, unsigned int alto);

	/*
	 * pre:
	 * post:
	 */
	virtual ~Tablero();

	/*
	 * pre:
	 * post:
	 */
	unsigned int getProfundidad();

	/*
	 * pre:
	 * post:
	 */
	unsigned int getAncho();

	/*
	 * pre:
	 * post:
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
	 * pre:
	 * post:
	 */
	int getRangoVecinos();

	/*
	 * pre:
	 * post:
	 */
	bool existeCasillero(unsigned int z, unsigned int x, unsigned int y);

	/*
	 * pre:
	 * post:
	 */
	void inicializarCuboVecinos(Casillero *casillero);

	/*
	 * pre:
	 * post:
	 */
	void configurarCuboVecinos();
};

#endif /* TABLERO_H_ */
