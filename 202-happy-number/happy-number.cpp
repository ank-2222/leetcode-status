class Solution {
    int calc(int num){
        int ans=0;
        while(num>0){
            int mod = num%10;
            ans+=mod*mod;
            num/=10;
        }
       
        return ans;
    }
public:
    bool isHappy(int n) {
        
       unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = calc(n);
        }

        return n == 1;
    }
};