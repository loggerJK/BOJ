#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPossible(int sudoku[10][10], int a, int b);
bool DFS(int sudoku[10][10], int coordinate);

int main() {
	int sudoku[10][10]; // 9X9 ������ �迭

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			scanf("%d", &sudoku[i][j]);
		}
	}


	DFS(sudoku, 1);


	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			printf("%d ", sudoku[i][j]);
		}
		printf("\n");
	}


}
bool isPossible(int sudoku[10][10], int a, int b) {
	int horizontal[10] = { 0, };
	int vertical[10] = { 0, };
	int square[10] = { 0, };
	// ���� �˻�
	for (int j = 1; j <= 9; j++) {
		int tmp = sudoku[a][j];
		horizontal[tmp]++;
	}
	for (int i = 1; i <= 9; i++) {
		if (horizontal[i] > 1)
			return false;
	}
	//���� �˻�
	for (int i = 1; i <= 9; i++) {
		int tmp = sudoku[i][b];
		vertical[tmp]++;
	}
	for (int i = 1; i <= 9; i++) {
		if (vertical[i] > 1)
			return false;
	}
	// square �˻�
	int i = 0;
	int j = 0;
	int cnt = 0;
	
	for (i = 2; i <= 8; i += 3) {
		for (j = 2; j <= 8; j += 3) {
			if (i - 1 <= a && a <= i + 1 && j - 1 <= b && b <= j + 1)
				goto EXIT;
		}
	}
EXIT:

	for (int x = i - 1; x <= i + 1; x++) {
		for (int y = j - 1; y <= j + 1; y++) {
			cnt++;
			int tmp = sudoku[x][y];
			square[tmp]++;
		}
	}

	for (int x = 1; x <= 9; x++) { // 0�� ������ ���� ���� �ִ�.
		if (square[x] > 1) {
			//printf("(%d, %d)\n", x, square[x]);
			return false;
		}

	}

	return true;


}

bool DFS(int sudoku[10][10], int coordinate) {
	// ��ǥ�� (a,b)�������� ��ȯ
	int a = 0, b = 0;
	if (coordinate % 9 == 0) {
		 a = coordinate / 9;
		 b = 9;
	}
	else {
		 a = coordinate / 9 + 1;
		 b = coordinate % 9;
	}


	if (coordinate == 81 && sudoku[a][b] != 0)
		return true;


	if (sudoku[a][b] == 0) {
		//������ 0�̸� ���� ������ ���� ã�´�
		
		for (int i = 1; i <= 9; i++) {
			sudoku[a][b] = i;
			// ���� ������ ���� �ִٸ� �����Ѵ�
			if (isPossible(sudoku, a, b)) {
				
				// ���� ĭ���� DFS�� �ѱ��
				if (coordinate != 81) {
					bool chk = DFS(sudoku, coordinate + 1);

					if (chk == true) {
						// �����ؼ� ���ƿ����� �� �̻� Ž���� ���� �ʰ� �����Ѵ�
						return true;
					}
					else {
						// �����ؼ� ���ƿԴٸ� �� depth���� ��� Ž���Ѵ�
						continue;
					}
				}
				else {
					return true;
				}
			}
		}
		// 1���� 9���� ��� �Ұ����Ѱ��
		// �� depth�� �����ϰ� ���� depth�� ���ư���
		sudoku[a][b] = 0;
		return false;

	}
	else {
		// ������ ���� �̹� �ԷµǾ� ������ ���� ĭ���� DFS�� �ѱ��
		return DFS(sudoku, coordinate + 1);
	}
}
