/*
 * Main.cpp
 *
 *  Created on: 13 oct. 2023
 *      Author: gonzalo
 */



#include "TesoroBinario.h"
#include "JuegoNuevo.h"
#include "Constantes.h"


int main() {

	TesoroBinario * nuevoJuego = new TesoroBinario(CANTIDAD_DE_JUGADORES);

	jugarJuego(nuevoJuego);

}



