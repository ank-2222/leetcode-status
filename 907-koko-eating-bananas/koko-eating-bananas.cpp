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
        int high = *max_element(piles.begin(), piles.end()); //highest ffrom the pile
        while(high-low>1){  //now here istead of piles, our search space will be 1 to max[piles] and whichever satisfies eating in h hour , and is min , that will be answer
            int mid = (low+high)/2;
            if(canEat(piles,mid,h)){ //if its true, this is counted and shrinked high to get more lowest value (min)
                high=mid;
            }else{
                low=mid+1;
            }
        }
        if(canEat(piles,low,h)){
            return low;
        }else{
           return high;
        }
    }
};