/*
 * Main.cpp
 *
 *  Created on: 11 nov. 2023
 *      Author: gonzalo
 */

#include "TesoroBinario.h"

int main() {

	TesoroBinario* nuevoJuego = new TesoroBinario();
	nuevoJuego->jugar();

	delete nuevoJuego;

	return 0;
}





