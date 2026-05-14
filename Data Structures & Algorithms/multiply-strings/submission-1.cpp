class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int n=num1.length(),m=num2.length();
        vector<int> result(m+n,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int pos1=i+j;//tens place
                int pos2=i+j+1; //one's place
                int sum=mul+result[pos2];
                result[pos2]=sum%10;
                result[pos1]+=sum/10;


            }
        }
        //convert to string
        string ans="";
        for(int x:result){
            if(!(ans.empty() && x==0)){   //if ans is empty and num is 0 then we can skip 000577.  so 577
                ans.push_back(x+'0');
            }
        }
       return ans.empty()?"0":ans;
    }
};
