#ifndef __IGVINTERFAZ
#define __IGVINTERFAZ

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include <string>
#include <iostream>

#include "igvEscena3D.h"
#include "igvCamara.h"

using namespace std;

typedef enum {
	IGV_VISUALIZAR,
	IGV_SELECCIONAR,
} modoInterfaz;

class igvInterfaz {
private:
	//Atributos referentes a la cámara para poder visualizar las diferentes vistas
	static int posicion;
	static int maxPosiciones;
	static igvPunto3D puntos[4];
	static igvPunto3D arriba[4];
protected:
	// Atributos
	int ancho_ventana; // Ancho inicial de la ventana de visualizacion
	int alto_ventana;  // Alto inicial de la ventana de visualizacion
	
	igvEscena3D escena; // Escena que se visualiza en la ventana definida por igvInterfaz
	igvCamara camara; // Cámara que se utiliza para visualizar la escena

	modoInterfaz modo; // IGV_VISUALIZAR: en la ventana se va a visualizar de manera normal la escena, 
					   // IGV_SELECCIONAR: se ha pulsado sobre la ventana de visualizaci�n, la escena se debe
	int cursorX, cursorY; // Píxel de la pantalla sobre el que está situado el ratón

	int objeto_seleccionado; // Código del objeto seleccionado, -1 si no hay ninguno


public:
	// Constructores por defecto y destructor
	igvInterfaz();
	~igvInterfaz();

	// callbacks de eventos
	static void set_glutKeyboardFunc(unsigned char key, int x, int y); // metodo para control de eventos del teclado
	static void set_glutReshapeFunc(int w, int h); // m�todo que define la camara de vision y el viewport
												   // se llama autom�ticamente cuano se camba el tama�o de la ventana
	static void set_glutDisplayFunc(); // m�todo para visualizar la escena


	//Método para el control de la pulsación del ratón
	static void  set_glutMouseFunc(GLint boton, GLint estado, GLint x, GLint y); // control de pulsacion del raton

	// crea el mundo que se visualiza en la ventana
	void crear_mundo(void);

	// inicializa todos los par�metros para crear una ventana de visualizaci�n
	void configura_entorno(int argc, char** argv, // parametros del main
		int _ancho_ventana, int _alto_ventana, // ancho y alto de la ventana de visualizaci�n
		int _pos_X, int _pos_Y, // posicion inicial de la ventana de visualizaci�n
		string _titulo // t�tulo de la ventan de visualizaci�n
	);
	void inicializa_callbacks(); // inicializa todas los callbacks

	void inicia_bucle_visualizacion(); // visualiza la escena y espera a eventos sobre la interfaz

	// m�todos get_ y set_ de acceso a los atributos
	int get_ancho_ventana() { return ancho_ventana; };
	int get_alto_ventana() { return alto_ventana; };

	void set_ancho_ventana(int _ancho_ventana) { ancho_ventana = _ancho_ventana; };
	void set_alto_ventana(int _alto_ventana) { alto_ventana = _alto_ventana; };
	//Función que crea el menú
	void create_menu();
	//Función que asigna el comportamiento al menú cuando se selecciona una de las opciones
	static void menuHandle(int value);
};

#endif
