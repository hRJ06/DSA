class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        n = len(arr)
        if k >= n:
            return max(arr)
        ans = arr[0]
        streak = 0
        for i in range(1,n):
            if arr[i] > ans:
                ans = arr[i]
                streak = 1
            else:
                streak += 1
            if streak == k or ans == max:
                return ans
        return ans

        