class Solution {
    //space =O(n). time O(n)
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0); //{0,1,2,3,4}
        for(int i=1;i<=n;i++){//But i >> 1 is just the number itself divided by 2, not the count of set bits.
            result[i]=result[i>>1]+(i&1);   //divide by 2 and check if it is odd
        }
        return result;
    }
};
