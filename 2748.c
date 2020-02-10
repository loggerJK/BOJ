#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned long long func(int n);
unsigned long long dp[100];
int main() {
	// dp 초기화
	for (int i = 0; i < 100; i++) {
		dp[i] = -1;
	}
	int N;
	scanf("%d", &N);

	printf("%llu", func(N));

}

unsigned long long func(int n){
	if (n == 0) {
		return 0;
	}
	if (n == 1)
		return 1;
	if (dp[n] != -1) {
		return dp[n];
	}
	dp[n] = func(n - 1) + func(n - 2);
	return dp[n];
}