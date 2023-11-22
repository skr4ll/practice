/* Program to practice and try out Ncurses functions
 * currently it switches the colour of the text depending on what key is pressed
**/

#include <stdio.h>
#include <ncurses.h>
int selectColour(char c);

int main(){
	char test = 'a';
	
	initscr();	//Cursemodus starten
	raw();		//Raw ermöglicht direkten Zugriff auf Usereingabe, ohne auf new line zu warten
	noecho();	//noecho unterdrückt die direkte Wiedergabe des Inputs
	
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);

	while(true){
		if(test == 'q'){	//Ist die Eingabe q, beenden wir das Programm
			endwin();
			return 0;
		}
		if((test = getch())){	
			clear();				//Am Anfang das Fenster leeren, ansonsten werden Eingaben aneinander gereiht
			refresh();
			
			attron(COLOR_PAIR(selectColour(test)));
			printw("Current Pair NR: %d The Key pressed is: the %c character",selectColour(test), test);	//Eingabe auf Bildschirm wiedergeben
			refresh();
			attroff(COLOR_PAIR(selectColour(test)));				
		}
	}
}
int selectColour(char c){
	int selectedPair = 1;
	switch (c) {
		case 'a':
		case 's':
		case 'd':
		return selectedPair = 2;

		case 'y':
		case 'x':
		case 'c':
		return selectedPair = 3;

		case 'w':
		case 'e':
		case 'r':
		case 't':
		return selectedPair = 4;
		
		case 'f':
		case 'g':
		case 'h':
		case 'j':
		return selectedPair = 5;

		default:
		return selectedPair;
	}	
}
