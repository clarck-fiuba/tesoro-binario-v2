/*
 * Casillero.cpp
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#include "Casillero.h"

void Casillero::validarXYyZ(unsigned int x, unsigned int y, unsigned z) {
	if(x < 1 || y < 1 || z < 1) {
		throw std::runtime_error("Coordenadas fuera de rango");
	}
}

void Casillero::validarPropietario(unsigned int nuevoPropietario) {
	if(nuevoPropietario < 1) {
		throw std::runtime_error("El nuevo propietario debe ser mayor o igual a 1");
	}
}

void Casillero::verificarColocacionDeFicha(Ficha* nuevaFicha) {
	if(this->ficha != NULL) {
		throw std::runtime_error("La ficha debe estar en NULL");
	}
	if(nuevaFicha == NULL) {
		throw std::runtime_error("La nueva ficha no puede estar en NULL");
	}
}

void Casillero::verificarFicha() {
	if(this->ficha == NULL) {
		throw std::runtime_error("No se ha colocado ninguna ficha, la ficha apunta a NULL");
	}
}

void Casillero::validarNuevoEstado(EstadoCasilla nuevoEstado) {
	if(nuevoEstado != VACIA && nuevoEstado != INACTIVA && nuevoEstado != BLINDADA && nuevoEstado != LLENO) {
		throw std::runtime_error("El nuevo estado no existe");
	}
}

void Casillero::validarRangoVecinos(unsigned int rangoVecinos) {
	if(rangoVecinos < 1) {
		throw std::runtime_error("El rango de busqueda de vecinos debe se mayor o igual a 1");
	}
}

void Casillero::validarDimensionCuboVecinos(unsigned int dimensionCuboVecinos) {
	if(dimensionCuboVecinos < 3) {
		throw std::runtime_error("El rango de busqueda de vecinos debe se mayor o igual a 3");
	}
}

void Casillero::validarCoordenadasVecinos(unsigned int z, unsigned int x, unsigned int y) {
	if((static_cast<int>(z) < -this->rangoDeVecinos || static_cast<int>(z) > this->rangoDeVecinos) ||
	   (static_cast<int>(x) < -this->rangoDeVecinos || static_cast<int>(x) > this->rangoDeVecinos) ||
	   (static_cast<int>(y) < -this->rangoDeVecinos || static_cast<int>(y) > this->rangoDeVecinos)) {
		throw std::runtime_error("Las coordenadas de los vecinos están mal ingresadas");
	}
}

Casillero::Casillero(unsigned int z, unsigned int x, unsigned int y) {
	this->validarXYyZ(x, y, z);
	this->estado = VACIA;
	this->propietario = 0;
	this->ficha = NULL;
	this->rangoDeVecinos = 0;
	this->dimensionCuboVecinos = 0;
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
}

void Casillero::eliminarCuboVecinos() {
	for(int i = 0; i < this->dimensionCuboVecinos; i++) {
		for(int j = 0; j < this->dimensionCuboVecinos; j++) {
			for(int k = 0; k < this->dimensionCuboVecinos; k++) {
				this->vecinos[i][j][k] = NULL;
			}
			delete[] this->vecinos[i][j];
		}
		delete[] this->vecinos[i];
	}
	delete[] this->vecinos;
}

unsigned int Casillero::getPropietario() {
	return this->propietario;
}

void Casillero::setPropietario(unsigned int nuevoPropietario) {
	this->validarPropietario(nuevoPropietario);
	this->propietario = nuevoPropietario;
}

TipoDeFicha Casillero::getTipoFicha() {
	this->verificarFicha();
	return this->ficha->getTipoFicha();
}

void Casillero::colocarFicha(Ficha *nuevaFicha) {
	this->verificarColocacionDeFicha(nuevaFicha);
	this->ficha = nuevaFicha;
}

void Casillero::quitarFicha() {
	this->ficha = NULL;
	this->setEstado(VACIA);
	this->setPropietario(0);
}

void Casillero::cambiarFicha(TipoDeFicha nuevoTipo) {
	this->verificarFicha();
	this->ficha->setTipoFicha(nuevoTipo);
}

EstadoCasilla Casillero::getEstado() {
	return this->estado;
}

void Casillero::setEstado(EstadoCasilla nuevoEstado) {
	this->validarNuevoEstado(nuevoEstado);
	this->estado = nuevoEstado;
}

bool Casillero::estaVacio() {
	return this->estado == VACIA;
}

int Casillero::getRangoVecinos() {
	return this->rangoDeVecinos;
}

void Casillero::setRangoVecinos(int rangoVecinos) {
	this->validarRangoVecinos(rangoVecinos);
	this->rangoDeVecinos = rangoVecinos;
}

void Casillero::setDimensionCuboVecinos(int dimensionCuboVecinos) {
	this->validarDimensionCuboVecinos(dimensionCuboVecinos);
	this->dimensionCuboVecinos = dimensionCuboVecinos;
}

bool Casillero::validarVecino(Casillero* vecino) {
	if(vecino != NULL) {
		if(vecino != this->getVecino(0, 0, 0)) {
			return true;
		}
	}
	return false;
}

Casillero *Casillero::getVecino(unsigned int z, unsigned int x, unsigned int y) {
	this->validarCoordenadasVecinos(z, x, y);
	return this->vecinos[z+this->rangoDeVecinos][x+this->rangoDeVecinos][y+this->rangoDeVecinos];
}

void Casillero::setVecino(Casillero *vecino, unsigned int z, unsigned int x, unsigned int y) {
	this->validarCoordenadasVecinos(z, x, y);
	this->vecinos[z+this->rangoDeVecinos][x+this->rangoDeVecinos][y+this->rangoDeVecinos] = vecino;
}


