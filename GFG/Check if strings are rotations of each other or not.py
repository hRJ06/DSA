class Solution:
    def areRotations(self,s1,s2):
        return True if s2 in s1 + s1 else False