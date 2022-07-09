from math import pow
from collections import defaultdict
from pprint import pprint
import string

a : list = input().split()

N:int = int(a[0])
M:int = int(a[1])

# [i:i+7][j:j+7]
def calc(i,j):
    # 두 번
    default_color :str= 'W'
    other_color :str = 'B'
    cnt_1 = 0
    for k in range(8):
        for l in range(8):
            if (((k+l) % 2 ) == 0) :
                if chessMap[i+k][j+l] != default_color :
                    cnt_1 += 1
            else :
                if chessMap[i+k][j+l] != other_color :
                    cnt_1 += 1

    default_color :str= 'B'
    other_color :str = 'W'
    cnt_2 = 0
    for k in range(8):
        for l in range(8):
            if (((k+l) % 2 ) == 0) :
                if chessMap[i+k][j+l] != default_color :
                    cnt_2 += 1
            else :
                if chessMap[i+k][j+l] != other_color :
                    cnt_2 += 1
    
    return min(cnt_1, cnt_2)

chessMap = list()

for i in range(N):
    line = list(input())
    chessMap.append(line)

min_num = 999999
for i in range(N - 7):
    for j in range(M - 7):
        num = calc(i,j)
        min_num = min(min_num, num)

print(min_num)


