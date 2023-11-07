/*
 * Jugador.cpp
 *
 *  Created on: 20 oct. 2023
 *      Author: gonzalo
 */

#include "Jugador.h"

void Jugador::validarNumeroJugador(unsigned int numeroJugador) {
	if(numeroJugador < 1) {
		throw std::runtime_error("El numero del jugador debe ser mayor a 0");
	}
}

void Jugador::validarCantidadDeTesoros(unsigned int cantidadDeTesoros) {
	if(cantidadDeTesoros < 0) {
		throw std::runtime_error("La cantidad de tesoros no puede ser negativa");
	}
}

void Jugador::validarNumeroTurno(unsigned int numeroTurno) {
	if(numeroTurno < 1) {
		throw std::runtime_error("El numero de turno debe ser mayor a 0");
	}
}

Jugador::Jugador(unsigned int numeroJugador) {
	this->validarNumeroJugador(numeroJugador);
	this->numeroJugador = numeroJugador;
	this->cantidadDeTesoros = 0;
	this->cantidadDeMinasPermitidas = 3;
	this->cantidadDeMinasPuestas = 0;
	this->numeroTurno = 0;
	this->minaEncontrada = true;
	for(int i = 0; i < 4; i++) {
		this->turnoRecuperarTesoro[i] = 0;
	}
	//this->numeroRandom = 0;
	this->manoDeCartas = new Lista<Carta *>();
	for(int i = 0; i < 4; i++) {
		this->casilleros[i] = NULL;
	}
	/*this->casilleros = new Lista<Casillero* >();
	for(unsigned int i = 1; i <= 3; i++) {
		this->casilleros->agregarElemento(NULL);
	}*/
	this->casillerosDesactivados = 0;
	this->casillerosActivados = 0;
	for(unsigned int i = 1; i <= 3; i++) {
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(1, 3);
		this->numeroRandom = dist(mt);
		switch(numeroRandom) {
			case 1:
				this->manoDeCartas->agregarElemento(new Carta(BLINDAJE));
				break;
			case 2:
				this->manoDeCartas->agregarElemento(new Carta(RADAR));
				break;
			case 3:
				this->manoDeCartas->agregarElemento(new Carta(PARTIR_TESORO));
				break;
		}
	}
}

Jugador::~Jugador() {
	this->manoDeCartas->iniciarCursor();
	while(this->manoDeCartas->avanzarCursor()) {
		delete this->manoDeCartas->obtenerCursor();
	}
	delete this->manoDeCartas;
}

unsigned int Jugador::getNumeroJugador() {
	return this->numeroJugador;
}

unsigned int Jugador::getCantidadDeTesoros() {
	return this->cantidadDeTesoros;
}

unsigned int Jugador::getNumeroTurno() {
	return this->numeroTurno;
}

Lista<Carta *> *Jugador::getManoCarta() {
	return this->manoDeCartas;
}

void Jugador::setCantidadDeTesoros(unsigned int cantidadDeTesoros) {
	this->validarCantidadDeTesoros(cantidadDeTesoros);
	this->cantidadDeTesoros = cantidadDeTesoros;
}

void Jugador::setNumeroDeTurno(unsigned int turno) {
	this->numeroTurno = turno;
}

void Jugador::eliminarCartaDeLaMano(unsigned int posicion) {
	delete this->manoDeCartas->obtenerElemento(posicion);
	this->manoDeCartas->removerElemento(posicion);
}

unsigned int Jugador::getCasillerosDesactivados() {
	return this->casillerosDesactivados;
}

void Jugador::setCasillerosDesactivados(unsigned int casillerosDesactivados) {
	/*if(casillerosDesactivados > 2) {
		this->casillerosDesactivados = 0;
	}*/
	this->casillerosDesactivados = casillerosDesactivados;
}

unsigned int Jugador::getCasillerosActivados() {
	return this->casillerosActivados;
}

void Jugador::setCasilleroActivados(unsigned int casillerosActivados) {
	/*if(casillerosActivados > 2) {
		this->casillerosActivados = 0;
	}*/
	this->casillerosActivados = casillerosActivados;
}

unsigned int Jugador::getTurnoRecuperarTesoro(int posicion) {
	return this->turnoRecuperarTesoro[posicion];
}

void Jugador::setTurnoRecuperarTesoro(int posicion, unsigned int turno) {
	this->turnoRecuperarTesoro[posicion] = turno;
}

Casillero* Jugador::getCasillero(int posicion) {
	return this->casilleros[posicion];
}

void Jugador::setCasillero(int posicion, Casillero* casillero) {
	this->casilleros[posicion] = casillero;
}

unsigned int Jugador::getCantidadDeMinasPermitidas() {
	return this->cantidadDeMinasPermitidas;
}

void Jugador::setCantidadDeMinasPermitidas(unsigned int cantidad) {
	this->cantidadDeMinasPermitidas = cantidad;
}

unsigned int Jugador::getCantidadDeMinasPuestas() {
	return this->cantidadDeMinasPuestas;
}

void Jugador::setCantidadDeMinasPuestas(unsigned int cantidad) {
	this->cantidadDeMinasPuestas = cantidad;
}

bool Jugador::getMinaEncontrada() {
	return this->minaEncontrada;
}

void Jugador::setMinaEncontrada() {
	this->minaEncontrada = !this->minaEncontrada;
}

/*
Lista<Casillero*> *Jugador::getCasilleros() {
	return this->casilleros;
}*/

/*void Jugador::setCasillero(Casillero* casillero) {
	this->casillero = casillero;
}*/
