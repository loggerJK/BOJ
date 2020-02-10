#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPossible(int sudoku[10][10], int a, int b);
bool DFS(int sudoku[10][10], int coordinate);

int main() {
	int sudoku[10][10]; // 9X9 스도쿠 배열

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
	// 가로 검사
	for (int j = 1; j <= 9; j++) {
		int tmp = sudoku[a][j];
		horizontal[tmp]++;
	}
	for (int i = 1; i <= 9; i++) {
		if (horizontal[i] > 1)
			return false;
	}
	//세로 검사
	for (int i = 1; i <= 9; i++) {
		int tmp = sudoku[i][b];
		vertical[tmp]++;
	}
	for (int i = 1; i <= 9; i++) {
		if (vertical[i] > 1)
			return false;
	}
	// square 검사
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

	for (int x = 1; x <= 9; x++) { // 0이 여러개 나올 수도 있다.
		if (square[x] > 1) {
			//printf("(%d, %d)\n", x, square[x]);
			return false;
		}

	}

	return true;


}

bool DFS(int sudoku[10][10], int coordinate) {
	// 좌표를 (a,b)형식으로 변환
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
		//스도쿠가 0이면 대입 가능한 값을 찾는다
		
		for (int i = 1; i <= 9; i++) {
			sudoku[a][b] = i;
			// 대입 가능한 값이 있다면 대입한다
			if (isPossible(sudoku, a, b)) {
				
				// 다음 칸으로 DFS를 넘긴다
				if (coordinate != 81) {
					bool chk = DFS(sudoku, coordinate + 1);

					if (chk == true) {
						// 성공해서 돌아왔으면 더 이상 탐색을 하지 않고 종료한다
						return true;
					}
					else {
						// 실패해서 돌아왔다면 그 depth에서 계속 탐색한다
						continue;
					}
				}
				else {
					return true;
				}
			}
		}
		// 1부터 9까지 모두 불가능한경우
		// 그 depth는 리셋하고 이전 depth로 돌아간다
		sudoku[a][b] = 0;
		return false;

	}
	else {
		// 스도쿠 값이 이미 입력되어 있으면 다음 칸으로 DFS를 넘긴다
		return DFS(sudoku, coordinate + 1);
	}
}
