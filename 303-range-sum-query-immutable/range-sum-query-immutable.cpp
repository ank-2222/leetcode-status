class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
     prefix.resize(nums.size());
     prefix[0]=nums[0];
      for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

    }
    
    int sumRange(int left, int right) {
        if(left==0) return prefix[right];  //if index start from fist element directly return righ 
        return prefix[right]-prefix[left-1];  //else return subtraction, also inclusive so left-1
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */