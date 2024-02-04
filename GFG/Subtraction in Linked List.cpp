class Solution {
private:
    int getLength(Node* head) {
        if(!head) return 0;
        return 1 + getLength(head->next);
    }
    Node* reverse(Node* head) {
        Node *prev = NULL, *cur = head, *next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while(head1 and !head1->data) head1 = head1->next;
        while(head2 and !head2->data) head2 = head2->next;
        int s1 = getLength(head1), s2 = getLength(head2);
        if(!s1 and !s2) return new Node(0);
        if(s2 > s1) {
            Node* t = head1;
            head1 = head2;
            head2 = t;
        }
        if(s2 == s1) {
            Node *t1 = head1, *t2 = head2;
            while(t1->data == t2->data) {
                t1 = t1->next;
                t2 = t2->next;
                if(!t1) return new Node(0);
            }
            if(t2->data > t1->data) {
                Node* t = head1;
                head1 = head2;
                head2 = t;
            }
        }
        Node* h1 = reverse(head1);
        Node* h2 = reverse(head2);
        Node* ans = NULL;
        while(h1) {
            int n1 = h1->data, n2 = 0;
            if(h2) n2 = h2->data;
            if(n1 < n2) {
                if(h1->next) {
                    h1->next->data -= 1;
                    n1 += 10;
                }
            }
            Node* node = new Node(n1 - n2);
            node->next = ans;
            ans = node;
            h1 = h1->next;
            if(h2) h2 = h2->next;
        }
        while(ans and ans->next) {
            if(!ans->data) ans = ans->next;
            else break;
        }
        return ans;
    }
};