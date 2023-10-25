/*
 * Casillero.cpp
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#include "Casillero.h"

Casillero::Casillero(unsigned int z, unsigned int x, unsigned int y, int rangoVecinos) {
	this->validarXYyZ(x, y, z);
	this->estado = VACIA;
	this->propietario = 0;
	this->ficha = NULL;
	this->rangoDeVecinos = rangoVecinos;
	this->dimensionCuboVecinos = (this->rangoDeVecinos * 2) + 1;
	this->vecinos = new Casillero ***[this->dimensionCuboVecinos];
	for(int i = 0; i < this->dimensionCuboVecinos; i++) {
		this->vecinos[i] = new Casillero **[this->dimensionCuboVecinos];
		for(int j = 0; j < this->dimensionCuboVecinos; j++) {
			this->vecinos[i][j] = new Casillero *[this->dimensionCuboVecinos];
			for(int k = 0; k < this->dimensionCuboVecinos; k++) {
				this->vecinos[i][j][k] = NULL;
			}
		}
	}
	this->z = z;
	this->x = x;
	this->y = y;
}

Casillero::~Casillero() {
	delete this->ficha;
}

void Casillero::validarXYyZ(unsigned int x, unsigned int y, unsigned z) {
	if(x < 1 || y < 1 || z < 1) {
		throw "Coordenadas fuera de rango";
	}
}

unsigned int Casillero::getPropietario() {
	return this->propietario;
}

void Casillero::setPropietario(unsigned int nuevoPropietario) {
	this->propietario = nuevoPropietario;
}

Ficha *Casillero::getFicha() {
	return this->ficha;
}

void Casillero::colocarFicha(Ficha *nuevaFicha) {
	//Hacer validacion de que ficha sea NULL
	this->ficha = nuevaFicha;
}

void Casillero::cambiarFicha(TipoDeFicha nuevoTipo) {
	//Hacer validacion de que la ficha ya este colocada
	this->ficha->setTipoFicha(nuevoTipo);
}

EstadoCasilla Casillero::getEstado() {
	return this->estado;
}

void Casillero::setEstado(EstadoCasilla nuevoEstado) {
	this->estado = nuevoEstado;
}

Casillero *Casillero::getVecino(unsigned int z, unsigned int x, unsigned int y) {
	return this->vecinos[z+this->rangoDeVecinos][x+this->rangoDeVecinos][y+this->rangoDeVecinos];
}

void Casillero::setVecino(Casillero *vecino, unsigned int z, unsigned int x, unsigned int y) {
	this->vecinos[z+this->rangoDeVecinos][x+this->rangoDeVecinos][y+this->rangoDeVecinos] = vecino;
}


