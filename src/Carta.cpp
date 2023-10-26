/*
 * Cartas.cpp
 *
 *  Created on: 20 oct. 2023
 *      Author: gonzalo
 */

#include "Carta.h"

Carta::Carta(TipoDeCarta tipoDeCarta) {
	this->tipoDeCarta = tipoDeCarta;
	//this->casillero = NULL;
}

Carta::~Carta() {

}

TipoDeCarta Carta::getTipoDeCarta() {
	return this->tipoDeCarta;
}

void Carta::setTipoDeCarta(TipoDeCarta nuevoTipo) {
	this->tipoDeCarta = nuevoTipo;
}

void Carta::CartaBlindaje(Casillero *casilleroABlindar) {
	//Casillero *auxiliar = casilleroABlindar;

	if(this->tipoDeCarta == BLINDAJE && casilleroABlindar->getFicha()->getTipoFicha() == TESORO) {
		casilleroABlindar->setEstado(BLINDADA);
	}
	else {
		throw "No se puede blindar";
	}

	//delete auxiliar;

	/*if(this->tipoDeCarta == BLINDAJE && casilleroABlindar->getFicha()->getTipoFicha() == TESORO) {
		this->casillero = casilleroABlindar;
		this->casillero->setEstado(BLINDADA);
	}
	else {
		throw "No se puede";
	}*/
}










