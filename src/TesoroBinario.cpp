/*
 * TesoroBinario.cpp
 *
 *  Created on: 24 oct. 2023
 *      Author: gonzalo
 */
#include "TesoroBinario.h"

TesoroBinario::TesoroBinario(unsigned int numeroJugadores) {
	validarCantidadDeJugadores(numeroJugadores);
	this->numeroJugadores = numeroJugadores;
	this->jugadores = new Lista<Jugador *>();
	for(unsigned int i = 1; i <= numeroJugadores; i++) {
		this->jugadores->agregarElemento(new Jugador(i));
	}
	this->tablero = new Tablero(numeroJugadores/2, numeroJugadores * ANCHO, numeroJugadores * ALTO);
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

void TesoroBinario::configurarCantidadDeTesoros(unsigned int cantidadDeTesoros) {
	this->cantidadDeTesoros = cantidadDeTesoros;
}

Jugador* TesoroBinario::getJugador(unsigned int posicion) {
	validarPosicion(posicion);
	return this->jugadores->obtenerElemento(posicion);
}

Lista<Jugador* > *TesoroBinario::getJugadores() {
	return this->jugadores;
}

Casillero* TesoroBinario::ingresoDeCoordenadas() {
	unsigned int z, x, y;
	validarCoordenada(z, x, y);
	return this->tablero->getCasillero(z, x, y);
}

unsigned int TesoroBinario::getTurnos() {
	return this->turnos;
}

void TesoroBinario::setTurno(unsigned int turno) {
	this->turnos = turno;
}

/*
void TesoroBinario::colocarTesoros(unsigned int z, unsigned int x, unsigned int y, Jugador *jugador) {
	//validar casilla no tenga un tesoro enemigo
	if (this->tablero->getCasillero(z, x, y)->getEstado() == VACIA){
		this->tablero->getCasillero(z, x, y)->setEstado(LLENO);
		this->tablero->getCasillero(z, x, y)->colocarFicha(new Ficha(TESORO));
		this->tablero->getCasillero(z, x, y)->setPropietario(jugador->getNumeroJugador());
	}

}
 */
void TesoroBinario::colocarTesoros(Jugador* jugador) {
	std::cout << "Jugador " << jugador->getNumeroJugador() << std::endl;
	std::cout << "Ingrese la coordenada de su " << jugador->getCantidadDeTesoros()+1 << " tesoro:" << std::endl;
	Casillero* casillero = this->ingresoDeCoordenadas();
	if(casillero->estaVacio()) {
		casillero->setEstado(LLENO);
		casillero->colocarFicha(new Ficha(TESORO));
		casillero->setPropietario(jugador->getNumeroJugador());
		jugador->setCantidadDeTesoros(jugador->getCantidadDeTesoros()+1);
		Jugador* jugadorDelTesoro = this->getJugador(casillero->getPropietario());
		std::cout << "Jugador: " << jugadorDelTesoro->getNumeroJugador()
																  << " Cantidad de tesoros: "<< jugadorDelTesoro->getCantidadDeTesoros() << std::endl;
		//jugador->setNumeroDeTurno(jugador->getNumeroTurno()+1);
	}
	else {
		/*if(casillero->getTipoFicha() == TESORO && casillero->getPropietario() == jugador->getNumeroJugador()) {
			std::cout << "Ya se encuentra un tesoro suyo en esta casilla." << std::endl;
			this->colocarTesoros(jugador);
		}
		else if(casillero->getTipoFicha() == TESORO && casillero->getPropietario() != jugador->getNumeroJugador()) {
			std::cout << "Se encuentra un tesoro del jugador "
					<< casillero->getPropietario() << std::endl;
			this->colocarTesoros(jugador);
		}*/
		if(casillero->getTipoFicha() == TESORO) {
			if(casillero->getPropietario() == jugador->getNumeroJugador()) {
				std::cout << "Ya se encuentra un tesoro suyo en esta casilla." << std::endl;
				this->colocarTesoros(jugador);
			}
			else {
				std::cout << "Se encuentra un tesoro del jugador " << casillero->getPropietario() << std::endl;
				this->colocarTesoros(jugador);
			}
		}
	}
}

void TesoroBinario::activarCasillero(Jugador* jugador) {
	//jugador->setNumeroDeTurno(jugador->getNumeroTurno()+1);
	//std::cout << "Turno: " << jugador->getNumeroTurno() << std::endl;
	unsigned int indice = jugador->getCasillerosActivados();
	if(jugador->getCasillero(indice) != NULL) {
		std::cout << "Casillero iniciado" << std::endl;
		std::cout << "Indice: " << indice << std::endl;
		std::cout << this->turnos << " - " << jugador->getTurnoRecuperarTesoro(indice) << std::endl;
		if(jugador->getCasillero(indice)->getEstado() == INACTIVA &&
				this->turnos >= jugador->getTurnoRecuperarTesoro(indice)) {
			jugador->setCasilleroActivados(indice + 1);
			std::cout << "Activar Casilla" << std::endl;
		}
	}
	else {
		std::cout << "Casillero NULL" << std::endl;
	}
}

void TesoroBinario::colocarEspias(Jugador* jugador) {
	bool mina = false;
	//jugador->setNumeroDeTurno(jugador->getNumeroTurno()+1);
	//std::cout << "Turno: " << jugador->getNumeroTurno() << std::endl;
	jugador->setMinaEncontrada(mina);
	std::cout << "Jugador " << jugador->getNumeroJugador() << std::endl;
	std::cout << "Ingrese la coordenada de su espia: " << std::endl;
	Casillero* casillero = this->ingresoDeCoordenadas();
	if(casillero->estaVacio()) {
		casillero->setEstado(LLENO);
		casillero->colocarFicha(new Ficha(ESPIA));
		casillero->setPropietario(jugador->getNumeroJugador());
	}
	else {
		if(casillero->getTipoFicha() == TESORO) {
			if(casillero->getPropietario() != jugador->getNumeroJugador()) {
				if(casillero->getEstado() == BLINDADA) {
					std::cout << "Tesoro blindado" << std::endl;
					jugador->getManoCarta()->iniciarCursor();
					while (jugador->getManoCarta()->avanzarCursor()){
						Carta * carta = jugador->getManoCarta()->obtenerCursor();
						if (carta->getTipoDeCarta() == ROMPER_BLINDAJE){
							//pregunta al jugador si quiere usar o no la carta;
							funcionalidadCartas->romperBlindaje(jugador, this->getJugadores() , casillero);
						}
						else {
							std::cout << "Tesoro encontrado" << std::endl;
							casillero->setEstado(INACTIVA);
							//jugador->setCasillero(casillero);
							//jugador->getCasilleros()->asignarElemento(casillero, 1);
							unsigned int indice = jugador->getCasillerosDesactivados();
							jugador->setCasillero(indice, casillero);
							jugador->setTurnoRecuperarTesoro(indice, this->turnos + 5);
							std::cout << "Turno para activar casilla: " << jugador->getTurnoRecuperarTesoro(indice) << std::endl;
							jugador->setCasillerosDesactivados(indice + 1);
							eliminarTesoro(jugador, casillero, this->jugadores);
						}
					}
					else {
						std::cout << "Se encuentra un tesoro suyo en esa casilla." << std::endl;
						this->colocarEspias(jugador);
					}
				}
				else if(casillero->getTipoFicha() == MINA) {
					mina = true;
					casillero->quitarFicha();
					casillero->setEstado(VACIA);
					std::cout << "Espia eliminado" << std::endl;
					jugador->setMinaEncontrada(mina);
				}
			}
		}
	}
}
void TesoroBinario::colocarTesoroMina(Jugador *jugador) {
	if(jugador->getMinaEncontrada() == false) {
		jugador->setCantidadDeMinasPuestas(jugador->getCantidadDeMinasPuestas() + 1);
		std::cout << "Jugador " << jugador->getNumeroJugador() << std::endl;
		std::cout << "Ingrese la coordenada de su tesoro mina: " << std::endl;
		Casillero* casillero = this->ingresoDeCoordenadas();
		if(jugador->getCantidadDeMinasPuestas() <= jugador->getCantidadDeMinasPermitidas()) {
			if(casillero->estaVacio()) {
				casillero->setEstado(LLENO);
				casillero->colocarFicha(new Ficha(MINA));
				casillero->setPropietario(jugador->getNumeroJugador());
			}
			else {
				if(casillero->getTipoFicha() == TESORO) {
					if(casillero->getPropietario() != jugador->getNumeroJugador()) {
						if(casillero->getEstado() == BLINDADA) {
							casillero->setEstado(LLENO);
						}

					}
				}
				else {
					casillero->setEstado(INACTIVA);
					unsigned int indice = jugador->getCasillerosDesactivados();
					jugador->setCasillero(indice, casillero);
					jugador->setTurnoRecuperarTesoro(indice, this->turnos + 5);
					std::cout << "Turno para activar casilla: " << jugador->getTurnoRecuperarTesoro(indice) << std::endl;
					jugador->setCasillerosDesactivados(indice + 1);
					eliminarTesoro(jugador, casillero, this->jugadores);
				}
			}
		}
	}else{
		return ;
	}

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
	case AGREGAR_MINA:
		this->funcionalidadCartas->agregarTesoroMina(jugador);
		break;
	case ELIMINAR_CARTA:
		this->funcionalidadCartas->eliminarCartaEnemiga(jugador, this->jugadores);
		break;
	}
	jugador->eliminarCartaDeLaMano(numeroCarta);
	this->mostrarMasoCarta(jugador);
}

void TesoroBinario::eliminarJugador(unsigned int posicion) {
	if(this->jugadores->obtenerElemento(posicion)->getCantidadDeTesoros() == 0) {
		std::cout << "JUGADOR " << jugadores->obtenerElemento(posicion)->getNumeroJugador() << " ELIMINADO" << std::endl;
		delete this->jugadores->obtenerElemento(posicion);
		this->jugadores->removerElemento(posicion);
	}
}


void eliminarTesoro(Jugador * jugador, Casillero *casillero, Lista<Jugador *> *jugadores){

	unsigned int i = 1;
	unsigned int dueñoCasillero = casillero->getPropietario();
	while(jugadores->obtenerElemento(i)->getNumeroJugador() != dueñoCasillero) {
		i++;
	}
	Jugador* jugadorDelTesoro = jugadores->obtenerElemento(i);
	jugadorDelTesoro->setCantidadDeTesoros(jugadorDelTesoro->getCantidadDeTesoros() - 1);
	std::cout << "Jugador: " << jugadorDelTesoro->getNumeroJugador()
																					 << " Cantidad de tesoros: "<< jugadorDelTesoro->getCantidadDeTesoros() << std::endl;

}

