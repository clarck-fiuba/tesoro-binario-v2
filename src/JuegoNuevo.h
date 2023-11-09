/*
 * JuegoNuevo.h
 *
 *  Created on: 08/11/2023
 *      Author: algo2
 */

#ifndef SRC_JUEGONUEVO_H_
#define SRC_JUEGONUEVO_H_


void jugarJuego(TesoroBinario * nuevoJuego){

	unsigned int cantidadDeTesoros = (CAPA * CAPA)/CAPA;

	nuevoJuego->configurarCantidadDeTesoros(cantidadDeTesoros);

	for(unsigned i = 1; i <= cantidadDeTesoros; i++) {
		unsigned int indice = 1;
		while(indice <= CANTIDAD_DE_JUGADORES) {
			nuevoJuego->colocarTesoros(nuevoJuego->getJugador(indice));
			indice++;
		}
	}

	std::cout << "Fase de ingreso tesoro terminada" << std::endl;

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

	delete nuevoJuego;

}

#endif /* SRC_JUEGONUEVO_H_ */
