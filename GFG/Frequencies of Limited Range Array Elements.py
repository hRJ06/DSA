class Solution:
    #Function to count the frequency of all elements from 1 to N in the array.
    def frequencyCount(self, arr, N, P):
        # code here
        Map = {}
        for i in arr:
            Map[i] = Map.get(i,0) + 1
        for i in range(N):
            if i + 1 in Map:
                arr[i] = Map[i + 1]
            else:
                arr[i] = 0
        