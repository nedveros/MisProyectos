#include <GL/glut.h>
#include <math.h>

#include "igvCamara.h"
#include <iostream>

// Metodos constructores

igvCamara::igvCamara () {}

igvCamara::~igvCamara () {}

igvCamara::igvCamara(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V) {
	P0 = _P0;
	r = _r;
	V = _V;

	tipo = _tipo;
	grado = 0;
}

// Metodos publicos 
void igvCamara::set(igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V) {
	P0 = _P0;
	r = _r;
	V = _V;
}
void igvCamara::set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
			                                double _xwmin, double _xwmax, double _ywmin, double _ywmax, double _znear, double _zfar) {
	tipo = _tipo;

	P0 = _P0;
	r = _r;
	V = _V;

	xwmin = _xwmin;
	xwmax = _xwmax;
	ywmin = _ywmin;
	ywmax = _ywmax;
	znear = _znear;
	zfar = _zfar;
}

void igvCamara::set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
			                         double _angulo, double _raspecto, double _znear, double _zfar) {
	tipo = _tipo;

	P0 = _P0;
	r = _r;
	V = _V;

	angulo = _angulo;
	raspecto = _raspecto;
	znear = _znear;
	zfar = _zfar;
}

void igvCamara::aplicar(void) {

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();

	if (tipo==IGV_PARALELA) {
		glOrtho(xwmin, xwmax, ywmin, ywmax, znear, zfar);
	}
	if (tipo==IGV_FRUSTUM) {
		glFrustum(xwmin, xwmax, ywmin, ywmax, znear, zfar);
	}
	if (tipo==IGV_PERSPECTIVA) {
		gluPerspective(angulo,raspecto,znear,zfar);
	}
	
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(P0[X],P0[Y],P0[Z], r[X],r[Y],r[Z], V[X],V[Y],V[Z]);
	
	//Rotamos la c�mara en el �ngulo deseado
	glRotatef(grado, 0, 1, 0);
}

/*Funci�n que hace zoom en la c�mara
*/
void igvCamara::zoom(double factor) {
	double f = 1.0 - factor;

	if (tipo == IGV_PERSPECTIVA) {
		angulo *= f;
		if (angulo > 180) angulo = 180;
	}
	else {
		xwmin *= f;
		xwmax *= f;
		ywmin *= f;
		ywmax *= f;
	}
}

/*Funci�n que aumenta hacia la derecha la rotaci�n de la c�mara
*/
void igvCamara::girarDerecha() {
	grado = grado + 10;
}

/*Funci�n que aumenta hacia la izquierda la rotaci�n de la c�mara
*/
void igvCamara::girarIzquierda() {
	grado = grado - 10;
}