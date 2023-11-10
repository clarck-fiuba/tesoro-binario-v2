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
	this->jugadorVivo = true;
	this->tableroJugador = NULL;
	this->tablero = new BMP();
	this->tesoro = new BMP();
	this->espia = new BMP();
	this->mina = new BMP();
	this->tesoro->ReadFromFile("Tesoro.bmp");
	this->espia->ReadFromFile("Espia.bmp");
	this->mina->ReadFromFile("Mina.bmp");
	this->numeroJugador = numeroJugador;
	this->nombreTablero = "Tablero " + std::to_string(this->numeroJugador) + ".bmp";
	this->cantidadDeTesoros = 0;
	this->cantidadDeMinasPermitidas = 3;
	this->cantidadDeMinasPuestas = 0;
	this->numeroTurno = 0;
	this->minaEncontrada = true;
	this->casillerosDesactivados = 0;
	this->casillerosActivados = 1;
	this->casillerosDeTesoroEncontrado = new Lista<Casillero* >();
	this->turnoRecuperarTesoro = new Lista<unsigned int>();
	this->manoDeCartas = new Lista<Carta* >();
	for(unsigned int i = 1; i <= 3; i++) {
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(1, 6);
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

Jugador::~Jugador() {
	this->manoDeCartas->iniciarCursor();
	while(this->manoDeCartas->avanzarCursor()) {
		delete this->manoDeCartas->obtenerCursor();
	}
	delete this->manoDeCartas;
	delete this->tablero;
	delete this->tesoro;
	delete this->espia;
	delete this->mina;
	this->casillerosDeTesoroEncontrado->iniciarCursor();
	while(this->casillerosDeTesoroEncontrado->avanzarCursor()) {
		if(this->casillerosDeTesoroEncontrado->obtenerCursor() != NULL) {
			delete this->casillerosDeTesoroEncontrado->obtenerCursor();
		}
	}
	delete this->casillerosDeTesoroEncontrado;
	delete this->turnoRecuperarTesoro;
	delete this->tableroJugador;
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
	this->casillerosDesactivados = casillerosDesactivados;
}

unsigned int Jugador::getCasillerosActivados() {
	return this->casillerosActivados;
}

void Jugador::setCasilleroActivados(unsigned int casillerosActivados) {
	this->casillerosActivados = casillerosActivados;
}

unsigned int Jugador::getTurnoRecuperarTesoro(int posicion) {
	return this->turnoRecuperarTesoro->obtenerElemento(posicion);
}

void Jugador::setTurnoRecuperarTesoro(unsigned int turno) {
	this->turnoRecuperarTesoro->agregarElemento(turno);
}

Lista<Casillero* > *Jugador::getListaCasillerosDesactivados() {
	return this->casillerosDeTesoroEncontrado;
}

Casillero* Jugador::getCasillerosConTesorosEncontrados(int posicion) {
	return this->casillerosDeTesoroEncontrado->obtenerElemento(posicion);
}

void Jugador::setCasillerosConTesorosEncontrados(Casillero* casillero) {
	this->casillerosDeTesoroEncontrado->agregarElemento(casillero);
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

void Jugador::setMinaEncontrada(bool minaEncontrada) {
	this->minaEncontrada = minaEncontrada;
}

void Jugador::crearTableroJugador(int profundidad, int filas, int columnas) {
	this->tableroJugador = new BMPTablero(profundidad, filas, columnas);
	this->tableroJugador->guardarTablero(this->nombreTablero);
	this->tablero->ReadFromFile(this->nombreTablero.c_str());
}

void Jugador::pintarTesoro(int z, int x, int y) {
	this->tableroJugador->pintarTesoro(z, x, y, *this->tablero, *this->tesoro);
	this->tablero->WriteToFile(this->nombreTablero.c_str());
}

void Jugador::pintarEspia(int z, int x, int y) {
	this->tableroJugador->pintarTesoro(z, x, y, *this->tablero, *this->espia);
	this->tablero->WriteToFile(this->nombreTablero.c_str());
}

void Jugador::pintarMina(int z, int x, int y) {
	this->tableroJugador->pintarMina(z, x, y, *this->tablero, *this->mina);
	this->tablero->WriteToFile(this->nombreTablero.c_str());
}

bool Jugador::getEstadoJugador() {
	return this->jugadorVivo;
}

void Jugador::jugadorEliminado() {
	this->jugadorVivo = false;
}


