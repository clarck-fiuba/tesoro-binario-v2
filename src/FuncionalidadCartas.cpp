/*
 * FuncionalidadCartas.cpp
 *
 *  Created on: 26/10/2023
 *      Author: algo2
 */
#include "FuncionalidadCartas.h"

void FuncionalidadCartas::validarTablero(Tablero* tablero) {
	if(tablero == NULL) {
		throw std::runtime_error("El tablero ya debe estar inicializado");
	}
}

Casillero* FuncionalidadCartas::ingresoDeCoordenadas() {
	unsigned int z, x, y;
	std::cout << "Z: ";
	std::cin >> z;
	std::cout << "X: ";
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;
	return this->tablero->getCasillero(z, x, y);
}

bool FuncionalidadCartas::validarCasilleroTesoro(Casillero* casillero) {
	return casillero->getTipoFicha() == TESORO;
}

bool FuncionalidadCartas::validarCasilleroPropietario(Casillero* casillero, Jugador* jugador) {
	return casillero->getPropietario() == jugador->getNumeroJugador();
}

void FuncionalidadCartas::validarJugador(Jugador* jugador) {
	if(jugador == NULL) {
		throw std::runtime_error("El jugador ya debe estar inicializado");
	}
}

FuncionalidadCartas::FuncionalidadCartas(Tablero* tablero) {
	this->validarTablero(tablero);
	this->tablero = tablero;
}

FuncionalidadCartas::~FuncionalidadCartas() {
	// TODO Auto-generated destructor stub
}

void FuncionalidadCartas::blindarCarta(Jugador* jugador){
	this->validarJugador(jugador);
	std::cout << "Ingrese la coordenada de su tesoro que desea blindar: " << std::endl;
	Casillero* casillero = this->ingresoDeCoordenadas();
	if(this->validarCasilleroTesoro(casillero) && this->validarCasilleroPropietario(casillero, jugador)){
		casillero->setEstado(BLINDADA);
	}
	else {
		throw std::runtime_error("Casillero mal ingresado");
	}
	if(casillero->getEstado() == BLINDADA) {
		std::cout << "Casillero blindado" << std::endl;
	}
}

void FuncionalidadCartas::radar(Jugador* jugador) {
	this->validarJugador(jugador);
	unsigned contadorTesoros = 0;
	std::cout << "Ingrese la coordenada donde quiere poner su radar: " << std::endl;
	Casillero* casillero = this->ingresoDeCoordenadas();
	for(int i = -casillero->getRangoVecinos(); i <= casillero->getRangoVecinos(); i++) {
		for(int j = -casillero->getRangoVecinos(); j <= casillero->getRangoVecinos(); j++) {
			for(int k = -casillero->getRangoVecinos(); k <= casillero->getRangoVecinos(); k++) {
				Casillero* vecino = casillero->getVecino(i, j, k);
				if(casillero->validarVecino(vecino)) {
					if(!vecino->estaVacio()) {
						if(this->validarCasilleroTesoro(vecino)) {
							if(!this->validarCasilleroPropietario(vecino, jugador))
								contadorTesoros++;
						}
					}
				}
			}
		}
	}
	if(contadorTesoros != 0) {
		std::cout << "Se han detectado " << contadorTesoros << " tesoros" << std::endl;
	}
	else {
		std::cout << "El radar no ha detectado ningun tesoro" << std::endl;
	}
}

void FuncionalidadCartas::partirTesoro(Jugador* jugador) {
	this->validarJugador(jugador);
	bool tesoroPartido = false;
	std::cout << "Ingrese el tesoro que desea partir: " << std::endl;
	Casillero* casillero = this->ingresoDeCoordenadas();
	if(this->validarCasilleroTesoro(casillero) && this->validarCasilleroPropietario(casillero, jugador)) {
		for(int i = -casillero->getRangoVecinos(); i <= casillero->getRangoVecinos(); i++) {
			for(int j = -casillero->getRangoVecinos(); j <= casillero->getRangoVecinos(); j++) {
				for(int k = -casillero->getRangoVecinos(); k <= casillero->getRangoVecinos(); k++) {
					Casillero* vecino = casillero->getVecino(i, j, k);
					if(casillero->validarVecino(vecino)) {
						if(vecino->estaVacio()) {
							vecino->setEstado(LLENO);
							vecino->colocarFicha(new Ficha(TESORO));
							vecino->setPropietario(jugador->getNumeroJugador());
							jugador->setCantidadDeTesoros(jugador->getCantidadDeTesoros()+1);
							tesoroPartido = true;
							return;
						}
					}
				}
			}
		}
		if(!tesoroPartido) {
			std::cout << "No se pudo partir el tesoro, no hay vecinos libres" << std::endl;
		}
	}
	else {
		std::cout << "Casillero mal ingresado o inactivo" << std::endl;
		this->partirTesoro(jugador);
	}
}

void FuncionalidadCartas::agregarTesoroMina(Jugador* jugador) {
	this->validarJugador(jugador);
	jugador->setCantidadDeMinasPermitidas(jugador->getCantidadDeMinasPermitidas() + 1);
	std::cout << "Ahora puede colocar " << jugador->getCantidadDeMinasPermitidas() << " tesoros mina" << std::endl;
}

void FuncionalidadCartas::romperBlindaje(Jugador* jugador, Lista<Jugador* >* jugadores, Casillero* casillero) {
	this->validarJugador(jugador);
	//validar lista jugadores
	//validar casillero
	std::cout << "Tesoro recuperado" << std::endl;
	casillero->cambiarFicha(ESPIA);
	casillero->setEstado(LLENO);
	unsigned int i = 1;
	unsigned int dueñoCasillero = casillero->getPropietario();
	while(jugadores->obtenerElemento(i)->getNumeroJugador() != dueñoCasillero) {
		i++;
	}
	Jugador* jugadorDelTesoro = jugadores->obtenerElemento(i);
	jugadorDelTesoro->setCantidadDeTesoros(jugadorDelTesoro->getCantidadDeTesoros() - 1);
	std::cout << "Jugador: " << jugadorDelTesoro->getNumeroJugador()
			  << " Cantidad de tesoros: "<< jugadorDelTesoro->getCantidadDeTesoros() << std::endl;
	casillero->setPropietario(jugador->getNumeroJugador());
}

void FuncionalidadCartas::eliminarCartaEnemiga(Jugador* jugador, Lista<Jugador* >* jugadores) {
	this->validarJugador(jugador);
	unsigned int numeroJugadorAEliminarCarta = 0;
	std::cout << "Ingrese el numero del jugador que desea eliminar una de sus cartas: ";
	std::cin >> numeroJugadorAEliminarCarta;
	unsigned int i = 1;
	while(jugadores->obtenerElemento(i)->getNumeroJugador() != numeroJugadorAEliminarCarta) {
		i++;
	}
	Jugador* jugadorAEliminarCarta = jugadores->obtenerElemento(i);
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, jugadorAEliminarCarta->getManoCarta()->contarElementos());
	int numeroRandom = dist(mt);
	jugadorAEliminarCarta->eliminarCartaDeLaMano(numeroRandom);
}








