/*
 * FuncionalidadCartas.h
 *
 *  Created on: 26/10/2023
 *      Author: algo2
 */

#ifndef FUNCIONALIDADCARTAS_H_
#define FUNCIONALIDADCARTAS_H_
#include "Tablero.h"
#include "Jugador.h"

class FuncionalidadCartas {
private:
	Tablero* tablero;

	/*
	 * pre: -
	 * post: Valida que el tablero sea distinto de NULL.
	 */
	void validarTablero(Tablero* tablero);

	/*
	 * pre: -
	 * post: Devuelve el casillero con las coordenadas que se ingresaron.
	 */
	Casillero* ingresoDeCoordenadas();

	/*
	 * pre: -
	 * post: Retorna verdadero si el tipo de ficha del casillero es TESORO.
	 */
	bool validarCasilleroTesoro(Casillero* casillero);

	/*
	 * pre: -
	 * post: Retorna verdadero si el propietario del tablero es el numero de jugador pasado por parámetro.
	 */
	bool validarCasilleroPropietario(Casillero* casillero, Jugador* jugador);

	/*
	 * pre: -
	 * post: Valida que el jugador sea distinto de NULL.
	 */
	void validarJugador(Jugador* jugador);

public:

	/*
	 * pre: El tablero debe ser distinto de NULL.
	 * post: Crea la funcionalidadCartas con el tablero pasado por parámetro.
	 */
	FuncionalidadCartas(Tablero* tablero);

	virtual ~FuncionalidadCartas();

	/*
	 * pre: El jugador debe ser distinto de NULL.
	 * post: Cambia el estado del casillero a BLINDADA.
	 */
	void blindarCarta(Jugador* jugador);

	/*
	 * pre: El jugador debe ser distinto de NULL.
	 * post: Verifica si en los casillos vecinos a una casilla hay tesoros de otros jugadores,
	 * 		 informando la cantidad.
	 */
	void radar(Jugador* jugador);

	/*
	 * pre: El jugador debe ser distinto de NULL.
	 * post: Recorre los vecinos de una casilla buscando una libre para
	 * 		 colocar un tesoro.
	 */
	void partirTesoro(Jugador* jugador);

	/*
	 * pre: El jugador debe ser distinto de NULL.
	 * post: Permite que el jugador pueda ingresar un tesoro mina más.
	 */
	void agregarTesoroMina(Jugador* jugador);

	/*
	 * pre: El jugador debe ser distinto de NULL.
	 * post: rompe el blindaje y automaticamente recupera el tesoro.S
	 */
	void romperBlindaje(Jugador* jugador, Lista<Jugador* >* jugadores, Casillero* casillero);

	/*
	 * pre: El jugador debe ser distinto de NULL.
	 * post: elimina una carta al jugador enemigo, dejandolo con una carta mejor que utilizar.
	 */
	void eliminarCartaEnemiga(Jugador* jugador, Lista<Jugador* >* jugadores);
};

#endif /* FUNCIONALIDADCARTAS_H_ */
