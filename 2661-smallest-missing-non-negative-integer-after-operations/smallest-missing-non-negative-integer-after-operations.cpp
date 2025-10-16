class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> vec(value, 0);
        for (auto i : nums) {
            int x = ((i % value) + value) % value;
            vec[x]++;
        }
        int j = 0;
        while (true) {
            int x = j % value;
            if (vec[x] == 0) {
                return j;
            }
            vec[x]--;
            j++;
        }
    }
};