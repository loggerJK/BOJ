#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
save the information about snake legnth
true : snake is in there
false : snake is not in there
*/
vector<vector<bool>>snake;
/*
지도 배열
1 : 사과
0 : 빈칸
*/
vector<vector<int>>map;
queue<pair<int,int>> tail;
int direction_info[10000] = {0,};

int N = 0, K = 0, L = 0;

void turnRight (int& cur_dir)
{
	if (cur_dir == 3)
		cur_dir = 0;
	else
		cur_dir++;

	return;
}

void turnLeft(int& cur_dir)
{
	if (cur_dir == 0)
		cur_dir = 3;
	else
		cur_dir--;
	
	return;
}

void forwardStep (int& cur_dir, int& cur_x, int& cur_y)
{
	switch(cur_dir)
	{
		case 0 :
			cur_x--;
			break;
		case 1 :
			cur_y++;
			break;
		case 2 :
			cur_x++;
			break;
		case 3 :
			cur_y--;
			break;
	}
	return;
		
}

int main ()
{
	cin >> N >> K ;
	
// 	배열 초기화
	for (int i = 0; i < N; i++)
	{
		vector<bool>row_snake;
		vector<int>row_map;
		for (int j = 0; j < N; j++)
		{
			row_snake.push_back(false);
			row_map.push_back(0);
		}
		snake.push_back(row_snake);
		map.push_back(row_map);
	}
	
	for (int k = 0; k < K; k++)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		map[x-1][y-1] = 1;
	}
	
	cin >> L;
	for (int l = 0; l < L; l++)
	{
		int input1 = 0;
		char input2 = 0;
		cin >> input1 >> input2;
		direction_info[input1] = input2;
	}
	
	// init snake status
	int cur_dir = 1, cur_x = 0, cur_y = 0;
	snake[cur_x][cur_y] = true;
	// 초
	int X = 0;
	tail.push(make_pair(cur_x,cur_y));
	
	// update currrent status
	forwardStep(cur_dir, cur_x, cur_y);
	
	// cur_x와 cur_y를 탐색한다
	while(true)
	{
	

		// 벽이거나 자기 자신이면 반복문 종료
		if (cur_x < 0 || cur_x >= N || cur_y < 0 || cur_y >= N || snake[cur_x][cur_y] == true)
			break;
		
		// 초 증가
		X++;
		snake[cur_x][cur_y] = true;
		
		// cout << "x =" << cur_x << ", y = " << cur_y <<  ", X = " << X << ", cur_dir = " << cur_dir << "\n";

		

		// 사과 여부 체크
		if (map[cur_x][cur_y] == 1)
		{
			// 사과가 존재한다면 몸 길이를 늘리면서 이동한다
			// 사과는 없어진다
			map[cur_x][cur_y] = 0;
		}
		else 
		{
			// 사과가 존재하지 않는다면 꼬리를 삭제하고 이동한다
			snake[tail.front().first][tail.front().second] = false;
			tail.pop();
		}
		
		tail.push(make_pair(cur_x,cur_y));
		
		// 다음 탐색할 노드를, 방향 전환을 고려해서 정한다
		if (direction_info[X] == 'L')
			turnLeft(cur_dir);
		else if (direction_info[X] == 'D')
			turnRight(cur_dir);
		
		// update currrent stauts
		forwardStep(cur_dir, cur_x, cur_y);
	}
	
	cout << ++X;
}

