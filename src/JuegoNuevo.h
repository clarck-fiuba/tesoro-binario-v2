/*
 * JuegoNuevo.h
 *
 *  Created on: 08/11/2023
 *      Author: algo2
 */

#ifndef SRC_JUEGONUEVO_H_
#define SRC_JUEGONUEVO_H_

unsigned int ingresoCantidadDeJugadores(unsigned int cantidadDeJugadores){
	std:: cin >> cantidadDeJugadores;
	return (cantidadDeJugadores);
}

void jugarJuego(TesoroBinario * nuevoJuego, unsigned int jugadores){

	unsigned int cantidadDeTesoros = (2 * 2);

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
