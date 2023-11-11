/*
 * Main.cpp
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */

#include "TesoroBinario.h"
#include "JuegoNuevo.h"

int main() {

	std::cout << "---BIENVENIDO AL JUEGO TESORO BINARIO---" << std::endl;
	unsigned int cantidadJugadores = ingresoCantidadDeJugadores();
	TesoroBinario * nuevoJuego = new TesoroBinario(cantidadJugadores);
	jugarJuego(nuevoJuego, cantidadJugadores);

}



