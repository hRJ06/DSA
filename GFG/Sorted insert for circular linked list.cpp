class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
       Node* node = new Node(data);
       Node* t = head;
       if(!head) {
           node->next = node;
           return node;
       }
       if(head->data > data) {
           while(t->next != head) t = t->next;
           node->next = head;
           t->next = head;
           t->next = node;
           return node;
       }
       while(t->next != head and t->next->data <= data) t = t->next;
       node->next = t->next;
       t->next = node;
       return head;
    }
};