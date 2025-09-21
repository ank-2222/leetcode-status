class Solution {
public:
    string calc(string s) {
        string ans;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '#') {
                ans = ans.substr(0, ans.length()-1);
            }else{

            ans += s[i];
            }
            i++;
          
        }
        return ans;
    }

    bool backspaceCompare(string s, string t) {
        
         return calc(s) == calc(t); }
};