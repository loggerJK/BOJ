from functools import cmp_to_key

def compare(s1, s2):
    # s1, s2순으로 있다고 할 때, 그대로 유지되어야 하는 경우에 -1을 리턴
    if len(s1) < len(s2) :
        return -1
    elif len(s1) > len(s2) :
        return 1
    else :
        if s1 < s2 :
            return -1
        else :
            return 1
        

s = set()

N = int(input())

for i in range(N):
    s.add(input())

s = list(s)
s = (sorted(s, key=cmp_to_key( compare)))

print(s)
# for i in s:
#     print(i)
