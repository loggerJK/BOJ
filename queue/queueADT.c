
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queueADT.h"

QUEUE *createQueue(void)
{
	QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));
	if (queue == NULL)
		return NULL;

	queue->count = 0;
	queue->front = queue->rear = NULL;

	return queue;

	// TODO
}

void destroyQueue(QUEUE *queue)
{
	QUEUE_NODE *pCur = NULL, *pNext = NULL;

	for (pCur = queue->front; pCur != NULL; pCur = pNext)
	{
		pNext = pCur->next;
		free(pCur);
	}
	free(queue);

	// TODO
}

void enqueue(QUEUE *queue, void *data)
{
	QUEUE_NODE *pNewNode = (QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));
	if (pNewNode == NULL)
		return;
	pNewNode->dataPtr = data;
	pNewNode->next = NULL;

	if (queue->count <= 0)
	{
		queue->front = queue->rear = pNewNode;
	}
	else
	{
		queue->rear->next = pNewNode;
		queue->rear = pNewNode;
	}
	queue->count++;

	// TODO
}

void dequeue(QUEUE *queue)
{
	QUEUE_NODE *pFront = NULL;
	queue->front->dataPtr = NULL;

	if (queue->count <= 0)
		return;

	pFront = queue->front;
	queue->front->dataPtr = pFront->dataPtr;

	if (queue->count == 1)
	{
		queue->front = queue->rear = NULL;
	}

	else
		queue->front = pFront->next;

	free(pFront);
	queue->count--;

	// TODO
}

void *queueFront(QUEUE *queue)
{

	return queue->front->dataPtr;
	// TODO
}

int queueCount(QUEUE *queue)
{
	return queue->count;
	// TODO
}
