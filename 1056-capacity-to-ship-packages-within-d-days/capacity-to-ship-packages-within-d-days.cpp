class Solution {
    bool canShip(vector<int>& weights, int days, int cap) {
   int usedDays = 1;   // start with day 1
    int load = 0;
    
    for (int w : weights) { //for every weight in order we will add till max cap , and then change to next day and reset load , for next day
        if (load + w > cap) {
            usedDays++;   // new day
            load = 0;
        }
        load += w;
    }
    return usedDays <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        // trick is to find search space, here we need lower bound and high
        // bound
        int low = 0, high = 0;
        for (int i = 0; i < weights.size(); i++) {
            high += weights[i];
            if (low < weights[i])
                low = weights[i];
        }

        while (low < high) { //at equal to it will break the loop and low and high both will have same value
            int mid = (high + low) / 2;
            if (canShip(weights, days, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};