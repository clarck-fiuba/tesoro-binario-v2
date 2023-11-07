/*
 * Main.cpp
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#include "TesoroBinario.h"

int main() {
	unsigned int numeroJugadores = 3;
	unsigned int cantidadDeTesoros = (2 * 2)/2;
	TesoroBinario* nuevoJuego = new TesoroBinario(numeroJugadores);

	//nuevoJuego->crearTablero(numeroJugadores);

	//std::cout << "Profundidad: " << nuevoJuego->getTablero()->getProfundidad() << std::endl;
	//std::cout << "Ancho: " <<nuevoJuego->getTablero()->getAncho() << std::endl;
	//std::cout << "Alto: " <<nuevoJuego->getTablero()->getAlto() << std::endl;

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

	/*for(unsigned i = 1; i <= 10; i++) {
		unsigned int indice = 1;
		while(indice <= numeroJugadores) {
			nuevoJuego->setTurno(nuevoJuego->getTurnos() + 1);
			nuevoJuego->activarCasillero(nuevoJuego->getJugador(indice));
			nuevoJuego->colocarEspias(nuevoJuego->getJugador(indice));
			indice++;
		}
	}*/

	while(nuevoJuego->getJugadores()->contarElementos() > 1) {
		unsigned int indice = 1;
		while(indice <= nuevoJuego->getJugadores()->contarElementos()) {
			nuevoJuego->setTurno(nuevoJuego->getTurnos() + 1);
			nuevoJuego->activarCasillero(nuevoJuego->getJugador(indice));
			nuevoJuego->colocarEspias(nuevoJuego->getJugador(indice));
			nuevoJuego->eliminarJugador(indice);
			std::cout << "-----------" << std::endl;
			indice++;
		}
	}

	std::cout << "Juego terminado" << std::endl;

	//nuevoJuego->JugarCarta(nuevoJuego->getJugador(1));
	/*
	try {
		nuevoJuego->JugarCarta(nuevoJuego->getJugador(1));
		if(nuevoJuego->getTablero()->getCasillero(1, 1, 2)->getTipoFicha() == TESORO &
		   nuevoJuego->getTablero()->getCasillero(1, 1, 3)->estaVacio() &&
		   nuevoJuego->getTablero()->getCasillero(1, 2, 1)->estaVacio()) {
			std::cout << "Se ha partido bien el tesoro" << std::endl;
		}
		else if(nuevoJuego->getTablero()->getCasillero(1, 1, 2)->getTipoFicha() == TESORO &&
				nuevoJuego->getTablero()->getCasillero(1, 1, 3)->getTipoFicha() == TESORO) {
			std::cout << "Se ha partido mal el tesoro" << std::endl;
		}
	} catch(std::runtime_error& excep) {
		std::cerr << excep.what() << std::endl;
	}


	nuevoJuego->colocarTesoros(1, 1, 1, nuevoJuego->getJugador(1));
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



