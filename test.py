from __future__ import print_function

def solution(distance, rocks, n):
    answer = 0
    left = 1
    right = 20
    rocks.sort()
    while left <= right:
        mid = (left + right) // 2
        print('mid:', mid)
        pre_rock = 0
        num_of_rock = 0
        m_min = 1000000001
        for rock in rocks:
            if rock - pre_rock < mid:
                num_of_rock += 1
                print('rock:', rock)
            else:
                m_min = min(m_min, rock - pre_rock)
                pre_rock = rock

        print('num_of_rock:', num_of_rock)
        if num_of_rock > n:
            right = mid - 1
        else:
            answer = m_min
            left = mid + 1
            
    return answer

print(solution(15, [10, 13, 14], 2)) # 10
