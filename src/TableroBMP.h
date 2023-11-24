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
	 * post:
	 */
	TableroBMP(int cantidadDeCapas, int cantidadDeFilas, int cantidadDeColumnas);

	/*
	 * pre:
	 * post:
	 */
	virtual ~TableroBMP();

	/*
	 * pre:
	 * post:
	 */
	void pintarBlanco(BMP* bmpAPintar, int x, int y);

	/*
	 * pre:
	 * post:
	 */
	void pintarNegro(BMP* bmpAPintar, int x, int y);

	/*
	 * pre:
	 * post:
	 */
	void pintarFondoDeLaCapa();

	/*
	 * pre:
	 * post:
	 */
	void pintarCasilleros();

	/*
	 * pre:
	 * post:
	 */
	void pintarMarcoDeLaCapa();

	/*
	 * pre:
	 * post:
	 */
	bool archivoCapaYaExistente(const std::string& nombreArchivo);

	/*
	 * pre:
	 * post:
	 */
	void crearCapa();

	/*
	 * pre:
	 * post:
	 */
	void crearTablero(BMP& tablero, std::string nombreTablero);

	/*
	 * pre:
	 * post:
	 */
	void calculoParaPintarFichas(unsigned int z, unsigned int x, unsigned int y, int& inicioY, int& inicioX);

	/*
	 * pre:
	 * post:
	 */
	void pintarFicha(unsigned int z, unsigned int x, unsigned int y,
			BMP& tablero, BMP& ficha, std::string nombreTablero);

	/*
	 * pre:
	 * post:
	 */
	void pintarTesoro(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, std::string nombreTablero);

	/*
	 * pre:
	 * post:
	 */
	void pintarEspia(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, std::string nombreTablero);

	/*
	 * pre:
	 * post:
	 */
	void pintarMina(unsigned int z, unsigned int x, unsigned int y, BMP& tablero, std::string nombreTablero);

	/*
	 * pre:
	 * post:
	 */
	void pintarCasilleroVacio(unsigned int z, unsigned int x, unsigned int y,
			BMP& tablero, std::string nombreTablero);
};

#endif /* TABLEROBMP_H_ */
