class Solution:
    def isRepresentingBST(self, arr, N):
        # code here
        for i in range(N - 1):
            if arr[i + 1] < arr[i]:
                return 0
        return 1

