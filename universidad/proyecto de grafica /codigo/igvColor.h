#ifndef __IGVCOLOR
#define __IGVCOLOR

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

typedef enum {
	R,
	G,
	B,
	A
};

class igvColor {

	protected:
		// atributos

		double color[4]; // componentes R, G, B, A del color

		// Metodos

	public:
		// Constructores por defecto y destructor
		igvColor();
		~igvColor();

		// Otros constructores
		igvColor(const double r, const double g, const double b);
		igvColor(const double r, const double g, const double b, const double a);
		igvColor(const igvColor& p);	//de copia

		// Metodos
		double& operator[] ( const unsigned char idx );
		double operator[] (const unsigned char idx) const;

		void aplicar(void);

};

#endif

