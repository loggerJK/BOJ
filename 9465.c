#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#include <stdio.h>
#include <stdlib.h>

int M = 0;
int dp [MAX][3]; // DP�� �迭 ����, sticker[][] �� �����Ѵ�
int testcase[3][MAX]; // �׽�Ʈ ���̽��� ���� �迭 ����

int sticker(int c, int status) { // c���� status�϶�,  "c+1��������"  1 <= c <= M
	if (c == M) {
		return 0;
	}
	// c������ �ƹ��͵� �������� ���� ���
	if (status == 0) {
		int max;
		// c+1������ �ƹ��͵� �������� ���� ���
		if (dp[c + 1][0] == -1) {
			max = sticker(c + 1, 0);
		}
		else {
			max = dp[c + 1][0];
		}
		// c+1������ ������ ������ ���
		if (dp[c + 1][1] == -1) {
			int tmp = testcase[1][c + 1] + sticker(c + 1, 1);
			if (max < tmp) max = tmp;
		}
		else {
			int tmp = testcase[1][c + 1] + dp[c + 1][1];
			if (max < tmp) max = tmp;
		}
		// c+1������ �Ʒ����� ������ ���
		if (dp[c + 1][2] == -1) {
			int tmp = testcase[2][c + 1] + sticker(c + 1, 2);
			if (max < tmp) max = tmp;
		}
		else {
			int tmp = testcase[2][c + 1] + dp[c + 1][2];
			if (max < tmp) max = tmp;
		}

		dp[c][0] = max;
		return max;

	}
	else if (status == 1) {
		// c���� ���� ��ƼĿ�� �� ���
		// ������ ���� status = 0, 2
		int max;
		if (dp[c + 1][0] == -1) {
			max = sticker(c + 1, 0);
		}
		else {
			max = dp[c + 1][0];
		}

		if (dp[c + 1][2] == -1) {
			int tmp = testcase[2][c + 1] + sticker(c + 1, 2);
			if (max < tmp) max = tmp;
		}
		else {
		 	int tmp = testcase[2][c + 1] + dp[c + 1][2];
			if (max < tmp) max = tmp;
		}

		dp[c][1] = max;
		return max;

	}
	else {
		// c���� status�� 2�� ���
		// ������ ���� status�� 0 1
		int max;
		// c������ �ƹ��͵� �������� ���� ���
		if (dp[c + 1][0] == -1) {
			max = sticker(c + 1, 0);
		}
		else {
			max = dp[c + 1][0];
		}

		if (dp[c + 1][1] == -1) {
			int tmp = testcase[1][c + 1] + sticker(c + 1, 1);
			if (max < tmp) max = tmp;
		}
		else {
			int tmp = testcase[1][c + 1] + dp[c + 1][1];
			if (max < tmp) max = tmp;
		}

		dp[c][2] = max;
		return max;
	}
}

int main() {
	int N = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= M; j++) {
				scanf("%d", &testcase[i][j]);
			}
		}
		for (int i = 0; i <= MAX; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = -1;
			}
		}
		int data = sticker(0, 0);
		printf("%d\n", data);
	}

	/*
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%d ", testcase[i][j]);
		}
		printf("\n");
	}
	*/

}