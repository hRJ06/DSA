class Solution:
    def findIntersection(self,head1,head2):
        #return head
        head = None
        tail = None
        t1 = head1
        t2 = head2
        while t1 is not None and t2 is not None:
            if t1.data > t2.data:
                t2 = t2.next
            elif t1.data < t2.data:
                t1 = t1.next
            else:
                if head is None:
                    head = tail = Node(t1.data)
                else:
                    tail.next = Node(t1.data)
                    tail = tail.next
                t1 = t1.next
                t2 = t2.next
        return head
