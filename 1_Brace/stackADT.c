#include "stackADT.h"

STACK* createStack()
{

	STACK *stack = (STACK *)malloc(sizeof(STACK));
	if (stack == NULL)
		return NULL;

	stack->count = 0;
	stack->top = NULL;
	return stack;
	
	// TODO

}
void destroyStack(STACK* stack) 
{
	
	if (stack->top > 0)
		free(stack);
}

	//TO DO



void pushStack(STACK* stack, void* dataInPtr)
{

	STACK_NODE *newPtr = (STACK_NODE *)malloc(sizeof(STACK_NODE));

	if (newPtr == NULL)
		return;

	newPtr->dataPtr = dataInPtr;
	newPtr->link = stack->top;
	stack->top = newPtr; 

	(stack->count)++;

	

	// TODO
	// Use linked list
}

void popStack(STACK* stack)
{

	void *dataOut;
	STACK_NODE *temp;


	if (stack->count == 0)
	{
		dataOut = NULL;
	}


	else
	{
		temp = stack->top;
		dataOut = stack->top->dataPtr;
		stack->top = stack-> top->link;
		free(temp);
		(stack->count)--;
	}
	
	// TODO

}




void* stackTop(STACK* stack)
{
	if (stack->count > 0)
		return stack->top->dataPtr;

	else
		return  NULL;
}

// TO DO

void catStack(STACK *a, STACK *b)
{

	STACK_NODE *ptr = (STACK_NODE *)malloc(sizeof(STACK_NODE));
	ptr = b->top;

	while (ptr->link != NULL)
	{
		
		ptr = ptr->link;
	}

	
	
	a->count += b->count;

	ptr->link = a->top;
	a->top = b->top;

	ptr = a->top;

	destroyStack(b);


	
}



