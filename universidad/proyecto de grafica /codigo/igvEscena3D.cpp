#include "igvEscena3D.h"
#include "igvFuenteLuz.h"
#include "igvMaterial.h"
#include "igvTextura.h"
#include "glm.h"

#include <iostream>

// Metodos constructores 

igvEscena3D::igvEscena3D () {
	//Inicializamos los objetos con las texturas y materiales por defecto
	materialSilverSurfer = 0;
	texturaPlanetaUno = 0;
	texturaPlanetaDos = 0;
	texturaTetera = 0;
}

igvEscena3D::~igvEscena3D() {
}

/*Función que dibuja la escena
*/
void igvEscena3D::visualizar(void) {
	// crear el modelo
	glPushMatrix(); // guarda la matriz de modelado
	  
		//Definimos la primera luz que tenemos y la aplicamos
		unsigned int id = GL_LIGHT0;
		igvPunto3D posicionPrimeraLuz(0, 1, 5);
		igvColor ambientalPrimeraLuz(0.5, 0.5, 0.5, 1.0);
		igvColor difusoPrimeraLuz(0.5, 0.5, 0.5, 1.0);
		igvColor especularPrimeraLuz(1, 1, 1, 1.0);
		double aCPrimeraLuz = 1.0;
		double aUPrimeraLuz = 0.0;
		double aDPrimeraLuz = 0.0;
		
		igvFuenteLuz primeraLuz(id, posicionPrimeraLuz, ambientalPrimeraLuz, difusoPrimeraLuz, especularPrimeraLuz, aCPrimeraLuz, aUPrimeraLuz, aDPrimeraLuz);
		primeraLuz.aplicar();

		//Definimos la segunda luz que tenemos
		id = GL_LIGHT1;
		igvPunto3D posicionSegundaLuz(-4, -2, 0);
		igvColor ambientalSegundaLuz(0.5, 0.5, 0.5, 1.0);
		igvColor difusoSegundaLuz(0.5, 0.5, 0.5, 1.0);
		igvColor especularSegundaLuz(1, 1, 1, 1.0);
		double aCSegundaLuz = 1.0;
		double aUSegundaLuz = 0.0;
		double aDSegundaLuz = 0.0;

		igvFuenteLuz SegundaLuz(id, posicionSegundaLuz, ambientalSegundaLuz, difusoSegundaLuz, especularSegundaLuz, aCSegundaLuz, aCSegundaLuz, aDSegundaLuz);
		SegundaLuz.aplicar();

		//Realizamos las transformaciones y dibujamos el obj
		glPushMatrix();
			glTranslatef(0, 0, -3);
			silverSurfer();
		glPopMatrix();
		
		//Realizamos las transformaciones y dibujamos el planeta uno
		glPushMatrix();
			glTranslatef(0, 0, 7);
			planetaUno();			
		glPopMatrix();
		
		//Realizamos las transformaciones y dibujamos el planeta dos
		glPushMatrix();
			glTranslatef(7, 5, 5);
			planetaDos();
		glPopMatrix();

		//Realizamos las transformaciones y dibujamos la tetera
		glPushMatrix();
		glTranslatef(-20, 0, -20);
		tetera();
		glPopMatrix();

	glPopMatrix (); // restaura la matriz de modelado
}

/*Función que dibuja las envolventes de la escena
*/
void igvEscena3D::visualizar_BV() {

	glPushMatrix();
		//Realizamos las transformaciones y dibujamos la envolvente del obj
		glPushMatrix();
			GLfloat colorSilver[] = { 1,0,0 };
			glTranslatef(0, 1, -2.9);
			pintar_BV(1.4, 2, 3.6, colorSilver);
		glPopMatrix();

		//Realizamos las transformaciones y dibujamos la envolvente del planeta uno
		glPushMatrix();
			GLfloat colorPU[] = {0,1,0 };
			glTranslatef(0, 0, 7);
			pintar_BV_Esfera(4, 50, 50,colorPU);
		glPopMatrix();

		//Realizamos las transformaciones y dibujamos la envolvente del planeta dos
		glPushMatrix();
			glTranslatef(7, 5, 5);
			GLfloat colorPD[] = { 0,0,1 };
			pintar_BV_Esfera(1, 50, 50, colorPD);
		glPopMatrix();

		//Realizamos las transformaciones y dibujamos la envolvente de la tetera
		glPushMatrix();
			glTranslatef(-20, 0, -20);
			GLfloat colorTetera[] = { 1,1,0 };
			pintar_BV_Tetera(6, colorTetera);
		glPopMatrix();

	glPopMatrix();

}

/*Función que crea una envolvente con forma de cubo
*/
void igvEscena3D::pintar_BV(float escalaX, float escalaY, float escalaZ, float *color) {
	//Aplicamos el color a la envolvente
	glColor3fv(color);
	//Dibujamos la envolvente con forma de cubo
	glPushMatrix();
	glScalef(escalaX, escalaY, escalaZ);
	glutSolidCube(1);
	glPopMatrix();
}

/*Función que crea una envolvente con forma de esfera
*/
void igvEscena3D::pintar_BV_Esfera(float radio, float slices, float stacks, float *color) {
	//Aplicamos el color a la envolvente
	glColor3fv(color);
	//Dibujamos la envolvente con forma de esfera
	glPushMatrix();
	glutSolidSphere(radio, slices, stacks);
	glPopMatrix();
}

/*Función que crea una envolvente con forma de tetera
*/
void igvEscena3D::pintar_BV_Tetera(float tam, float* color) {
	//Aplicamos el color a la envolvente
	glColor3fv(color);
	//Dibujamos la envolvente con forma de tetera
	glPushMatrix();
	glutSolidTeapot(tam);
	glPopMatrix();
}

/*Función que devuelve que objeto ha sido seleccionado en función del color
*/
int igvEscena3D::devolverObjeto(GLfloat* vector) {
	
	GLfloat colorSilver[] = { 1,0,0 };
	GLfloat colorPU[] = { 0,1,0 };
	GLfloat colorPD[] = { 0,0,1 };
	GLfloat colorTetera[] = { 1,1,0 };

	//Compruebo Si es el Obj
	bool igual = true;

	for (int i = 0; i < 3; i++) {
		if (colorSilver[i] != vector[i])
			igual = false;
	}

	if (igual)
		return 1;

	//Compruebo Si es el Planeta Uno
	igual = true;

	for (int i = 0; i < 3; i++) {
		if (colorPU[i] != vector[i])
			igual = false;
	}

	if (igual)
		return 2;


	//Compruebo Si es el Planeta Dos
	igual = true;

	for (int i = 0; i < 3; i++) {
		if (colorPD[i] != vector[i])
			igual = false;
	}

	if (igual)
		return 3;

	//Compruebo Si es la tetera
	igual = true;

	for (int i = 0; i < 3; i++) {
		if (colorTetera[i] != vector[i])
			igual = false;
	}

	if (igual)
		return 4;

	return -1;
}

/*Función que dibuja el obj
*/
void igvEscena3D::silverSurfer() {
	//Definimos el objeto de la biblioteca GLM que cargará el .obj
	GLMmodel* model;

	//Silver Surfer
	if (materialSilverSurfer == 0) {
		//Definimos el material que simula el plateado	
		igvColor ambientalMaterial(0.19225, 0.19225, 0.19225);
		igvColor difusoMaterial(0.50754, 0.50754, 0.50754);
		igvColor especularMaterial(0.508273, 0.508273, 0.508273);
		double exponentePhong = 30;
		igvMaterial material(ambientalMaterial, difusoMaterial, especularMaterial, exponentePhong);
		material.aplicar();

	}
	
	//Golden Surfer
	if (materialSilverSurfer == 1) {
		//Definimos el material que simula el oro
		igvColor ambientalMaterial(0.24725, 0.1995, 0.0745);
		igvColor difusoMaterial(0.75164, 0.60648, 0.22648);
		igvColor especularMaterial(0.628281, 0.555802, 0.366065);
		double exponentePhong = 30;
		igvMaterial material(ambientalMaterial, difusoMaterial, especularMaterial, exponentePhong);
		material.aplicar();
	}
	

	//Emerald Surfer
	if (materialSilverSurfer == 2) {
		//Definimos el material que simula la esmeralda
		igvColor ambientalMaterial(0.0215,	0.1745,	0.0215);
		igvColor difusoMaterial(0.07568,	0.61424,	0.07568);
		igvColor especularMaterial(0.633,	0.727811,	0.633);
		double exponentePhong = 70;
		igvMaterial material(ambientalMaterial, difusoMaterial, especularMaterial, exponentePhong);
		material.aplicar();
	}
	
	//Definimos el .obj a cargar
	char nombre[] = "SilverSurfer.obj";
	//Leemos el .obj
	model = glmReadOBJ(nombre);
	//Lo dibujamos en modo GLM_SMOOTH
	glmDraw(model, GLM_SMOOTH);
}

/*Función que dibuja el planeta uno
*/
void igvEscena3D::planetaUno() {
	glPushMatrix();
	//Primera Textura: Planeta Tierra
	if (texturaPlanetaUno == 0) {
		//Definimos los elementos para que aparezca la textura
		GLUquadric *qobj = gluNewQuadric();
		gluQuadricTexture(qobj, GL_TRUE);

		//Definimos el material del que está hecho el planeta
		igvColor difusoMaterial(1.0, 1.0, 1.0);
		igvColor especularMaterial(1.0, 1.0, 1.0);
		igvColor ambientalMaterial(1.0, 1.0, 1.0);
		double exponentePhon = 120;

		igvMaterial material(ambientalMaterial, difusoMaterial, especularMaterial, exponentePhon);
		material.aplicar();
		
		//Aplicamos la textura
		char archivo[] = "mapa.bmp";
		igvTextura textura(archivo, 0);
		textura.aplicar();
		
		//Dibujamos la esfera
		glRotatef(270, 1, 0, 0);
		gluSphere(qobj, 3, 50, 50);
		gluDeleteQuadric(qobj);
	}
	//Segunda Textura: Roca
	if (texturaPlanetaUno == 1) {
		//Definimos los elementos para que aparezca la textura
		GLUquadric *qobj = gluNewQuadric();
		gluQuadricTexture(qobj, GL_TRUE);

		//Definimos el material del que está hecho el planeta
		igvColor difusoMaterial(1.0, 1.0, 1.0);
		igvColor especularMaterial(1.0, 1.0, 1.0);
		igvColor ambientalMaterial(1.0, 1.0, 1.0);
		double exponentePhon = 120;

		igvMaterial material(ambientalMaterial, difusoMaterial, especularMaterial, exponentePhon);
		material.aplicar();

		//Aplicamos la textura
		char archivo[] = "roca.bmp";
		igvTextura textura(archivo, 0);
		textura.aplicar();

		//Dibujamos la esfera
		gluSphere(qobj, 3, 50, 50);
		gluDeleteQuadric(qobj);
	}

	//Tercera Textura: ladrillo en repetición
	if (texturaPlanetaUno == 2) {
		//Definimos los elementos para que aparezca la textura
		GLUquadric *qobj = gluNewQuadric();
		gluQuadricTexture(qobj, GL_TRUE);
		
		//Definimos el material del que está hecho el planeta
		igvColor difusoMaterial(1.0, 1.0, 1.0);
		igvColor especularMaterial(1.0, 1.0, 1.0);
		igvColor ambientalMaterial(1.0, 1.0, 1.0);
		double exponentePhon = 120;

		igvMaterial material(ambientalMaterial, difusoMaterial, especularMaterial, exponentePhon);
		material.aplicar();

		//Aplicamos la textura
		char archivo[] = "ladrillo.bmp";
		igvTextura textura(archivo,1);
		textura.aplicar();

		//Habilitamos los elementos necesarios para la repetición
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		//Dibujamos la textura
		gluSphere(qobj, 3, 50, 50);
		gluDeleteQuadric(qobj);
		//Volvemos al estado normal de aplicación de texturas
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
	}
	
	glPopMatrix();
}

/*Función que dibuja el planeta dos
*/
void igvEscena3D::planetaDos() {
	glPushMatrix();

	//Primera Textura: Luna
	if (texturaPlanetaDos == 0) {
		//Definimos los elementos para que aparezca la textura
		GLUquadric *qobj = gluNewQuadric();
		gluQuadricTexture(qobj, GL_TRUE);

		//Definimos el material del que está hecho el planeta
		igvColor difusoMaterial(1.0, 1.0, 1.0);
		igvColor especularMaterial(1.0, 1.0, 1.0);
		igvColor ambientalMaterial(1.0, 1.0, 1.0);
		double exponentePhon = 120;

		igvMaterial material(ambientalMaterial, difusoMaterial, especularMaterial, exponentePhon);
		material.aplicar();

		//Aplicamos la textura
		char archivo[] = "luna.bmp";
		igvTextura textura(archivo,0);
		textura.aplicar();

		//Dibujamos la esfera
		gluSphere(qobj, 1, 50, 50);
		gluDeleteQuadric(qobj);
	}

	//Segunda Textura: Sol
	if (texturaPlanetaDos == 1) {
		//Definimos los elementos para que aparezca la textura
		GLUquadric *qobj = gluNewQuadric();
		gluQuadricTexture(qobj, GL_TRUE);

		//Definimos el material del que está hecho el planeta
		igvColor difusoMaterial(1.0, 1.0, 1.0);
		igvColor especularMaterial(1.0, 1.0, 1.0);
		igvColor ambientalMaterial(1.0, 1.0, 1.0);
		double exponentePhon = 120;

		igvMaterial material(ambientalMaterial, difusoMaterial, especularMaterial, exponentePhon);
		material.aplicar();

		//Aplicamos la textura
		char archivo[] = "sol.bmp";
		igvTextura textura(archivo,0);
		textura.aplicar();
		//Dibujamos la esfera

		gluSphere(qobj, 1, 50, 50);
		gluDeleteQuadric(qobj);
	}

	//Tercera Textura: metal
	if (texturaPlanetaDos== 2) {
		//Definimos los elementos para que aparezca la textura
		GLUquadric *qobj = gluNewQuadric();
		gluQuadricTexture(qobj, GL_TRUE);

		//Definimos el material del que está hecho el planeta
		igvColor difusoMaterial(1.0, 1.0, 1.0);
		igvColor especularMaterial(1.0, 1.0, 1.0);
		igvColor ambientalMaterial(1.0, 1.0, 1.0);
		double exponentePhon = 120;

		igvMaterial material(ambientalMaterial, difusoMaterial, especularMaterial, exponentePhon);
		material.aplicar();

		//Aplicamos la textura
		char archivo[] = "metal.bmp";
		igvTextura textura(archivo,0);
		textura.aplicar();

		//Dibujamos la esfera
		gluSphere(qobj, 1, 50, 50);
		gluDeleteQuadric(qobj);
	}

	glPopMatrix();
}

/*Función que dibuja la tetera
*/
void igvEscena3D::tetera() {
	glPushMatrix();
	//Primera textura: Oro Clamp
	if (texturaTetera == 0) {
		//Aplicamos el material del que estará hecha
		igvColor difusoMaterial(0.0, 0.0, 0.0);
		igvColor especularMaterial(0.0, 0.0, 0.0);
		igvColor ambientalMaterial(0.0, 0.0, 0.0);
		double exponentePhong = 120;

		igvMaterial material(ambientalMaterial, difusoMaterial, especularMaterial, exponentePhong);
		material.aplicar();

		//Aplicamos la textura
		char archivo[] = "oro.bmp";
		igvTextura textura(archivo, 0);
		textura.aplicar();
		
		//Dibujamos la tetera
		glutSolidTeapot(6);

	}

	//Segunda textura: Oro Repeat
	if (texturaTetera == 1) {
		//Aplicamos el material del que estará hecha
		igvColor difusoMaterial(0.0, 0.0, 0.0);
		igvColor especularMaterial(0.0, 0.0, 0.0);
		igvColor ambientalMaterial(0.0, 0.0, 0.0);
		double exponentePhong = 120;

		igvMaterial material(ambientalMaterial, difusoMaterial, especularMaterial, exponentePhong);
		material.aplicar();

		//Aplicamos la textura
		char archivo[] = "oro.bmp";
		igvTextura textura(archivo, 1);
		textura.aplicar();

		//Habilitamos los elementos necesarios para la repetición
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		
		//Dibujamos la tetera
		glutSolidTeapot(6);
		
		//Volvemos al estado normal de aplicación de texturas
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
	}

	//Tercera textura: Metal Clamp
	if (texturaTetera == 2) {
		//Aplicamos el material del que estará hecha
		igvColor difusoMaterial(0.0, 0.0, 0.0);
		igvColor especularMaterial(0.0, 0.0, 0.0);
		igvColor ambientalMaterial(0.0, 0.0, 0.0);
		double exponentePhong = 120;

		igvMaterial material(ambientalMaterial, difusoMaterial, especularMaterial, exponentePhong);
		material.aplicar();

		//Aplicamos la textura
		char archivo[] = "tetera.bmp";
		igvTextura textura(archivo, 0);
		textura.aplicar();

		//Dibujamos la tetera
		glutSolidTeapot(6);
	}

	//Cuarta textura: Metal Repeat
	if (texturaTetera == 3) {
		//Aplicamos el material del que estará hecha
		igvColor difusoMateria(0.0, 0.0, 0.0);
		igvColor especularMateria(0.0, 0.0, 0.0);
		igvColor ambientalMateria(0.0, 0.0, 0.0);
		double exponentePhon = 120;

		igvMaterial materia(difusoMateria, difusoMateria, especularMateria, exponentePhon);
		materia.aplicar();

		//Aplicamos la textura
		char archivo[] = "tetera.bmp";
		igvTextura textura(archivo, 1);
		textura.aplicar();

		//Habilitamos los elementos necesarios para la repetición
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		
		//Dibujamos la tetera
		glutSolidTeapot(6);
		
		//Volvemos al estado normal de aplicación de texturas
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
	}



	glPopMatrix();
}

/*Función que cambia la textura del objeto o los materiales si se trata
del obj
*/
void igvEscena3D::cambiarModo(int idObjeto, int valor) {
	//Actualiza el .obj
	if (idObjeto == 1) {
		materialSilverSurfer = valor;
	}
	//Actualiza el planeta uno
	if (idObjeto == 2) {
		texturaPlanetaUno = valor;
	}

	//Actualiza el planeta dos
	if (idObjeto == 3) {
		texturaPlanetaDos = valor;
	}

	//Actualiza la tetera
	if (idObjeto == 4){
		texturaTetera = valor;
	}
}






