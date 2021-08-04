/*  
https://www.acmicpc.net/problem/1043
1043 : 거짓말

전략
원래 모두 white(=0)였는데
계속 black(=1)이 퍼져나간다

주의점
사람들 번호 [1:N]
파티 번호 [0:M-1]

출력
white인 party의 개수

*/
#include <iostream>
#include <vector>
#include <queue>
#define white 0 // 진실
#define black 1 // 거짓
#define yes 1
#define no 0
using namespace std;

int N = 0, M = 0;
vector<int> party;
vector<int> people;
/* 
[i][j] : i번 파티에 j번 사람이 참석하는지 유무
 */
int adjList[60][60] = {
    no,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    //초기화
    for (int i = 0; i <= N; i++)
        people.push_back(white);

    for (int i = 0; i < M; i++)
        party.push_back(white);

    queue<int> peopleQ;
    queue<int> partyQ;

    // 맨 처음 진실을 알고 있었던 사람들
    int num_whoKnowsTruth = 0;
    cin >> num_whoKnowsTruth;
    for (int i = 0; i < num_whoKnowsTruth; i++)
    {
        int input = 0;
        cin >> input;
        peopleQ.push(input);
    }

    for (int i = 0; i < M; i++)
    {
        // i번째 파티에 오는 사람들
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int person = 0;
            cin >> person;
            adjList[i][person] = yes;
        }
    }
    while (!peopleQ.empty() || !partyQ.empty())
    {

        while (!peopleQ.empty())
        {
            int person = 0;
            person = peopleQ.front();
            peopleQ.pop();

            /*  
        연결된 파티를 조사한다
        파티가 white인 경우 black으로 변경한다
        업데이트된 파티는 큐에 푸쉬된다
        */
            for (int i = 0; i < M; i++)
            {
                if (adjList[i][person] == yes)
                    if (party[i] == white)
                    {
                        // party를 black으로 전염시킨다
                        party[i] = black;
                        // 큐에 푸쉬한다
                        partyQ.push(i);
                    }
            }
        }
        while (!partyQ.empty())
        {
            int party_idx = 0;
            party_idx = partyQ.front();
            partyQ.pop();

            for (int i = 1; i <= N; i++)
            {
                if (adjList[party_idx][i] == yes)
                    if (people[i] == white)
                    {
                        // i번 사람을 black으로 전염시킨다
                        people[i] = black;
                        // 큐에 푸쉬한다
                        peopleQ.push(i);
                    }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < M; i++)
        if (party[i] == white)
            cnt++;

    cout << cnt;
}