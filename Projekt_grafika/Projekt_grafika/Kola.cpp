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
	glBegin(GL_TRIANGLE_FAN); // rozpoczêcie wykonywania funkcji GL_TRIANGLE_FAN
	glVertex3f(srodek[0],srodek[1], srodek[2]); // ustawienie wspó³rzêdnych œrodka podstawy
	glColor3f(0.0f, 1.0f, 0.0f); // ustawienie koloru
	for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 40) // pêtla s³uz¹ca do rysowania górnej podstawy walca, podstawa sk³ada siê z czterdziestu odcinków
	{
		glVertex3f( promien * cos(alpha), promien * sin(alpha), srodek[2]);

	}
	alpha = 0.0; // wyzerowanie wartoœci k¹ta, potrzebne, poniewa¿ wczeœniejsza pêtla po przejœciu po ca³ym obwodzie ko³a ustawi³a wartoœæ równ¹ dwukrotnoœci liczby pi
	glVertex3f(promien * cos(alpha), promien * sin(alpha), srodek[2]);
	glEnd(); // koniec wykonywania funkcji GL_TRIANGLE_FAN
	glColor3f(1.0f, 0.0f, 0.0f); //ustawienie koloru
	glBegin(GL_TRIANGLE_FAN); // rozpoczêcie wykonywania funkcji GL_TRIANGLE_FAN
	glVertex3f(srodek[0], srodek[1], srodek[2] + wysokosc); // ustawienie wspó³rzêdnych œrodka podstawy
	glColor3f(0.0f, 0.0f, 1.0f); // ustawienie koloru
	for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 40) // pêtla s³uz¹ca do rysowania górnej podstawy walca, podstawa sk³ada siê z czterdziestu odcinków
	{
		glVertex3f(promien * cos(alpha), promien * sin(alpha), srodek[2] + wysokosc);


	}
	alpha = 0.0; // wyzerowanie wartoœci k¹ta, potrzebne, poniewa¿ wczeœniejsza pêtla po przejœciu po ca³ym obwodzie ko³a ustawi³a wartoœæ równ¹ dwukrotnoœci liczby pi
	glVertex3f(promien * cos(alpha), promien * sin(alpha), srodek[2] + wysokosc);
	glEnd(); //koniec wykonywania funkcji GL_TRIANGLE_FAN
	glBegin(GL_TRIANGLE_STRIP);// rozpoczêcie wykonywania funkcji GL_TRIANGLE_STRIP-SKLEJANE TRÓJK¥TY
	for (float i = srodek[2]; i < srodek[2] + wysokosc; i = i + 0.10f) // pêtla odpowiadaj¹ca umo¿liwiaj¹ca przestrzenne u³o¿enie sklejanych trójkatów
	{
		for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 40) // pêtla odpowiadaj¹ca za u³o¿enie sklejanych trójk¹tów dooko³a podstawy walca
		{

			glVertex3f(promien * cos(alpha), promien * sin(alpha), i + 10); // wspórzêdne osi Z s¹ przypisywane z pêtli 
			glVertex3f(promien * cos(alpha), promien * sin(alpha), i);

		}
	}
	glEnd(); // koniec wykonywania funkcji GL_TRIANGLE_STRIP
	alpha = 0.0;
	glColor3f(1.0f, 0.0f, 0.0f); // ustawienie koloru
	glBegin(GL_TRIANGLE_FAN); // rozpoczêcie wykonywania funkcji GL_TRIANGLE_FAN
	glVertex3f(srodek[0], srodek[1], srodek[2]+40.0f); // ustawienie wspó³rzêdnych œrodka podstawy
	glColor3f(0.0f, 1.0f, 0.0f); // ustawienie koloru
	for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 40) // pêtla s³uz¹ca do rysowania górnej podstawy walca, podstawa sk³ada siê z czterdziestu odcinków
	{
		glVertex3f(promien * cos(alpha), promien * sin(alpha), srodek[2] + 40.0f);

	}
	alpha = 0.0; // wyzerowanie wartoœci k¹ta, potrzebne, poniewa¿ wczeœniejsza pêtla po przejœciu po ca³ym obwodzie ko³a ustawi³a wartoœæ równ¹ dwukrotnoœci liczby pi
	glVertex3f(promien * cos(alpha), promien * sin(alpha), (srodek[2]) + 40.0f);
	glEnd(); // koniec wykonywania funkcji GL_TRIANGLE_FAN
	glColor3f(1.0f, 0.0f, 0.0f); //ustawienie koloru
	glBegin(GL_TRIANGLE_FAN); // rozpoczêcie wykonywania funkcji GL_TRIANGLE_FAN
	glVertex3f(srodek[0], srodek[1], srodek[2] + wysokosc+40.0f); // ustawienie wspó³rzêdnych œrodka podstawy
	glColor3f(0.0f, 0.0f, 1.0f); // ustawienie koloru
	for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 40) // pêtla s³uz¹ca do rysowania górnej podstawy walca, podstawa sk³ada siê z czterdziestu odcinków
	{
		glVertex3f(promien * cos(alpha), promien * sin(alpha), srodek[2] + wysokosc + 40.0f);


	}
	alpha = 0.0; // wyzerowanie wartoœci k¹ta, potrzebne, poniewa¿ wczeœniejsza pêtla po przejœciu po ca³ym obwodzie ko³a ustawi³a wartoœæ równ¹ dwukrotnoœci liczby pi
	glVertex3f(promien * cos(alpha), promien * sin(alpha), srodek[2] + wysokosc + 40.0f);
	glEnd(); //koniec wykonywania funkcji GL_TRIANGLE_FAN
	glBegin(GL_TRIANGLE_STRIP);// rozpoczêcie wykonywania funkcji GL_TRIANGLE_STRIP-SKLEJANE TRÓJK¥TY
	for (float i = srodek[2]+40.0f; i < srodek[2] + 40.0f+wysokosc; i = i + 0.10f) // pêtla odpowiadaj¹ca umo¿liwiaj¹ca przestrzenne u³o¿enie sklejanych trójkatów
	{
		for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 40) // pêtla odpowiadaj¹ca za u³o¿enie sklejanych trójk¹tów dooko³a podstawy walca
		{

			glVertex3f(promien * cos(alpha), promien * sin(alpha), i + 10); // wspórzêdne osi Z s¹ przypisywane z pêtli 
			glVertex3f(promien * cos(alpha), promien * sin(alpha), i);

		}
	}
	glEnd();

	rozmieszczenie = rozmieszczenie + 4 * promien;
}