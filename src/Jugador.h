/*
 * Jugador.h
 *
 *  Created on: 20 oct. 2023
 *      Author: gonzalo
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include <iostream>
#include <random>
#include "Lista.h"
#include "Carta.h"

class Jugador {
private:
	unsigned int numeroJugador;
	unsigned int cantidadDeTesoros;
	unsigned int numeroTurno;
	int numeroRandom;
	Lista<Carta *> *manoDeCartas;

public:
	/*
	 * pre:
	 * post:
	 */
	Jugador(unsigned int numeroJugador);

	/*
	 * pre:
	 * post:
	 */
	virtual ~Jugador();

	/*
	 * pre:
	 * post:
	 */
	unsigned int getNumeroJugador();

	/*
	 * pre:
	 * post:
	 */
	unsigned int getCantidadDeTesoros();

	/*
	 * pre:
	 * post:
	 */
	unsigned int getNumeroTurno();

	/*
	 * pre:
	 * post:
	 */
	Lista<Carta *> *getMasoCarta();

	/*
	 * pre:
	 * post:
	 */
	void setCantidadDeTesoros(unsigned int cantidadDeTesoros);

	/*
	 * pre:
	 * post:
	 */
	void setNumeroDeTurno(unsigned int turno);
};

#endif /* JUGADOR_H_ */
