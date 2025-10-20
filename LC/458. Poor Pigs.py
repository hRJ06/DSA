class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        trial = (minutesToTest / minutesToDie) + 1
        pig = 0
        while trial ** pig < buckets:
            pig += 1
        return pig

        