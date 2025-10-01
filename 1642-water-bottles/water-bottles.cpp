class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int count = numBottles; 
        int empty = numBottles;

        while(empty >= numExchange){
           int newBottles = empty / numExchange;
            count += newBottles; 
             empty = newBottles + (empty % numExchange);
        }
        return count;
    }
};