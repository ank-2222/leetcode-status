class Solution {
public:
    string minRemoveToMakeValid(string s) {
        

        stack<int> st;
        string ans = "";
        vector<bool> remove(s.length(),false);

        for(int i=0;i<s.length();i++){

            if(s[i]=='('){
                st.push(i);
                
            }else if(s[i]==')'){
                if(!st.empty()) st.pop();
                else{
                    remove[i]=true;
                }
            }

        }
        while(!st.empty()){
            int index = st.top();
            remove[index]=true;
            st.pop();
        }

        for(int i=0;i<s.length();i++){
            if(remove[i]) continue;
            ans+=s[i];
        }
        return ans;
      


    }
};