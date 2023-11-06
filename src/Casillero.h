/*
 * Casillero.h
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_
#include <iostream>
#include "Ficha.h"

enum EstadoCasilla {
	VACIA,
	INACTIVA,
	BLINDADA,
	LLENO
};

class Casillero {
private:
	EstadoCasilla estado;
	unsigned int propietario;
	Ficha *ficha;
	Casillero**** vecinos;
	int rangoDeVecinos;
	int dimensionCuboVecinos;
	unsigned int z;
	unsigned int x;
	unsigned int y;

	/*
	 * pre: -
	 * post: Valida las coordenadas x, y, z.
	 */
	void validarXYyZ(unsigned int x, unsigned int y, unsigned int z);

	/*
	 * pre: -
	 * post: Valida que el nuevoPropietario sea el correcto.
	 */
	void validarPropietario(unsigned int nuevoPropietario);

	/*
	 * pre: -
	 * post: Verifica que la colocacion de una ficha se haga de manera correcta.
	 */
	void verificarColocacionDeFicha(Ficha* nuevaFicha);

	/*
	 * pre: -
	 * post: Verifica que primero se haya colocado una ficha, que ficha sea distinto de NULL.
	 */
	void verificarFicha();

	/*
	 * pre: -
	 * post: Verifica que nuevoEstado sea correcto.
	 */
	void validarNuevoEstado(EstadoCasilla nuevoEstado);

	/*
	 * pre: -
	 * post: Valida que el rango de busqueda de los vecinos sea mayor o igual a 1
	 */
	void validarRangoVecinos(unsigned int rangoVecinos);

	/*
	 * pre: -
	 * post: Valida que la dimension del cubo vecinos sea mayor o igual a 3.
	 */
	void validarDimensionCuboVecinos(unsigned int dimensionCuboVecinos);

	/*
	 * pre: -
	 * post: Valida que las coordenadas sea las correctas.
	 */
	void validarCoordenadasVecinos(unsigned int z, unsigned int x, unsigned int y);

public:
	/*
	 * pre: Las coordenadas x, y, z deben ser mayores a 0.
	 * post: Crea un casillero con las coordenadas que se pasaron por parametro.
	 */
	Casillero(unsigned int z, unsigned int x, unsigned int y);

	/*
	 * pre: -
	 * post: Elimina de forma correcta al casillero.
	 */
	virtual ~Casillero();

	/*
	 * pre: -
	 * post: Devuelve el valor de la coordenada z.
	 */
	unsigned int getZ();

	/*
	 * pre: -
	 * post: Devuelve el valor de la coordenada x.
	 */
	unsigned int getX();

	/*
	 * pre: -
	 * post: Devuelve el valor de la coordenada y.
	 */
	unsigned int getY();

	/*
	 * pre: El atributo dimensionesCuboVecinos debe ser mayor a 0.
	 * post: Inicializa cuadruple puntero vecinos de dimensiones "dimensionesCuboVecinos"
	 * 		 y deja el puntero vecinos[i][j][k] inicializado en NULL.
	 */
	void inicializarCuboVecinos();

	/*
	 * pre: -
	 * post: Elimina de forma correcta el cuadruple puntero vecinos.
	 */
	void eliminarCuboVecinos();

	/*
	 * pre: -
	 * post: Devuelve el propietario del casillero.
	 */
	unsigned int getPropietario();

	/*
	 * pre: El nuevoPropietario debe ser mayor o igual a 1.
	 * post: Cambia el propietario del casillero por el pasado por parámetro.
	 */
	void setPropietario(unsigned int nuevoPropietario);

	/*
	 * pre: La ficha debe ser distinta de NULL.
	 * post: Devuelve el tipo de ficha.
	 */
	TipoDeFicha getTipoFicha();

	/*
	 * pre: La ficha debe estar NULL y la nuevaFicha debe ser distinto de NULL.
	 * post: Coloca una nueva ficha en el tablero.
	 */
	void colocarFicha(Ficha *nuevaFicha);

	/*
	 * pre: Se debe de haber colocado una ficha (llamado al metodo colocarFicha()),
	 * 		que ficha sea distinto de NULL.
	 * post: Cambia el tipo de ficha de la ficha por el pasado por parámetro.
	 */
	void cambiarFicha(TipoDeFicha nuevoTipo);

	/*
	 * pre: -
	 * post: Devuelve el estado del casillero.
	 */
	EstadoCasilla getEstado();

	/*
	 * pre: El nuevo estado debe existir.
	 * post: Cambia el estado del casillero por el nuevo estado pasado por parámetro.
	 */
	void setEstado(EstadoCasilla nuevoEstado);

	/*
	 * pre: -
	 * post: Retorna verdadero si el estado de la casilla es VACIA.
	 */
	bool estaVacio();

	/*
	 * pre: -
	 * post: Devuelve el rango de busqueda de los vecinos.
	 */
	int getRangoVecinos();

	/*
	 * pre: El rango de busqueda de los vecinos debe ser mayor o igual a 1.
	 * post: Cambia el rango de busqueda de los vecinos por el pasado por parámetro.
	 */
	void setRangoVecinos(int rangoVecinos);

	/*
	 * pre: La dimension del cubo vecinos debe ser mayor o igual a 3.
	 * post: Cambia la dimension del cubo vecinos por el pasado por parámetro.
	 */
	void setDimensionCuboVecinos(int dimensionCuboVecinos);

	/*
	 * pre: -
	 * post: Verifica que el vecino del casillero pasado por parámetro sea distinto de NULL
	 * 		 y que tampoco sea el vecino (0, 0, 0).
	 */
	bool validarVecino(Casillero* vecino);

	/*
	 * pre: Las coordenadas z, x e y deben valer entre -rangoDeVecinos y rangoDeVecinos.
	 * post: Retorna el casillero vecino de mi cubo de vecinos.
	 */
	Casillero* getVecino(unsigned int z, unsigned int x, unsigned int y);

	/*
	 * pre: Las coordenadas z, x e y deben valer entre -rangoDeVecinos y rangoDeVecinos y
	 * 		el cubo de vecinos debe estar inicializado, haber llamado al metodo inicializarCuboVecinos().
	 * post: Cambia el puntero vecino del cubo vecino y hace que apunte al vecino pasado por parámetro.
	 */
	void setVecino(Casillero *vecino, unsigned int z, unsigned int x, unsigned int y);
};

#endif /* CASILLERO_H_ */
