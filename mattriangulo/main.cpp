#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;

void init(void)
{
	// Ubicamos la fuente de luz en el punto
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };// Activamos la fuente de luz
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); //Activamos las luces en 0
	glDepthFunc(GL_LESS); //comparación de profundidad
	glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	// Queremos que se dibujen las caras frontales
	// y con un color solido de relleno.
    glPolygonMode(GL_FRONT, GL_FILL);

}
	//Funcion para dar color y material a cada lado de el triangulo
	void color(float a1, float a2, float a3, float d1, float d2, float d3, float s1, float s2, float s3, float a4)
	{
		GLfloat mat_ambient[] = { a1, a2, a3, a4 };
		GLfloat mat_diffuse[] = { d1, d2, d3, a4 };
		GLfloat mat_specular[] = { s1, s2, s3, a4 };
		GLfloat shine[] = {a4};

		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shine);

	}
		
	void reshape(int w, int h)
	{
		glViewport(0, 0, (GLsizei) w, (GLsizei) h);
		// Activamos la matriz de proyeccion.
		glMatrixMode(GL_PROJECTION);
		// "limpiamos" esta con la matriz identidad.
		glLoadIdentity();
		// Usamos proyeccion ortogonal
		glOrtho(-1, 1, -1, 1, -1, 1);
		// Activamos la matriz de modelado/visionado.
		glMatrixMode(GL_MODELVIEW);
		// "Limpiamos" la matriz
		glLoadIdentity();
	}

	void display(void)
	{


		// "Limpiamos" el frame buffer con el color de "Clear", en este
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode( GL_MODELVIEW_MATRIX );
		glLoadIdentity();
		// Rotar en el eje X,Y
		glRotatef( rotate_x, 1.0, 0.0, 0.0 );
		glRotatef( rotate_y, 0.0, 1.0, 0.0 );
		glPushMatrix();

glEnable(GL_NORMALIZE);

		//Dibujamos un triangulo
		
		glBegin(GL_POLYGON);
		//Le pasamos valores a la funcion para agregar color y material
		color(0.0f, 0.1f, 0.06f,0.0f, 0.50980392f, 0.50980392f,0.50196078f, 0.50196078f, 0.50196078f,0.25f);
		//Suavisamos los bordes
		glShadeModel(GL_SMOOTH);
		glNormal3f(1.0f, 1.0f, 1.0f);
		glVertex3f(0.3, -0.3, -0.3 );
		glNormal3f(1.0f, 1.0f, 1.0f);
		glVertex3f(0.3, -0.3,  0.3 );
		glNormal3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-0.3, -0.3,  0.3 );
		glNormal3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-0.3, -0.3, -0.3 );
		glEnd();

		//Parte delantera de triangulo
		glBegin(GL_TRIANGLES);
		color(0.0,0.05,0.05,0.4,0.5,0.5,0.04,0.7,0.7,0.4f );
		glShadeModel(GL_SMOOTH);
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3d(  0.3, -0.3, -0.3 );      
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3d(  0.0,  0.3, 0.0 );     
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3d( -0.3,  -0.3, -0.3 );
		glEnd();

		//Parte de atras del triangulo
		glBegin(GL_TRIANGLES);
		color(0.0,0.0,0.0,0.5,0.0,0.0,0.7,0.6,0.6,0.25f );
		glShadeModel(GL_SMOOTH);
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3f(  0.3, -0.3, 0.3 );      
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3f(  0.0,  0.3, 0.0 );      
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3f( -0.3,  -0.3, 0.3 );    
		glEnd();

		//Parte derecha del triangulo
		glBegin(GL_TRIANGLES);
		color(0.0f, 0.0, 0.0f,0.1f, 0.35f, 0.1f,0.45f, 0.55f, 0.45f,0.25f);
		glShadeModel(GL_SMOOTH);
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3f(0.3, -0.3, -0.3 );
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3f(0.3,  -0.3, 0.3 );
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3f(0.0,  0.3,  0.0 );
		glEnd();

		//Parte izquierda del triangulo
		glBegin(GL_TRIANGLES);
		color(0.05f, 0.05, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.7f, 0.04f,0.07812f);
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3f(-0.3, -0.3,  0.3 );
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3f(0.0,  0.3,  0.0 );
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glVertex3f(-0.3,  -0.3, -0.3 );
		glEnd();

		glFlush();
	}
		void specialKeys( int key, int x, int y )
{

		//  Flecha derecha: aumentar rotación 7 grados
	if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;

		//  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;
		//  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 7;
		//  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;
        
		//  Solicitar actualización de visualización
		glutPostRedisplay();
	}


	int main(int argc, char **argv)
	{
		// Inicializo OpenGL
		glutInit(&argc, argv);
		// Activamos buffer simple y colores del tipo RGB
		glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
		// Definimos una ventana de medidas 800 x 600 como ventana
		// de visualizacion en pixels
		glutInitWindowSize (800, 600);
		// Posicionamos la ventana en la esquina superior izquierda de
		// la pantalla.
		glutInitWindowPosition (0, 0);
		// Creamos literalmente la ventana y le adjudicamos el nombre que se
		// observara en su barra de titulo.
		glutCreateWindow ("Triangulo");
		// Inicializamos el sistema
		init();
		glutDisplayFunc(display);
		glutReshapeFunc(reshape);
		//glutKeyboardFunc(keyboard);
		glutSpecialFunc(specialKeys);

		glutMainLoop();
		return 0;
	}
