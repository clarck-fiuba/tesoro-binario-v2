/*
 * Main.cpp
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#include "TesoroBinario.h"
#include "JuegoNuevo.h"

int main() {

	unsigned int cantidadJugadores = 0;
	cantidadJugadores = ingresoCantidadDeJugadores(unsigned int cantidadDejugadores);
	TesoroBinario * nuevoJuego = new TesoroBinario(cantidadJugadores);
	jugarJuego(nuevoJuego, cantidadJugadores);

}



