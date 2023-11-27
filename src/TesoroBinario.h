/*
 * TesoroBinario.h
 *
 *  Created on: 24 oct. 2023
 *      Author: gonzalo
 */

#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_
#include <iostream>
#include "Constantes.h"
#include "FuncionalidadCartas.h"
#include "Jugador.h"
#include "Carta.h"
#include "Tablero.h"

class TesoroBinario {
private:
	unsigned int cantidadDeJugadores;
	unsigned int numeroDeTurno;
	unsigned int cantidadDeTesorosPermitidos;
	unsigned int cantidadDeMinasPermitidas;
	Lista<Jugador *> *jugadores;
	Tablero *tablero;
	Lista<Casillero* > *casillerosInactivos;
	Lista<unsigned int> *numeroDeTurnoActivarCasillero;
	TableroBMP* tableroBMP;
	FuncionalidadCartas *funcionalidadCartas;


	/*
	 * pre:
	 * post:devuelve una exepcion si la posicion es invalida.
	 */
	void validarPoscion(unsigned int posicion);

	/*
	 * pre:
	 * post: valida que la cantidad de jugadores sea mayor a 1.
	 */
	void validarCantidadDeJugadores(unsigned int cantidadDeJugadores);

	/*
	 * pre:
	 * post: si direccionDeMovimiento es "a s w d q e" devuelve true, caso contrareo false.
	 */
	bool validarDireccionDeMoviento(char direccionDeMovimiento);

	/*
	 * pre:
	 * post: devuelve true si las direcciones son correctas.
	 */
	bool validarMovimiento(char direccionDeMovimiento, Casillero* casilleroConTesoroAMover);

	/*
	 * pre:
	 * post: devuelve true siel casillero tiene un tesoro propio.
	 */
	bool tesoroPropio(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post: devuelve true si el casillero tiene un tesoro de otro jugador.
	 */
	bool tesoroDeOtroJugador(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post: devuelve true si el casillero tiene un espia de otro jugador.
	 */
	bool espiaDeOtroJugador(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post: devuelve true si el casillero tiene una mina de otro jugador.
	 */
	bool minaDeOtroJugador(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post:  devuelve true si el casillero esta vacio.
	 */
	bool casilleroVacio(Casillero* casillero);

	/*
	 * pre:
	 * post: devuelve true si el casillero esta inactivo.
	 */
	bool casilleroInactivo(Casillero* casillero);

	/*
	 * pre:
	 * post: devuelve true si el casillero esta blindado.
	 */
	bool tesoroBlindado(Casillero* casillero);

	/*
	 * pre:
	 * post: devuelve true si se alcanzo el limete de minas colocadas por el jugador.
	 */
	bool limiteAlcanzadoDeMinasEnTablero(Jugador* jugador);

public:

	/*
	 * pre:
	 * post: crea el juego TesoroBinario con todas sus configuraciones.
	 */
	TesoroBinario();

	/*
	 * pre:
	 * post: destrulle el juego de manera correcta.
	 */
	virtual ~TesoroBinario();

	/*
	 * pre: la posicon del jugador debe ser valida.S
	 * post: devulve el jugador en la posion indicada.S
	 */
	Jugador *getJugador(unsigned int posicion);

	/*
	 * pre:
	 * post: devuelve la lista de jugadores.
	 */
	Lista<Jugador* > *getJugadores();

	/*
	 * pre:
	 * post: devuelve el numero de turno.
	 */
	unsigned int getNumeroDeTurno();

	/*
	 * pre:
	 * post: actualiza el numero de turno.
	 */
	void actualizarNumeroDeTurno(unsigned int numeroDeTurno);

	/*
	 * pre: la cantidad de jugadores debe ser mayor a 1
	 * post: deveulve la cantidad de jugadores que va a tener el juego.
	 */
	unsigned int configurarCantidadDeJugadores();

	/*
	 * pre:
	 * post: devuelve la cantidad de tesoros perimitidos por jugador.
	 */
	unsigned int configurarCantidadDeTesorosPermitidos(unsigned int cantidadDeJugadores);

	/*
	 * pre:
	 * post: crea cada jugador con un numero distintivo, asigna la cantidad de minas por jugador, y devuelve la lista de jugadores.
	 */
	Lista<Jugador* >* configurarJugadores(unsigned int cantidadDeJugadores);

	/*
	 * pre:
	 * post: crea el tablero del juego dependiendo la cantidad de jugadores y lo devuelve.
	 */
	Tablero* configurarTablero(unsigned int cantidadDeJugadores);

	/*
	 * pre:
	 * post: crea un tablero BMP dependiendo las dimensiones del tablero y lo devuelve.
	 */
	TableroBMP* configurarTableroBMP(Tablero* tablero);

	/*
	 * pre:
	 * post: crea el tablero BMP de cada jugador.
	 */
	void crearTableroBMPDeLosJugadores();

	/*
	 * pre:
	 * post: muestra las configuraciones del juego.
	 */
	void mostrarConfiguracionesDelJuego();

	/*
	 * pre:
	 * post: muestras kas cartas que tiene cada jugador.
	 */
	void mostrarManoDeCartas(Jugador* jugador);

	/*
	 * pre:
	 * post: ingreso de coordenadas de un casillero y devuelve el casillero.
	 */
	Casillero* ingresoCoordenadaDeCasillero();

	/*
	 * pre:
	 * post: ingresa las direcciones de movimiento y devuelve la direccion de movimiento.
	 */
	char ingresoDeDireccionDeMoviento(Casillero *casilleroConTesoroAMover);

	/*
	 * pre:
	 * post: devuelve el nuevo casillero con las nuevas coordenadas.
	 */
	Casillero* calculoNuevoCasilleroConTesoro(char direccionDeMovimiento, Casillero* casilleroConTesoroAMover);

	/*
	 * pre:
	 * post: devuelve true si en la mano del jugador tiene el blindaje.
	 */
	bool buscarCartaRomperBlindaje(Jugador* jugador);

	/*
	 * pre:
	 * post: retorna el jugador propietaro del casillero.
	 */
	Jugador* jugadorDelCasillero(Casillero* casillero);

	/*
	 * pre:
	 * post: elimina el tesoro en el casillero del jugador que lo perdio.
	 */
	void eliminarTesoro(Casillero* casillero);

	/*
	 * pre:
	 * post: deja la casilla inactiva dependiendo la cantidad de numeroDeTurno.
	 */
	void inactivarCasillero(Casillero* casillero, unsigned int numeroDeTurno);

	/*
	 * pre:
	 * post: Activa el casillero.
	 */
	void activarCasillero();

	/*
	 * pre:	el casillero debe tener un tesoro y debe estar blindado.
	 * post: rompe el blindaje en la posicion de un casillero que halla un tesoro.
	 */
	void romperBlindaje(Casillero*& casillero);

	/*
	 * pre:
	 * post: devuelve true si el jugador pasado por parametro piso una mina.
	 */
	bool saltarTurno(Jugador* jugador);

	/*
	 * pre:
	 * post: coloca un tesoro de manera correcta.
	 */
	void colocarTesoros(Jugador* jugador);

	/*
	 * pre:
	 * post: coloca un espia de manera correcta.
	 */
	void colocarEspias(Jugador* jugador);

	/*
	 * pre:
	 * post: mueve el tesoro de forma correcta.
	 */
	void moverTesoros(Jugador* jugador);

	/*
	 * pre:
	 * post: coloca una mina de forma correcta.
	 */
	void colocarMinas(Jugador* jugador);

	/*
	 * pre:
	 * post: juega la carta de forma correcta.
	 */
	void jugarCarta(Jugador* jugador);

	/*
	 * pre:
	 * post: agrega una carta aleatoria al jugador.
	 */
	void agregarCarta(Jugador* jugador);

	/*
	 * pre:
	 * post: devuelve nulo si el jugador a sido eliminado o al mismo jugador en caso contrareo.
	 */
	Jugador* verificarEliminacionJugador(Jugador* jugador);

	/*
	 * pre:
	 * post: pinta el tesoro en el tableroBMP del jugador.
	 */
	void pintarTesoro(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post: pinta el espia en el tableroBMP del jugador.
	 */
	void pintarEspia(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post: pinta el tesoroMina en el tableroBMP del jugador.
	 */
	void pintarMina(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post: pinta la casilla vacia en el tableroBMP del jugador.
	 */
	void pintarCasilleroVacio(Casillero* casillero, Jugador* jugador);

	/*
	 * pre:
	 * post: inicia en secuencia el juego, llamando a los metedos necesarios.
	 */
	void jugar();

};

#endif /* TESOROBINARIO_H_ */
