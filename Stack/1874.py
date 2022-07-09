from collections import deque


d = deque([0])
result = list()
real_result = list()

able = True

N = int(input())

num_to_push = 1
for _ in range(N):
    input_num = int(input())

    # 스택의 top을 확인한다
    stack_top = d[-1]
    if (input_num > stack_top):
        # input_num까지 stack에 push
        while(input_num >= num_to_push):
            real_result.append('+')
            d.append(num_to_push)
            num_to_push += 1

        assert input_num == d[-1]
        # pop
        real_result.append('-')
        result.append(d.pop())

    elif (input_num == stack_top):
        real_result.append('-')
        result.append(d.pop())
    
    else:
        able = False
        break

if (able):
    for i in real_result:
        print(i)
else :
    print("NO")

