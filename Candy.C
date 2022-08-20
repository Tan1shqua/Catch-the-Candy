/* 	Author: Tanishqua Bansal
	DOC: 	24th Dec 2021
	Objective: My first candy game.
*/
#include<stdio.h>
#include<conio.h>
void main()
{
	int box_x=37,box_y=23,candy_x=40,candy_y=2;
	int diff,score=0,life=3;
	char input; //input variables

	start:
	textbackground(GREEN);
	clrscr();
	textcolor(YELLOW);

	gotoxy(60,5);
	cprintf("score:%d",score);
	gotoxy(60,6);
	cprintf("Life:%d",life);

	gotoxy(candy_x,candy_y);

	cprintf("0");
	gotoxy(box_x,box_y);
	cprintf("#     #");
	gotoxy(box_x,box_y+1);
	cprintf("#######");

	if(kbhit())
	{
		input=getch();
		switch(input)
		{
		case 'a':if(box_x>20)
			 {box_x--;}
			 break;
		case 'd':if(box_x<54)
			 {box_x++;}
			 break;
		case 'x':exit(0);
		}//end of switch statement
	}//end of if statement
	candy_y++;
		if(candy_y==22)
		{
			diff=candy_x-box_x;
			if(diff>0 && diff<6)
			{
				score++;
				if(score==5)
				{
					textbackground(WHITE);
					clrscr();
					gotoxy(30,13);
					textcolor(BLUE);
					cprintf("MISSION ACCOMPLISHED");
					delay(2000);
					getch();
					exit(0);
				}
			}
			else
			{
				life--;
				if(life==0)
				{
					textbackground(WHITE);
					clrscr();
					gotoxy(36,13);
					textcolor(RED);
					cprintf("GAME OVER");
					delay(2000);
					getch();
					exit(0);
				}
			}
			candy_x=rand()%40+20;
			candy_y=2;
		}
	delay(200);
	goto start;
}//End of main