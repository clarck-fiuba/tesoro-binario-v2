/*
 * TableroBMP.cpp
 *
 *  Created on: 20 nov. 2023
 *      Author: gonzalo
 */

#include "TableroBMP.h"

TableroBMP::TableroBMP(int cantidadDeCapas, int cantidadDeFilas, int cantidadDeColumnas) {
	this->cantidadDeCapas = cantidadDeCapas;
	this->cantidadDeFilas = cantidadDeFilas + 2;
	this->cantidadDeColumnas = cantidadDeColumnas + 2;
	this->anchoDeCasillero = 160;
	this->alturaDeCasillero = 160;
	this->separacionEntreCasilleros = 40;
	this->anchoDeCapa = (this->anchoDeCasillero * this->cantidadDeColumnas) +
						(this->separacionEntreCasilleros * (this->cantidadDeColumnas - 1));
	this->alturaDeCapa = (this->alturaDeCasillero * this->cantidadDeFilas) +
					   (this->separacionEntreCasilleros * (this->cantidadDeFilas - 1));
	this->anchoDelTablero = this->anchoDeCapa * cantidadDeCapas;
	this->alturaDelTablero = this->alturaDeCapa;
	this->capaDelTablero = new BMP();
	this->tesoro = new BMP();
	this->tesoro->ReadFromFile("Tesoro.bmp");
	this->espia = new BMP();
	this->espia->ReadFromFile("Espia.bmp");
	this->mina = new BMP();
	this->mina->ReadFromFile("Mina.bmp");
}

TableroBMP::~TableroBMP() {
	delete this->capaDelTablero;
	delete this->tesoro;
	delete this->espia;
	delete this->mina;
}

void TableroBMP::pintarBlanco(BMP* bmpAPintar, int x, int y) {
	(*bmpAPintar)(x, y)->Red = 255;
	(*bmpAPintar)(x, y)->Blue = 255;
	(*bmpAPintar)(x, y)->Green = 255;
}

void TableroBMP::pintarNegro(BMP* bmpAPintar, int x, int y) {
	(*bmpAPintar)(x, y)->Red = 0;
	(*bmpAPintar)(x, y)->Blue = 0;
	(*bmpAPintar)(x, y)->Green = 0;
}

void TableroBMP::pintarFondoDeLaCapa() {
	for(int i = 0; i < this->anchoDeCapa; i++) {
		for(int j = 0; j < this->alturaDeCapa; j++) {
			this->pintarBlanco(this->capaDelTablero, i, j);
		}
	}
}

void TableroBMP::pintarCasilleros() {
	int inicioX, finX, inicioY, finY;
	for(int x = 0; x < this->cantidadDeColumnas; x++) {
		for(int y = 0; y < this->cantidadDeFilas; y++) {
			inicioX = (x * (this->alturaDeCasillero + this->separacionEntreCasilleros));
			finX = (this->alturaDeCasillero * (x + 1)) + (this->separacionEntreCasilleros * x);
			inicioY = (y * (this->anchoDeCasillero + this->separacionEntreCasilleros));
			finY = (this->anchoDeCasillero * (y + 1)) + (this->separacionEntreCasilleros * y);
			for(int i = inicioX; i < finX; i++) {
				for(int j = inicioY; j < finY; j++) {
					this->pintarNegro(this->capaDelTablero, i, j);
				}
			}
		}
	}
}

void TableroBMP::pintarMarcoDeLaCapa() {
	for(int i = 0; i < this->anchoDeCapa; i++) {
		for(int j = 0; j < this->alturaDeCasillero; j++) {
			this->pintarBlanco(this->capaDelTablero, i, j);
		}
	}

	for(int i = 0; i < this->anchoDeCapa; i++) {
		for(int j = (this->cantidadDeFilas - 1) * (this->alturaDeCasillero + this->separacionEntreCasilleros);
				j < this->alturaDeCapa; j++) {
			this->pintarBlanco(this->capaDelTablero, i, j);
		}
	}

	for(int i = 0; i < this->anchoDeCasillero; i++) {
		for(int j = 0; j < this->alturaDeCapa; j++) {
			this->pintarBlanco(this->capaDelTablero, i, j);
		}
	}

	for(int i = (this->cantidadDeColumnas - 1) * (this->anchoDeCasillero + this->separacionEntreCasilleros);
			i < this->anchoDeCapa; i++) {
		for(int j = 0; j < this->alturaDeCapa; j++) {
			this->pintarBlanco(this->capaDelTablero, i, j);
		}
	}
}

void TableroBMP::crearCapa() {
	std::string nombreArchivo = "Capa_del_tablero.bmp";
 	this->capaDelTablero->SetSize(this->anchoDeCapa, this->alturaDeCapa);
	this->capaDelTablero->SetBitDepth(24);
	this->pintarFondoDeLaCapa();
	this->pintarCasilleros();
	this->pintarMarcoDeLaCapa();
	this->capaDelTablero->WriteToFile(nombreArchivo.c_str());
}

void TableroBMP::crearTablero(BMP& tablero, std::string nombreTablero) {
	this->crearCapa();
	tablero.SetSize(this->anchoDelTablero, this->alturaDelTablero);
	tablero.SetBitDepth(24);
	for(int x = 0; x < this->cantidadDeCapas; x++) {
		RangedPixelToPixelCopy(*this->capaDelTablero, 0, this->anchoDeCapa-1, this->alturaDeCapa-1, 0,
				tablero, x * this->anchoDeCapa, 0);
	}
	tablero.WriteToFile(nombreTablero.c_str());
}

void TableroBMP::calculoParaPintarFichas(unsigned int z, unsigned int x, unsigned int y,
		int& inicioY, int& inicioX) {
	inicioY = (static_cast<int>(y) * (this->anchoDeCasillero + this->separacionEntreCasilleros)) +
			((static_cast<int>(z) - 1) * this->anchoDeCapa);
	inicioX = static_cast<int>(x) * (this->alturaDeCasillero + this->separacionEntreCasilleros);
}

void TableroBMP::pintarFicha(unsigned int z, unsigned int x, unsigned int y,
		BMP& tablero, BMP& ficha, std::string nombreTablero) {
	int inicioX, inicioY;
	this->calculoParaPintarFichas(z, x, y, inicioY, inicioX);
	RangedPixelToPixelCopy(ficha, 0, this->anchoDeCasillero - 1, this->alturaDeCasillero - 1, 0,
			tablero, inicioY, inicioX);
	tablero.WriteToFile(nombreTablero.c_str());
}

void TableroBMP::pintarTesoro(unsigned int z, unsigned int x, unsigned int y,
		BMP& tablero, std::string nombreTablero) {
	this->pintarFicha(z, x, y, tablero, *(this->tesoro), nombreTablero);
}

void TableroBMP::pintarEspia(unsigned int z, unsigned int x, unsigned int y,
		BMP& tablero, std::string nombreTablero) {
	this->pintarFicha(z, x, y, tablero, *(this->espia), nombreTablero);
}

void TableroBMP::pintarMina(unsigned int z, unsigned int x, unsigned int y,
		BMP& tablero, std::string nombreTablero) {
	this->pintarFicha(z, x, y, tablero, *(this->mina), nombreTablero);
}

void TableroBMP::pintarCasilleroVacio(unsigned int z, unsigned int x, unsigned int y,
		BMP& tablero, std::string nombreTablero) {
	int inicioX, inicioY;
	this->calculoParaPintarFichas(z, x, y, inicioY, inicioX);
	RangedPixelToPixelCopy(*this->capaDelTablero, 160 + this->separacionEntreCasilleros,
			319 + this->separacionEntreCasilleros, 319 + this->separacionEntreCasilleros,
			160 + this->separacionEntreCasilleros, tablero, inicioY, inicioX);
	tablero.WriteToFile(nombreTablero.c_str());
}


