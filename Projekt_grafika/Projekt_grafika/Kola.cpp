#include "Kola.h"
static GLfloat rozmieszczenie;
Kola::Kola()
{
	promien = 10.0f;
	wysokosc = 20.0f;
	srodek[0] = rozmieszczenie;
	srodek[1] = 0.0f;
	srodek[2] = 0.0f;
}
Kola::Kola(const Kola& wzor)
{
	promien = wzor.promien;
	wysokosc = wzor.wysokosc;
	srodek[0] = wzor.srodek[0];
	srodek[1] = wzor.srodek[1];
	srodek[2] = wzor.srodek[2];

}
void Kola::Rysuj_pare_kol()
{ 
	float alpha = 0.0;
	glColor3f(1.0f, 0.0f, 0.0f); // ustawienie koloru
	glBegin(GL_TRIANGLE_FAN); // rozpocz�cie wykonywania funkcji GL_TRIANGLE_FAN
	glVertex3f(srodek[0],srodek[1], srodek[2]); // ustawienie wsp�rz�dnych �rodka podstawy
	glColor3f(0.0f, 1.0f, 0.0f); // ustawienie koloru
	for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 40) // p�tla s�uz�ca do rysowania g�rnej podstawy walca, podstawa sk�ada si� z czterdziestu odcink�w
	{
		glVertex3f( promien * cos(alpha), promien * sin(alpha), srodek[2]);

	}
	alpha = 0.0; // wyzerowanie warto�ci k�ta, potrzebne, poniewa� wcze�niejsza p�tla po przej�ciu po ca�ym obwodzie ko�a ustawi�a warto�� r�wn� dwukrotno�ci liczby pi
	glVertex3f(promien * cos(alpha), promien * sin(alpha), srodek[2]);
	glEnd(); // koniec wykonywania funkcji GL_TRIANGLE_FAN
	glColor3f(1.0f, 0.0f, 0.0f); //ustawienie koloru
	glBegin(GL_TRIANGLE_FAN); // rozpocz�cie wykonywania funkcji GL_TRIANGLE_FAN
	glVertex3f(srodek[0], srodek[1], srodek[2] + wysokosc); // ustawienie wsp�rz�dnych �rodka podstawy
	glColor3f(0.0f, 0.0f, 1.0f); // ustawienie koloru
	for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 40) // p�tla s�uz�ca do rysowania g�rnej podstawy walca, podstawa sk�ada si� z czterdziestu odcink�w
	{
		glVertex3f(promien * cos(alpha), promien * sin(alpha), srodek[2] + wysokosc);


	}
	alpha = 0.0; // wyzerowanie warto�ci k�ta, potrzebne, poniewa� wcze�niejsza p�tla po przej�ciu po ca�ym obwodzie ko�a ustawi�a warto�� r�wn� dwukrotno�ci liczby pi
	glVertex3f(promien * cos(alpha), promien * sin(alpha), srodek[2] + wysokosc);
	glEnd(); //koniec wykonywania funkcji GL_TRIANGLE_FAN
	glBegin(GL_TRIANGLE_STRIP);// rozpocz�cie wykonywania funkcji GL_TRIANGLE_STRIP-SKLEJANE TR�JK�TY
	for (float i = srodek[2]; i < srodek[2] + wysokosc; i = i + 0.10f) // p�tla odpowiadaj�ca umo�liwiaj�ca przestrzenne u�o�enie sklejanych tr�jkat�w
	{
		for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 40) // p�tla odpowiadaj�ca za u�o�enie sklejanych tr�jk�t�w dooko�a podstawy walca
		{

			glVertex3f(promien * cos(alpha), promien * sin(alpha), i + 10); // wsp�rz�dne osi Z s� przypisywane z p�tli 
			glVertex3f(promien * cos(alpha), promien * sin(alpha), i);

		}
	}
	glEnd(); // koniec wykonywania funkcji GL_TRIANGLE_STRIP
	alpha = 0.0;
	glColor3f(1.0f, 0.0f, 0.0f); // ustawienie koloru
	glBegin(GL_TRIANGLE_FAN); // rozpocz�cie wykonywania funkcji GL_TRIANGLE_FAN
	glVertex3f(srodek[0], srodek[1], srodek[2]+40.0f); // ustawienie wsp�rz�dnych �rodka podstawy
	glColor3f(0.0f, 1.0f, 0.0f); // ustawienie koloru
	for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 40) // p�tla s�uz�ca do rysowania g�rnej podstawy walca, podstawa sk�ada si� z czterdziestu odcink�w
	{
		glVertex3f(promien * cos(alpha), promien * sin(alpha), srodek[2] + 40.0f);

	}
	alpha = 0.0; // wyzerowanie warto�ci k�ta, potrzebne, poniewa� wcze�niejsza p�tla po przej�ciu po ca�ym obwodzie ko�a ustawi�a warto�� r�wn� dwukrotno�ci liczby pi
	glVertex3f(promien * cos(alpha), promien * sin(alpha), (srodek[2]) + 40.0f);
	glEnd(); // koniec wykonywania funkcji GL_TRIANGLE_FAN
	glColor3f(1.0f, 0.0f, 0.0f); //ustawienie koloru
	glBegin(GL_TRIANGLE_FAN); // rozpocz�cie wykonywania funkcji GL_TRIANGLE_FAN
	glVertex3f(srodek[0], srodek[1], srodek[2] + wysokosc+40.0f); // ustawienie wsp�rz�dnych �rodka podstawy
	glColor3f(0.0f, 0.0f, 1.0f); // ustawienie koloru
	for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 40) // p�tla s�uz�ca do rysowania g�rnej podstawy walca, podstawa sk�ada si� z czterdziestu odcink�w
	{
		glVertex3f(promien * cos(alpha), promien * sin(alpha), srodek[2] + wysokosc + 40.0f);


	}
	alpha = 0.0; // wyzerowanie warto�ci k�ta, potrzebne, poniewa� wcze�niejsza p�tla po przej�ciu po ca�ym obwodzie ko�a ustawi�a warto�� r�wn� dwukrotno�ci liczby pi
	glVertex3f(promien * cos(alpha), promien * sin(alpha), srodek[2] + wysokosc + 40.0f);
	glEnd(); //koniec wykonywania funkcji GL_TRIANGLE_FAN
	glBegin(GL_TRIANGLE_STRIP);// rozpocz�cie wykonywania funkcji GL_TRIANGLE_STRIP-SKLEJANE TR�JK�TY
	for (float i = srodek[2]+40.0f; i < srodek[2] + 40.0f+wysokosc; i = i + 0.10f) // p�tla odpowiadaj�ca umo�liwiaj�ca przestrzenne u�o�enie sklejanych tr�jkat�w
	{
		for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 40) // p�tla odpowiadaj�ca za u�o�enie sklejanych tr�jk�t�w dooko�a podstawy walca
		{

			glVertex3f(promien * cos(alpha), promien * sin(alpha), i + 10); // wsp�rz�dne osi Z s� przypisywane z p�tli 
			glVertex3f(promien * cos(alpha), promien * sin(alpha), i);

		}
	}
	glEnd();

	rozmieszczenie = rozmieszczenie + 4 * promien;
}