class Solution:
    def transitionPoint(self, arr, n): 
        # Code here
        ans = 0
        for i in arr:
            if not i:
                ans += 1
            if i:
                return ans
        return -1

