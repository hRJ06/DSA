class Solution:
    def reverseDLL(self, head):
        #return head after reversing
        if head is None:
            return head
        cur = head
        while cur is not None:
            next = cur.next
            cur.next = cur.prev
            cur.prev = next
            if next is None:
                break
            cur = next
        return cur