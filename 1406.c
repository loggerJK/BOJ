#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* prev;
	struct node* next;
} Node;

typedef struct list {
	int count;
	Node* cursor;
	//Node* headPtr;
	Node* backPtr;
}List;

List* createList() {
	List* listPtr = (List*)malloc(sizeof(List));
	//Node* headPtr = (Node*)malloc(sizeof(Node));
	Node* backPtr = (Node*)malloc(sizeof(Node));


	if (!listPtr) {
		return NULL;
	}
	listPtr->count = 0;
	//listPtr->headPtr = headPtr;
	listPtr->backPtr = backPtr;
	listPtr->cursor = backPtr;
	/*
	headPtr->data = 'H';
	headPtr->next = backPtr;
	headPtr->prev = NULL;
	*/


	backPtr->data = 'B';
	backPtr->next = NULL;
	backPtr->prev = NULL;

	
	return listPtr;
}

void insert(List* list, char data) { // 커서 왼쪽에 문자를 추가
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	if (list->cursor->prev == NULL) {
		// 커서가 문장 처음인 경우
		newNode->next = list->cursor;
		list->cursor->prev = newNode;
		// 커서 위치는 그대로 유지
	}
	else {
		// 커서가 문장 중간 or 문장 끝
		list->cursor->prev->next = newNode;
		newNode->prev = list->cursor->prev;
		newNode->next = list->cursor;
		list->cursor->prev = newNode;
	}


	list->count++;
	
}
void delete(List* list) {
	Node* delPtr = list->cursor->prev;
	if (delPtr == NULL) {
		return;
	}
	else if (!delPtr->prev) {
		list->cursor->prev = NULL;
	}
	else  {
		delPtr->prev->next = list->cursor;
		list->cursor->prev = delPtr->prev;
	}
	free(delPtr);
	list->count--;
}

void func_L(List* list) {
	if (list->cursor->prev) {
		list->cursor = list->cursor->prev;
	}
}

void func_R(List* list) {
	if (list->cursor->next) {
		list->cursor = list->cursor->next;
	}
}

int main() {
	char str = 0;

	List* list = createList();
	do {
		str = getchar();
		if (str != '\n') {
			insert(list, str);
		}
	} while (str != '\n');
	int N = 0;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		str = getchar();
		getchar();
		switch (str) {
		case 'L':
			func_L(list);
			break;
		case 'D':
			func_R(list);
			break;
		case 'B':
			delete(list);
			break;
		case 'P':
			str = getchar();
			getchar();
			insert(list, str);
		}
	}
	
	for (int i = 0; i < list->count; i++) {
		func_L(list);
	}

	for (int i = 0; i < list->count; i++) {
		printf("%c", list->cursor->data);
		func_R(list);
	}
	
}