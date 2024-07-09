# BOJ
백준 문제풀이 소스 / BOJ Algorithm Study Source

사용 언어 : C/C++ 

# C++ STL
- `vector` : 배열(array)와 비슷하게 사용가능
- `set`, `multiset`
  - RedblackTree 기반
  - 검색 삽입 삭제 O(logN)
  - unique한 원소, multi는 중복 O
  - 정렬 (default : 오름차순)
  - `find()` -> iter, `count()` -> int,
  - `insert()`는 `pair<iterator, bool>` 반환
    - `iterator` : point inserted element
    - `bool` : 성공 여부, 실패 시 삽입 X
- `unordered_set`
  - `#include <unordered_set>`
  - Hash Table
- `map`, `multimap`
  - `#include <map>`
  - RedblackTree 기반
  - 검색 삽입 삭제 O(logN)
  - key값 기준 **정렬**
  - 파이썬의 Dictionary
  - `set`과 다르게 `[]`를 사용하여 대입 가능. 단, 참조만 해도 값을 생성해버리니 주의!!!!
    ```c
    map<string, int> m;
    m['jiwon'] = 1;
    ```
- `unordered_map`
  - `#include <unordered_map>`
  - Hash Table
  - O(1), 최악 O(N) (Hash Collision)
  - map에서 정렬이 되어 있지 않은 버전 -> 더 빠르다
  - 중복 허용 X
- `stack`
- `queue`
  - `priority queue`
- `tuple`
- `deque`
  - vector의 확장
  - `push_front() / pop_front()` 가능

# 자료구조 종류
- Array, Linked List
- Stack, Queue
- Tree, Graph
- Heap

# 알고리즘 종류
- [X] DFS, BFS
  - DFS : stack or 반복문
  - BFS : queue
- [X] Binary Search
  - C++ `binary_search`,`lower_bound`, `upper_bound` (`<algorithm>`)
    - `first == last`라면 (값에 상관없이, 혹은 비어있는 경우)
      - `binary_search` false
      - `bound` : `first` == `last` 반환
    - `first < last` 조건을 철저히 지켜줘야 함!
    - 찾는 val이 없다면, "val 이후의 첫번째 값" (`end()`)를 반환
    - lower_bound
      - 해당 배열 내 값 X $\not\implies$ `end()` 반환
      - `end()` 반환 -> 해당 배열 내 값 X
      - `begin()` 반환 -> 값 O OR Index 0에 다음 값
    - upper_bound
      - `begin()` 반환 -> 해당 배열 내 값 X
      - `end()` 반환 -> 값 O OR Index Last에 다음 값
- [X] Dynamic Programming
- [X] Greedy
- [X] Priority queue
- [X] Hash Map
- [X] Union Find
  - 무방향 그래프, 동일 그룹 판단
  - 방문하려는 노드의 부모가 동일 -> 사이클
- [ ] Trie
- [X] Kruskal (Minimum Spanning Tree)
  - 최소 가중치 간선부터 N-1개 선택하는 그리디 알고리즘
- [ ] Shortest Path(최단 경로)
  - [X] Dijkstra
  - [ ] Bellman-Ford
  - [X] Floyd-Warshall
- [X] 조합(Combination)
  - [X] `next_permutation()` or `prev_permutation()`
- [ ] 분할정복
- [ ] 위상정렬
  - 방향 그래프
  - Indegree가 0인 노드부터, 삭제해가며 BFS
  - 큐에 들어온 순서 = 위상 정렬 순서
  - 방문하지 않은 노드 존재 => 사이클

# TIP
- 2D `vector` 생성
```c 
  vector<vector<int>> tmp(n, vector<int>(m, 0));
  vector<vector<int>> edge(10, vector<int>{});
```
- DFS 2번으로, 그래프에서 가장 긴 path를 찾을 수 있다.
- `#include <limits>` -> INT_MIN, LLONG_MIN
- Anagram 판별 : Sorting
- N개의 정점을 사이클 없이 연결하기 위해서는 정확히 N-1개의 간선이 필요하다. 
- `1억(10^8) == 1초`로 알고리즘의 속도를 판별해 볼 수 있다.
- 틀리는 경우에는 자료형의 크기 / 특이값 input 등에 대해 생각해보자
- default = less = 오름차순 정렬 코드
  - `>=`, `<=` 사용 금지

```c
/* 클래스를 정의하는 경우 */
// 오름차순
bool operator<(edge &e)
{
    return this->dist < e.dist;
}

// sort()의 custom compare 함수
// 순서대로 a -> b가 들어왔는데, 그대로 유지되기를 원하면 True
bool compare(edge a, edge b)
{
    return a.dist < b.dist;
}

// `priority_queue`
// Minheap일 때 오름차순 : struct + 혼자 operator() + 부등호 반대
struct compare
{
    bool operator()(pii b, pii a)
    {
        return a.second < b.second;
    }
};
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

- 이분탐색 직접 구현
```c
while (left <= right)
{
  mid = (left + right) / 2;
  if (mid == target)
  else if (mid < target) left = mid + 1;
  else right = mid - 1;
}

// left == right가 되는 순간을 찾아간다
while (left != right)
{
  mid = (left + right) / 2;
  if (mid < target) left = mid + 1;
  else right = mid;
}
```


# 주의
- `에라토스테네스의 체`는 여러 개의 숫자에 대해서 소수를 판별해야 할 때 유용하다. 하지만 지나치게 큰 숫자의 경우 (ex - 10^12)에는 배열이 너무 커지기 때문에 **메모리 초과**가 발생할 수 있다는 점을 염두에 두어야 한다.
  - 관련 문제 : k진수에서 소수 개수 구하기 (2022 KAKAO BLIND RECRUITMENT)
- 순회할 때에는 항상 `Index Error`에 주의할 것
- "대입" 연산도 O(1)이다
  - **매우 큰 크기의 배열, vector의 복사는 O(N)** 이 될 수 있다.
- Stack, Queue의 iterator는 없다.
  - Queue의 경우는 deque를 활용
- Set은 iterator를 통해서만 접근 가능하다
- iterable 자료구조는 다음과 같이 활용할 수 있다
  - `for (auto& elem : vector)`
- 자료형 크기
  - `int` : +- $2 \times 10^9$ (= $2^{32}$)
  - `long long` : +- $9 \times 10^{18}$ (= $2^{64}$)
- `DFS` 에서 visit 배열을 인자로 넘겨주는 경우, 계속 copy가 일어나기 때문에 시간초과가 뜰 수 있다.

# 참고
- [블로그](https://www.tutorialspoint.com/cpp_standard_library/deque.htm)
- [C++ Sort](https://blockdmask.tistory.com/178)
- [C++ String](https://rebro.kr/53) 
- [Stack](https://life-with-coding.tistory.com/406)
- [Queue](https://life-with-coding.tistory.com/408)
- [Tuple](https://novlog.tistory.com/entry/C-tuple-%EC%82%AC%EC%9A%A9%EB%B2%95-%EC%98%88%EC%A0%9C)
- [vector](https://blockdmask.tistory.com/70)
- [deque](https://blockdmask.tistory.com/73)
- [Priority Queue](https://kbj96.tistory.com/15)
- [STL 시간복잡도](https://blog.naver.com/yoochansong/221739086178)
- [Set](https://blockdmask.tistory.com/79)
- [Split / Tokenizing](https://novlog.tistory.com/entry/C-Tokenizing-%EB%AC%B8%EC%9E%90%EC%97%B4-%ED%8C%8C%EC%8B%B1-split-with-find-substr?category=885399)
