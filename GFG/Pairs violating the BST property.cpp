// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  private:
    int f3(vector<int> &v, int start, int mid, int end){
        vector<int> left(mid - start + 1), right(end - mid);
        for(int i = start; i<=mid; i++) left[i - start] = v[i];
        for(int i = mid + 1; i<=end; i++) right[i - mid - 1] = v[i];
        int i = 0, j = 0, k = start, ans = 0;
        while(i < left.size() and j < right.size()){
            if(left[i] >= right[j]){
                ans += left.size() - i;
                v[k++] = right[j++];
            }
            else{
                v[k++] = left[i++];
            }
        }
        while(i < left.size()) v[k++] = left[i++];
        while(j < right.size()) v[k++] = right[j++];
        return ans;
    }
    void f1(Node* root,vector<int> &v) {
        if(!root) return;
        f1(root->left,v);
        v.push_back(root->data);
        f1(root->right,v);
    }
    int f2(vector<int> &v,int s,int e) {
        if(s >= e) return 0;
        int m = s + (e - s) / 2, ans = 0;
        ans += f2(v, s, m);
        ans += f2(v, m + 1, e);
        ans += f3(v, s, m, e);
        return ans;
    }
  public:
    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        vector<int> v;
        f1(root,v);
        return f2(v,0,n - 1); 
    }
};