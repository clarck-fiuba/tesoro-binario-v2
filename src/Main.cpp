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

	nuevoJuego->configurarCantidadDeTesoros(cantidadDeTesoros);

	for(unsigned i = 1; i <= cantidadDeTesoros; i++) {
		unsigned int indice = 1;
		while(indice <= numeroJugadores) {
			nuevoJuego->colocarTesoros(nuevoJuego->getJugador(indice));
			indice++;
		}
	}
	std::cout << "Fase de ingreso tesoro terminada" << std::endl;

	/*while(nuevoJuego->getJugadores()->contarElementos() > 1) {
		unsigned int indice = 1;
		while(indice <= nuevoJuego->getJugadores()->contarElementos()) {
			nuevoJuego->eliminarJugador(indice);
			nuevoJuego->setTurno(nuevoJuego->getTurnos() + 1);
			nuevoJuego->activarCasillero(nuevoJuego->getJugador(indice));
			nuevoJuego->colocarEspias(nuevoJuego->getJugador(indice));
			std::cout << "-----------" << std::endl;
			indice++;
		}
	}*/

	while(nuevoJuego->getJugadoresVivos() > 1) {
		unsigned int indice = 1;
		while(indice <= numeroJugadores) {
			nuevoJuego->eliminarJugador(indice);
			nuevoJuego->setTurno(nuevoJuego->getTurnos() + 1);
			nuevoJuego->activarCasillero(nuevoJuego->getJugador(indice));
			nuevoJuego->colocarEspias(nuevoJuego->getJugador(indice));
			nuevoJuego->jugarCarta(nuevoJuego->getJugador(indice));
			nuevoJuego->colocarTesoroMina(nuevoJuego->getJugador(indice));
			std::cout << "-----------" << std::endl;
			indice++;
		}
	}

	/*while(nuevoJuego->getJugadores()->contarElementos() > 1) {
		unsigned int indice = 1;

		nuevoJuego->getJugadores()->iniciarCursor();
		while(nuevoJuego->getJugadores()->avanzarCursor()) {
			nuevoJuego->eliminarJugador(indice);
			Jugador* jugadorActual = nuevoJuego->getJugadores()->obtenerCursor();
			//nuevoJuego->eliminarJugador(jugadorActual->getNumeroJugador());
			nuevoJuego->setTurno(nuevoJuego->getTurnos() + 1);
			nuevoJuego->activarCasillero(jugadorActual);
			nuevoJuego->colocarEspias(jugadorActual);
			indice++;
		}

	}*/


	std::cout << "Juego terminado" << std::endl;

	delete nuevoJuego;
}



