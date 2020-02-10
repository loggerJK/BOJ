#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#include <stdio.h>
#include <stdlib.h>

int M = 0;
int dp [MAX][3]; // DP용 배열 선언, sticker[][] 를 저장한다
int testcase[3][MAX]; // 테스트 케이스를 담을 배열 선언

int sticker(int c, int status) { // c열이 status일때,  "c+1열부터의"  1 <= c <= M
	if (c == M) {
		return 0;
	}
	// c열에서 아무것도 선택하지 않은 경우
	if (status == 0) {
		int max;
		// c+1열에서 아무것도 선택하지 않은 경우
		if (dp[c + 1][0] == -1) {
			max = sticker(c + 1, 0);
		}
		else {
			max = dp[c + 1][0];
		}
		// c+1열에서 위쪽을 선택한 경우
		if (dp[c + 1][1] == -1) {
			int tmp = testcase[1][c + 1] + sticker(c + 1, 1);
			if (max < tmp) max = tmp;
		}
		else {
			int tmp = testcase[1][c + 1] + dp[c + 1][1];
			if (max < tmp) max = tmp;
		}
		// c+1열에서 아래쪽을 선택한 경우
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
		// c열의 위쪽 스티커를 뗀 경우
		// 가능한 다음 status = 0, 2
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
		// c열의 status가 2인 경우
		// 가능한 다음 status는 0 1
		int max;
		// c열에서 아무것도 선택하지 않은 경우
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