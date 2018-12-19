#ifndef __IGVMALLATRIANGULOS
#define __IGVMALLATRIANGULOS

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

class igvMallaTriangulos {
	protected:
		// Atributos

		long int num_vertices; // n�mero de v�rtices de la malla de tri�ngulos
		float *vertices; // array con las (num_vertices * 3) coordenadas de los v�rtices
		float *normales; // array con las (num_vertices * 3) coordenadas de la normal a cada v�rtice (s�lo para la generaci�n de la esfera)

		float *coor_tex; // array con las (num_vertices * 2) coordenadas de textura para cada v�rtice (s�lo para la generaci�n de la esfera)

		long int num_triangulos; // n�mero de tri�ngulos de la malla de tri�ngulos
		unsigned int *triangulos; // array con los (num_triangulos * 3) �ndices a los v�rtices de cada tri�ngulo

		// Apartado G: A�adir aqu� los atributos con los �ngulos de rotaci�n en X, Y y Z.

	public:
		// Constructor y destructor

		// genera una esfera centrada en el origen de radio r y con div_u divisiones en u y div_v divisiones en v
		igvMallaTriangulos(float r, int div_u, int div_v);

		~igvMallaTriangulos();

		// M�todos
		// m�todo con las llamadas OpenGL para visualizar la malla de tri�ngulos
    void visualizar();

};

#endif
