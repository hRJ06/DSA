class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        ans = []
        present = []
        for i in nums:
            if not present or (i - present[0] <= k and i - present[-1] <= k):
                present.append(i)
            else:
                return []
            if len(present) != 3:
                continue
            else:
                ans.append(present.copy())
                present.clear()
        if present:
            return []
        return ans