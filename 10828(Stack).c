#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// 링크드 리스트로 구현
typedef struct node {
	int data; //
	struct node* link;
}Node;

typedef struct {
	int cnt;
	Node* top;
}Stack;

void push(Stack* stack, int x) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	// 1. 초기화
	newNode->data = x;
	newNode->link = stack->top;
	stack->top = newNode;
	
	stack->cnt++;
	return;
}

void pop(Stack* stack) {
	if (stack->cnt == 0) {
		printf("%d\n", -1);
		return;
	}
	int data = stack->top->data;
	Node* oldPtr = stack->top;
	stack->top = oldPtr->link;
	free(oldPtr);
	stack->cnt--;
	printf("%d\n", data);
	return;
}

int size(Stack* stack) {
	printf("%d\n", stack->cnt);
}

int empty(Stack* stack) {
	if (stack->cnt == 0)
		printf("%d\n", 1);
	else
		printf("%d\n", 0);
	return;
}

int top(Stack* stack) {
	if (stack->cnt == 0)
		printf("%d\n", -1);
	else
		printf("%d\n", stack->top->data);
}

int main() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->cnt = 0;
	stack->top = NULL;
	int size2 = 0;
	scanf("%d", &size2);

	for (int i = 0; i < size2; i++) {
		char* strings = (char*) malloc (sizeof(char) * 10);
		scanf("%s", strings);
		if (strcmp(strings, "push") == 0) {
			int data = 0;
			scanf("%d", &data);
			push(stack, data);
		}
		else if (strcmp(strings, "pop") == 0) {
			pop(stack);
		}
		else if (strcmp(strings, "size") == 0) {
			size(stack);
		}
		else if (strcmp(strings, "empty") == 0) {
			empty(stack);
		}
		else if (strcmp(strings, "top") == 0) {
			top(stack);
		}
	}
	
	
}