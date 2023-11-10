/*
 * BMPTablero.h
 *
 *  Created on: 8 nov. 2023
 *      Author: gonzalo
 */

#ifndef BMPTABLERO_H_
#define BMPTABLERO_H_
#include "EasyBMP.h"
#include <iostream>
#include <string>

class BMPTablero {
private:
	int numeroCapas;
	int numeroFilas;
	int numeroColumnas;
	int anchoCasillero;
	int altoCasillero;
	int separacionCasillero;
	int anchoCapa;
	int alturaCapa;
	int anchoTablero;
	int alturaTablero;
	BMP* capa;
	BMP* tablero;

public:
	/*
	 * pre:
	 * post:
	 */
	BMPTablero(int numeroCapas, int numeroFilas, int numeroColumnas);

	/*
	 * pre:
	 * post:
	 */
	virtual ~BMPTablero();

	/*
	 * pre:
	 * post:
	 */
	void pintarBlanco(int x, int y);

	/*
	 * pre:
	 * post:
	 */
	void pintarNegro(int x, int y);

	/*
	 * pre:
	 * post:
	 */
	void pintarFondoCapa();

	/*
	 * pre:
	 * post:
	 */
	void pintarCasilleros();

	/*
	 * pre:
	 * post:
	 */
	void pintarMarcoCapa();

	/*
	 * pre:
	 * post:
	 */
	void crearCapa();

	/*
	 * pre:
	 * post:
	 */
	void crearTablero(BMP& tablero, BMP& capa);

	/*
	 * pre:
	 * post:
	 */
	void pintarTesoro(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, BMP& tesoro);

	/*
	 * pre:
	 * post:
	 */
	void pintarEspia(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, BMP& espia);

	/*
	 * pre:
	 * post:
	 */
	void pintarMina(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, BMP& mina);

	/*
	 * pre:
	 * post:
	 */
	void guardarTablero(std::string nombreTablero);
};

#endif /* BMPTABLERO_H_ */
