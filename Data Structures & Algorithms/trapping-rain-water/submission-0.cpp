class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int water = 0;
        while(l + 1 < height.size()){
            if(height[l + 1] >= height[l]){
                l++;
            }
            else{
                int r = l + 1;
                int possible = 0;
                int max = r;
                while(r < height.size() && height[r] < height[l]){
                    if(height[r] > height[max]){
                        max = r;
                    }
                    r++;
                }
                if(r < height.size()){
                    for(int w = l + 1; w < r; w++){
                        possible += height[l] - height[w];
                    }
                    water += possible;
                    l = r;
                }
                else{
                    r = max;
                    for(int w = l + 1; w < r; w++){
                        possible += height[max] - height[w];
                    }
                    water += possible;
                    l = r;
                }

            }
        }
        return water;

    }
};
