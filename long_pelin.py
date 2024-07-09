def long_pelin(array):
   N = len(array)
   dp = [[0]*N for _ in range(N)]
   max_value = 1
   for idx in range(N):
       for start in range(N-idx):
           end = start+idx
           if idx == 0:
               dp[start][end] = 1
           elif idx == 1:
               if array[start] == array[end]:
                   dp[start][end] = 1
                   max_value = idx+1
           else:
               if array[start] == array[end] and dp[start+1][end-1] == 1:
                   dp[start][end] = 1
                   max_value = max(max_value,idx+1)
   return max_value
