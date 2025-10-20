typedef long long ll;
class Solution {
private:
    vector<vector<ll>> dp;
    ll f(int ri,int fi,vector<int> &r, vector<int> &fact) {
        if(ri >= r.size()) return 0;
        if(fi >= fact.size()) return 1e16;
        if(dp[ri][fi] != -1) return dp[ri][fi];
        ll take = abs(fact[fi] - r[ri]) + f(ri + 1, fi + 1, r, fact);
        ll not_take = f(ri, fi + 1, r, fact);
        return dp[ri][fi] = min(take, not_take);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        /* Why Greedy fails ?
        Take an example 
        <---R0--- ---R1---R2---->
                F0(2)     F1(2)
            0   2    4    6

        If I go greedy and allocate Robot to each factory from left until one factory reach capacity, then
        a) Suppose F1 here insteaf of position 6 is at position 5 then it would have been optimal to allocate R1 to factory F1
        b) Again suppose if F1 has a capacity of 1 instead of 2 then even if we allocate R1 to F1, then we will have no choice but to allocate
           R2 to F0 which in turn increase the distance again.
        c) Suppose F1 is at 5 with capacity of 2 so for R1 and R2 it will be optimal to allocate to F1 but suppose another R3 comes after R2?
            i. Then it would have been optimal to allocate R1 -> F0, R2 -> F1, R3 -> F1.
        So optimal way is to try all possible cases
        */
        vector<int> fact;
        for(auto &i : factory) 
            for(int j = 0; j<i[1]; j++)
                fact.push_back(i[0]);
        /* We expand factory to simplify dp by not explicitly keeping track of whether factory limit has been exceeded or not */
        sort(robot.begin(), robot.end());
        sort(fact.begin(), fact.end());
        int n = robot.size(), m = fact.size();
        dp.resize(n, vector<ll>(m, -1));
        return f(0, 0, robot, fact);
    }
};