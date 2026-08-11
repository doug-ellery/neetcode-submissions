class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lower_bound = 0; 
        int upper_bound = min(nums1.size(), nums2.size());
        bool nums_1_smallest = nums1.size() == upper_bound;
        int left_choice  = 0, other_left_choice = 0;
        int half = (nums1.size() + nums2.size()) / 2;
        while(lower_bound <= upper_bound){
            left_choice = (lower_bound + upper_bound) / 2;
            other_left_choice = half - left_choice;
            if(nums_1_smallest){
                bool choose_more = other_left_choice > 0 && left_choice < nums1.size() &&  nums2[other_left_choice - 1] > nums1[left_choice];
                bool choose_less = left_choice > 0 && nums1[left_choice - 1] > nums2[other_left_choice];
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
            else{
                bool choose_more = other_left_choice > 0 && left_choice < nums2.size() && nums1[other_left_choice - 1] > nums2[left_choice];
                bool choose_less = left_choice > 0 && nums2[left_choice - 1] > nums1[other_left_choice];
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
        }
        if((nums1.size() + nums2.size()) % 2 == 0){
                if(!nums_1_smallest){
                    int temp = other_left_choice;
                    other_left_choice = left_choice;
                    left_choice = temp;
                }
                int val_1 = other_left_choice > 0 ? nums2[other_left_choice - 1] : INT_MIN;
                int val_2 = left_choice > 0 ? nums1[left_choice - 1] : INT_MIN;
                int left_val = max(val_1, val_2);
                int val_3 = other_left_choice < nums2.size() ? nums2[other_left_choice] : INT_MAX;
                int val_4 = left_choice < nums1.size() ? nums1[left_choice] : INT_MAX;
                int right_val = min(val_3, val_4);
                return ((double)(left_val + right_val)) / 2;
        }
        else{
           if(!nums_1_smallest){
                    int temp = other_left_choice;
                    other_left_choice = left_choice;
                    left_choice = temp;
                } 
            int val_3 = other_left_choice < nums2.size() ? nums2[other_left_choice] : INT_MAX;
            int val_4 = left_choice < nums1.size() ? nums1[left_choice] : INT_MAX;
            return min(val_3, val_4);
        }
    }
};
