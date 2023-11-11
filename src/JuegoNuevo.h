/*
 * JuegoNuevo.h
 *
 *  Created on: 08/11/2023
 *      Author: algo2
 */

#ifndef SRC_JUEGONUEVO_H_
#define SRC_JUEGONUEVO_H_
#include "Constantes.h"

unsigned int ingresoCantidadDeJugadores(){
	unsigned int cantidadDeJugadores = 0;
	std::cout << "Ingrese la cantidad de jugadores: ";
	std:: cin >> cantidadDeJugadores;
	return (cantidadDeJugadores);
}

void jugarJuego(TesoroBinario * nuevoJuego, unsigned int jugadores){

	unsigned int cantidadDeTesoros = (jugadores * MULTIPLICADOR_DEL_TESORO)/2;

	std::cout << "El tablero creado tiene dimensiones: " << std::endl;
	std::cout << "z: "<< nuevoJuego->getTablero()->getProfundidad() << std::endl;
	std::cout << "x: "<< nuevoJuego->getTablero()->getAncho() << std::endl;
	std::cout << "y: "<< nuevoJuego->getTablero()->getAlto() << std::endl;

	nuevoJuego->configurarCantidadDeTesoros(cantidadDeTesoros);

	for(unsigned i = 1; i <= cantidadDeTesoros; i++) {
		unsigned int indice = 1;
		while(indice <= jugadores) {
			nuevoJuego->colocarTesoros(nuevoJuego->getJugador(indice));
			indice++;
		}
	}

	std::cout << "Fase de ingreso tesoro terminada" << std::endl;

	while(nuevoJuego->getJugadoresVivos() > 1) {
		unsigned int indice = 1;
		while(indice <= jugadores) {
			nuevoJuego->eliminarJugador(indice);
			nuevoJuego->setTurno(nuevoJuego->getTurnos() + 1);
			nuevoJuego->activarCasillero(nuevoJuego->getJugador(indice));
			nuevoJuego->colocarEspias(nuevoJuego->getJugador(indice));
			nuevoJuego->moverTesoro(nuevoJuego->getJugador(indice));
			nuevoJuego->jugarCarta(nuevoJuego->getJugador(indice));
			nuevoJuego->colocarTesoroMina(nuevoJuego->getJugador(indice));
			std::cout << "-----------" << std::endl;
			indice++;
		}
	}

	std::cout << "Juego terminado" << std::endl;

	delete nuevoJuego;

}

#endif /* SRC_JUEGONUEVO_H_ */
