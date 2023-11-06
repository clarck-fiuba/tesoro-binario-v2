/*
 * TesoroBinario.h
 *
 *  Created on: 24 oct. 2023
 *      Author: gonzalo
 */

#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_
#include <iostream>
#include "Jugador.h"
#include "Carta.h"
#include "Tablero.h"
#include "FuncionalidadCartas.h"

class TesoroBinario {
private:
	unsigned int numeroJugadores;
	Lista<Jugador *> *jugadores;
	Tablero *tablero;
	FuncionalidadCartas* funcionalidadCartas;
	unsigned int cantidadDeTesoros;
	unsigned int turnos;

	unsigned int profundidadTablero;
	unsigned int anchoTablero;
	unsigned int altoTablero;

public:

	/*
	 * pre:
	 * post:
	 */
	TesoroBinario(unsigned int numeroJugadores);

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
	unsigned int getProfundidad();

	/*
	 * pre:
	 * post:
	 */
	unsigned int getAncho();

	/*
	 * pre:
	 * post:
	 */
	unsigned int getAlto();

	/*
	 * pre:
	 * post:
	 */
	void configurarCantidadDeTesoros(unsigned int cantidadDeTesoros);

	/*
	 * pre:
	 * post:
	 */
	Jugador *getJugador(unsigned int posicion);

	/*
	 * pre:
	 * post:
	 */
	void colocarTesoros(unsigned int z, unsigned int x, unsigned int y, Jugador *jugador);
	void colocarTesoros(Jugador *jugador);

	/*
	 * pre:
	 * post:
	 */
	void colocarEspias(unsigned int z, unsigned int x, unsigned int y, Jugador jugador);

	/*
	 * pre:
	 * post:
	 */
	void colocarTesoroMina(unsigned int z, unsigned int x, unsigned int y, Jugador jugador);

	/*
	 * pre:
	 * post:
	 */
	void mostrarMasoCarta(Jugador* jugador);

	/*
	 * pre:
	 * post:
	 */
	void JugarCarta(Jugador *jugador);
};

#endif /* TESOROBINARIO_H_ */
