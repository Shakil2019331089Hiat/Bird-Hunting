#include "iGraphics.h"
#include<iostream>
using namespace std;


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

int ind;
int kill;
char* str = "Score :";
char* scr = "00";
bool sound_on;
int tail_y;
int up_peak_x, up_peak_y;
int down_peak_x, down_peak_y;
int peak_open;
int string_potential;
int arrow_speed;
int string_x, string_y;
int obstacle_1_x, obstacle_2_x;
int obstacle_length, obstacle_width;
int ob_1_dif, ob_2_dif;
int bird_gone, bird_cycle;
int obs_1_height, obs_2_height;
bool obstacle_on;
char score[100][10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                        "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40",
                        "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", 
                        "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", 
                        "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99"};


int special_bird, gold, devil;

void environment()
{
	ind = 0;
	scr_height = 1050;
	scr_width = 1910;
	num_arrow = 5;
	dx = 5;
	dy = 2;
	bow_x = -700;
	
	arrow_x = -700;
	bow_dir = 1;
	arrow_dir = bow_dir;

	obstacle_2_x = 810;
	obstacle_length = 200;
	obstacle_width = 20;
	ob_1_dif = 10;
	ob_2_dif = 15;
	bird_cycle = 40;
	obs_1_height = 500;
	obs_2_height = 530;
	obstacle_on = true;
	gold = 3; 
	devil = 2;
}


void iDraw()
{
	iClear();
	if (bird_x == 0)
	{
		special_bird = rand() % 6;
	}
	if (special_bird == gold)
	{
		iSetColor(255, 255, 255);
		iCircle(105, 600, 70);
		iCircle(105, 600, 67);
		iSetColor(255, 255, 0);
		iText(55, 590, "Gold Bird", GLUT_BITMAP_TIMES_ROMAN_24);
		//iText(60, 570, "5 points", GLUT_BITMAP_TIMES_ROMAN_24);
		

		iSetColor(255, 255, 0);
		
		iEllipse(bird_x + 100, bird_y + 900, 70, 30);
		iEllipse(bird_x + 100, bird_y + 900, 67, 28);
		iEllipse(bird_x + 100, bird_y + 900, 64, 25);

		iEllipse(bird_x + 190, bird_y + 900, 23, 23);
		iEllipse(bird_x + 190, bird_y + 900, 21, 21);
		iEllipse(bird_x + 190, bird_y + 900, 20, 20);

		iLine(bird_x + 200, bird_y + 875, bird_x + down_peak_x + 220, bird_y + down_peak_y + 860);
		iLine(bird_x + 210, bird_y + 885, bird_x + up_peak_x + 220, bird_y + up_peak_y + 860);

		iLine(bird_x + 200, bird_y + 875, bird_x + up_peak_x + 220, bird_y + up_peak_y + 860);
		iLine(bird_x + 210, bird_y + 885, bird_x + down_peak_x + 220, bird_y + down_peak_y + 860);

		//iSetColor(255,255,0);
		iLine(bird_x + 33, bird_y + 905, bird_x + 15, bird_y + tail_y + 884);
		iLine(bird_x + 35, bird_y + 890, bird_x + 10, bird_y + tail_y + 896);
		iLine(bird_x + 33, bird_y + 905, bird_x + 12, bird_y + tail_y + 888);
		iLine(bird_x + 35, bird_y + 890, bird_x + 10, bird_y + tail_y + 892);
		iFilledCircle(bird_x + 25, bird_y + tail_y + 895, 3);

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

		iSetColor(00, 0, 255);
		iFilledEllipse(bird_x + 200, bird_y + 900, 5, 5);
	}
	else if (special_bird == devil)
	{
		iSetColor(255, 255, 255);
		iCircle(105, 600, 70);
		iCircle(105, 600, 67);
		iSetColor(255, 0, 0);
		iText(55, 589, "Devil Bird", GLUT_BITMAP_TIMES_ROMAN_24);
		//iText(55, 570, "-5 points", GLUT_BITMAP_TIMES_ROMAN_24);


		iSetColor(255, 0, 0);

		iEllipse(bird_x + 100, bird_y + 900, 70, 30);
		iEllipse(bird_x + 100, bird_y + 900, 67, 28);
		iEllipse(bird_x + 100, bird_y + 900, 64, 25);

		iEllipse(bird_x + 190, bird_y + 900, 23, 23);
		iEllipse(bird_x + 190, bird_y + 900, 21, 21);
		iEllipse(bird_x + 190, bird_y + 900, 20, 20);

		iLine(bird_x + 200, bird_y + 875, bird_x + down_peak_x + 220, bird_y + down_peak_y + 860);
		iLine(bird_x + 210, bird_y + 885, bird_x + up_peak_x + 220, bird_y + up_peak_y + 860);

		iLine(bird_x + 200, bird_y + 875, bird_x + up_peak_x + 220, bird_y + up_peak_y + 860);
		iLine(bird_x + 210, bird_y + 885, bird_x + down_peak_x + 220, bird_y + down_peak_y + 860);

		//iSetColor(255,255,0);
		iLine(bird_x + 33, bird_y + 905, bird_x + 15, bird_y + tail_y + 884);
		iLine(bird_x + 35, bird_y + 890, bird_x + 10, bird_y + tail_y + 896);
		iLine(bird_x + 33, bird_y + 905, bird_x + 12, bird_y + tail_y + 888);
		iLine(bird_x + 35, bird_y + 890, bird_x + 10, bird_y + tail_y + 892);
		iFilledCircle(bird_x + 25, bird_y + tail_y + 895, 3);

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

		iSetColor(00, 0, 255);
		iFilledEllipse(bird_x + 200, bird_y + 900, 5, 5);
	}
	else
	{

		iSetColor(10, 160, 255);
		//iRectangle(bird_x + 10, bird_y + 900, 100, 100);
		iEllipse(bird_x + 100, bird_y + 900, 70, 30);
		iEllipse(bird_x + 100, bird_y + 900, 67, 28);
		iEllipse(bird_x + 100, bird_y + 900, 64, 25);

		iEllipse(bird_x + 190, bird_y + 900, 23, 23);
		iEllipse(bird_x + 190, bird_y + 900, 21, 21);
		iEllipse(bird_x + 190, bird_y + 900, 20, 20);

		iLine(bird_x + 200, bird_y + 875, bird_x + down_peak_x + 220, bird_y + down_peak_y + 860);
		iLine(bird_x + 210, bird_y + 885, bird_x + up_peak_x + 220, bird_y + up_peak_y + 860);

		iLine(bird_x + 200, bird_y + 875, bird_x + up_peak_x + 220, bird_y + up_peak_y + 860);
		iLine(bird_x + 210, bird_y + 885, bird_x + down_peak_x + 220, bird_y + down_peak_y + 860);

		//iSetColor(255,255,0);
		iLine(bird_x + 33, bird_y + 905, bird_x + 15, bird_y + tail_y + 884);
		iLine(bird_x + 35, bird_y + 890, bird_x + 10, bird_y + tail_y + 896);
		iLine(bird_x + 33, bird_y + 905, bird_x +12, bird_y + tail_y + 888);
		iLine(bird_x + 35, bird_y + 890, bird_x + 10, bird_y + tail_y + 892);
		iFilledCircle(bird_x + 25, bird_y + tail_y + 895, 3);

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
	}


		iSetColor(255, 0, 0);
		int y1 = 80;
		int y2 = 120;
		for (int i = 0; i < num_arrow; i++)
		{
			iLine(1170, y1, 1420, y2);
			iLine(1405, y2 + 5, 1420, y2);
			iLine(1410, y2 - 10, 1420, y2);
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

			//iLine(bow_x + 1500, bow_y + 120, bow_x + 1800, bow_y + 120);
			iLine(bow_x + 1500, bow_y + 120, bow_x + string_x + 1650, bow_y + string_y + 120);
			iLine(bow_x + string_x + 1650, bow_y + string_y + 120, bow_x + 1800, bow_y + 120);
		}
		else if (bow_dir == 0)
		{
			iLine(bow_x + 1800, bow_y + 120, bow_x + 1785, bow_y + 195);
			iLine(bow_x + 1785, bow_y + 195, bow_x + 1735, bow_y + 235);
			iLine(bow_x + 1735, bow_y + 235, bow_x + 1680, bow_y + 225);
			iLine(bow_x + 1680, bow_y + 225, bow_x + 1650, bow_y + 275);
			iLine(bow_x + 1650, bow_y + 275, bow_x + 1590, bow_y + 290);
			iLine(bow_x + 1590, bow_y + 290, bow_x + 1525, bow_y + 258);

			//iLine(bow_x + 1525, bow_y + 258, bow_x + 1800, bow_y + 120);
			iLine(bow_x + 1525, bow_y + 258, bow_x + string_x + 1662, bow_y + string_y + 189);
			iLine(bow_x + string_x + 1662, bow_y + string_y + 189, bow_x + 1800, bow_y + 120);
			
		}
		else if (bow_dir == 2)
		{
			iLine(bow_x + 1500, bow_y + 120, bow_x + 1515, bow_y + 195);
			iLine(bow_x + 1515, bow_y + 195, bow_x + 1565, bow_y + 235);
			iLine(bow_x + 1565, bow_y + 235, bow_x + 1620, bow_y + 225);
			iLine(bow_x + 1620, bow_y + 225, bow_x + 1650, bow_y + 275);
			iLine(bow_x + 1650, bow_y + 275, bow_x + 1710, bow_y + 290);
			iLine(bow_x + 1710, bow_y + 290, bow_x + 1775, bow_y + 258);

			//iLine(bow_x + 1500, bow_y + 120, bow_x + 1775, bow_y + 258);
			iLine(bow_x + 1500, bow_y + 120, bow_x + string_x + 1637, bow_y + string_y + 189);
			iLine(bow_x + string_x + 1637, bow_y + string_y + 189, bow_x + 1775, bow_y + 258);
		}

	iSetColor(255, 0, 0);
	if (num_arrow >= 0)
	{
		if (arrow_dir == 1)
		{
			iLine(arrow_x + 1650, arrow_y + string_y + 120, arrow_x + 1650, arrow_y + 300);
			iLine(arrow_x + 1643, arrow_y + 293, arrow_x + 1650, arrow_y + 300);
			iLine(arrow_x + 1657, arrow_y + 293, arrow_x + 1650, arrow_y + 300);
		}
		else if (arrow_dir == 0)
		{
			iLine(arrow_x +string_x + 1662, arrow_y +string_y + 189, arrow_x + 1740, arrow_y + 350);
			iLine(arrow_x + 1732, arrow_y + 346, arrow_x + 1740, arrow_y + 350);
			iLine(arrow_x + 1744, arrow_y + 342, arrow_x + 1740, arrow_y + 350);
		}
		else if (arrow_dir == 2)
		{
			iLine(arrow_x + string_x + 1637, arrow_y + string_y + 189, arrow_x + 1560, arrow_y + 350);
			iLine(arrow_x + 1556, arrow_y + 340, arrow_x + 1560, arrow_y + 350);
			iLine(arrow_x + 1572, arrow_y + 345, arrow_x + 1560, arrow_y + 350);
		}
	}
	int write_x = 700;
	int write_y = 700;
	if (bird_y < -50 && special_bird == gold)
	{

		iSetColor(255, 255, 0);
		iFilledRectangle(write_x, write_y, 60, 15);
		iFilledRectangle(write_x, write_y - 60, 15, 60);
		iFilledRectangle(write_x, write_y - 60, 60, 15);
		iFilledRectangle(write_x + 45, write_y - 130, 15, 70);
		iFilledRectangle(write_x, write_y - 130, 60, 15);
		iFilledCircle(write_x + 15, write_y - 110, 15);

		iSetColor(0, 255, 255);
		iFilledRectangle(write_x + 130, write_y - 130, 15, 130);
		iFilledRectangle(write_x + 170, write_y - 65, 15, 65);
		iFilledRectangle(write_x + 130, write_y - 15, 55, 15);
		iFilledRectangle(write_x + 130, write_y - 65, 55, 15);


		iFilledRectangle(write_x + 210, write_y - 130, 15, 120);
		iFilledRectangle(write_x + 260, write_y - 130, 15, 120);
		iFilledRectangle(write_x + 210, write_y - 15, 65, 15);
		iFilledRectangle(write_x + 210, write_y - 130, 65, 15);


		iSetColor(0, 255, 255);
		iFilledRectangle(write_x + 310, write_y - 130, 15, 120);
		iFilledRectangle(write_x + 300, write_y - 10, 35, 10);
		iFilledRectangle(write_x + 300, write_y - 130, 35, 10);

		iFilledRectangle(write_x + 360, write_y - 130, 15, 130);
		iFilledRectangle(write_x + 420, write_y - 130, 15, 130);
		iLine(write_x + 360, write_y, write_x + 420, write_y - 130);
		iLine(write_x + 375, write_y, write_x + 435, write_y - 130);

		iFilledRectangle(write_x + 490, write_y - 130, 15, 120);
		iFilledRectangle(write_x + 455, write_y - 15, 80, 15);


		iFilledRectangle(write_x + 550, write_y - 15, 50, 15);
		iFilledRectangle(write_x + 550, write_y - 75, 15, 65);
		iFilledRectangle(write_x + 550, write_y - 75, 60, 15);
		iFilledRectangle(write_x + 550 + 45, write_y - 130, 15, 60);
		iFilledRectangle(write_x + 560, write_y - 130, 50, 15);


		iFilledRectangle(write_x + 550, write_y - 130, 15, 30);
		iFilledRectangle(write_x + 595, write_y - 30, 15, 30);
	}

	if (num_arrow < 0)
	{
		iText(870, 600, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (num_arrow == 0)
	{
		iSetColor(rand() % 255, rand() % 255, rand() % 255);
		iText(870, 80, "LAST ARROW", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	iSetColor(0, 255,255);
	iText(1600, 1010, str, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1680, 1010, score[kill], GLUT_BITMAP_TIMES_ROMAN_24);

	if (num_arrow > -1)
	{
		iText(50, 1010,"Birds remaininng : " , GLUT_BITMAP_TIMES_ROMAN_24);
		iText(240, 1010, score[bird_cycle - bird_gone], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 1010,"Arrow remaininng : " , GLUT_BITMAP_TIMES_ROMAN_24);
		iText(810, 1010, score[num_arrow], GLUT_BITMAP_TIMES_ROMAN_24);

	}


	// obstacle part ///////////////////////////////////////////////////
	/**iSetColor(255, 50, 30);
	iFilledRectangle(obstacle_1_x, obs_1_height, obstacle_length, obstacle_width);
	iFilledRectangle(obstacle_2_x, obs_2_height, obstacle_length, obstacle_width);

	**/
	
	/**if (arrow_dir == 0)
	{
		if (arrow_y + 350 >= obs_1_height && arrow_y + 350 <= obs_1_height + 30 && obstacle_1_x - 1040 < arrow_x + 700 && obstacle_1_x - 840 > arrow_x + 700)
		{
			iText(900, 700, "y same", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (arrow_y + 350 >= obs_2_height && arrow_y + 350 <= obs_2_height + 30 && obstacle_2_x - 1040 < arrow_x + 700 && obstacle_2_x - 840 > arrow_x + 700)
		{
			iText(900, 700, "y same", GLUT_BITMAP_TIMES_ROMAN_24);
		}

		if (ob_1_dif > 0)
		{
			if (arrow_y + 350 >= obs_1_height + 50  && arrow_y + 350 <= obs_1_height + 150 && obstacle_1_x - 800 < arrow_x + 700 && obstacle_1_x - 770 > arrow_x + 700)
			{
				iText(900, 700, "y same", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			if (arrow_y + 350 >= obs_2_height && arrow_y + 189 < obs_2_height && obstacle_2_x - 950 < arrow_x + 700 && obstacle_2_x - 750 > arrow_x + 700)
			{
				iText(900, 700, "y same", GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
		else
		{
			if (arrow_y + 350 >= obs_1_height && arrow_y + 189 < obs_1_height && obstacle_1_x - 950 < arrow_x + 700 && obstacle_1_x - 750 > arrow_x + 700)
			{
				iText(900, 700, "y same", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			if (arrow_y + 350 >= obs_2_height && arrow_y + 189 < obs_2_height && obstacle_2_x - 950 < arrow_x + 700 && obstacle_2_x - 750 > arrow_x + 700)
			{
				iText(900, 700, "y same", GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
	}
	 cout << obstacle_1_x - 950 << " " << arrow_x + 700 << endl;
	 **/
}

/**void obstacle()
{
	obstacle_1_x += ob_1_dif;
	obstacle_2_x += ob_2_dif;
	if (obstacle_1_x >= 1710 || obstacle_1_x <= 0)
	{
		ob_1_dif *= -1;
	}
	if (obstacle_2_x >= 1710 || obstacle_2_x <= 0)
	{
		ob_2_dif *= -1;
	}
}

void obstacle_hit()
{
	if (arrow_dir == 1)
	{
		if (arrow_y + 300 >= obs_1_height && arrow_y + 120 < obs_1_height && obstacle_1_x - 950 < arrow_x + 700 && obstacle_1_x - 750 > arrow_x + 700)
		{
			arrow_y = scr_height + 201;
		}
		if (arrow_y + 300 >= obs_2_height && arrow_y + 120 < obs_2_height && obstacle_2_x - 950 < arrow_x + 700 && obstacle_2_x - 750 > arrow_x + 700)
		{
			arrow_y = scr_height + 201;
		}
	}
	
}**/

void string_condition()
{
	if (arrow_y + 200 > scr_height)
	{
		string_potential = 0;
	}


	if (string_potential == 0)
	{
		arrow_speed = 3;
		if (arrow_y > 150)
		{
			arrow_y  = scr_height + 200;
		}


		string_x = 0;
		string_y = 0;
	}
	else if (string_potential == 1)
	{
		arrow_speed = 10;

		if (bow_dir == 0)
		{
			string_x = -15;
			string_y = -25;
		}
		else if (bow_dir == 1)
		{
			string_x = 0;
			string_y = -20;
		}
		else if (bow_dir == 2)
		{
			string_x = 15;
			string_y = -25;
		}
	}
	else if (string_potential == 2)
	{
		arrow_speed = 20;

		if (bow_dir == 0)
		{
			string_x = -30;
			string_y = -50;
		}
		else if (bow_dir == 1)
		{
			string_x = 0;
			string_y = -40;
		}
		else if (bow_dir == 2)
		{
			string_x = 30;
			string_y = -50;
		}
	}

}
void peak()
{
	if (peak_open)
	{
		down_peak_y = -5;
		down_peak_x = -10;
		up_peak_y = 15;
		up_peak_x = 10;
	}
	else
	{
		down_peak_y = 0;
		down_peak_x = 0;
		up_peak_y = 0;
		up_peak_x = 0;
	}
}

void tail()
{
	if (bird_x % 80 < 40)
	{
		tail_y = -2;
	}
	else
	{
		tail_y = 1;
	}
}

void birds_path_hit_or_not()
{
	if (!(arrow_x + 1500 >= bird_x + 50 || arrow_x + 1500 <= bird_x - 120) && (arrow_y + 300 >= bird_y + 900 && arrow_y + 300 <= bird_y + 950) && (arrow_dir == 1))
	{
		obstacle_on = false;
		peak_open = 0;
		bird_y -= 10;
		arrow_y -= 10;
		ind++;
		
		if (bird_y < -1000)
		{
			if (special_bird == gold)
			{
				kill += 5;
			}
			else if (special_bird == devil)
			{
				num_arrow--;
			}
			else
			{
				kill++;
			}

			bird_gone++;
			
			obstacle_on = true;
			ind = 0;
			dx++;
			bird_x = 0;
			bird_y = 0;
			arrow_y = 0;
			arrow_x = -700;
			release_arrow = 0;
			string_potential = 0;
		}
	}
	else if (!(arrow_x + 1590 >= bird_x + 80 || arrow_x + 1590 <= bird_x - 100) && (arrow_y + 350 >= bird_y + 900 && arrow_y + 350 <= bird_y + 950) && (arrow_dir == 0))
	{
		obstacle_on = false;
		peak_open = 0;
		bird_y -= 10;
		arrow_y -= 10;
		//bird_x += 5;
		//arrow_x += 5;
		ind++;

		if (bird_y < -1000)
		{
			if (special_bird == gold)
			{
				kill += 5;
			}
			else if (special_bird == devil)
			{
				num_arrow--;
			}
			else
			{
				kill++;
			}

			bird_gone++;
			
			obstacle_on = true;
			ind = 0; 
			dx++;
			bird_x = 0;
			bird_y = 0;
			arrow_y = 0;
			arrow_x = -700;
			release_arrow = 0;
			string_potential = 0;
		}
	}
	else if (!(arrow_x + 1500 >= bird_x + 140 || arrow_x + 1500 <= bird_x - 50) && (arrow_y + 350 >= bird_y + 890 && arrow_y + 350 <= bird_y + 910) && (arrow_dir == 2))
	{
		obstacle_on = false;
		peak_open = 0;
		bird_y -= 10;
		arrow_y -= 10;
		//bird_x -= 5;
		//arrow_x -= 5;
		ind++;
		if (bird_y < -1000)
		{
			if (special_bird == gold)
			{
				kill += 5;
			}
			else if (special_bird == devil)
			{
				num_arrow--;
			}
			else
			{
				kill++;
			}

			bird_gone++;
			
			obstacle_on = true;
			ind = 0;
			dx++;
			bird_x = 0;
			bird_y = 0;
			arrow_y = 0;
			arrow_x = -700;
			release_arrow = 0;
			string_potential = 0;
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
		if (bird_x >= 1900)
		{
			bird_gone++;
			if (bird_gone >= bird_cycle)
			{
				num_arrow = -1;
			}
			bird_y = 0;
			bird_x = 0;
			
		}

		if (arrow_y == 0)
		{
			arrow_dir = bow_dir;
		}
		if (arrow_dir == 1 && release_arrow == 1 && arrow_y <= scr_height)
		{
			arrow_y += arrow_speed - arrow_y / 200;
		}
		if (arrow_dir == 0 && release_arrow == 1 && arrow_y <= scr_height)
		{
			arrow_y += arrow_speed - arrow_y / 200;
			arrow_x += (arrow_speed / 2) + arrow_y / 100;
		}
		if (arrow_dir == 2 && release_arrow == 1 && arrow_y <= scr_height)
		{
			arrow_y += arrow_speed - arrow_y / 200;
			arrow_x -= (arrow_speed / 2) + arrow_y / 100;
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
}

void sound()
{

	if (ind == 1)
	{
		PlaySound(0, 0, 0);
		PlaySound("Music//6.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (bird_x == 0)
	{
		
		//PlaySound("Music//running.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (bird_x % 1000 > 200 && bird_x % 1000 < 250)
	{
			peak_open = 1;
			PlaySound(0, 0, 0);
			PlaySound("Music//hawk.wav", NULL, SND_LOOP | SND_ASYNC);
		
	}
	else if (bird_x % 1000 > 500 && bird_x % 1000 < 550)
	{
			peak_open = 0;
			PlaySound(0, 0, 0);
			PlaySound("Music//running.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (num_arrow < 0)
	{
		PlaySound(0, 0, 0);
	}
}
void change()
{
	birds_path_hit_or_not();
	if (num_arrow > -1)
	{
		//sound();
		peak();
		tail();
		string_condition();
		if (obstacle_on)
		{
			//obstacle_hit();
		}
	}
	//obstacle();
}




void iMouseMove(int mx, int my)
{
	
}

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




void iKeyboard(unsigned char key)
{
	if (key == 'r')
	{
		release_arrow = 1;
	}
	
	
}


void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
		if (bow_dir == 2)
		{
			bow_dir = 1;
		}
		else
		{
			bow_dir = 0;
		}
		

	}
	if (key == GLUT_KEY_LEFT)
	{
		if (bow_dir == 0)
		{
			bow_dir = 1;
		}
		else
		{
			bow_dir = 2;
		}
		
	}
	if (key == GLUT_KEY_UP)
	{
		if (arrow_y == 0)
		{
			if (string_potential == 2)
			{
				string_potential = 1;
			}
			else
			{
				string_potential = 0;
			}
		}
	}
	if (key == GLUT_KEY_DOWN)
	{
		if (arrow_y == 0)
		{

			if (string_potential == 0)
			{
				string_potential = 1;
			}
			else
			{
				string_potential = 2;
			}
		}
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}


int main()
{
	environment();
	iSetTimer(16, change);
	
	//PlaySound("Music//running.wav", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(scr_width, scr_height, "Birds Hunting");
	
	iStart();
	return 0;
}