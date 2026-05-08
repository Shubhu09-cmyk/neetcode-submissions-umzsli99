class Solution {
    /*
    Time Complexity
Transpose: O(n^2)
Reverse rows: O(n^2)
Overall: O(n^2)
Space Complexity
O(1) (in-place rotation)
Idea
To rotate 90° clockwise:
Transpose the matrix
(convert rows to columns)
Reverse each row
*/
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //step 1 :transpose
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse the rows
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};
