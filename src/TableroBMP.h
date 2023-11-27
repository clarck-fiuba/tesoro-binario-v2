/*
 * TableroBMP.h
 *
 *  Created on: 20 nov. 2023
 *      Author: gonzalo
 */

#ifndef TABLEROBMP_H_
#define TABLEROBMP_H
#include <iostream>
#include <fstream>
#include "EasyBMP.h"

class TableroBMP {
private:
	int cantidadDeCapas;
	int cantidadDeFilas;
	int cantidadDeColumnas;
	int anchoDeCasillero;
	int alturaDeCasillero;
	int separacionEntreCasilleros;
	int anchoDeCapa;
	int alturaDeCapa;
	int anchoDelTablero;
	int alturaDelTablero;
	BMP* capaDelTablero;
	BMP* tesoro;
	BMP* espia;
	BMP* mina;

public:
	/*
	 * pre: -
	 * post: Crea TableroBMP inicializando de forma correcta sus atributos.
	 */
	TableroBMP(int cantidadDeCapas, int cantidadDeFilas, int cantidadDeColumnas);

	/*
	 * pre: -
	 * post: Elimina de forma correcta TableroBMP.
	 */
	virtual ~TableroBMP();

	/*
	 * pre: -
	 * post: Pinta de blanco el pixel de coordenadas x,y del BMP pasado por parámetro.
	 */
	void pintarBlanco(BMP* bmpAPintar, int x, int y);

	/*
	 * pre: -
	 * post: Pinta de negro el pixel de coordenadas x,y del BMP pasado por parámetro.
	 */
	void pintarNegro(BMP* bmpAPintar, int x, int y);

	/*
	 * pre: -
	 * post: Pinta el fondo del BMP capaDelTablero.
	 */
	void pintarFondoDeLaCapa();

	/*
	 * pre: -
	 * post: Pinta los casilleros del BMP capaDelTablero.
	 */
	void pintarCasilleros();

	/*
	 * pre: -
	 * post: Pinta los marcos del BMP capaDelTablero.
	 */
	void pintarMarcoDeLaCapa();

	/*
	 * pre: -
	 * post: Crea el BMP capaDelTablero de forma correcta y lo escribe en un archivo .bmp
	 */
	void crearCapa();

	/*
	 * pre: -
	 * post: Crea el BMP tablero de forma correcta y lo guarda con el nombre pasado por parámetro.
	 */
	void crearTablero(BMP& tablero, std::string nombreTablero);

	/*
	 * pre: -
	 * post: Realiza el calculo encontrar los pixeles correctos para pintar una ficha.
	 */
	void calculoParaPintarFichas(unsigned int z, unsigned int x, unsigned int y, int& inicioY, int& inicioX);

	/*
	 * pre: -
	 * post: Pinta el BMP ficha que se pasa por parámetro en el tablero que se pasa por parámetro.
	 */
	void pintarFicha(unsigned int z, unsigned int x, unsigned int y,
			BMP& tablero, BMP& ficha, std::string nombreTablero);

	/*
	 * pre: -
	 * post: Pinta un tesoro en el BMP tablero que se pasa por parámetro.
	 */
	void pintarTesoro(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, std::string nombreTablero);

	/*
	 * pre: -
	 * post: Pinta un espia en el BMP tablero que se pasa por parámetro.
	 */
	void pintarEspia(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, std::string nombreTablero);

	/*
	 * pre: -
	 * post: Pinta una mina en el BMP tablero que se pasa por parámetro.
	 */
	void pintarMina(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, std::string nombreTablero);

	/*
	 * pre: -
	 * post: Pinta de negro un casillero del BMP tablero que se pasa por parámetro.
	 */
	void pintarCasilleroVacio(unsigned int z, unsigned int x, unsigned int y,
			BMP& tablero, std::string nombreTablero);
};

#endif /* TABLEROBMP_H_ */
