#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>


typedef struct node {
	void* dataptr;
	struct node* next;
}Node;

typedef struct queue {
	int count;
	Node* front;
	Node* rear;
} Queue;

Queue* createQueue() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	// 메모리 생성에 실패한 경우 null을 반환
	if (queue == NULL)
		return NULL;

	// 멤버 초기화
	queue->count = 0;
	queue->front = NULL;
	queue->rear = NULL;

	return queue;
}

void push(Queue* queue, void* ptr) {
	// 노드를 생성한다
	Node* newNode = (Node*)malloc(sizeof(Node));

	// 노드 초기화
	newNode->dataptr = ptr;
	newNode->next = NULL;
	// 노드가 하나도 없다면 front와 rear를 둘 다 연결한다

	if (queue->count == 0) {
		queue->front = newNode;
		queue->rear = newNode;
	}
	// 노드가 존재한다면 rear에 연결한다
	else {
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
	// 카운트를 올린다
	queue->count++;
	return;
}

void* pop(Queue* queue) {
	if (queue->count == 0)
		return NULL;


	Node* oldptr = queue->front;
	void* data = queue->front->dataptr;
	// queue->front를 (삭제할 노드의) 다음 노드에 연결
	queue->front = queue->front->next;
	// 마지막 남은 노드를 삭제한다면 rear도 NULL
	if (queue->count == 1)
		queue->rear = oldptr->next;

	free(oldptr);
	queue->count--;
	return data;

}

int size(Queue* queue) {
	return queue->count;
}

void* front(Queue* queue) {
	if (queue->count == 0)
		return NULL;
	return queue->front->dataptr;
}

void* back(Queue* queue) {
	if (queue->count == 0)
		return NULL;
	return queue->rear->dataptr;
}

bool empty(Queue* queue) {
	if (queue->count == 0)
		return true;  //True
	else
		return false;
}

int main() {
	Queue* queue = createQueue();
	int N, K;
	int printCount = 0;
	scanf("%d %d", &N, &K);


	// N+1개의 노드를 생성한다
	// front -> 0번 노드
	// back -> N번 노드
	for (int i = 0; i <= N; i++) {
		int* dataptr = (int*)malloc(sizeof(int));
		*dataptr = i;
		push(queue, dataptr);
	}

	// 마지막 노드 -> 첫번째 노드로 연결
	queue->rear->next = queue->front;


	printf("<");
	while (size(queue) > 1) {
		printCount++;
		Node* oldPtr = (Node*)malloc(sizeof(Node));
		for (int i = 0; i < K; i++) {
			// queue->front 값을 저장해놓는다
			oldPtr = queue->front;
			// queue->front를 다음 노드로 이동한다
			queue->front = queue->front->next;
			//queue->front가 가리키는 노드의 값을 검사한다
			int* dataPtr = queue->front->dataptr;
			int data = *dataPtr;

			// 0번 노드라면 탐색을 1회 더 한다.
			if (data == 0)
				i--;

		}
		// oldPtr -> (queue->front) 이전 노드
		// queue->front : 삭제할 노드

		// (삭제할노드) 이전노드를 (삭제할노드의) 다음노드와 연결
		oldPtr->next = queue->front->next;
		int* numPtr = (int*)pop(queue);
		int num = *numPtr;
		if (printCount == N) {
			printf("%d", num);
		}
		else {
			printf("%d, ", num);
		}

		// queue->front는 (삭제한 노드의) 다음 노드를 가리킴.
		// 이전노드를 가리키도록 수정
		queue->front = oldPtr;

		// 출력 카운트++;
	}
	printf(">");
}



