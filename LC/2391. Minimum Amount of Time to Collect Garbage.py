class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        g = 0
        p = 0
        m = 0
        n = len(garbage)
        time = 0
        for i in range(n):
            l = len(garbage[i])
            time += l
            for j in range(l):
                if garbage[i][j] == 'M':
                    m = i
                elif garbage[i][j] == 'P':
                    p = i
                else:
                    g = i
        t = len(travel)
        for i in range(1,t):
            travel[i] += travel[i - 1]
        if m > 0:
            time += travel[m - 1]
        if p > 0:
            time += travel[p - 1]
        if g > 0:
            time += travel[g - 1]
        return time

        