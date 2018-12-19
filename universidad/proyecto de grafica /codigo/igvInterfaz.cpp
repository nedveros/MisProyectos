#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "igvInterfaz.h"

using namespace std;

//Variables que utilizaremos para las distintas vistas
int igvInterfaz::posicion = 0;
int igvInterfaz::maxPosiciones = 4;
igvPunto3D igvInterfaz::puntos[] = { igvPunto3D(10.0, 6.0, 14.0),igvPunto3D(0.0, 20.0, 0.1), igvPunto3D(20.0, 0.0, 0.0), igvPunto3D(0.0, 0.0, 20.0) };
igvPunto3D igvInterfaz::arriba[] = { igvPunto3D(0.0, 1.0, 0.0),igvPunto3D(1.0, 0.0, 0.0), igvPunto3D(0.0, 1.0, 0.0), igvPunto3D(0.0, 1.0, 0.0) };

extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
							 // ellos a las variables de la clase

// Metodos constructores -----------------------------------

igvInterfaz::igvInterfaz() {
	//// Apartado E: inicializaci�n de los atributos para realizar la selecci�n
	modo = IGV_VISUALIZAR;
	objeto_seleccionado = -1;

}

igvInterfaz::~igvInterfaz() {}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {
	//// Apartado B: establecer los par�metros de la c�mara en funci�n de la escena concreta que se est� modelando
	//interfaz.camara.set(IGV_PARALELA, igvPunto3D(6.0, 4.0, 8), igvPunto3D(0, 0, 0), igvPunto3D(0, 1.0, 0),
		//-1 * 5, 1 * 5, -1 * 5, 1 * 5, -1 * 3, 200);
	interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(10.0, 6.0, 14.0), igvPunto3D(0, 0, 0), igvPunto3D(0, 1.0, 0), 60, 1, 1, 100);
}
void igvInterfaz::configura_entorno(int argc, char** argv,
	int _ancho_ventana, int _alto_ventana,
	int _pos_X, int _pos_Y,
	string _titulo) {
	// inicializaci�n de las variables de la interfaz																	
	ancho_ventana = _ancho_ventana;
	alto_ventana = _alto_ventana;

	// inicializaci�n de la ventana de visualizaci�n
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(_ancho_ventana, _alto_ventana);
	glutInitWindowPosition(_pos_X, _pos_Y);
	glutCreateWindow(_titulo.c_str());

	create_menu();

	glEnable(GL_DEPTH_TEST); // activa el ocultamiento de superficies por z-buffer
	glClearColor(0.0, 0.0, 0.0, 0.0); // establece el color de fondo de la ventana

	glEnable(GL_LIGHTING); // activa la iluminacion de la escena
	glEnable(GL_NORMALIZE); // normaliza los vectores normales para calculo iluminacion

	crear_mundo(); // crea el mundo a visualizar en la ventana

}

void igvInterfaz::inicia_bucle_visualizacion() {
	glutMainLoop(); // inicia el bucle de visualizacion de OpenGL
}

void igvInterfaz::set_glutKeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
		// Cambio entre las distintas vistas de la cámara
	case 'v':
		if (posicion == maxPosiciones - 1) {
			posicion = 0;
		}
		else {
			posicion++;
		}

		interfaz.camara.grado = 0;
		interfaz.camara.set(puntos[posicion], igvPunto3D(0, 0, 0), arriba[posicion]);
		break;
	case'z':
		//Hacemos zoom in con la cámara.
		interfaz.camara.zoom(0.2);
		break;
	case 'Z':
		//Hacemos zoom out con la cámara.
		interfaz.camara.zoom(-0.2);
		break;
	case 'p':
		//Rotamos la cámara hacia la derecha
		interfaz.camara.girarDerecha();
		break;
	case 'P':
		//Rotamos la cámara hacia la izquierda
		interfaz.camara.girarIzquierda();
		break;
	case 27: // tecla de escape para SALIR
		exit(1);
		break;
	}
	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutReshapeFunc(int w, int h) {
	// dimensiona el viewport al nuevo ancho y alto de la ventana
	// guardamos valores nuevos de la ventana de visualizacion
	interfaz.set_ancho_ventana(w);
	interfaz.set_alto_ventana(h);

	// establece los par�metros de la c�mara y de la proyecci�n
	
	interfaz.camara.aplicar();
}

void igvInterfaz::set_glutDisplayFunc() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer
	// se establece el viewport
	glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());

	if (interfaz.modo == IGV_SELECCIONAR) {
		//Dibujamos la escena sin efectos
		glDisable(GL_LIGHTING); 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_CULL_FACE);

		// Aplica la cámara
		interfaz.camara.aplicar();

		// Visualiza los BV cada uno de un color
		interfaz.escena.visualizar_BV();

		// Obtener el color del pixel seleccionado
		GLfloat vector[3];

		// Leemos el color del pixel y lo guardamos en vector
		glReadPixels(interfaz.cursorX, interfaz.cursorY, 1, 1, GL_RGB, GL_FLOAT, vector);


		// Comprobamos que objeto ha sido seleccionado
		interfaz.objeto_seleccionado = interfaz.escena.devolverObjeto(vector);
		// Eliminamos la opción número 4 del menú, si no existe, no ocurre nada.
		glutRemoveMenuItem(4);
		// Cambiamos las opciones en función del objeto y si es la tetera, se añade una entrada más al menú
		if (interfaz.objeto_seleccionado == 1) {
			glutChangeToMenuEntry(1, "Silver Surfer", 0);
			glutChangeToMenuEntry(2, "Golden Surfer", 1);
			glutChangeToMenuEntry(3, "Emerald Surfer", 2);
		}
		else if (interfaz.objeto_seleccionado == 2) {
			glutChangeToMenuEntry(1, "Tierrra", 0);
			glutChangeToMenuEntry(2, "Roca", 1);
			glutChangeToMenuEntry(3, "Ladrillo", 2);
		}
		else if (interfaz.objeto_seleccionado == 3) {
			glutChangeToMenuEntry(1, "Luna", 0);
			glutChangeToMenuEntry(2, "Sol", 1);
			glutChangeToMenuEntry(3, "Metal", 2);
		}
		else if (interfaz.objeto_seleccionado == 4) {
			glutChangeToMenuEntry(1, "Oro Clamp", 0);
			glutChangeToMenuEntry(2, "Oro Repeat", 1);
			glutChangeToMenuEntry(3, "Metal Clamp", 2);
			glutAddMenuEntry("Metal Repeat", 3);
			
		}
		else {
			glutChangeToMenuEntry(1, "Primera Textura", 0);
			glutChangeToMenuEntry(2, "Segunda Textura", 1);
			glutChangeToMenuEntry(3, "Tercera Textura", 2);
		}
		
		//Volvemos a activar los efectos
		glEnable(GL_LIGHTING);

	}
	else {
		// Aplica las transformaciones en función de los parámetros de la cámara
		interfaz.camara.aplicar();
		// Visualiza la escena
		interfaz.escena.visualizar();
		// Refresca la ventana
		glutSwapBuffers();
	}
}

void igvInterfaz::set_glutMouseFunc(GLint boton, GLint estado, GLint x, GLint y) {

		//Sabemos que el botón izquierdo del ratón es 0
	if (boton == 0) {
		// Comprobar que el botón se ha presionado o se ha soltado, si se ha pulsado hay que
		// pasar a modo IGV_SELECCIONAR

		//Sabemos que soltar el bot�n corresponde a GLUT_UP
		if (estado == GLUT_UP) {
			interfaz.modo = IGV_VISUALIZAR;
		}

		//Sabemos que apretar el bot�n corresponde a GLUT_DOWN
		if (estado == GLUT_DOWN) {
			interfaz.modo = IGV_SELECCIONAR;
		}

		// Guardo el pixel pulsado
		interfaz.cursorX = x;
		//Realizamos la correspondencia entre pixel y de OPENGL Y GLUT
		interfaz.cursorY = interfaz.alto_ventana - y;

		// Apartado E: renovar el contenido de la ventana de vision 
		glutPostRedisplay();
	}
}



void igvInterfaz::inicializa_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);
	glutMouseFunc(set_glutMouseFunc);
	
}

/* Función que crea el menú para la selección de las texturas
*/
void igvInterfaz::create_menu() {
	int menu_id = glutCreateMenu(menuHandle);
	std::cout << menu_id << std::endl;
	std::cout << "----" << std::endl;
	glutAddMenuEntry("Primera Textura", 0);
	glutAddMenuEntry("Segunda Textura", 1);
	glutAddMenuEntry("Tercera Textura", 2);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

}


/* Función que asigna el comportamiento al menú cuando se selecciona una de las opciones
   En este caso cambiamos la textura del objeto seleccionado 
*/

void igvInterfaz::menuHandle(int value)
{
	interfaz.escena.cambiarModo(interfaz.objeto_seleccionado, value);
	glutPostRedisplay(); // renew the content of the window
}