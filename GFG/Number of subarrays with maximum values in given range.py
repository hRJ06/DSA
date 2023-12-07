class Solution:
    def countSubarrays(self, a,n,L,R): 
        # Complete the function
        size = 0
        ans = 0
        start = 0
        for end in range(n):
            if a[end] >= L and a[end] <= R:
                size = end - start + 1
            elif a[end] >= R:
                size = 0
                start = end + 1
            ans += size
        return ans