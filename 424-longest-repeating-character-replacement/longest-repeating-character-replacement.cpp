class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();
        int l = 0, r = 0, maxlen = 0;
        int maxf=0;
        map<char, int> mp;
        while (r < n) {
            mp[s[r]-'a']++;
            maxf = max(maxf,mp[s[r]-'a']);

            int changes = (r-l+1)-maxf;
            if(changes<=k){
                maxlen=max(maxlen,r-l+1);
            }else{
                mp[s[l]-'a']--;
                if(mp[s[l]-'a']==0) mp.erase(mp[s[l]]-'a');
                l++;

            }

           
            r++;
        }
        return maxlen;
    }
};