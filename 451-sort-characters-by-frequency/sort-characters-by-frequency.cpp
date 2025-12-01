class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;

        priority_queue<pair<int, char>>
            pq;

            for(int i =0;i<s.length();i++){
                mp[s[i]]++;
            }

            for(auto x:mp){
                pq.push({x.second,x.first});
            }

            string ans="";
            while(!pq.empty()){

                for(int i =0;i<pq.top().first;i++){
                    ans+=pq.top().second;
                }
                pq.pop();
            }
            return ans;
    }
};