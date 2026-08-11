class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lower_bound = 0; 
        int upper_bound = min(nums1.size(), nums2.size());
        int left_choice  = 0, other_left_choice = 0;
        int half = (nums1.size() + nums2.size()) / 2;
        const auto& small_one = nums1.size() == upper_bound ? nums1 : nums2;
        const auto& large_one = nums1.size() == upper_bound ? nums2 : nums1;
        while(lower_bound <= upper_bound){
            left_choice = (lower_bound + upper_bound) / 2;
            other_left_choice = half - left_choice;
            bool choose_more = other_left_choice > 0 && left_choice < small_one.size() &&  large_one[other_left_choice - 1] > small_one[left_choice];
            bool choose_less = left_choice > 0 && small_one[left_choice - 1] > large_one[other_left_choice];
            if(choose_more){
                lower_bound = left_choice + 1;
            }
            else if(choose_less){
                upper_bound = left_choice - 1;
            }                
            else{
                break;
            }
        }
        if((nums1.size() + nums2.size()) % 2 == 0){
                int val_1 = other_left_choice > 0 ? large_one[other_left_choice - 1] : INT_MIN;
                int val_2 = left_choice > 0 ? small_one[left_choice - 1] : INT_MIN;
                int left_val = max(val_1, val_2);
                int val_3 = other_left_choice < large_one.size() ? large_one[other_left_choice] : INT_MAX;
                int val_4 = left_choice < small_one.size() ? small_one[left_choice] : INT_MAX;
                int right_val = min(val_3, val_4);
                return ((double)(left_val + right_val)) / 2;
        }
        else{ 
            int val_3 = other_left_choice < large_one.size() ? large_one[other_left_choice] : INT_MAX;
            int val_4 = left_choice < small_one.size() ? small_one[left_choice] : INT_MAX;
            return min(val_3, val_4);
        }
    }
};
