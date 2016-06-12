#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10
#define STACK_EMPTY -1

void push(char [], // input/ouput - the stack
	  char,	   // input - data being pushed onto the stack
	  int *,   // input/output - pointer to the index of the top of stack
	  int);    // constant - maximum size of stack

char		   // output - data being popped out from the stack
     pop(char [],  // input/output - the stack
	 int *);   // input/output - pointer to the index of the top of stack

void push(char stack[],
	  char item,
	  int *top,
	  int max_size){

	// Your code here ...
	// Push item to the top of stack if it's not full. 
	// Update the top pointer s/t it points to the index of the new top element on the stack.
	if(*top < max_size-1){
		*top+=1;
		stack[*top] = item;
	}	
}

char pop(char stack[],
	 int *top){

	// Your code here ...
	// Pop out the top item on the stack and return it if the stack is not emtpy.
	// Update the top pointer s/t it points to the index of the new top element on the stack.
	// Return STACK_EMPTY if the stack is empty.
	if(*top > -1){
		*top-=1;
		return stack[*top+1];
	}	
	if(*top == -1)
		return STACK_EMPTY;
}

int main(){
	char s[STACK_SIZE];
	int s_top = STACK_EMPTY; // Pointer points to the index of the top of the stack

	srand(time(NULL));

	// Your code here ...
	// (Using a loop) Keep pushing chars randomly picked between '!'(33) and '~'(126) to the stack
	// until it is full. 
	// Print each char before each pushing.
	char ranChar;	
	int i;
	for(i=0;i<STACK_SIZE;i++){
		if(i >= STACK_SIZE)
			printf("Stack if Full\n");
		else{// if(s_top < STACK_SIZE){
			ranChar = rand()%94+33;
			printf("%c\n",ranChar);
			push(s,(char)ranChar,&s_top,STACK_SIZE);
		}	
	}
	printf("-----------\n");

	// Your code here ...
	// (Using a loop) Keep popping out chars from the stack until it is empty
	// Print each char after each popping. 
	for(i=s_top;i>-1;i--){
		if(s_top == -1)
			printf("Stack is Empty\n");
		else
			printf("%c\n", pop(s,&s_top));
	}
	return 0;
}


