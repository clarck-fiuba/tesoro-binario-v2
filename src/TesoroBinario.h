/*
 * TesoroBinario.h
 *
 *  Created on: 24 oct. 2023
 *      Author: gonzalo
 */

#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_
#include <iostream>
#include "Constantes.h"
#include "FuncionalidadCartas.h"
#include "Jugador.h"
#include "Carta.h"
#include "Tablero.h"

class TesoroBinario {
private:
	unsigned int cantidadDeJugadores;
	unsigned int numeroDeTurno;
	unsigned int cantidadDeTesorosPermitidos;
	unsigned int cantidadDeMinasPermitidas;
	Lista<Jugador *> *jugadores;
	Tablero *tablero;
	Lista<Casillero* > *casillerosInactivos;
	Lista<unsigned int> *numeroDeTurnoActivarCasillero;
	TableroBMP* tableroBMP;
	FuncionalidadCartas *funcionalidadCartas;

	/*
	 * pre:
	 * post:
	 */
	void validarCantidadDeJugadores(unsigned int cantidadDeJugadores);

	/*
	 * pre:
	 * post:
	 */
	bool validarDireccionDeMoviento(char direccionDeMovimiento);

	/*
	 * pre:
	 * post:
	 */
	bool validarMovimiento(char direccionDeMovimiento, Casillero* casilleroConTesoroAMover);

	/*
	 * pre:
	 * post:
	 */
	bool tesoroPropio(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	bool tesoroDeOtroJugador(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	bool espiaDeOtroJugador(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	bool minaDeOtroJugador(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	bool casilleroVacio(Casillero* casillero);

	/*
	 * pre:
	 * post:
	 */
	bool casilleroInactivo(Casillero* casillero);

	/*
	 * pre:
	 * post:
	 */
	bool tesoroBlindado(Casillero* casillero);

	/*
	 * pre:
	 * post:
	 */
	bool limiteAlcanzadoDeMinasEnTablero(Jugador* jugador);

public:

	/*
	 * pre:
	 * post:
	 */
	TesoroBinario();

	/*
	 * pre:
	 * post:
	 */
	virtual ~TesoroBinario();

	/*
	 * pre:
	 * post:
	 */
	Tablero *getTablero();

	/*
	 * pre:
	 * post:
	 */
	Jugador *getJugador(unsigned int posicion);

	/*
	 * pre:
	 * post:
	 */
	Lista<Jugador* > *getJugadores();

	/*
	 * pre:
	 * post:
	 */
	unsigned int getNumeroDeTurno();

	/*
	 * pre:
	 * post:
	 */
	void actualizarNumeroDeTurno(unsigned int numeroDeTurno);

	/*
	 * pre:
	 * post:
	 */
	unsigned int configurarCantidadDeJugadores();

	/*
	 * pre:
	 * post:
	 */
	unsigned int configurarCantidadDeTesorosPermitidos(unsigned int cantidadDeJugadores);

	/*
	 * pre:
	 * post:
	 */
	Lista<Jugador* >* configurarJugadores(unsigned int cantidadDeJugadores);

	/*
	 * pre:
	 * post:
	 */
	Tablero* configurarTablero(unsigned int cantidadDeJugadores);

	/*
	 * pre:
	 * post:
	 */
	TableroBMP* configurarTableroBMP(Tablero* tablero);

	/*
	 * pre:
	 * post:
	 */
	void crearTableroBMPDeLosJugadores();

	/*
	 * pre:
	 * post:
	 */
	void mostrarConfiguracionesDelJuego();

	/*
	 * pre:
	 * post:
	 */
	void mostrarManoDeCartas(Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	Casillero* ingresoCoordenadaDeCasillero();

	/*
	 * pre:
	 * post:
	 */
	char ingresoDeDireccionDeMoviento(Casillero *casilleroConTesoroAMover);

	/*
	 * pre:
	 * post:
	 */
	Casillero* calculoNuevoCasilleroConTesoro(char direccionDeMovimiento, Casillero* casilleroConTesoroAMover);

	/*
	 * pre:
	 * post:
	 */
	bool buscarCartaRomperBlindaje(Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	Jugador* jugadorDelCasillero(Casillero* casillero);

	/*
	 * pre:
	 * post:
	 */
	void eliminarTesoro(Casillero* casillero);

	/*
	 * pre:
	 * post:
	 */
	void inactivarCasillero(Casillero* casillero, unsigned int numeroDeTurno);

	/*
	 * pre:
	 * post:
	 */
	void activarCasillero();

	/*
	 * pre:
	 * post:
	 */
	void romperBlindaje(Casillero*& casillero);

	/*
	 * pre:
	 * post:
	 */
	bool saltarTurno(Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	void colocarTesoros(Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	void colocarEspias(Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	void moverTesoros(Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	void colocarMinas(Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	void jugarCarta(Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	void agregarCarta(Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	Jugador* verificarEliminacionJugador(Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	void pintarTesoro(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	void pintarEspia(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	void pintarMina(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	void pintarCasilleroVacio(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	void jugar();
};

#endif /* TESOROBINARIO_H_ */
