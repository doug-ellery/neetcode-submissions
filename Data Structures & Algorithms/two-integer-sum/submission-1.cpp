class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> sorted;
        for(int i = 0; i < nums.size(); i++){
            sorted.push_back({nums[i], i});
        }
        struct{
            bool operator()(std::pair<int,int> a, std::pair<int,int> b) const {
                return a.first < b.first;
            }
        }
        customLess;

        std::sort(sorted.begin(), sorted.end(), customLess);

        int l = 0, r = sorted.size() - 1;
        while(l < r){
            if(sorted[l].first + sorted[r].first < target){
                l++;
            }
            else if(sorted[l].first + sorted[r].first > target){
                r--;
            }
            else{
                return {std::min(sorted[l].second, sorted[r].second), std::max(sorted[l].second, sorted[r].second)};
            }
        }
        return {-1,-1};
    }    
};
