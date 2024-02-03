class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
           long long unsigned int ans = 0;
           Node* t = head;
           while(t){
               ans = (ans * 2 + t->data) % 1000000007;
               t = t->next;
           }
           return ans;
        }
};