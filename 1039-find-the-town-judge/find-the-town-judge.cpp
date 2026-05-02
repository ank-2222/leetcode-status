class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      vector<int> trustScore(n+1,0);

       for(auto &x:trust){
        int u = x[0];
        int v = x[1];

        trustScore[u]--;
        trustScore[v]++;

       }

       for(int i =1;i<=n;i++){
        if(trustScore[i]==n-1)return i;
       }  
       return -1;
    }
};