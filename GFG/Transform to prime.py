import math

class Solution:
    def prime(self, n):
        for i in range(2, math.floor(math.sqrt(n)) + 1):  
            if not n % i:
                return False
        return True

    def minNumber(self, arr, n):
        total = sum(arr)  
        add = 0
        while True:
            if self.prime(total + add):
                return add
            add += 1
