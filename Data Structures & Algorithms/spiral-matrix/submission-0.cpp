class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(),cols = matrix[0].size();
        vector<int> ans;
        int rowstart=0,rowend=rows-1,colstart = 0,colend = cols-1;
        while(rowstart<=rowend && colstart<=colend){
            //  left to right
            for(int col = colstart ; col<=colend;col++){
                ans.push_back(matrix[rowstart][col]);
            }
            rowstart++;
            // Top to bottom
            for (int row = rowstart;row<=rowend;row++){
                ans.push_back(matrix[row][colend]);
            }
            colend--;
            // right to left
            if(rowstart <= rowend){
                for(int col = colend;col>=colstart;col--){
                    ans.push_back(matrix[rowend][col]);
                }
                rowend--;
            }
            // bottom to top
            if(colstart<=colend){
                for(int row = rowend;row>=rowstart;row--){
                    ans.push_back(matrix[row][colstart]);
                }
                colstart++;
            }
            
        }
        return ans;
    }
};
