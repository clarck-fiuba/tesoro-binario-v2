/*
 * Cartas.cpp
 *
 *  Created on: 20 oct. 2023
 *      Author: gonzalo
 */

#include "Carta.h"

void Carta::validarTipoDeCarta(TipoDeCarta tipoDeCarta) {
	if(tipoDeCarta != BLINDAJE && tipoDeCarta != RADAR && tipoDeCarta != PARTIR_TESORO &&
	   tipoDeCarta != AGREGAR_MINA && tipoDeCarta != ROMPER_BLINDAJE && tipoDeCarta != ELIMINAR_CARTA) {
		throw std::runtime_error("Tipo de carta no existente");
	}
}

Carta::Carta(TipoDeCarta tipoDeCarta) {
	this->validarTipoDeCarta(tipoDeCarta);
	this->tipoDeCarta = tipoDeCarta;
}

Carta::~Carta() {
	// TODO Auto-generated destructor stub
}

TipoDeCarta Carta::getTipoDeCarta() {
	return this->tipoDeCarta;
}










