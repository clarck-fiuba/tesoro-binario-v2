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

void FuncionalidadCartas::Radar(){

	unsigned int x, y ,z;

	unsigned int contadorTesoros = 0;

	std::cout << "Ingrese la coordenada donde quiere poner su radar: " << std::endl;

	IngresoCordenadas(z, x, y);

	for(int i = -this->tablero->getRangoVecinos(); i <= this->tablero->getRangoVecinos(); i++) {
		for(int j = -this->tablero->getRangoVecinos(); j <= this->tablero->getRangoVecinos(); j++) {
			for(int k = -this->tablero->getRangoVecinos(); k <= this->tablero->getRangoVecinos(); k++) {
				if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k) != tablero->getCasillero(z, x, y)->getVecino(0, 0, 0)) {
					if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k) != NULL) {
						if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k)->estaVacio() == false) {
							if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k)->getTipoficha() == TESORO) {
								if (this->tablero->getCasillero(z, x, y)->getVecino(i, j, k)->getPropietario() != this->tablero->getCasillero(z, x, y)->getPropietario())
									contadorTesoros++;
							}
						}
					}
				}
			}
		}
	}
	if(contadorTesoros != 0) {
		std::cout << "Se ha detectado " << contadorTesoros << " tesoros" << std::endl;
	}else{
		std::cout << "Radar no ha detectado ningun tesoro" << std::endl;
	}

}


Casillero* FuncionalidadCartas::partirTesoro(){

	unsigned int x, y ,z;

	std::cout << "Ingrese el tesoro que desea partir: " << std::endl;

	IngresoCordenadas(z, x, y);

	if (this->tablero->getCasillero(z, x, y)->getTipoficha() == TESORO){

		for(int i = -this->tablero->getRangoVecinos(); i <= this->tablero->getRangoVecinos(); i++) {
			for(int j = -this->tablero->getRangoVecinos(); j <= this->tablero->getRangoVecinos(); j++) {
				for(int k = -this->tablero->getRangoVecinos(); k <= this->tablero->getRangoVecinos(); k++){
					if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k) != tablero->getCasillero(z, x, y)->getVecino(0, 0, 0)){
						if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k) != NULL){
							if(this->tablero->getCasillero(z, x, y)->getVecino(i, j, k)->estaVacio() == true){
								return (this->tablero->getCasillero(z, x, y)->getVecino(i, j, k));
								break;
							}
						}

					}
				}

			}
		}
	std::cout << "No hay espacio para partir el tesoro" << std::endl;

	}else{
		std::cout << "coordenada invalida" << std::endl;
	}
	return NULL;
}
