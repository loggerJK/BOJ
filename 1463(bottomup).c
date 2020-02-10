#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#include <stdio.h>
#include <stdlib.h>

int data[MAX];

int func(int N) {
	int min = 0;

	int tmp = 0;
	if (N == 1) // 항상 베이스 케이스가 코드 맨 위에 있어야 한다
		return 0;

	min = data[N-1] + 1;

	if (N % 3 == 0) {
		tmp = data[N / 3] + 1;
		if (min > tmp) {
			min = tmp;
		}
	}
	if (N % 2 == 0) {
		tmp = data[ N / 2] + 1;
		if (min > tmp) {
			min = tmp;
		}
	}

	data[N] = min;
	return data[N];
}

int main() {
	int N = 0;
	scanf("%d", &N);

	for (int i = 0; i <= N; i++) {
		data[i] = func(i);
	}

	printf("%d", data[N]);
	system("pause");
}