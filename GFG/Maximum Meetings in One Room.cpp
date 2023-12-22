//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; i++)
            v[i] = {F[i], i};
        sort(v.begin(), v.end());
        vector<int> ans;
        ans.push_back(v[0].second + 1);
        int end = v[0].first;
        for(int i = 1; i<N; i++) {
            if(S[v[i].second] > end) {
                ans.push_back(v[i].second + 1);
                end = v[i].first;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};