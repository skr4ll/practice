/* Perform a binary Search on the test Array and print each step 
 * colouring the current middle in red.
 */
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

int binSearch(char data[], int length, char target);
void printSearch(char data[], int left, int middle, int right);

void printSearch(char data[], int left, int middle, int right){
	start_color();
	use_default_colors();
	init_pair(1, COLOR_RED, -1);
	printw("CURRENT ARRAY:( ");
		
		for (int i =0; i<=right; i++) {
			if(i >= left && i <= right){
				if(i == middle){
					attron(COLOR_PAIR(1));
					printw(" %c ", data[i]);
					attroff(COLOR_PAIR(1));
				}
				else{
					printw(" %c ", data[i]);
				}
			}
		refresh();
		usleep(100000);
		}
		printw(" )\n");
}

int binSearch(char data[], int length, char target){
	int left = 0,  middle = 0, right = length - 1;
	while(left <= right){
		middle = left + (right - left) / 2;
		printSearch(data, left, middle, right);	
		if (data[middle] == target)
			return middle;
		if(data[middle] < target)
			left = middle + 1;
		else
			right = middle;
	}
	return -1;
}
int main(){
	initscr();
	raw();
	char target = ' ';
	char testArray[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	while (true){
		if((target = getch())){
			clear();
			refresh();
		}
		printw("\n");
		if(target == 'q'){
			endwin();
			return 0;
		}
		int result = binSearch(testArray, 10, target);
		printw("Char at testArray[%d]\n", result);
	}
}
