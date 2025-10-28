class Solution {

    void validParentheses(string current,int open,int close,int n,vector<string>& ans){
        if(current.length()==2*n){
            ans.push_back(current);
            return;
        }

        if(open<n){
            validParentheses(current+'(',open+1,close,n,ans);
        }
        if(close<open){
            validParentheses(current+')',open,close+1,n,ans);
        }

    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        validParentheses("",0,0,n,ans);
        return ans;


    }
};