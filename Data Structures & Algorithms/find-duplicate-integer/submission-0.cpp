class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 2){
            return nums[0];
        }
        int fast = 0, slow = 0;
        fast = nums[nums[fast]];
        slow = nums[slow];
        while(fast != slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        int slow_2 = 0;
        while(slow_2 != slow){
            slow_2 = nums[slow_2];
            slow = nums[slow];
        }
        return slow;
    }
};
