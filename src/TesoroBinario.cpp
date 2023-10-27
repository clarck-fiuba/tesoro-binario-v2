/*
 * TesoroBinario.cpp
 *
 *  Created on: 24 oct. 2023
 *      Author: gonzalo
 */

#include "TesoroBinario.h"
#include "FuncionalidadCartas.h"

TesoroBinario::TesoroBinario(unsigned int numeroJugadores) {
	this->numeroJugadores = numeroJugadores;
	this->jugadores = new Lista<Jugador *>();
	for(unsigned int i = 1; i <= numeroJugadores; i++) {
		this->jugadores->agregarElemento(new Jugador(i));
	}
	//this->tablero = this->crearTablero(this->numeroJugadores);
	this->tablero = new Tablero(numeroJugadores * 10, numeroJugadores * 10, numeroJugadores * 10);
	this->funcionalidad = new FuncionalidadCartas(this->tablero);
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

void TesoroBinario::setProfundidad(unsigned int profundidad) {
	this->profundidadTablero = profundidad;
}

void TesoroBinario::setAncho(unsigned int ancho) {
	this->anchoTablero = ancho;
}

void TesoroBinario::setAlto(unsigned int alto) {
	this->altoTablero = alto;
}

Tablero *TesoroBinario::crearTablero(unsigned int numeroJugadores) {
	/*this->setProfundidad(numeroJugadores * 10);
	this->setAncho(numeroJugadores * 10);
	this->setAlto(numeroJugadores * 10);*/
	this->tablero = new Tablero(numeroJugadores * 10, numeroJugadores * 10, numeroJugadores * 10);
	return tablero;
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
	this->tablero->getCasillero(z, x, y)->setEstado(LLENO);
	this->tablero->getCasillero(z, x, y)->colocarFicha(new Ficha(TESORO));
	this->tablero->getCasillero(z, x, y)->setPropietario(jugador->getNumeroJugador());
	jugador->setCantidadDeTesoros(jugador->getCantidadDeTesoros()+1);
	jugador->setNumeroDeTurno(jugador->getNumeroTurno()+1);
}

void TesoroBinario::colocarEspias(unsigned int z, unsigned int x, unsigned int y, Jugador jugador) {
	if(tablero->getCasillero(z, x, y)->getFicha()->getTipoFicha() == TESORO) {
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

void TesoroBinario::JugarCarta(Jugador *jugador) {
	for(unsigned int i = 1; i <= 3; i++) {
		std::cout << "Carta: " << i << std::endl;
		if(jugador->getMasoCarta()->obtenerElemento(i)->getTipoDeCarta() == BLINDAJE) {
			std::cout << "Carta blindaje" << std::endl;
		}
		else if(jugador->getMasoCarta()->obtenerElemento(i)->getTipoDeCarta() == RADAR) {
			std::cout << "Carta radar" << std::endl;
		}
		else if(jugador->getMasoCarta()->obtenerElemento(i)->getTipoDeCarta() == PARTIR_TESORO) {
			std::cout << "Carta partir tesoro" << std::endl;
		}
	}
	unsigned int numeroCarta;
	unsigned int z, x, y;
	unsigned int contadorTesoros = 0;
	std::cout << "Ingrese la carta que desea jugar: ";
	std::cin >> numeroCarta;
	switch(jugador->getMasoCarta()->obtenerElemento(numeroCarta)->getTipoDeCarta()) {
		case BLINDAJE:

			this->funcionalidad->blindarCarta();
			//jugador->getMasoCarta()->obtenerElemento(numeroCarta)->CartaBlindaje(this->tablero->getCasillero(z, x, y));
			/*this->tablero->getCasillero(z, x, y)->setEstado(BLINDADA);
			if(this->tablero->getCasillero(z, x, y)->getEstado() == BLINDADA) {
				std::cout << "Casillero blindado" << std::endl;
			}*/
			break;
		case RADAR:
			std::cout << "Ingrese la coordenada donde quiere poner su radar: " << std::endl;
			std::cout << "Z: ";
			std::cin >> z;
			std::cout << "X: ";
			std::cin >> x;
			std::cout << "Y: ";
			std::cin >> y;
			/*for(int i = -this->tablero->getRangoVecinos(); i <= this->tablero->getRangoVecinos(); i++) {
				for(int j = -this->tablero->getRangoVecinos(); j <= this->tablero->getRangoVecinos(); j++) {
					for(int k = -this->tablero->getRangoVecinos(); k <= this->tablero->getRangoVecinos(); k++) {
						std::cout << "Primera" << std::endl;
						if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k) != NULL) {
							std::cout << "Segundo" << std::endl;
							if(this->tablero->getCasillero(z, x, y)->getPropietario() !=
							   this->tablero->getCasillero(z, x, y)->getVecino(i, j, k)->getPropietario()) {
								std::cout << "Tercero" << std::endl;
								if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k)->getFicha()->getTipoFicha() == TESORO) {
									std::cout << "Cuarta" << std::endl;
									contadorTesoros++;
								}
							}
						}
					}
				}
			}*/
			for(int i = -this->tablero->getRangoVecinos(); i <= this->tablero->getRangoVecinos(); i++) {
				for(int j = -this->tablero->getRangoVecinos(); j <= this->tablero->getRangoVecinos(); j++) {
					for(int k = -this->tablero->getRangoVecinos(); k <= this->tablero->getRangoVecinos(); k++) {
						if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k) != tablero->getCasillero(z, x, y)->getVecino(0, 0, 0)) {
							if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k) != NULL) {
								if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k)->getFicha() != NULL) {
									if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k)->getFicha()->getTipoFicha() == TESORO) {
										std::cout << tablero->getCasillero(z, x, y)->getVecino(i, j, k)->getFicha() << std::endl;
										contadorTesoros++;
									}
								}
							}
						}
					}
				}
			}
			if(contadorTesoros != 0) {
				std::cout << "Se ha detectado " << contadorTesoros << " tesoros" << std::endl;
			}
			//std::cout << "Activar radar" << std::endl;
			break;
		case PARTIR_TESORO:
			std::cout << "Partir tesoro" << std::endl;
			break;
	}

}




