class Solution {

bool isPalindrome(string& s, int left, int right){
    while(left<right){
        if(s[left]!=s[right])return false;
        left++;
        right--;
    }
    return true;
}

void solve(vector<vector<string>>& ans,vector<string>&temp,int index,string& s){

    if(index == s.length()){
        ans.push_back(temp);
        return;
    }

    for(int i =index;i<s.length();i++){
        if(isPalindrome(s,index,i)){
             string sub = s.substr(index, i-index+1);
            temp.push_back(sub);
            solve(ans,temp,i+1,s);
            temp.pop_back();
        }
    }
}


public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans,temp,0,s);
        return ans;
    }
};