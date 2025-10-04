class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int i = 0;
        int j = height.size() - 1;

        while (i < j) {
            int water = min(height[i], height[j]) * (j - i);


            if (height[i] < height[j])
                i++;
            else
                j--;

            maxwater = max(water, maxwater);

        }
        return maxwater;
    }
};