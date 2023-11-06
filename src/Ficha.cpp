/*
 * Ficha.cpp
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#include "Ficha.h"

void Ficha::validarTipoDeFicha(TipoDeFicha tipoDeFicha) {
	if(tipoDeFicha != TESORO && tipoDeFicha != ESPIA && tipoDeFicha != MINA) {
		throw std::runtime_error("Tipo de ficha no existente");
	}
}

Ficha::Ficha(TipoDeFicha tipoDeFicha) {
	this->validarTipoDeFicha(tipoDeFicha);
	this->tipoDeFicha = tipoDeFicha;
}

Ficha::~Ficha() {
	// TODO Auto-generated destructor stub
}

TipoDeFicha Ficha::getTipoFicha() {
	return this->tipoDeFicha;
}

void Ficha::setTipoFicha(TipoDeFicha nuevoTipoDeFicha) {
	this->validarTipoDeFicha(nuevoTipoDeFicha);
	this->tipoDeFicha = nuevoTipoDeFicha;
}

