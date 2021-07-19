#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count = 0;



typedef struct {
	int visit;
}Node;

void search(Node arr[16][16], int start_x, int start_y, int depth, int size);

int main() {
	Node arr[16][16]; // 15 X 15 체스판 배열, 0칸은 사용하지 않는다

	int size = 0;
	scanf("%d", &size);

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			arr[i][j].visit = 0;
		}
	}

	//시작노드는 [1][1] 부터 14행까지 반복
	for (int i = 1; i <= size - 1; i++) {
		for (int j = 1; j <= size; j++) {
			search(arr, i, j, 1, size);
		}
	}
	/*
	for (int j = 1; j < size - 2; j++) {
		search(arr, size, j, 1, size);
	}
	*/
	printf("%d", count);

	return 0;
}

void node_visit(Node arr[][16], int start_x, int start_y, int size) {
	// 가로 방문 처리
	for (int j = 0; j < 15; j++) {
		arr[start_x][j].visit = 1;
	}
	// 세로 방문 처리
	for (int i = 0; i < 15; i++) {
		arr[i][start_y].visit = 1;
	}
	// 오른쪽아래 대각선 방문처리
	for (int i = 1, j = 1; start_x + i <= 15 || start_y + j <= 15; i++, j++) {
		arr[start_x + i][start_y + j].visit = 1;
	}
	// 왼쪽 아래 대각선
	for (int i = 1, j = 1; start_x + i <= 15 || start_y - j >= 1; i++, j++) {
		arr[start_x + i][start_y - j].visit = 1;
	}
	// 왼쪽 위 대각선
	for (int i = 1, j = 1; start_x - i >= 1 || start_y - j >= 1; i++, j++) {
		arr[start_x - i][start_y - j].visit = 1;
	}
	// 오른쪽 위 대각선
	for (int i = 1, j = 1; start_x - i >= 1 || start_y + j <= 15; i++, j++) {
		arr[start_x + i][start_y + j].visit = 1;
	}
}
void node_visit_reset (Node arr[][16], int start_x, int start_y, int size) {
	// 가로 방문 처리
	for (int j = 0; j < 15; j++) {
		arr[start_x][j].visit = 1;
	}
	// 세로 방문 처리
	for (int i = 0; i < 15; i++) {
		arr[i][start_y].visit = 1;
	}
	// 오른쪽아래 대각선 방문처리
	for (int i = 1, j = 1; start_x + i <= 15 || start_y + j <= 15; i++, j++) {
		arr[start_x + i][start_y + j].visit = 1;
	}
	// 왼쪽 아래 대각선
	for (int i = 1, j = 1; start_x + i <= 15 || start_y - j >= 1; i++, j++) {
		arr[start_x + i][start_y - j].visit = 1;
	}
	// 왼쪽 위 대각선
	for (int i = 1, j = 1; start_x - i >= 1 || start_y - j >= 1; i++, j++) {
		arr[start_x - i][start_y - j].visit = 1;
	}
	// 오른쪽 위 대각선
	for (int i = 1, j = 1; start_x - i >= 1 || start_y + j <= 15; i++, j++) {
		arr[start_x + i][start_y + j].visit = 1;
	}
}

void search(Node arr[16][16], int start_x, int start_y, int depth, int size) {
	// depth가 N(size)이라면 퀸을 놓을 수 있는 방법을 찾은 것이다.
	if (depth == size) {
		count++;
		printf("(%d %d %d %d) \n", start_x, start_y, depth, count);

		return;
	}
	//printf("(%d %d %d %d) \n", start_x, start_y, depth, count);
	arr[start_x][start_y].visit = 1; //시작 노드 방문 처리

	// 퀸이 이동할 수 있는 자리들은 방문 처리
	node_visit(arr, start_x, start_y, 15);

	// 다음 시작 노드를 찾는다
	for (int i = 0; start_x + i <= size; i++) {
		for (int j = 0; start_y + j <= size; j++) {

			// 방문하지 않은 노드라면 방문한다
			if (arr[start_x + i][start_y + j].visit == 0) {
				search(arr, start_x + i, start_y + j, depth + 1, size);
			}
		}
	}

	// 시작노드와 연결된 노드들의 방문 처리를 해제한다.
	node_visit_reset(arr, start_x, start_y, 15);
	return;
}
