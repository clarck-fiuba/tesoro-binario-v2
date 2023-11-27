/*
 * FuncionalidadCartas.h
 *
 *  Created on: 13 nov. 2023
 *      Author: gonzalo
 */

#ifndef FUNCIONALIDADCARTAS_H_
#define FUNCIONALIDADCARTAS_H_
#include "TableroBMP.h"
#include "Tablero.h"
#include "Jugador.h"


class FuncionalidadCartas {
private:
	Tablero* tableroDelJuego;

	/*
	 * pre:
	 * post:
	 */
	void validarTablero(Tablero*& tablero);

	/*
	 * pre:
	 * post:
	 */
	void validarJugador(Jugador*& jugador);

	/*
	 * pre:
	 * post:
	 */
	bool tesoroPropio(Casillero*& casillero, Jugador*& jugador);

	/*
	 * pre:
	 * post:
	 */
	bool tesoroDeOtroJugador(Casillero*& casillero, Jugador*& jugador);

	/*
	 * pre:
	 * post:
	 */
	bool casilleroVacio(Casillero*& casillero);

public:
	/*
	 * pre:
	 * post:
	 */
	FuncionalidadCartas(Tablero*& tableroDelJuego);

	/*
	 * pre:
	 * post:
	 */
	virtual ~FuncionalidadCartas();

	/*
	 * pre:
	 * post:
	 */
	Casillero* ingresoCoordenadaDeCasillero();

	/*
	 * pre:
	 * post:
	 */
	void eliminarTesoro(Casillero*& casillero, Lista<Jugador* >*& jugadores);

	/*
	 * pre:
	 * post:
	 */
	unsigned int posicionCartaRomperBlindaje(Jugador*& jugador);

	/*
	 * pre:
	 * post:
	 */
	void pintarTesoro(TableroBMP*& tableroBMP, Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	Jugador* jugadorAEliminarCarta(Jugador* jugadorDeLaCarta, Lista<Jugador* >* jugadores);

	/*
	 * pre:
	 * post:
	 */
	void blindar(Jugador*& jugador);

	/*
	 * pre:
	 * post:
	 */
	void radar(Jugador*& jugador);

	/*
	 * pre:
	 * post:
	 */
	void partirTesoro(Jugador*& jugador, TableroBMP*& tableroBMP);

	/*
	 * pre:
	 * post:
	 */
	void agregarMina(Jugador*& jugador);

	/*
	 * pre:
	 * post:
	 */
	void romperBlindaje(Jugador*& jugador, Lista<Jugador* >*& jugadores, Casillero*& casillero);

	/*
	 * pre:
	 * post:
	 */
	void eliminarCarta(Jugador* jugador, Lista<Jugador* >* jugadores);

};

#endif /* FUNCIONALIDADCARTAS_H_ */
