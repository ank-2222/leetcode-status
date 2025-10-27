class Solution {

    long long modPow(long long base, long long exp, long long mod){
        if(exp==0) return 1; //base condition 

        long long half = modPow(base,exp/2,mod);
        long long result = (half*half)%mod; //if even

        if(exp%2){
            result = (result*base)%mod;  //if odd, we need to x*hal*half
        }
        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long mod = 1e9+7;
// 0,2,4,6,8 -> total 5 choices can only be made , and for prime 2,3,5,7 only 4 choices can be made, so permutation combination
        long long evenCount = modPow(5,(n+1)/2,mod); //n+1 /2 cause for n we have ceil(n/2 ) even positions, so use n+1/2 or ceil
        long long oddCount = modPow(4,n/2,mod);  // we need floor(n/2) 

        return (evenCount*oddCount)%mod;
    }
};