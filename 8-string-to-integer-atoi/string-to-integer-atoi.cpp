class Solution {

    long long parse(string& s, int i, long long num, int sign) {
        if (i >= s.length() || !isdigit(s[i]))
            return num;

        num = num * 10 + (s[i] - '0');
        if (num * sign > INT_MAX)
            return INT_MAX;
        if (num * sign < INT_MIN)
            return INT_MIN;

        return parse(s, i+1, num, sign);
    }

public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {  //if will check only once, and if we have multiple sign operator it will return 0 
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }
        long long num = parse(s, i, 0, sign);
        return sign * num;
    }
};