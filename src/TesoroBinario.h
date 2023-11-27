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
	 * pre: -
	 * post: Valida que la cantidad de jugadores sea mayor a 1.
	 */
	void validarCantidadDeJugadores(unsigned int cantidadDeJugadores);

	/*
	 * pre: -
	 * post: Valida que la direccion de movimiento sea: ARRIBA, ABAJO, IZQUIERDA, DERECHA, ADELANTE O ATRAS.
	 */
	bool validarDireccionDeMoviento(char direccionDeMovimiento);

	/*
	 * pre: -
	 * post: Valida que el movimiento pueda ser efectuado de forma correcta.
	 */
	bool validarMovimiento(char direccionDeMovimiento, Casillero* casilleroConTesoroAMover);

	/*
	 * pre: -
	 * post: Retorna verdadero si el casillero tiene como ficha un TESORO del jugador.
	 */
	bool tesoroPropio(Casillero* casillero, Jugador* jugador);

	/*
	 * pre: -
	 * post: Retorna verdadero si el casillero tiene como ficha un TESORO de otro jugador.
	 */
	bool tesoroDeOtroJugador(Casillero* casillero, Jugador* jugador);

	/*
	 * pre: -
	 * post: Retorna verdadero si el casillero tiene como ficha un ESPIA de otro jugador.
	 */
	bool espiaDeOtroJugador(Casillero* casillero, Jugador* jugador);

	/*
	 * pre: -
	 * post: Retorna verdadero si el casillero tiene como ficha una MINA de otro jugador.
	 */
	bool minaDeOtroJugador(Casillero* casillero, Jugador* jugador);

	/*
	 * pre: -
	 * post: Devuelve verdadero si el casillero está VACIO.
	 */
	bool casilleroVacio(Casillero* casillero);

	/*
	 * pre: -
	 * post: Devuelve verdadero si el casillero está en estado INACTIVO.
	 */
	bool casilleroInactivo(Casillero* casillero);

	/*
	 * pre: -
	 * post: Devuelve verdadero si el casillero está en estado BLINDADO y
	 * 		 tiene como ficha un TESORO.
	 */
	bool tesoroBlindado(Casillero* casillero);

	/*
	 * pre: -
	 * post: Retorna verdadero si el jugador alcanzó el límite de minas que
	 * 		 puede colocar en el tablero.
	 */
	bool limiteAlcanzadoDeMinasEnTablero(Jugador* jugador);

public:

	/*
	 * pre: -
	 * post: Crea el TesoroBinario con todas sus configuraciones.
	 */
	TesoroBinario();

	/*
	 * pre: -
	 * post: Destruye TesoroBinario de manera correcta.
	 */
	virtual ~TesoroBinario();

	/*
	 * pre: -
	 * post: Retorna el tablero del juego.
	 */
	Tablero *getTablero();

	/*
	 * pre: -
	 * post: Retorna el jugador en la posicion que se pasa por parámetro.
	 */
	Jugador *getJugador(unsigned int posicion);

	/*
	 * pre: -
	 * post: Retorna la lista de jugadores.
	 */
	Lista<Jugador* > *getJugadores();

	/*
	 * pre: -
	 * post: Retorna el número de turno del juego.
	 */
	unsigned int getNumeroDeTurno();

	/*
	 * pre: -
	 * post: Actualiza el número de turno por el pasado por parámetro.
	 */
	void actualizarNumeroDeTurno(unsigned int numeroDeTurno);

	/*
	 * pre: La cantidad de jugadores debe ser mayor a 1.
	 * post: Retorna la cantidad de jugadores que el usuario ingrese.
	 */
	unsigned int configurarCantidadDeJugadores();

	/*
	 * pre: -
	 * post: Devuelve la cantidad de tesoros permitidos que los jugadores pueden ingresar.
	 */
	unsigned int configurarCantidadDeTesorosPermitidos(unsigned int cantidadDeJugadores);

	/*
	 * pre: -
	 * post: Crea una lista jugadores con la cantidad de jugadores que se pasa por parámetro,
	 * 		 configurando a cada jugador con un número,
	 * 		 una cantidad de minas que puede colocar y retorna la lista de jugadores.
	 */
	Lista<Jugador* >* configurarJugadores(unsigned int cantidadDeJugadores);

	/*
	 * pre: -
	 * post: Crea un tablero dependiendo de la cantidad de jugadores que se pasa por parámetro
	 * 		 y retorna el tablero.
	 */
	Tablero* configurarTablero(unsigned int cantidadDeJugadores);

	/*
	 * pre: -
	 * post: Crea un tableroBMP dependiendo de las dimensiones del tablero que se pasa por parámetro
	 * 		 y retorna el tableroBMP.
	 */
	TableroBMP* configurarTableroBMP(Tablero* tablero);

	/*
	 * pre: -
	 * post: Crea el tableroBMP de cada jugador.
	 */
	void crearTableroBMPDeLosJugadores();

	/*
	 * pre: -
	 * post: Muestra las configuraciones del juego.
	 */
	void mostrarConfiguracionesDelJuego();

	/*
	 * pre: -
	 * post: Muestra la mano de cartas que tiene el jugador.
	 */
	void mostrarManoDeCartas(Jugador* jugador);

	/*
	 * pre: -
	 * post: Retorna un casillero con las coordenadas que el usuario ingresó.
	 */
	Casillero* ingresoCoordenadaDeCasillero();

	/*
	 * pre: -
	 * post: Retorna la direccion de movimiento correcta en la cual
	 * 		 quiere mover el TESORO que tiene en el casillero pasado por parámetro.
	 */
	char ingresoDeDireccionDeMoviento(Casillero *casilleroConTesoroAMover);

	/*
	 * pre: -
	 * post: Devuelve el casillero donde se moverá el TESORO que tiene en el casillero pasado por parámetro.
	 */
	Casillero* calculoNuevoCasilleroConTesoro(char direccionDeMovimiento, Casillero* casilleroConTesoroAMover);

	/*
	 * pre: -
	 * post: Retorna verdadero si el jugador tiene en su mano de cartas la carta ROMPER_BLINDAJE.
	 */
	bool buscarCartaRomperBlindaje(Jugador* jugador);

	/*
	 * pre: -
	 * post: Retorna al jugador que es propietario del casillero pasado por parámetro.
	 */
	Jugador* jugadorDelCasillero(Casillero* casillero);

	/*
	 * pre: -
	 * post: Busca al jugador a eliminar tesoro y se le descuenta un tesoro
	 * 		 a la cantidad de tesoros.
	 */
	void eliminarTesoro(Casillero* casillero);

	/*
	 * pre: -
	 * post: Cambia el estado del casillero a INACTIVO, lo agrega a lista casillerosInactivos y
	 * 		 agrega el numero de turno de activacion a la lista numeroDeTurnoActivarCasillero.
	 */
	void inactivarCasillero(Casillero* casillero, unsigned int numeroDeTurno);

	/*
	 * pre: -
	 * post: Activa el casillero indicado de forma correcta.
	 */
	void activarCasillero();

	/*
	 * pre: El casillero debe tener como ficha un TESORO y debe estar en estado BLINDADO.
	 * post: Cambia el estado del casillero a LLENO.
	 */
	void romperBlindaje(Casillero*& casillero);

	/*
	 * pre: -
	 * post: Devuelve verdadero si el jugador su funcion getEstadoPisadoMinaDeOtroJugador devuelve verdadero.
	 */
	bool saltarTurno(Jugador* jugador);

	/*
	 * pre: -
	 * post: Coloca un TESORO del jugador de forma correcta.
	 */
	void colocarTesoros(Jugador* jugador);

	/*
	 * pre: -
	 * post: Coloca un ESPIA del jugador de forma correcta.
	 */
	void colocarEspias(Jugador* jugador);

	/*
	 * pre: -
	 * post: Mueve un TESORO del jugador de forma correcta.
	 */
	void moverTesoros(Jugador* jugador);

	/*
	 * pre: -
	 * post: Coloca una MINA del jugador de forma correcta.
	 */
	void colocarMinas(Jugador* jugador);

	/*
	 * pre: -
	 * post: Juega la carta del jugador de forma correcta.
	 */
	void jugarCarta(Jugador* jugador);

	/*
	 * pre: -
	 * post: Agrega una carta aleatoria a la mano de carta del jugador.
	 */
	void agregarCarta(Jugador* jugador);

	/*
	 * pre: -
	 * post: Devuelve NULL si el jugador a sido eliminado o al mismo jugador en caso contrario.
	 */
	Jugador* verificarEliminacionJugador(Jugador* jugador);

	/*
	 * pre: -
	 * post: Pinta un tesoro en el casillero pasado por parámetro
	 * 		 en el tableroBMP del jugador.
	 */
	void pintarTesoro(Casillero* casillero, Jugador* jugador);

	/*
	 * pre: -
	 * post: Pinta un espia en el casillero pasado por parámetro
	 * 		 en el tableroBMP del jugador.
	 */
	void pintarEspia(Casillero* casillero, Jugador* jugador);

	/*
	 * pre: -
	 * post: Pinta una mina en el casillero pasado por parámetro
	 * 		 en el tableroBMP del jugador.
	 */
	void pintarMina(Casillero* casillero, Jugador* jugador);

	/*
	 * pre: -
	 * post: Pinta de negro el casillero pasado por parámetro
	 * 		 en el tableroBMP del jugador.
	 */
	void pintarCasilleroVacio(Casillero* casillero, Jugador* jugador);

	/*
	 * pre: -
	 * post: Inicia el juego llamando a los métodos correspondientes.
	 */
	void jugar();
};

#endif /* TESOROBINARIO_H_ */
