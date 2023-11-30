/*
 * Main.cpp
 *
 *  Created on: 11 nov. 2023
 *      Author: gonzalo
 */

#include "TesoroBinario.h"

int main() {
	std::cout << "BIENVENIDOS AL JUEGO TESORO BINARIO" << std::endl;
	std::cout << std::endl;
	TesoroBinario* nuevoJuego = new TesoroBinario();
	nuevoJuego->jugar();

	delete nuevoJuego;

	return 0;
}





