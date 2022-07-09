from collections import deque
from functools import cmp_to_key


def bruteforce(h: int):
    global B
    global save
    B_ = B
    able = True
    time = 0

    for i in range(len(map)):
        for j in range(len(map[i])):
            cur_height = map[i][j]
            if (h > cur_height):
                B_ -= (h - cur_height)
                time += (h-cur_height)
            elif (h < cur_height):
                B_ += (cur_height - h)
                time += 2*(cur_height - h)

    if (B_ >= 0):
        # (시간, 높이)를 저장한다
        save.append((time, h))


def compare(t1: tuple, t2: tuple):
    if (t1[0] < t2[0]):
        return -1
    elif (t1[0] > t2[0]):
        return 1
    else:
        if (t1[1] > t2[1]):
            return -1
        else:
            return 1


N, M, B = map(int, input().split())
save = list()
map = [list(map(int, input().split())) for n in range(N)]

min_height = 999
max_height = -1

for i in range(len(map)):
    for j in range(len(map[i])):
        min_height = min(min_height, map[i][j])
        max_height = max(max_height, map[i][j])

for h in range(min_height, max_height + 1):
    bruteforce(h)

save = sorted(save, key=cmp_to_key(compare))

print(save[0][0], save[0][1])
