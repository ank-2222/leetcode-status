class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(auto x:s){
            mp[x]++;
           if(mp[x]>(s.length()+1)/2) return "";
        }

        priority_queue<pair<int,char>>pq;

        for(auto &it: mp){
            pq.push({it.second,it.first});
        }
        string ans="";
          while (pq.size() > 1) {  //greater than one so that 2nd pop should not give error
            auto p1 = pq.top(); pq.pop();
            auto p2 = pq.top(); pq.pop();

            ans += p1.second;
            ans += p2.second;

            if (--p1.first > 0) pq.push(p1);
            if (--p2.first > 0) pq.push(p2);
        }

        // If one character remains
        if (!pq.empty()) {
            ans += pq.top().second; // freq must be 1
        }
        return ans;
    }
};