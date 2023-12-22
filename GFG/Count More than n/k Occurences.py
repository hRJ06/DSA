#User function Template for python3


class Solution:
    
    #Function to find all elements in array that appear more than n/k times.
    def countOccurence(self,arr,n,k):
        #Your code here
        Map = {}
        for i in range(n):
            Map[arr[i]] = Map.get(arr[i],0) + 1
        ans = 0
        for i in Map:
            if Map[i] > n // k:
                ans += 1
        return ans
            
