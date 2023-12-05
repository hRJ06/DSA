class Solution:
    def getMinDiff(self, arr, n, k):
        # code here
        arr.sort()
        ans = arr[n - 1] - arr[0]
        minimum = arr[0] + k
        maximum = arr[n - 1] - k
        for i in range(n - 1):
            cur_min = min(minimum,arr[i + 1] - k)
            cur_max = max(maximum,arr[i] + k,maximum)
            if cur_min >= 0:
                ans = min(ans,cur_max - cur_min)
        return ans