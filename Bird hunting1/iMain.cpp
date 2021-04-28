#include "iGraphics.h"
#include<iostream>
using namespace std;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

int scr_height, scr_width;
int bird_x, bird_y;
int r, g, b;
int dx, dy;
int bow_x, bow_y;
int bow_dir;
int arrow_dir;
int arrow_x, arrow_y;
int release_arrow;
int num_arrow;
char score[100][3];
int ind;
void environment()
{
	scr_height = 1050;
	scr_width = 1910;
	num_arrow = 5;
	dx = 5;
	dy = 2;
	bow_x = -700;
	//arrow_x = 0;
	arrow_x = -700;
	bow_dir = 1;
	arrow_dir = bow_dir;
	

}

void iDraw()
{
	iClear();
	

		iSetColor(10, 160, 255);
		//iRectangle(bird_x + 10, bird_y + 900, 100, 100);
		iEllipse(bird_x + 100, bird_y + 900, 70, 30);
		iEllipse(bird_x + 190, bird_y + 900, 23, 23);
		iLine(bird_x + 200, bird_y + 875, bird_x + 220, bird_y + 860);
		iLine(bird_x + 210, bird_y + 885, bird_x + 220, bird_y + 860);
		iSetColor(255, 255, 0);
		if (bird_x % 200 < 100)
		{
			iLine(bird_x + 70, bird_y + 900, bird_x + 30, bird_y + 850);
			iLine(bird_x + 140, bird_y + 900, bird_x + 30, bird_y + 850);
		}
		else
		{
			iLine(bird_x + 70, bird_y + 900, bird_x + 30, bird_y + 950);
			iLine(bird_x + 140, bird_y + 900, bird_x + 30, bird_y + 950);
		}
		if (bird_x % 200 < 100)
		{
			iLine(bird_x + 70, bird_y + 890, bird_x + 100, bird_y + 850);
			iLine(bird_x + 140, bird_y + 890, bird_x + 100, bird_y + 850);
		}
		else
		{
			iLine(bird_x + 80, bird_y + 910, bird_x + 100, bird_y + 950);
			iLine(bird_x + 130, bird_y + 910, bird_x + 100, bird_y + 950);
		}

		iSetColor(200, 100, 150);
		iFilledEllipse(bird_x + 200, bird_y + 900, 5, 5);



		iSetColor(255, 0, 0);
		int y1 = 40;
		int y2 = 60;
		for (int i = 0; i < num_arrow; i++)
		{
			iLine(70, y1, 220, y2);
			iLine(200, y2 + 5, 220, y2);
			iLine(205, y2 - 10, 220, y2);
			y1 += 20;
			y2 += 20;
		}
		/**iLine(70, 60, 220, 80);
		iLine(200, 85, 220, 80);
		iLine(205, 70, 220, 80);

		iLine(70, 80, 220, 100);
		iLine(200, 105, 220, 100);
		iLine(205, 90, 220, 100);

		iLine(70, 100, 220, 120);
		iLine(200, 125, 220, 120);
		iLine(205, 110, 220, 120);

		iLine(70, 120, 220, 140);
		iLine(200, 145, 220, 140);
		iLine(205, 130, 220, 140);**/



		iSetColor(255, 255, 255);
		if (bow_dir == 1)
		{

			iLine(bow_x + 1500, bow_y + 120, bow_x + 1550, bow_y + 180);
			iLine(bow_x + 1550, bow_y + 180, bow_x + 1600, bow_y + 190);
			iLine(bow_x + 1600, bow_y + 190, bow_x + 1650, bow_y + 160);
			iLine(bow_x + 1650, bow_y + 160, bow_x + 1700, bow_y + 190);
			iLine(bow_x + 1700, bow_y + 190, bow_x + 1750, bow_y + 180);
			iLine(bow_x + 1750, bow_y + 180, bow_x + 1800, bow_y + 120);
			iLine(bow_x + 1500, bow_y + 120, bow_x + 1800, bow_y + 120);


		}
		else if (bow_dir == 0)
		{

			iLine(bow_x + 1800, bow_y + 120, bow_x + 1785, bow_y + 195);
			iLine(bow_x + 1785, bow_y + 195, bow_x + 1735, bow_y + 235);
			iLine(bow_x + 1735, bow_y + 235, bow_x + 1680, bow_y + 225);
			iLine(bow_x + 1680, bow_y + 225, bow_x + 1650, bow_y + 275);
			iLine(bow_x + 1650, bow_y + 275, bow_x + 1590, bow_y + 290);
			iLine(bow_x + 1590, bow_y + 290, bow_x + 1525, bow_y + 258);
			iLine(bow_x + 1525, bow_y + 258, bow_x + 1800, bow_y + 120);


		}
		else if (bow_dir == 2)
		{

			iLine(bow_x + 1500, bow_y + 120, bow_x + 1515, bow_y + 195);
			iLine(bow_x + 1515, bow_y + 195, bow_x + 1565, bow_y + 235);
			iLine(bow_x + 1565, bow_y + 235, bow_x + 1620, bow_y + 225);
			iLine(bow_x + 1620, bow_y + 225, bow_x + 1650, bow_y + 275);
			iLine(bow_x + 1650, bow_y + 275, bow_x + 1710, bow_y + 290);
			iLine(bow_x + 1710, bow_y + 290, bow_x + 1775, bow_y + 258);
			iLine(bow_x + 1500, bow_y + 120, bow_x + 1775, bow_y + 258);


		}
	if (num_arrow >= 0)
	{
		if (arrow_dir == 1)
		{
			iLine(arrow_x + 1650, arrow_y + 120, arrow_x + 1650, arrow_y + 300);
			iLine(arrow_x + 1643, arrow_y + 293, arrow_x + 1650, arrow_y + 300);
			iLine(arrow_x + 1657, arrow_y + 293, arrow_x + 1650, arrow_y + 300);
		}
		else if (arrow_dir == 0)
		{



			iLine(arrow_x + 1662, arrow_y + 189, arrow_x + 1740, arrow_y + 350);
			iLine(arrow_x + 1732, arrow_y + 346, arrow_x + 1740, arrow_y + 350);
			iLine(arrow_x + 1744, arrow_y + 342, arrow_x + 1740, arrow_y + 350);
		}
		else if (arrow_dir == 2)
		{


			iLine(arrow_x + 1637, arrow_y + 189, arrow_x + 1560, arrow_y + 350);
			iLine(arrow_x + 1556, arrow_y + 340, arrow_x + 1560, arrow_y + 350);
			iLine(arrow_x + 1572, arrow_y + 345, arrow_x + 1560, arrow_y + 350);
		}
	}
	if (num_arrow < 0)
	{
		iText(800, 600, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//iText(800, 600, "30", GLUT_BITMAP_TIMES_ROMAN_24);
	cout << bird_x  << " " << bird_y  << endl;
	if (!(arrow_x + 1500 >= bird_x + 50 || arrow_x + 1500 <= bird_x - 100) && (arrow_y + 0 <= bird_y + 900 && arrow_y + 300 >= bird_y + 900))
	{
		iText(800, 600, "wow", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	/**if (arrow_y + 120 <= bird_y + 900 && arrow_y + 300 >= bird_y + 900)
	{
		iText(800, 400, "Y same", GLUT_BITMAP_TIMES_ROMAN_24);
	}**/
}



void change()
{
	
	if (ind == 1)
	{
		PlaySound(0, 0, 0);
		PlaySound("Music//6.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (!(arrow_x + 1500 >= bird_x + 50 || arrow_x + 1500 <= bird_x - 100) && (arrow_y + 120 <= bird_y + 900 && arrow_y + 300 >= bird_y + 900))
	{
		bird_y -= 10;
		arrow_y -= 10; 
		ind++;
		
		if (bird_y < -1000)
		{
			ind = 0;
			PlaySound(0,0,0);
			PlaySound("Music//2.wav", NULL, SND_LOOP | SND_ASYNC);
			bird_x = 0;
			bird_y = 0;
			arrow_y = 0;
			arrow_x = -700;
			release_arrow = 0;
		}
	}
	else
	{
		bird_x += dx;
		if (bird_x % 200 < 100)
		{
			bird_y += dy;
		}
		else
		{
			bird_y -= dy;
		}
		if (bird_x == 1900)
		{
			bird_y = 0;
			bird_x = 0;
		}

		if (arrow_y == 0)
		{
			arrow_dir = bow_dir;
		}
		if (arrow_dir == 1 && release_arrow == 1 && arrow_y <= scr_height)
		{
			arrow_y += 10 - arrow_y / 200;
		}
		if (arrow_dir == 0 && release_arrow == 1 && arrow_y <= scr_height)
		{
			arrow_y += 10 - arrow_y / 200;
			arrow_x += 4 + arrow_y / 100;
		}
		if (arrow_dir == 2 && release_arrow == 1 && arrow_y <= scr_height)
		{
			arrow_y += 10 - arrow_y / 200;
			arrow_x -= 4 + arrow_y / 100;
		}

		if (arrow_y + 100 > scr_height)
		{
			//arrow_dir = bow_dir;
			num_arrow -= 1;
			release_arrow = 0;
			arrow_y = 0;
			arrow_x = -700;
		}
	}
	/**if (y + 50 == 800)
	{
		dy *= (-1);
	}
	else if ((y == 0) && (x >= bx && x <= bx + 150))
	{
		dy *= (-1);
	}**/


}

/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		release_arrow = 1;
	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
		bow_dir = 0;
	}
	if (key == GLUT_KEY_LEFT)
	{
		bow_dir = 2;
	}
	if (key == GLUT_KEY_UP)
	{
		
		release_arrow = 1;
	}
	if (key == GLUT_KEY_DOWN)
	{
		bow_dir = 1;
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}


int main()
{
	environment();
	iSetTimer(16, change);
	PlaySound("Music//2.wav", NULL, SND_LOOP | SND_ASYNC);
	
	iInitialize(scr_width, scr_height, "Birds Hunting");
	///updated see the documentations
	iStart();
	return 0;
}