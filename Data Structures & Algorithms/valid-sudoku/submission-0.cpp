class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        vector<unordered_set<char>> row(n), col(n), box(n);
        //visiting each cell in board
        for (int i=0; i<n;i++){
            for(int j=0; j<n; j++){
                char val=board[i][j];
                if(val=='.'){     //skip the cell if . is there
                    continue;
                }
                int box_index=(i/3)*3+j/3;
                
                if(row[i].count(val)||col[j].count(val)||box[box_index].count(val)){
                    return false;
                }
                row[i].insert(val);
                col[j].insert(val);
                box[box_index].insert(val);
            }

        }
        return true;
        
    }
};
