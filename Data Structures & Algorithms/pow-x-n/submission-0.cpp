class Solution {
public:
//time : O(logn). space O(1)
    double myPow(double x, int n) {
        long long N=n; //long long to avoid overflow
        if(N<0){
            x=1/x;   //must be this block at start
            N=-N;
        }
        double result=1;
        while(N>0){
            if(N%2==1){ //if N is odd 2^21
            result*=x;    // result=1*2
            }
            x*=x;   //x=2*2=4
            N/=2;    //. 21/2=10         next is 4^10
        }
        
        
        return result;
    }
};
