#User function Template for python3

class Solution:
    def pushZerosToEnd(self,arr, n):
        # code here
        count = 0
        for i in range(n):
            if arr[i] != 0:
                arr[count] = arr[i]
                count += 1
        for i in range(count,n):
            arr[i] = 0
            
