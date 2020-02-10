#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* left;
	struct node* right;
}Node;

Node* createTree(Node* array[], char leftData, char data, char rightData) {
	
	Node* rootPtr = NULL;
	Node* rightPtr = NULL;
	Node* leftPtr = NULL;

	if (array[data - 'A']) { // 이미 해당 루트 노드가 존재한다면 (NULL이 아니라면)
		rootPtr = array[data - 'A'];
	}
	else {
		rootPtr = (Node*)malloc(sizeof(Node)); // 존재하지 않는다면 노드를 생성
		array[data - 'A'] = rootPtr;
		rootPtr->data = data;
		rootPtr->left = NULL;
		rootPtr->right = NULL;
	}
	// 루트 포인터 지정

	// left 노드 
	if (array[leftData - 'A'] && leftData != '.' ) { // 이미 해당 루트 노드가 존재한다면 (NULL이 아니라면)
		leftPtr = array[leftData - 'A'];
	}
	else if (leftData !='.'){ // NULL이고 비어 있는 노드가 아니라면
		leftPtr = (Node*)malloc(sizeof(Node)); // 노드를 생성
		array[leftData - 'A'] = leftPtr;
		leftPtr->data = leftData;
		leftPtr->left = NULL;
		leftPtr->right = NULL;
	}

	rootPtr->left = leftPtr;

	if (array[rightData - 'A'] && rightData != '.') {
		rightPtr = array[rightData - 'A'];
	}
	else if (rightData != '.') {
		rightPtr = (Node*)malloc(sizeof(Node));
		array[rightData - 'A'] = rightPtr;
		rightPtr->data = rightData;
		rightPtr->left = NULL;
		rightPtr->right = NULL;
	}


	rootPtr->right = rightPtr;
	


	/*
	if (!newNodePtr) {
		// NULL이 아니라면
		newNodePtr->data = data;
		newNodePtr->left = leftPtr;
		newNodePtr->right = rightPtr;
	}
	return newNodePtr;

	*/


}

void preOrdersearchTree(Node* rootPtr) {
	if (!rootPtr) { // NULL이라면
		return;
	}
	printf("%c", rootPtr->data);
	preOrdersearchTree(rootPtr->left);
	preOrdersearchTree(rootPtr->right);
}
void inOrdersearchTree(Node* rootPtr) {
	if (!rootPtr) {
		return;
	}
	inOrdersearchTree(rootPtr->left);
	printf("%c", rootPtr->data);
	inOrdersearchTree(rootPtr->right);
}

void postOrdersearchTree(Node* rootPtr) {
	if (!rootPtr) {
		return;
	}
	postOrdersearchTree(rootPtr->left);
	postOrdersearchTree(rootPtr->right);
	printf("%c", rootPtr->data);

}

int main() {
	Node * array [26]; // NULL로 초기화된다
	for (int i = 0; i < 26; i++) {
		array[i] = NULL;
	}
	char left, root , right;
	int N;
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {

		scanf("%c %c %c ", &root, &left, &right);

		createTree(array, left, root, right);
	}

	Node* rootPtr = array[0];
	preOrdersearchTree(rootPtr);
	printf("\n");	
	inOrdersearchTree(rootPtr);
	printf("\n");
	postOrdersearchTree(rootPtr);


	

}
