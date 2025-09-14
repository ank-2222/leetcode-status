class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, start = -1, minLen = INT_MAX;
        unordered_map<int, int> mp;
        for (int i = 0; i < t.length(); i++) {
            mp[t[i]]++;
        }
        int count = mp.size();
        while (r < s.length()) {
            if (--mp[s[r]] == 0)
                count--;

            if (count == 0) {
                while (true) {
                    if (mp[s[l]] < 0) {
                        mp[s[l]]++;
                        l++;
                    } else {
                        break;
                    }
                }
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
            }

            r++;
        }
        return start == -1 ? "" : s.substr(start, minLen);
    }
};