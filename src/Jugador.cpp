/*
 * Jugador.cpp
 *
 *  Created on: 20 oct. 2023
 *      Author: gonzalo
 */

#include "Jugador.h"

Jugador::Jugador(unsigned int numeroJugador) {
	this->numeroJugador = numeroJugador;
	this->cantidadDeTesoros = 0;
	this->numeroTurno = 0;
	this->numeroRandom = 2;
	this->manoDeCartas = new Lista<Carta *>();
	for(unsigned int i = 1; i <= 3; i++) {
		/*std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(1, 3);
		this->numeroRandom = dist(mt);*/
		Carta *nuevaCarta;
		switch(numeroRandom) {
			case 1:
				nuevaCarta = new Carta(BLINDAJE);
				break;
			case 2:
				nuevaCarta = new Carta(RADAR);
				break;
			case 3:
				nuevaCarta = new Carta(PARTIR_TESORO);
				break;
		}
		this->manoDeCartas->agregarElemento(nuevaCarta);
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

Lista<Carta *> *Jugador::getMasoCarta() {
	return this->manoDeCartas;
}

void Jugador::setCantidadDeTesoros(unsigned int cantidadDeTesoros) {
	this->cantidadDeTesoros = cantidadDeTesoros;
}

void Jugador::setNumeroDeTurno(unsigned int turno) {
	this->numeroTurno = turno;
}
