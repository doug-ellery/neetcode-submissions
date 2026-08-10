class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(nums[m] < nums[l]){
                if(m == 0 || nums[m] < nums[m - 1]){
                    return nums[m];
                }
                r = m - 1;
            }
            else if(nums[r] < nums[m]){
                l = m + 1;
            }
            else{
                return nums[l];
            }
        }
        return nums[l];
    }
};
