class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        time = max(abs(fx - sx),abs(fy - sy))
        if not time and t == 1:
            return False
        return t >= time