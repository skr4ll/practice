#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

char* createArray(int arraySize);
void printArray(char* array, int arraySize);

int main(){
	initscr();
	raw();
	noecho();

	char* testArray = createArray(4);
	printArray(testArray, 4);

//Um das Ergebnis von printArray betrachten zu können, müssen wir das Programm am laufen halten. Hierzu wird der endlose Loop gestartet bis q gedrückt wurde.
	printw("\nPRESS q FOR QUIT\n");
	char input;
	while (true){
		input = getch();
		if (input == 'q') {
			endwin();
			return 0;
		}
		else{
			printw("PROG TERMINATED PRESS q FOR QUIT\n");
		}
	}
}

char* createArray(int arraySize){
	char* createdArray = (char*)malloc(arraySize * sizeof(char));
	char input = 'c';
	printw("\n");
	for (int i = 0; i < arraySize; i++) {
		printw("\tEnter char at array[%d] = \t", i);
		input = getch();
		printw("%c\n", input);
		createdArray[i] = input;
	}
	return createdArray;
}

void printArray(char* array, int arraySize){
	printw("\n\n\n");
	for (int i = 0; i < arraySize ; i++) {
		printw("\tValue of array[%d] = %c\n", i, array[i]);
	}
}
