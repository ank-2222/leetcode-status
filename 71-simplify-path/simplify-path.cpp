class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if ( token ==""||token == ".")  //this will skip current directory and other empty space between // so //// will be treated as empty string between 2// and it will continue in that 
                continue;
            else if (token == "..") { //will remove from stack for parent directory
                if (!st.empty()) {
                    st.pop();
                }

            } else st.push(token);  //all other things will be considered as file name and pushed to stack
        }

        string result ="";
        while(!st.empty()){  //building result
            result = "/"+st.top()+result;
            st.pop();
        }
        return result.empty()?"/":result;
    }
};