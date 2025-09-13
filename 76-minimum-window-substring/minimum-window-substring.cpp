class Solution {
public:
string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto x: t){
            mp[x]++;

        }
        int count=mp.size();
        int start=0,left=0,right=0,ans=INT_MAX;
        while(right<s.length()){
            mp[s[right]]--;
            if(mp[s[right]]==0){
                count--;
            }
              if(count==0){
                   while(count==0){
                      if(ans>right-left+1){
                        ans=right-left+1;
                        start=left;
                      }
                      mp[s[left]]++;
                      if(mp[s[left]]>0){
                        count++;
                      }
                      left++;
                   }
                   //left++;
              }
            right++;
        }
        if(ans!=INT_MAX)return s.substr(start,ans);
        else return "";
    }
};