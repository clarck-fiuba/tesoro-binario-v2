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

enum EstadoCasillero {
	VACIO,
	INACTIVO,
	BLINDADO,
	LLENO
};

class Casillero {
private:
	EstadoCasillero estadoCasillero;
	unsigned int numeroDePropietario;
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
	 * post: Valida que el número de propietario sea mayor o igual a 0.
	 */
	void validarNumeroDePropietario(unsigned int numeroDePropietario);

	/*
	 * pre: -
	 * post: Verifica que la ficha sea NULL, el estado del casillero este en VACIO,
	 * 		 que la nueva ficha sea distinto de NULL y que el numero de propietario sea mayor a 0.
	 */
	void verificarColocacionDeFicha(Ficha* nuevaFicha, unsigned int numeroDePropietario);

	/*
	 * pre: -
	 * post: Verifica que primero haya una ficha colocada, (ficha sea distinto de NULL),
	 * 		 que el tipo de ficha sea el correcto y que el numero de propietario sea mayor 0.
	 */
	void verificarCambioDeFicha(TipoDeFicha tipoDeFicha, unsigned int numeroDePropietario);

	/*
	 * pre: -
	 * post: Verifica que nuevoEstado sea correcto.
	 */
	void validarNuevoEstado(EstadoCasillero nuevoEstado);

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
	 * post: Devuelve el numero de propietario del casillero.
	 */
	unsigned int getNumeroDePropietario();

	/*
	 * pre: El numero de propietario debe ser mayor o igual a 0.
	 * post: Cambia el numero de propietario del casillero por el pasado por parámetro.
	 */
	void setNumeroDePropietario(unsigned int numeroDePropietario);

	/*
	 * pre: La ficha debe ser distinta de NULL.
	 * post: Devuelve el tipo de ficha.
	 */
	TipoDeFicha getTipoFicha();

	/*
	 * pre: -
	 * post: Retorna verdadero si la ficha es distinto de NULL.
	 */
	//bool fichaInicializada();

	/*
	 * pre: La ficha debe estar NULL, la nuevaFicha debe ser distinto de NULL,
	 * 		el casillero debe estar en estado VACIO y el numero de propietario debe ser mayor a 0.
	 * post: Hace que la ficha sea igual a la nueva ficha pasada por parámetro,
	 * 		 cambia el estado del casillero a LLENO y
	 * 		 actualiza el numero de propietario al pasado por parámetro.
	 */
	void colocarFicha(Ficha *nuevaFicha, unsigned int numeroDePropietario);

	/*
	 * pre: Se debe de haber colocado una ficha (llamado al metodo colocarFicha()),
	 * 		que el tipo de ficha sea el correcto y el numero de propietario debe ser mayor a 0.
	 * post: Cambia el tipo de ficha de la ficha por el pasado por parámetro y
	 * 		 actualiza el numero de propietario al pasado por parámetro.
	 */
	void cambiarFicha(TipoDeFicha tipoDeFicha, unsigned int numeroDePropietario);

	/*
	 * pre: -
	 * post: Cambia la ficha a NULL, el estado del casillero a VACIO y
	 * 		 el numero de propietario a 0.
	 */
	void quitarFicha();

	/*
	 * pre: -
	 * post: Devuelve el estado del casillero.
	 */
	EstadoCasillero getEstado();

	/*
	 * pre: El nuevo estado debe existir.
	 * post: Cambia el estado del casillero por el nuevo estado pasado por parámetro.
	 */
	void setEstado(EstadoCasillero nuevoEstado);

	/*
	 * pre: -
	 * post: Retorna verdadero si el estado del casillero es VACIO.
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
