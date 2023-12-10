#User function Template for python3
class Solution:
    def maximumSumSubarray(self, K, Arr, N):
        # code here
        ans = float('-inf')
        total = 0
        for i in range(K):
            total += Arr[i]
        ans = max(ans, total)
        i = 0
        for j in range(K, N):
            total -= Arr[i]
            total += Arr[j]
            i += 1
            ans = max(ans, total)
        return ans
