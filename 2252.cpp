#include <iostream>
#define maxN 32000
#define maxM 100000 // 10^5
using namespace std;

// 노드들의 인덱스는 [1:maxN], 0이라면 부모 노드가 존재하지 않는다는 의미이다.
int parent[maxN + 100] = {0,};
int root[maxN + 100] = {0,};

int N = 0, M = 0;

int main() {
	cin >> N >> M;
	
	for (int i = 0 ; i < M; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		// a의 부모가 b이다
		parent[a] = b;
	}
}