/*
 * BMPTablero.cpp
 *
 *  Created on: 8 nov. 2023
 *      Author: gonzalo
 */

#include "BMPTablero.h"

BMPTablero::BMPTablero(int numeroCapas, int numeroFilas, int numeroColumnas) {
	this->numeroCapas = numeroCapas;
	this->numeroFilas = numeroFilas + 2;
	this->numeroColumnas = numeroColumnas + 2;
	this->anchoCasillero = 160;
	this->altoCasillero = 160;
	this->separacionCasillero = 40;
	this->anchoCapa = (this->anchoCasillero * this->numeroColumnas) + (this->separacionCasillero * (this->numeroColumnas-1));
	this->alturaCapa = (this->altoCasillero * this->numeroFilas) + (this->separacionCasillero * (this->numeroFilas-1));
	this->anchoTablero = this->anchoCapa * numeroCapas;
	this->alturaTablero = this->alturaCapa;
	this->capa = new BMP();
	this->tablero = new BMP();
	this->crearTablero(*this->tablero, *this->capa);
}

BMPTablero::~BMPTablero() {
	delete this->capa;
	delete this->tablero;
}

void BMPTablero::pintarBlanco(int x, int y) {
	(*this->capa)(x, y)->Red = 255;
	(*this->capa)(x, y)->Blue = 255;
	(*this->capa)(x, y)->Green = 255;
}

void BMPTablero::pintarNegro(int x, int y) {
	(*this->capa)(x, y)->Red = 0;
	(*this->capa)(x, y)->Blue = 0;
	(*this->capa)(x, y)->Green = 0;
}

void BMPTablero::pintarFondoCapa() {
	for(int i = 0; i < this->anchoCapa; i++) {
		for(int j = 0; j < this->alturaCapa; j++) {
			this->pintarBlanco(i, j);
		}
	}
}

void BMPTablero::pintarCasilleros() {
	for(int x = 0; x < this->numeroColumnas; x++) {
		for(int y = 0; y < this->numeroFilas; y++) {
			int inicioX = (x * (this->altoCasillero + this->separacionCasillero));
			int finX = (this->altoCasillero * (x+1)) + (this->separacionCasillero * x);
			int inicioY = y * (this->anchoCasillero + this->separacionCasillero);
			int finY = (this->anchoCasillero * (y+1)) + (this->separacionCasillero * y);
			for(int i = inicioX; i < finX; i++) {
				for(int j = inicioY; j < finY; j++) {
					this->pintarNegro(i, j);
				}
			}
		}
	}
}

void BMPTablero::pintarMarcoCapa() {
	for(int i = 0; i < this->anchoCapa; i++) {
		for(int j = 0; j < this->altoCasillero; j++) {
			this->pintarBlanco(i, j);
		}
	}

	for(int i = 0; i < this->anchoCapa; i++) {
		for(int j = (this->numeroFilas - 1) * (this->altoCasillero + this->separacionCasillero); j < this->alturaCapa; j++) {
			this->pintarBlanco(i, j);
		}
	}

	for(int i = 0; i < this->anchoCasillero; i++) {
		for(int j = 0; j < this->alturaCapa; j++) {
			this->pintarBlanco(i, j);
		}
	}

	for(int i = ((this->numeroColumnas - 1) * (this->anchoCasillero + this->separacionCasillero)); i < this->anchoCapa; i++) {
		for(int j = 0; j < this->alturaCapa; j++) {
			this->pintarBlanco(i, j);
		}
	}
}

void BMPTablero::crearCapa() {
	this->capa->SetSize(this->anchoCapa, this->alturaCapa);
	this->capa->SetBitDepth(24);
	this->pintarFondoCapa();
	this->pintarCasilleros();
	this->pintarMarcoCapa();
}

void BMPTablero::crearTablero(BMP& tablero, BMP& capa) {
	this->crearCapa();
	tablero.SetSize(this->anchoTablero, this->alturaTablero);
	tablero.SetBitDepth(24);
	for(int x = 0; x < this->numeroCapas; x++) {
		RangedPixelToPixelCopy(capa, 0 , this->anchoCapa-1, this->alturaCapa-1, 0, tablero, x * anchoCapa, 0);
	}
}

void BMPTablero::pintarTesoro(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, BMP& tesoro) {
	int inicioY = (static_cast<int>(y) * (this->anchoCasillero + this->separacionCasillero)) + ((static_cast<int>(z)-1)*this->anchoCapa);
	int inicioX = static_cast<int>(x) * (this->altoCasillero + this->separacionCasillero);
	RangedPixelToPixelCopy(tesoro, 0, 159, 159, 0, tablero, inicioY, inicioX );
}

void BMPTablero::pintarEspia(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, BMP& espia) {
	int inicioY = (static_cast<int>(y) * (this->anchoCasillero + this->separacionCasillero)) + ((static_cast<int>(z)-1)*this->anchoCapa);
	int inicioX = static_cast<int>(x) * (this->altoCasillero + this->separacionCasillero);
	RangedPixelToPixelCopy(espia, 0, 159, 159, 0, tablero, inicioY, inicioX );
}

void BMPTablero::pintarMina(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, BMP& mina) {
	int inicioY = (static_cast<int>(y) * (this->anchoCasillero + this->separacionCasillero)) + ((static_cast<int>(z)-1)*this->anchoCapa);
	int inicioX = static_cast<int>(x) * (this->altoCasillero + this->separacionCasillero);
	RangedPixelToPixelCopy(mina, 0, 159, 159, 0, tablero, inicioY, inicioX );
}

void BMPTablero::guardarTablero(std::string nombreTablero) {
	this->tablero->WriteToFile(nombreTablero.c_str());
}






