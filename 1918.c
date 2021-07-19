#define _CRT_SECURE_NO_WARNINGS
#define str_size 100

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
// ��ũ�� ����Ʈ�� ����
typedef struct node {
	char data;
	struct node* link;
}Node;

typedef struct {
	int cnt;
	Node* top;
}Stack;

Stack* createStack() {
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
		return NULL;
	pStack->cnt = 0;
	pStack->top = NULL;

	return pStack;

}

void push(Stack* stack, int x) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	// 1. �ʱ�ȭ
	newNode->data = x;
	newNode->link = stack->top;
	stack->top = newNode;

	stack->cnt++;
	return;
}

char pop(Stack* stack) {
	if (stack->cnt == 0) {
		printf("%d\n", -1);
		return;
	}
	char data = stack->top->data;
	Node* oldPtr = stack->top;
	stack->top = oldPtr->link;
	free(oldPtr);
	stack->cnt--;
	return data;
}

int size(Stack* stack) {
	printf("%d\n", stack->cnt);
}

int empty(Stack* stack) {
	if (stack->cnt == 0)
		return 1;
	else
		return 0;
}

char top(Stack* stack) {
	if (stack->cnt == 0)
		return -1;
	else
		return stack->top->data;
}

int priority(char data) {
	if (data == '*' || data == '/')
		return 3;
	if (data == '+' || data == '-')
		return 2;
	if (data == '(' || data == ')')
		return 1;
}

int main() {
	Stack* stack = createStack();
	char str[str_size];

	scanf("%s", str);

	int str_length = strlen(str);

	for (int i = 0; i < str_length; i++) { 
		char data = str[i];

		// ���ڴ� �״�� ����Ѵ�

		if ('a' <= data && data <= 'z') {
			printf("%c", data);
			continue;
		}


		if ('A' <= data && data <= 'Z') {
			printf("%c", data);
			continue;
		}

		char newOperator = data;
		char oldOperator = top(stack);

		// 1. '(' ��ȣ�� �׳� push
		if (newOperator == '(') {
			push(stack, newOperator);
			continue;
		}



		// 2. ')' ��ȣ�� '('�� ���ö����� pop
		else if (newOperator == ')') {
			while (1) {
				char oper = pop(stack);
				if (oper == '(')
					break;
				printf("%c", oper);
			}
			continue;
		}
	

		// ���ÿ� �ƹ� �����ڵ� ������ push

		if (empty(stack)) {
			push(stack, data);
			continue;
		}


		// 2. �� �������� �켱������ ������ push
		else if (priority(newOperator) > priority(oldOperator)) {
			push(stack, newOperator);
		}
		// 3. (�� ��������) �켱������ �� ���ų� ������, ������ ������ or ���� ������ pop, ���� push
		else if (priority(newOperator) <= priority (oldOperator)) {
			while (priority(newOperator) <= priority(oldOperator) && !empty(stack)) {
				char tmp = pop(stack);
				printf("%c", tmp);
				oldOperator = top(stack);
			}
			push(stack, newOperator);
		}


	}

	// ��� ���ڿ� ���� �ݺ����� ���Ҵٸ�

	while (!empty(stack)) {
		char data = pop(stack);
		printf("%c", data);
	}



}