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

void Casillero::validarNumeroDePropietario(unsigned int numeroDePropietario) {
	if(numeroDePropietario < 0) {
		throw std::runtime_error("El nuevo propietario debe ser mayor o igual a 0");
	}
}

void Casillero::verificarColocacionDeFicha(Ficha* nuevaFicha, unsigned int numeroDePropietario) {
	if(this->estadoCasillero != VACIO || this->numeroDePropietario != 0) {
		throw std::runtime_error("El casillero debe estar vacío");
	}
	if(this->ficha != NULL) {
		throw std::runtime_error("La ficha debe estar en NULL");
	}
	if(nuevaFicha == NULL) {
		throw std::runtime_error("La nueva ficha no puede estar en NULL");
	}
	if(numeroDePropietario < 1) {
		throw std::runtime_error("El numero de propietario debe ser mayor a 0");
	}
}

void Casillero::verificarCambioDeFicha(TipoDeFicha tipoDeFicha, unsigned int numeroDePropietario) {
	if(tipoDeFicha != TESORO && tipoDeFicha != ESPIA && tipoDeFicha != MINA) {
		throw std::runtime_error("Tipo de ficha no existente");
	}
	if(this->ficha == NULL) {
		throw std::runtime_error("No se ha colocado ninguna ficha, la ficha apunta a NULL");
	}
	if(numeroDePropietario < 1) {
		throw std::runtime_error("El numero de propietario debe ser mayor a 0");
	}
}

void Casillero::validarNuevoEstado(EstadoCasillero nuevoEstado) {
	if(nuevoEstado != VACIO && nuevoEstado != INACTIVO && nuevoEstado != BLINDADO && nuevoEstado != LLENO) {
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
	this->estadoCasillero = VACIO;
	this->numeroDePropietario = 0;
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

unsigned int Casillero::getNumeroDePropietario() {
	return this->numeroDePropietario;
}

void Casillero::setNumeroDePropietario(unsigned int numeroDePropietario) {
	this->validarNumeroDePropietario(numeroDePropietario);
	this->numeroDePropietario = numeroDePropietario;
}

TipoDeFicha Casillero::getTipoFicha() {
	if(this->estaVacio()) {
		throw std::runtime_error("El casillero no tiene ningun tipo de ficha");
	}
	return this->ficha->getTipoFicha();
}

void Casillero::colocarFicha(Ficha *nuevaFicha, unsigned int numeroDePropietario) {
	this->verificarColocacionDeFicha(nuevaFicha, numeroDePropietario);
	this->ficha = nuevaFicha;
	this->setEstado(LLENO);
	this->setNumeroDePropietario(numeroDePropietario);
}

void Casillero::cambiarFicha(TipoDeFicha tipoDeFicha, unsigned int numeroDePropietario) {
	this->verificarCambioDeFicha(tipoDeFicha, numeroDePropietario);
	this->ficha->setTipoFicha(tipoDeFicha);
	this->setNumeroDePropietario(numeroDePropietario);
}

void Casillero::quitarFicha() {
	delete this->ficha;
	this->ficha = NULL;
	this->setEstado(VACIO);
	this->setNumeroDePropietario(0);
}

EstadoCasillero Casillero::getEstado() {
	return this->estadoCasillero;
}

void Casillero::setEstado(EstadoCasillero nuevoEstado) {
	this->validarNuevoEstado(nuevoEstado);
	this->estadoCasillero = nuevoEstado;
}

bool Casillero::estaVacio() {
	return (this->estadoCasillero == VACIO && this->ficha == NULL && this->getNumeroDePropietario() == 0);
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


