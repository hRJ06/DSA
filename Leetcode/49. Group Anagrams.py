class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        Map = {}
        n = len(strs)
        for i in range(n):
            s = strs[i]
            store = sorted(s)
            if tuple(store) not in Map:
                Map[tuple(store)] = []
            Map[tuple(store)].append(s)
        ans = []
        for key,value in Map.items():
            ans.append(value)
        return ans