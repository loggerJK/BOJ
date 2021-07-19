#define _CRT_SECURE_NO_WARNINGS
#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>

int hotdogsSold(int numCustomers, int* patience)
{
	int big_sold = 0;

	QUEUE *queue = createQueue();

	for (int i = 0; i < numCustomers; i++)
	{
		enqueue(queue, &patience[i]);

	}

	while (queue->front != NULL)
	{
		if (*(int*)queueFront(queue) >= 0 && queueCount(queue) >= 2)
		{
			big_sold += 2;
			dequeue(queue);
			dequeue(queue);

		}

		else if (*(int *)queueFront(queue) >= 0 && queueCount(queue) < 2)
		{
			big_sold++;
			dequeue(queue);
		}

		for (int j = 0; j < queueCount(queue); j++)
		{
			int f = (*(int *)queueFront(queue)) - 1;

			dequeue(queue);

			if ((j == 0 && f==0) || (j==1 && f==0) || f > 0)
				enqueue(queue, &f);

		}





	}
	destroyQueue(queue);
	return big_sold;
	// TODO
}

int main()
{
	int numCustomers;
	int* patience;

	printf("Number of customers : ");
	scanf("%d", &numCustomers);
	patience = (int*)malloc(sizeof(int) * numCustomers);

	for (int i = 0; i < numCustomers; ++i)
	{
		printf("Patience of customer %d (1~9): ", i + 1);
		scanf("%d", &patience[i]);
	}

	printf("I sold %d hotdogs\n", hotdogsSold(numCustomers, patience));

	return 0;
}