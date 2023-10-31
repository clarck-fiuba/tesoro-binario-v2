/*
 * Main.cpp
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#include <iostream>
#include "TesoroBinario.h"

int main() {
	unsigned int numeroJugadores = 2;
	unsigned int cantidadDeTesoros = numeroJugadores * 2;
	TesoroBinario *nuevoJuego = new TesoroBinario(numeroJugadores);

	//nuevoJuego->crearTablero(numeroJugadores);

	std::cout << "Profundidad: " << nuevoJuego->getTablero()->getProfundidad() << std::endl;
	std::cout << "Ancho: " <<nuevoJuego->getTablero()->getAncho() << std::endl;
	std::cout << "Alto: " <<nuevoJuego->getTablero()->getAlto() << std::endl;

	nuevoJuego->configurarCantidadDeTesoros(cantidadDeTesoros);

	for(unsigned i = 1; i <= cantidadDeTesoros; i++) {
		unsigned int indice = 1;
		while(indice <= numeroJugadores) {
			nuevoJuego->colocarTesoros(nuevoJuego->getJugador(indice));
			indice++;
		}
		//nuevoJuego->colocarTesoros(nuevoJuego->getJugador(1));
		//nuevoJuego->colocarTesoros(nuevoJuego->getJugador(2));
	}
	std::cout << "Fase de ingreso tesoro terminada" << std::endl;

	nuevoJuego->JugarCarta(nuevoJuego->getJugador(1));

	/*nuevoJuego->colocarTesoros(1, 1, 1, nuevoJuego->getJugador(1));
	nuevoJuego->colocarTesoros(1, 1, 2, nuevoJuego->getJugador(1));
	nuevoJuego->colocarTesoros(1, 1, 3, nuevoJuego->getJugador(1));

	if(nuevoJuego->getTablero()->getCasillero(1, 1, 1)->getFicha()->getTipoFicha() == TESORO) {
		std::cout << "Tesoro bien ingresado" << std::endl;
	}

	if(nuevoJuego->getTablero()->getCasillero(1, 1, 1)->getVecino(0, 0, 2)->getFicha()->getTipoFicha() == TESORO) {
		std::cout << "Vecino con tesoro" << std::endl;
	}*/

	delete nuevoJuego;
}



