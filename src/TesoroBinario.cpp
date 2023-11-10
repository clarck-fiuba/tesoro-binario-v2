/*
 * TesoroBinario.cpp
 *
 *  Created on: 24 oct. 2023
 *      Author: gonzalo
 */
#include "TesoroBinario.h"

TesoroBinario::TesoroBinario(unsigned int numeroJugadores) {
	this->numeroJugadores = numeroJugadores;
	this->numeroJugadoresVivos = numeroJugadores;
	this->profundidadTablero = numeroJugadores/2;
	this->anchoTablero = numeroJugadores*10;
	this->altoTablero = numeroJugadores*10;
	this->jugadores = new Lista<Jugador *>();
	for(unsigned int i = 1; i <= numeroJugadores; i++) {
		this->jugadores->agregarElemento(new Jugador(i));
	}
	jugadores->iniciarCursor();
	while(jugadores->avanzarCursor()) {
		jugadores->obtenerCursor()->crearTableroJugador(static_cast<int>(this->profundidadTablero),
				static_cast<int>(this->anchoTablero), static_cast<int>(this->altoTablero));
	}
	this->tablero = new Tablero(this->profundidadTablero, this->anchoTablero,this->altoTablero);
	this->funcionalidadCartas = new FuncionalidadCartas(this->tablero);
	this->turnos = 0;
	this->cantidadDeTesoros = 0;
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
	return this->jugadores->obtenerElemento(posicion);
}

Lista<Jugador* > *TesoroBinario::getJugadores() {
	return this->jugadores;
}

Casillero* TesoroBinario::ingresoDeCoordenadas() {
	unsigned int z, x, y;
	std::cout << "Z: ";
	std::cin >> z;
	std::cout << "X: ";
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;
	return this->tablero->getCasillero(z, x, y);
}

unsigned int TesoroBinario::getTurnos() {
	return this->turnos;
}

void TesoroBinario::setTurno(unsigned int turno) {
	this->turnos = turno;
}

void TesoroBinario::colocarTesoros(Jugador* jugador) {
	std::cout << "Jugador " << jugador->getNumeroJugador() << std::endl;
	std::cout << "Ingrese la coordenada de su " << jugador->getCantidadDeTesoros()+1 << " tesoro:" << std::endl;
	Casillero* casillero = this->ingresoDeCoordenadas();
	if(casillero->estaVacio()) {
		casillero->setEstado(LLENO);
		casillero->colocarFicha(new Ficha(TESORO));
		casillero->setPropietario(jugador->getNumeroJugador());
		jugador->setCantidadDeTesoros(jugador->getCantidadDeTesoros()+1);
		jugador->pintarTesoro(casillero->getZ(), casillero->getX(), casillero->getY());
		Jugador* jugadorDelTesoro = this->getJugador(casillero->getPropietario());
		std::cout << "Jugador: " << jugadorDelTesoro->getNumeroJugador()
				  << " Cantidad de tesoros: "<< jugadorDelTesoro->getCantidadDeTesoros() << std::endl;
	}
	else {
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
	if(jugador->getEstadoJugador() == false) {
		return;
	}
	else {
		if(jugador != NULL) {
			std::cout << "jfakfjjdf" << std::endl;
			if(!jugador->getListaCasillerosDesactivados()->estaVacia()) {
				unsigned int indice = 0;
				indice = jugador->getCasillerosActivados();
				std::cout << "Casillero iniciado" << std::endl;
				std::cout << "Indice: " << indice << std::endl;
				std::cout << this->turnos << " - " << jugador->getTurnoRecuperarTesoro(indice) << std::endl;
				if(this->turnos >= jugador->getTurnoRecuperarTesoro(indice)) {
					std::cout << "CASILLERO ACTIVADO" << std::endl;
					jugador->getCasillerosConTesorosEncontrados(indice)->setEstado(LLENO);
					jugador->setCasilleroActivados(jugador->getCasillerosActivados() + 1);
				}
			}
			else {
				std::cout << "No hay casilleros para activar" << std::endl;
			}
		}
	}
}

void TesoroBinario::colocarEspias(Jugador* jugador) {
	if(jugador->getEstadoJugador() == false) {
		return;
	}
	else {
		bool minaEncontrada = false;
		jugador->setMinaEncontrada(minaEncontrada);
		std::cout << "Jugador " << jugador->getNumeroJugador() << std::endl;
		std::cout << "Ingrese la coordenada de su espia: " << std::endl;
		Casillero* casillero = this->ingresoDeCoordenadas();
		if(casillero->estaVacio()) {
			casillero->setEstado(LLENO);
			casillero->colocarFicha(new Ficha(ESPIA));
			casillero->setPropietario(jugador->getNumeroJugador());
			jugador->pintarEspia(casillero->getZ(), casillero->getX(), casillero->getY());
		}
		else {
			if(casillero->getTipoFicha() == TESORO) {
				if(casillero->getPropietario() != jugador->getNumeroJugador()) {
					if(casillero->getEstado() == BLINDADA) {
						std::cout << "Se encuentra un tesoro blindado" << std::endl;
						bool buscarCartaRomperBlindaje = false;
						jugador->getManoCarta()->iniciarCursor();
						while(jugador->getManoCarta()->avanzarCursor() && !buscarCartaRomperBlindaje) {
							Carta* cartaActual = jugador->getManoCarta()->obtenerCursor();
							if(cartaActual->getTipoDeCarta() == ROMPER_BLINDAJE) {
								buscarCartaRomperBlindaje = true;
							}
						}
						if(buscarCartaRomperBlindaje) {
							char afirmacion;
							std::cout << "Tiene una carta que rompe el blindaje. ";
							std::cout << "Ingrese 'S' si desea usarla o cualquier otro caracter si no: ";
							std::cin >> afirmacion;
							if(afirmacion == 'S') {
								this->funcionalidadCartas->romperBlindaje(jugador, this->jugadores, casillero);
							}
							else {
								return;
							}
						}
						else {
							std::cout << "No cuenta con la carta romper blindaje" << std::endl;
						}
					}
					else {
						std::cout << "Tesoro encontrado" << std::endl;
						casillero->cambiarFicha(ESPIA);
						casillero->setEstado(INACTIVA);
						jugador->pintarEspia(casillero->getZ(), casillero->getX(), casillero->getY());
						unsigned int indice = 0;
						jugador->setCasillerosDesactivados(jugador->getCasillerosDesactivados() + 1);
						indice = jugador->getCasillerosDesactivados();
						jugador->setCasillerosConTesorosEncontrados(casillero);
						jugador->setTurnoRecuperarTesoro(this->turnos + 5);
						std::cout << "Turno para activar casilla: " << jugador->getTurnoRecuperarTesoro(indice) << std::endl;
						unsigned int i = 1;
						unsigned int dueñoCasillero = casillero->getPropietario();
						while(this->jugadores->obtenerElemento(i)->getNumeroJugador() != dueñoCasillero) {
							i++;
						}
						Jugador* jugadorDelTesoro = this->getJugador(i);
						jugadorDelTesoro->setCantidadDeTesoros(jugadorDelTesoro->getCantidadDeTesoros() - 1);
						std::cout << "Jugador: " << jugadorDelTesoro->getNumeroJugador()
											  << " Cantidad de tesoros: "<< jugadorDelTesoro->getCantidadDeTesoros() << std::endl;
						casillero->setPropietario(jugador->getNumeroJugador());
					}
				}
				else {
					std::cout << "Se encuentra un tesoro suyo en esa casilla." << std::endl;
					this->colocarEspias(jugador);
				}
			}
			else if(casillero->getTipoFicha() == MINA) {
				minaEncontrada = true;
				casillero->quitarFicha();
				std::cout << "Su espia piso una mina, espia eliminado." << std::endl;
				jugador->setMinaEncontrada(minaEncontrada);
			}
			else if(casillero->getTipoFicha() == ESPIA) {
				//Matar a ambos espias.
			}
		}
	}

}

void TesoroBinario::colocarTesoroMina(Jugador *jugador) {
	if(jugador->getMinaEncontrada()) {
		return;
	}
	else {
		if(jugador->getCantidadDeMinasPuestas() == jugador->getCantidadDeMinasPermitidas()) {
			std::cout << "Limite de minas puestas, no puede colocar mas minas." << std::endl;
			return;
		}
		else {
			std::cout << "Jugador " << jugador->getNumeroJugador() << std::endl;
			std::cout << "Ingrese la coordenada de su tesoro mina: " << std::endl;
			Casillero* casillero = this->ingresoDeCoordenadas();
			if(casillero->estaVacio()) {
				casillero->setEstado(LLENO);
				casillero->colocarFicha(new Ficha(MINA));
				casillero->setPropietario(jugador->getNumeroJugador());
				jugador->setCantidadDeMinasPuestas(jugador->getCantidadDeMinasPuestas() + 1);
				jugador->pintarMina(casillero->getZ(), casillero->getX(), casillero->getY());
			}
			else {
				if(casillero->getTipoFicha() == TESORO) {
					if(casillero->getPropietario() != jugador->getNumeroJugador()) {
						if(casillero->getEstado() == BLINDADA) {
							std::cout << "El tesoro esta blindado, no se pudo eliminar." << std::endl;
							casillero->setEstado(LLENO);
						}
						else {
							casillero->setEstado(INACTIVA);
							unsigned int indice = jugador->getCasillerosDesactivados();
							jugador->setCasillerosConTesorosEncontrados(casillero);
							jugador->setTurnoRecuperarTesoro(this->turnos + 5);
							std::cout << "Turno para activar casilla: " << jugador->getTurnoRecuperarTesoro(indice) << std::endl;
							jugador->setCasillerosDesactivados(indice + 1);
							unsigned int i = 1;
							unsigned int dueñoCasillero = casillero->getPropietario();
							while(jugadores->obtenerElemento(i)->getNumeroJugador() != dueñoCasillero) {
								i++;
							}
							Jugador* jugadorDelTesoro = this->getJugador(i);
							jugadorDelTesoro->setCantidadDeTesoros(jugadorDelTesoro->getCantidadDeTesoros() - 1);
							std::cout << "Jugador: " << jugadorDelTesoro->getNumeroJugador()
									  << " Cantidad de tesoros: "<< jugadorDelTesoro->getCantidadDeTesoros() << std::endl;
						}
						jugador->setCantidadDeMinasPuestas(jugador->getCantidadDeMinasPuestas() + 1);
					}
				}
				else if(casillero->getTipoFicha() == ESPIA || casillero->getTipoFicha() == MINA) {
					std::cout << "Casillero lleno." << std::endl;
					this->colocarTesoroMina(jugador);
				}
			}
		}
	}
}

void TesoroBinario::mostrarMasoCarta(Jugador* jugador) {
	for(unsigned int i = 1; i <= jugador->getManoCarta()->contarElementos(); i++) {
		std::cout << "Carta: " << i << std::endl;
		switch(jugador->getManoCarta()->obtenerElemento(i)->getTipoDeCarta()) {
		case BLINDAJE:
			std::cout << "Carta blindaje" << std::endl;
			break;
		case RADAR:
			std::cout << "Carta radar" << std::endl;
			break;
		case PARTIR_TESORO:
			std::cout << "Carta partir tesoro" << std::endl;
			break;
		case AGREGAR_MINA:
			std::cout << "Carta agregar tesoro mina" << std::endl;
			break;
		case ROMPER_BLINDAJE:
			std::cout << "Carta de partir blindaje de tesoro, no puede jugar ahora la carta." << std::endl;
			break;
		case ELIMINAR_CARTA:
			std::cout << "Carta eliminar carta enemiga" << std::endl;
			break;
		}
	}
}

void TesoroBinario::jugarCarta(Jugador *jugador) {
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
	case ROMPER_BLINDAJE:
		break;
	case ELIMINAR_CARTA:
		this->funcionalidadCartas->eliminarCartaEnemiga(jugador, this->jugadores);
		break;
	}
	jugador->eliminarCartaDeLaMano(numeroCarta);
}

void TesoroBinario::eliminarJugador(unsigned int posicion) {
	if(this->jugadores->obtenerElemento(posicion)->getEstadoJugador() == false) {
		return;
	}
	else {
		if(this->jugadores->obtenerElemento(posicion)->getCantidadDeTesoros() == 0) {
			std::cout << "JUGADOR " << jugadores->obtenerElemento(posicion)->getNumeroJugador() << " ELIMINADO" << std::endl;
			//delete this->jugadores->obtenerElemento(posicion);
			//this->jugadores->removerElemento(posicion);
			this->jugadores->obtenerElemento(posicion)->jugadorEliminado();
			this->setJugadoresVivos(this->getJugadoresVivos() - 1);
		}
	}
}

void TesoroBinario::setJugadoresVivos(unsigned int jugadores) {
	this->numeroJugadoresVivos = jugadores;
}

unsigned int TesoroBinario::getJugadoresVivos() {
	return this->numeroJugadoresVivos;
}


