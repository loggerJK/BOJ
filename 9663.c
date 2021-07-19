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
	Node arr[16][16]; // 15 X 15 ü���� �迭, 0ĭ�� ������� �ʴ´�

	int size = 0;
	scanf("%d", &size);

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			arr[i][j].visit = 0;
		}
	}

	//���۳��� [1][1] ���� 14����� �ݺ�
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
	// ���� �湮 ó��
	for (int j = 0; j < 15; j++) {
		arr[start_x][j].visit = 1;
	}
	// ���� �湮 ó��
	for (int i = 0; i < 15; i++) {
		arr[i][start_y].visit = 1;
	}
	// �����ʾƷ� �밢�� �湮ó��
	for (int i = 1, j = 1; start_x + i <= 15 || start_y + j <= 15; i++, j++) {
		arr[start_x + i][start_y + j].visit = 1;
	}
	// ���� �Ʒ� �밢��
	for (int i = 1, j = 1; start_x + i <= 15 || start_y - j >= 1; i++, j++) {
		arr[start_x + i][start_y - j].visit = 1;
	}
	// ���� �� �밢��
	for (int i = 1, j = 1; start_x - i >= 1 || start_y - j >= 1; i++, j++) {
		arr[start_x - i][start_y - j].visit = 1;
	}
	// ������ �� �밢��
	for (int i = 1, j = 1; start_x - i >= 1 || start_y + j <= 15; i++, j++) {
		arr[start_x + i][start_y + j].visit = 1;
	}
}
void node_visit_reset (Node arr[][16], int start_x, int start_y, int size) {
	// ���� �湮 ó��
	for (int j = 0; j < 15; j++) {
		arr[start_x][j].visit = 1;
	}
	// ���� �湮 ó��
	for (int i = 0; i < 15; i++) {
		arr[i][start_y].visit = 1;
	}
	// �����ʾƷ� �밢�� �湮ó��
	for (int i = 1, j = 1; start_x + i <= 15 || start_y + j <= 15; i++, j++) {
		arr[start_x + i][start_y + j].visit = 1;
	}
	// ���� �Ʒ� �밢��
	for (int i = 1, j = 1; start_x + i <= 15 || start_y - j >= 1; i++, j++) {
		arr[start_x + i][start_y - j].visit = 1;
	}
	// ���� �� �밢��
	for (int i = 1, j = 1; start_x - i >= 1 || start_y - j >= 1; i++, j++) {
		arr[start_x - i][start_y - j].visit = 1;
	}
	// ������ �� �밢��
	for (int i = 1, j = 1; start_x - i >= 1 || start_y + j <= 15; i++, j++) {
		arr[start_x + i][start_y + j].visit = 1;
	}
}

void search(Node arr[16][16], int start_x, int start_y, int depth, int size) {
	// depth�� N(size)�̶�� ���� ���� �� �ִ� ����� ã�� ���̴�.
	if (depth == size) {
		count++;
		printf("(%d %d %d %d) \n", start_x, start_y, depth, count);

		return;
	}
	//printf("(%d %d %d %d) \n", start_x, start_y, depth, count);
	arr[start_x][start_y].visit = 1; //���� ��� �湮 ó��

	// ���� �̵��� �� �ִ� �ڸ����� �湮 ó��
	node_visit(arr, start_x, start_y, 15);

	// ���� ���� ��带 ã�´�
	for (int i = 0; start_x + i <= size; i++) {
		for (int j = 0; start_y + j <= size; j++) {

			// �湮���� ���� ����� �湮�Ѵ�
			if (arr[start_x + i][start_y + j].visit == 0) {
				search(arr, start_x + i, start_y + j, depth + 1, size);
			}
		}
	}

	// ���۳��� ����� ������ �湮 ó���� �����Ѵ�.
	node_visit_reset(arr, start_x, start_y, 15);
	return;
}
