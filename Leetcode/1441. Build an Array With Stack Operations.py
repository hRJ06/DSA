class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans = []
        i = 1
        for j in target:
            while i < j:
                ans.append("Push")
                ans.append("Pop")
                i += 1
            ans.append("Push")
            i += 1
        return ans

