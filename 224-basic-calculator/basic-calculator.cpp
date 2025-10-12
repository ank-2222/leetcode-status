class Solution {
public:
    int calculate(string s) {

        stack<int> st;
        int ans = 0;
        int sign = 1;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < n &&
                       isdigit(s[i])) { // here i will already be increased due
                                        // to ++i in for loop
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i; // Adjust index since outer loop will increment
                ans += num * sign;  //this line is evaluation where it is adding or subtracting from result on the go, cause suppost ans+ 3 is the nexct expression , so after ans, cursor goes to + and sign is updated , and then when it comes to 3 , sign is already updated, and this line will evaluate expression acc to previous sign 
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;

            } else if (s[i] == ')') {
                int sign = st.top();
                st.pop();
                int prev = st.top();
                st.pop();
                ans = prev +
                      sign * ans; // basically this is like merging prev result
                                  // + result from sub expression to use further
            }
        }

        return ans;
    }
};