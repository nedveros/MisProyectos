#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include "igvFuenteLuz.h"
#include "igvMallaTriangulos.h"


class igvEscena3D {
	protected:
		//Variables que guardan la textura o el material de los elementos de la escena
		int materialSilverSurfer;
		int texturaPlanetaUno;
		int texturaPlanetaDos;
		int texturaTetera;

	public:
		// Constructores por defecto y destructor
		igvEscena3D();
		~igvEscena3D();

		
		// Métodos de visualización
		void visualizar();
		void visualizar_BV();
		//Funciones que dibujan los elementos de la escena
		void silverSurfer();
		void planetaUno();
		void planetaDos();
		void tetera();
		//Metódos para dibujar las envolventes
		void pintar_BV(float escalaX, float escalaY, float escalaZ, float *color);
		void pintar_BV_Esfera(float radio, float x, float y, float *color);
		void pintar_BV_Tetera(float tam, float *color);
		//Funciones relacionadas con texturas o materiales
		int devolverObjeto(GLfloat* vector);
		void cambiarModo(int objeto, int modo);
		
};

#endif
