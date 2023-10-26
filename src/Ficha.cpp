/*
 * Ficha.cpp
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#include "Ficha.h"

Ficha::Ficha(TipoDeFicha tipoDeFicha) {
	this->tipoDeFicha = tipoDeFicha;
}

Ficha::~Ficha() {
	// TODO Auto-generated destructor stub
}

TipoDeFicha Ficha::getTipoFicha() {
	return this->tipoDeFicha;
}

void Ficha::setTipoFicha(TipoDeFicha nuevaFicha) {
	this->tipoDeFicha = nuevaFicha;
}

