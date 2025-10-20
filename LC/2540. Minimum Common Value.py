class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        Set = set()
        for i in nums1:
            Set.add(i)
        for i in nums2:
            if i in Set:
                return i
        return -1