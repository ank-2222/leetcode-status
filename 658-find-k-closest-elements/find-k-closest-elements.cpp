class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            int mid = (low + high) / 2;
            if (x < arr[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int left = low - 1;
        int right = low;
        vector<int> ans;
        while (ans.size() < k) {
            if(left<0){
                ans.push_back(arr[right++]);
            }else if(right>=arr.size()){
                ans.push_back(arr[left--]);
            }else if (abs(arr[right]-x)>=abs(arr[left]-x)){
                ans.push_back(arr[left--]);
            }else{
                ans.push_back(arr[right++]);
            }

        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};