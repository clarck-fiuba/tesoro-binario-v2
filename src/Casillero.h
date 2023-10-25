/*
 * Casillero.h
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_
#ifndef NULL
#define NULL 0
#endif
#include "Ficha.h"

enum EstadoCasilla {
	VACIA,
	INACTIVA,
	BLINDADA,
	LLENO
};

class Casillero {
private:
	EstadoCasilla estado;
	unsigned int propietario;
	Ficha *ficha;
	Casillero ****vecinos;
	int rangoDeVecinos;
	int dimensionCuboVecinos;
	unsigned int z;
	unsigned int x;
	unsigned int y;

	/*
	 * pre: -
	 * post: Valida las coordenadas x, y, z.
	 */
	void validarXYyZ(unsigned int x, unsigned int y, unsigned int z);

public:
	/*
	 * pre: Las coordenadas x, y, z deben ser mayores a 0.
	 * post: Crea un casillero con las coordenadas que se pasaron por parametro.
	 */
	Casillero(unsigned int z, unsigned int x, unsigned int y, int rangoVecinos);

	/*
	 * pre:
	 * post:
	 */
	virtual ~Casillero();

	/*
	 * pre:
	 * post:
	 */
	unsigned int getPropietario();

	/*
	 * pre:
	 * post:
	 */
	void setPropietario(unsigned int nuevoPropietario);

	/*
	 * pre: -
	 * post: Devuelve el valor de la ficha.
	 */
	Ficha *getFicha();

	/*
	 * pre:
	 * post:
	 */
	void colocarFicha(Ficha *nuevaFicha);

	/*
	 * pre:
	 * post:
	 */
	void cambiarFicha(TipoDeFicha nuevoTipo);

	/*
	 * pre:
	 * post:
	 */
	EstadoCasilla getEstado();

	/*
	 * pre:
	 * post:
	 */
	void setEstado(EstadoCasilla nuevoEstado);

	/*
	 * pre:
	 * post:
	 */
	Casillero *getVecino(unsigned int z, unsigned int x, unsigned int y);

	/*
	 * pre:
	 * post:
	 */
	void setVecino(Casillero *vecino, unsigned int z, unsigned int x, unsigned int y);
};

#endif /* CASILLERO_H_ */
