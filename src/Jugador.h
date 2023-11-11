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
#include "BMPTablero.h"
#include "Constantes.h"

class Jugador {
private:
	bool jugadorVivo;
	unsigned int numeroJugador;
	unsigned int cantidadDeTesoros;
	unsigned int cantidadDeMinasPuestas;
	unsigned int cantidadDeMinasPermitidas;
	unsigned int numeroTurno;
	int numeroRandom;
	bool minaEncontrada;
	Lista<Carta *> *manoDeCartas;
	Lista<Casillero* > *casillerosDeTesoroEncontrado;
	Lista<unsigned int> *turnoRecuperarTesoro;
	unsigned int casillerosDesactivados;
	unsigned int casillerosActivados;
	BMPTablero *tableroJugador;
	BMP *tablero;
	BMP *tesoro;
	BMP *espia;
	BMP *mina;
	std::string nombreTablero;

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

	/*pre:
	 * post: devuelve la cantidad de casilleros desactivados.
	 */
	unsigned int getCasillerosDesactivados();

	/*pre:
	 * post: asigna una cantidad de casilleros desactivados.
	 */
	void setCasillerosDesactivados(unsigned int casillerosDesactivados);

	/*pre:
	 * post: devuelve la canitdad de casilleros activados
	 */
	unsigned int getCasillerosActivados();

	/*pre:
	 * post: asigna la cantidad de casilleros activados por jugador
	 */
	void setCasilleroActivados(unsigned int casillerosActivados);

	/*pre:
	 * post: devuelve el turno en que se va a recuperar el tesoro
	 */
	unsigned int getTurnoRecuperarTesoro(int posicion);

	/*pre:
	 * post: asgina el turno en el cual va a recuperar un tesoro
	 */
	void setTurnoRecuperarTesoro(unsigned int turno);


	/*pre:
	 * post:devuelve la lista con los casilleros desactivados.
	 */
	Lista<Casillero* > *getListaCasillerosDesactivados();

	/*pre:
	 * post: devuelve el casillero que encontro el tesoro.
	 */
	Casillero* getCasillerosConTesorosEncontrados(int posicion);

	/*pre:
	 * post: asigna el casillero con el tesoro encontrado
	 */
	void setCasillerosConTesorosEncontrados(Casillero* casillero);

	/*pre:
	 * post: devuelve la cantidad de minas permitidas por jugador
	 */
	unsigned int getCantidadDeMinasPermitidas();

	/*pre:
	 * post: aumenta la cantidad de minas permitidas por jugador.
	 */
	void setCantidadDeMinasPermitidas(unsigned int cantidad);

	/*pre:
	 * post: devuelve la cantidad de minas colocadas
	 */
	unsigned int getCantidadDeMinasPuestas();

	/*pre:
	 * post: asigna la canitdad de minas puestas.
	 */
	void setCantidadDeMinasPuestas(unsigned int cantidad);

	/*pre:
	 * post: devuelve true o false dependiendo si encontro o no una mina.
	 */
	bool getMinaEncontrada();

	/*pre:
	 * post: asigna true o false dependiendo si encontro o no una mina.
	 */
	void setMinaEncontrada(bool minaEncontrada);

	/*pre:
	 * post:
	 */
	void crearTableroJugador(int profundidad, int filas, int columnas);

	/*pre:
	 * post:
	 */
	void pintarTesoro(int z, int x, int y);

	/*pre:
	 * post:
	 */
	void pintarEspia(int z, int x, int y);

	/*pre:
	 * post:
	 */
	void pintarMina(int z, int x, int y);

	/*pre:
	 * post: devuelve el estado del jugador.
	 */
	bool getEstadoJugador();

	/*pre:
	 * post: cambia el estado del jugador a elimnado
	 */
	void jugadorEliminado();
};

#endif /* JUGADOR_H_ */
