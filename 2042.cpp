/*
2042 : 구간 합 구하기
세그먼트 트리
*/
#include <iostream>
#incldue <vector>
#define ll long long
using namespace std;

/*
리프 노드의 개수는 N개
리프 노드 범위 [N-1, 2N-2]
총 index = [0, 2N-2], 2N-1개
a의 root = (a-1)/2
a의 leaf nodes = 2a+1, 2a+2
*/
vector<ll> segTree(2000000); // 2* 10^6개, 0으로 초기화

int N = 0, M = 0, K = 0, max_size = 0;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	
	cin >> N >> M >> K;
	
	max_size = 2 * N - 1;
	
	// 리프 노드들 값을 입력
	for (int idx = N-1; idx <= 2*N-2; idx++)
	{.
		
		ll input = 0;
		cin >> input;
		segTree[idx] = input;
	}
	
	// build whole segment tree
	for (int idx = N-2; idx >=0; idx--)
	{
		segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
	}
	
	
	for (int i = 0; i < M+K; i++)
	{
		int case = 0;
		cin >> case;
		
		if (case == 1)
		{
			// change b to c
			update(b,c);
		}
		else if (case == 2)
		{
			// get sum [b:c]
			getSum(b,c);
		}
	}
}

