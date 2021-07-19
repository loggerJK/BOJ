#include "stackADT.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void catStackTest()
{
	char *data;

	////////////////////////////////////////
	// Fill stack A
	STACK *A = createStack();
	data = (char *)malloc(sizeof(char));
	*data = 'e';
	pushStack(A, data);

	data = (char *)malloc(sizeof(char));
	*data = 'd';
	pushStack(A, data);
	data = (char *)malloc(sizeof(char));
	*data = 'c';
	pushStack(A, data);

	////////////////////////////////////////
	// Fill stack B
	STACK *B = createStack();
	data = (char *)malloc(sizeof(char));
	*data = 'b';
	pushStack(B, data);
	data = (char *)malloc(sizeof(char));
	*data = 'a';
	pushStack(B, data);

	// concatenate
	catStack(A, B);

	////////////////////////////////////////
	// Print char values in Stack A
	//
	// EXPECTED OUTPUT:
	// a, b, c, d, e

	while (stackTop(A) != NULL)
	{
		printf("%c", *(char *)stackTop(A));
		popStack(A);

		if (stackTop(A) != NULL)
		{
			printf(", ");
		}
	}
	printf("\n");
	destroyStack(A);
}

bool braceCheck(const char *str) // 포인터가 가리키는 대상의 변경을 허용하지 않는다
{

	STACK *brace = createStack();

	for (int i = 0; i < 100; i++)
	{
		if (str[i] == '[' || str[i] == '(' || str[i] == '{')
		{
			pushStack(brace, str + i);
		}

		else if ((str[i] == ']' || str[i] == ')' || str[i] == '}'))
		{
			if (stackTop(brace) == NULL)
				return false;

			if (str[i] == ')')
			{
				if (*(char *)stackTop(brace) == '(')
					popStack(brace);
				else
					return false;
			}
			if (str[i] == ']')
			{
				if (*(char *)stackTop(brace) == '[')
					popStack(brace);

				else
					return false;
			}
			if (str[i] == '}')
			{
				if (*(char *)stackTop(brace) == '{')
					popStack(brace);
				else
					return false;
			}
		}
	}
	if (stackTop(brace) != NULL)
		return false;
	else
		return true;
}

void braceCheckTest()
{
	const int numTestCase = 7;
	int i = 0;
	char str[7][100] = {

		{"So when I die (the [first] I will see in (heaven) is a score list)."},
		{"[ first in ] ( first out )."},
		{"Half Moon tonight (At least it is better than no Moon at all]."},
		{"A rope may form )( a trail in a maze."},
		{"Help( I[m being held prisoner in a fortune cookie factory)]."},
		{"([ (([( [ ] ) ( ) (( ))] )) ])."},
		{"."}};

	for (i = 0; i < numTestCase; ++i)
	{
		if (braceCheck(str[i]))

		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
}

int main(void)
{

	catStackTest();

	braceCheckTest();

	return 0;
}