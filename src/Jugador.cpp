/*
 * Jugador.cpp
 *
 *  Created on: 20 oct. 2023
 *      Author: gonzalo
 */

#include "Jugador.h"

void Jugador::validarNumeroDeJugador(unsigned int numeroJugador) {
	if(numeroJugador < 1) {
		throw std::runtime_error("El numero del jugador debe ser mayor a 0");
	}
}

void Jugador::validarCantidadDeTesoros(unsigned int cantidadDeTesoros) {
	if(cantidadDeTesoros < 0) {
		throw std::runtime_error("La cantidad de tesoros no puede ser negativa");
	}
}

void Jugador::validarCantidadDeMinasPermitidas(unsigned int cantidadDeMinas) {
	if(cantidadDeMinas < 0) {
		throw std::runtime_error("La cantidad de minas permitidas no puede ser negativa");
	}
}

void Jugador::validarCantidadDeMinasEnTablero(unsigned int cantidadDeMinas) {
	if(cantidadDeMinas < 0 || cantidadDeMinas > this->cantidadDeMinasPermitidas) {
		throw std::runtime_error("La cantidad de minas en el tablero está fuera de rango");
	}
}

Jugador::Jugador(unsigned int numeroJugador) {
	this->validarNumeroDeJugador(numeroJugador);
	this->numeroDeJugador = numeroJugador;
	this->cantidadDeTesorosEnTablero = 0;
	this->cantidadDeMinasPermitidas = 0;
	this->cantidadDeMinasEnTablero = 0;
	this->manoDeCartas = new Lista<Carta* >();
	this->crearManoDeCartas();
	this->tableroBMP = new BMP();
	this->nombreTablero = "Tablero " + std::to_string(this->numeroDeJugador) + ".bmp";
}

Jugador::~Jugador() {
	this->manoDeCartas->iniciarCursor();
	while(this->manoDeCartas->avanzarCursor()) {
		delete this->manoDeCartas->obtenerCursor();
	}
	delete this->manoDeCartas;
	delete this->tableroBMP;
}

unsigned int Jugador::getNumeroJugador() {
	return this->numeroDeJugador;
}

unsigned int Jugador::getCantidadDeTesorosEnTablero() {
	return this->cantidadDeTesorosEnTablero;
}

unsigned int Jugador::getCantidadDeMinasPermitidas() {
	return this->cantidadDeMinasPermitidas;
}

unsigned int Jugador::getCantidadDeMinasEnTablero() {
	return this->cantidadDeMinasEnTablero;
}

bool Jugador::getEstadoPisadoMinaDeOtroJugador() {
	return this->pisadoMinaDeOtroJugador;
}

bool Jugador::getEstadoJugadoCarta() {
	return this->jugadoCarta;
}

Lista<Carta *> *Jugador::getManoDeCartas() {
	return this->manoDeCartas;
}

BMP* Jugador::getTableroBMP() {
	return this->tableroBMP;
}

std::string Jugador::getNombreTablero() {
	return this->nombreTablero;
}

void Jugador::setCantidadDeTesorosEnTablero(unsigned int cantidadDeTesoros) {
	this->validarCantidadDeTesoros(cantidadDeTesoros);
	this->cantidadDeTesorosEnTablero = cantidadDeTesoros;
}

void Jugador::setCantidadDeMinasPermitidas(unsigned int cantidadDeMinas) {
	this->validarCantidadDeMinasPermitidas(cantidadDeMinas);
	this->cantidadDeMinasPermitidas = cantidadDeMinas;
}

void Jugador::setCantidadDeMinasEnTablero(unsigned int cantidadDeMinas) {
	this->validarCantidadDeMinasEnTablero(cantidadDeMinas);
	this->cantidadDeMinasEnTablero = cantidadDeMinas;
}

void Jugador::aPisadoMina(bool pisarMina) {
	this->pisadoMinaDeOtroJugador = pisarMina;
}

void Jugador::aJugadoCarta(bool jugarCarta) {
	this->jugadoCarta = jugarCarta;
}

void Jugador::crearManoDeCartas() {
	int numeroRandom;
	for(unsigned int i = 1; i <= CANTIDAD_DE_CARTAS_EN_MANO; i++) {
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(1, CANTIDAD_DE_CARTAS);
		numeroRandom = dist(mt);
		switch(numeroRandom) {
		case 1:
			this->manoDeCartas->agregarElemento(new Carta(BLINDAR));
			break;
		case 2:
			this->manoDeCartas->agregarElemento(new Carta(RADAR));
			break;
		case 3:
			this->manoDeCartas->agregarElemento(new Carta(PARTIR_TESORO));
			break;
		case 4:
			this->manoDeCartas->agregarElemento(new Carta(AGREGAR_MINA));
			break;
		case 5:
			this->manoDeCartas->agregarElemento(new Carta(ROMPER_BLINDAJE));
			break;
		case 6:
			this->manoDeCartas->agregarElemento(new Carta(ELIMINAR_CARTA));
			break;
		}
	}
}

void Jugador::eliminarCartaDeLaMano(unsigned int posicion) {
	delete this->manoDeCartas->obtenerElemento(posicion);
	this->manoDeCartas->removerElemento(posicion);
}



