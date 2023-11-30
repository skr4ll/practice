#include <stdio.h>

struct stack{
	int top;
	int stackSize;
	char items[300];
};
typedef struct stack Stack;

char pop(Stack* sta);
void push(Stack* sta, char item);
void peek(Stack* sta);

char pop(Stack* sta){
	char topItem;  
	if(sta->top != 0){
		topItem = sta->items[sta->top];
		sta->top--;
	}
	else{
		topItem = sta->items[sta->top];
		sta->items[sta->top] = ' ';
		sta->top--;
	}
	return topItem;
}

void push(Stack* sta, char item){
	if(sta->top == 0){
		sta->items[0] = item;
		sta->top++;
	}
	else if(sta->stackSize >= sta->top + 1){
		sta->items[sta->top + 1] = item;
		sta->top++;
	}
	else{
		printf("STACK FULL\n");
		return;
	}
}

void peek(Stack* sta){
	printf("Peeking at top item.\nThe Top item is: %c\n", sta->items[sta->top]);
}

int main(){

	Stack testStack;
	testStack.stackSize = 10;
	testStack.top = 0;
	Stack* ptrToStack = &testStack;
	char currentTop;
	
	char item = 'a';
	printf("ADDED %c at stacktop of %i\n", item, testStack.top);
	push(ptrToStack, item);
	printf("New Stacktop is: %i\n\n", testStack.top);
	
	item = 'b';
	printf("ADDED %c at stacktop of %i\n", item, testStack.top);
	push(ptrToStack, item);
	printf("New Stacktop is: %i\n\n", testStack.top);
	
	item = 'c';
	printf("ADDED %c at stacktop of %i\n", item, testStack.top);
	push(ptrToStack, item);
	printf("New Stacktop is: %i\n\n", testStack.top);
	
	item = 'd';
	printf("ADDED %c at stacktop of %i\n", item, testStack.top);
	push(ptrToStack, item);
	printf("New Stacktop is: %i\n\n", testStack.top);
	
	currentTop = pop(ptrToStack);
	printf("Top item was: %c and is now poped\n", currentTop);
	printf("New Stacktop is: %i\n\n", testStack.top);
	
	item = 'z';
	printf("ADDED %c at stacktop of %i\n", item, testStack.top);
	push(ptrToStack, item);
	printf("New Stacktop is: %i\n\n", testStack.top);
	
	currentTop = pop(ptrToStack);
	printf("Top item was: %c and is now poped\n", currentTop);
	printf("New Stacktop is: %i\n\n", testStack.top);

	peek(ptrToStack);
	return 0;
}
