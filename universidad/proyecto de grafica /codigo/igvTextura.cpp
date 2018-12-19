#include "igvTextura.h"

// Metodos constructores y destructor

/*Función que crea la textura
*/
igvTextura::igvTextura(char *fichero, int modo) {
  GLubyte *imagen;

	//Cargamos la imagen
	imagen = loadBMPRaw(fichero, alto, ancho);
 
	glGenTextures(1, &idTextura);
	/*- Enlazar el identificador creado a GL_TEXTURE_2D*/
	glBindTexture(GL_TEXTURE_2D, idTextura);
	/*- Especificar la textura, asign�dole como textura el array imagen*/
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ancho, alto, 0, GL_RGB, GL_UNSIGNED_BYTE, imagen);
	/*- Modo de aplicaci�n de la textura*/
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	/*- Par�metros de la textura: repetici�n y filtros
	*/
	//En función del modo en el que queramos la textura, la aplicamos en GL_CLAMP o en GL_REPEAT
	if (modo = 0) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	}

	if (modo = 1) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	glEnable(GL_TEXTURE_2D);
	
	delete imagen;
}

/*Función que aplica la textura
*/
void igvTextura::aplicar(void) {
  glBindTexture(GL_TEXTURE_2D, idTextura);
}

/*Función que destruye la textura
*/
igvTextura::~igvTextura() {
  glDeleteTextures(1, &idTextura); 
}
