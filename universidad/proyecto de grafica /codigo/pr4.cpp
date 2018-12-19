#include <cstdlib>

#include "igvInterfaz.h"

#pragma comment(linker,"/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

// Objetos globales
// objeto que contiene la configuraci�n y la interacci�n con la ventana de visualizaci�n
igvInterfaz interfaz;

int main (int argc, char** argv) {
	// inicializa la ventana de visualizaci�n
	interfaz.configura_entorno(argc,argv,
		                         500,500, // tama�o de la ventana
														 100,100, // posicion de la ventana
														 "IGV. Proyecto de pr�cticas" // t�tulo de la ventana
														 );

	// establece las funciones callbacks para la gesti�n de los eventos
	interfaz.inicializa_callbacks();

	// inicia el bucle de visualizaci�n de OpenGL
	interfaz.inicia_bucle_visualizacion();

	return(0);
}
