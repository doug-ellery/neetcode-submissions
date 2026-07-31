class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        pair<int,int> range = {nums[0], nums[0]};
        std::unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++){
            set.insert(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            int start = nums[i];
            pair<int,int> temp = {start, start};
            int finish = nums[i] + 1;
            if(set.find(start - 1) == set.end()){
                while(set.find(finish) != set.end()){
                    temp.second++;
                    finish++;
                }
                if(temp.second - temp.first > range.second - range.first){
                    range = temp;
                }
            }
        }
        return range.second - range.first + 1;
    }
};
