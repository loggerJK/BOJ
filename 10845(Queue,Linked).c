// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
	void *dataptr;
	struct node *next;
} Node;

typedef struct queue
{
	int count;
	Node *front;
	Node *rear;
} Queue;

Queue *createQueue()
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	// �޸� ������ ������ ��� null�� ��ȯ
	if (queue == NULL)
		return NULL;

	// ��� �ʱ�ȭ
	queue->count = 0;
	queue->front = NULL;
	queue->rear = NULL;

	return queue;
}

void push(Queue *queue, void *ptr)
{
	// ��带 �����Ѵ�
	Node *newNode = (Node *)malloc(sizeof(Node));

	// ��� �ʱ�ȭ
	newNode->dataptr = ptr;
	newNode->next = NULL;
	// ��尡 �ϳ��� ���ٸ� front�� rear�� �� �� �����Ѵ�

	if (queue->count == 0)
	{
		queue->front = newNode;
		queue->rear = newNode;
	}
	// ��尡 �����Ѵٸ� rear�� �����Ѵ�
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
	// ī��Ʈ�� �ø���
	queue->count++;
	return;
}

void *pop(Queue *queue)
{
	if (queue->count == 0)
		return NULL;

	Node *oldptr = queue->front;
	void *data = queue->front->dataptr;

	queue->front = queue->front->next;
	if (queue->count == 1)
		queue->rear = oldptr->next;

	free(oldptr);
	queue->count--;
	return data;
}

int size(Queue *queue)
{
	return queue->count;
}

void *front(Queue *queue)
{
	if (queue->count == 0)
		return NULL;
	return queue->front->dataptr;
}

void *back(Queue *queue)
{
	if (queue->count == 0)
		return NULL;
	return queue->rear->dataptr;
}

bool empty(Queue *queue)
{
	if (queue->count == 0)
		return true; //True
	else
		return false;
}

int main()
{
	Queue *queue = createQueue();
	int size2 = 0;
	scanf("%d", &size2);

	for (int i = 0; i < size2; i++)
	{
		char *strings = (char *)malloc(sizeof(char) * 100);
		scanf("%s", strings);
		int *intptr = (int *)malloc(sizeof(int));

		if (strcmp(strings, "push") == 0)
		{
			scanf("%d", intptr);
			push(queue, intptr);
		}
		else if (strcmp(strings, "pop") == 0)
		{
			intptr = (int *)pop(queue);
			if (intptr == NULL)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", *intptr);
			}
		}
		else if (strcmp(strings, "size") == 0)
		{
			int queue_size = size(queue);
			printf("%d\n", queue_size);
		}
		else if (strcmp(strings, "empty") == 0)
		{
			bool ifempty = empty(queue);
			if (ifempty)
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else if (strcmp(strings, "front") == 0)
		{
			intptr = (int *)front(queue);
			if (intptr == NULL)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", *intptr);
			}
		}
		else if (strcmp(strings, "back") == 0)
		{
			intptr = (int *)back(queue);
			if (intptr == NULL)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", *intptr);
			}
		}
	}
}
