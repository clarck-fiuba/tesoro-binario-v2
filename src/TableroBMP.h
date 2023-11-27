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
	 * pre:
	 * post: crea el tableroBMP inicializando de forma correcta sus atrubitos.
	 */
	TableroBMP(int cantidadDeCapas, int cantidadDeFilas, int cantidadDeColumnas);

	/*
	 * pre:
	 * post: elimina el forma correcta el tableroBMP.
	 */
	virtual ~TableroBMP();

	/*
	 * pre:
	 * post: pinta en blaco el pixel de coordenadas x, y del BMP a pintar.
	 */
	void pintarBlanco(BMP* bmpAPintar, int x, int y);

	/*
	 * pre:
	 * post: pinta en negro el pixel de coordenadas x, y del BMP a pintar.
	 */
	void pintarNegro(BMP* bmpAPintar, int x, int y);

	/*
	 * pre:
	 * post: pinta el fondo de la capaBMP.
	 */
	void pintarFondoDeLaCapa();

	/*
	 * pre:
	 * post: pinta los casilleros de la capaBMP.
	 */
	void pintarCasilleros();

	/*
	 * pre:
	 * post: pinta el marco de la capaBMP.
	 */
	void pintarMarcoDeLaCapa();


	/*
	 * pre:
	 * post: crea el capaBMP y lo escribe en un archivo.
	 */
	void crearCapa();

	/*
	 * pre:
	 * post: crea el tableroBMP y lo escribe en un archivo.
	 */
	void crearTablero(BMP& tablero, std::string nombreTablero);

	/*
	 * pre:
	 * post: hace el calculo para los pixeles correctos para pintar las fichas.
	 */
	void calculoParaPintarFichas(unsigned int z, unsigned int x, unsigned int y, int& inicioY, int& inicioX);

	/*
	 * pre:
	 * post: pinta el fichaBMP en el tableroBMP.
	 */
	void pintarFicha(unsigned int z, unsigned int x, unsigned int y,
			BMP& tablero, BMP& ficha, std::string nombreTablero);

	/*
	 * pre:
	 * post: pinta el tesoroBMP en el tableroBMP.
	 */
	void pintarTesoro(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, std::string nombreTablero);

	/*
	 * pre:
	 * post:pinta el espiaBMP en el tableroBMP.
	 */
	void pintarEspia(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, std::string nombreTablero);

	/*
	 * pre:
	 * post: pinta el minaBMP en el tableroBMP.
	 */
	void pintarMina(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, std::string nombreTablero);

	/*
	 * pre:
	 * post: pinta un casillero vacio en el tableroBMP.
	 */
	void pintarCasilleroVacio(unsigned int z, unsigned int x, unsigned int y,
			BMP& tablero, std::string nombreTablero);
};

#endif /* TABLEROBMP_H_ */
