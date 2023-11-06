/*
 * TesoroBinario.cpp
 *
 *  Created on: 24 oct. 2023
 *      Author: gonzalo
 */
#include "TesoroBinario.h"

TesoroBinario::TesoroBinario(unsigned int numeroJugadores) {
	this->numeroJugadores = numeroJugadores;
	this->jugadores = new Lista<Jugador *>();
	for(unsigned int i = 1; i <= numeroJugadores; i++) {
		this->jugadores->agregarElemento(new Jugador(i));
	}
	this->tablero = new Tablero(numeroJugadores * 10, numeroJugadores * 10, numeroJugadores * 10);
	this->funcionalidadCartas = new FuncionalidadCartas(this->tablero);
	this->turnos = 0;
	this->cantidadDeTesoros = 0;

	this->profundidadTablero = 0;
	this->anchoTablero = 0;
	this->altoTablero = 0;
}

TesoroBinario::~TesoroBinario() {
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()) {
		delete this->jugadores->obtenerCursor();
	}
	delete this->jugadores;
	delete this->tablero;
	delete this->funcionalidadCartas;
}

Tablero *TesoroBinario::getTablero() {
	return this->tablero;
}

unsigned int TesoroBinario::getProfundidad() {
	return this->tablero->getProfundidad();
}

unsigned int TesoroBinario::getAncho() {
	return this->tablero->getAncho();
}

unsigned int TesoroBinario::getAlto() {
	return this->tablero->getAlto();
}

void TesoroBinario::configurarCantidadDeTesoros(unsigned int cantidadDeTesoros) {
	this->cantidadDeTesoros = cantidadDeTesoros;
}

Jugador *TesoroBinario::getJugador(unsigned int posicion) {
	return this->jugadores->obtenerElemento(posicion);
}

void TesoroBinario::colocarTesoros(unsigned int z, unsigned int x, unsigned int y, Jugador *jugador) {
	//validar que el tablero este vacio y que la casilla no tenga un tesoro enemigo
	this->tablero->getCasillero(z, x, y)->setEstado(LLENO);
	this->tablero->getCasillero(z, x, y)->colocarFicha(new Ficha(TESORO));
	this->tablero->getCasillero(z, x, y)->setPropietario(jugador->getNumeroJugador());
}

void TesoroBinario::colocarTesoros(Jugador *jugador) {
	unsigned int z, x, y;
	std::cout << "Jugador " << jugador->getNumeroJugador() << std::endl;
	std::cout << "Ingrese la coordenada de su " << jugador->getCantidadDeTesoros()+1 << " tesoro:" << std::endl;
	std::cout << "Z: ";
	std::cin >> z;
	std::cout << "X: ";
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;
	if(this->tablero->getCasillero(z, x, y)->estaVacio()) {
		this->tablero->getCasillero(z, x, y)->setEstado(LLENO);
		this->tablero->getCasillero(z, x, y)->colocarFicha(new Ficha(TESORO));
		this->tablero->getCasillero(z, x, y)->setPropietario(jugador->getNumeroJugador());
		jugador->setCantidadDeTesoros(jugador->getCantidadDeTesoros()+1);
		jugador->setNumeroDeTurno(jugador->getNumeroTurno()+1);
	}
	else {
		if(this->tablero->getCasillero(z, x, y)->getPropietario() == jugador->getNumeroJugador()) {
			std::cout << "Ya se encuentra un tesoro suyo en esta casilla." << std::endl;
			this->colocarTesoros(jugador);
		}
		else if(this->tablero->getCasillero(z, x, y)->getPropietario() != jugador->getNumeroJugador()) {
			std::cout << "Se encuentra un tesoro del jugador "
					  << this->tablero->getCasillero(z, x, y)->getPropietario() << std::endl;
			this->colocarTesoros(jugador);
		}
	}

}

void TesoroBinario::colocarEspias(unsigned int z, unsigned int x, unsigned int y, Jugador jugador) {
	if(tablero->getCasillero(z, x, y)->getTipoFicha() == TESORO) {
		//Metodo de recuperar tesoro.
	}
	//Validar si se encuentra un espia
	//Validar si hay una mina
	else {
		this->tablero->getCasillero(z, x, y)->cambiarFicha(ESPIA);
	}
}

void TesoroBinario::colocarTesoroMina(unsigned int z, unsigned int x, unsigned int y, Jugador jugador) {
	//Validar que la casilla este vacia
	this->tablero->getCasillero(z, x, y)->colocarFicha(new Ficha(MINA));
}

void TesoroBinario::mostrarMasoCarta(Jugador* jugador) {
	for(unsigned int i = 1; i <= jugador->getManoCarta()->contarElementos(); i++) {
		std::cout << "Carta: " << i << std::endl;
		if(jugador->getManoCarta()->obtenerElemento(i)->getTipoDeCarta() == BLINDAJE) {
			std::cout << "Carta blindaje" << std::endl;
		}
		else if(jugador->getManoCarta()->obtenerElemento(i)->getTipoDeCarta() == RADAR) {
			std::cout << "Carta radar" << std::endl;
		}
		else if(jugador->getManoCarta()->obtenerElemento(i)->getTipoDeCarta() == PARTIR_TESORO) {
			std::cout << "Carta partir tesoro" << std::endl;
		}
	}
}

void TesoroBinario::JugarCarta(Jugador *jugador) {
	this->mostrarMasoCarta(jugador);
	unsigned int numeroCarta;
	std::cout << "Ingrese la carta que desea jugar: ";
	std::cin >> numeroCarta;
	//validar numero carta
	switch(jugador->getManoCarta()->obtenerElemento(numeroCarta)->getTipoDeCarta()) {
		case BLINDAJE:
			this->funcionalidadCartas->blindarCarta(jugador);
			break;
		case RADAR:
			this->funcionalidadCartas->radar(jugador);
			break;
		case PARTIR_TESORO:
			this->funcionalidadCartas->partirTesoro(jugador);
			break;
	}
	jugador->eliminarCartaDeLaMano(numeroCarta);
	this->mostrarMasoCarta(jugador);
}




