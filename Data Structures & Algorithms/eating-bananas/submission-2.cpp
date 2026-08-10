class Solution {
public:
    bool can_eat(vector<int>& piles, int h, int k){
        int time = 0;
        for(int i = 0; i < piles.size(); i++){
            time += ceil((double)piles[i] / k);
            if(time > h){return false;}
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            r = max(r, piles[i]);
        }
        int l = 1;
        int out = INT_MAX;
        while(l <= r){
            int m = (l + r) / 2;
            if(can_eat(piles, h, m)){
                out = min(m, out);
                r = m - 1;
            }
            else if(can_eat(piles, h, r)){
                out = min(r, out);
                l = m + 1;
            }
            else{
                break;
            }
            
        }
        return out; 
    }
};
