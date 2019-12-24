
//potzebne zmienne globalne:

	// x i y naszej planety
	float xForEarth, zForEarth;
	// licznik pozycji planety
	float counterForEarth = 0;
	const float DEG2RAD = 3.14159 / 180.0;

		
***********************************************
//Do dodania w funkcji render scene:

	// Rysowanie orbity w formie punktów
		glBegin(GL_POINTS);
    for (int i=0; i < 360; i++) 
    { 
		//const float DEG2RAD = 3.14159/180.0;
        float degInRad = i*DEG2RAD;  
        glVertex3f(cos(degInRad)*18.0, 0.0f, sin(degInRad)*5.3); 
    }
    glEnd();
   

	// Kontrola prêdkoœci poruszania siê planety. Im bli¿ej drugiego ogniwa tym szybciej siê porusza.
	if (counterForEarth > 359)
		counterForEarth = 0;//reset to 0 when becomes 360
	if (counterForEarth > 180 && counterForEarth <359)
		counterForEarth += 0.5 + ((360 - counterForEarth)/ 180);
	else
		counterForEarth += 0.5+(counterForEarth / 180) ;



	xForEarth = cos(counterForEarth*DEG2RAD)*18.0f;//nowe x planety
	zForEarth = sin(counterForEarth*DEG2RAD)*5.3f;//nowe y planety
	glPushMatrix();
	glTranslatef(xForEarth, 0.0f, zForEarth); // Zmiana pozycji planety
	glRotatef(30.0f, 0.5f, 1.0f, 1.0f); // Przechylenie planety.
	drawEgg(); // Funkcja rysuj¹ca obiekt
	glPopMatrix();
	