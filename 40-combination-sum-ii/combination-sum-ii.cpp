class Solution {

void combination(vector<int>& candidates, int target,vector<int>& op, int index,  vector<vector<int>>& ans){
    if(target==0){
        ans.push_back(op);
        return;
    }
   if (index >= candidates.size() || target < 0) {
        return;
    }

    //need to include next index only
   for (int i = index; i < candidates.size(); i++) {
            // \U0001f539 Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // \U0001f539 Stop if current number exceeds target
            if (candidates[i] > target)
                break;

            // include
            op.push_back(candidates[i]);
            combination(candidates, target - candidates[i], op, i + 1, ans); // use next index only once
            op.pop_back(); // backtrack
        }
}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int>> ans;

      vector<int> op;
      sort(candidates.begin(),candidates.end());
      combination(candidates,target,op,0,ans);
      return ans;

    }
};