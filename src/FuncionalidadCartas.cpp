/*
 * FuncionalidadCartas.cpp
 *
 *  Created on: 13 nov. 2023
 *      Author: gonzalo
 */

#include "FuncionalidadCartas.h"

void FuncionalidadCartas::validarTablero(Tablero*& tablero) {
	if(tablero == NULL) {
		throw std::runtime_error("El tablero debe estar inicializado.");
	}
}

void FuncionalidadCartas::validarJugador(Jugador*& jugador) {
	if(jugador == NULL) {
		throw std::runtime_error("El jugador no puede ser nulo");
	}
}

bool FuncionalidadCartas::tesoroPropio(Casillero*& casillero, Jugador*& jugador) {
	return (casillero->getTipoFicha() == TESORO &&
			casillero->getNumeroDePropietario() == jugador->getNumeroJugador());
}

bool FuncionalidadCartas::tesoroDeOtroJugador(Casillero*& casillero, Jugador*& jugador) {
	return (casillero->getTipoFicha() == TESORO &&
			casillero->getNumeroDePropietario() != jugador->getNumeroJugador());
}

bool FuncionalidadCartas::casilleroVacio(Casillero*& casillero) {
	return casillero->estaVacio();
}

FuncionalidadCartas::FuncionalidadCartas(Tablero*& tableroDelJuego) {
	this->validarTablero(tableroDelJuego);
	this->tableroDelJuego = tableroDelJuego;
}

FuncionalidadCartas::~FuncionalidadCartas() {

}

Casillero* FuncionalidadCartas::ingresoCoordenadaDeCasillero() {
	unsigned int z, x, y;
	std::cout << "Z: ";
	std::cin >> z;
	std::cout << "X: ";
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;
	return this->tableroDelJuego->getCasillero(z, x, y);
}

void FuncionalidadCartas::eliminarTesoro(Casillero*& casillero, Lista<Jugador* >*& jugadores) {
	unsigned int numeroDePropietario = casillero->getNumeroDePropietario();
	unsigned int i = 1;
	while(jugadores->obtenerElemento(i)->getNumeroJugador() != numeroDePropietario) {
		i++;
	}
	Jugador* jugadorAEliminarTesoro = jugadores->obtenerElemento(i);
	unsigned int cantidadDeTesoros = jugadorAEliminarTesoro->getCantidadDeTesorosEnTablero()-1;
	jugadorAEliminarTesoro->setCantidadDeTesorosEnTablero(cantidadDeTesoros);
	std::cout << "Jugador " << jugadorAEliminarTesoro->getNumeroJugador()
					<< " cantidad de tesoros: " << cantidadDeTesoros << std::endl;
}

unsigned int FuncionalidadCartas::posicionCartaRomperBlindaje(Jugador*& jugador) {
	unsigned int posicionCarta = 1;
	jugador->getManoDeCartas()->iniciarCursor();
	while(jugador->getManoDeCartas()->avanzarCursor()) {
		Carta* cartaActual = jugador->getManoDeCartas()->obtenerCursor();
		if(cartaActual->getTipoDeCarta() != ROMPER_BLINDAJE) {
			posicionCarta++;
		}
	}
	return posicionCarta;
}

void FuncionalidadCartas::pintarTesoro(TableroBMP*& tableroBMP, Casillero* casillero, Jugador* jugador) {
	tableroBMP->pintarTesoro(casillero->getZ(), casillero->getX(), casillero->getY(),
			*(jugador->getTableroBMP()), jugador->getNombreTablero());
}

Jugador* FuncionalidadCartas::jugadorAEliminarCarta(Jugador* jugador, Lista<Jugador* >* jugadores) {
	unsigned int numeroJugadorAEliminarCarta = 0;

	bool jugadorEncontrado = false;

	Jugador* jugadorAEliminarCarta = NULL;
	do {
		std::cout << "Ingrese el número del jugador del cual desea eliminar una de sus cartas: ";
		std::cin >> numeroJugadorAEliminarCarta;
		unsigned int indice = 1;
		while(indice <= jugadores->contarElementos() && jugadorEncontrado == false) {
			if(jugadores->obtenerElemento(indice)->getNumeroJugador() == numeroJugadorAEliminarCarta &&
					jugadores->obtenerElemento(indice)->getNumeroJugador() != jugador->getNumeroJugador()) {
				jugadorAEliminarCarta = jugadores->obtenerElemento(indice);
				jugadorEncontrado = true;
			}
			else {
				indice++;
			}
		}

		if(jugadorEncontrado == false) {
			std::cout << "El numero del jugador está mal ingresado o no existe." << std::endl;
		}

	} while(jugadorEncontrado == false);
	return jugadorAEliminarCarta;
}

void FuncionalidadCartas::blindar(Jugador*& jugador) {
	this->validarJugador(jugador);
	std::cout << "Ingrese la coordenada de su tesoro que desea blindar: " << std::endl;
	Casillero* casilleroConTesoroABlindar = this->ingresoCoordenadaDeCasillero();

	if(!this->tesoroPropio(casilleroConTesoroABlindar, jugador)) {
		std::cout << "Coordenada mal ingresada." << std::endl;
		this->blindar(jugador);
	}
	else {
		casilleroConTesoroABlindar->setEstado(BLINDADO);
	}
}

void FuncionalidadCartas::radar(Jugador*& jugador) {
	this->validarJugador(jugador);
	unsigned int cantidadTesorosDetectados = 0;
	std::cout << "Ingrese la coordenada donde quiere poner su radar: " << std::endl;
	Casillero* casilleroAPonerRadar = this->ingresoCoordenadaDeCasillero();
	int rangoDelRadar = casilleroAPonerRadar->getRangoVecinos();
	for(int i = -rangoDelRadar; i <= rangoDelRadar; i++) {
		for(int j = -rangoDelRadar; j <= rangoDelRadar; j++) {
			for(int k = -rangoDelRadar; k <= rangoDelRadar; k++) {
				Casillero* vecino = casilleroAPonerRadar->getVecino(i, j, k);
				if(casilleroAPonerRadar->validarVecino(vecino)) {
					if(!this->casilleroVacio(vecino)) {
						if(this->tesoroDeOtroJugador(vecino, jugador)) {
							cantidadTesorosDetectados++;
						}
					}
				}
			}
		}
	}
	if(cantidadTesorosDetectados != 0) {
		std::cout << "Se han detectado " << cantidadTesorosDetectados << " tesoros." << std::endl;
	}
	else {
		std::cout << "Su radar no ha detectado ningún tesoro enemigo." << std::endl;
	}
}

void FuncionalidadCartas::partirTesoro(Jugador*& jugador, TableroBMP*& tableroBMP) {
	this->validarJugador(jugador);
	std::cout << "Ingrese la coordenada del tesoro que desea partir:" << std::endl;
	Casillero* casilleroAPartirTesoro = this->ingresoCoordenadaDeCasillero();

	if(!this->tesoroPropio(casilleroAPartirTesoro, jugador)) {
		std::cout << "Coordenada mal ingresada." << std::endl;
		this->partirTesoro(jugador, tableroBMP);
	}
	else {
		Casillero* casilleroAPonerTesoro = NULL;
		int rangoDeBusqueda = casilleroAPartirTesoro->getRangoVecinos();
		int i = -rangoDeBusqueda; int j = -rangoDeBusqueda; int k = -rangoDeBusqueda;
		while(i <= rangoDeBusqueda && casilleroAPonerTesoro == NULL) {
			while(j <= rangoDeBusqueda && casilleroAPonerTesoro == NULL) {
				while(k <= rangoDeBusqueda && casilleroAPonerTesoro == NULL) {
					Casillero* vecino = casilleroAPartirTesoro->getVecino(i, j, k);
					if(casilleroAPartirTesoro->validarVecino(vecino)) {
						if(this->casilleroVacio(vecino)) {
							casilleroAPonerTesoro = vecino;
						}
					}
					k++;
				}
				k = -rangoDeBusqueda;
				j++;
			}
			j = -rangoDeBusqueda;
			i++;
		}
		if(casilleroAPonerTesoro == NULL) {
			std::cout << "No se pudo partir su tesoro, no hay casilleros vacíos alrededor." << std::endl;
		}
		else {
			std::cout << "Casillero con nuevo tesoro: "
					<< casilleroAPonerTesoro->getZ() << " - " << casilleroAPonerTesoro->getX()
					<< " - " << casilleroAPonerTesoro->getY() << std::endl;
			casilleroAPonerTesoro->colocarFicha(new Ficha(TESORO), jugador->getNumeroJugador());
			jugador->setCantidadDeTesorosEnTablero(jugador->getCantidadDeTesorosEnTablero() + 1);
			this->pintarTesoro(tableroBMP, casilleroAPonerTesoro, jugador);
		}
	}
}

void FuncionalidadCartas::agregarMina(Jugador*& jugador) {
	this->validarJugador(jugador);
	jugador->setCantidadDeMinasPermitidas(jugador->getCantidadDeMinasPermitidas() + 1);
}

void FuncionalidadCartas::romperBlindaje(Jugador*& jugador, Lista<Jugador* >*& jugadores, Casillero*& casillero) {
	this->validarJugador(jugador);
	std::cout << "TESORO RECUPERADO." << std::endl;
	this->eliminarTesoro(casillero, jugadores);
	casillero->cambiarFicha(ESPIA, jugador->getNumeroJugador());
	jugador->eliminarCartaDeLaMano(this->posicionCartaRomperBlindaje(jugador));
}

void FuncionalidadCartas::eliminarCarta(Jugador* jugador, Lista<Jugador* >* jugadores) {
	this->validarJugador(jugador);
	Jugador* jugadorAEliminarCarta = this->jugadorAEliminarCarta(jugador, jugadores);
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, jugadorAEliminarCarta->getManoDeCartas()->contarElementos());
	int numeroRandom = dist(mt);
	jugadorAEliminarCarta->eliminarCartaDeLaMano(numeroRandom);
	std::cout << "Carta eliminada." << std::endl;
}








