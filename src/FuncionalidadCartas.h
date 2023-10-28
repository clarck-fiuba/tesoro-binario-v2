/*
 * FuncionalidadCartas.h
 *
 *  Created on: 26/10/2023
 *      Author: algo2
 */

#ifndef FUNCIONALIDADCARTAS_H_
#define FUNCIONALIDADCARTAS_H_


#include "Tablero.h"

class FuncionalidadCartas {



private:

Tablero* tablero;

void IngresoCordenadas(unsigned int &z, unsigned int &x, unsigned int &y);

public:

	/*
	 *
	 */
	FuncionalidadCartas(Tablero* tablero);


	/*
	*
	*/
	virtual ~FuncionalidadCartas();

	/*
	*
	*/
	void blindarCarta();

	/*
	*
	*/
	void Radar();


	/*
	*
	*/
	Casillero* partirTesoro();

};

#endif /* FUNCIONALIDADCARTAS_H_ */
