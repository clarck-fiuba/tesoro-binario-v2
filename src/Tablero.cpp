/*
 * Tablero.cpp
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#include "Tablero.h"

void Tablero::validarAnchoLargoYProfundidad(unsigned int profundidad, unsigned int ancho, unsigned int alto) {
	if(profundidad < 1) {
		throw std::runtime_error("La profundidad ingresada es un numero no valido");
	}
	if(ancho < 1) {
		throw std::runtime_error("El ancho ingresado es un numero no valido");
	}
	if(alto < 1) {
		throw std::runtime_error("El alto ingresado es un numero no valido");
	}
}

void Tablero::validarCoordenadaCasillero(unsigned int z, unsigned int x, unsigned int y){
	if(z < 1 || z > this->profundidad) {
		throw std::runtime_error("La coordenada z esta mal ingresada");
	}
	if(x < 1 || x > this->ancho) {
		throw std::runtime_error("La coordenada x esta mal ingresada");
	}
	if(y < 1 || y > this->alto) {
		throw std::runtime_error("La coordenada y esta mal ingresada");
	}
}

void Tablero::validarCasillero(Casillero* casillero) {
	if(casillero == NULL) {
		throw std::runtime_error("El casillero debe estar inicializado");
	}
}

void Tablero::validarTablero() {
	if(this->tablero == NULL) {
		throw std::runtime_error("El tablero debe estar inicializado");
	}
}

Tablero::Tablero(unsigned int profundidad, unsigned int ancho, unsigned int alto) {
	this->validarAnchoLargoYProfundidad(profundidad, ancho, alto);
	this->profundidad = profundidad;
	this->ancho = ancho;
	this->alto = alto;
	this->rangoVecinos = (this->ancho)/10;
	this->dimensionCuboVecinos = (this->rangoVecinos*2)+1;
	this->tablero = new Lista<Lista<Lista<Casillero *> *> *>();
	for(unsigned int i = 1; i <= profundidad; i++) {
		Lista<Lista<Casillero *> *> *capa = new Lista<Lista<Casillero *> *>();
		for(unsigned int j = 1; j <= ancho; j++) {
			Lista<Casillero *> *fila = new Lista<Casillero *>();
			for(unsigned int k = 1; k <= alto; k++) {
				Casillero *casillero = new Casillero(i, j, k);
				this->inicializarCuboVecinos(casillero);
				fila->agregarElemento(casillero);
			}
			capa->agregarElemento(fila);
		}
		this->tablero->agregarElemento(capa);
	}
	this->configurarCuboVecinos();
}

Tablero::~Tablero() {
	this->tablero->iniciarCursor();
	while(this->tablero->avanzarCursor()) {
		Lista<Lista<Casillero *> *> *capa = this->tablero->obtenerCursor();
		capa->iniciarCursor();
		while(capa->avanzarCursor()) {
			Lista<Casillero *> *fila = capa->obtenerCursor();
			fila->iniciarCursor();
			while(fila->avanzarCursor()) {
				delete fila->obtenerCursor();
			}
			delete fila;
		}
		delete capa;
	}
	delete this->tablero;
}

unsigned int Tablero::getProfundidad() {
	return this->profundidad;
}

unsigned int Tablero::getAncho() {
	return this->ancho;
}

unsigned int Tablero::getAlto() {
	return this->alto;
}

Casillero *Tablero::getCasillero(unsigned int z, unsigned int x, unsigned int y) {
	this->validarCoordenadaCasillero(z, x, y);
	return this->tablero->obtenerElemento(z)->obtenerElemento(x)->obtenerElemento(y);
}

bool Tablero::existeCasillero(unsigned int z, unsigned int x, unsigned int y) {
	return ((z >= 1) &&
			(z <= this->profundidad) &&
			(x >= 1) &&
			(x <= this->ancho) &&
			(y >= 1) &&
			(y <= this->alto));
}

void Tablero::inicializarCuboVecinos(Casillero *casillero) {
	this->validarCasillero(casillero);
	casillero->setRangoVecinos(this->rangoVecinos);
	casillero->setDimensionCuboVecinos(this->dimensionCuboVecinos);
	casillero->inicializarCuboVecinos();
}

void Tablero::configurarCuboVecinos() {
	this->validarTablero();
	this->tablero->iniciarCursor();
	while(this->tablero->avanzarCursor()) {
		Lista<Lista<Casillero *> *> *capa = this->tablero->obtenerCursor();
		capa->iniciarCursor();
		while(capa->avanzarCursor()) {
			Lista<Casillero *> *fila = capa->obtenerCursor();
			fila->iniciarCursor();
			while(fila->avanzarCursor()) {
				Casillero *casillero = fila->obtenerCursor();

				for(int i = -this->rangoVecinos; i <= this->rangoVecinos; i++) {
					for(int j = -this->rangoVecinos; j <= this->rangoVecinos; j++) {
						for(int k = -this->rangoVecinos; k <= this->rangoVecinos; k++) {
							if(this->existeCasillero(casillero->getZ()+i, casillero->getX()+j, casillero->getY()+k)) {
								if(i == 0 && j == 0 && k == 0) {
									casillero->setVecino(casillero, 0, 0, 0);
								}
								else {
									if(casillero->getVecino(i, j, k) == NULL) {
										Casillero *vecino = this->getCasillero(casillero->getZ()+i, casillero->getX()+j, casillero->getY()+k);
										casillero->setVecino(vecino, i, j, k);
										vecino->setVecino(casillero, -1*i, -1*j, -1*k);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

