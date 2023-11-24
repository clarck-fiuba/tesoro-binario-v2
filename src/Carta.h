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
	BLINDAR,
	RADAR,
	PARTIR_TESORO,
	AGREGAR_MINA,
	ROMPER_BLINDAJE,
	ELIMINAR_CARTA
};

class Carta {
private:
	TipoDeCarta tipoDeCarta;

	/*
	 * pre: -
	 * post: Valida que el tipo de carta sea el correcto.
	 */
	void validarTipoDeCarta(TipoDeCarta tipoDeCarta);

public:
	/*
	 * pre: El tipo de carta debe ser: BLINDAJE, RADAR o PARTIR_TESORO.
	 * post: Carta con el tipo de carta pasada por parámetro.
	 */
	Carta(TipoDeCarta tipoDeCarta);

	virtual ~Carta();

	/*
	 * pre: -
	 * post: Devuelve el tipo de carta.
	 */
	TipoDeCarta getTipoDeCarta();
};

#endif /* CARTA_H_ */
