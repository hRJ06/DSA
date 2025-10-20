class Solution {
private:
    int count = 0;
    int maxOr = 0;
    void f(int index, int curOr, vector<int> &nums) {
        if(index >= nums.size()) {
            if(curOr > maxOr) {
                maxOr = curOr;
                count = 1;
            }
            else if(curOr == maxOr) count++;
            return;
        }
        f(index + 1, curOr, nums);
        f(index + 1, curOr | nums[index], nums);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        f(0, 0, nums);
        return count;
    }
};