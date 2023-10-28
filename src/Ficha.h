/*
 * Ficha.h
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#ifndef FICHA_H_
#define FICHA_H_

enum TipoDeFicha{
	TESORO,
	ESPIA,
	MINA,
};

class Ficha {
private:
	TipoDeFicha tipoDeFicha;

public:
	/*
	 * pre:
	 * post:
	 */
	Ficha(TipoDeFicha tipoDeFicha);

	virtual ~Ficha();

	/*
	 * pre:
	 * post:
	 */
	TipoDeFicha getTipoFicha();

	/*
	 * pre:
	 * post:
	 */
	void setTipoFicha(TipoDeFicha nuevaFicha);
};

#endif /* FICHA_H_ */
