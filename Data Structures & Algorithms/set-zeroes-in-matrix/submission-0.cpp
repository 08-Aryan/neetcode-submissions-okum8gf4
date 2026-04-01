class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> ZeroRow;
        unordered_set<int> ZeroCol;
        // SC = O(n+m)
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    ZeroRow.insert(i);
                    ZeroCol.insert(j);
                }
            }
        }
        for(int row:ZeroRow){
            for(int col=0;col<matrix[0].size();col++){
                matrix[row][col]=0;
            }
        }
        for(int col:ZeroCol){
            for(int row=0;row<matrix.size();row++){
                matrix[row][col]=0;
            }
        }
    }
};
