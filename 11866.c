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
	// �޸� ������ ������ ��� null�� ��ȯ
	if (queue == NULL)
		return NULL;

	// ��� �ʱ�ȭ
	queue->count = 0;
	queue->front = NULL;
	queue->rear = NULL;

	return queue;
}

void push(Queue* queue, void* ptr) {
	// ��带 �����Ѵ�
	Node* newNode = (Node*)malloc(sizeof(Node));

	// ��� �ʱ�ȭ
	newNode->dataptr = ptr;
	newNode->next = NULL;
	// ��尡 �ϳ��� ���ٸ� front�� rear�� �� �� �����Ѵ�

	if (queue->count == 0) {
		queue->front = newNode;
		queue->rear = newNode;
	}
	// ��尡 �����Ѵٸ� rear�� �����Ѵ�
	else {
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
	// ī��Ʈ�� �ø���
	queue->count++;
	return;
}

void* pop(Queue* queue) {
	if (queue->count == 0)
		return NULL;


	Node* oldptr = queue->front;
	void* data = queue->front->dataptr;
	// queue->front�� (������ �����) ���� ��忡 ����
	queue->front = queue->front->next;
	// ������ ���� ��带 �����Ѵٸ� rear�� NULL
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


	// N+1���� ��带 �����Ѵ�
	// front -> 0�� ���
	// back -> N�� ���
	for (int i = 0; i <= N; i++) {
		int* dataptr = (int*)malloc(sizeof(int));
		*dataptr = i;
		push(queue, dataptr);
	}

	// ������ ��� -> ù��° ���� ����
	queue->rear->next = queue->front;


	printf("<");
	while (size(queue) > 1) {
		printCount++;
		Node* oldPtr = (Node*)malloc(sizeof(Node));
		for (int i = 0; i < K; i++) {
			// queue->front ���� �����س��´�
			oldPtr = queue->front;
			// queue->front�� ���� ���� �̵��Ѵ�
			queue->front = queue->front->next;
			//queue->front�� ����Ű�� ����� ���� �˻��Ѵ�
			int* dataPtr = queue->front->dataptr;
			int data = *dataPtr;

			// 0�� ����� Ž���� 1ȸ �� �Ѵ�.
			if (data == 0)
				i--;

		}
		// oldPtr -> (queue->front) ���� ���
		// queue->front : ������ ���

		// (�����ҳ��) ������带 (�����ҳ����) �������� ����
		oldPtr->next = queue->front->next;
		int* numPtr = (int*)pop(queue);
		int num = *numPtr;
		if (printCount == N) {
			printf("%d", num);
		}
		else {
			printf("%d, ", num);
		}

		// queue->front�� (������ �����) ���� ��带 ����Ŵ.
		// ������带 ����Ű���� ����
		queue->front = oldPtr;

		// ��� ī��Ʈ++;
	}
	printf(">");
}



