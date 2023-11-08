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
#include "Constantes.h"

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


	/*
	 * pre: -
	 * post: devuelve una excepción si se ingresa numeroJugadores invalido.
	 */
	void validarCantidadDeJugadores(unsigned int numeroJugadores){

		if (numeroJugadores < 0){
			throw "numero invalido";
		}

	}


	/*
	 * pre: -
	 * post: devuelve una excepción si la posicion es invalido.
	 */
	void validarPosicion(unsigned int posicion){
		if (posicion < 0){
			throw "numero invalido";
		}else
			if (posicion > this->jugadores->contarElementos()){
				throw "no puede superar la cantidad de jugadores";
			}

	}
	/*
	 * pre: -
	 * post: devuelve una excepción si las coordenadas son invalidas es invalido.
	 */
	void validarCoordenada(unsigned int &z, unsigned int &x, unsigned int &y){

		std::cout << "Z: ";
		std::cin >> z;
		if(z < 1 || z > this->numeroJugadores / 2) {
			throw std::runtime_error("La coordenada z esta mal ingresada");
		}
		std::cout << "X: ";
		std::cin >> x;
		if(x < 1 || x > this->numeroJugadores* ANCHO) {
			throw std::runtime_error("La coordenada x esta mal ingresada");
		}

		std::cout << "Y: ";
		std::cin >> y;
		if(y < 1 || y > this->numeroJugadores* ALTO) {
			throw std::runtime_error("La coordenada y esta mal ingresada");
		}
	}



public:

	/*
	 * pre: numeroJugadores debe ser valido.
	 * post: inicia el juego, dependiendo la cantidad de jugadore creara el tablero.
	 */
	TesoroBinario(unsigned int numeroJugadores);

	/*
	 * pre:-
	 * post: elimina jugadores, tablero, funcionalidadCartas;
	 */
	virtual ~TesoroBinario();

	/*
	 * pre: -
	 * post: devuelve todo el tablero.
	 */
	Tablero *getTablero();

	/*
	 * pre:
	 * post:
	 */
	void configurarCantidadDeTesoros(unsigned int cantidadDeTesoros);

	/*
	 * pre: la posicion debe ser valida.
	 * post: devuelve un jugador.
	 */
	Jugador *getJugador(unsigned int posicion);


	/*
	 * pre:-
	 * post:devuelve toda la lista de los jugadores.
	 */
	Lista<Jugador* > *getJugadores();

	/*
	 * pre: las coordenadas deben ser validas.
	 * post: devuelve el tablero con las coordenadas ingresadas.
	 */
	Casillero* ingresoDeCoordenadas();


	/*
	 * pre:-
	 * post: devuelve la cantidad de turnos.
	 */
	unsigned int getTurnos();


	/*
	 * pre:
	 * post: asigna un turno a la variable turnos.
	 */
	void setTurno(unsigned int turno);

	/*
	 * pre:
	 * post:coloca un tesoro en las coordenadas indicadas.
	 */
//	void colocarTesoros(unsigned int z, unsigned int x, unsigned int y, Jugador *jugador);


	/*
	 * pre:
	 * post: coloca un tesoro.
	 */
	void colocarTesoros(Jugador* jugador);


	/* NO SE PARA QUE SE USA
	 * pre:
	 * post:
	 */
	void activarCasillero(Jugador* jugador);

	/*
	 * pre:
	 * post: coloca un espia en la casilla que esta en el tablero.
	 */
	void colocarEspias(Jugador* jugador);

	/*
	 * pre:
	 * post: coloca el tesoro mina en la casilla que esta en el tablero.
	 */
	void colocarTesoroMina(Jugador* jugador);

	/*
	 * pre:
	 * post: muetra el maso de cartas.
	 */
	void mostrarMasoCarta(Jugador* jugador);

	/*
	 * pre:
	 * post: juega una carta a la vez de las 6 dadas.
	 */
	void JugarCarta(Jugador *jugador);

	/*
	 * pre:
	 * post: elimina el jugador que se quedo sin tesoros.
	 */
	void eliminarJugador(unsigned int posicion);

	/*
	 * pre:
	 * post: elimina el tesoro del casillero.
	 */
	void void eliminarTesoro(Jugador * jugador, Casillero *casillero, Lista<Jugador *> *jugadores);
};

#endif /* TESOROBINARIO_H_ */
