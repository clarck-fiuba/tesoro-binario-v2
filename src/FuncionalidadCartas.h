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
	 * post: valida que el tablero no sea nulo.
	 */
	void validarTablero(Tablero*& tablero);

	/*
	 * pre:
	 * post: valida que el jugador no sea nulo.
	 */
	void validarJugador(Jugador*& jugador);

	/*
	 * pre:
	 * post: develve verdadero si en el casillero hay un tesoro propio.
	 */
	bool tesoroPropio(Casillero*& casillero, Jugador*& jugador);

	/*
	 * pre:
	 * post: develve verdadero si en el casillero hay un tesoro enemigo.
	 */
	bool tesoroDeOtroJugador(Casillero*& casillero, Jugador*& jugador);

	/*
	 * pre:
	 * post: devuelve true o false dependiendo si el casillero esta vacio.
	 */
	bool casilleroVacio(Casillero*& casillero);

public:
	/*
	 * pre: el tablero del jugador no puede nulo.
	 * post: asigna el tablero del juego.
	 */
	FuncionalidadCartas(Tablero*& tableroDelJuego);

	/*
	 * pre:
	 * post:
	 */
	virtual ~FuncionalidadCartas();

	/*
	 * pre:
	 * post: devulve las coordenadas asingadas en una posicion del tablero.
	 */
	Casillero* ingresoCoordenadaDeCasillero();

	/*
	 * pre:
	 * post: elimina el tesoro de un jugador.
	 */
	void eliminarTesoro(Casillero*& casillero, Lista<Jugador* >*& jugadores);

	/*
	 * pre:
	 * post: devuelve la posicon de la carta romper blindaje.
	 */
	unsigned int posicionCartaRomperBlindaje(Jugador*& jugador);

	/*
	 * pre:
	 * post: pinta el tesoro en la poscion deseada.
	 */
	void pintarTesoro(TableroBMP*& tableroBMP, Casillero* casillero, Jugador* jugador);

	/*
	 * pre:.
	 * post: retorna el jugador a elimnar la carta.
	 */
	Jugador* jugadorAEliminarCarta(Jugador* jugadorDeLaCarta, Lista<Jugador* >* jugadores);

	/*
	 * pre: el jugador debe exitir.
	 * post: cambia el estado del casillero a blindado.
	 */
	void blindar(Jugador*& jugador);

	/*
	 * pre:	el jugador debe exitir.
	 * post: contabiliza la cantidad de tesoros vecinos detectados.
	 */
	void radar(Jugador*& jugador);

	/*
	 * pre: el jugador debe exitir.
	 * post: coloca un tesoro en uno de los casilleros vecinos a un tesoro propio.
	 */
	void partirTesoro(Jugador*& jugador, TableroBMP*& tableroBMP);

	/*
	 * pre: el jugador debe exitir.
	 * post: agrega una mina al las cantidad de minas permitidas al jugador.
	 */
	void agregarMina(Jugador*& jugador);

	/*
	 * pre: el jugador debe exitir.
	 * post: rompe el blindaje de un tesoro enemigo.
	 */
	void romperBlindaje(Jugador*& jugador, Lista<Jugador* >*& jugadores, Casillero*& casillero);

	/*
	 * pre:  el jugador debe exitir.
	 * post: elimina la carta del jugador deseado.
	 */
	void eliminarCarta(Jugador* jugador, Lista<Jugador* >* jugadores);

};

#endif /* FUNCIONALIDADCARTAS_H_ */
