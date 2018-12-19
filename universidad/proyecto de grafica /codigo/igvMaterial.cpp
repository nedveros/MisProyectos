#include "igvMaterial.h"

// Metodos constructores 

igvMaterial::igvMaterial () {
	
}

igvMaterial::~igvMaterial () {

}

igvMaterial::igvMaterial (const igvMaterial& p) {	//de copia
	Ka = p.Ka;
	Kd = p.Kd;
	Ks = p.Ks;
	Ns = p.Ns;
}

igvMaterial::igvMaterial(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}

// Metodos publicos 

void igvMaterial::aplicar(void) {


	// APARTADO C
	// Aplicar los valores de los atributos del objeto igvMaterial:
	// - coeficiente de reflexi�n de la luz ambiental
	GLfloat ambiental[3] = { Ka[0],Ka[1],Ka[2] };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambiental);
	// - coeficiente de reflexi�n difuso
	GLfloat difuso[3] = { Kd[0],Kd[1] ,Kd[2] };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuso);
	// - coeficiente de reflesi�n especular
	GLfloat especular[3] = { Ks[0],Ks[1],Ks[2] };
	glMaterialfv(GL_FRONT, GL_SPECULAR, especular);
	// - exponente de Phong
	GLfloat exponente = Ns;
	glMaterialfv(GL_FRONT, GL_SHININESS, &exponente);
	// establecer como color de emisi�n (0.0, 0.0, 0.0) (el objeto no es una fuente de luz)
	GLfloat emision[3] = { 0.0,0.0,0.0 };
	glMaterialfv(GL_FRONT, GL_EMISSION, emision);
}

void igvMaterial::set(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}



