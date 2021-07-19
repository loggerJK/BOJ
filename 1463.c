#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#include <stdio.h>
#include <stdlib.h>

int func(int N);


int data[MAX];

int func(int N) {
	int min = 0;

	int tmp = 0;
	if (N == 1) // 항상 베이스 케이스가 코드 맨 위에 있어야 한다
		return 0;

	// 이미 계산했다면 배열에서 리턴한다
	// -1 은 절대 나올 수 없는 값이다
	if (data[N] != -1) {
		return data[N];
	}

	min = func(N - 1) + 1;

	if (N % 3 == 0) {
		tmp = func(N / 3) + 1;
		if (min > tmp) {
			min = tmp;
		}
	}
	if (N % 2 == 0) {
		tmp = func (N / 2) + 1;
		if (min > tmp) {
			min = tmp;
		}
	}

	data[N] = min;
	return min;
}

int main() {
	int N = 0;
	for (int i = 0; i < MAX; i++) {
		data[i] = -1;
	}
	scanf("%d", &N);
	printf("%d", func(N));
}