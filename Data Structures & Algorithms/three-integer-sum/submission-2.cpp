class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){break;}
            if(i > 0 && nums[i] == nums[i - 1]){continue;}
            int l = i + 1;
            int r = nums.size() - 1;
            int target = 0 - nums[i];
            while(l < r){
                if(nums[l] + nums[r] > target){r--;}
                else if(nums[l] + nums[r] < target){l++;}
                else{
                    triplets.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]){
                        l++;
                    }
                    while(l < r && nums[r] == nums[r + 1]){
                        r--;
                    }
                }
            }
        }
        return triplets;
    }
};
