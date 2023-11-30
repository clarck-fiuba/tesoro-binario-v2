/*
 * TesoroBinario.cpp
 *
 *  Created on: 24 oct. 2023
 *      Author: gonzalo
 */
#include "TesoroBinario.h"

void TesoroBinario::validarCantidadDeJugadores(unsigned int cantidadDeJugadores) {
	if(cantidadDeJugadores <= 1) {
		throw std::runtime_error("La cantidad de jugadores debe ser mayor a 1.");
	}
}

bool TesoroBinario::validarDireccionDeMoviento(char direccionDeMovimiento) {
	if(direccionDeMovimiento != IZQUIERDA && direccionDeMovimiento != DERECHA &&
			direccionDeMovimiento != ABAJO && direccionDeMovimiento != ARRIBA &&
			direccionDeMovimiento != ADELANTE && direccionDeMovimiento != ATRAS) {
		std::cout << "Dirección inexistente. Inténtelo de nuevo." << std::endl;
		return false;
	}
	return true;
}

bool TesoroBinario::validarMovimiento(char direccionDeMovimiento, Casillero* casilleroConTesoroAMover) {
	if(this->getTablero()->getProfundidad() == 1 && (direccionDeMovimiento == ADELANTE ||
			direccionDeMovimiento == ATRAS)) {
		std::cout << "No se puede mover el tesoro en esa dirección, el tablero es de 1 capa. ";
		std::cout << "Inténtelo de nuevo." << std::endl;
		return false;
	}
	else if(casilleroConTesoroAMover->getZ() == 1 && direccionDeMovimiento == ADELANTE) {
		std::cout << "No se puede mover el tesoro para adelante. ";
		std::cout << "Inténtelo de nuevo." << std::endl;
		return false;
	}
	else if(casilleroConTesoroAMover->getX() == 1 && direccionDeMovimiento == ARRIBA) {
		std::cout << "No se puede mover el tesoro para arriba. ";
		std::cout << "Inténtelo de nuevo." << std::endl;
		return false;
	}
	else if(casilleroConTesoroAMover->getY() == 1 && direccionDeMovimiento == IZQUIERDA) {
		std::cout << "No se puede mover el tesoro para la izquierda. ";
		std::cout << "Inténtelo de nuevo." << std::endl;
		return false;
	}
	else if(casilleroConTesoroAMover->getZ() == this->tablero->getProfundidad() &&
			direccionDeMovimiento == ATRAS) {
		std::cout << "No se puede mover el tesoro para atrás. ";
		std::cout << "Inténtelo de nuevo." << std::endl;
		return false;
	}
	else if(casilleroConTesoroAMover->getX() == this->tablero->getAlto() &&
			direccionDeMovimiento == ABAJO) {
		std::cout << "No se puede mover el tesoro para abajo. ";
		std::cout << "Inténtelo de nuevo." << std::endl;
		return false;
	}
	else if(casilleroConTesoroAMover->getY() == this->tablero->getAncho() &&
			direccionDeMovimiento == DERECHA) {
		std::cout << "No se puede mover el tesoro para la derecha.";
		std::cout << "Inténtelo de nuevo." << std::endl;
		return false;
	}
	else {
		return true;
	}
}

bool TesoroBinario::tesoroPropio(Casillero* casillero, Jugador* jugador) {
	return (casillero->getTipoFicha() == TESORO &&
			casillero->getNumeroDePropietario() == jugador->getNumeroJugador());
}

bool TesoroBinario::tesoroDeOtroJugador(Casillero* casillero, Jugador* jugador) {
	return (casillero->getTipoFicha() == TESORO &&
			casillero->getNumeroDePropietario() != jugador->getNumeroJugador());
}

bool TesoroBinario::espiaDeOtroJugador(Casillero* casillero, Jugador* jugador) {
	return (casillero->getTipoFicha() == ESPIA &&
			casillero->getNumeroDePropietario() != jugador->getNumeroJugador());
}

bool TesoroBinario::minaDeOtroJugador(Casillero* casillero, Jugador* jugador) {
	return (casillero->getTipoFicha() == MINA &&
			casillero->getNumeroDePropietario() != jugador->getNumeroJugador());
}

bool TesoroBinario::casilleroVacio(Casillero* casillero) {
	return casillero->estaVacio();
}

bool TesoroBinario::casilleroInactivo(Casillero* casillero) {
	return casillero->getEstado() == INACTIVO;
}

bool TesoroBinario::tesoroBlindado(Casillero* casillero) {
	return (casillero->getTipoFicha() == TESORO && casillero->getEstado() == BLINDADO);
}

bool TesoroBinario::limiteAlcanzadoDeMinasEnTablero(Jugador* jugador) {
	return jugador->getCantidadDeMinasEnTablero() == jugador->getCantidadDeMinasPermitidas();
}

TesoroBinario::TesoroBinario() {
	this->cantidadDeJugadores = this->configurarCantidadDeJugadores();
	this->numeroDeTurno = 0;
	this->cantidadDeTesorosPermitidos = this->configurarCantidadDeTesorosPermitidos(cantidadDeJugadores);
	this->cantidadDeMinasPermitidas = this->cantidadDeJugadores;
	this->jugadores = this->configurarJugadores(this->cantidadDeJugadores);
	this->tablero = this->configurarTablero(this->cantidadDeJugadores);
	this->casillerosInactivos = new Lista<Casillero* >();
	this->numeroDeTurnoActivarCasillero = new Lista<unsigned int>();
	this->tableroBMP = this->configurarTableroBMP(tablero);
	this->funcionalidadCartas = new FuncionalidadCartas(this->tablero);
}

TesoroBinario::~TesoroBinario() {
	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()) {
		delete this->jugadores->obtenerCursor();
	}
	delete this->jugadores;
	delete this->tablero;
	delete this->funcionalidadCartas;
	delete this->casillerosInactivos;
	delete this->numeroDeTurnoActivarCasillero;
	delete this->tableroBMP;
}

Tablero *TesoroBinario::getTablero() {
	return this->tablero;
}

Jugador* TesoroBinario::getJugador(unsigned int posicion) {
	return this->jugadores->obtenerElemento(posicion);
}

Lista<Jugador* > *TesoroBinario::getJugadores() {
	return this->jugadores;
}

unsigned int TesoroBinario::getNumeroDeTurno() {
	return this->numeroDeTurno;
}

void TesoroBinario::actualizarNumeroDeTurno(unsigned int numeroDeTurno) {
	this->numeroDeTurno = numeroDeTurno;
}

unsigned int TesoroBinario::configurarCantidadDeJugadores() {
	unsigned int cantidadDeJugadores;
	std::cout << "Ingrese la cantidad de jugadores: ";
	std::cin >> cantidadDeJugadores;
	this->validarCantidadDeJugadores(cantidadDeJugadores);
	return cantidadDeJugadores;
}

unsigned int TesoroBinario::configurarCantidadDeTesorosPermitidos(unsigned int cantidadDeJugadores) {
	unsigned int cantidadDeTesorosPermitidos = cantidadDeJugadores * MULTIPLICADOR_DE_TESOROS;
	return cantidadDeTesorosPermitidos;
}

Lista<Jugador* >* TesoroBinario::configurarJugadores(unsigned int cantidadDeJugadores) {
	Lista<Jugador* >* jugadores = new Lista<Jugador* >();
	for(unsigned int i = 1; i <= cantidadDeJugadores; i++) {
		Jugador* jugador = new Jugador(i);
		jugador->setCantidadDeMinasPermitidas(this->cantidadDeMinasPermitidas);
		jugadores->agregarElemento(jugador);
	}
	return jugadores;
}

Tablero* TesoroBinario::configurarTablero(unsigned int cantidadDeJugadores) {
	Tablero* tablero = new Tablero(cantidadDeJugadores / MULTIPLICADOR_PROFUNDIDAD,
			MULTIPLICADOR_ANCHO * cantidadDeJugadores, MULTIPLICADOR_ALTO * cantidadDeJugadores);
	return tablero;
}

TableroBMP* TesoroBinario::configurarTableroBMP(Tablero* tablero) {
	TableroBMP* tableroBMP = new TableroBMP(static_cast<int>(tablero->getProfundidad()),
			static_cast<int>(tablero->getAncho()), static_cast<int>(tablero->getAlto()));
	return tableroBMP;
}

void TesoroBinario::crearTableroBMPDeLosJugadores() {
	std::cout << "Creando los tablerosBMP de los jugadores..." << std::endl;
	this->getJugadores()->iniciarCursor();
	while(this->getJugadores()->avanzarCursor()) {
		Jugador* jugador = this->getJugadores()->obtenerCursor();
		this->tableroBMP->crearTablero(*(jugador->getTableroBMP()), jugador->getNombreTablero());
	}
	std::cout << "Tableros creados con éxito." << std::endl;
}

void TesoroBinario::mostrarConfiguracionesDelJuego() {
	std::cout << "Cada jugador tiene que ingresar "
			  << this->cantidadDeTesorosPermitidos << " tesoros." << std::endl;

	std::cout << "Cada jugador tiene " << this->getJugador(1)->getCantidadDeMinasPermitidas()
					<< " minas para colocar en el tablero." << std::endl;

	std::cout << "El tablero creado para cada jugador tiene dimensiones:";
	std::cout << " Z: "<< this->getTablero()->getProfundidad();
	std::cout << " X: "<< this->getTablero()->getAncho();
	std::cout << " Y: "<< this->getTablero()->getAlto() << std::endl;
}

void TesoroBinario::mostrarManoDeCartas(Jugador* jugador) {
	std::cout << "Mano de cartas: ";
	for(unsigned int i = 1; i <= jugador->getManoDeCartas()->contarElementos(); i++) {
		switch(jugador->getManoDeCartas()->obtenerElemento(i)->getTipoDeCarta()) {
		case BLINDAR:
			std::cout << i << ".BLINDAR TESORO  ";
			break;
		case RADAR:
			std::cout << i << ".RADAR  ";
			break;
		case PARTIR_TESORO:
			std::cout << i << ".PARTIR TESORO  ";
			break;
		case AGREGAR_MINA:
			std::cout << i << ".AGREGAR MINA  ";
			break;
		case ROMPER_BLINDAJE:
			std::cout << i << ".ROMPER BLINDAJE   ";
			break;
		case ELIMINAR_CARTA:
			std::cout << i << ".ELIMINAR CARTA  ";
			break;
		}
	}
	std::cout << std::endl;
}

Casillero* TesoroBinario::ingresoCoordenadaDeCasillero() {
	unsigned int z, x, y;
	std::cout << "Z: ";
	std::cin >> z;
	std::cout << "X: ";
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;
	return this->tablero->getCasillero(z, x, y);
}

char TesoroBinario::ingresoDeDireccionDeMoviento(Casillero* casilleroConTesoroAMover) {
	char direccionDeMovimiento;
	do {
		std::cout << "Ingrese la dirección en la que desea moverse: ";
		std::cin >> direccionDeMovimiento;
	} while(!this->validarDireccionDeMoviento(direccionDeMovimiento) ||
			!this->validarMovimiento(direccionDeMovimiento, casilleroConTesoroAMover));

	return direccionDeMovimiento;
}

Casillero* TesoroBinario::calculoNuevoCasilleroConTesoro(char direccionDeMovimiento,
		Casillero* casilleroConTesoroAMover) {
	Casillero* nuevoCasilleroConTesoro;
	switch(direccionDeMovimiento) {
	case ADELANTE:
		nuevoCasilleroConTesoro = this->tablero->getCasillero(casilleroConTesoroAMover->getZ() - 1,
				casilleroConTesoroAMover->getX(), casilleroConTesoroAMover->getY());
		break;
	case ARRIBA:
		nuevoCasilleroConTesoro = this->tablero->getCasillero(casilleroConTesoroAMover->getZ(),
				casilleroConTesoroAMover->getX() - 1, casilleroConTesoroAMover->getY());
		break;
	case IZQUIERDA:
		nuevoCasilleroConTesoro = this->tablero->getCasillero(casilleroConTesoroAMover->getZ(),
				casilleroConTesoroAMover->getX(), casilleroConTesoroAMover->getY() - 1);
		break;
	case ATRAS:
		nuevoCasilleroConTesoro = this->tablero->getCasillero(casilleroConTesoroAMover->getZ() + 1,
				casilleroConTesoroAMover->getX(), casilleroConTesoroAMover->getY());
		break;
	case ABAJO:
		nuevoCasilleroConTesoro = this->tablero->getCasillero(casilleroConTesoroAMover->getZ(),
				casilleroConTesoroAMover->getX() + 1, casilleroConTesoroAMover->getY());
		break;
	case DERECHA:
		nuevoCasilleroConTesoro = this->tablero->getCasillero(casilleroConTesoroAMover->getZ(),
				casilleroConTesoroAMover->getX(), casilleroConTesoroAMover->getY() + 1);
		break;
	}
	return nuevoCasilleroConTesoro;
}

bool TesoroBinario::buscarCartaRomperBlindaje(Jugador* jugador) {
	jugador->getManoDeCartas()->iniciarCursor();
	while(jugador->getManoDeCartas()->avanzarCursor()) {
		Carta* cartaActual = jugador->getManoDeCartas()->obtenerCursor();
		if(cartaActual->getTipoDeCarta() == ROMPER_BLINDAJE) {
			return true;
		}
	}
	return false;
}

Jugador* TesoroBinario::jugadorDelCasillero(Casillero* casillero) {
	unsigned int numeroDePropietario = casillero->getNumeroDePropietario();
	unsigned int i = 1;
	while(i <= this->getJugadores()->contarElementos()) {
		if(this->getJugador(i)->getNumeroJugador() == numeroDePropietario) {
			return this->getJugador(i);
		}
		else {
			i++;
		}
	}
	return NULL;
}

void TesoroBinario::eliminarTesoro(Casillero* casillero) {
	Jugador* jugadorAEliminarTesoro = this->jugadorDelCasillero(casillero);
	unsigned int cantidadDeTesoros = jugadorAEliminarTesoro->getCantidadDeTesorosEnTablero()-1;
	jugadorAEliminarTesoro->setCantidadDeTesorosEnTablero(cantidadDeTesoros);
	std::cout << "Jugador " << jugadorAEliminarTesoro->getNumeroJugador()
		<< " cantidad de tesoros: " << cantidadDeTesoros << std::endl;
}

void TesoroBinario::inactivarCasillero(Casillero* casillero, unsigned int numeroDeTurno) {
	casillero->setEstado(INACTIVO);
	this->casillerosInactivos->agregarElemento(casillero);
	this->numeroDeTurnoActivarCasillero->agregarElemento(numeroDeTurno + TURNOS_CASILLERO_DESACTIVADO);
}

void TesoroBinario::activarCasillero() {
	if(this->casillerosInactivos->estaVacia()) {
		std::cout << "No hay casilleros para activar." << std::endl;
		return;
	}
	unsigned int indice = 1;
	if(this->numeroDeTurnoActivarCasillero->obtenerElemento(indice) == this->numeroDeTurno) {
		Casillero* casilleroActual = this->casillerosInactivos->obtenerElemento(indice);
		std::cout << "Casillero: " << casilleroActual->getZ() << " - " << casilleroActual->getX()
				<< " - " << casilleroActual->getY() << std::endl;
		if(casilleroActual->getTipoFicha() != ESPIA) {
			std::cout << "Casillero activado." << std::endl;
			casilleroActual->quitarFicha();
		}
		else {
			std::cout << "TESORO RECUPERADO." << std::endl;
			casilleroActual->setEstado(LLENO);
		}
		this->casillerosInactivos->removerElemento(indice);
		this->numeroDeTurnoActivarCasillero->removerElemento(indice);
	}
}

void TesoroBinario::romperBlindaje(Casillero*& casillero) {
	if(!this->tesoroBlindado(casillero)) {
		throw std::runtime_error("No se encuentra un tesoro blindado en el casillero.");
	}
	else {
		casillero->setEstado(LLENO);
	}
}

bool TesoroBinario::saltarTurno(Jugador* jugador) {
	return jugador->getEstadoPisadoMinaDeOtroJugador();
}

void TesoroBinario::colocarTesoros(Jugador* jugador) {
	std::cout << "JUGADOR " << jugador->getNumeroJugador() << ": ";
	std::cout << "Ingrese la coordenada donde quiere poner su "
			<< jugador->getCantidadDeTesorosEnTablero()+1 << " tesoro:" << std::endl;
	Casillero* casillero = this->ingresoCoordenadaDeCasillero();
	if(this->casilleroVacio(casillero)) {
		casillero->colocarFicha(new Ficha(TESORO), jugador->getNumeroJugador());
		jugador->setCantidadDeTesorosEnTablero(jugador->getCantidadDeTesorosEnTablero() + 1);
		this->pintarTesoro(casillero, jugador);
	}
	else {
		if(this->tesoroDeOtroJugador(casillero, jugador)) {
			std::cout << "Se encuentra un tesoro del jugador "
					<< casillero->getNumeroDePropietario() << "." << std::endl;
		}
		else {
			std::cout << "Se encuentra un tesoro suyo en este casillero." << std::endl;
		}
		this->colocarTesoros(jugador);
	}
}

void TesoroBinario::colocarEspias(Jugador* jugador) {
	jugador->aPisadoMina(false);
	std::cout << "JUGADOR " << jugador->getNumeroJugador() << ": ";
	std::cout << "Ingrese la coordenada donde quiere poner su espia: " << std::endl;
	Casillero* casillero = this->ingresoCoordenadaDeCasillero();
	Jugador* jugadorDelCasillero = this->jugadorDelCasillero(casillero);

	if(this->casilleroVacio(casillero)) {
		casillero->colocarFicha(new Ficha(ESPIA), jugador->getNumeroJugador());
		this->pintarEspia(casillero, jugador);
	}
	else if(this->casilleroInactivo(casillero)) {
		std::cout << "Este casillero está inactivo." << std::endl;
		this->colocarEspias(jugador);
	}
	else {
		if(this->tesoroDeOtroJugador(casillero, jugador)) {
			if(this->tesoroBlindado(casillero)) {
				std::cout << "Se encuentra un tesoro blindado." << std::endl;
				if(this->buscarCartaRomperBlindaje(jugador)) {
					char respuesta;
					do {
						std::cout << "Cuenta con una carta ROMPER BLINDAJE, desea jugarla (S/N): ";
						std::cin >> respuesta;
					} while(respuesta != AFIRMATIVA && respuesta != NEGATIVA);
					if(respuesta == AFIRMATIVA) {
						this->funcionalidadCartas->romperBlindaje(jugador, this->jugadores, casillero);
						this->pintarEspia(casillero, jugador);
					}
					else {
						return;
					}
				}
				else {
					std::cout << "No cuenta con una carta ROMPER BLINDAJE." << std::endl;
				}
			}
			else {
				std::cout << "Tesoro encontrado." << std::endl;
				this->eliminarTesoro(casillero);
				this->pintarCasilleroVacio(casillero, jugadorDelCasillero);
				casillero->cambiarFicha(ESPIA, jugador->getNumeroJugador());
				this->inactivarCasillero(casillero, this->getNumeroDeTurno());
				this->pintarEspia(casillero, jugador);
			}
		}
		else if(this->espiaDeOtroJugador(casillero, jugador)) {
			std::cout << "Se encuentra un espia enemigo, ambos espias mueren." << std::endl;
			casillero->quitarFicha();
			this->pintarCasilleroVacio(casillero, jugadorDelCasillero);
			return;
		}
		else if(this->minaDeOtroJugador(casillero, jugador)) {
			std::cout << "¡¡¡¡BOOOOOOOOOOOM!!!!, su espia pisó una mina, espia eliminado. "
					"Pierde el resto del turno." << std::endl;
			this->tableroBMP->pintarCasilleroVacio(casillero->getZ(), casillero->getX(), casillero->getY(),
					*(jugador->getTableroBMP()), jugador->getNombreTablero());
			casillero->quitarFicha();
			jugador->aPisadoMina(true);
			this->pintarCasilleroVacio(casillero, jugadorDelCasillero);
		}
		else {
			std::cout << "Coordenada de espia mal ingresada." << std::endl;
			this->colocarEspias(jugador);
		}
	}
}

void TesoroBinario::moverTesoros(Jugador* jugador) {
	if(this->saltarTurno(jugador)) {
		return;
	}
	char respuesta;
	std::cout << "JUGADOR " << jugador->getNumeroJugador() << ": ";
	std::cout << "Desea mover un tesoro, "
			"tenga en cuenta que perderá el blindaje en caso de que esté blindado (S/N): ";
	std::cin >> respuesta;

	if(respuesta != AFIRMATIVA && respuesta != NEGATIVA) {
		std::cout << "Respuesta no válida." << std::endl;
		this->moverTesoros(jugador);
	}
	else {
		if(respuesta == AFIRMATIVA) {
			Casillero* casilleroConTesoroAMover;
			Casillero* nuevoCasilleroConTesoro;
			do {
				std::cout << "Ingrese el casillero con el tesoro que desea mover: " << std::endl;
				casilleroConTesoroAMover = this->ingresoCoordenadaDeCasillero();
				if(!this->tesoroPropio(casilleroConTesoroAMover, jugador) ||
					this->casilleroInactivo(casilleroConTesoroAMover)) {
					std::cout << "El casillero ingresado no tiene un tesoro suyo o "
							"el casillero esta inactivo" << std::endl;
				}
			} while(!this->tesoroPropio(casilleroConTesoroAMover, jugador) ||
					this->casilleroInactivo(casilleroConTesoroAMover));
			char direccionDeMovimiento;
			std::cout << "Direcciones de movimiento: "
					"w: ARRIBA - s:ABAJO - a:IZQUIERDA - d:DERECHA - q:ADELANTE - e: ATRAS. " << std::endl;

			direccionDeMovimiento = this->ingresoDeDireccionDeMoviento(casilleroConTesoroAMover);
			nuevoCasilleroConTesoro = this->calculoNuevoCasilleroConTesoro(direccionDeMovimiento,
					casilleroConTesoroAMover);

			if(this->casilleroVacio(nuevoCasilleroConTesoro)) {
				casilleroConTesoroAMover->quitarFicha();
				nuevoCasilleroConTesoro->colocarFicha(new Ficha(TESORO), jugador->getNumeroJugador());
				this->pintarCasilleroVacio(casilleroConTesoroAMover, jugador);
				this->pintarTesoro(nuevoCasilleroConTesoro, jugador);
			}
			else if(this->casilleroInactivo(nuevoCasilleroConTesoro)) {
				std::cout << "El casillero donde desea moverse está inactivo, "
						"no se pudo mover su tesoro." << std::endl;
			}
			else {
				if(this->tesoroDeOtroJugador(nuevoCasilleroConTesoro, jugador)) {
					std::cout << "El casillero donde desea moverse se encuentra un tesoro del jugador "
							<< nuevoCasilleroConTesoro->getNumeroDePropietario() << "." << std::endl;
				}
				else {
					std::cout << "El casillero donde desea moverse se encuentra lleno." << std::endl;
				}
			}
		}
		else {
			return;
		}
	}
}

void TesoroBinario::colocarMinas(Jugador* jugador) {
	if(this->saltarTurno(jugador)) {
		return;
	}
	if(this->limiteAlcanzadoDeMinasEnTablero(jugador)) {
		std::cout << "JUGADOR " << jugador->getNumeroJugador() << ": ";
		std::cout << "A alcanzado el límite de minas que puede colocar." << std::endl;
		return;
	}
	else {
		char respuesta;
		std::cout << "JUGADOR " << jugador->getNumeroJugador() << ": ";
		std::cout << "Desea colocar una mina (S/N): ";
		std::cin >> respuesta;
		if(respuesta != AFIRMATIVA && respuesta != NEGATIVA) {
			std::cout << "Respuesta no válida." << std::endl;
			this->colocarMinas(jugador);
		}
		else {
			if(respuesta == AFIRMATIVA) {
				std::cout << "Ingrese la coordenada donde desea colocar su mina: " << std::endl;
				Casillero* casillero = this->ingresoCoordenadaDeCasillero();
				Jugador* jugadorDelCasillero = this->jugadorDelCasillero(casillero);

				if(this->casilleroVacio(casillero)) {
					casillero->colocarFicha(new Ficha(MINA), jugador->getNumeroJugador());
					jugador->setCantidadDeMinasEnTablero(jugador->getCantidadDeMinasEnTablero() + 1);
					this->pintarMina(casillero, jugador);
				}
				else if(this->casilleroInactivo(casillero)) {
					std::cout << "Este casillero está inactivo, no se pudo colocar la mina." << std::endl;
					return;
				}
				else {
					if(this->tesoroDeOtroJugador(casillero, jugador)) {
						if(this->tesoroBlindado(casillero)) {
							std::cout << "El tesoro esta blindado, se rompió el blindaje "
									"mas no se pudo recuperar." << std::endl;
							this->romperBlindaje(casillero);
						}
						else {
							std::cout << "¡¡¡¡BOOOOOOOOOOOM!!!!, se encontró un tesoro." << std::endl;
							this->eliminarTesoro(casillero);
							this->inactivarCasillero(casillero, this->getNumeroDeTurno());
							jugador->setCantidadDeMinasEnTablero(jugador->getCantidadDeMinasEnTablero() + 1);
							this->pintarCasilleroVacio(casillero, jugadorDelCasillero);
						}
					}
					else {
						std::cout << "El casillero que ingreso ya está lleno" << std::endl;
						this->colocarMinas(jugador);
					}
				}
			}
			else {
				return;
			}
		}
	}
}

void TesoroBinario::jugarCarta(Jugador* jugador) {
	if(this->saltarTurno(jugador)) {
		return;
	}
	if(jugador->getManoDeCartas()->estaVacia()) {
		std::cout << "No cuenta con cartas para jugar." << std::endl;
		return;
	}
	char respuesta;
	std::cout << "JUGADOR " << jugador->getNumeroJugador() << ": ";
	this->mostrarManoDeCartas(jugador);
	std::cout << "Desea jugar una carta (S/N): ";
	std::cin >> respuesta;

	if(respuesta != AFIRMATIVA && respuesta != NEGATIVA) {
		std::cout << "Respuesta no válida." << std::endl;
		this->jugarCarta(jugador);
	}
	else {
		if(respuesta == AFIRMATIVA) {
			jugador->aJugadoCarta(true);
			unsigned int numeroDeCartaAJugar;
			do {
				std::cout << "Ingrese el número de carta que desea jugar: ";
				std::cin >> numeroDeCartaAJugar;
			}
			while(numeroDeCartaAJugar < 1 ||
					numeroDeCartaAJugar > jugador->getManoDeCartas()->contarElementos());

			switch(jugador->getManoDeCartas()->obtenerElemento(numeroDeCartaAJugar)->getTipoDeCarta()) {
			case BLINDAR:
				this->funcionalidadCartas->blindar(jugador);
				break;
			case RADAR:
				this->funcionalidadCartas->radar(jugador);
				break;
			case PARTIR_TESORO:
				this->funcionalidadCartas->partirTesoro(jugador, this->tableroBMP);
				break;
			case AGREGAR_MINA:
				this->funcionalidadCartas->agregarMina(jugador);
				break;
			case ROMPER_BLINDAJE:
				jugador->aJugadoCarta(false);
				std::cout << "Esta carta solo se puede jugar al momento "
						"que un espia encontró un tesoro blindado." << std::endl;
				return;
				break;
			case ELIMINAR_CARTA:
				this->funcionalidadCartas->eliminarCarta(jugador, this->getJugadores());
				break;
			}
			jugador->eliminarCartaDeLaMano(numeroDeCartaAJugar);
		}
		else {
			jugador->aJugadoCarta(false);
		}
	}
}

void TesoroBinario::agregarCarta(Jugador* jugador) {
	if(jugador->getEstadoJugadoCarta()) {
		int numeroRandom;
		std::srand(static_cast<unsigned int>(std::time(0)));
		numeroRandom = (std::rand() % CANTIDAD_DE_CARTAS) + 1;
		switch(numeroRandom) {
		case 1:
			jugador->getManoDeCartas()->agregarElemento(new Carta(BLINDAR));
			break;
		case 2:
			jugador->getManoDeCartas()->agregarElemento(new Carta(RADAR));
			break;
		case 3:
			jugador->getManoDeCartas()->agregarElemento(new Carta(PARTIR_TESORO));
			break;
		case 4:
			jugador->getManoDeCartas()->agregarElemento(new Carta(AGREGAR_MINA));
			break;
		case 5:
			jugador->getManoDeCartas()->agregarElemento(new Carta(ROMPER_BLINDAJE));
			break;
		case 6:
			jugador->getManoDeCartas()->agregarElemento(new Carta(ELIMINAR_CARTA));
			break;
		}
	}
	else {
		return;
	}
}

Jugador* TesoroBinario::verificarEliminacionJugador(Jugador* jugador) {
	unsigned int i = 1;
	unsigned int numeroJugadorAEliminar = jugador->getNumeroJugador();
	if(jugador->getCantidadDeTesorosEnTablero() == 0) {
		std::cout << "JUGADOR " << numeroJugadorAEliminar << " ELIMINADO" << std::endl;
		while(this->getJugador(i)->getNumeroJugador() != numeroJugadorAEliminar) {
			i++;
		}
		delete jugador;
		jugador = NULL;
		this->getJugadores()->removerElemento(i);
	}
	return jugador;
}

void TesoroBinario::pintarTesoro(Casillero* casillero, Jugador* jugador) {
	this->tableroBMP->pintarTesoro(casillero->getZ(), casillero->getX(), casillero->getY(),
					*(jugador->getTableroBMP()), jugador->getNombreTablero());
}

void TesoroBinario::pintarCasilleroVacio(Casillero* casillero, Jugador* jugador) {
	this->tableroBMP->pintarCasilleroVacio(casillero->getZ(), casillero->getX(), casillero->getY(),
			*(jugador->getTableroBMP()), jugador->getNombreTablero());
}

void TesoroBinario::pintarEspia(Casillero* casillero, Jugador* jugador) {
	this->tableroBMP->pintarEspia(casillero->getZ(), casillero->getX(), casillero->getY(),
			*(jugador->getTableroBMP()), jugador->getNombreTablero());
}

void TesoroBinario::pintarMina(Casillero* casillero, Jugador* jugador) {
	this->tableroBMP->pintarMina(casillero->getZ(), casillero->getX(), casillero->getY(),
			*(jugador->getTableroBMP()), jugador->getNombreTablero());
}

void TesoroBinario::jugar() {
	this->crearTableroBMPDeLosJugadores();
	std::cout << "------------------------------------" << std::endl;
	this->mostrarConfiguracionesDelJuego();
	std::cout << "------------------------------------" << std::endl;

	for(unsigned int i = 1; i <= this->cantidadDeTesorosPermitidos; i++) {
		this->getJugadores()->iniciarCursor();
		while(this->getJugadores()->avanzarCursor()) {
			Jugador* jugadorActual = this->getJugadores()->obtenerCursor();
			this->colocarTesoros(jugadorActual);
		}
	}
	std::cout << "Fase de ingreso de tesoros terminada." << std::endl;
	std::cout << "------------------------------------" << std::endl;

	while(this->getJugadores()->contarElementos() > 1) {
		this->getJugadores()->iniciarCursor();
		while(this->getJugadores()->avanzarCursor() && this->getJugadores()->contarElementos() > 1) {
			Jugador* jugadorActual = this->getJugadores()->obtenerCursor();
			std::cout << "JUGADOR ACTUAL: " << jugadorActual->getNumeroJugador() << std::endl;
			jugadorActual = this->verificarEliminacionJugador(jugadorActual);
			if(jugadorActual != NULL) {
				this->actualizarNumeroDeTurno(this->getNumeroDeTurno() + 1);
				std::cout << "TURNO: " << this->getNumeroDeTurno() << std::endl;
				this->activarCasillero();
				this->colocarEspias(jugadorActual);
				this->moverTesoros(jugadorActual);
				this->colocarMinas(jugadorActual);
				this->jugarCarta(jugadorActual);
				this->agregarCarta(jugadorActual);
				std::cout << "------------------------------------" << std::endl;
			}

		}
	}
	std::cout << "------------------------------------" << std::endl;
	std::cout << "JUGADOR " << this->getJugador(1)->getNumeroJugador() << " GANADOR" << std::endl;
	std::cout << "JUEGO TERMINADO" << std::endl;
}


