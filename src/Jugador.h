/*
 * Jugador.h
 *
 *  Created on: 20 oct. 2023
 *      Author: gonzalo
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include <iostream>
//#include <random>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "EasyBMP.h"
#include "Constantes.h"
#include "Lista.h"
#include "Carta.h"
#include "Casillero.h"
#include "Ficha.h"

class Jugador {
private:
	unsigned int numeroDeJugador;
	unsigned int cantidadDeTesorosEnTablero;
	unsigned int cantidadDeMinasPermitidas;
	unsigned int cantidadDeMinasEnTablero;
	bool pisadoMinaDeOtroJugador;
	bool jugadoCarta;
	Lista<Carta *> *manoDeCartas;
	BMP* tableroBMP;
	std::string nombreTablero;

	/*
	 * pre: -
	 * post: Valida que el numero de jugador sea mayor a 0.
	 */
	void validarNumeroDeJugador(unsigned int numeroJugador);

	/*
	 * pre: -
	 * post: Valida que la cantidad de tesoros sea mayor o igual a 0.
	 */
	void validarCantidadDeTesoros(unsigned int cantidadDeTesoros);

	/*
	 * pre: -
	 * post: Valida que la cantidad de minas permitidas sea mayor o igual a 0.
	 */
	void validarCantidadDeMinasPermitidas(unsigned int cantidadDeMinas);

	/*
	 * pre: -
	 * post: Valida que la cantidad de minas en el tablero sea mayor o igual a 0 y
	 * 		 menor o igual a la cantidad de minas permitidas.
	 */
	void validarCantidadDeMinasEnTablero(unsigned int cantidadDeMinas);

public:
	/*
	 * pre: El numeroDeJugador debe ser mayor a 0.
	 * post: Crea un Jugador con su numero de jugador, la cantidad de tesoros en el tablero en 0 y
	 * 		 una mano de 3 cartas aleatorias.
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
	 * post: Devuelve la cantidad de tesoros que el jugador tiene en el tablero.
	 */
	unsigned int getCantidadDeTesorosEnTablero();

	/*
	 * pre: -
	 * post: Devuelve la cantidad de minas permitidas por jugador.
	 */
	unsigned int getCantidadDeMinasPermitidas();

	/*
	 * pre: -
	 * post: Devuelve la cantidad de minas que el jugador tiene en el tablero.
	 */
	unsigned int getCantidadDeMinasEnTablero();

	/*
	 * pre: -
	 * post: Devuelve verdadero o falso según valga la variable "pisadoMinaDeOtroJugador".
	 */
	bool getEstadoPisadoMinaDeOtroJugador();

	/*
	 * pre:
	 * post: Devuelve verdadero o false según valga la variable "jugadoCarta".
	 */
	bool getEstadoJugadoCarta();

	/*
	 * pre: -
	 * post: Devuelve la lista mano de cartas del jugador.
	 */
	Lista<Carta *> *getManoDeCartas();

	/*
	 * pre:
	 * post:
	 */
	BMP* getTableroBMP();

	/*
	 * pre:
	 * post:
	 */
	std::string getNombreTablero();

	/*
	 * pre: La cantidad de tesoros debe ser mayor o igual a 0.
	 * post: Actualiza la cantidad de tesoros en el tablero.
	 */
	void setCantidadDeTesorosEnTablero(unsigned int cantidadDeTesoros);

	/*
	 * pre: La cantidad de minas permitidas debe ser mayor o igual a 0.
	 * post: Actualiza la cantidad de minas permitidas por cada jugador.
	 */
	void setCantidadDeMinasPermitidas(unsigned int cantidadDeMinas);

	/*
	 * pre: La cantidad de minas debe ser mayor o igual a 0 y
	 * 		menor o igual a la cantidad de minas permitidas.
	 * post: Actualiza la cantidad de minas en el tablero.
	 */
	void setCantidadDeMinasEnTablero(unsigned int cantidadDeMinas);

	/*
	 * pre: -
	 * post: Cambia el estado de la variable "pisadoMinaDeOtroJugador" por el pasado por parámetro.
	 */
	void aPisadoMina(bool pisarMina);

	/*
	 * pre: -
	 * post: Cambia el estado de la variable "jugadoCarta" por el pasado por parámetro.
	 */
	void aJugadoCarta(bool jugarCarta);

	/*
	 * pre: -
	 * post: Llena la lista mano de cartas con 3 nuevas cartas aleatorias.
	 */
	void crearManoDeCartas();

	/*
	 * pre: La posicion debe estar entre 1 y el numero de cartas de mi mano.
	 * post: Elimina la carta en la posicion pasada por parámetro.
	 */
	void eliminarCartaDeLaMano(unsigned int posicion);
};

#endif /* JUGADOR_H_ */
