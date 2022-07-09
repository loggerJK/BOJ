# Python PS 팁 정리

## INPUT : 'This is test string'
- `input()` : str
  - `This is test string`
- `input().split()` : list
  - `['This', 'is', 'test', 'string']`
- `list(input())`
  - `['T', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g']`
- `input().replace(' ', '')`
  - `Thisisteststring`

## 정렬
```python
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
        

s = list(s)
s = sorted(s, key=cmp_to_key(compare))
```