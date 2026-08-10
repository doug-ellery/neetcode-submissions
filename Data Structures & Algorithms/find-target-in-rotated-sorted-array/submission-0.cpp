class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(nums[l] < nums[m] && target < nums[m] && target > nums[l]){
                r = m - 1;
            }
            else if(nums[l] > nums[m] && (target > nums[l] || target < nums[m])){
                r = m - 1;
            }
            else if(nums[m] < nums[r] && nums[m] < target && target < nums[r]){
                l = m + 1;
            }
            else if(nums[m] > nums[r] && (target > nums[m] || target < nums[r])){
                l = m + 1;
            }
            else{
                if(nums[l] == target){return l;}
                if(nums[r] == target){return r;}
                if(nums[m] == target){return m;}
                break;
            }
        }
        return -1;
    }
};
