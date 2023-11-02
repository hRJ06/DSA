class Solution:
    def minDist(self, arr, n, x, y):
        ans = -1
        i = -1
        j = -1
        for index in range(n):
            if arr[index] == x:
                i = index
            elif arr[index] == y:
                j = index
            if i != -1 and j != -1:
                dist = abs(j - i)
                if dist < ans or ans == -1:
                    ans = dist
        return ans
    

