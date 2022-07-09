import enum
from functools import cmp_to_key
from collections import deque


def compare(t1: tuple, t2: tuple):
    if (t1[1] > t2[1]):
        return -1
    elif (t1[1] == t2[1]):
        return 0
    else:
        return 1


TC = int(input())

for tc in range(TC):
    N, M = map(int, input().split())
    input_list = list()
    sorted_list = list()

    tmp_input_list = list(map(int, input().split()))        # [1 1 9 1 1 1]

    # list of (번호, 중요도)
    # [(0,1), (1,1), (2,9), (3,1), (4,1), (5,1)]
    input_list = [(num, i) for num, i in enumerate(tmp_input_list)]
    input_list = deque(input_list)

    # 중요도 순으로 정렬한다
    sorted_list = sorted(input_list, key=cmp_to_key(compare))
    sorted_list = deque(sorted_list)

    final = list()

    while (input_list):
        # 길이가 같은지 확인
        assert len(input_list) == len(sorted_list)

        # 중요도가 같은지 확인
        if (input_list[0][1] == sorted_list[0][1]):
            # 둘 다 pop, 번호를 final에 저장
            final.append(input_list.popleft()[0])
            sorted_list.popleft()
        else:
            input_list.append(input_list.popleft())

    # print(final)

    for step, i in enumerate(final):
        if (i == M):
            print(step + 1)
