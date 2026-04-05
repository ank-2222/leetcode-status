/*
Set -> Removes Duplicates
So if we put everything in a set and compare sizes
if size!= -> it has duplicates
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> seen;
        for(int num : nums) seen.insert(num);
        return seen.size()!=nums.size();
    }
};