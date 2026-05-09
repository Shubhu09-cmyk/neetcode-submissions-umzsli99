class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool firstRowZero=false;
        bool firstColZero=false;

        //set firstRowZero  if needed
        for(int j=0;j<m;j++){
            if(matrix[0][j]==0) {firstRowZero=true;
            break;
            }
        }
        //set firstColZero  if needed
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){ firstColZero=true;
            break;
            }
        }

        //set marker in first row and first col
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        //set cells to 0 based on markers
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

            //mark first row zero if needed
            if(firstRowZero){
                for(int j=0;j<m;j++){
                    matrix[0][j]=0;
                }
            }

            //mark first col zero if needed
            if(firstColZero){
                for(int i=0;i<n;i++){
                    matrix[i][0]=0;
                }
            }
        
     
        
    }
};
