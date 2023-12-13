class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        R = {}
        C = {}
        m = len(mat)
        n = len(mat[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j]:
                    R[i] = R.get(i,0) + 1
                    C[j] = C.get(j,0) + 1
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1 and R.get(i) == 1 and C.get(j) == 1:
                    ans += 1
        return ans

