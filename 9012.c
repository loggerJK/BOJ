#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>


typedef struct node {
	char data;
	struct node* link;
}StackNode;

typedef struct {
	int count;
	StackNode* top;
} Stack;

Stack* createStack() {
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
		return NULL;
	pStack->count = 0;
	pStack->top = NULL;

	return pStack;

}

bool pushStack(Stack* stack, int data) {
	StackNode* pNewNode = (StackNode*)malloc(sizeof(StackNode)); // 새로운 노드를 생성한다
	if (pNewNode == NULL)
		return false;

	pNewNode->data = data;
	pNewNode->link = stack->top;
	stack->top = pNewNode;

	stack->count++;
	return true;
}

char popStack(Stack* stack) {
	if (stack->top == NULL)
		return 0;
	else {
		char item = stack->top->data;
		StackNode* pOldStack = stack->top;
		stack->top = pOldStack->link;
		free(pOldStack);
		stack->count--;
		return item;
	}
}

char stackTop(Stack* stack) {
	if (stack->count == 0)
		return '.';
	char item = stack->top->data;
	return item;

}

bool emptyStack(Stack* stack) {
	if (stack->top == NULL)
		return true;
	return false;
}

int stackCount(Stack* stack) {
	return stack->count;
}

void destroyStack(Stack* stack) {
	while (stack->top != NULL) {
		popStack(stack);
	}
	free(stack);
}

int main()
{
	int recur = 0;
	scanf("%d", &recur);

	for (int i = 0; i < recur; i++) {
		Stack* stack = createStack();

		char str[100];
		scanf("%s", str);
		int length = strlen(str);

		for (int j = 0; j < length; j++) {
			if (stack->count < 1) {
				pushStack(stack, str[j]);
				continue;
			}// 스택이 2개 이상일 경우에만 비교를 실행한다.

			int oldtop = stackTop(stack);
			int newtop = str[j];
			pushStack(stack, str[j]);
			if (oldtop == '(' && newtop == ')') {
				popStack(stack);
				popStack(stack);
			}
		}

		if (stack->count == 0)
			printf("%s\n", "YES");
		else
			printf("%s\n", "NO");

		destroyStack(stack);
	}


}
