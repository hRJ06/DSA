/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int bs1(int s,int e,MountainArray &mountainArr,int k) {
        while(s <= e) {
            int m = s + (e - s) / 2;
            if(mountainArr.get(m) < k) 
                s = m + 1;
            else if(mountainArr.get(m) > k)
                e = m - 1;
            else
                return m;
        }
        return -1;
    }
    int bs2(int s,int e,MountainArray &mountainArr,int k) {
        while(s <= e) {
            int m = s + (e - s) / 2;
            if(mountainArr.get(m) < k) 
                e = m - 1;
            else if(mountainArr.get(m) > k)
                s = m + 1;
            else
                return m;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int left = 0, right = n - 2, ans = -1;
        while(left <= right) {
            int m = left + (right - left) / 2;
            if(mountainArr.get(m) < mountainArr.get(m + 1)) {
                left = m + 1;
            }
            else {
                ans = m;
                right = m - 1;
            }
        }
        int f = bs1(0,ans,mountainArr,target);
        return f != -1 ? f : bs2(ans + 1, n - 1,mountainArr,target);
    }
};