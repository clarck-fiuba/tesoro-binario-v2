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
	unsigned int numeroJugadoresVivos;
	Lista<Jugador *> *jugadores;
	Tablero *tablero;
	FuncionalidadCartas* funcionalidadCartas;
	unsigned int cantidadDeTesoros;
	unsigned int turnos;

	unsigned int profundidadTablero;
	unsigned int anchoTablero;
	unsigned int altoTablero;

	char movimiento;

	/*
	 * pre: -
	 * post: devuelve una excepción si se ingresa numeroJugadores invalido.
	 */
	void validarCantidadDeJugadores(unsigned int numeroJugadores);


	/*
	 * pre: -
	 * post: devuelve una excepción si la posicion es invalido.
	 */
	void validarPosicion(unsigned int posicion);

	/*
	 * pre: -
	 * post: devuelve una excepción si las coordenadas son invalidas es invalido.
	 */
	void validarCoordenada(unsigned int &z, unsigned int &x, unsigned int &y);



	void validarPosicionTesoro(Casillero * casilleroViejo);

	void validarMovimiento();



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
	 * pre: no se puede colocar un tesoro encima del propio o del enemigo.
	 * post: coloca un tesoro.
	 */
	void colocarTesoros(Jugador* jugador);


	/*
	 * pre: la posicion del tesoro debe ser valida.
	 * post: mueve el tesoro a la posicion deseada.
	 */
	void moverTesoro(Jugador * jugador);

	/*
	 * pre:
	 * post: valdia el movimiento y llama a colocarTesoroNuevo.
	 */
	void colocarNuevaPosicion(Jugador * jugador, Casillero * casilleroNuevo);

	/*
	 * pre: .
	 * post: devuelve el casillero con las coordenadas donde se colocara el tesoro;
	 */
	Casillero * nuevasCoordenas(unsigned int x, unsigned int y, unsigned int z);

	/*
	 * pre:
	 * post: valida el movimiento del tesoro.
	 */
	void elegirMovimiento();

	/*
	 * pre: .
	 * post: coloca el tesoro en la nueva posicion.
	 */
	void colocarTesoroNuevo(Jugador * jugador, Casillero * casilleroNuevo);


	/*
	 * pre:
	 * post: activa la casilla una vez recuperado el tesoro, o explotando un tesoro mina.
	 */
	void activarCasillero(Jugador* jugador);

	/*
	 * pre:
	 * post: coloca un espia en la casilla del tablero.
	 */
	void colocarEspias(Jugador* jugador);

	/*
	 * pre:
	 * post: coloca el tesoro mina en la casilla que esta en el tablero.
	 */
	void colocarTesoroMina(Jugador* jugador);

	/*
	 * pre:
	 * post: muestra el maso de cartas.
	 */
	void mostrarMasoCarta(Jugador* jugador);

	/*
	 * pre:
	 * post: juega una carta a la vez de las 6 dadas.
	 */
	void jugarCarta(Jugador *jugador);


	/*
	 * pre:
	 * post: elimina al jugador que se quedo sin tesoros.
	 */
	void eliminarJugador(unsigned int posicion);

	/*
	 * pre:
	 * post: asgina la cantidad de jugadores vivos.
	 */
	void setJugadoresVivos(unsigned int jugadores);

	/*
	 * pre:
	 * post:devuelve la cantidad de jugadores vivos.
	 */
	unsigned int getJugadoresVivos();
};

#endif /* TESOROBINARIO_H_ */
