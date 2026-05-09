class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;//output space not counted for space complexity
        int n=matrix.size();//no. of rows
        int m=matrix[0].size(); //no. of cool
        int rowBegin=0;
        int colBegin=0;
        int rowEnd=n-1;
        int colEnd=m-1;

        while(rowBegin<=rowEnd && colBegin<=colEnd){
            //traverse right-top
            for(int j=colBegin;j<=colEnd;j++){
                ans.push_back(matrix[rowBegin][j]);
            }
                rowBegin++;
            
            //traverse right-top bottom
            for(int j=rowBegin;j<=rowEnd;j++){
                ans.push_back(matrix[j][colEnd]);
            }
                colEnd--;
            
            //traverse bottom-left reverse
            if(rowBegin<=rowEnd){
            for(int j=colEnd;j>=colBegin;j--){
                ans.push_back(matrix[rowEnd][j]);
            }
            
                rowEnd--;
            }
            
            //traversing bottom->top left most
            if(colBegin<=colEnd){
            for(int j=rowEnd;j>=rowBegin;j--){
                ans.push_back(matrix[j][colBegin]);
            }
          
                colBegin++;
            }
            
        }

      return ans;  
    }
};
