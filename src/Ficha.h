/*
 * Ficha.h
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#ifndef FICHA_H_
#define FICHA_H_
#include <iostream>

enum TipoDeFicha{
	TESORO,
	ESPIA,
	MINA,
};

class Ficha {
private:
	TipoDeFicha tipoDeFicha;

	/*
	 * pre: -
	 * post: Verifica que nuevoTipoDeFicha sea correcto.
	 */
	void validarTipoDeFicha(TipoDeFicha tipoDeFicha);

public:
	/*
	 * pre: El tipo de ficha debe ser: TESORO, ESPIA o MINA
	 * post: Ficha con el tipo de ficha pasado por parámetro.
	 */
	Ficha(TipoDeFicha tipoDeFicha);

	virtual ~Ficha();

	/*
	 * pre: -
	 * post: Devuelve el tipo de ficha, ya sea: TESORO, ESPIA o MINA.
	 */
	TipoDeFicha getTipoFicha();

	/*
	 * pre: El tipo de ficha debe ser: TESORO, ESPIA o MINA.
	 * post: Cambia el tipo de ficha por el pasado por parámetro.
	 */
	void setTipoFicha(TipoDeFicha nuevoTipoDeFicha);
};

#endif /* FICHA_H_ */
