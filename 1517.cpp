/* 
<버블 소트>
Category : Inversion Counting
요약 :
Merge Sort를 이용해서 Inversion Counting을 O(nlogn)으로 해결할 수 있다
 */

#include <iostream>
#define maxN 500000
#define ull unsigned long long
using namespace std;

int A[maxN + 10] = {
    0,
};
int tempA[maxN + 10] = {
    0,
};
int N = 0;

ull inversionCounting(int A[maxN + 1], int start, int end)
{
    /* 
    배열 정보 : [start, end)
    받은 배열을 둘로 쪼갠다
    merge sort를 이용해 두 배열을 정렬한다
    두 배열을 합칠때 inversion의 개수를 카운트한다
    inversion의 개수를 리턴한다
    */
    int mid = (start + end) / 2;

    // 배열이 한개인 경우  : No Inversion
    if (start >= mid)
        return 0;

    // 두 배열로 쪼갠 후, 각각의 배열에서 Inversion Counting
    ull left_cnt, right_cnt, prev_cnt = 0;
    left_cnt = inversionCounting(A, start, mid);
    right_cnt = inversionCounting(A, mid, end);
    prev_cnt += left_cnt + right_cnt;

    // 원본 배열은 미리 복사를 해둔다
    copy(A + start, A + end, tempA + start);

    // 두 배열 간의 merge sort를 진행한다
    /*  
    cnt : inversion의 개수 카운팅 변수
    answer : 두 배열을 합치면서 발생하는 inversion의 총 개수
    merger sort의 결과는 tempA 배열에 저장한다
    */
    ull left_idx = 0, right_idx = 0, pointer_origin = 0, cnt = 0, answer = 0;
    left_idx = start;
    right_idx = mid;
    pointer_origin = start;

    while (left_idx < mid || right_idx < end)
    {
        if (left_idx >= mid)
        {
            for (int s = right_idx; s < end;)
            {
                tempA[pointer_origin] = A[s];
                s++;
                pointer_origin++;
            }
            break;
        }

        if (right_idx >= end)
        {
            // 모두 inversion
            for (int f = left_idx; f < mid;)
            {
                tempA[pointer_origin] = A[f];
                f++;
                pointer_origin++;
            }
            answer += cnt;
            cnt = 0;
            break;
        }

        // inversion이 발생하면
        if (A[left_idx] > A[right_idx])
        {
            // sort
            tempA[pointer_origin] = A[right_idx];
            // inversion counter 증가
            cnt++;
            right_idx++;
            pointer_origin++;
        }
        else
        {
            // inversion이 아닌경우
            tempA[pointer_origin] = A[left_idx];
            answer += cnt;
            left_idx++;
            pointer_origin++;
        }
    }

    // sort한 결과를 반영
    copy(tempA + start, tempA + end, A + start);
    return prev_cnt + answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    // input
    for (int n = 0; n < N; n++)
    {
        cin >> A[n];
    }

    cout << inversionCounting(A, 0, N);

    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
}
