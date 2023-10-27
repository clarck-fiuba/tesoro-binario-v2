/*
 * FuncionalidadCartas.cpp
 *
 *  Created on: 26/10/2023
 *      Author: algo2
 */

#include "FuncionalidadCartas.h"

FuncionalidadCartas::FuncionalidadCartas(Tablero* tablero) {
	this->tablero = tablero;
}

FuncionalidadCartas::~FuncionalidadCartas() {
	// TODO Auto-generated destructor stub
}


void FuncionalidadCartas::IngresoCordenadas(unsigned int &z, unsigned int &x, unsigned int &y){
	std::cout << "Z: ";
	std::cin >> z;
	std::cout << "X: ";
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;
}


void FuncionalidadCartas::blindarCarta(){

	unsigned int x, y ,z;

	std::cout << "Ingrese la coordenada de su tesoro que desea blindar: " << std::endl;
	IngresoCordenadas(z, x, y);
	this->tablero->getCasillero(z, x, y)->setEstado(BLINDADA);
	if(this->tablero->getCasillero(z, x, y)->getEstado() == BLINDADA) {
	std::cout << "Casillero blindado" << std::endl;
	}

}


