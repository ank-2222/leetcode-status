class Solution {
public:
    void solve(vector<int> candidates,int target, vector<int> op,vector<vector<int>>& ans,int i){

     if (target == 0) {
        ans.push_back(op);
        return;
    }

    // \U0001f6ab Base case 2: out of bounds OR target overshoot
    if (i >= candidates.size() || target < 0) {
        return;
    }
    op.push_back(candidates[i]); //include same candidate
        solve(candidates, target - candidates[i], op, ans, i);
        op.pop_back();

        // Exclude current element (move to next index)
        solve(candidates, target, op, ans, i + 1);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        vector<int> op;

        solve(candidates,target,op,ans,0);
        return ans;
    }
};