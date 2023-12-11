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
		sta->items[sta->top] = ' ';
		sta->top--;
	}
	else{
		topItem = sta->items[sta->top];
		sta->items[sta->top] = ' ';
	}
	return topItem;
}

void push(Stack* sta, char item){

	if(sta->top == 0){
		sta->items[0] = item;
		sta->top++;
	}
	else if(sta->stackSize >= sta->top + 1){
		sta->top++;
		sta->items[sta->top] = item;
	}
	else{
		printf("STACK FULLL\n");
		printf("ITEM %c NOT ADDED\n", item);
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

	for(int i = 0; i <= testStack.stackSize; i++){
		printf("TRYING TO PUSH --- %c --- TO STACK\n", item);
		push(ptrToStack, item);
		if(ptrToStack->items[i] == item || ptrToStack->items[ptrToStack->top] == item){
			printf("ITEM %c HAS BEEN ADDED\n", item);
		}
		printf("The top index is now: %i\n\n", testStack.top);
		item++;
	}
	currentTop = pop(ptrToStack);
	printf("Top item was: %c and is now popped\n", currentTop);
	printf("The top index is now: %i\n\n", testStack.top);

	item = 'z';
	printf("ADDED %c AT STACKTOP OF %i\n", item, testStack.top);
	push(ptrToStack, item);
	printf("The top index is now: %i\n\n", testStack.top);

	currentTop = pop(ptrToStack);
	printf("Top item was: %c and is now popped\n", currentTop);
	printf("The top index is now: %i\n\n", testStack.top);

	peek(ptrToStack);
	return 0;
}
