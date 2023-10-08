class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node *cur = head, *prev = NULL;
        while(cur and cur->data <= data) {
            prev = cur;
            cur = cur->next;
        }
        Node* node = new Node(data);
        if(!prev) {
            if(head->data < data) {
                node->next = head->next;
                head->next = node;
                return head;
            }
            node->next = head;
            return node;
        }
        else {
            node->next = prev->next;
            prev->next = node;
        }
        return head;
    }
};