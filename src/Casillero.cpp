/*
 * Casillero.cpp
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#include "Casillero.h"

Casillero::Casillero(unsigned int z, unsigned int x, unsigned int y) {
	this->validarXYyZ(x, y, z);
	this->estado = VACIA;
	this->propietario = 0;
	this->ficha = NULL;
	this->rangoDeVecinos = 0;
	this->volumenCuboVecinos = 0;
	this->vecinos = NULL;
	this->z = z;
	this->x = x;
	this->y = y;
}

Casillero::~Casillero() {
	delete this->ficha;
	this->eliminarCuboVecinos();
}

unsigned int Casillero::getZ() {
	return this->z;
}

unsigned int Casillero::getX() {
	return this->x;
}

unsigned int Casillero::getY() {
	return this->y;
}

void Casillero::inicializarCuboVecinos() {
	this->vecinos = new Casillero ***[this->volumenCuboVecinos];
	for(int i = 0; i < this->volumenCuboVecinos; i++) {
		this->vecinos[i] = new Casillero **[this->volumenCuboVecinos];
		for(int j = 0; j < this->volumenCuboVecinos; j++) {
			this->vecinos[i][j] = new Casillero *[this->volumenCuboVecinos];
			for(int k = 0; k < this->volumenCuboVecinos; k++) {
				this->vecinos[i][j][k] = NULL;
			}
		}
	}
}

void Casillero::eliminarCuboVecinos() {
	for(int i = 0; i < this->volumenCuboVecinos; i++) {
		for(int j = 0; j < this->volumenCuboVecinos; j++) {
			for(int k = 0; k < this->volumenCuboVecinos; k++) {
				this->vecinos[i][j][k] = NULL;
			}
			delete[] this->vecinos[i][j];
		}
		delete[] this->vecinos[i];
	}
	delete[] this->vecinos;
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

TipoDeFicha Casillero::getTipoficha(){
	return this->ficha->getTipoFicha();
}
/*
Ficha *Casillero::getFicha() {
	return this->ficha;
}*/

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

void Casillero::setRangoVecinos(int rangoVecinos) {
	this->rangoDeVecinos = rangoVecinos;
}

void Casillero::setVolumenCuboVecinos(int volumenCuboVecinos) {
	this->volumenCuboVecinos = volumenCuboVecinos;
}

Casillero *Casillero::getVecino(unsigned int z, unsigned int x, unsigned int y) {
	return this->vecinos[z+this->rangoDeVecinos][x+this->rangoDeVecinos][y+this->rangoDeVecinos];
}

void Casillero::setVecino(Casillero *vecino, unsigned int z, unsigned int x, unsigned int y) {
	this->vecinos[z+this->rangoDeVecinos][x+this->rangoDeVecinos][y+this->rangoDeVecinos] = vecino;
}

bool Casillero::estaVacio(){
	return (this->ficha == NULL);
}

