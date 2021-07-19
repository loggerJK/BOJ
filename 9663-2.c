#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void func(int col[16], int col_num, int N);
bool isPossible(int col[16], int i, int j);
int count = 0;


int main() {
	int N = 0;
	scanf("%d", &N);

	int col[15 + 1];

	func(col, 1, N);

	printf("%d", count);
}

void func(int col[16], int col_num, int N) {
	int i = col_num;
	
	for (int j = 1; j <= N; j++) {
		if (isPossible(col, i, j)) {
			col[i] = j;
			// 끝 열이라면
			if (i == N) {
				count++;
				/*

				for (int a = 1; a <= i; a++) {
					printf("(%d, %d)", a, col[a]);
				}
				printf("\n");
				*/
				continue;
			}
			else {
				func(col, i + 1, N);
			}
		}
	}
}

bool isPossible(int col[16], int i, int j) {
	if (i == 1)
		return true;
	for (int a = 1; a <= i - 1; a++) {
		int b = col[a];
		if (b == j || abs(a-i) == abs(b-j))
			return false;
	}
	return true;
}




