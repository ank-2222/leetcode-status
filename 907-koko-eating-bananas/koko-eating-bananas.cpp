class Solution {

    bool canEat(vector<int>& piles,int k,int h){
        int i =0;
        int sum=0;
        while(i<piles.size()){
            sum+=ceil((double)piles[i] / k);
            if(sum>h) return false;
            i++;
        }
        return true;
    }

public:


    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high = *max_element(piles.begin(), piles.end());
        while(low < high){
            int mid = (low+high)/2;
            if(canEat(piles,mid,h)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
    return low;
    }
};