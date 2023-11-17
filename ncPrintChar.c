#include <stdio.h>
#include <ncurses.h>

int main(){
	char test = 'a';
	initscr();	//Cursemodus starten
	raw();		//Raw ermöglicht direkten Zugriff auf Usereingabe, ohne auf new line zu warten
	noecho();	//noecho unterdrückt die direkte Wiedergabe des Inputs
	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);
	while(true){
		if(test == 'q'){	//Ist die Eingabe q, beenden wir das Programm
			endwin();
			return 0;
		}
		if(test = getch()){	
			clear();				//Am Anfang das Fenster leeren, ansonsten werden Eingaben aneinander gereiht
			refresh();
			attron(COLOR_PAIR(1));
			printw("Key pressed: %c", test);	//Eingabe auf Bildschirm wiedergeben
			refresh();
			attroff(COLOR_PAIR(1));				
		}
	}
}

