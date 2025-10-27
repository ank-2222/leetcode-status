class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if(exp<0){
            x =1/x;
            exp=-exp;  //converting negative to positive, can we cannot send exponential negative, -(-n) <- this is representation
        }
        if(exp==0) return 1;

        double half = myPow(x,exp/2);
        if(exp%2==0)return half*half;
        else return x*half*half;

       
    }
};