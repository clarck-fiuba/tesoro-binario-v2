/*
 * TesoroBinario.cpp
 *
 *  Created on: 24 oct. 2023
 *      Author: gonzalo
 */
#include "TesoroBinario.h"
#include "Constantes.h"



void validarCantidadDeJugadores(unsigned int numeroJugadores){

	if (numeroJugadores < 0){
		throw "numero invalido";
	}

}


void TesoroBinario::validarPosicion(unsigned int posicion){
	if (posicion < 0){
		throw "numero invalido";
	}else
		if (posicion > this->jugadores->contarElementos()){
			throw "no puede superar la cantidad de jugadores";
		}

}

void TesoroBinario::validarCoordenada(unsigned int &z, unsigned int &x, unsigned int &y){

	std::cout << "Z: ";
	std::cin >> z;
	if(z < 1 || z > this->numeroJugadores / CAPA) {
		throw std::runtime_error("La coordenada z esta mal ingresada");
	}
	std::cout << "X: ";
	std::cin >> x;
	if(x < 1 || x > this->numeroJugadores * ANCHO) {
		throw std::runtime_error("La coordenada x esta mal ingresada");
	}

	std::cout << "Y: ";
	std::cin >> y;
	if(y < 1 || y > this->numeroJugadores * ALTO) {
		throw std::runtime_error("La coordenada y esta mal ingresada");
	}
}



void colocarFicha(Casillero* casillero, Jugador* jugador, unsigned int numero)){

	if (numero == 1){
		casillero->setEstado(LLENO);
		casillero->colocarFicha(new Ficha(TESORO));
		casillero->setPropietario(jugador->getNumeroJugador());
	}else
		if (numero == 2){
			casillero->setEstado(LLENO);
			casillero->colocarFicha(new Ficha(ESPIA));
			casillero->setPropietario(jugador->getNumeroJugador());
		}else
			if (numero == 3){
				casillero->setEstado(LLENO);
				casillero->colocarFicha(new Ficha(MINA));
				casillero->setPropietario(jugador->getNumeroJugador());
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
	this->movimiento = ' ';
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
	validarCantidadDeJugadores(posicion);
	return this->jugadores->obtenerElemento(posicion);
}

Lista<Jugador* > *TesoroBinario::getJugadores() {
	return this->jugadores;
}

Casillero* TesoroBinario::ingresoDeCoordenadas() {
	unsigned int z, x, y;
	validarCoordenada(z, x ,y);
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
		colocarFicha(casillero, jugador, 1);
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

void TesoroBinario::moverTesoro(Jugador * jugador){
	std::cout << "ingrese la posicion del tesoro que quiere mover " << std::endl;
	Casillero * casilleroViejo = this->ingresoDeCoordenadas();
	this->validarPosicionTesoro(casilleroViejo);
	casilleroViejo->quitarFicha();

	Casillero * casilleroNuevo = casilleroViejo;
	this->colocarNuevaPosicion(jugador, casilleroNuevo);
}

void TesoroBinario::validarPosicionTesoro(Casillero * casilleroViejo){
	if(casilleroViejo->getTipoFicha() != TESORO){
		throw std::runtime_error("en esta posicion no hay un tesoro para mover");
	}
}

Casillero * TesoroBinario::nuevasCoordenas(unsigned int x, unsigned int y, unsigned int z){
	return this->tablero->getCasillero(z, x, y);
}


void TesoroBinario::elegirMovimiento(){
	std::cout << "que movimiento desea realizar: ";
	std::cin >> this->movimiento;
	this->validarMovimiento();
}

void TesoroBinario::validarMovimiento(){
	if (this->movimiento != ARRIBA && this->movimiento != ABAJO && this->movimiento != DERECHA && this->movimiento != IZQUIERDA && this->movimiento != MENOS_PROFUNIDAD && this->movimiento != MAS_PROFUNDIDAD){
		throw std::runtime_error("Tipo de movimiento invalido");
	}
}


void TesoroBinario::colocarNuevaPosicion(Jugador * jugador, Casillero * casilleroNuevo){
	this->elegirMovimiento();
	if (this->movimiento == ARRIBA && casilleroNuevo->getY() != 0){
		casilleroNuevo = this->nuevasCoordenas(casilleroNuevo->getX(), casilleroNuevo->getY() - 1, casilleroNuevo->getZ());
		this->colocarTesoroNuevo(jugador, casilleroNuevo);
	}
	else if (this->movimiento == ABAJO && casilleroNuevo->getY() != this->altoTablero){
		casilleroNuevo = this->nuevasCoordenas(casilleroNuevo->getX(), casilleroNuevo->getY() + 1, casilleroNuevo->getZ());
		this->colocarTesoroNuevo(jugador, casilleroNuevo);
	}
	else if (this->movimiento == DERECHA && casilleroNuevo->getX() != this->anchoTablero){
		casilleroNuevo = this->nuevasCoordenas(casilleroNuevo->getX() + 1, casilleroNuevo->getY(), casilleroNuevo->getZ());
		this->colocarTesoroNuevo(jugador, casilleroNuevo);
	}
	else if (this->movimiento == IZQUIERDA && casilleroNuevo->getX() != 0){
		casilleroNuevo = this->nuevasCoordenas(casilleroNuevo->getX() - 1, casilleroNuevo->getY(), casilleroNuevo->getZ());
		this->colocarTesoroNuevo(jugador, casilleroNuevo);
	}
	else if (this->movimiento == MAS_PROFUNDIDAD && casilleroNuevo->getZ() != this->profundidadTablero){/*PREGUNTAR COMO ES EL MAPA*/
		casilleroNuevo = this->nuevasCoordenas(casilleroNuevo->getX(), casilleroNuevo->getY() , casilleroNuevo->getZ() + 1);
		this->colocarTesoroNuevo(jugador, casilleroNuevo);
	}
	else if (this->movimiento == MENOS_PROFUNIDAD && casilleroNuevo->getZ() != 0){
		casilleroNuevo = this->nuevasCoordenas(casilleroNuevo->getX() , casilleroNuevo->getY(), casilleroNuevo->getZ() - 1);
		this->colocarTesoroNuevo(jugador, casilleroNuevo);
	}
}

void TesoroBinario::colocarTesoroNuevo(Jugador * jugador, Casillero * casilleroNuevo){
	if(casilleroNuevo->estaVacio()) {
		colocarFicha(casilleroNuevo, jugador, 1);
		jugador->pintarTesoro(casilleroNuevo->getZ(), casilleroNuevo->getX(), casilleroNuevo->getY());
		Jugador* jugadorDelTesoro = this->getJugador(casilleroNuevo->getPropietario());
		std::cout << "se movio el tesoro de forma correcta" << std::endl;
	}
	else {
		if(casilleroNuevo->getTipoFicha() == TESORO) {
			if(casilleroNuevo->getPropietario() == jugador->getNumeroJugador()) {
				std::cout << "Ya se encuentra un tesoro suyo en esta casilla." << std::endl;
				this->colocarNuevaPosicion(jugador, casilleroNuevo);
			}
			else {
				std::cout << "Se encuentra un tesoro del jugador " << casilleroNuevo->getPropietario() << std::endl;
				this->colocarNuevaPosicion(jugador, casilleroNuevo);
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
			colocarFicha(casillero, jugador, 2);
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
						eliminarTesoro(jugador, casillero, this->jugadores);
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
				colocarFicha(casillero, jugador, 3);
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
							eliminarTesoro(jugador, casillero, this->jugadores);
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

	unsigned int numeroCarta;
	char pregunta;

	if(jugador->getManoCarta()->contarElementos() > 0){

		this->mostrarMasoCarta(jugador);

		do {
			std::cout << "Desea usar una carta? (s/n): ";
			std::cin  >> pregunta;
		} while (pregunta != 's' && pregunta != 'n');

		if (pregunta == 's'){
			do{
				std::cout << "Ingrese la carta que desea jugar: ";
				std::cin  >> numeroCarta;
			} while(numeroCarta != 1 && numeroCarta != 2 && numeroCarta != 3)

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
	}
}


void TesoroBinario::eliminarJugador(unsigned int posicion) {
	if(this->jugadores->obtenerElemento(posicion)->getEstadoJugador() == false) {
		return;
	}
	else {
		if(this->jugadores->obtenerElemento(posicion)->getCantidadDeTesoros() == 0) {
			std::cout << "JUGADOR " << jugadores->obtenerElemento(posicion)->getNumeroJugador() << " ELIMINADO" << std::endl;
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


