class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        i = 0
        j = 0
        while j < n:
            if arr[j] != arr[i]:
                i = j
            else:
                if (j - i + 1) / n > 0.25:
                    return arr[i]
            j += 1
        return -1

        
        