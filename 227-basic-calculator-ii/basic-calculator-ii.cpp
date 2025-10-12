class Solution {

    bool isSign(const string& s) {
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }

public:
    int calculate(string s) {

        stack<int> st;
        int currentNumber = 0;
        int n = s.length();
        string sign = "+";

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                currentNumber = currentNumber * 10 + (int)(s[i] - '0');
            }

            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) { //i==n-1 for last number, cause we are pushing everythiing when sign is encountered, but for last number, sign wont be available so we need to process that number explicitly
                if (sign == "+") {
                    st.push(currentNumber);
                } else if (sign == "-") {
                    st.push(-currentNumber);
                } else if (sign == "*") {
                    int last = st.top();
                    st.pop();
                    st.push(last * currentNumber);
                } else if (sign == "/") {
                    int last = st.top();
                    st.pop();
                    st.push(last / currentNumber);
                }
                sign = s[i];
                currentNumber = 0;
            }
        }
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};