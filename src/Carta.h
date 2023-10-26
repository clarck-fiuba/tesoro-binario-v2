/*
 * Cartas.h
 *
 *  Created on: 20 oct. 2023
 *      Author: gonzalo
 */

#ifndef CARTA_H_
#define CARTA_H_
#include <iostream>
#include "Casillero.h"

enum TipoDeCarta {
	BLINDAJE,
	RADAR,
	PARTIR_TESORO
};

class Carta {
private:
	TipoDeCarta tipoDeCarta;
	//Casillero *casillero;

public:
	/*
	 * pre:
	 * post:
	 */
	Carta(TipoDeCarta tipoDeCarta);

	/*
	 * pre:
	 * post:
	 */
	virtual ~Carta();

	/*
	 * pre:
	 * post:
	 */
	TipoDeCarta getTipoDeCarta();

	/*
	 * pre:
	 * post:
	 */
	void setTipoDeCarta(TipoDeCarta nuevoTipo);

	/*
	 * pre:
	 * post:
	 */
	void CartaBlindaje(Casillero *casillero);
};

#endif /* CARTA_H_ */
