# BOJ
백준 문제풀이 소스 / BOJ Algorithm Study Source

사용 언어 : C/C++ 

# C++ STL
- `vector` : 배열(array)와 비슷하게 사용가능
- `map`
  - 파이썬의 Dictionary와 비슷함
```c
map<string, int> m;
m['jiwon'] = 1;
```
- `unordered_map`
  - map에서 정렬이 되어 있지 않은 버전 -> 더 빠르다
- `set`
  - unique한 원소들을 정렬된 상태로 보관
- `queue`
  - `priority queue`
- `tuple`
- `deque`

# 알고리즘 종류
- [X] DFS, BFS
  - DFS : stack or 반복문
  - BFS : queue
- [X] Binary Search
  - C++ `lower_bound`, `upper_bound`
- [X] Dynamic Programming
- [ ] Greedy
- [X] Priority queue
- [X] Hash Map
- [X] Union Find
- [ ] Trie
- [X] Kruskal (Minimum Spanning Tree)
- [ ] Shortest Path(최단 경로)
  - [X] Dijkstra
  - [ ] Bellman-Ford
  - [X] Floyd-Warshall
- [X] 조합(Combination)
  - [X] `next_permutation()` or `prev_permutation()`

# TIP
- `1억(10^8) == 1초`로 알고리즘의 속도를 판별해 볼 수 있다.
- 틀리는 경우에는 자료형의 크기 / 특이값 input 등에 대해 생각해보자
- 오름차순 정렬 코드

```c
// `priority_queue`
struct compare
{
    bool operator()(pii a, pii b)
    {
        return a.second > b.second;
    }
};

/* 클래스를 정의하는 경우 */
// 오름차순
bool operator<(edge &e)
{
    return this->dist < e.dist;
}

// sort()의 custom compare 함수
bool compare(edge a, edge b)
{
    return a.dist < b.dist;
}
```

- C++에서의 클래스 선언 및 사용

```c
class edge
{
public:
    // 멤버 변수 선언
    int node[2];
    int dist;
    // 생성자 선언
    edge(int a, int b, int dist)
    {
        this->node[0] = a;
        this->node[1] = b;
        this->dist = dist;
    }
};

vector.push_back(edge(a, b, dist));
```

# 주의
- `에라토스테네스의 체`는 여러 개의 숫자에 대해서 소수를 판별해야 할 때 유용하다. 하지만 지나치게 큰 숫자의 경우 (ex - 10^12)에는 배열이 너무 커지기 때문에 **메모리 초과**가 발생할 수 있다는 점을 염두에 두어야 한다.
  - 관련 문제 : k진수에서 소수 개수 구하기 (2022 KAKAO BLIND RECRUITMENT)
- 순회할 때에는 항상 `Index Error`에 주의할 것
- "대입" 연산도 O(1)이다
  - **매우 큰 크기의 배열, vector의 복사는 O(N)**이 될 수 있다.