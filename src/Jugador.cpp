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
	this->numeroTurno = 0;
	this->numeroRandom = 3;
	this->manoDeCartas = new Lista<Carta *>();
	for(unsigned int i = 1; i <= 3; i++) {
		/*std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(1, 3);
		this->numeroRandom = dist(mt);*/
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
