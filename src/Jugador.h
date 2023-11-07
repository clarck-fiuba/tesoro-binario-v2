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
#include "Casillero.h"
#include "Ficha.h"

class Jugador {
private:
	unsigned int numeroJugador;
	unsigned int cantidadDeTesoros;
	unsigned int cantidadDeMinasPuestas;
	unsigned int cantidadDeMinasPermitidas;
	unsigned int numeroTurno;
	int numeroRandom;
	bool minaEncontrada;
	Lista<Carta *> *manoDeCartas;
	Casillero* casilleros[4];
	//Lista<Casillero* > *casilleros;
	//Lista<unsigned int> *turnoRecuperarTesoro;
	unsigned int turnoRecuperarTesoro[4];
	unsigned int casillerosDesactivados;
	unsigned int casillerosActivados;

	/*
	 * pre: -
	 * post: Valida que el numero de jugador sea mayor a 0.
	 */
	void validarNumeroJugador(unsigned int numeroJugador);

	/*
	 * pre: -
	 * post: Valida que la cantidad de tesoros sea mayor o igual a 0.
	 */
	void validarCantidadDeTesoros(unsigned int cantidadDeTesoros);

	/*
	 * pre: -
	 * post: Valida que el numero de turno sea mayor o igual a 1.
	 */
	void validarNumeroTurno(unsigned int numeroTurno);

public:
	/*
	 * pre: El numeroJugador debe ser mayor a 0.
	 * post: Crea un Jugador con su numero de jugador, la cantidad de tesoros y el
	 * 		 numero de turno en 0 y una mano de 3 cartas aleatorias.
	 */
	Jugador(unsigned int numeroJugador);

	/*
	 * pre: -
	 * post: Elimina al jugador de manera correcta.
	 */
	virtual ~Jugador();

	/*
	 * pre: -
	 * post: Devuelve el numero de jugador.
	 */
	unsigned int getNumeroJugador();

	/*
	 * pre: -
	 * post: Devuelve la cantidad de tesoros de cada jugador que tiene en el tablero.
	 */
	unsigned int getCantidadDeTesoros();

	/*
	 * pre: -
	 * post: Devuelve el numero de turno de cada jugador.
	 */
	unsigned int getNumeroTurno();

	/*
	 * pre: -
	 * post: Devuelve la lista mano de cartas de cada jugador.
	 */
	Lista<Carta *> *getManoCarta();

	/*
	 * pre: La cantidad de tesoros debe ser mayor o igual a 0.
	 * post: Cambia la cantidad de tesoros de cada jugador.
	 */
	void setCantidadDeTesoros(unsigned int cantidadDeTesoros);

	/*
	 * pre: El turno debe ser mayor o igual a 1.
	 * post: Cambia el numero de turno por el pasado por parámetro.
	 */
	void setNumeroDeTurno(unsigned int turno);

	/*
	 * pre: La posicion debe estar entre 1 y el numero de cartas de mi mano.
	 * post: Elimina la carta en la posicion pasada por parámetro.
	 */
	void eliminarCartaDeLaMano(unsigned int posicion);

	unsigned int getCasillerosDesactivados();

	void setCasillerosDesactivados(unsigned int casillerosDesactivados);

	unsigned int getCasillerosActivados();

	void setCasilleroActivados(unsigned int casillerosActivados);

	unsigned int getTurnoRecuperarTesoro(int posicion);

	void setTurnoRecuperarTesoro(int posicion, unsigned int turno);

	Casillero* getCasillero(int posicion);

	void setCasillero(int posicion, Casillero* casillero);

	unsigned int getCantidadDeMinasPermitidas();

	void setCantidadDeMinasPermitidas(unsigned int cantidad);

	unsigned int getCantidadDeMinasPuestas();

	void setCantidadDeMinasPuestas(unsigned int cantidad);

	bool getMinaEncontrada();

	void setMinaEncontrada();

	//Lista<Casillero*> *getCasilleros();

	//void setCasillero(Casillero* casillero);
};

#endif /* JUGADOR_H_ */
