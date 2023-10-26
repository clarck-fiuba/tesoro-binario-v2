/*
 * TesoroBinario.h
 *
 *  Created on: 24 oct. 2023
 *      Author: gonzalo
 */

#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_
#include <iostream>
#include "Lista.h"
#include "Jugador.h"
#include "Carta.h"
#include "Tablero.h"

class TesoroBinario {
private:
	unsigned int numeroJugadores;
	Lista<Jugador *> *jugadores;
	Tablero *tablero;
	//Lista<Carta *> *masoDeCartas;
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
	void setProfundidad(unsigned int profundidad);

	/*
	 * pre:
	 * post:
	 */
	void setAncho(unsigned int ancho);

	/*
	 * pre:
	 * post:
	 */
	void setAlto(unsigned int alto);

	/*
	 * pre:
	 * post:
	 */
	Tablero *crearTablero(unsigned int numeroJugadores);

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
	void JugarCarta(Jugador *jugador);
};

#endif /* TESOROBINARIO_H_ */
