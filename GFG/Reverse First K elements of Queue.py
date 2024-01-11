class Solution:
    def modifyQueue(self, q, k):
        # code here
        store = []
        while k > 0:
            store.append(q.pop(0))
            k -= 1
        for i in store:
            q.insert(0,i)
        return q