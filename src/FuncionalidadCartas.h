/*
 * FuncionalidadCartas.h
 *
 *  Created on: 13 nov. 2023
 *      Author: gonzalo
 */

#ifndef FUNCIONALIDADCARTAS_H_
#define FUNCIONALIDADCARTAS_H_
#include <cstdlib>
#include <ctime>
#include "TableroBMP.h"
#include "Tablero.h"
#include "Jugador.h"



class FuncionalidadCartas {
private:
	Tablero* tableroDelJuego;

	/*
	 * pre: -
	 * post: Valida que el tablero esté inicializado.
	 */
	void validarTablero(Tablero*& tablero);

	/*
	 * pre: -
	 * post: Valida que el jugador esté inicializado.
	 */
	void validarJugador(Jugador*& jugador);

	/*
	 * pre: -
	 * post: Retorna verdadero si el casillero tiene como ficha un TESORO del jugador.
	 */
	bool tesoroPropio(Casillero*& casillero, Jugador*& jugador);

	/*
	 * pre: -
	 * post: Retorna verdadero si el casillero tiene como ficha un TESORO de otro jugador.
	 */
	bool tesoroDeOtroJugador(Casillero*& casillero, Jugador*& jugador);

	/*
	 * pre: -
	 * post: Retorna verdadero si el casillero está en estado VACIO.
	 */
	bool casilleroVacio(Casillero*& casillero);

public:
	/*
	 * pre: El tablero del jugador debe estar inicializado.
	 * post: Crea funcionalidad cartas asignando el tablero al pasado por parámetro.
	 */
	FuncionalidadCartas(Tablero*& tableroDelJuego);

	/*
	 * pre: -
	 * post: Elimina de forma correcta a funcionalidad cartas.
	 */
	virtual ~FuncionalidadCartas();

	/*
	 * pre: -
	 * post: Retorna un casillero con las coordenadas que el usuario ingresó.
	 */
	Casillero* ingresoCoordenadaDeCasillero();

	/*
	 * pre: -
	 * post: Busca al jugador propietario del casillero y le elimina un tesoro.
	 */
	void eliminarTesoro(Casillero*& casillero, Lista<Jugador* >*& jugadores);

	/*
	 * pre: -
	 * post: Retorna la posicion de la carta ROMPER_BLINDAJE de la mano de cartas del jugador.
	 */
	unsigned int posicionCartaRomperBlindaje(Jugador*& jugador);

	/*
	 * pre: -
	 * post: Pinta un tesoro en las coordenadas del casillero indicado en el tablero del jugador.
	 */
	void pintarTesoro(TableroBMP*& tableroBMP, Casillero* casillero, Jugador* jugador);

	/*
	 * pre: -
	 * post: Retorna el jugador que el usuario ingresó del cual se eliminará una de sus cartas.
	 */
	Jugador* jugadorAEliminarCarta(Jugador* jugadorDeLaCarta, Lista<Jugador* >* jugadores);

	/*
	 * pre: El jugador debe estar inicializado.
	 * post: Cambia el estado del casillero a BLINDADO.
	 */
	void blindar(Jugador*& jugador);

	/*
	 * pre: El jugador debe estar inicializado.
	 * post: Contabiliza la cantidad de tesoros vecinos hay alrededor de cierto casillero
	 * 		 que el usuario ingresa.
	 */
	void radar(Jugador*& jugador);

	/*
	 * pre: El jugador debe estar inicializado.
	 * post: Coloca un tesoro en un casillero vecino de un tesoro que el jugador elija.
	 */
	void partirTesoro(Jugador*& jugador, TableroBMP*& tableroBMP);

	/*
	 * pre: El jugador debe estar inicializado.
	 * post: Suma una mina a la cantidad de minas permitidas que puede colocar el jugador.
	 */
	void agregarMina(Jugador*& jugador);

	/*
	 * pre: El jugador debe estar inicializado.
	 * post: Rompe el blindaje a un casillero blindado, recuperando el tesoro instantáneamente y
	 * 		 dejando a un espia del jugador en el casillero.
	 */
	void romperBlindaje(Jugador*& jugador, Lista<Jugador* >*& jugadores, Casillero*& casillero);

	/*
	 * pre: El jugador debe estar inicializado.
	 * post: Elimina una carta aleatoria del jugador indicado.
	 */
	void eliminarCarta(Jugador* jugador, Lista<Jugador* >* jugadores);

};

#endif /* FUNCIONALIDADCARTAS_H_ */
